/*
 * Vehicle
 *
 * Original file: Vehicle.cpp
 * Area:          vehicles
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Vehicle.cpp here, in the order they appear in the library.
 */

#include "../characters/PhysicInfo.h"
#include "../core/Randomizer.h"
#include "../world/LevelObject.h"
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
#include "../world/ObjectData.h"
#include "../core/NativeStrings.h"
#include "../core/Lock.h"
#include "../rendering/CustomBillboardSceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/PhysicsBodyDef.h"
#include "../core/VideoDriver.h"
#include "../core/MeshBufferInterfaces.h"
#include "../core/MeshSceneInterfaces.h"
#include "../rendering/GS3DStuff.h"
#include "../world/TrailMgr.h"
#include "../world/Trail.h"

extern "C" float __aeabi_fmul(float, float) __attribute__((const));
extern "C" float __aeabi_fadd(float, float) __attribute__((const));
extern "C" int puts(const char*);
void aTransitionCallback(irr::scene::ITimelineController*, void*);

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

namespace irr {
namespace scene {
class IMeshBuffer;
class CColladaMeshSceneNode : public IMeshSceneNode {
public:
    virtual ~CColladaMeshSceneNode();
    virtual void OnRegisterSceneNode();
    virtual void OnAnimate(unsigned int);
    virtual void render(void*);
    virtual unsigned int getRenderVertexCount(void*);
    virtual const core::aabbox3d<float>& getBoundingBox() const;
    virtual void setVisible(bool);
    virtual const char* getUID() const;
    virtual video::SMaterial& getMaterial(unsigned int);
    virtual unsigned int getMaterialCount() const;
    virtual void notifyMaterialChanged();
    virtual int getType() const;
    virtual void onMaterialChanged();
    virtual void notifyVisibilityChanged(bool);
    virtual void setMesh(IMesh*);
    virtual IMesh* getMesh();
    virtual void setReadOnlyMaterials(bool);
    virtual bool isReadOnlyMaterials() const;
    virtual IMeshBuffer* getMeshBuffer(unsigned int);
};
}
namespace collada {
class CSkinnedMeshSceneNode : public scene::CColladaMeshSceneNode {
public:
    CSkinnedMeshSceneNode(scene::IColladaMesh*, IRootSceneNode*, SNode*, int,
        const core::vector3d<float>&, const core::quaternion&, const core::vector3d<float>&);
    virtual ~CSkinnedMeshSceneNode() {}
    virtual void serializeAttributes(io::IAttributes*, io::SAttributeReadWriteOptions*) const;
    virtual void deserializeAttributes(io::IAttributes*, io::SAttributeReadWriteOptions*);
    virtual void OnAnimate(unsigned int);
    virtual void render(void*);
    virtual const core::aabbox3d<float>& getTransformedBoundingBox() const;
    virtual int getType() const;
    void setIsSkinningEnabled(bool);
protected:
    unsigned char unknown328[4];
    SkinBoundsSource* skin;
    unsigned char unknown336[56];
};
}
}

class CustomSkinnedMeshSceneNode : public irr::collada::CSkinnedMeshSceneNode {
public:
    CustomSkinnedMeshSceneNode(irr::scene::IColladaMesh*, irr::collada::IRootSceneNode*, irr::collada::SNode*, int,
        const irr::core::vector3d<float>&, const irr::core::quaternion&, const irr::core::vector3d<float>&);
    virtual ~CustomSkinnedMeshSceneNode() {}
    virtual const irr::core::aabbox3d<float>& getBoundingBox() const __attribute__((weak));
    virtual const irr::core::aabbox3d<float>& getTransformedBoundingBox() const __attribute__((weak));
};

typedef char CustomSkinnedMeshSceneNodeExtent[sizeof(CustomSkinnedMeshSceneNode) == 404 ? 1 : -1];

CustomSkinnedMeshSceneNode::CustomSkinnedMeshSceneNode(
    irr::scene::IColladaMesh* mesh, irr::collada::IRootSceneNode* root, irr::collada::SNode* node, int id,
    const irr::core::vector3d<float>& position, const irr::core::quaternion& rotation,
    const irr::core::vector3d<float>& scale)
    : irr::collada::CSkinnedMeshSceneNode(mesh, root, node, id, position, rotation, scale)
{
}

struct SkinNodeBoundsLayout {
    unsigned char opaque0[36];
    irr::core::matrix4 absoluteTransform;
    unsigned char opaque104[108];
    mutable irr::core::aabbox3d<float> transformedBounds;
};

const irr::core::aabbox3d<float>& CustomSkinnedMeshSceneNode::getBoundingBox() const
{
    return skin->mesh->getBoundingBox();
}

const irr::core::aabbox3d<float>& CustomSkinnedMeshSceneNode::getTransformedBoundingBox() const
{
    const irr::scene::ISceneNode* node = reinterpret_cast<const irr::scene::ISceneNode*>(this);
    const SkinNodeBoundsLayout* bounds = reinterpret_cast<const SkinNodeBoundsLayout*>(this);
    bounds->transformedBounds = node->getBoundingBox();
    bounds->absoluteTransform.transformBoxEx(bounds->transformedBounds);
    return bounds->transformedBounds;
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
    const float height = (wheelPosition0.Z + wheelPosition1.Z +
        wheelPosition2.Z + wheelPosition3.Z) * 0.25f;
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


float Vehicle::_adjustEnginePitch(unsigned int speed)
{
    using namespace gameloft::vehicle::gear_profiles;
    float range;
    float result = 0.0f;
    const GearProfile& profile = profiles[gearProfile];
    if (gear == profile.gearCount) {
        const unsigned int lower = profile.shiftSpeeds[gear - 2];
        const unsigned int span = lower - profile.shiftSpeeds[gear - 3];
        if (speed > lower + span) {
            range = static_cast<float>(span);
        } else {
            range = static_cast<float>(span);
            gearProgress = static_cast<float>(speed - lower) / range;
        }
    } else if (gear == 1 || gear == static_cast<unsigned int>(-1)) {
        gearProgress = static_cast<float>(speed) / (range = static_cast<float>(profile.shiftSpeeds[0]));
        result = 1.0f - gearProgress;
    } else {
        const unsigned int lower = profile.shiftSpeeds[gear - 2];
        range = static_cast<float>(profile.shiftSpeeds[gear - 1] - lower);
        gearProgress = static_cast<float>(speed - lower) / range;
    }
    if (gearProgress > 1.0f)
        gearProgress = 1.0f;
    else if (gearProgress < 0.0f)
        gearProgress = 0.0f;

    enginePitchSpeed = static_cast<float>(speed) - __aeabi_fmul(range, 1.0f - gearProgress) * enginePitchFalloff;
    if (enginePitchSpeed < 0.0f)
        enginePitchSpeed = 0.0f;
    return result;
}

void Vehicle::UpdateCarSounds()
{
    carSoundParameters->mode = carSoundMode;
    const int mode = carSoundMode;

    if (mode == 1) {
        carSoundParameters->rpm =
            static_cast<int>((enginePitchSpeed / soundMaximumSpeed) * soundRpmRange) + soundMinimumRpm;
        carSoundParameters->trigger = carSoundTrigger;
        carSoundParameters->gear = gear;

        if (soundLoadCountdown) {
            carSoundParameters->load = previousSoundLoad;
        } else {
            if (previousSoundGear == static_cast<float>(gear) &&
                previousSoundRpm <= carSoundParameters->rpm && carSoundParameters->rpm != 0) {
                if (previousSoundRpm < carSoundParameters->rpm)
                    carSoundParameters->load = mode;
                else
                    carSoundParameters->load = previousSoundLoad;
            } else {
                carSoundParameters->load = 0;
            }
            if (previousSoundLoad != carSoundParameters->load)
                soundLoadCountdown = soundLoadDuration;
        }
        if (--soundLoadCountdown < 0)
            soundLoadCountdown = 0;

        carSoundParameters->scale = 1.0f;
        carSoundParameters->rpmCopyB = carSoundParameters->rpm;
        carSoundParameters->rpmCopyA = carSoundParameters->rpm;
        carSounds->Update(carSoundParameters);
        previousSoundGear = static_cast<float>(gear);
        previousSoundRpm = carSoundParameters->rpm;
        previousSoundLoad = carSoundParameters->load;
        if (carSoundTrigger)
            carSoundTrigger = false;
    } else if (mode == 2) {
        carSounds->Update(carSoundParameters);
        carSoundMode = 0;
    }
}

void Vehicle::stopDriving()
{
    _cleanupSounds();
    Character* currentDriver = driver;
    Character* player = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
    const unsigned int driverAddress = reinterpret_cast<unsigned int>(currentDriver);
    const unsigned int playerAddress = reinterpret_cast<unsigned int>(player);
    if (driverAddress - playerAddress == 0) {
        for (int wheel = 0; wheel < 4; ++wheel) {
            if (wheelTrails[wheel]) {
                GS3DStuff::GetTrailMgr()->FreeTrail(wheelTrails[wheel]);
                wheelTrails[wheel] = 0;
            }
        }
    }
    setDriver(0);
    flags344 &= ~0x10u;
    unknown4 |= 4u;
}

void Vehicle::_cleanupSounds()
{
    if (driver == reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))) {
        savedRadioStation = SoundManager::getInstance()->radioStation;
        SoundManager::getInstance()->stopRadio();
        SoundManager::getInstance()->stop(123, -1, 0);
        SoundManager::getInstance()->stop(106, -1, 0);
        carSoundMode = 2;
        UpdateCarSounds();
    }

    if (skidSoundPlaying) {
        SoundManager::getInstance()->stop(119, -1, 0);
        skidSoundPlaying = false;
    }
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

void Vehicle::cleanTargets()
{
    for (LevelObject* object = GameObjectManager::s_gom->GetFirst(0); object; object = object->next) {
        const int type = LevelObject::s_type[object->getObjectType()];
        if (type == 5) {
            Character* character = static_cast<Character*>(object);
            if (character->target == this)
                character->SetTarget(0);
            if (reinterpret_cast<unsigned int>(this) -
                reinterpret_cast<unsigned int>(character->lastHitVehicle) == 0)
                character->lastHitVehicle = 0;
            if (character->getVehicle() == this)
                character->setVehicle(0);
        } else if (type == 3) {
            Vehicle* other = static_cast<Vehicle*>(object);
            if (other->aiTarget == this)
                other->aiTarget = 0;
        }
    }
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
namespace scene {
class IColladaMesh : public IMesh {
public:
    enum E_PREPARE_BUFFER_STEP {};
    virtual ~IColladaMesh();
    virtual int getType() const = 0;
    virtual void onAnimate(unsigned int);
    virtual unsigned int onPrepareBufferForRendering(E_PREPARE_BUFFER_STEP, video::IVideoDriver*, unsigned int);
    virtual void releaseProcessBuffer(video::IVideoDriver*, unsigned int);

private:
    unsigned char unknown4[36];
};
}
namespace collada {
class CColladaMorphingMesh : public scene::IColladaMesh {
public:
    CColladaMorphingMesh(const CColladaDatabase&, SController&, bool, video::IVideoDriver*);
    virtual ~CColladaMorphingMesh();
    virtual unsigned int getMeshBufferCount() const;
    virtual scene::IMeshBuffer* getMeshBuffer(unsigned int) const;
    virtual scene::IMeshBuffer* getMeshBuffer(const video::SMaterial&) const;
    virtual const core::aabbox3d<float>& getBoundingBox() const;
    virtual void setBoundingBox(const core::aabbox3d<float>&);
    virtual void setMaterialFlag(video::E_MATERIAL_FLAG, bool);
    virtual void* getUserProperty() const;
    virtual int getType() const;
    virtual unsigned int onPrepareBufferForRendering(
        scene::IColladaMesh::E_PREPARE_BUFFER_STEP, video::IVideoDriver*, unsigned int);
    virtual void releaseProcessBuffer(video::IVideoDriver*, unsigned int);

private:
    unsigned char unknown40[48];
};
}
}

class CCarMorphingMesh : public irr::collada::CColladaMorphingMesh {
public:
    CCarMorphingMesh(const irr::collada::CColladaDatabase& db, irr::collada::SController& controller,
                     irr::video::IVideoDriver* driver)
        : irr::collada::CColladaMorphingMesh(db, controller, false, driver), prepareBuffer(true) {}
    virtual ~CCarMorphingMesh() __attribute__((used));
    virtual unsigned int onPrepareBufferForRendering(
        irr::scene::IColladaMesh::E_PREPARE_BUFFER_STEP step,
        irr::video::IVideoDriver* driver, unsigned int buffer) __attribute__((weak));

private:
    bool prepareBuffer;
};

inline CCarMorphingMesh::~CCarMorphingMesh()
{
}

typedef char CarMorphingMeshExtent[sizeof(CCarMorphingMesh) == 104 ? 1 : -1];

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

void* CCarFactory::createMorph(const irr::collada::CColladaDatabase& database, irr::collada::SController* controller)
{
    irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();
    return new (irr::DefaultMemHint) CCarMorphingMesh(database, *controller, driver);
}

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



#include "VehicleEvents.h"

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



inline EvVehicleDestroyed::~EvVehicleDestroyed()
{
}

