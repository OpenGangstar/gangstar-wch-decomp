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
#include "CarSoundCallbacks.h"
#include "../world/SceneNodeManager.h"
#include "../ai/NPC.h"
#include "../ai/AIManager.h"
#include "../characters/PlayerTest.h"
#include "../characters/PhysicAttributes.h"
#include "../world/GameObjectManager.h"
#include "../scripting/ScriptManager.h"
#include "../audio/SoundManager.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
#include "../core/GameEventMethods.h"
#include "../characters/NPCVehicleEvent.h"
#include "../hud/CHudManager.h"
#include "../core/NativeStdio.h"
#include "../core/MemHint.h"
namespace GameFactoryProperties {
extern const char billboard[] __attribute__((visibility("hidden")));
}
#include "../core/LocalStringStartupStorage.h"
#include "../core/NativeStrings.h"
#include "../core/Lock.h"
#include "../rendering/CustomBillboardSceneNode.h"
#include "../core/PhysicsBodyDef.h"
#include "../rendering/GS3DStuff.h"

extern "C" float __aeabi_fmul(float, float);
extern "C" int puts(const char*);
void aTransitionCallback(irr::scene::ITimelineController*, void*);

namespace irr { namespace collada {
class CSkinnedMeshSceneNode {
public:
    void setIsSkinningEnabled(bool enabled);
};
} }

namespace {
class SkinnedMeshBoundsView {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual const irr::core::aabbox3d<float>& getBoundingBox() const;
};

struct SkinBoundsSource {
    unsigned char unknown[108];
    SkinnedMeshBoundsView* mesh;
};
}

class CustomSkinnedMeshSceneNode {
public:
    const irr::core::aabbox3d<float>& getBoundingBox() const __attribute__((weak));

private:
    unsigned char unknown[36];
    irr::core::matrix4 absoluteTransform;
    unsigned char unknown104[108];
    mutable irr::core::aabbox3d<float> transformedBounds;
    unsigned char unknown236[96];
    SkinBoundsSource* skin;
    unsigned char unknown336[68];

public:
    const irr::core::aabbox3d<float>& getTransformedBoundingBox() const __attribute__((weak));
};

const irr::core::aabbox3d<float>& CustomSkinnedMeshSceneNode::getBoundingBox() const
{
    return skin->mesh->getBoundingBox();
}

const irr::core::aabbox3d<float>& CustomSkinnedMeshSceneNode::getTransformedBoundingBox() const
{
    const irr::scene::ISceneNode* node = reinterpret_cast<const irr::scene::ISceneNode*>(this);
    transformedBounds = node->getBoundingBox();
    absoluteTransform.transformBoxEx(transformedBounds);
    return transformedBounds;
}

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

float __attribute__((weak)) Vehicle::GetSpeed() const
{
    return (speed / 1000.0f) * 3600.0f;
}

