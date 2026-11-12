/*
 * Vehicle
 *
 * Original file: Vehicle.cpp
 * Area:          vehicles
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Vehicle.cpp here, in the order they appear in the library.
 */

#include "Vehicle.h"
#include "../ai/NPC.h"
#include "../characters/PlayerTest.h"
#include "../characters/PhysicAttributes.h"
#include "../world/GameObjectManager.h"
#include "../scripting/ScriptManager.h"
#include "../audio/SoundManager.h"
#include "../core/LocalStringStartupStorage.h"
#include "../core/NativeStrings.h"
#include "../core/Lock.h"
#include "../rendering/CustomBillboardSceneNode.h"
#include "../core/PhysicsBodyDef.h"
#include "../rendering/GS3DStuff.h"

extern "C" int puts(const char*);
void aTransitionCallback(irr::scene::ITimelineController*, void*);

namespace irr { namespace collada {
class CSkinnedMeshSceneNode {
public:
    void setIsSkinningEnabled(bool enabled);
};
} }

namespace {
const unsigned int photographedFlag = 1u << 15;

union VehicleControlFlags {
    unsigned int word;
    struct {
        unsigned int accelerating : 1;
        unsigned int braking : 1;
        unsigned int : 6;
        unsigned int waitState : 3;
    } bits;
};
}

void* __attribute__((weak)) Vehicle::getSkinMesh()
{
    return skinnedMesh;
}

int __attribute__((weak)) Vehicle::getSpawnType()
{
    return spawnType;
}

void __attribute__((weak)) Vehicle::setSpawnType(int type)
{
    spawnType = type;
}

int __attribute__((weak)) Vehicle::getMaxHealth() const
{
    return maxHealth;
}

int __attribute__((weak)) Vehicle::getHealth() const
{
    return health;
}

bool __attribute__((weak)) Vehicle::isDead()
{
    return health <= 0;
}

void __attribute__((weak)) Vehicle::photographed()
{
    flags344 |= photographedFlag;
}

void __attribute__((weak)) Vehicle::clearPhotographed()
{
    flags344 &= ~photographedFlag;
}

bool __attribute__((weak)) Vehicle::isPhotographed() const
{
    return (flags344 & photographedFlag) != 0;
}

void Vehicle::_shiftWeight(irr::core::vector3d<float>&, float)
{
}

const char* Vehicle::getEnterAnim() const { return enterAnim; }
const char* Vehicle::getExitAnim() const { return exitAnim; }
const char* Vehicle::getCloseDoorAnim() const { return closeDoorAnim; }

void Vehicle::toggleInterior(bool visible)
{
    interior->setVisible(visible);
}

bool Vehicle::isLeftDoor(const irr::scene::ISceneNode* door) const
{
    return leftDoor == door;
}

bool Vehicle::isDoorOpened(bool left) const
{
    return !(left ? leftDoorClosed : rightDoorClosed);
}

bool Vehicle::isDoorClosed(bool left) const
{
    return left ? leftDoorClosed : rightDoorClosed;
}

bool Vehicle::isDoorAnim(const char* name, bool left) const
{
    irr::scene::ISceneNodeAnimator* animator = left ? leftDoorAnimator : rightDoorAnimator;
    const int clip = animator->getAnimationClipIndex(name);
    return clip == animator->getTimelineCtrl()->getCurrentClipIndex();
}