void Vehicle::cleanupTargetDetection()
{
    const unsigned int detectingTarget = 1u << 14;
    if (flags344 & detectingTarget) {
        flags344 &= ~detectingTarget;
        EventManager* events = Application::GetInstance()->GetEventManager();
        EvNPCVehicle event(19, this);
        events->raise(event);
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
    aiTarget = 0;
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

void Vehicle::startDriving()
{
    unknown4 &= ~4u;
    if (flags344 & 0x10000u) {
        showHighlight(-1);
        ScriptManager::displayOnMinimap(this, false, true);
    }
    if (flags344 & 0x800u) {
        EventManager* events = Application::GetInstance()->GetEventManager();
        unsigned int storage[sizeof(EvVehicleDeactivated) / sizeof(unsigned int)];
        EvVehicleDeactivated* event = new (storage) EvVehicleDeactivated(this);
        events->raise(*event);
        _ZN20EvVehicleDeactivatedD1Ev(event);
        flags344 &= ~0x800u;
    }
    flags344 |= 0x10u;
    unknown511 = false;
    skidAmount = 0.0f;
    GS3DStuff::GetTrailMgr()->SetSegmentWidth(static_cast<float>(tireTrailWidth));
    carSoundMode = 1;
    carSoundTrigger = true;
}

extern "C" long lrand48();

void Vehicle::playHorn()
{
    const int choice = lrand48() % 7;
    if (driverBehavior == -1)
        driverBehavior = lrand48() % 2;

    int horn = 226;
    if (driverBehavior == 0) {
        switch (choice) {
        case 2: horn = 230; break;
        case 3: horn = 232; break;
        case 1: horn = 239; break;
        case 6: horn = 243; break;
        case 5: horn = 244; break;
        case 4: horn = 229; break;
        default: break;
        }
    } else {
        switch (choice) {
        case 2: horn = 230; break;
        case 3: horn = 232; break;
        case 1: horn = 239; break;
        case 6: horn = 234; break;
        case 5: horn = 227; break;
        case 4: horn = 236; break;
        default: break;
        }
    }
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(horn, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    turnSoundPlaying = true;
}

struct VehicleDriveSfxView {
    unsigned char pad0[132];
    int unknown132;
    unsigned char pad136[344 - 136];
    unsigned int flags344;
    unsigned char pad348[364 - 348];
    int init364;
    unsigned char pad368[506 - 368];
    bool unknown506;
    bool unknown507;
    bool unknown508;
    bool unknown509;
    unsigned char unknown510;
    unsigned char pad511[648 - 511];
    float skidAmount;
};

extern "C" float _ZN7Vehicle18_adjustEnginePitchEj(Vehicle* self, unsigned int speed);

extern "C" void _ZN7Vehicle12playDriveSfxEj(Vehicle* self, unsigned int speed)
{
    VehicleDriveSfxView* view = reinterpret_cast<VehicleDriveSfxView*>(self);
    if (!(view->flags344 & 0x10))
        return;

    if (view->skidAmount > 0.0f && view->unknown509 && view->unknown508 && view->unknown507 && view->unknown506
        && !SoundManager::getInstance()->isSoundPlaying(123)) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(123, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    } else if (view->skidAmount > 0.0f && view->unknown509 && view->unknown508 && view->unknown507 && view->unknown506
               && !view->unknown510 && !(view->skidAmount <= 0.0f)) {
        if ((view->flags344 & 2) && view->unknown132 == 1 && !view->unknown510
            && !SoundManager::getInstance()->isSoundPlaying(106)) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(106, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        } else if (!((view->flags344 & 2) && view->unknown132 == 1 && !view->unknown510)
                   && SoundManager::getInstance()->isSoundPlaying(106)) {
            SoundManager::getInstance()->stop(106, -1, 0);
        }
    } else {
        SoundManager::getInstance()->stop(123, -1, 0);
    }

    if (!view->unknown506 && !view->unknown507 && !view->unknown508 && !view->unknown509)
        view->unknown510 = true;
    if (view->unknown510 && (view->unknown506 || view->unknown507 || view->unknown508 || view->unknown509)) {
        view->unknown510 = false;
        SoundManager* sound = SoundManager::getInstance();
        int id = Vehicle::s_smallImpactSounds[lrand48() % 3];
        sound->unknown140 = true;
        sound->playEx(id, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }

    int newState;
    int state;
    if (speed > 1) {
        _ZN7Vehicle18_adjustEnginePitchEj(self, speed);
        newState = 1;
        state = 1;
    } else {
        newState = 0;
        state = 0;
    }
    if (view->init364 != state)
        view->init364 = newState;
}

namespace {
inline void subtractVector(irr::core::vector3d<float>& target, const irr::core::vector3d<float>& value)
{
    target.X -= value.X;
    target.Y -= value.Y;
    target.Z -= value.Z;
}

inline void setVector(b2Vec2& u, float x, float y)
{
    u.x = x;
    u.y = y;
}

inline irr::core::vector3d<float> scaledVector(const irr::core::vector3d<float>& v, const float& s)
{
    return irr::core::vector3d<float>(v.X * s, v.Y * s, v.Z * s);
}

inline void multiplyVector(b2Vec2& v, float a)
{
    v.x *= a;
    v.y *= a;
}

}

void Vehicle::getCollisionRect(irr::core::vector3d<float>* corners, float margin)
{
    if (!isEnabled())
        return;
    b2Vec2 points[4];
    // Unused member reads (removed as dead code) release SSA names that the
    // later scalarised right/front components reuse, which gives retail's
    // operand order in the post-loop multiplies.
    const float unusedA = unknown56;
    const float unusedB = unknown60;
    const float unusedC = unknown64;
    const float unusedD = init104;
    const float unusedE = init108;
    const float unusedF = init112;
    const float unusedG = unknown116;
    (void)unusedA; (void)unusedB; (void)unusedC; (void)unusedD; (void)unusedE; (void)unusedF; (void)unusedG;
    for (b2Shape* shape = collisionBody->shapeList; shape; shape = shape->next) {
        const b2PolygonShape* polygon = static_cast<const b2PolygonShape*>(shape);
        for (int i = 0; i < 4; ++i) {
            const b2XForm& xf = collisionBody->GetXForm();
            b2Vec2 r;
            setVector(r, xf.rotation[0] * polygon->vertices[i].x + xf.rotation[2] * polygon->vertices[i].y, xf.rotation[1] * polygon->vertices[i].x + xf.rotation[3] * polygon->vertices[i].y);
            float x = r.x;
            float y = r.y;
            const float px = xf.position.x;
            y += xf.position.y;
            // Overwritten below in the same iteration; keeps the angle load as a
            // third float PRE value, which gives retail's spill-slot order.
            points[static_cast<unsigned int>(i)].y = collisionBody->angle;
            x += px;
            points[i] = b2Vec2(x, y);
            multiplyVector(points[i], 100.0f);
        }
    }
    corners[0] = irr::core::vector3d<float>(points[0].x, points[0].y, 0.0f);
    corners[1] = irr::core::vector3d<float>(points[1].x, points[1].y, 0.0f);
    corners[2] = irr::core::vector3d<float>(points[2].x, points[2].y, 0.0f);
    corners[3] = irr::core::vector3d<float>(points[3].x, points[3].y, 0.0f);
    irr::core::vector3d<float> right = LevelObject::GetRight();
    irr::core::vector3d<float> front = LevelObject::GetFront();
    corners[0] += scaledVector(front, margin) * 3.0f;
    corners[0] += scaledVector(right, margin);
    corners[1] += scaledVector(front, margin) * 3.0f;
    subtractVector(corners[1], scaledVector(right, margin));
    subtractVector(corners[2], scaledVector(front, margin) * 3.0f);
    subtractVector(corners[2], scaledVector(right, margin));
    subtractVector(corners[3], scaledVector(front, margin) * 3.0f);
    corners[3] += scaledVector(right, margin);
}

void Vehicle::debug(irr::video::IVideoDriver* videoDriver)
{
    irr::core::vector3d<float> corners[4];
    getCollisionRect(corners, 50.0f);
    corners[0].Z = GetPosition().Z + 50.0f;
    corners[1].Z = GetPosition().Z + 50.0f;
    corners[2].Z = GetPosition().Z + 50.0f;
    corners[3].Z = GetPosition().Z + 50.0f;
    videoDriver->draw3DLine(corners[0], corners[1], irr::video::SColor(255, 255, 255, 255));
    videoDriver->draw3DLine(corners[1], corners[2], irr::video::SColor(255, 255, 255, 255));
    videoDriver->draw3DLine(corners[2], corners[3], irr::video::SColor(255, 255, 255, 255));
    videoDriver->draw3DLine(corners[3], corners[0], irr::video::SColor(255, 255, 255, 255));
}

void Vehicle::UpdateCarTireTrails(int, int alpha)
{
    bool active[4] = {false, false, false, false};
    for (int wheel = 0; wheel < 4; ++wheel) {
        switch (wheel) {
        case 0:
            active[0] = false;
            break;
        case 1:
            active[1] = false;
            break;
        case 2:
            active[2] = unknown509 && (skidAmount > 0.0f || ((flags344 & 2u) && unknown132 == 1));
            break;
        case 3:
            active[3] = unknown508 && (skidAmount > 0.0f || ((flags344 & 2u) && unknown132 == 1));
            break;
        }
    }

    using irr::core::vector3d;
    for (int wheel = 0; wheel < 4; ++wheel) {
        if (!active[wheel])
            continue;
        if (!wheelTrails[wheel])
            wheelTrails[wheel] = GS3DStuff::GetTrailMgr()->AllocTrail();
        if (!wheelTrails[wheel])
            continue;

        vector3d<float> position;
        switch (wheel) {
        case 0:
            position = wheelPosition0;
            break;
        case 1:
            position = wheelPosition1;
            break;
        case 2:
            position = wheelPosition3;
            break;
        case 3:
            position = wheelPosition2;
            break;
        }

        vector3d<float> up(0.0f, 0.0f, 1.0f);
        wheelTrails[wheel]->SetColor(static_cast<unsigned char>(alpha));
        wheelTrails[wheel]->Update(position, up, false);
    }
}

struct VehicleRepairVisualBlock {
    unsigned char unknown0[12];
    float value12;
    unsigned char unknown16[4];
    float value20;
};

struct VehicleRepairVisualState {
    unsigned char unknown0[60];
    VehicleRepairVisualBlock* block;
    unsigned char unknown64[24];
    bool dirty;
};

void Vehicle::repair()
{
    unknown960Word = -5000;
    if (enabledSceneNode)
        GS3DStuff::SetAlpha(enabledSceneNode, 255, GS3DStuff::Color0);
    if (sceneNode) {
        GS3DStuff::SetAlpha(sceneNode, 255, GS3DStuff::Color0);
        GS3DStuff::SetMaterialType(sceneNode, static_cast<irr::video::E_MATERIAL_TYPE>(0));
    }
    if (explosionTimeline) {
        enableSkinning(false);
        toggleInterior(false);
        enableBackfaceCulling(true);
        sceneNode->removeAnimator(explosionAnimator);
    }

    exploding = false;
    explosionFinished = false;
    explosionFlag = 0;
    VehicleRepairVisualState* visual = repairVisualState;
    VehicleRepairVisualBlock* block = visual->block;
    if (block->value12 != 0.0f) {
        block->value12 = 0.0f;
        visual->dirty = true;
        visual = repairVisualState;
        block = visual->block;
    }
    if (block->value20 != 0.0f) {
        block->value20 = 0.0f;
        visual->dirty = true;
    }
    health = getMaxHealth();
    repairMaterialNode->getMaterial(0).setTexture(0, repairTexture);
    GS3DStuff::SetMaterialFiltering(repairMaterialNode, false, true);
    repairFlag420 = false;
    const irr::video::SColor white(255, 255, 255, 255);
    GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag2, true);
    GS3DStuff::SetColor(sceneNode, white, GS3DStuff::Color0);
    GS3DStuff::SetColor(interior, white, GS3DStuff::Color0);
    GS3DStuff::SetMaterialFlag(repairGlassNode, irr::video::MaterialFlag2, false);
    GS3DStuff::SetMaterialType(repairGlassNode, static_cast<irr::video::E_MATERIAL_TYPE>(25));
    GS3DStuff::SetMaterialType(repairLightNode, irr::video::MaterialType13);
    _resetLights();
    showWheels();
    doorSoundSuppression = 2;
    closeDoor(true);
    closeDoor(false);
    sceneNode->resetTransform(true);
    reinterpret_cast<irr::scene::ISceneNode*>(skinnedMesh)->resetTransform(true);
    ResetBodyPosition();
}

namespace {
const char vehicleLight00Asset[] = "car_light_00.bdae";
const char vehicleLight01Asset[] = "car_light_01.bdae";
const char vehicleCopLightsAsset[] = "cop_lights.bdae";
const char vehicleLight01Node[] = "dummy_light_01-node";
const char vehicleLight02Node[] = "dummy_light_02-node";
const char vehicleCopLightsNode[] = "cop_lights-node";
}

extern "C" irr::collada::CColladaFactory* _ZN12CGameFactory11getInstanceEv() __attribute__((weak));

irr::scene::ISceneNode* Vehicle::grabSceneNode(int, void***)
{
    using namespace irr;
    void** params = 0;
    scene::ISceneNode* result = LevelObject::grabSceneNode(19, &params);
    Application::GetInstance();
    repairVisualState = static_cast<VehicleRepairVisualState*>(params[0]);
    leftDoorAnimator = static_cast<scene::ISceneNodeAnimator*>(params[1]);
    rightDoorAnimator = static_cast<scene::ISceneNodeAnimator*>(params[2]);
    leftDoor = static_cast<scene::ISceneNode*>(params[3]);
    rightDoor = static_cast<scene::ISceneNode*>(params[4]);
    skinnedMesh = static_cast<collada::CSkinnedMeshSceneNode*>(params[5]);
    interior = static_cast<scene::ISceneNode*>(params[6]);
    repairTexture = static_cast<video::ITexture*>(params[7]);
    damageTexture = static_cast<video::ITexture*>(params[8]);
    repairMaterialNode = static_cast<scene::ISceneNode*>(params[9]);
    enabledSceneNode = static_cast<scene::ISceneNode*>(params[10]);
    wheelNodes[0] = static_cast<scene::ISceneNode*>(params[11]);
    wheelNodes[1] = static_cast<scene::ISceneNode*>(params[12]);
    wheelNodes[2] = static_cast<scene::ISceneNode*>(params[13]);
    wheelNodes[3] = static_cast<scene::ISceneNode*>(params[14]);
    exterior = static_cast<scene::ISceneNode*>(params[15]);

    if (params[16]) {
        scenePool812 = reinterpret_cast<int>(params[17]);
        scenePool892 = reinterpret_cast<int>(params[18]);

        SceneNodeManager* manager = SceneNodeManager::getInstance();
        lightPool824 = manager->findOrCreatePool(vehicleLight00Asset, 8, _ZN12CGameFactory11getInstanceEv());
        manager = SceneNodeManager::getInstance();
        lightPool828 = manager->findOrCreatePool(vehicleLight01Asset, 8, _ZN12CGameFactory11getInstanceEv());
        manager = SceneNodeManager::getInstance();
        scenePool880 = manager->findOrCreatePool(vehicleCopLightsAsset, 8, _ZN12CGameFactory11getInstanceEv());
        repairGlassNode = SceneNodeManager::getInstance()->grab(scenePool812, 0, 0, 0);
        repairLightNode = SceneNodeManager::getInstance()->grab(scenePool892, 0, 0, 0);
        lightNodes[0] = SceneNodeManager::getInstance()->grab(lightPool824, 0, 0, 0);
        lightNodes[1] = SceneNodeManager::getInstance()->grab(lightPool824, 0, 0, 0);
        lightNodes[2] = SceneNodeManager::getInstance()->grab(lightPool828, 0, 0, 0);
        lightNodes[3] = SceneNodeManager::getInstance()->grab(lightPool828, 0, 0, 0);
        pooledNode884 = SceneNodeManager::getInstance()->grab(scenePool880, 0, 0, 0);

        GS3DStuff::SetMaterialFlag(repairGlassNode, video::MaterialFlag2, false);
        GS3DStuff::SetMaterialType(repairGlassNode, static_cast<video::E_MATERIAL_TYPE>(25));
        GS3DStuff::SetMaterialType(repairLightNode, video::MaterialType13);
        _resetLights();
        GS3DStuff::SetMaterialFlag(pooledNode884, video::MaterialFlag2, false);
        repairGlassNode->setVisible(false);
        repairLightNode->setVisible(false);
        pooledNode884->setVisible(false);

        scene::ITimelineController* controller = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
        if (controller)
            controller->setLoop(false);
        controller = (*repairLightNode->getAnimators().begin())->getTimelineCtrl();
        if (controller)
            controller->setLoop(false);

        sceneData820 = static_cast<scene::ISceneNode*>(params[16]);
        sceneData848 = sceneNode->getSceneNodeFromUID(vehicleLight01Node);
        sceneData852 = sceneNode->getSceneNodeFromUID(vehicleLight02Node);
        sceneData888 = sceneNode->getSceneNodeFromUID(vehicleCopLightsNode);
        if (sceneData848) {
            const float x = sceneData848->getPosition().X;
            const float y = sceneData848->getPosition().Y;
            const float z = sceneData848->getPosition().Z;
            sceneOffset856.X = x;
            sceneOffset856.Y = y;
            sceneOffset856.Z = z;
        }
        if (sceneData852) {
            const float x = sceneData852->getPosition().X;
            const float y = sceneData852->getPosition().Y;
            const float z = sceneData852->getPosition().Z;
            sceneOffset868.X = x;
            sceneOffset868.Y = y;
            sceneOffset868.Z = z;
        }

        sceneData820->addChild(repairGlassNode);
        sceneData820->addChild(repairLightNode);
        if (sceneData848 && sceneData852) {
            sceneData848->addChild(lightNodes[0]);
            sceneData852->addChild(lightNodes[1]);
            sceneData848->addChild(lightNodes[2]);
            sceneData852->addChild(lightNodes[3]);
        }
        if (sceneData888)
            sceneData888->addChild(pooledNode884);
    }

    if (unknown4 & 1u)
        CreateBody();
    enableSkinning(false);
    enableBackfaceCulling(true);
    toggleInterior(false);
    return result;
}

void Vehicle::InitV8Z06Sounds()
{
    CarSoundSettings* settings = new CarSoundSettings;
    settings->initialLoad = 0;
    previousSoundLoad = 0;
    soundMinimumRpm = 1000;
    soundMaximumRpm = 5000;
    soundRpmRange = soundMaximumRpm - soundMinimumRpm;
    settings->maximumRpm = soundMaximumRpm;
    previousSoundRpm = (settings->initialRpm = soundMinimumRpm);
    settings->unknownGear16 = static_cast<unsigned int>(-1);
    settings->unknownGear20 = 1;
    settings->initialGear = gear;
    previousSoundGear = static_cast<float>(gear);
    settings->filterRpm = true;
    settings->filterFrequency = 0.1f;

    settings->onEngineCount = 7;
    settings->onEngineGain = 100.0f;
    settings->onEngineIds = new int[7];
    settings->onEngineIds[0] = 194;
    settings->onEngineIds[1] = 206;
    settings->onEngineIds[2] = 198;
    settings->onEngineIds[3] = 204;
    settings->onEngineIds[4] = 195;
    settings->onEngineIds[5] = 205;
    settings->onEngineIds[6] = 200;
    settings->onEngineReferenceRpm = new int[settings->onEngineCount];
    settings->onEngineReferenceRpm[0] = 1500;
    settings->onEngineReferenceRpm[1] = 2314;
    settings->onEngineReferenceRpm[2] = 3360;
    settings->onEngineReferenceRpm[3] = 5168;
    settings->onEngineReferenceRpm[4] = 5868;
    settings->onEngineReferenceRpm[5] = 6208;
    settings->onEngineReferenceRpm[6] = 6210;
    settings->onEngineLowerRpm = new int[settings->onEngineCount];
    settings->onEngineLowerRpm[0] = 0;
    settings->onEngineLowerRpm[1] = 1686;
    settings->onEngineLowerRpm[2] = 2684;
    settings->onEngineLowerRpm[3] = 3701;
    settings->onEngineLowerRpm[4] = 4845;
    settings->onEngineLowerRpm[5] = 5770;
    settings->onEngineLowerRpm[6] = 7000;
    settings->onEngineUpperRpm = new int[settings->onEngineCount];
    settings->onEngineUpperRpm[0] = 2264;
    settings->onEngineUpperRpm[1] = 3263;
    settings->onEngineUpperRpm[2] = 4321;
    settings->onEngineUpperRpm[3] = 5248;
    settings->onEngineUpperRpm[4] = 6233;
    settings->onEngineUpperRpm[5] = 7200;
    settings->onEngineUpperRpm[6] = soundMaximumRpm;

    settings->offEngineCount = 7;
    settings->offEngineGain = 100.0f;
    settings->offEngineIds = new int[7];
    settings->offEngineIds[0] = 197;
    settings->offEngineIds[1] = 196;
    settings->offEngineIds[2] = 199;
    settings->offEngineIds[3] = 203;
    settings->offEngineIds[4] = 209;
    settings->offEngineIds[5] = 207;
    settings->offEngineIds[6] = 200;
    settings->offEngineReferenceRpm = new int[settings->offEngineCount];
    settings->offEngineReferenceRpm[0] = 780;
    settings->offEngineReferenceRpm[1] = 3000;
    settings->offEngineReferenceRpm[2] = 3876;
    settings->offEngineReferenceRpm[3] = 4644;
    settings->offEngineReferenceRpm[4] = 5376;
    settings->offEngineReferenceRpm[5] = 6024;
    settings->offEngineReferenceRpm[6] = 6210;
    settings->offEngineLowerRpm = new int[settings->offEngineCount];
    settings->offEngineLowerRpm[0] = 0;
    settings->offEngineLowerRpm[1] = 1266;
    settings->offEngineLowerRpm[2] = 2471;
    settings->offEngineLowerRpm[3] = 3627;
    settings->offEngineLowerRpm[4] = 4575;
    settings->offEngineLowerRpm[5] = 5541;
    settings->offEngineLowerRpm[6] = 6795;
    settings->offEngineUpperRpm = new int[settings->offEngineCount];
    settings->offEngineUpperRpm[0] = 1759;
    settings->offEngineUpperRpm[1] = 3119;
    settings->offEngineUpperRpm[2] = 4031;
    settings->offEngineUpperRpm[3] = 4991;
    settings->offEngineUpperRpm[4] = 6073;
    settings->offEngineUpperRpm[5] = 7095;
    settings->offEngineUpperRpm[6] = soundMaximumRpm;

    settings->rumbleEnabled = false;
    settings->startupEnabled = true;
    settings->startupSound = 202;
    settings->startupGain = 100.0f;
    settings->clutchEnabled = false;
    settings->turboEnabled = false;
    carSounds->Init(settings);
    delete settings;
}

void Vehicle::InitV6TurboSounds()
{
    CarSoundSettings* settings = new CarSoundSettings;
    settings->initialLoad = 0;
    previousSoundLoad = 0;
    soundMinimumRpm = 1000;
    soundMaximumRpm = 5000;
    soundRpmRange = soundMaximumRpm - soundMinimumRpm;
    settings->maximumRpm = soundMaximumRpm;
    previousSoundRpm = (settings->initialRpm = soundMinimumRpm);
    settings->unknownGear16 = static_cast<unsigned int>(-1);
    settings->unknownGear20 = 1;
    settings->initialGear = gear;
    previousSoundGear = static_cast<float>(gear);
    settings->filterRpm = true;
    settings->filterFrequency = 0.1f;

    settings->onEngineCount = 6;
    settings->onEngineGain = 100.0f;
    settings->onEngineIds = new int[6];
    settings->onEngineIds[0] = 192;
    settings->onEngineIds[1] = 185;
    settings->onEngineIds[2] = 193;
    settings->onEngineIds[3] = 184;
    settings->onEngineIds[4] = 189;
    settings->onEngineIds[5] = 182;
    settings->onEngineReferenceRpm = new int[settings->onEngineCount];
    settings->onEngineReferenceRpm[0] = 2000;
    settings->onEngineReferenceRpm[1] = 3000;
    settings->onEngineReferenceRpm[2] = 3944;
    settings->onEngineReferenceRpm[3] = 5000;
    settings->onEngineReferenceRpm[4] = 6500;
    settings->onEngineReferenceRpm[5] = 6580;
    settings->onEngineLowerRpm = new int[settings->onEngineCount];
    settings->onEngineLowerRpm[0] = 0;
    settings->onEngineLowerRpm[1] = 2060;
    settings->onEngineLowerRpm[2] = 3132;
    settings->onEngineLowerRpm[3] = 4311;
    settings->onEngineLowerRpm[4] = 5775;
    settings->onEngineLowerRpm[5] = 7153;
    settings->onEngineUpperRpm = new int[settings->onEngineCount];
    settings->onEngineUpperRpm[0] = 2662;
    settings->onEngineUpperRpm[1] = 3787;
    settings->onEngineUpperRpm[2] = 4981;
    settings->onEngineUpperRpm[3] = 6703;
    settings->onEngineUpperRpm[4] = 7343;
    settings->onEngineUpperRpm[5] = soundMaximumRpm;

    settings->offEngineCount = 6;
    settings->offEngineGain = 100.0f;
    settings->offEngineIds = new int[6];
    settings->offEngineIds[0] = 190;
    settings->offEngineIds[1] = 187;
    settings->offEngineIds[2] = 183;
    settings->offEngineIds[3] = 191;
    settings->offEngineIds[4] = 186;
    settings->offEngineIds[5] = 182;
    settings->offEngineReferenceRpm = new int[settings->offEngineCount];
    settings->offEngineReferenceRpm[0] = 800;
    settings->offEngineReferenceRpm[1] = 1455;
    settings->offEngineReferenceRpm[2] = 3000;
    settings->offEngineReferenceRpm[3] = 5000;
    settings->offEngineReferenceRpm[4] = 6500;
    settings->offEngineReferenceRpm[5] = 6580;
    settings->offEngineLowerRpm = new int[settings->offEngineCount];
    settings->offEngineLowerRpm[0] = 0;
    settings->offEngineLowerRpm[1] = 852;
    settings->offEngineLowerRpm[2] = 2000;
    settings->offEngineLowerRpm[3] = 3400;
    settings->offEngineLowerRpm[4] = 5363;
    settings->offEngineLowerRpm[5] = 7026;
    settings->offEngineUpperRpm = new int[settings->offEngineCount];
    settings->offEngineUpperRpm[0] = 1600;
    settings->offEngineUpperRpm[1] = 2600;
    settings->offEngineUpperRpm[2] = 4400;
    settings->offEngineUpperRpm[3] = 6172;
    settings->offEngineUpperRpm[4] = 7276;
    settings->offEngineUpperRpm[5] = soundMaximumRpm;

    settings->rumbleEnabled = false;
    settings->startupEnabled = true;
    settings->startupSound = 188;
    settings->clutchEnabled = false;
    settings->turboEnabled = false;
    settings->startupGain = 100.0f;
    carSounds->Init(settings);
    delete settings;
}

void Vehicle::InitV6naSounds()
{
    CarSoundSettings* settings = new CarSoundSettings;
    settings->initialLoad = 0;
    previousSoundLoad = 0;
    soundMinimumRpm = 1000;
    soundMaximumRpm = 5000;
    soundRpmRange = soundMaximumRpm - soundMinimumRpm;
    settings->maximumRpm = soundMaximumRpm;
    previousSoundRpm = (settings->initialRpm = soundMinimumRpm);
    settings->unknownGear16 = static_cast<unsigned int>(-1);
    settings->unknownGear20 = 1;
    settings->initialGear = gear;
    previousSoundGear = static_cast<float>(gear);
    settings->filterRpm = true;
    settings->filterFrequency = 0.1f;

    settings->onEngineCount = 4;
    settings->onEngineGain = 100.0f;
    settings->onEngineIds = new int[4];
    settings->onEngineIds[0] = 179;
    settings->onEngineIds[1] = 178;
    settings->onEngineIds[2] = 172;
    settings->onEngineIds[3] = 171;
    settings->onEngineReferenceRpm = new int[settings->onEngineCount];
    settings->onEngineReferenceRpm[0] = 1070;
    settings->onEngineReferenceRpm[1] = 2000;
    settings->onEngineReferenceRpm[2] = 3000;
    settings->onEngineReferenceRpm[3] = 4500;
    settings->onEngineLowerRpm = new int[settings->onEngineCount];
    settings->onEngineLowerRpm[0] = 0;
    settings->onEngineLowerRpm[1] = 1566;
    settings->onEngineLowerRpm[2] = 2777;
    settings->onEngineLowerRpm[3] = 4080;
    settings->onEngineUpperRpm = new int[settings->onEngineCount];
    settings->onEngineUpperRpm[0] = 2226;
    settings->onEngineUpperRpm[1] = 3352;
    settings->onEngineUpperRpm[2] = 4813;
    settings->onEngineUpperRpm[3] = soundMaximumRpm;

    settings->offEngineCount = 4;
    settings->offEngineGain = 100.0f;
    settings->offEngineIds = new int[4];
    settings->offEngineIds[0] = 180;
    settings->offEngineIds[1] = 170;
    settings->offEngineIds[2] = 181;
    settings->offEngineIds[3] = 169;
    settings->offEngineReferenceRpm = new int[settings->offEngineCount];
    settings->offEngineReferenceRpm[0] = 900;
    settings->offEngineReferenceRpm[1] = 2400;
    settings->offEngineReferenceRpm[2] = 3000;
    settings->offEngineReferenceRpm[3] = 4500;
    settings->offEngineLowerRpm = new int[settings->offEngineCount];
    settings->offEngineLowerRpm[0] = 0;
    settings->offEngineLowerRpm[1] = 1144;
    settings->offEngineLowerRpm[2] = 2385;
    settings->offEngineLowerRpm[3] = 3407;
    settings->offEngineUpperRpm = new int[settings->offEngineCount];
    settings->offEngineUpperRpm[0] = 1633;
    settings->offEngineUpperRpm[1] = 2954;
    settings->offEngineUpperRpm[2] = 4116;
    settings->offEngineUpperRpm[3] = soundMaximumRpm;

    settings->rumbleEnabled = false;
    settings->startupEnabled = true;
    settings->startupSound = 176;
    settings->clutchEnabled = false;
    settings->turboEnabled = false;
    settings->startupGain = 100.0f;
    carSounds->Init(settings);
    delete settings;
}

void Vehicle::Init4CylNaSounds()
{
    CarSoundSettings* settings = new CarSoundSettings;
    settings->initialLoad = 0;
    previousSoundLoad = 0;
    const int minimumRpm = soundMinimumRpm = 1000;
    soundMaximumRpm = 4000;
    const int rpmRange = soundRpmRange = soundMaximumRpm - soundMinimumRpm;
    settings->maximumRpm = soundMaximumRpm;
    previousSoundRpm = (settings->initialRpm = soundMinimumRpm);
    settings->unknownGear16 = static_cast<unsigned int>(-1);
    settings->unknownGear20 = 1;
    settings->initialGear = gear;
    previousSoundGear = static_cast<float>(gear);
    settings->filterRpm = true;
    settings->filterFrequency = 0.1f;

    settings->onEngineCount = 6;
    settings->onEngineGain = 100.0f;
    settings->onEngineIds = new int[6];
    settings->onEngineIds[0] = 158;
    settings->onEngineIds[1] = 161;
    settings->onEngineIds[2] = 164;
    settings->onEngineIds[3] = 162;
    settings->onEngineIds[4] = 160;
    settings->onEngineIds[5] = 159;
    settings->onEngineReferenceRpm = new int[settings->onEngineCount];
    settings->onEngineReferenceRpm[0] = 2000;
    settings->onEngineReferenceRpm[1] = rpmRange;
    settings->onEngineReferenceRpm[2] = 0x1194;
    settings->onEngineReferenceRpm[3] = 0x1964;
    settings->onEngineReferenceRpm[4] = 0x1f52;
    settings->onEngineReferenceRpm[5] = 0x2215;
    settings->onEngineLowerRpm = new int[settings->onEngineCount];
    settings->onEngineLowerRpm[0] = 0;
    settings->onEngineLowerRpm[1] = 0x887;
    settings->onEngineLowerRpm[2] = 0xd9e;
    settings->onEngineLowerRpm[3] = 0x1360;
    settings->onEngineLowerRpm[4] = 0x191c;
    settings->onEngineLowerRpm[5] = 0x1de9;
    settings->onEngineUpperRpm = new int[settings->onEngineCount];
    settings->onEngineUpperRpm[0] = 0xaf3;
    settings->onEngineUpperRpm[1] = 0x1027;
    settings->onEngineUpperRpm[2] = 0x1644;
    settings->onEngineUpperRpm[3] = 0x1b49;
    settings->onEngineUpperRpm[4] = 0x1e89;
    settings->onEngineUpperRpm[5] = soundMaximumRpm;

    settings->offEngineCount = 6;
    settings->offEngineGain = 100.0f;
    settings->offEngineIds = new int[6];
    settings->offEngineIds[0] = 167;
    settings->offEngineIds[1] = 165;
    settings->offEngineIds[2] = 168;
    settings->offEngineIds[3] = 163;
    settings->offEngineIds[4] = 157;
    settings->offEngineIds[5] = 159;
    settings->offEngineReferenceRpm = new int[settings->offEngineCount];
    settings->offEngineReferenceRpm[0] = minimumRpm;
    settings->offEngineReferenceRpm[1] = rpmRange;
    settings->offEngineReferenceRpm[2] = 0x1194;
    settings->offEngineReferenceRpm[3] = 0x1964;
    settings->offEngineReferenceRpm[4] = 8000;
    settings->offEngineReferenceRpm[5] = 0x2215;
    settings->offEngineLowerRpm = new int[settings->offEngineCount];
    settings->offEngineLowerRpm[0] = 0;
    settings->offEngineLowerRpm[1] = 0x51d;
    settings->offEngineLowerRpm[2] = 0xb96;
    settings->offEngineLowerRpm[3] = 0xf07;
    settings->offEngineLowerRpm[4] = 0x13ff;
    settings->offEngineLowerRpm[5] = 0x1c99;
    settings->offEngineUpperRpm = new int[settings->offEngineCount];
    settings->offEngineUpperRpm[0] = 0x774;
    settings->offEngineUpperRpm[1] = 0xd80;
    settings->offEngineUpperRpm[2] = 0x10ad;
    settings->offEngineUpperRpm[3] = 0x16e3;
    settings->offEngineUpperRpm[4] = 0x1e4b;
    settings->offEngineUpperRpm[5] = soundMaximumRpm;

    settings->rumbleEnabled = false;
    settings->startupEnabled = true;
    settings->startupSound = 166;
    settings->clutchEnabled = false;
    settings->turboEnabled = false;
    settings->startupGain = 100.0f;
    carSounds->Init(settings);
    delete settings;
}

int __attribute__((weak)) Vehicle::getMarkerType()
{
    return -1;
}

extern "C" void vehicleStaticInitialization(int initialize, int priority)
    __asm__("_Z41__static_initialization_and_destruction_0ii");

extern "C" {
static void _GLOBAL__I__ZN7Vehicle19s_smallImpactSoundsE() __attribute__((used));
static void _GLOBAL__I__ZN7Vehicle19s_smallImpactSoundsE()
{
    vehicleStaticInitialization(1, 65535);
}
}

Vehicle::Vehicle(int type)
    : LevelObject(type),
      wheelGroundHeights(),
      lightNodes(),
      unknown56(0.0f),
      unknown60(1.0f),
      unknown64(0.0f),
      init104(0.0f),
      init108(0.0f),
      init112(0.0f),
      unknown116(0.0f),
      unknown120(0.0f),
      unknown124(0.0f),
      unknown132(0),
      init136(0),
      aiTarget(0),
      rotationZ(0.0f),
      rotationX(0.0f),
      rotationY(0.0f),
      init156(0.0f),
      init160(0.0f),
      init164(0.0f),
      mass(0),
      skidThreshold(0.0f),
      init180(0.0f),
      init184(0.0f),
      unknown188(0.0f),
      savedRadioStation(0),
      init200(0),
      init204(0),
      init208(0.0f),
      init212(0.0f),
      init216(0.0f),
      init220(0.0f),
      tireTrailWidth(0),
      init228(0),
      init232(0.0f),
      init236(1.0f),
      unknown240(-1),
      targetingCharacter(0),
      gearProfile(-1),
      gearProgress(0.0f),
      pathToFollow(0),
      currentWaypoint(0),
      turnLeft(true),
      turnAmount(0.0f),
      flags344(8388608),
      init348(-1),
      init352(0.0f),
      accelerationAmount(0.0f),
      brakeAmount(0.0f),
      init364(-1),
      gear(1),
      init372(0.0f),
      init376(0.0f),
      init380(0.0f),
      init388(0),
      init389(0),
      init392(0.0f),
      init396(0.0f),
      waitElapsed(0),
      waitDuration(0),
      repairTexture(0),
      damageTexture(0),
      repairFlag420(false),
      explosionFlag(0),
      vehicleIndex(-1),
      carSounds(0),
      carSoundParameters(0),
      carSoundMode(0),
      carSoundTrigger(false),
      enginePitchFalloff(1.0f),
      enginePitchSpeed(0.0f),
      soundMaximumSpeed(0.0f),
      soundLoadDuration(10),
      hasBeenStolen(false),
      unknown505(0),
      unknown506(false),
      unknown507(false),
      unknown508(false),
      unknown509(false),
      unknown510(0),
      unknown511(0),
      init560(0.0f),
      init564(0.0f),
      init568(0.0f),
      init572(0.0f),
      init576(0.0f),
      init580(0.0f),
      init584(0.0f),
      init588(0.0f),
      init592(0.0f),
      init596(0.0f),
      init600(0.0f),
      init604(0.0f),
      init608(0.0f),
      init612(0.0f),
      init616(0.0f),
      collisionBody(0),
      leftCollisionBody(0),
      rightCollisionBody(0),
      init644(0),
      skidAmount(0.0f),
      init652(0.0f),
      enabledSceneNode(0),
      driver(0),
      init700(0.0f),
      init704(0.0f),
      init708(0.0f),
      init712(0.0f),
      init716(0.0f),
      init720(0.0f),
      init724(0.0f),
      init728(0.0f),
      init732(0.0f),
      init736(0.0f),
      init740(0.0f),
      init744(0.0f),
      init748(0),
      init768(0),
      init772(0),
      sensorContactCount(0),
      spawnType(-1),
      turnSoundPlaying(false),
      skidSoundPlaying(false),
      scenePool812(-1),
      repairGlassNode(0),
      sceneData820(0),
      lightPool824(-1),
      lightPool828(-1),
      sceneData848(0),
      sceneData852(0),
      scenePool880(-1),
      pooledNode884(0),
      sceneData888(0),
      scenePool892(-1),
      repairLightNode(0),
      exploding(false),
      explosionFinished(false),
      doorSoundSuppression(0),
      repairVisualState(0),
      maxHealth(100),
      health(100),
      unknown924(0),
      animationClipIndex(999999),
      driverMetatype(-1),
      driverBehavior(-1),
      speed(0.0f),
      init980(0.0f),
      unknown984(0.0f),
      unknown988(0.0f),
      unknown992(0.0f),
      leftDoorClosed(true),
      rightDoorClosed(true),
      leftDoorTransition(false),
      rightDoorTransition(false),
      immobilized(false),
      init1008(1000.0f)
{
    Application::GetInstance();
    init748 = new irr::core::vector3d<float>[4];
    wheelTrails[0] = 0;
    wheelTrails[1] = 0;
    wheelTrails[2] = 0;
    wheelTrails[3] = 0;
}

#include "../core/Geometry.h"
extern "C" float acosf(float);
extern "C" float fabsf(float);
void Vehicle::stepPhysic()
{
    using irr::core::vector3d;
    using irr::core::quaternion;
    using irr::core::clamp;
    const irr::core::matrix4& transform = sceneNode->getAbsoluteTransformation();
    const b2Vec2& bodyPosition = collisionBody->GetXForm().position;
    const float x = 100.0f * bodyPosition.x;
    const float y = 100.0f * bodyPosition.y;
    const float height = (wheelPosition0.Z + wheelPosition1.Z + wheelPosition2.Z + wheelPosition3.Z) * 0.25f;
    const float offsetZ = bodyOffset.X * transform[2] + bodyOffset.Y * transform[6] + bodyOffset.Z * transform[10];
    vector3d<float> position(x, y, height - offsetZ);
    vector3d<float> forward = (wheelPosition1 + wheelPosition0) * 0.5f - (wheelPosition3 + wheelPosition2) * 0.5f;
    vector3d<float> right = (wheelPosition1 + wheelPosition3) * 0.5f - (wheelPosition0 + wheelPosition2) * 0.5f;
    forward.normalize();
    right.normalize();
    vector3d<float> normal(
        -forward.Y * right.Z + forward.Z * right.Y,
        -forward.Z * right.X + right.Z * forward.X,
        right.Y * -forward.X + forward.Y * right.X);
    normal.normalize();
    if (fabsf(forward.Z) > 0.95f) {
        unknown506 = false;
        unknown507 = false;
        unknown508 = false;
        unknown509 = false;
        init1008 = 1000.0f;
    }
    vector3d<float> flatForward(forward);
    vector3d<float> flatRight(right);
    flatForward.Z = 0.0f;
    flatRight.Z = 0.0f;
    flatForward.normalize();
    flatRight.normalize();
    float forwardAngle = acosf(clamp(flatForward.dotProduct(forward), -1.0f, 1.0f));
    float rightAngle = acosf(clamp(flatRight.dotProduct(right), -1.0f, 1.0f));
    if (vector3d<float>(0, 0, 1).dotProduct(forward) < 0.0f)
        forwardAngle = -forwardAngle;
    if (vector3d<float>(0, 0, 1).dotProduct(right) < 0.0f)
        rightAngle = -rightAngle;
    quaternion yaw;
    quaternion pitch;
    quaternion roll;
    yaw.fromAngleAxis(rotationZ * 0.01745329238474369f, vector3d<float>(0, 0, 1));
    pitch.fromAngleAxis(forwardAngle, vector3d<float>(1, 0, 0));
    roll.fromAngleAxis(-rightAngle, vector3d<float>(0, 1, 0));
    sceneNode->setRotation(yaw * pitch * roll);
    sceneNode->setPosition(position);
    sceneNode->updateAbsolutePosition(false);
    if (driver == reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))) {
        float distance = position.getDistanceFrom(previousPosition);
        PlayerTest::GetPlayer()->addDistanceDriven(distance);
        if (skidAmount > 0.0f)
            PlayerTest::GetPlayer()->addCurrentDriftDistance(distance);
        if (unknown505)
            PlayerTest::GetPlayer()->addCurrentJumpDistance(distance);
    }
    previousPosition = position;
}

#include "../combat/Explosion.h"
#include "../meta/Achievements.h"
#include "../core/Geometry.h"
extern "C" long lrand48();
extern "C" void _ZN18EvVehicleDestroyedD1Ev(void*) __attribute__((weak));

void Vehicle::explode()
{
    if (exploding)
        return;
    exploding = true;
    if (flags344 & 0x10000u) {
        showHighlight(-1);
        ScriptManager::displayOnMinimap(this, false, true);
    }

    const irr::video::SColor burnedColor(255, 35, 25, 25);
    GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag2, false);
    GS3DStuff::SetColor(sceneNode, burnedColor, GS3DStuff::Color0);
    GS3DStuff::SetColor(interior, burnedColor, GS3DStuff::Color0);
    if (explosionTimeline) {
        enableSkinning(true);
        toggleInterior(true);
        enableBackfaceCulling(false);
        sceneNode->addAnimator(explosionAnimator);
        explosionTimeline->setClip(0);
        explosionTimeline->setLoop(false);
        explosionTimeline->jumpTo(explosionTimeline->startTime);
        irr::scene::ITimelineController* const timeline = explosionTimeline;
        timeline->callbackData = this;
        timeline->callback = VehicleExplosionAnimCallback;
    }

    VehicleRepairVisualState* visual = repairVisualState;
    if (visual) {
        VehicleRepairVisualBlock* block = visual->block;
        const float previous = block->value12;
        float weight = previous + 1.0f;
        if (weight > 1.0f)
            weight = 1.0f;
        if (weight != previous) {
            block->value12 = weight;
            visual->dirty = true;
            visual = repairVisualState;
            block = visual->block;
        }
        const float previousSecond = block->value20;
        float secondWeight = previousSecond + 1.0f;
        if (secondWeight > 1.0f)
            secondWeight = 1.0f;
        if (secondWeight != previousSecond) {
            block->value20 = secondWeight;
            visual->dirty = true;
        }
    }

    if (repairMaterialNode && !repairFlag420 &&
        static_cast<float>(health) / static_cast<float>(maxHealth) < 0.5f) {
        repairMaterialNode->getMaterial(0).setTexture(0, damageTexture);
        repairFlag420 = true;
    }

    health = 0;
    if (PlayerTest::GetPlayer()->getVehicle() == this)
        PlayerTest::GetPlayer()->health = 0;
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(110, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    Explosion::drawExplosion(GetPosition(), irr::core::vector3d<float>(50.0f, 50.0f, 50.0f));
    Explosion::applyExplosionDamage(this, GetPosition(), 700.0f, 800);
    stopDriving();
    Stop();

    EventManager* events = Application::GetInstance()->GetEventManager();
    unsigned int storage[sizeof(EvVehicleDestroyed) / sizeof(unsigned int)];
    EvVehicleDestroyed* event = new (storage) EvVehicleDestroyed(this);
    events->raise(*event);
    _ZN18EvVehicleDestroyedD1Ev(event);
    stopSiren();
    cleanupTargetDetection();
    explosionFlag = true;
    showHighlight(-1);
    AchievementManager::s_achievementManager->recordDestroyedVehicle(*this);
}

void Vehicle::collision(irr::core::vector3d<float> impact, int type)
{
    using irr::core::vector3d;
    using irr::core::min_;
    using irr::core::max_;
    using irr::core::clamp;
    flags344 |= 0x20000u;
    unknown511 = 0;
    if (type == -1) {
        if (flags344 & 0x80000u)
            flags344 &= ~0x80000u;
        else {
            vector3d<float> previousFront = GetFront();
            init372 = previousFront.X;
            init376 = previousFront.Y;
            init380 = previousFront.Z;
            flags344 |= 0x80000u;
        }
    }
    float impactSpeed = impact.getLength() / 1000.0f * 3600.0f;
    unknown128 = impactSpeed;
    if (!(impactSpeed > 10.0f))
        return;
    const float& damageFactor = unknown912;
    float amount = damageFactor * (impactSpeed / 100.0f);
    vector3d<float> front = GetFront();
    float frontDot;
    float inverseSpeed = 1.0f / impactSpeed;
    frontDot = vector3d<float>(impact.X * inverseSpeed, impact.Y * inverseSpeed,
        __aeabi_fmul(impact.Z, inverseSpeed)).dotProduct(front);
    int damage;
    if (type == 5 || type == 8)
        damage = static_cast<int>(amount * 0.0f);
    else {
        VehicleRepairVisualState* visual = repairVisualState;
        if (visual) {
            if (frontDot >= 0.0f) {
                VehicleRepairVisualBlock* block = visual->block;
                float value = block->value12;
                float changed = amount + value;
                if (changed > 1.0f)
                    changed = 1.0f;
                if (changed != value) {
                    block->value12 = changed;
                    visual->dirty = true;
                }
            } else {
                VehicleRepairVisualBlock* block = visual->block;
                float value = block->value20;
                float changed = amount + value;
                if (changed > 1.0f)
                    changed = 1.0f;
                if (changed != value) {
                    block->value20 = changed;
                    visual->dirty = true;
                }
            }
        }
        damage = static_cast<int>(amount * 90.0f);
    }
    health -= damage;
    if (static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle() == this ||
        (flags344 & 0x1000u) || unknown240 == 6)
        AchievementManager::s_achievementManager->recordDamage(damage);
    else
        unknown511 |= 1;
    if (type != 5 && type != 8 && unknown506 && unknown507 && unknown508 && unknown509) {
        const vector3d<float>& right = GetRight();
        float rightDot = (impact * inverseSpeed).dotProduct(right);
        init732 += clamp((rightDot - frontDot) * impactSpeed * 30.0f, 0.0f, 700.0f);
        init736 = __aeabi_fadd(init736, clamp((-frontDot - rightDot) * impactSpeed * 30.0f, 0.0f, 700.0f));
        init740 += clamp((frontDot + rightDot) * impactSpeed * 30.0f, 0.0f, 700.0f);
        init744 += clamp((frontDot - rightDot) * impactSpeed * 30.0f, 0.0f, 700.0f);
        unknown506 = false;
        unknown507 = false;
        unknown508 = false;
        unknown509 = false;
    }
    if (!(GetSpeed() > 10.0f))
        return;
    int sound;
    if (type == 5 || type == 8) {
        unknown511 |= 2;
        sound = s_smallImpactSounds[lrand48() % 3];
    } else if (impactSpeed > 60.0f)
        sound = s_hardImpactSounds[lrand48() % 3];
    else if (impactSpeed > 30.0f)
        sound = s_mediumImpactSounds[lrand48() % 3];
    else
        sound = s_smallImpactSounds[lrand48() % 3];
    if (static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle() == this || type == 8) {
        SoundManager* sounds = SoundManager::getInstance();
        sounds->unknown140 = true;
        sounds->playEx(sound, 0, false, 1.0f, 0, true, 1.0f, 0);
        sounds->unknown140 = false;
    }
}


#include "../characters/PhysicInfo.h"
#include "../meta/Achievements.h"
#include "../core/Geometry.h"

class b2RevoluteJoint { public: float GetJointAngle() const; };

namespace {
struct VehicleUpdateGearProfile {
    unsigned int gearCount;
    unsigned char unknown4[12];
    const unsigned int* shiftSpeeds;
    const float* accelerationFactors;
    unsigned char unknown24[4];
};
}
extern "C" const VehicleUpdateGearProfile _ZN8gameloft7vehicle13gear_profiles8profilesE[] __attribute__((visibility("hidden")));
namespace {
struct VehicleUpdateBodyFields {
    unsigned short flags;
    unsigned char unknown2[138];
    float sleepTime;
};
inline void wakeVehicleUpdateBody(b2Body* body)
{
    VehicleUpdateBodyFields& fields = *reinterpret_cast<VehicleUpdateBodyFields*>(body);
    fields.flags &= ~8;
    fields.sleepTime = 0;
}
}

namespace {
inline bool isVehicleGlassCracked(float ratio)
{
    if (ratio < 0.3) {
        if (ratio > 0.0f)
            return true;
    }
    return false;
}
}

namespace {
inline bool isSet(const bool& flag)
{
    return flag;
}
}
void Vehicle::Update(int elapsed)
{
    using irr::core::vector3d;
    using irr::core::quaternion;
    using irr::core::clamp;
    bool finished = explosionFinished;
    if (finished && !unknown28) {
            unknown960Word += elapsed;
            int alpha = static_cast<int>(255.0f + -255.0f * (static_cast<float>(unknown960Word) / 3000.0f));
            alpha = clamp(alpha, 0, 255);
            if (alpha < 255) {
                if (enabledSceneNode) {
                    GS3DStuff::SetMaterialType(enabledSceneNode, static_cast<irr::video::E_MATERIAL_TYPE>(25));
                    GS3DStuff::SetAlpha(enabledSceneNode, alpha, static_cast<GS3DStuff::eColorType>(0));
                }
                GS3DStuff::SetMaterialType(sceneNode, static_cast<irr::video::E_MATERIAL_TYPE>(25));
                GS3DStuff::SetAlpha(sceneNode, alpha, static_cast<GS3DStuff::eColorType>(0));
            }
            if (!alpha) {
                unknown4 |= 0x800;
                return;
            }
        finished = explosionFinished;
    }
    if (!isSet(finished)) {
        const PhysicInfo* information = unknown24->info;
        if (information[0].unknown0 != PhysicAttributes::MATERIAL_TYPE_DEATH_WATER && information[1].unknown0 != PhysicAttributes::MATERIAL_TYPE_DEATH_WATER
            && information[2].unknown0 != PhysicAttributes::MATERIAL_TYPE_DEATH_WATER && information[3].unknown0 != PhysicAttributes::MATERIAL_TYPE_DEATH_WATER
            && information[4].unknown0 != PhysicAttributes::MATERIAL_TYPE_DEATH_WATER) {
            if (__builtin_expect(repairLightNode && isDead(), 0)) {
                unknown924 += elapsed;
                if (unknown924 > 4999) {
                    unknown924 = 0;
                    if (Lock::getInstance()->target == this)
                        Lock::getInstance()->setTarget(0);
                    explode();
                }
                repairLightNode->setVisible(true);
                GS3DStuff::SetMaterialFlag(repairLightNode, static_cast<irr::video::E_MATERIAL_FLAG>(2), true);
                irr::scene::ITimelineController* timeline = (*repairLightNode->getAnimators().begin())->getTimelineCtrl();
                if (timeline) {
                    timeline->jumpTo(static_cast<int>((timeline->startTime + timeline->endTime) * 0.5f));
                    timeline->setScale(1);
                }
                if (!skidSoundPlaying && !explosionFlag) {
                    SoundManager* sounds = SoundManager::getInstance();
                    sounds->unknown140 = true;
                    int channel = sounds->playEx(119, 0, true, 1, 0, false, 1, 0);
                    sounds->unknown140 = false;
                    if (channel >= 0)
                        skidSoundPlaying = true;
                }
                repairGlassNode->setVisible(true);
                timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
                if (timeline) {
                    timeline->jumpTo(static_cast<int>((timeline->startTime + timeline->endTime) * 0.5f));
                    timeline->setScale(1);
                }
            } else {
                if (repairGlassNode && isVehicleGlassCracked(static_cast<float>(health) / static_cast<float>(maxHealth))) {
                    GS3DStuff::SetMaterialFlag(repairGlassNode, static_cast<irr::video::E_MATERIAL_FLAG>(2), false);
                    repairGlassNode->setVisible(true);
                    irr::scene::ITimelineController* timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
                    if (timeline) {
                        timeline->jumpTo(static_cast<int>((timeline->startTime + timeline->endTime) * 0.5f));
                        timeline->setScale(1);
                    }
                } else {
                    irr::scene::ITimelineController* timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
                    if (timeline) {
                        timeline->jumpTo(timeline->startTime);
                        timeline->setScale(0);
                    }
                    timeline = (*repairLightNode->getAnimators().begin())->getTimelineCtrl();
                    if (timeline) {
                        timeline->jumpTo(timeline->startTime);
                        timeline->setScale(0);
                    }
                    if (skidSoundPlaying) {
                        SoundManager::getInstance()->stop(119, -1, false);
                        skidSoundPlaying = false;
                    }
                }
            }
            if (repairMaterialNode && !repairFlag420
                && static_cast<float>(health) / static_cast<float>(maxHealth) < 0.3) {
                repairMaterialNode->getMaterial(0).setTexture(0, damageTexture);
                repairFlag420 = true;
            }
        } else if (__builtin_expect(unknown506 && unknown507 && unknown508 && unknown509, 0)) {
            health = 0;
            explosionFinished = true;
            if (__builtin_expect(PlayerTest::GetPlayer()->getVehicle() == this, 0))
                PlayerTest::GetPlayer()->health = 0;
            stopDriving();
            Stop();
            Application::GetInstance()->GetEventManager()->raise(EvVehicleDestroyed(this));
            stopSiren();
            cleanupTargetDetection();
            explosionFlag = true;
            AchievementManager::s_achievementManager->recordDestroyedVehicle(*this);
        }
    } else {
        if (flags344 & 0x2000000u) {
            tagForKill(false);
            ScriptManager::getInstance()->taggedKilled();
        }
        irr::scene::ITimelineController* timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
        if (timeline) {
            timeline->jumpTo(timeline->startTime);
            timeline->setScale(0);
        }
        timeline = (*repairLightNode->getAnimators().begin())->getTimelineCtrl();
        if (timeline) {
            timeline->jumpTo(timeline->startTime);
            timeline->setScale(0);
        }
        if (skidSoundPlaying) {
            SoundManager::getInstance()->stop(119, -1, false);
            skidSoundPlaying = false;
        }
        return;
    }
    CheckDestination();
    const vector3d<float> position = GetPosition();
    unknown132 = getVelDirec();
    unsigned int time = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    if (flags344 & 0x20000u) {
        if (unknown128 < static_cast<float>(sqrt(static_cast<double>(unknown116 * unknown116 + unknown120 * unknown120 + unknown124 * unknown124))) / 1000.0f * 3600.0f)
            flags344 &= ~0x20000u;
    }
    if (!(flags344 & 0x800u) && skidAmount <= 0) {
        if ((unknown132 != 1 && unknown132 != 2) && init136 == 1
            && (unknown509 || unknown508 || unknown507 || unknown506) && !(flags344 & 0x20000u)) {
            Stop();
            flags344 |= 96;
            init348 = time;
        }
        if ((flags344 & 32u) && time - init348 > 199)
            flags344 &= ~96u;
    }
    _processAIFlags();
    waitElapsed += elapsed;
    if (unknown984 > 0) accelerate(unknown984);
    else if (unknown984 < 0) brake(-unknown984);
    if (unknown988 > 0) turn(true, unknown988);
    else if (unknown988 < 0) turn(false, -unknown988);
    if (unknown992 > 0) turn(true, unknown992);
    else if (unknown992 < 0) turn(false, -unknown992);
    const float elapsedFloat = static_cast<float>(elapsed);
    init389 = false;
    init392 = 0;
    if (flags344 & 1) {
        if (unknown132 == 3) {
            init392 = init164 * accelerationAmount;
        } else {
            const float base = init156;
            const VehicleUpdateGearProfile& profile = _ZN8gameloft7vehicle13gear_profiles8profilesE[gearProfile];
            float low = base * profile.accelerationFactors[gear - 1];
            float high = profile.accelerationFactors[gear] * init156;
            float fraction;
            if (gear == 1)
                fraction = (speed / 1000.0f * 3600.0f) / static_cast<float>(profile.shiftSpeeds[gear - 1]);
            else
                fraction = ((speed / 1000.0f * 3600.0f) - static_cast<float>(profile.shiftSpeeds[gear - 2]))
                    / static_cast<float>(profile.shiftSpeeds[gear - 1] - profile.shiftSpeeds[gear - 2]);
            fraction = clamp(fraction, 0.0f, 1.0f);
            init392 = ((high - low) * fraction + low) * accelerationAmount;
        }
        init396 += elapsedFloat / -100.0f;
        if (init396 < 0) init396 = 0;
        wakeVehicleUpdateBody(collisionBody);
    } else if (flags344 & 2) {
        if (init396 < 80) init396 = 80;
        if (unknown132 == 1) {
            init392 = -init164 * brakeAmount;
        } else if (!(flags344 & 0x800u)) {
            if (!(flags344 & 0x40u)) {
                init392 = -init160 * brakeAmount;
                wakeVehicleUpdateBody(collisionBody);
            }
        } else {
            if (!(unknown511 & 1)) Stop();
            flags344 |= 2;
        }
    } else if (flags344 & 8) {
        init392 = -init160 * brakeAmount;
    } else {
        init389 = true;
    }
    float magnitude = vector3d<float>(unknown116, unknown120, unknown124).getLength();
    if (!(flags344 & 4)) {
        const vector3d<float> force = -basisY * (magnitude * 100.0f / 200.0f) * elapsedFloat;
        unknown56 += force.X;
        unknown60 += force.Y;
        unknown64 += force.Z;
        reinterpret_cast<vector3d<float>*>(&unknown56)->normalize();
    }
    speed = magnitude;
    float kph = magnitude / 1000.0f * 3600.0f;
    if (PlayerTest::GetPlayer()->getVehicle() == this)
        AchievementManager::s_achievementManager->recordVehicleSpeed(static_cast<int>(kph));
    if (!(unknown511 & 1) && leftCollisionBody && rightCollisionBody) {
        if (speed < 0.1f && init389) {
            rightCollisionBody->linearVelocity.x = rightCollisionBody->linearVelocity.y = 0;
            rightCollisionBody->angularVelocity = 0;
            leftCollisionBody->linearVelocity.x = leftCollisionBody->linearVelocity.y = 0;
            leftCollisionBody->angularVelocity = 0;
            collisionBody->linearVelocity.x = collisionBody->linearVelocity.y = 0;
            collisionBody->angularVelocity = 0;
        }
    }
    if (leftCollisionBody && rightCollisionBody) {
        unknown752 += unknown116 * unknown116 + unknown120 * unknown120 + unknown124 * unknown124;
        unknown756 += unknown116 * unknown116 + unknown120 * unknown120 + unknown124 * unknown124 - (init104 * init104 + init108 * init108 + init112 * init112);
        vector3d<float> angles;
        wheelNodes[2]->getRotation().toEulerDegree(angles);
        angles *= 0.01745329238474369f;
        wheelNodes[2]->setRotation(quaternion(angles + vector3d<float>(((unknown132 == 3 ? 1.0f : -1.0f) * static_cast<float>(__builtin_sqrtf(rightCollisionBody->linearVelocity.x * rightCollisionBody->linearVelocity.x + rightCollisionBody->linearVelocity.y * rightCollisionBody->linearVelocity.y)) / 25.0f)
            * static_cast<float>(elapsed) / 16.66666603088379f, 0, 0)));
        wheelNodes[3]->getRotation().toEulerDegree(angles);
        angles *= 0.01745329238474369f;
        wheelNodes[3]->setRotation(quaternion(angles + vector3d<float>(((unknown132 == 3 ? 1.0f : -1.0f) * static_cast<float>(__builtin_sqrtf(rightCollisionBody->linearVelocity.x * rightCollisionBody->linearVelocity.x + rightCollisionBody->linearVelocity.y * rightCollisionBody->linearVelocity.y)) / 25.0f)
            * static_cast<float>(elapsed) / 16.66666603088379f, 0, 0)));
        init980 += ((unknown132 != 3 ? -1.0f : 1.0f) * static_cast<float>(__builtin_sqrtf(leftCollisionBody->linearVelocity.x * leftCollisionBody->linearVelocity.x + leftCollisionBody->linearVelocity.y * leftCollisionBody->linearVelocity.y)) / 25.0f)
            * static_cast<float>(elapsed) / 16.66666603088379f;
        quaternion steering;
        quaternion wheel;
        steering.fromAngleAxis(-reinterpret_cast<b2RevoluteJoint*>(init644)->GetJointAngle(), vector3d<float>(0, 0, 1));
        wheel.fromAngleAxis(init980, vector3d<float>(1, 0, 0));
        wheelNodes[0]->setRotation(steering * wheel);
        wheelNodes[1]->setRotation(steering * wheel);
    }
    init136 = unknown132;
    unsigned int displayedSpeed = static_cast<unsigned int>(kph);
    _shiftGears(displayedSpeed);
    _ZN7Vehicle12playDriveSfxEj(this, displayedSpeed);
    if (kph > 10) {
        if (isDoorOpened(true) && !leftDoorTransition) closeDoor(true);
        if (isDoorOpened(false) && !rightDoorTransition) closeDoor(false);
    }
    if (carSoundMode)
        UpdateCarSounds();
}

Vehicle::~Vehicle()
{
    _cleanupSounds();
    stopSiren();
    PlayerTest* player = PlayerTest::GetPlayer();
    if (flags344 & (1u << 16)) {
        showHighlight(-1);
        ScriptManager::displayOnMinimap(this, false, true);
    }
    if (PlayerTest::GetPlayer()) {
        if (PlayerTest::GetPlayer()->getVehicle() == this) {
            player->stopDriving(playertest::PlayerCarState::MovingOut, true);
            player->setVehicle(0);
            player->unknown312 = 0;
            player->setLastUsedVehicle(0);
        }
        if (PlayerTest::GetPlayer()->unknown368 == this) {
            player->initMoveTo(0);
            player->stopMoving(false);
            player->flags240 &= ~0x1000u;
        }
    }
    if (collisionBody) {
        DestroyWheels();
        if (collisionBody->data) {
            ::operator delete(collisionBody->data);
            collisionBody->data = 0;
        }
        PhysicAttributes::s_world->DestroyBody(collisionBody);
        collisionBody = 0;
    }
    if (unknown24) {
        delete unknown24;
        unknown24 = 0;
    }
    Application* app = Application::GetInstance();
    EventManager* events = app->GetEventManager();
    {
        EvVehicleDestroyed event(this);
        events->raise(event);
    }
    delete carSounds;
    delete carSoundParameters;
    delete[] enterAnim;
    delete[] exitAnim;
    delete[] closeDoorAnim;
    delete[] init748;
    delete[] init768;
    delete[] init772;
    explosionAnimator->drop();
    if (!hasSceneNodePool() && enabledSceneNode) {
        app->GetDevice()->getSceneManager()->getRootSceneNode()->removeChild(enabledSceneNode);
        enabledSceneNode = 0;
    }
    for (int i = 0; i < 4; ++i) {
        if (wheelTrails[i]) {
            GS3DStuff::GetTrailMgr()->FreeTrail(wheelTrails[i]);
            wheelTrails[i] = 0;
        }
    }
}

#include "../core/CameraManager.h"
#include "../hud/MiniMap.h"
#include "../input/CControlManager.h"
void Vehicle::disable()
{
    if (!isEnabled())
        return;
    if (flags344 & 0x02000000u)
        tagForKill(false);

    PlayerTest* player = PlayerTest::GetPlayer();
    SavePrimaryInterface* primary = player;
    if (primary->getVehicle() == this) {
        CHudManager* hud = Application::GetInstance()->GetHudManager();
        Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player));
        if (hud->minimap)
            static_cast<MiniMap*>(hud->minimap)->setFollowedObject(character);
        if ((player->flags240 & 0x400u) && character->getVehicle()) {
            player->stopDriving(playertest::PlayerCarState::MovingOut, true);
            character->setAnimation(165, 1.0f, false, false, false);
            Application::GetInstance()->GetHudManager()->walking();
            Application::GetInstance()->GetControlManager()->exitCar(true);
        } else {
            CameraManager::getInstance()->enterMode(0, character, 0.3f, 0);
        }
        primary->setVehicle(0);
    }
    if (static_cast<const LevelObject*>(this) == player->lastHitVehicle)
        player->lastHitVehicle = 0;
    if (player->target == this) {
        static_cast<SavePositionInterface*>(player)->SetTarget(0);
        player->_SetTarget(0, true);
    }
    if (static_cast<Vehicle*>(player->unknown368) == this)
        player->unknown368 = 0;
    if (static_cast<Vehicle*>(player->unknown312) == this)
        player->unknown312 = 0;

    stopSiren();
    _cleanupSounds();
    cleanupTargetDetection();
    repair();
    Stop();
    clean();
    cleanTargets();
    aiTarget = 0;

    EventManager* events = Application::GetInstance()->GetEventManager();
    unsigned int storage[sizeof(EvVehicleDeactivated) / sizeof(unsigned int)];
    EvVehicleDeactivated* event = new (storage) EvVehicleDeactivated(this);
    events->raise(*event);
    flags344 = 1u << 23;
    LevelObject::disable();
    _ZN20EvVehicleDeactivatedD1Ev(event);
}
void Vehicle::OnDespawn()
{
    LevelObject::OnDespawn();
    unknown960Word = -5000;
    unknown4 &= ~0x800u;
    stopSiren();
    cleanupTargetDetection();
    repair();
    Stop();
    clean();
    cleanTargets();
    aiTarget = 0;

    PlayerTest* player = PlayerTest::GetPlayer();
    if (static_cast<const LevelObject*>(this) == player->lastHitVehicle)
        player->lastHitVehicle = 0;
    if (player->target == this) {
        static_cast<SavePositionInterface*>(player)->SetTarget(0);
        player->_SetTarget(0, true);
    }
    SavePrimaryInterface* primary = player;
    if (primary->getVehicle() == this)
        primary->setVehicle(0);
    if (static_cast<Vehicle*>(player->unknown368) == this)
        player->unknown368 = 0;
    if (static_cast<Vehicle*>(player->unknown312) == this)
        player->unknown312 = 0;

    EventManager* events = Application::GetInstance()->GetEventManager();
    unsigned int storage[sizeof(EvVehicleDeactivated) / sizeof(unsigned int)];
    EvVehicleDeactivated* event = new (storage) EvVehicleDeactivated(this);
    events->raise(*event);
    flags344 = 1u << 23;
    if (hasSceneNodePool())
        dropSceneNode();
    else
        sceneNode->setVisible(false);
    _ZN20EvVehicleDeactivatedD1Ev(event);
}