float Vehicle::_calculatePercentSkid(float amount)
{
    if (skidThreshold * 15.0f < amount) {
        const float upper = skidThreshold * 35.0f;
        if (amount >= upper)
            return 0.6f * turnAmount;

        const float offset = skidThreshold * -15.0f;
        return ((amount + offset) / (upper + offset)) * turnAmount * 0.6f;
    }
    return 0.0f;
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

namespace {
template<void (irr::core::vector3d<float>::*Rotate)(
    double, const irr::core::vector3d<float>&)>
inline __attribute__((always_inline)) void rotateBasisPair(
    irr::core::vector3d<float>& first, irr::core::vector3d<float>& second, float radians,
    float radiansToDegrees = 57.2957763671875f)
{
    const double degrees = radians * radiansToDegrees;
    (first.*Rotate)(degrees, irr::core::vector3d<float>());
    (second.*Rotate)(degrees, irr::core::vector3d<float>());
}
}

void Vehicle::_yaw(float radians)
{
    rotateBasisPair<&irr::core::vector3d<float>::rotateXYBy>(basisY, basisX, radians);
}

void Vehicle::_roll(float radians)
{
    rotateBasisPair<&irr::core::vector3d<float>::rotateXZBy>(basisX, basisZ, radians);
}

void Vehicle::_pitch(float radians)
{
    rotateBasisPair<&irr::core::vector3d<float>::rotateYZBy>(basisY, basisZ, radians);
}

namespace gameloft { namespace vehicle { namespace gear_profiles {
struct GearProfile {
    unsigned int gearCount;
    unsigned char unknown[12];
    const unsigned int* shiftSpeeds;
    unsigned char unknown20[8];
};
extern GearProfile profiles[] __attribute__((visibility("hidden")));
} } }

int Vehicle::getVelDirec()
{
    if (isEnabled()) {
        const b2Vec2 linearVelocity = collisionBody->linearVelocity;
        const irr::core::vector3d<float> velocity(linearVelocity.x, linearVelocity.y, 0.0f);
        const irr::core::vector3d<float> front = GetFront();
        const float frontX = front.X;
        const float frontY = front.Y;
        const float frontZ = front.Z;
        if (velocity.getLength() > 0.00001f) {
            const float x = __aeabi_fmul(frontX, velocity.X);
            const float y = __aeabi_fmul(frontY, velocity.Y);
            const float z = frontZ * velocity.Z;
            const float alignment = (x + y) + z;
            if (alignment == 0.0f)
                return 2;
            if (alignment > 0.0f)
                return 1;
            return 3;
        }
    }
    return 0;
}

void Vehicle::_shiftGears(unsigned int speed)
{
    if (getVelDirec() == 3) {
        gear = static_cast<unsigned int>(-1);
        return;
    }
    if (gear == static_cast<unsigned int>(-1))
        gear = 1;

    const unsigned int currentGear = gear;
    const gameloft::vehicle::gear_profiles::GearProfile& profile =
        gameloft::vehicle::gear_profiles::profiles[gearProfile];
    if (currentGear < profile.gearCount && speed >= profile.shiftSpeeds[currentGear - 1])
        gear = currentGear + 1;
    else if (currentGear > 1 && speed < profile.shiftSpeeds[currentGear - 2])
        gear = currentGear - 1;
}

void Vehicle::_adjustTraction(b2Body* body, float amount)
{
    const float velocityY = body->linearVelocity.y;
    const float lateralY = body->GetXForm().rotation[1];
    const float velocityX = body->linearVelocity.x;
    const float lateralX = body->GetXForm().rotation[0];
    const float correction = (lateralX * velocityX + lateralY * velocityY) * amount;
    body->linearVelocity.y = velocityY - correction * lateralY;
    body->linearVelocity.x = velocityX - correction * lateralX;
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

void Vehicle::_setYaw(float radians)
{
    basisY.Y = -1.0f;
    basisX.X = -1.0f;
    basisY.X = 0.0f;
    basisY.Z = 0.0f;
    basisX.Y = 0.0f;
    basisX.Z = 0.0f;
    rotateBasisPair<&irr::core::vector3d<float>::rotateXYBy>(basisY, basisX, radians, -57.2957763671875f);
}

void Vehicle::_setRoll(float radians)
{
    basisX.X = 1.0f;
    basisZ.Z = 1.0f;
    basisX.Y = 0.0f;
    basisX.Z = 0.0f;
    basisZ.X = 0.0f;
    basisZ.Y = 0.0f;
    rotateBasisPair<&irr::core::vector3d<float>::rotateXZBy>(basisX, basisZ, radians);
}

void Vehicle::_setPitch(float radians)
{
    basisY.Y = 1.0f;
    basisZ.Z = 1.0f;
    basisY.X = 0.0f;
    basisY.Z = 0.0f;
    basisZ.X = 0.0f;
    basisZ.Y = 0.0f;
    rotateBasisPair<&irr::core::vector3d<float>::rotateYZBy>(basisY, basisZ, radians);
}

void Vehicle::WarmUp()
{
    LevelObject::WarmUp();
    if (hasSceneNodePool())
        SceneNodeManager::getInstance()->manage(s_nodePoolID[objectType], this, 19);
}

void Vehicle::tagForKill(bool tagged)
{
    const unsigned int killTarget = 1u << 25;
    if (tagged) {
        flags344 |= killTarget;
        unknown4 |= 4u;
        ScriptManager::getInstance()->displayOnMinimap(this, true, true);
        showHighlight(0);
    } else {
        flags344 &= ~killTarget;
        ScriptManager::getInstance()->displayOnMinimap(this, false, true);
        showHighlight(-1);
    }
}

void Vehicle::init()
{
    if (!collisionBody)
        CreateBody();

    unknown506 = false;
    unknown507 = false;
    unknown508 = false;
    unknown509 = false;
    unknown511 = false;
    sensorContactCount = 0;
    turnSoundPlaying = false;
    skidSoundPlaying = false;
    unknown924 = 0;
    speed = 0.0f;
    unknown776 = 0.0f;
}

void Vehicle::OnSpawn()
{
    if (hasSceneNodePool() && !sceneNode)
        grabSceneNode(0, 0);

    hasBeenStolen = false;
    flags344 |= 1u << 23;
    unknown4 |= 2u;
    LevelObject::OnSpawn();
    init();
    sceneNode->setVisible(true);
    ResetBodyPosition();
    enabledSceneNode->setVisible(true);
    unknown4 |= 4u;
    _resetLights();
    flags344 &= ~2u;
}

void Vehicle::enable()
{
    const bool wasEnabled = isEnabled();
    LevelObject::enable();
    flags344 &= ~(1u << 28);
    if (!wasEnabled) {
        init();
        enabledSceneNode->setVisible(true);
        unknown4 |= 4u;
    }
    repair();
    hasBeenStolen = false;
}

void Vehicle::initializeDriver()
{
    if ((flags344 & 0x800u) && !unknown28)
        resetDriver();

    if (driver) {
        driver->positionInVehicle(true);
        driver->show();
    }
}

void Vehicle::resetDriver()
{
    setDriver(GameObjectManager::s_gom->spawnNPCInVehicle(this, driverMetatype, driverBehavior));
}

void Vehicle::resetPreviousPos()
{
    const irr::core::matrix4& transform = sceneNode->getAbsoluteTransformation();
    const float offsetZ = bodyOffset.X * transform[2] +
        bodyOffset.Y * transform[6] + bodyOffset.Z * transform[10];
    const b2Vec2& bodyPosition = collisionBody->GetXForm().position;
    const float x = 100.0f * bodyPosition.x;
    const float y = 100.0f * bodyPosition.y;
    const float height = (wheelPositions[0].Z + wheelPositions[1].Z +
        wheelPositions[2].Z + wheelPositions[3].Z) * 0.25f;
    previousPosition = irr::core::vector3d<float>(x, y, height - offsetZ);
}

void Vehicle::resetVehicle()
{
    SetPosition(irr::core::vector3d<float>(-42205.0f, -27279.0f, 678.0f));
    basisX.X = 1.0f;
    basisY.Y = 1.0f;
    basisZ.Z = 1.0f;
    rotationZ = 0.0f;
    rotationX = 0.0f;
    rotationY = 0.0f;
    unknown752 = 0.0f;
    unknown756 = 0.0f;
    basisX.Y = 0.0f;
    basisX.Z = 0.0f;
    basisY.X = 0.0f;
    basisY.Z = 0.0f;
    basisZ.X = 0.0f;
    basisZ.Y = 0.0f;
    unknown56 = 0.0f;
    unknown60 = 1.5f;
    unknown64 = 0.0f;
    resetPreviousPos();
    hasBeenStolen = false;
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


void Vehicle::mobilize()
{
    const bool skipBlockingCommands = ScriptManager::getInstance()->areBlockingCommandsSkipped();
    if (!skipBlockingCommands) {
        collisionBody->SetMassFromShapes();
        b2Body* body = collisionBody;
        b2MassData bodyMass;
        bodyMass.I = body->inertia;
        bodyMass.center.x = body->localCenter.x;
        bodyMass.center.y = body->localCenter.y;
        bodyMass.mass = static_cast<float>(mass) / 3.0f;
        body->SetMass(&bodyMass);

        leftCollisionBody->SetMassFromShapes();
        rightCollisionBody->SetMassFromShapes();
        body = leftCollisionBody;
        b2MassData sideMass;
        sideMass.I = body->inertia;
        sideMass.center.x = body->localCenter.x;
        sideMass.center.y = body->localCenter.y;
        sideMass.mass = static_cast<float>(mass) / 3.0f;
        body->SetMass(&sideMass);
        rightCollisionBody->SetMass(&sideMass);
        immobilized = skipBlockingCommands;
    }
    Stop();
}

irr::scene::ISceneNode* Vehicle::getNearestDoorDummy(irr::core::vector3d<float> point)
{
    point.Z = 0.0f;
    irr::core::vector3d<float> left = leftDoor->getAbsolutePosition();
    irr::core::vector3d<float> right = rightDoor->getAbsolutePosition();
    left.Z = 0.0f;
    right.Z = 0.0f;
    if (point.getDistanceFromSQ(left) < point.getDistanceFromSQ(right))
        return leftDoor;
    return rightDoor;
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

const irr::core::aabbox3d<float>& Vehicle::GetMeshBoundingBox(
    const irr::scene::ISceneNode* node) const
{
    const int colladaMeshNode = 0x6d656164;
    const int colladaSkinnedNode = 0x73656164;
    if (node->getType() == colladaMeshNode || node->getType() == colladaSkinnedNode)
        return node->getTransformedBoundingBox();

    return GetMeshBoundingBox(node->getChildren().begin()->value);
}

void Vehicle::enableBackfaceCulling(bool enabled)
{
    GS3DStuff::SetMaterialFlag(exterior, irr::video::MaterialFlag512, enabled);
}

namespace {
inline __attribute__((always_inline)) void resetLightPair(
    irr::scene::ISceneNode* const& first, irr::scene::ISceneNode* const& second)
{
    if (first && second) {
        GS3DStuff::SetMaterialFlag(first, irr::video::MaterialFlag512, false);
        GS3DStuff::SetMaterialFlag(second, irr::video::MaterialFlag512, false);
        GS3DStuff::SetMaterialFlag(first, irr::video::MaterialFlag2, false);
        GS3DStuff::SetMaterialFlag(second, irr::video::MaterialFlag2, false);
        GS3DStuff::SetMaterialType(first, irr::video::MaterialType13);
        GS3DStuff::SetMaterialType(second, irr::video::MaterialType13);
        first->setVisible(false);
        second->setVisible(false);
    }
}
}

void Vehicle::_resetLights()
{
    resetLightPair(lightNodes[0], lightNodes[1]);
    resetLightPair(lightNodes[2], lightNodes[3]);
}

void Vehicle::rent(bool rented)
{
    int highlight;
    if (rented) {
        flags344 |= 0x10000u;
        highlight = 1;
    } else {
        flags344 &= ~0x10000u;
        highlight = -1;
    }
    showHighlight(highlight);
    ScriptManager::displayOnMinimap(this, rented, true);
}

inline __attribute__((always_inline)) void Vehicle::setWheelVisibility(bool visible)
{
    GS3DStuff::SetVisibility(wheelNodes[0], visible);
    GS3DStuff::SetVisibility(wheelNodes[1], visible);
    GS3DStuff::SetVisibility(wheelNodes[2], visible);
    GS3DStuff::SetVisibility(wheelNodes[3], visible);
}

void Vehicle::loadExplosion(const char* name)
{
    explosionAnimator = irr::collada::CColladaDatabase::constructAnimator(
        name, &irr::collada::CColladaDatabase::DefaultFactory);
    if (explosionAnimator)
        explosionTimeline = explosionAnimator->getTimelineCtrl();
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
extern unsigned char _ZZN9AIManager11getInstanceEvE3aim[];

void _ZN12CGameFactoryD1Ev(void*) __attribute__((weak));
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

}


namespace {
inline __attribute__((always_inline)) void disableWheelCollisions(b2Body* body, b2FilterData& saved)
{
    for (b2Shape* shape = body->shapeList; shape; shape = shape->next) {
        if (shape->filter.maskBits) {
            saved = shape->filter;
            b2FilterData filter = saved;
            filter.maskBits = 0;
            shape->filter = filter;
        }
    }
}
}

namespace irr {
namespace video { class IVideoDriver; }
namespace scene {
class IColladaMesh {
public:
    enum E_PREPARE_BUFFER_STEP {};
};
}
namespace collada {
// Partial layout for the render preparation call.
class CColladaMorphingMesh {
public:
    unsigned int onPrepareBufferForRendering(
        scene::IColladaMesh::E_PREPARE_BUFFER_STEP, video::IVideoDriver*, unsigned int);

private:
    unsigned char unknown[88];
};
}
}

class CCarMorphingMesh : public irr::collada::CColladaMorphingMesh {
public:
    unsigned int onPrepareBufferForRendering(
        irr::scene::IColladaMesh::E_PREPARE_BUFFER_STEP step,
        irr::video::IVideoDriver* driver, unsigned int buffer) __attribute__((weak));

private:
    bool prepareBuffer;
};

unsigned int CCarMorphingMesh::onPrepareBufferForRendering(
    irr::scene::IColladaMesh::E_PREPARE_BUFFER_STEP step,
    irr::video::IVideoDriver* driver, unsigned int buffer)
{
    if (!prepareBuffer)
        return 16;

    const unsigned int result =
        CColladaMorphingMesh::onPrepareBufferForRendering(step, driver, buffer);
    prepareBuffer = false;
    return result;
}

class CCarFactory : public irr::collada::CColladaFactory {
public:
    virtual ~CCarFactory() __attribute__((used));
    static CCarFactory* getInstance() __attribute__((weak, used))
    {
        static CCarFactory cf;
        return &cf;
    }
    virtual void* createMorph(const irr::collada::CColladaDatabase&, irr::collada::SController*);
    virtual irr::collada::CSceneNode* createNode(const irr::collada::CColladaDatabase&, irr::collada::SNode*) __attribute__((weak));
    virtual void* createSkinNode(const irr::collada::CColladaDatabase&, irr::scene::IColladaMesh*,
                                 irr::collada::IRootSceneNode*, void*);
};

irr::collada::CSceneNode* CCarFactory::createNode(
    const irr::collada::CColladaDatabase& database, irr::collada::SNode* node)
{
    char value[256];
    if (node && GS3DStuff::getProperty(node->properties, GameFactoryProperties::billboard, value) && atoi(value) == 1)
        return new CustomBillboardSceneNode(database, node);
    return new (irr::DefaultMemHint) irr::collada::CSceneNode(database, node);
}

extern "C" void _ZN26CustomSkinnedMeshSceneNodeC1EPN3irr5scene12IColladaMeshEPNS0_7collada14IRootSceneNodeEPNS4_5SNodeEiRKNS0_4core8vector3dIfEERKNS9_10quaternionESD_(
    CustomSkinnedMeshSceneNode*, irr::scene::IColladaMesh*, irr::collada::IRootSceneNode*,
    irr::collada::SNode*, int, const irr::core::vector3d<float>&,
    const irr::core::quaternion&, const irr::core::vector3d<float>&) __attribute__((weak));

void* __attribute__((weak)) CCarFactory::createSkinNode(
    const irr::collada::CColladaDatabase&, irr::scene::IColladaMesh* mesh,
    irr::collada::IRootSceneNode* root, void*)
{
    const irr::core::vector3d<float> position;
    const irr::core::quaternion rotation;
    const irr::core::vector3d<float> scale(1.0f, 1.0f, 1.0f);
    CustomSkinnedMeshSceneNode* node = static_cast<CustomSkinnedMeshSceneNode*>(
        ::operator new(sizeof(CustomSkinnedMeshSceneNode)));
    _ZN26CustomSkinnedMeshSceneNodeC1EPN3irr5scene12IColladaMeshEPNS0_7collada14IRootSceneNodeEPNS4_5SNodeEiRKNS0_4core8vector3dIfEERKNS9_10quaternionESD_(
        node, mesh, root, 0, -1, position, rotation, scale);
    return node;
}

inline CCarFactory::~CCarFactory()
{
}

void Vehicle::removeWheelCollisions()
{
    disableWheelCollisions(leftCollisionBody, collisionFilter);
    disableWheelCollisions(rightCollisionBody, collisionFilter);
}

void Vehicle::resetCollisions()
{
    if (isEnabled()) {
        for (b2Shape* shape = collisionBody->shapeList; shape; shape = shape->next)
            shape->filter = collisionFilter;
    }
}

void __attribute__((weak)) Vehicle::playSiren()
{
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    const int channel = sound->playEx(241, 0, true, 1.0f, 0, false, 1.0f, 0);
    sound->unknown140 = false;
    sirenChannel = channel;
    if (channel >= 0)
        flags344 |= 1u << 27;
}

void __attribute__((weak)) Vehicle::stopSiren()
{
    const unsigned int sirenPlaying = 1u << 27;
    if (flags344 & sirenPlaying) {
        SoundManager::getInstance()->stop(241, sirenChannel, 1000);
        flags344 &= ~sirenPlaying;
    }
}

extern "C" void _ZN12EvNPCVehicleD1Ev(void*) __attribute__((weak));


class EvVehicleDeactivated : public IEvent {
public:
    explicit EvVehicleDeactivated(Vehicle* vehicle) : vehicle(vehicle) { eventID = 21; }
    Vehicle* vehicle;
    virtual ~EvVehicleDeactivated() __attribute__((used));
};

inline EvVehicleDeactivated::~EvVehicleDeactivated()
{
}

extern "C" void _ZN20EvVehicleDeactivatedD1Ev(void*) __attribute__((weak));

void Vehicle::clean()
{
    AIManager::getInstance()->removeAI(this);
    if (collisionBody) {
        DestroyWheels();
        if (collisionBody->data) {
            ::operator delete(collisionBody->data);
            collisionBody->data = 0;
        }
        PhysicAttributes::s_world->DestroyBody(collisionBody);
        collisionBody = 0;
        enabledSceneNode->setVisible(false);
        if (unknown24) {
            delete unknown24;
            unknown24 = 0;
        }
        EventManager* events = Application::GetInstance()->GetEventManager();
        unsigned int storage[sizeof(EvVehicleDeactivated) / sizeof(unsigned int)];
        EvVehicleDeactivated* event = new (storage) EvVehicleDeactivated(this);
        events->raise(*event);
        _ZN20EvVehicleDeactivatedD1Ev(event);
    }
}

class EvVehicleDestroyed : public IEvent {
public:
    virtual ~EvVehicleDestroyed() __attribute__((used));
};

inline EvVehicleDestroyed::~EvVehicleDestroyed()
{
}

void Vehicle::cleanupTargetDetection()
{
    const unsigned int detectingTarget = 1u << 14;
    if (flags344 & detectingTarget) {
        flags344 &= ~detectingTarget;
        EventManager* events = Application::GetInstance()->GetEventManager();
        unsigned int storage[sizeof(EvNPCVehicle) / sizeof(unsigned int)] __attribute__((aligned(__alignof__(EvNPCVehicle))));
        EvNPCVehicle* event = new (storage) EvNPCVehicle(19, this);
        events->raise(*event);
        _ZN12EvNPCVehicleD1Ev(event);
    }
}

void Vehicle::notifyHitNPCofDespawn()
{
    for (LevelObject* object = GameObjectManager::s_gom->GetFirst(0); object; object = object->next) {
        if (LevelObject::s_type[object->getObjectType()] == 5) {
            Character* character = static_cast<Character*>(object);
            if (character->lastHitVehicle == this)
                character->lastHitVehicle = 0;
        }
    }

    PlayerTest* player = PlayerTest::GetPlayer();
    if (__builtin_expect(reinterpret_cast<unsigned int>(this) - reinterpret_cast<unsigned int>(player->lastHitVehicle), 1) == 0u)
        player->lastHitVehicle = 0;
}

void Vehicle::clearOnAlert()
{
    stopSiren();
    cleanupTargetDetection();
    alertState = 0;
    flags344 &= ~0x47000u;
}

void Vehicle::onCameraEnter()
{
    const unsigned int radioEnabled = 1u << 23;
    const unsigned int radioStarted = 1u << 24;
    if (!(flags344 & radioEnabled))
        return;

    if (!(flags344 & radioStarted)) {
        SoundManager::getInstance()->playRadio(defaultRadioStation);
        flags344 |= radioStarted;
    } else {
        SoundManager::getInstance()->playRadio(savedRadioStation);
    }
    Application::GetInstance()->GetHudManager()->hide();
    if (!ScriptManager::getInstance()->isInCinematic())
        Application::GetInstance()->GetHudManager()->show();
}

void Vehicle::UnRegisterCarSoundsCallbacks()
{
    CarSounds::UnregisterCallbacks();
}

void Vehicle::RegisterCarSoundsCallbacks()
{
    CarSoundCallbacks callbacks;
    SoundManager::getInstance();
    callbacks.isSoundPlaying = SoundManager::isSoundPlayingCallback;
    SoundManager::getInstance();
    // Retail stores the callback directly. The default play stub returns -1.
    callbacks.play = reinterpret_cast<int (*)(int, bool, float, float)>(
        SoundManager::playSoundCallback);
    SoundManager::getInstance();
    callbacks.stop = SoundManager::stopSoundCallback;
    SoundManager::getInstance();
    callbacks.setPitch = SoundManager::setPitchCallback;
    SoundManager::getInstance();
    callbacks.setVolume = SoundManager::setVolumeCallback;
    CarSounds::RegisterCallbacks(callbacks);
}

int __attribute__((weak)) Vehicle::getMarkerType()
{
    return -1;
}