void Vehicle::onDoorClosed()
{
    if (isDoorClosed(false) && isDoorClosed(true)) {
        toggleInterior(false);
        enableSkinning(false);
        enableBackfaceCulling(true);
    }

    if (doorSoundSuppression) {
        --doorSoundSuppression;
    } else {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(113, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }
}

namespace {
const char openDoorClip[] = "car_open_door";
const char closeDoorClip[] = "car_close_door";
const char exitCarClip[] = "car_exit_car";
const char highVehicleEnterClip[] = "car_enter_car_hi";
const char lowVehicleEnterClip[] = "car_enter_car_low";
const char noAnimatorsMessage[] = "this scene node has no animators";
const char noTimelineMessage[] = "This mesh has no timeline";
const char noCallbackTimelineMessage[] = "no timeline...can't set callback";
const char closeLeftDoorClip[] = "car_close_door_left";
const char closeRightDoorClip[] = "car_close_door_right";
const char exitLowLeftClip[] = "car_exit_car_low_left";
const char exitLowRightClip[] = "car_exit_car_low_right";
const char exitHighLeftClip[] = "car_exit_car_hi_left";
const char exitHighRightClip[] = "car_exit_car_hi_right";
const char closedIdleClip[] = "car_closed_idle";
const char openedIdleClip[] = "car_opened_idle";
}

irr::scene::ISceneNode* Vehicle::getMesh()
{
    return sceneNode;
}

bool Vehicle::isHiVehicle()
{
    return strcmp(highVehicleEnterClip, enterAnim) == 0;
}

bool Vehicle::isLowVehicle()
{
    return strcmp(lowVehicleEnterClip, enterAnim) == 0;
}

int Vehicle::getSeatedAnimation()
{
    return isLowVehicle() ? 25 : 24;
}

int Vehicle::getRightThrownAnimation()
{
    return isLowVehicle() ? 33 : 31;
}

int Vehicle::getLeftThrownAnimation()
{
    return isLowVehicle() ? 32 : 30;
}

int Vehicle::getRightThrowAnimation()
{
    return isLowVehicle() ? 29 : 27;
}

int Vehicle::getLeftThrowAnimation()
{
    return isLowVehicle() ? 28 : 26;
}

int Vehicle::getRightEjectAnimation()
{
    // The retail eject selectors check vehicle height even though the clip is fixed.
    isLowVehicle();
    return 8;
}

int Vehicle::getLeftEjectAnimation()
{
    isLowVehicle();
    return 7;
}

int Vehicle::getRightExitAnimation()
{
    return isLowVehicle() ? 16 : 14;
}

int Vehicle::getLeftExitAnimation()
{
    return isLowVehicle() ? 15 : 13;
}

int Vehicle::getRightCloseDoorFromInsideAnimation()
{
    return isLowVehicle() ? 4 : 2;
}

int Vehicle::getLeftCloseDoorFromInsideAnimation()
{
    return isLowVehicle() ? 3 : 1;
}

int Vehicle::getRightEnterAnimation()
{
    return isLowVehicle() ? 12 : 10;
}

int Vehicle::getLeftEnterAnimation()
{
    return isLowVehicle() ? 11 : 9;
}

void doorTransitionCallback(irr::scene::ITimelineController* timeline, void* data)
{
    Vehicle* vehicle = static_cast<Vehicle*>(data);
    if (!vehicle->leftDoorAnimator || !vehicle->rightDoorAnimator)
        return;

    irr::scene::ITimelineController* leftTimeline = vehicle->leftDoorAnimator->getTimelineCtrl();
    vehicle->rightDoorAnimator->getTimelineCtrl();
    const bool left = leftTimeline == timeline;

    if (vehicle->isDoorAnim(closeDoorClip, left) || vehicle->isDoorAnim(exitCarClip, left)) {
        if (left) {
            vehicle->leftDoorClosed = true;
            vehicle->leftDoorTransition = false;
        } else {
            vehicle->rightDoorClosed = true;
            vehicle->rightDoorTransition = false;
        }
        vehicle->onDoorClosed();
    }
}

void Vehicle::setDoorAnim(const char* name, bool left)
{
    irr::scene::ISceneNodeAnimator* animator = left ? leftDoorAnimator : rightDoorAnimator;
    animationClipIndex = animator->getAnimationClipIndex(name);
    animator->setAnimationClip(animationClipIndex);
    irr::scene::ITimelineController* timeline = animator->getTimelineCtrl();
    if (timeline) {
        timeline->setScale(doorAnimationScale);
        timeline->callbackData = this;
        timeline->callback = doorTransitionCallback;
    }
}

inline __attribute__((always_inline)) void Vehicle::openDoorWithClip(const char* clip, bool left)
{
    if (left)
        leftDoorClosed = false;
    else
        rightDoorClosed = false;

    toggleInterior(true);
    enableSkinning(true);
    enableBackfaceCulling(false);
    setDoorAnim(clip, left);

    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(122, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
}

void Vehicle::openDoor(bool left)
{
    openDoorWithClip(openDoorClip, left);
}

void Vehicle::openDoorFromInside(bool left)
{
    openDoorWithClip(exitCarClip, left);
}

void Vehicle::flee(const irr::core::vector3d<float>& point)
{
    destination = point;
    VehicleControlFlags flags;
    flags.word = flags344;
    flags.word &= ~0x580u;
    flags344 = flags.word | 0xa00u;
}

void Vehicle::driveToLocation(const irr::core::vector3d<float>& point, bool flag)
{
    destination = point;
    driveToLocationFlag = flag;
    VehicleControlFlags flags;
    flags.word = flags344;
    flags.word &= ~0x380u;
    flags344 = flags.word | 0xc00u;
}

void Vehicle::CheckDestination()
{
    irr::core::vector3d<float> point;
    irr::core::vector3d<float> adjusted;
    if (canGoToPoint(destination, point, adjusted)) {
        destinationReachable = true;
        adjustedDestination = destination;
    } else {
        destinationReachable = false;
        adjustedDestination = adjusted;
    }
}

void Vehicle::wait(int seconds)
{
    waitDuration = seconds * 1000;
    waitElapsed = 0;
    VehicleControlFlags flags;
    flags.word = flags344;
    flags.word &= ~0x680u;
    flags344 = flags.word | 0x900u;
}

void Vehicle::freeze()
{
    VehicleControlFlags flags;
    flags.word = flags344;
    flags.bits.waitState = 0;
    flags344 = flags.word | 0x880u;
}

void Vehicle::accelerate(float amount)
{
    accelerationAmount = amount;
    VehicleControlFlags flags;
    flags.word = flags344;
    flags.bits.accelerating = 1;
    flags.bits.braking = 0;
    flags344 = flags.word;
}

void Vehicle::brake(float amount)
{
    brakeAmount = amount;
    VehicleControlFlags flags;
    flags.word = flags344;
    flags.bits.braking = 1;
    flags.bits.accelerating = 0;
    flags344 = flags.word;
}

void Vehicle::turn(bool left, float amount)
{
    turnLeft = left;
    turnAmount = amount;
    flags344 |= 4u;
}

void Vehicle::setDriver(Character* value)
{
    driver = value;
    if (value && !value->isPlayer()) {
        driverMetatype = driver->GetMetatype();
        driverBehavior = driver->driverBehavior;
    }
}

void Vehicle::resetDriver()
{
    setDriver(GameObjectManager::s_gom->spawnNPCInVehicle(this, driverMetatype, driverBehavior));
}

void Vehicle::DestroyWheels()
{
    if (leftCollisionBody) {
        PhysicAttributes::s_world->DestroyBody(leftCollisionBody);
        leftCollisionBody = 0;
    }
    if (rightCollisionBody) {
        PhysicAttributes::s_world->DestroyBody(rightCollisionBody);
        rightCollisionBody = 0;
    }
}

void Vehicle::Stop()
{
    if (!isEnabled())
        return;

    LevelObject::Stop();
    flags344 &= ~7u;
    unknown116 = 0.0f;
    unknown120 = 0.0f;
    unknown124 = 0.0f;
    b2Body* body = collisionBody;
    body->linearVelocity.y = 0.0f;
    body->linearVelocity.x = 0.0f;
    collisionBody->angularVelocity = 0.0f;
    body = leftCollisionBody;
    body->linearVelocity.y = 0.0f;
    body->linearVelocity.x = 0.0f;
    leftCollisionBody->angularVelocity = 0.0f;
    body = rightCollisionBody;
    body->linearVelocity.y = 0.0f;
    body->linearVelocity.x = 0.0f;
    rightCollisionBody->angularVelocity = 0.0f;
    _adjustEnginePitch(0);
}

void Vehicle::immobilize()
{
    if (!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
        collisionBody->SetMassFromShapes();
        b2MassData bodyMass;
        bodyMass.mass = 0.0f;
        bodyMass.center.y = 0.0f;
        bodyMass.center.x = 0.0f;
        bodyMass.I = 0.0f;
        collisionBody->SetMass(&bodyMass);

        leftCollisionBody->SetMassFromShapes();
        rightCollisionBody->SetMassFromShapes();
        b2MassData sideMass;
        sideMass.I = 0.0f;
        sideMass.center.y = 0.0f;
        sideMass.center.x = 0.0f;
        sideMass.mass = 0.0f;
        leftCollisionBody->SetMass(&sideMass);
        rightCollisionBody->SetMass(&sideMass);
        immobilized = true;
    }
    Stop();
}


void Vehicle::postExplosion()
{
    exploding = false;
    explosionFinished = true;
    immobilize();
    hideWheels();
}

void VehicleExplosionAnimCallback(irr::scene::ITimelineController*, void* userData)
{
    static_cast<Vehicle*>(userData)->postExplosion();
}

void Vehicle::shooted(int amount, LevelObject* source)
{
    if (isDead())
        return;

    applyDamage(amount, source, false);
    if (Lock::getInstance()->target == this)
        Lock::getInstance()->billboard->activateAnimation();
}

void Vehicle::applyDamage(int amount, LevelObject*, bool)
{
    if (!(unknown4 & 4u)) {
        Character* currentDriver = driver;
        Character* player = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
        if (player != currentDriver)
            return;
    }
    health -= amount;
}

void Vehicle::SetRotation(const irr::core::quaternion& rotation)
{
    LevelObject::SetRotation(rotation);
    irr::core::vector3d<float> angles;
    rotation.toEulerDegree(angles);
    rotationX = angles.X;
    rotationY = angles.Y;
    rotationZ = angles.Z;
}

void Vehicle::SetPosition(const irr::core::vector3d<float>& position)
{
    LevelObject::SetPosition(position);
    if (collisionBody) {
        collisionBody->SetXForm(b2Vec2(position.X / 100.0f, position.Y / 100.0f), collisionBody->angle);
        ResetBodyPosition();
        for (b2Shape* shape = collisionBody->shapeList; shape; shape = shape->next)
            PhysicAttributes::s_world->Refilter(shape);
    }
}

void Vehicle::closeDoor(bool left)
{
    if (left)
        leftDoorTransition = true;
    else
        rightDoorTransition = true;

    setDoorAnim(closeDoorClip, left);
}

void Vehicle::enableSkinning(bool enabled)
{
    if (skinnedMesh)
        skinnedMesh->setIsSkinningEnabled(enabled);
}

void Vehicle::enableBackfaceCulling(bool enabled)
{
    GS3DStuff::SetMaterialFlag(exterior, irr::video::MaterialFlag512, enabled);
}

inline __attribute__((always_inline)) void Vehicle::setWheelVisibility(bool visible)
{
    GS3DStuff::SetVisibility(wheelNodes[0], visible);
    GS3DStuff::SetVisibility(wheelNodes[1], visible);
    GS3DStuff::SetVisibility(wheelNodes[2], visible);
    GS3DStuff::SetVisibility(wheelNodes[3], visible);
}

void Vehicle::showWheels()
{
    setWheelVisibility(true);
}

void Vehicle::hideWheels()
{
    setWheelVisibility(false);
}

void Vehicle::startAnim(irr::scene::ISceneNodeAnimator* animator, bool loop)
{
    irr::scene::ITimelineController* timeline = animator->getTimelineCtrl();
    if (timeline) {
        timeline->setLoop(loop);
        timeline->jumpTo(timeline->startTime);
    }
}

bool Vehicle::isCurrentAnim(const char* name)
{
    irr::scene::ISceneNodeAnimator* animator = *sceneNode->getAnimators().begin();
    return animator->getAnimationClipIndex(name) == animationClipIndex;
}

irr::scene::ITimelineController* Vehicle::getTimeline(irr::scene::ISceneNode* node)
{
    const irr::scene::SceneAnimatorList& animators = node->getAnimators();
    if (animators.getSize())
        return (*animators.begin())->getTimelineCtrl();

    puts(noAnimatorsMessage);
    return 0;
}

void Vehicle::playCurAnimFromStart()
{
    irr::scene::ITimelineController* timeline = getTimeline(sceneNode);
    if (timeline)
        timeline->jumpTo(timeline->startTime);
    else
        puts(noTimelineMessage);
}

void Vehicle::setTransitionCallback(irr::scene::ISceneNode* node)
{
    irr::scene::ITimelineController* timeline = getTimeline(node);
    if (timeline) {
        timeline->setLoop(false);
        timeline->callbackData = this;
        timeline->callback = aTransitionCallback;
    } else {
        puts(noCallbackTimelineMessage);
    }
}

void Vehicle::setAnim(const char* name, bool, float scale)
{
    irr::scene::ISceneNodeAnimator* animator = *sceneNode->getAnimators().begin();
    const int clip = animator->getAnimationClipIndex(name);
    if (clip != animationClipIndex) {
        animator->getTimelineCtrl()->setScale(scale);
        animator->setAnimationClip(clip);
        animationClipIndex = clip;
        setTransitionCallback(sceneNode);
        playCurAnimFromStart();
    }
}

void aTransitionCallback(irr::scene::ITimelineController*, void* data)
{
    Vehicle* vehicle = static_cast<Vehicle*>(data);
    if (vehicle->isCurrentAnim(closeLeftDoorClip) ||
        vehicle->isCurrentAnim(closeRightDoorClip) ||
        vehicle->isCurrentAnim(exitLowLeftClip) ||
        vehicle->isCurrentAnim(exitLowRightClip) ||
        vehicle->isCurrentAnim(exitHighLeftClip) ||
        vehicle->isCurrentAnim(exitHighRightClip)) {
        vehicle->setAnim(closedIdleClip, false, 1.0f);
    } else if (vehicle->isCurrentAnim(openDoorClip)) {
        vehicle->setAnim(openedIdleClip, false, 1.0f);
    }
    vehicle->playCurAnimFromStart();
}

void VehicleCallBack(irr::scene::ITimelineController*, void* data)
{
    Vehicle* vehicle = static_cast<Vehicle*>(data);
    vehicle->animationClipIndex = 99999;
    vehicle->setAnim(closedIdleClip, false, 1.0f);
    vehicle->playCurAnimFromStart();
}

void Vehicle::_notifyTargeted(bool targeted, Character* source)
{
    if (targeted)
        targetingCharacter = source;
}

const Path* Vehicle::getPathToFollow() const
{
    return pathToFollow;
}

void Vehicle::setCurrentWaypoint(int waypoint)
{
    currentWaypoint = waypoint;
}

int Vehicle::getCurrentWaypoint() const
{
    return currentWaypoint;
}

void Vehicle::loopPathToFollow(bool loop)
{
    if (loop)
        flags344 |= 0x04000000u;
    else
        flags344 &= ~0x04000000u;
}

void Vehicle::setPathToFollow(const Path* path)
{
    currentWaypoint = 0;
    pathToFollow = path;
    loopPathToFollow(false);
}

bool Vehicle::isLoopingOnPathToFollow() const
{
    return (flags344 & 0x04000000u) != 0;
}

void Vehicle::AddTurboSounds() {}
void Vehicle::Init4CylTurboSounds() {}
void Vehicle::InitSuperbikeSounds() {}
void Vehicle::InitV12LamborghiniSounds() {}

void Vehicle::setHasBeenStolen() { hasBeenStolen = true; }
bool Vehicle::getHasBeenStolen() { return hasBeenStolen; }
int Vehicle::getUniqueId() { return vehicleIndex - 12335; }

void operator delete(void*) throw();

extern "C" {
static void __tcf_4() __attribute__((used));
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

extern "C" {
extern unsigned char _ZZN12CGameFactory11getInstanceEvE2gf[];
extern unsigned char _ZZN11CCarFactory11getInstanceEvE2cf[];
extern unsigned char _ZZN9AIManager11getInstanceEvE3aim[];

void _ZN12CGameFactoryD1Ev(void*) __attribute__((weak));
void _ZN11CCarFactoryD1Ev(void*) __attribute__((weak));
void _ZN9AIManagerD1Ev(void*);

static void __tcf_3() __attribute__((used));
static void __tcf_3()
{
    _ZN9AIManagerD1Ev(_ZZN9AIManager11getInstanceEvE3aim);
}

static void __tcf_1() __attribute__((used));
static void __tcf_1()
{
    _ZN12CGameFactoryD1Ev(_ZZN12CGameFactory11getInstanceEvE2gf);
}

static void __tcf_2() __attribute__((used));
static void __tcf_2()
{
    _ZN11CCarFactoryD1Ev(_ZZN11CCarFactory11getInstanceEvE2cf);
}
}


void Vehicle::resetCollisions()
{
    if (isEnabled()) {
        for (b2Shape* shape = collisionBody->shapeList; shape; shape = shape->next)
            shape->filter = collisionFilter;
    }
}