// Observed root-scene view: CRootSceneNode places ISceneNode 100 bytes in;
// field 40 points at a record whose field 8 is the stored setup value.
namespace {
// Scene-node, texture and effect names read by Vehicle::setupSceneNode.
const char vehicleSetupDoorFrontLeft[] = "dummy_door_front_left-node";
const char vehicleSetupDoorFrontRight[] = "dummy_door_front_right-node";
const char vehicleSetupBodySkin[] = "car_body-mesh-morpher-skin";
const char vehicleSetupInterior[] = "interior-node";
const char vehicleSetupTexture[] = "./car_texture.tga";
const char vehicleSetupDamageTexture[] = "./car_texture_damage.tga";
const char vehicleSetupWheelFrontLeft[] = "wheel_front_left-node";
const char vehicleSetupWheelFrontRight[] = "wheel_front_right-node";
const char vehicleSetupWheelBackLeft[] = "wheel_back_left-node";
const char vehicleSetupWheelBackRight[] = "wheel_back_right-node";
const char vehicleSetupBodyNode[] = "car_body-node";
const char vehicleSetupSmokeDummy[] = "dummy_p_smoke_00-node";
const char vehicleSetupSmokeEffect[] = "./p_smoke_00.bdae";
const char vehicleSetupFireEffect[] = "./p_fire_00.bdae";
const char vehicleSetupShadowNode[] = "shadow-node";
}

struct VehicleSetupRootRecord {
    unsigned char unknown0[8];
    void* value8;
};
struct VehicleSetupRootView {
    unsigned char unknown0[40];
    VehicleSetupRootRecord* record40;
};

void Vehicle::setupSceneNode(int id, irr::scene::ISceneNode* node, int count, void** params)
{
    using namespace irr;
    LevelObject::setupSceneNode(id, node, count, params);
    IrrlichtDevice* device = Application::GetInstance()->GetDevice();
    video::IVideoDriver* driver = device->getVideoDriver();
    GS3DStuff::SetColor(node, video::SColor(255, 102, 102, 102), GS3DStuff::Color3);
    GS3DStuff::SetColor(node, video::SColor(255, 229, 229, 229), GS3DStuff::Color2);
    params[0] = reinterpret_cast<VehicleSetupRootView*>(static_cast<collada::CRootSceneNode*>(node))->record40->value8;
    scene::ISceneNodeAnimator* animator =
        collada::CColladaDatabase::constructAnimator(init768, &collada::CColladaDatabase::DefaultFactory);
    node->addAnimator(animator);
    params[1] = animator;
    animator->drop();
    animator = collada::CColladaDatabase::constructAnimator(init772, &collada::CColladaDatabase::DefaultFactory);
    node->addAnimator(animator);
    params[2] = animator;
    animator->drop();
    params[3] = node->getSceneNodeFromUID(vehicleSetupDoorFrontLeft);
    params[4] = node->getSceneNodeFromUID(vehicleSetupDoorFrontRight);
    params[5] = node->getSceneNodeFromUID(vehicleSetupBodySkin);
    params[6] = node->getSceneNodeFromUID(vehicleSetupInterior);
    params[7] = driver->getTexture(vehicleSetupTexture);
    params[8] = driver->getTexture(vehicleSetupDamageTexture);
    params[9] = node->getSceneNodeFromUID(vehicleSetupBodySkin);
    scene::ISceneNode* shadow = node->getSceneNodeFromUID(vehicleSetupShadowNode);
    shadow->getChildren().first->value->setRenderingLayer(1);
    GS3DStuff::SetColor(shadow, video::SColor(255, 0, 0, 0), GS3DStuff::Color3);
    GS3DStuff::SetColor(shadow, video::SColor(255, 255, 255, 255), GS3DStuff::Color0);
    GS3DStuff::SetColor(shadow, video::SColor(255, 255, 255, 255), GS3DStuff::Color1);
    GS3DStuff::SetColor(shadow, video::SColor(255, 255, 255, 255), GS3DStuff::Color2);
    GS3DStuff::SetMaterialFlag(shadow, video::MaterialFlag1024, false);
    GS3DStuff::SetMaterialFlag(shadow, video::MaterialFlag512, false);
    GS3DStuff::SetMaterialFlag(shadow, video::MaterialFlag4, true);
    device->getSceneManager()->getRootSceneNode()->addChild(shadow);
    params[10] = shadow;
    params[11] = node->getSceneNodeFromUID(vehicleSetupWheelFrontLeft);
    params[12] = node->getSceneNodeFromUID(vehicleSetupWheelFrontRight);
    params[13] = node->getSceneNodeFromUID(vehicleSetupWheelBackLeft);
    params[14] = node->getSceneNodeFromUID(vehicleSetupWheelBackRight);
    params[15] = node->getSceneNodeFromUID(vehicleSetupBodyNode);
    params[16] = node->getSceneNodeFromUID(vehicleSetupSmokeDummy);
    if (params[16]) {
        SceneNodeManager* manager = SceneNodeManager::getInstance();
        params[17] = reinterpret_cast<void*>(manager->findOrCreatePool(vehicleSetupSmokeEffect, 5, _ZN12CGameFactory11getInstanceEv()));
        manager = SceneNodeManager::getInstance();
        params[18] = reinterpret_cast<void*>(manager->findOrCreatePool(vehicleSetupFireEffect, 5, _ZN12CGameFactory11getInstanceEv()));
    }
}

// Asset name passed to loadExplosion by Vehicle::Load.
namespace {
const char vehicleLoadExplosionAsset[] = "./anim_car_explode.bdae";
}

// Observed Vehicle words the header still declares as other types:
// offset 176 holds a float and offset 928 an int copied from the record.
struct VehicleLoadView {
    unsigned char unknown0[176];
    float value176;
    unsigned char unknown180[928 - 180];
    int value928;
};

void Vehicle::Load(const Structs::Car& data)
{
    using namespace irr;
    VehicleLoadView* view = reinterpret_cast<VehicleLoadView*>(this);
    LevelObject::Load(data, CCarFactory::getInstance());
    vehicleIndex = data.unknown80;
    init768 = data.unknown132;
    init772 = data.unknown172;
    view->value928 = data.unknown16;
    unknown240 = data.unknown72;
    gearProfile = data.unknown124;
    init156 = data.unknown104;
    init160 = data.unknown168;
    init164 = data.unknown76;
    mass = data.unknown148;
    init180 = mass * 9.80665;
    init184 = data.unknown88;
    view->value176 = data.unknown212;
    skidThreshold = data.unknown204;
    unknown188 = (float)data.unknown160 * 1000.0f / 3600.0f;
    defaultRadioStation = data.unknown96;
    init200 = data.unknown224;
    init204 = data.unknown136;
    init208 = data.unknown192;
    init212 = data.unknown180;
    init216 = data.unknown184;
    init220 = data.unknown188;
    tireTrailWidth = data.unknown220;
    init228 = data.unknown216;
    repairPrice = data.unknown92;
    init232 = data.unknown196;
    init236 = data.unknown200;
    enterAnim = data.unknown108;
    exitAnim = data.unknown116;
    closeDoorAnim = data.unknown84;
    unknown912 = data.unknown208;
    maxHealth = data.unknown156;
    health = data.unknown128;
    cameraMinDistance = data.unknown164;
    cameraSideDistance = data.unknown152;
    cameraPositionHeight = data.unknown100;
    cameraLookHeight = data.unknown144;
    cameraLookAhead = data.unknown140;
    entryAnimationScale = data.unknown112;
    doorAnimationScale = data.unknown120;
    if (!hasSceneNodePool()) {
        GS3DStuff::SetColor(sceneNode, video::SColor(255, 102, 102, 102), GS3DStuff::Color3);
        GS3DStuff::SetColor(sceneNode, video::SColor(255, 229, 229, 229), GS3DStuff::Color2);
        IrrlichtDevice* device = Application::GetInstance()->GetDevice();
        video::IVideoDriver* driver = device->getVideoDriver();
        core::vector3d<float> angles;
        GetRotation().toEulerDegree(angles);
        rotationX = angles.X;
        rotationY = angles.Y;
        rotationZ = angles.Z;
        scene::ISceneNode* node = sceneNode;
        VehicleSetupRootRecord* record = !node
            ? reinterpret_cast<VehicleSetupRootView*>(node)->record40
            : reinterpret_cast<VehicleSetupRootView*>(static_cast<collada::CRootSceneNode*>(node))->record40;
        repairVisualState = reinterpret_cast<VehicleRepairVisualState*>(record->value8);
        leftDoorAnimator = collada::CColladaDatabase::constructAnimator(init768, &collada::CColladaDatabase::DefaultFactory);
        rightDoorAnimator = collada::CColladaDatabase::constructAnimator(init772, &collada::CColladaDatabase::DefaultFactory);
        sceneNode->addAnimator(leftDoorAnimator);
        leftDoorAnimator->drop();
        sceneNode->addAnimator(rightDoorAnimator);
        rightDoorAnimator->drop();
        leftDoor = sceneNode->getSceneNodeFromUID(vehicleSetupDoorFrontLeft);
        rightDoor = sceneNode->getSceneNodeFromUID(vehicleSetupDoorFrontRight);
        skinnedMesh = reinterpret_cast<collada::CSkinnedMeshSceneNode*>(sceneNode->getSceneNodeFromUID(vehicleSetupBodySkin));
        interior = sceneNode->getSceneNodeFromUID(vehicleSetupInterior);
        repairTexture = driver->getTexture(vehicleSetupTexture);
        damageTexture = driver->getTexture(vehicleSetupDamageTexture);
        repairMaterialNode = sceneNode->getSceneNodeFromUID(vehicleSetupBodySkin);
        enabledSceneNode = sceneNode->getSceneNodeFromUID(vehicleSetupShadowNode);
        enabledSceneNode->getChildren().first->value->setRenderingLayer(1);
        GS3DStuff::SetColor(enabledSceneNode, video::SColor(255, 0, 0, 0), GS3DStuff::Color3);
        GS3DStuff::SetColor(enabledSceneNode, video::SColor(255, 255, 255, 255), GS3DStuff::Color0);
        GS3DStuff::SetColor(enabledSceneNode, video::SColor(255, 255, 255, 255), GS3DStuff::Color1);
        GS3DStuff::SetColor(enabledSceneNode, video::SColor(255, 255, 255, 255), GS3DStuff::Color2);
        GS3DStuff::SetMaterialFlag(enabledSceneNode, video::MaterialFlag1024, false);
        GS3DStuff::SetMaterialFlag(enabledSceneNode, video::MaterialFlag512, false);
        GS3DStuff::SetMaterialFlag(enabledSceneNode, video::MaterialFlag4, true);
        wheelNodes[0] = sceneNode->getSceneNodeFromUID(vehicleSetupWheelFrontLeft);
        wheelNodes[1] = sceneNode->getSceneNodeFromUID(vehicleSetupWheelFrontRight);
        wheelNodes[2] = sceneNode->getSceneNodeFromUID(vehicleSetupWheelBackLeft);
        wheelNodes[3] = sceneNode->getSceneNodeFromUID(vehicleSetupWheelBackRight);
        exterior = sceneNode->getSceneNodeFromUID(vehicleSetupBodyNode);
        if (unknown4 & 1u)
            CreateBody();
        enableSkinning(false);
        enableBackfaceCulling(true);
        toggleInterior(false);
        device->getSceneManager()->getRootSceneNode()->addChild(enabledSceneNode);
    }
    loadExplosion(vehicleLoadExplosionAsset);
    carSounds = new CarSounds();
    if (carSounds) {
        carSoundParameters = new CarSoundParameters();
        carSoundMode = 0;
        carSoundParameters->load = 0;
        soundMaximumSpeed = data.unknown160;
        soundLoadCountdown = 0;
        switch (data.unknown176) {
        case 0: Init4CylNaSounds(); break;
        case 1: InitV6naSounds(); break;
        case 2: InitV6TurboSounds(); break;
        case 3: InitV8Z06Sounds(); break;
        }
    }
    switch (GetMetatype()) {
    case 5:
        driverMetatype = 104;
        driverBehavior = 0;
        break;
    case 38:
        driverMetatype = 48;
        driverBehavior = 0;
        break;
    }
}

struct VehicleDropSceneView {
    unsigned char pad0[316];
    irr::scene::ISceneNode* leftDoor;
    irr::scene::ISceneNode* rightDoor;
    irr::collada::CSkinnedMeshSceneNode* skinnedMesh;
    irr::scene::ISceneNode* interior;
    unsigned char pad332[408 - 332];
    irr::video::ITexture* repairTexture;
    irr::video::ITexture* damageTexture;
    irr::scene::ISceneNode* repairMaterialNode;
    unsigned char pad420[672 - 420];
    irr::scene::ISceneNode* enabledSceneNode;
    irr::scene::ISceneNode* wheelNodes[4];
    irr::scene::ISceneNode* exterior;
    unsigned char pad696[760 - 696];
    irr::scene::ISceneNodeAnimator* leftDoorAnimator;
    irr::scene::ISceneNodeAnimator* rightDoorAnimator;
    unsigned char pad768[812 - 768];
    int scenePool812;
    irr::scene::ISceneNode* repairGlassNode;
    irr::scene::ISceneNode* sceneData820;
    int lightPool824;
    int lightPool828;
    irr::scene::ISceneNode* lightNodes[3];
    irr::scene::ISceneNode* lightNode844;
    irr::scene::ISceneNode* sceneData848;
    irr::scene::ISceneNode* sceneData852;
    unsigned char pad856[880 - 856];
    int scenePool880;
    irr::scene::ISceneNode* pooledNode884;
    irr::scene::ISceneNode* sceneData888;
    int scenePool892;
    irr::scene::ISceneNode* repairLightNode;
    unsigned char pad900[908 - 900];
    VehicleRepairVisualState* repairVisualState;
};

extern "C" void _ZN7Vehicle13dropSceneNodeEv(Vehicle* self)
{
    VehicleDropSceneView* view = reinterpret_cast<VehicleDropSceneView*>(self);
    if (view->enabledSceneNode)
        view->enabledSceneNode->setVisible(false);
    self->LevelObject::dropSceneNode();
    view->repairVisualState = 0;
    view->leftDoorAnimator = 0;
    view->rightDoorAnimator = 0;
    view->leftDoor = 0;
    view->rightDoor = 0;
    view->skinnedMesh = 0;
    view->interior = 0;
    view->repairTexture = 0;
    view->damageTexture = 0;
    view->repairMaterialNode = 0;
    view->wheelNodes[0] = 0;
    view->wheelNodes[1] = 0;
    view->wheelNodes[2] = 0;
    view->wheelNodes[3] = 0;
    view->exterior = 0;
    view->sceneData820 = 0;
    view->sceneData848 = 0;
    view->sceneData852 = 0;
    view->enabledSceneNode = 0;
    view->sceneData888 = 0;
    SceneNodeManager* manager = SceneNodeManager::getInstance();
    manager->drop(view->scenePool812, view->repairGlassNode);
    manager->drop(view->scenePool892, view->repairLightNode);
    manager->drop(view->lightPool824, view->lightNodes[0]);
    manager->drop(view->lightPool824, view->lightNodes[1]);
    manager->drop(view->lightPool828, view->lightNodes[2]);
    manager->drop(view->lightPool828, view->lightNode844);
    manager->drop(view->scenePool880, view->pooledNode884);
    view->repairGlassNode = 0;
    view->repairLightNode = 0;
    view->lightNodes[0] = 0;
    view->lightNodes[1] = 0;
    view->lightNodes[2] = 0;
    view->lightNode844 = 0;
    view->pooledNode884 = 0;
}


static inline bool isDrivenByPlayer(const LevelObject* vehicle)
{
    PlayerTest* player = PlayerTest::GetPlayer();
    LevelObject* car = player->unknown312;
    if (!car)
        car = player->unknown368;
    if (car != vehicle)
        return false;
    if (!PlayerTest::GetPlayer()->unknown372)
        return false;
    return true;
}

void Vehicle::_processAIFlags()
{
    using irr::core::vector3d;
    typedef vector3d<float> vector3df;
    if (!(flags344 & 0x800u))
        return;
    EventManager* events = Application::GetInstance()->GetEventManager();
    if (flags344 & 0x08000000u)
        SoundManager::getInstance()->setSourcePos(241, sirenChannel, GetPosition());
    if (flags344 & 0x80u) {
        if (unknown132 == 1) {
            brake(1.0f);
        } else {
            Stop();
            {
                events->raise(EvNPCVehicle(23, this));
            }
        }
        return;
    }
    if ((flags344 & 0x2000u) && aiTarget) {
        const float distanceSQ = aiTarget->GetPosition().getDistanceFromSQ(GetPosition());
        vector3df visiblePoint;
        if (distanceSQ < 9000000.0f && canSeeLevelObject(aiTarget, visiblePoint)) {
            if (!(flags344 & 0x4000u)) {
                flags344 |= 0x4000u;
                {
                    events->raise(EvNPCVehicle(18, this));
                }
                if (unknown240 == 3 && !(flags344 & 0x08000000u) && !isDrivenByPlayer(this))
                    playSiren();
            }
            if (flags344 & 0x100000u) {
                const vector3df targetPosition = aiTarget->GetPosition();
                const float targetY = targetPosition.Y;
                const float targetX = targetPosition.X;
                const vector3df front = GetFront();
                const float frontX = front.X;
                const float frontY = front.Y;
                float resultX;
                float productY;
                if ((irr::os::Randomizer::rand() & 1) == 0) {
                    const float productX = frontY * 200.0f;
                    resultX = targetX + productX;
                    productY = frontX * 200.0f;
                } else {
                    const float productX = frontY * -200.0f;
                    resultX = targetX + productX;
                    productY = frontX * -200.0f;
                }
                destination.X = resultX;
                destination.Y = productY + targetY;
                destination.Z = targetPosition.Z;
            } else if (flags344 & 0x200000u) {
                destination = aiTarget->GetPosition() + GetFront() * 300.0f;
            } else {
                destination = aiTarget->GetPosition();
            }
            if (distanceSQ < 2250000.0f && !(flags344 & 0x40000u) && aiTarget->GetSpeed() < 10.0f) {
                flags344 |= 0x40000u;
                {
                    events->raise(EvNPCVehicle(24, this));
                }
            } else if (flags344 & 0x40000u) {
                flags344 &= ~0x40000u;
                {
                    events->raise(EvNPCVehicle(25, this));
                }
            }
        } else if (flags344 & 0x4000u) {
            cleanupTargetDetection();
            if (flags344 & 0x40000u) {
                flags344 &= ~0x40000u;
                {
                    events->raise(EvNPCVehicle(25, this));
                }
            }
        }
    }
    vector3df direction;
    if (aiTarget && !aiTarget->sceneNode)
        aiTarget = 0;

    if ((((flags344 & 0x5000u) == 0x5000u) || (flags344 & 0x400000u)) && aiTarget) {
            if (flags344 & 0x400000u) {
                if (flags344 & 0x100000u) {
                    const vector3df targetPosition = aiTarget->GetPosition();
                    const float targetY = targetPosition.Y;
                    const float targetX = targetPosition.X;
                    const vector3df front = GetFront();
                    const float frontX = front.X;
                    const float frontY = front.Y;
                    float resultX;
                    float productY;
                    if ((irr::os::Randomizer::rand() & 1) == 0) {
                        const float productX = frontY * 200.0f;
                        resultX = targetX + productX;
                        productY = frontX * 200.0f;
                    } else {
                        const float productX = frontY * -200.0f;
                        resultX = targetX + productX;
                        productY = frontX * -200.0f;
                    }
                    destination.X = resultX;
                    destination.Y = productY + targetY;
                    destination.Z = targetPosition.Z;
                } else if (flags344 & 0x200000u) {
                    destination = aiTarget->GetPosition() + GetFront() * 300.0f;
                } else {
                    destination = aiTarget->GetPosition();
                }
            }
            if (flags344 & 0x80000u) {
                flags344 |= 8;
                brakeAmount = 1.0f;
            } else {
                accelerate(1.0f);
            }
            direction = destination - GetPosition();
            direction.getLength();
            if (direction.getLengthSQ() < 2250000.0f && aiTarget->GetSpeed() < 30.0f) {
                {
                    events->raise(EvNPCVehicle(24, this));
                }
            }
        } else if (flags344 & 0x100u) {
        Stop();
        if (static_cast<unsigned int>(waitElapsed) >= static_cast<unsigned int>(waitDuration)) {
            flags344 &= ~0x100u;
            {
                events->raise(EvNPCVehicle(5, this));
            }
        }
    } else {
            direction = destination - GetPosition();
            const float distance = direction.getLength();
            if (unknown24->info->unknown84 && unknown240 == 0) {
                if (speed > 0.0f) {
                    if (distance < 500.0f) {
                        {
                            events->raise(EvNPCVehicle(1, this));
                        }
                        pathToFollow = 0;
                        brake(1.0f);
                    } else if (distance < 1000.0f) {
                        brake((distance - 600.0f) / -400.0f + 1.0f);
                    } else {
                        if (flags344 & 0x400u)
                            accelerate(0.5f);
                        else if (flags344 & 0x200u)
                            accelerate(1.0f);
                    }
                } else {
                    if (flags344 & 0x400u)
                        accelerate(0.5f);
                    else if (flags344 & 0x200u)
                        accelerate(1.0f);
                    if (distance < 500.0f) {
                        {
                            events->raise(EvNPCVehicle(1, this));
                        }
                        pathToFollow = 0;
                        brake(1.0f);
                    }
                    unknown24->info->unknown84 = false;
                }
            } else if (!(flags344 & 0x80000u)) {
                if (flags344 & 0x1000u)
                    accelerate(1.0f);
                else if (flags344 & 0x400u)
                    accelerate(0.5f);
                else if (flags344 & 0x200u)
                    accelerate(1.0f);
                if (distance < 500.0f) {
                    {
                        events->raise(EvNPCVehicle(1, this));
                    }
                    if (driveToLocationFlag) {
                        pathToFollow = 0;
                        brake(1.0f);
                    }
                }
            }
            if (sensorContactCount && !(flags344 & 0x1000u) && !(flags344 & 0x10000000u))
                brake(1.0f);
            else if (flags344 & 0x80000u) {
                flags344 |= 8;
                brakeAmount = 1.0f;
            }
        }
    vector3df steeringDirection = direction;
    steeringDirection.rotateXYBy(90.0, vector3df());
    const float side = steeringDirection.dotProduct(GetFront());
    const vector3df adjustedSnapshot = adjustedDestination;
    const vector3df displacement = adjustedSnapshot - GetPosition();
    const float cosine = displacement.dotProduct(-GetFront()) /
        (displacement.getLength() * -GetFront().getLength());
    float angle = acosf(irr::core::clamp(cosine, -1.0f, 1.0f));
    if (static_cast<double>(displacement.getLengthSQ()) < 0.1)
        angle = 0.0f;
    if (flags344 & 0x80000u) {
        if (side > 0.0f)
            turn(false, 1.0f);
        else
            turn(true, 1.0f);
        const vector3df& turnFrontSnapshot = GetFront();
        if (((init372 * turnFrontSnapshot.X + init376 * turnFrontSnapshot.Y) + init380 * turnFrontSnapshot.Z) < 0.0f || angle < 0.2f)
            flags344 &= ~0x80000u;
    } else if (!(flags344 & 2)) {
        const float amount = angle > 1.5707963705062866f ? 1.0f : angle / 1.5707963705062866f;
        if (side < 0.0f)
            turn(false, amount);
        else
            turn(true, amount);
    }
}

struct VehicleDoorClearView {
    unsigned char pad0[316];
    irr::scene::ISceneNode* leftDoor;
    irr::scene::ISceneNode* rightDoor;
    unsigned char pad324[632 - 324];
    b2Body* collisionBody;
};

static inline bool otherGroup(b2Shape* s, const Vehicle* self)
{
    if (s->GetFilterData().groupIndex != self->getPhysicAttributes()->getIndex() + 1) return true;
    return false;
}

static inline bool skipBody(b2Shape* s, b2Body* body, const VehicleDoorClearView* v)
{
    if (body != 0) {
        if (s->GetBody() == body) return true;
        if (s->GetBody() == v->collisionBody) return true;
        return false;
    }
    if (s->GetBody() == v->collisionBody) return true;
    return false;
}

extern "C" bool _ZNK7Vehicle11isDoorClearEbP6b2Body(const Vehicle* self, bool left, b2Body* body)
{
    const VehicleDoorClearView* view = reinterpret_cast<const VehicleDoorClearView*>(self);
    b2World* world = PhysicAttributes::s_world;
    b2Shape* shapes[20] = {0};
    irr::core::vector3d<float> pos;
    if (left)
        pos = view->leftDoor->getAbsolutePosition();
    else
        pos = view->rightDoor->getAbsolutePosition();
    b2AABB bounds;
    bounds.lowerBound.x = pos.X / 100.0f - 0.5f;
    bounds.lowerBound.y = pos.Y / 100.0f - 0.5f;
    bounds.upperBound.x = pos.X / 100.0f + 0.5f;
    bounds.upperBound.y = pos.Y / 100.0f + 0.5f;
    float fraction = 1.0f;
    b2Vec2 normal;
    b2Segment first;
    first.p1 = bounds.lowerBound;
    first.p2 = bounds.upperBound;
    b2Segment second;
    second.p1.x = bounds.upperBound.x;
    second.p1.y = bounds.lowerBound.y;
    second.p2.x = bounds.lowerBound.x;
    second.p2.y = bounds.upperBound.y;
    world->Query(bounds, shapes, 20);
    for (int i = 0; i < 20; ++i) {
        b2Shape* shape = shapes[i];
        if (!shape) break;
        if (shape->GetFilterData().categoryBits == 0 && otherGroup(shape, self)) continue;
        if (shape->GetFilterData().categoryBits == 0 && shape->GetFilterData().maskBits == 0) continue;
        if (shape->IsSensor() || skipBody(shape, body, view)) continue;
        if (shape->TestSegment(shape->GetBody()->GetXForm(), &fraction, &normal, first, 1.0f)) return false;
        if (shapes[i]->TestSegment(shapes[i]->GetBody()->GetXForm(), &fraction, &normal, second, 1.0f)) return false;
    }
    return true;
}

#include "../vehicles/VehicleBodyShapes.h"

// Box2D 2.0.1 joint definitions (licensed SDK layout, see VehicleBodyShapes.h).
enum b2JointType { e_unknownJoint, e_revoluteJoint, e_prismaticJoint };
struct b2JointDef {
    b2JointDef() { type = e_unknownJoint; userData = 0; body1 = 0; body2 = 0; collideConnected = false; }
    b2JointType type;
    void* userData;
    b2Body* body1;
    b2Body* body2;
    bool collideConnected;
};
struct b2RevoluteJointDef : b2JointDef {
    b2RevoluteJointDef()
    {
        type = e_revoluteJoint;
        localAnchor1.SetZero();
        localAnchor2.SetZero();
        referenceAngle = 0.0f;
        lowerAngle = 0.0f;
        upperAngle = 0.0f;
        maxMotorTorque = 0.0f;
        motorSpeed = 0.0f;
        enableLimit = false;
        enableMotor = false;
    }
    void Initialize(b2Body* body1, b2Body* body2, const b2Vec2& anchor);
    b2Vec2 localAnchor1, localAnchor2;
    float referenceAngle;
    bool enableLimit;
    float lowerAngle, upperAngle;
    bool enableMotor;
    float motorSpeed, maxMotorTorque;
};
struct b2PrismaticJointDef : b2JointDef {
    b2PrismaticJointDef()
    {
        type = e_prismaticJoint;
        localAnchor1.SetZero();
        localAnchor2.SetZero();
        localAxis1.x = 1.0f; localAxis1.y = 0.0f;
        referenceAngle = 0.0f;
        enableLimit = false;
        lowerTranslation = 0.0f;
        upperTranslation = 0.0f;
        enableMotor = false;
        maxMotorForce = 0.0f;
        motorSpeed = 0.0f;
    }
    void Initialize(b2Body* body1, b2Body* body2, const b2Vec2& anchor, const b2Vec2& axis);
    b2Vec2 localAnchor1, localAnchor2, localAxis1;
    float referenceAngle;
    bool enableLimit;
    float lowerTranslation, upperTranslation;
    bool enableMotor;
    float maxMotorForce, motorSpeed;
};

class b2Joint;
struct Box2DUserInfo;
extern "C" b2Joint* _ZN7b2World11CreateJointEPK10b2JointDef(b2World* world, const b2JointDef* def);
extern "C" void _ZN12b2PolygonDef8SetAsBoxEff(b2PolygonDef* def, float hx, float hy);

namespace {
struct WheelView {
    unsigned char unknown0[144];
    float rotationZ;
    unsigned char unknown148[20];
    unsigned int mass;
    unsigned char unknown172[52];
    unsigned int tireWidth;
    unsigned int tireLength;
    unsigned char unknown232[340];
    irr::core::vector3d<float> wheelOffset0;
    irr::core::vector3d<float> wheelOffset1;
    irr::core::vector3d<float> wheelOffset2;
    irr::core::vector3d<float> wheelOffset3;
    irr::core::vector3d<float> wheelCenter;
    b2Body* collisionBody;
    b2Body* leftCollisionBody;
    b2Body* rightCollisionBody;
    b2Joint* wheelJoint;
    unsigned char unknown648[28];
    irr::scene::ISceneNode* wheelNodes[4];
};
inline b2Vec2 bodyWorldPoint(const b2Body* body, const b2Vec2& v)
{
    const float* r = body->transform.rotation;
    const b2Vec2 rotated(r[0] * v.x + r[2] * v.y, r[1] * v.x + r[3] * v.y);
    return b2Vec2(body->transform.position.x + rotated.x, body->transform.position.y + rotated.y);
}
}

inline const b2Vec2& bodyWorldCenter(const b2Body* body)
{
    return *reinterpret_cast<const b2Vec2*>(reinterpret_cast<const char*>(body) + 44);
}

extern "C" void _ZN7Vehicle12CreateWheelsEP13Box2DUserInfo(Vehicle* self, Box2DUserInfo* info)
{
    b2World* world = PhysicAttributes::s_world;
    WheelView* view = reinterpret_cast<WheelView*>(self);
    if (!view->wheelNodes[0])
        return;
    const irr::core::vector3d<float> front = view->wheelNodes[0]->getPosition();
    view->wheelOffset0 = irr::core::vector3d<float>(front.X, front.Y, 0.0f);
    view->wheelOffset1.X = -front.X;
    view->wheelOffset1.Y = front.Y;
    view->wheelOffset1.Z = 0.0f;
    irr::scene::ISceneNode* rearNode = view->wheelNodes[2];
    const irr::core::vector3d<float> rear = rearNode->getPosition();
    view->wheelOffset2 = irr::core::vector3d<float>(rear.X, rear.Y, 0.0f);
    view->wheelOffset3 = irr::core::vector3d<float>(-rear.X, rear.Y, 0.0f);
    view->wheelCenter = (view->wheelOffset0 + view->wheelOffset1 + view->wheelOffset2 + view->wheelOffset3) * 0.25f;

    b2BodyDef frontDef;
    frontDef.linearDamping = 0.0f;
    frontDef.angularDamping = 0.0f;
    view->leftCollisionBody = world->CreateBody(&frontDef);
    view->leftCollisionBody->SetXForm(bodyWorldPoint(view->collisionBody,
                                                     b2Vec2((view->wheelOffset0.X + view->wheelOffset1.X) * 0.5f / 100.0f,
                                                            (view->wheelOffset0.Y + view->wheelOffset1.Y) * 0.5f / 100.0f)),
                                      -0.017453292f * view->rotationZ);
    view->leftCollisionBody->data = info;

    b2BodyDef rearDef;
    rearDef.linearDamping = 0.0f;
    rearDef.angularDamping = 0.0f;
    view->rightCollisionBody = world->CreateBody(&rearDef);
    view->rightCollisionBody->SetXForm(bodyWorldPoint(view->collisionBody,
                                                     b2Vec2((view->wheelOffset2.X + view->wheelOffset3.X) * 0.5f / 100.0f,
                                                            (view->wheelOffset2.Y + view->wheelOffset3.Y) * 0.5f / 100.0f)),
                                      -0.017453292f * view->rotationZ);
    view->rightCollisionBody->data = info;

    b2PolygonDef frontShape;
    _ZN12b2PolygonDef8SetAsBoxEff(&frontShape, view->tireWidth * 0.5f / 100.0f,
                                  view->tireLength / 100.0f);
    frontShape.density = 1.0f;
    frontShape.filter.categoryBits = 0;
    frontShape.filter.maskBits = 0;
    frontShape.filter.groupIndex = 0;
    view->leftCollisionBody->CreateShape(&frontShape);

    b2PolygonDef rearShape;
    _ZN12b2PolygonDef8SetAsBoxEff(&rearShape, view->tireWidth * 0.5f / 100.0f,
                                  view->tireLength / 100.0f);
    rearShape.density = 1.0f;
    rearShape.filter.categoryBits = 0;
    rearShape.filter.maskBits = 0;
    rearShape.filter.groupIndex = 0;
    view->rightCollisionBody->CreateShape(&rearShape);

    view->leftCollisionBody->SetMassFromShapes();
    view->rightCollisionBody->SetMassFromShapes();
    b2MassData massData;
    massData.I = view->leftCollisionBody->inertia;
    massData.center = view->leftCollisionBody->localCenter;
    massData.mass = view->mass / 3.0f;
    view->leftCollisionBody->SetMass(&massData);
    view->rightCollisionBody->SetMass(&massData);

    b2RevoluteJointDef revolute;
    revolute.Initialize(view->collisionBody, view->leftCollisionBody, bodyWorldCenter(view->leftCollisionBody));
    revolute.enableMotor = false;
    revolute.maxMotorTorque = 100.0f;
    view->wheelJoint = (_ZN7b2World11CreateJointEPK10b2JointDef(world, &revolute));

    b2PrismaticJointDef prismatic;
    prismatic.Initialize(view->collisionBody, view->rightCollisionBody, bodyWorldCenter(view->rightCollisionBody), b2Vec2(1.0f, 0.0f));
    prismatic.enableLimit = true;
    prismatic.upperTranslation = 0.0f;
    prismatic.lowerTranslation = 0.0f;
    _ZN7b2World11CreateJointEPK10b2JointDef(world, &prismatic);

    self->removeWheelCollisions();
}
