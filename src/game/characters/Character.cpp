/*
 * Character
 *
 * Original file: Character.cpp
 * Area:          characters
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Character.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../ai/AIManagerSingleton.h"
#include "Character.h"
#include "../core/Lock.h"
#include "../rendering/CustomBillboardSceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../audio/SoundManager.h"
#include "../world/GameObjectManager.h"
#include "../vehicles/Vehicle.h"
#include "PlayerTest.h"
#include "../ai/NPC.h"
#include "PhysicAttributes.h"
#include "PhysicInfo.h"
#include "../core/Physics.h"
#include "../app/Application.h"
#include "../input/CControlManager.h"
#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"
#include "../rendering/GS3DStuff.h"
#include "../world/SceneNodeManager.h"
#include "../meta/Achievements.h"
#include "../scripting/ScriptManager.h"

irr::scene::ITimelineController* Character::s_timelineController;
bool Character::b_isBloodOn = true;
int Character::s_bloodpuddle = -1;
int Character::s_bloodsplash = -1;
irr::scene::ISceneNode* Character::m_bloodSplash;

extern "C" float acosf(float);
extern "C" long lrand48();
extern "C" irr::collada::CColladaFactory* _ZN12CGameFactory11getInstanceEv() __attribute__((weak));
void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_character_transitions {
extern const unsigned int civPassive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scriptedNpc_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civAggressive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int gangMember_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_trans[] __attribute__((visibility("hidden")));
extern const unsigned int swat_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civ_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int guard_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scripted_vehicle_trans[] __attribute__((visibility("hidden")));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

int __attribute__((weak)) Character::getSpawnType()
{
    return spawnType;
}

void __attribute__((weak)) Character::setSpawnType(int type)
{
    spawnType = type;
}

Vehicle* __attribute__((weak)) Character::getVehicle() const
{
    return vehicle;
}

Character* __attribute__((weak)) Character::getLockTarget() const
{
    return lockTarget;
}

const irr::core::vector3d<float>& __attribute__((weak)) Character::getCameraOffset() const
{
    return cameraOffset;
}

int __attribute__((weak)) Character::getMaxHealth() const
{
    return maxHealth;
}

int __attribute__((weak)) Character::getHealth() const
{
    return health;
}

void __attribute__((weak)) Character::SetTarget(LevelObject* value)
{
    target = value;
}

void* __attribute__((weak)) Character::getSkinMesh()
{
    return skinMesh;
}

bool Character::canAnimationBeInterrupted(int id)
{
    switch (id) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 86:
    case 164:
    case 175:
        return false;
    default:
        return true;
    }
}

void Character::setVehicle(Vehicle* value)
{
    vehicle = value;
}

void Character::updatePhysic(int)
{
}

void Character::render()
{
}

void Character::nextPunch()
{
    if (++punchIndex > 4)
        punchIndex = 1;
}

void Character::nextKick()
{
    if (++kickIndex > 6)
        kickIndex = 5;
}

void Character::init()
{
    health = maxHealth;
    unknown4 &= ~0x10u;
    movementFlags = 0;
}

void Character::block(int side)
{
    if (__builtin_expect(side == 0, 1))
        setAnimation(81, 1.0f, false, false, false);
    else if (side == 1)
        setAnimation(82, 1.0f, false, false, false);
}

void Character::enable()
{
    const bool wasEnabled = isEnabled();
    LevelObject::enable();
    if (!wasEnabled) {
        setAnimation(-1, 1.0f, false, false, false);
        init();
    }
}

void Character::disable()
{
    if (isEnabled()) {
        LevelObject::disable();
        clean();
    }
}

void Character::clean()
{
    const bool preserveFlag = unknown4 & 4;
    unknown4 = 0;
    if (preserveFlag)
        unknown4 |= 4;
    else
        unknown4 &= ~4u;

    unknown264 = 0;
    turnDirection = irr::core::vector3d<float>();
    turning = false;
    cleanPhysic();
    vehicle = 0;
    target = 0;
    removeBloodPuddle();
}

void Character::updateSceneNode(int)
{
}

void Character::cleanTimelineController()
{
    if (s_timelineController) {
        s_timelineController->drop();
        s_timelineController = 0;
    }
}

void Character::setAnimationSpeedMultiplier(int speed)
{
    animationSpeedMultiplier = speed;
}

bool Character::setAnimation(const char* name, int speed, bool a, bool b, bool c)
{
    const int id = s_timelineController->getClipIndex(name);
    return setAnimation(id, static_cast<float>(speed), a, b, c);
}

void Character::resetAnimation()
{
    animationFrame = 0.0f;
}

bool Character::isCurrentAnimation(int id)
{
    return currentAnimation == id;
}

bool __attribute__((weak)) Character::isDown()
{
    if (isCurrentAnimation(-1))
        return true;
    return isCurrentAnimation(162);
}

bool __attribute__((weak)) Character::isDying()
{
    if (isCurrentAnimation(86))
        return true;
    return isCurrentAnimation(175);
}

bool Character::isAnimationLastFrame(float advance) const
{
    if (!animationLoops && static_cast<int>(advance + animationFrame) >= animationFrameCount)
        return true;
    if (currentAnimation != -1) {
        bool wrapped = false;
        int current = static_cast<int>(animationFrame) % animationFrameCount;
        int next = static_cast<int>(advance + animationFrame) % animationFrameCount;
        if (current > next)
            wrapped = true;
        return wrapped;
    }
    return false;
}

void Character::setLockTarget(Character*)
{
}

bool Character::isInFlinchAnimation()
{
    return static_cast<unsigned int>(currentAnimation) - 83u <= 3u
        || currentAnimation == 162;
}

bool Character::isInHitByCarAnimation()
{
    return static_cast<unsigned int>(currentAnimation) - 17u <= 4u;
}

void Character::walkToTarget()
{
    if (target && !isCurrentAnimation(83) && !isCurrentAnimation(84) && !isCurrentAnimation(85))
        walkToLocation(target->GetPosition());
}

void __attribute__((weak)) Character::setCameraOffset(const irr::core::vector3d<float>& offset)
{
    cameraOffset = offset;
}

extern "C" {
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

void Character::removeBloodPuddle()
{
    if (b_isBloodOn && bloodPuddle) {
        bloodPuddle->setVisible(false);
        if (sceneNode)
            sceneNode->removeChild(bloodPuddle);
        bloodPuddle = 0;
    }
}

void Character::freeBloodObjects()
{
    if (b_isBloodOn) {
        SceneNodeManager::getInstance()->drop(s_bloodpuddle, 0);
        SceneNodeManager::getInstance()->drop(s_bloodsplash, m_bloodSplash);
        s_bloodpuddle = -1;
        s_bloodsplash = -1;
        m_bloodSplash = 0;
    }
}

void Character::loadBloodObjects(const char* puddle, const char* splash)
{
    if (b_isBloodOn) {
        s_bloodpuddle = SceneNodeManager::getInstance()->findOrCreatePool(
            puddle, 8, _ZN12CGameFactory11getInstanceEv());
        s_bloodsplash = SceneNodeManager::getInstance()->findOrCreatePool(
            splash, 8, _ZN12CGameFactory11getInstanceEv());
    }
}

bool Character::isPlayer() const
{
    return this == reinterpret_cast<Character*>(
        static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
}

void Character::shooted(int amount, LevelObject* source)
{
    if (isDying() || currentAnimation == 164 || isDead() || (movementFlags & 0x10000u))
        return;

    applyDamage(amount, source, false);
    if (!isPlayer()) {
        if (isDown()) {
            setAnimation(162, 1.0f, false, false, false);
        } else if (!(lrand48() & 1)) {
            setAnimation(84, 1.0f, false, false, false);
        } else {
            setAnimation(85, 1.0f, false, false, false);
        }
    }
    if (isPlayer()) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(129, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }
    if (reinterpret_cast<Character*>(Lock::getInstance()->target) != this)
        return;
    Lock::getInstance()->billboard->activateAnimation();
}

void Character::goToIdle()
{
    if (!isCurrentAnimation(getSpecificAnimation(165)))
        setAnimation(getSpecificAnimation(165), 1.0f, true, false, false);
}

namespace {
inline unsigned int withMovementMode(unsigned int flags, unsigned int mode)
{
    // Keep the shifts separate so GCC retains the retail byte-clearing sequence.
    const int upperFlags = static_cast<int>(flags) >> 8;
    const unsigned int preservedFlags = static_cast<unsigned int>(upperFlags) << 8;
    return preservedFlags | mode;
}
}

void Character::Stop()
{
    LevelObject::Stop();
    movementFlags = withMovementMode(movementFlags, 1);
    setAnimation(getSpecificAnimation(212), 1.0f, false, false, false);
}

void Character::onRocketLaunched()
{
    union {
        unsigned int word;
        struct {
            unsigned int : 29;
            unsigned int rocketLaunched : 1;
        } bits;
    } flags;
    flags.word = movementFlags & 0xefffffffu;
    flags.bits.rocketLaunched = 1;
    movementFlags = flags.word;
}

static inline bool isAnimationLocked(unsigned int flags)
{
    return static_cast<int>(flags << 20) < 0;
}

bool Character::setAnimation(int id, float speed, bool loop, bool flag149, bool flag150)
{
    if (isAnimationLocked(movementFlags))
        return false;

    if (id == -1) {
        currentAnimation = -1;
        animationStartFrame = 0;
        animationEndFrame = 0;
        animationFrameCount = 0;
        animationSpeed = 0.0f;
        animationLoops = false;
        animationFlag149 = false;
        animationFlag150 = false;
        animationFrame = 0.0f;
        return false;
    }

    if (currentAnimation == id)
        return false;
    if (!animationLoops && animationFrame < static_cast<float>(animationFrameCount)
        && !canAnimationBeInterrupted(currentAnimation)
        && !ScriptManager::getInstance()->isInCinematic()) {
        if (!canAnimationBeInterrupted(id))
            setNextAnimation(id, static_cast<int>(speed), loop, flag149, flag150);
        return false;
    }

    if (currentAnimation == 67 && getWeapon()->getWeaponType() == 7)
        getWeapon()->reloadRocket();
    if (id == 164)
        movementFlags |= 0x80000000u;

    nextAnimation = -1;
    currentAnimation = id;
    animationStartFrame = s_timelineController->getClipStart(currentAnimation);
    animationEndFrame = s_timelineController->getClipEnd(currentAnimation);
    animationFrameCount = s_timelineController->getClipLength(currentAnimation);
    animationSpeed = static_cast<float>(animationSpeedMultiplier) * speed;
    animationLoops = loop;
    animationFlag149 = flag149;
    animationFlag150 = flag150;
    animationFrame = 0.0f;
    return true;
}

bool __attribute__((weak)) Character::isDead()
{
    if (static_cast<int>(movementFlags << 17) < 0)
        return true;
    return static_cast<int>(movementFlags << 18) < 0;
}

void Character::setNextAnimation(int id, int, bool, bool, bool)
{
    if (!(movementFlags & 0x800u))
        nextAnimation = id;
}

void Character::setNextAnimation(const char* name, int speed, bool a, bool b, bool c)
{
    if (!(movementFlags & 0x800u)) {
        const int id = s_timelineController->getClipIndex(name);
        setNextAnimation(id, speed, a, b, c);
    }
}

void Character::setReloadWeaponAnimation(int type)
{
    switch (type) {
    case 1:
        if (s_type[getObjectType()] == 5 && static_cast<NPC*>(this)->category428 == 3)
            setAnimation(56, 1.0f, true, false, false);
        else
            setAnimation(51, 1.0f, true, false, false);
        break;
    case 2:
        setAnimation(60, 1.0f, true, false, false);
        break;
    case 3:
        setAnimation(76, 1.0f, true, false, false);
        break;
    case 4:
        setAnimation(75, 1.0f, true, false, false);
        break;
    case 5:
        setAnimation(51, 1.0f, true, false, false);
        break;
    case 6:
        // GCC merges this with case 2 in the retail jump-table layout.
        setAnimation(60, 1.0f, true, false, false);
        break;
    case 7:
        setAnimation(67, 1.0f, true, false, false);
        break;
    case 8:
        setAnimation(68, 1.0f, true, false, false);
        break;
    }
}

void Character::checkForWeaponReload()
{
    Weapon* weapon = getWeapon();
    if (!weapon)
        return;
    const int type = weapon->getWeaponType();
    if (type == 0 || weapon->getClip() > 0)
        return;

    if (s_type[getObjectType()] != 8) {
        weapon->reload(true);
        setReloadWeaponAnimation(type);
    } else if (Application::GetInstance()->GetWeaponManager()->getAmmo(weapon->getAmmoType(), PlayerTest::AnyContext) > 0) {
        weapon->reload(false);
        setReloadWeaponAnimation(type);
    }
}

void Character::setDestination(const irr::core::vector3d<float>& point, int limit)
{
    destination = point;
    destinationLimitSquared = limit * limit;
}

void Character::SetPosition(const irr::core::vector3d<float>& position)
{
    LevelObject::SetPosition(position);
    if (collisionBody) {
        collisionBody->SetXForm(b2Vec2(position.X / 100.0f, position.Y / 100.0f), collisionBody->angle);
        for (b2Shape* shape = collisionBody->shapeList; shape; shape = shape->next)
            PhysicAttributes::s_world->Refilter(shape);
    }
}

void Character::positionAtDoor(bool left)
{
    if (!vehicle)
        return;

    irr::core::matrix4 transform;
    if (left)
        transform = vehicle->leftDoor->getAbsoluteTransformation();
    else
        transform = vehicle->rightDoor->getAbsoluteTransformation();

    const float x = transform[12];
    const float y = transform[13];
    irr::core::quaternion rotation(transform);
    rotation = irr::core::quaternion(0.0f, 0.0f, 3.14159265358979323846f) * rotation;
    sceneNode->setRotation(rotation);
    collisionBody->SetXForm(b2Vec2(x / 100.0f, y / 100.0f), 0.0f);
}

void Character::getInVehicle(bool left)
{
    if (!vehicle || (movementFlags & 0x10000))
        return;

    movementFlags |= 0x10000;
    removeCollisions();
    vehicle->immobilize();
    if (left) {
        positionAtDoor(true);
        if (vehicle->getDriver()) {
            movementFlags |= 0x20000;
        } else {
            setAnimation(vehicle->getLeftEnterAnimation(), vehicle->entryAnimationScale, false, true, false);
            vehicle->setDriver(this);
        }
    } else {
        positionAtDoor(false);
        setAnimation(vehicle->getRightEnterAnimation(), vehicle->entryAnimationScale, false, true, false);
        if (vehicle->getDriver())
            movementFlags |= 0x40000;
        else
            vehicle->setDriver(this);
    }
}

void Character::enterVehicle(bool left, bool getIn, bool waitForDoor)
{
    if (vehicle->isDoorClosed(left)) {
        openVehicleDoor(left);
        if (getIn)
            movementFlags |= 0x60000;
        else if (waitForDoor)
            movementFlags |= 0x100000;
    } else if (getIn) {
        getInVehicle(left);
        movementFlags |= 0x40000;
    }
}

void Character::getOutOfVehicle(bool left, bool markExit)
{
    if (!vehicle)
        return;

    if (markExit)
        unknown289 = 1;
    vehicle->showHighlight(-1);
    movementFlags |= 0x10000;
    vehicle->immobilize();
    unknown256 = 1;
    movementFlags &= ~0x400u;
    getPhysicAttributes()->SetPhysicInfo(*vehicle->getPhysicAttributes()->info, 0);
    show();
    positionInVehicle(left);
    if (left) {
        setAnimation(vehicle->getLeftExitAnimation(), vehicle->doorAnimationScale, false, true, false);
        vehicle->openDoorFromInside(true);
    } else {
        setAnimation(vehicle->getRightExitAnimation(), vehicle->doorAnimationScale, false, true, left);
        vehicle->openDoorFromInside(false);
    }
    if (vehicle->getDriver() == this)
        vehicle->setDriver(0);
}

void Character::ejectFromVehicle(bool left)
{
    if (!vehicle)
        return;

    getPhysicAttributes()->SetPhysicInfo(*vehicle->getPhysicAttributes()->info, 0);
    positionInVehicle(left);
    show();
    if (left) {
        setAnimation(vehicle->getLeftEjectAnimation(), 1.0f, false, true, false);
        vehicle->openDoor(true);
    } else {
        positionInVehicle(true);
        setAnimation(vehicle->getRightEjectAnimation(), 1.0f, false, true, left);
        vehicle->openDoor(false);
    }
    vehicle->setDriver(0);
}

void Character::openVehicleDoor(bool left)
{
    if (!vehicle)
        return;

    vehicle->immobilize();
    if (vehicle->getDriver()->isPlayer())
        Application::GetInstance()->GetControlManager()->lock();
    if (this == reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())))
        Application::GetInstance()->GetControlManager()->lock();

    if (left) {
        if (vehicle->isDoorClosed(true)) {
            positionAtDoor(true);
            setAnimation(22, 1.0f, false, false, false);
            vehicle->openDoor(true);
        }
    } else if (vehicle->isDoorClosed(false)) {
        positionAtDoor(false);
        setAnimation(23, 1.0f, false, left, left);
        vehicle->openDoor(false);
    }

    if (vehicle->getDriver()) {
        vehicle->getDriver()->positionInVehicle(true);
        vehicle->getDriver()->show();
    }
}

void Character::openVehicleDoorFromInside(bool left)
{
    positionInVehicle(left);
    show();
    if (left) {
        if (vehicle->isDoorClosed(true))
            vehicle->openDoor(true);
    } else if (vehicle->isDoorClosed(false)) {
        vehicle->openDoor(false);
    }
}

void Character::closeVehicleDoorFromInside(bool left)
{
    if (!vehicle)
        return;
    if (left) {
        if (vehicle->isDoorOpened(true)) {
            setAnimation(vehicle->getLeftCloseDoorFromInsideAnimation(), 1.0f, false, false, false);
            vehicle->closeDoor(true);
        }
    } else if (vehicle->isDoorOpened(false)) {
        setAnimation(vehicle->getRightCloseDoorFromInsideAnimation(), 1.0f, false, false, false);
        vehicle->closeDoor(false);
    }
}

void Character::startTurn(float speed)
{
    const irr::core::vector3d<float> direction = turnDirection;
    if (direction.getLengthSQ() > 0.0f) {
        turnSpeed = speed;
        turning = true;
        setAnimation(201, 1.0f, true, false, false);
    }
}

void Character::setTurnDirection(irr::core::vector3d<float> direction)
{
    turnDirection = direction;
}

void Character::CheckDestination()
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

namespace {
inline __attribute__((always_inline)) void turnSceneNode(irr::scene::ISceneNode& node, float sign, float step)
{
    const float radiansPerDegree = 0.017453292519943295f;
    node.setRotation(node.getRotation()
        * irr::core::quaternion(0.0f, 0.0f, sign * step * -radiansPerDegree));
}
}

void Character::turnToward(const irr::core::vector3d<float>& point)
{
    using irr::core::vector3d;
    using irr::core::quaternion;

    const vector3d<float> position = GetPosition();
    const float x = point.X - position.X;
    const float y = point.Y - position.Y;
    vector3d<float> direction(x, y, 0.0f);
    direction.normalize();

    quaternion rotation;
    const float dot = vector3d<float>(-direction.X, direction.Y, direction.Z)
        .dotProduct(vector3d<float>(0.0f, -1.0f, 0.0f));
    if (dot <= -1.0f)
        rotation.fromAngleAxis(3.14159265358979323846f, vector3d<float>(0.0f, 0.0f, 1.0f));
    else
        rotation.rotationFromTo(vector3d<float>(0.0f, -1.0f, 0.0f), vector3d<float>(-x, y, 0.0f));

    rotation.normalize();
    sceneNode->setRotation(rotation);
}

bool Character::turnToward(irr::core::vector3d<float> direction, float step)
{

    const float dot = GetRight().dotProduct(direction);
    const float sign = dot > 0.0f ? 1.0f : -1.0f;
    turnSceneNode(*sceneNode, sign, step);
    return GetFront().dotProduct(direction) < -0.99f;
}

namespace {
const unsigned int switchWeaponFlag = 0x400000u;
}

void Character::goFromCombatToIdle()
{
    movementFlags &= 0xf3ffffffu;
    switch (currentAnimation) {
    case 89:
        setAnimation(96, 1.0f, false, false, false);
        return;
    case 50:
        setAnimation(54, 1.0f, false, false, false);
        return;
    case 55:
        setAnimation(58, 1.0f, false, false, false);
        return;
    case 59:
        setAnimation(63, 1.0f, false, false, false);
        return;
    case 64:
        if (getWeapon()->getWeaponType() == 7)
            setAnimation(66, 1.0f, false, false, false);
        else
            setAnimation(71, 1.0f, false, false, false);
        return;
    case 73:
        setAnimation(80, 1.0f, false, false, false);
        return;
    default:
        setAnimation(getSpecificAnimation(165), 1.0f, false, false, false);
        break;
    }

    if (movementFlags & switchWeaponFlag) {
        ready(1.0f);
        movementFlags &= ~switchWeaponFlag;
    }
}

void Character::switchWeapon()
{
    if (isCurrentAnimation(89) || isCurrentAnimation(50) ||
        isCurrentAnimation(55) || isCurrentAnimation(59) ||
        isCurrentAnimation(73) || isCurrentAnimation(64) ||
        isCurrentAnimation(96) || isCurrentAnimation(54) ||
        isCurrentAnimation(58) || isCurrentAnimation(63) ||
        isCurrentAnimation(80) || isCurrentAnimation(71) ||
        isCurrentAnimation(66) || isCurrentAnimation(143) ||
        isCurrentAnimation(140) || isCurrentAnimation(141) ||
        isCurrentAnimation(142) || isCurrentAnimation(146) ||
        isCurrentAnimation(145) || isCurrentAnimation(138)) {
        movementFlags |= switchWeaponFlag;
        goFromCombatToIdle();
    } else if (!(movementFlags & 0xfeu)) {
        goToIdle();
    }
}

void Character::OnDespawn()
{
    LevelObject::OnDespawn();
    getPhysicAttributes()->ResetPhysicInfo();
    setVehicle(0);
    unknown4 &= ~2u;
    sceneNode->setVisible(false);
    shadowNode->setVisible(false);
    clean();
    if (hasSceneNodePool())
        dropSceneNode();
}

void Character::OnSpawn()
{
    if (hasSceneNodePool() && !sceneNode)
        grabSceneNode(0, 0);
    setAnimation(-1, 1.0f, false, false, false);
    unknown4 |= 2u;
    LevelObject::OnSpawn();
    sceneNode->setVisible(true);
    shadowNode->setVisible(true);
    init();
}

void BloodSplashAnimCallback(irr::scene::ITimelineController*, void* data)
{
    irr::scene::ISceneNode* node = static_cast<irr::scene::ISceneNode*>(data);
    irr::scene::ITimelineController* timeline = node->getAnimators().first->animator->getTimelineCtrl();
    timeline->jumpTo(timeline->startTime);
    timeline->setScale(0.0f);
}

void Character::showBloodPuddle(irr::core::vector3d<float>)
{
    if (b_isBloodOn) {
        if (!bloodPuddle)
            bloodPuddle = SceneNodeManager::getInstance()->grab(s_bloodpuddle, 0, 0, 0);
        GS3DStuff::SetMaterialFlag(bloodPuddle, irr::video::MaterialFlag2, true);
        GS3DStuff::SetMaterialFlag(bloodPuddle, irr::video::MaterialFlag4, true);
        GS3DStuff::SetMaterialFlag(bloodPuddle, irr::video::MaterialFlag16, true);
        sceneNode->addChild(bloodPuddle);
        bloodPuddle->setVisible(true);
        bloodPuddle->getAnimators().first->animator->getTimelineCtrl()->setLoop(false);
        bloodPuddle->setPosition(irr::core::vector3d<float>(0.0f, 0.0f, -13.0f));
    }
    shadowNode->setVisible(false);
}

void Character::hide()
{
    unknown4 &= ~2u;
    if (sceneNode) {
        sceneNode->setVisible(false);
        shadowNode->setVisible(false);
    }
    if (!isPlayer()) {
        if (Lock::getInstance()->target == this)
            Lock::getInstance()->setTarget(0);
        objectList->Remove(this);
        GameObjectManager::s_gom->Add(this, 2);
    }
}

static inline irr::core::vector3d<float> scaleVector(const irr::core::vector3d<float>& vector, const float& scale)
{
    return vector * scale;
}

void Character::initInVehicle(Vehicle* value)
{
    hide();
    setVehicle(value);
    vehicle->setDriver(this);
    movementFlags |= 0x400;
    removeCollisions();
    SetPosition(vehicle->GetPosition());

    irr::core::matrix4 transform(vehicle->sceneNode->getAbsoluteTransformation(), irr::core::matrix4::EM4CONST_COPY);
    irr::core::quaternion rotation(transform);
    rotation = irr::core::quaternion(0.0f, 0.0f, 1.57079637f) * rotation;
    sceneNode->setRotation(rotation);

    float rightOffset;
    float frontOffset;
    if (vehicle->isLowVehicle()) {
        rightOffset = 111.0f;
        frontOffset = 11.0f;
    } else {
        rightOffset = 118.0f;
        frontOffset = 21.0f;
    }
    irr::core::vector3d<float> point = vehicle->leftDoor->getAbsolutePosition()
        + scaleVector(vehicle->GetRight(), rightOffset) + scaleVector(vehicle->GetFront(), frontOffset);
    collisionBody->SetXForm(b2Vec2(point.X / 100.0f, point.Y / 100.0f), 0.0f);
    setAnimation(vehicle->getSeatedAnimation(), 1.0f, false, false, false);
}


void Character::removeCollisions()
{
    if (collisionBody) {
        for (b2Shape* shape = collisionBody->shapeList; shape; shape = shape->next) {
            if (shape->filter.maskBits) {
                shape->filter.groupIndex = 0;
                shape->filter.categoryBits = 0;
                shape->filter.maskBits = 0;
                PhysicAttributes::s_world->Refilter(shape);
            }
        }
    }
}

void Character::cleanPhysic()
{
    if (collisionBody) {
        if (collisionBody->GetUserData()) {
            delete static_cast<PhysicsBodyData*>(collisionBody->GetUserData());
            collisionBody->data = 0;
        }
        PhysicAttributes::s_world->DestroyBody(collisionBody);
        collisionBody = 0;
    }
    if (unknown24) {
        delete unknown24;
        unknown24 = 0;
    }
}

void Character::resetCollisions()
{
    if (collisionBody) {
        for (b2Shape* shape = collisionBody->shapeList; shape; shape = shape->next) {
            shape->filter.categoryBits = collisionFilter.categoryBits;
            shape->filter.maskBits = collisionFilter.maskBits;
            shape->filter.groupIndex = collisionFilter.groupIndex;
            PhysicAttributes::s_world->Refilter(shape);
        }
    }
}

void Character::showBloodSplash(irr::core::vector3d<float> position, irr::core::vector3d<float>)
{
    if (!b_isBloodOn)
        return;
    if (!m_bloodSplash) {
        m_bloodSplash = SceneNodeManager::getInstance()->grab(s_bloodsplash, 0, 0, 0);
        GS3DStuff::SetMaterialFlag(m_bloodSplash, irr::video::MaterialFlag2, false);
        GS3DStuff::SetMaterialFlag(m_bloodSplash, irr::video::MaterialFlag16, true);
        GS3DStuff::SetMaterialFlag(m_bloodSplash, irr::video::MaterialFlag128, false);
        Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(m_bloodSplash);
    }

    m_bloodSplash->setVisible(true);
    m_bloodSplash->setPosition(position);
    m_bloodSplash->updateAbsolutePosition(true);
    irr::scene::ITimelineController* timeline = m_bloodSplash->getAnimators().first->animator->getTimelineCtrl();
    if (timeline) {
        timeline->setLoop(false);
        timeline->jumpTo(timeline->startTime);
        timeline->setScale(1.0f);
        void (*callback)(irr::scene::ITimelineController*, void*) = BloodSplashAnimCallback;
        void* data = m_bloodSplash;
        timeline->callback = callback;
        timeline->callbackData = data;
    }
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_character_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_character_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_character_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_character_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_character_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_character_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_character_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_character_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_character_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_character_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN9Character20s_timelineControllerE() __attribute__((used));
static void _GLOBAL__I__ZN9Character20s_timelineControllerE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

bool Character::isFacingTarget(LevelObject* object)
{
    const float threshold = s_type[object->getObjectType()] == 3 ? 0.95f : 0.99f;
    irr::core::vector3d<float> direction = object->GetPosition() - GetPosition();
    direction.Z = 0.0f;
    direction.normalize();

    irr::core::vector3d<float> front = GetFront();
    front.Z = 0.0f;
    front.normalize();
    return front.dotProduct(direction) > threshold;
}

bool Character::turnTowardTarget(LevelObject* object, float step)
{
    using irr::core::vector3d;

    vector3d<float> direction = GetPosition() - object->GetPosition();
    direction.normalize();
    const vector3d<float> right = GetRight();
    const float dot = right.dotProduct(direction);
    const float sign = dot > 0.0f ? 1.0f : -1.0f;
    turnSceneNode(*sceneNode, sign, step);
    return dot < 0.01f && dot > -0.01f;
}

void Character::turnTowardTarget(float step)
{
    if (target && !isFacingTarget(target))
        turnTowardTarget(target, step);
}

bool Character::isTargetInRange(float range, float degrees)
{
    if (!target)
        return false;

    irr::core::vector3d<float> direction = target->GetPosition() - GetPosition();
    if (direction.getLength() <= range) {
        direction.normalize();
        const irr::core::vector3d<float> front = GetFront();
        // The retail check squares the vertical component of the target direction.
        const float dot = direction.X * front.X + direction.Y * front.Y + direction.Z * direction.Z;
        const float lower = -1.0f;
        const float upper = 1.0f;
        const float* bounded = dot < lower ? &lower : &dot;
        bounded = *bounded < upper ? bounded : &upper;
        const float degreesPerRadian = 180.0f / 3.14159265358979323846f;
        const float angle = acosf(*bounded) * degreesPerRadian;
        const float minimum = -degrees;
        if (angle < degrees) {
            bool within = false;
            if (angle > minimum)
                within = true;
            return within;
        }
    }
    return false;
}

void Character::runToLocation(const irr::core::vector3d<float>& point)
{
    if (isDead() || isDown())
        return;
    movementFlags = withMovementMode(movementFlags, 4);
    turnToward(point);
    setAnimation(getSpecificAnimation(188), 1.0f, true, true, false);
}

void Character::walkToLocation(const irr::core::vector3d<float>& point)
{
    if (isDead())
        return;
    movementFlags = withMovementMode(movementFlags, 2);
    turnToward(point);
    setAnimation(getSpecificAnimation(202), 1.0f, true, true, false);
}


void Character::switchAnimation()
{
    if (nextAnimation != -1) {
        setAnimation(nextAnimation, 1.0f, true, true, false);
        nextAnimation = -1;
    } else if (!switchMoveAnimation()) {
        switchCombatAnimation();
    }
}

void Character::updatePosition(irr::core::quaternion rotation)
{
    using irr::core::quaternion;
    using irr::core::vector3d;

    if (collisionBody) {
        const float x = 100.0f * collisionBody->GetXForm().position.x;
        const float y = 100.0f * collisionBody->GetXForm().position.y;
        LevelObject::SetPosition(vector3d<float>(x, y, GetPosition().Z));
    }

    sceneNode->setRotation(rotation);
    sceneNode->setPosition(GetPosition());

    vector3d<float> shadowPosition = GetPosition();
    shadowPosition.Z = shadowBaseHeight + 3.0f;
    shadowNode->setPosition(shadowPosition);

    PhysicAttributes* physics = getPhysicAttributes();
    const PhysicInfo* info = physics->info;
    if (info->unknown60) {
        const vector3d<float> normal = info->vector48;
        quaternion shadowRotation;
        const float dot = normal.dotProduct(vector3d<float>(0.0f, 0.0f, 1.0f));
        if (dot <= -1.0f)
            shadowRotation.fromAngleAxis(3.14159265358979323846f, vector3d<float>(0.0f, 0.0f, 1.0f));
        else
            shadowRotation.rotationFromTo(physics->info->vector48, vector3d<float>(0.0f, 0.0f, 1.0f));
        shadowNode->setRotation(shadowRotation);
    }
}

extern "C" {
extern irr::collada::CColladaFactory _ZZN12CGameFactory11getInstanceEvE2gf __attribute__((weak));
void _ZN12CGameFactoryD1Ev(irr::collada::CColladaFactory*) __attribute__((weak));
static void __tcf_1() __attribute__((used));
static void __tcf_1()
{
    _ZN12CGameFactoryD1Ev(&_ZZN12CGameFactory11getInstanceEvE2gf);
}
}

bool Character::attack()
{
    switch (getWeapon()->getWeaponType()) {
    case 0:
        if (target && (s_type[target->getObjectType()] == 5 || s_type[target->getObjectType()] == 8)
            && static_cast<Character*>(target)->isDown()
            && isTargetInRange(getWeapon()->getRange() * 2, getWeapon()->getCone()))
            return kick();
        return punch();
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        return shoot(1.0f, false);
    default: return false;
    }
}

bool Character::kick()
{
    Character* victim;
    bool kicked = isCurrentAnimation(89);
    if (kicked) {
        movementFlags |= 0x10000000u;
        setAnimation(s_fistsCombatSequence[kickIndex], 1.0f, false, false, false);
    } else if (isCurrentAnimation(getSpecificAnimation(165))) {
        movementFlags |= 0x1c000000u;
        setAnimation(s_fistsCombatSequence[5], 1.0f, false, false, false);
        kickIndex = 5;
    } else {
        goto done;
    }
    victim = static_cast<Character*>(target);
    if (!victim->isDying() && victim->currentAnimation != 164 && !victim->isDead()
        && (!victim->isDown() || (unsigned)(currentAnimation - 90) <= 1u)) {
        showBloodSplash(irr::core::vector3d<float>(target->GetPosition().X, target->GetPosition().Y, target->GetPosition().Z),
            irr::core::vector3d<float>(0.0f, 0.0f, 0.0f));
        victim->punched(currentAnimation, getWeapon()->getDamage(), this);
        nextKick();
    }
    kicked = true;
done:
    movementFlags &= ~0x20000000u;
    return kicked;
}

bool Character::punch()
{
    Character* victim;
    bool punched = isCurrentAnimation(89);
    if (punched) {
        if (punchIndex == unknown228)
            punchIndex = 1;
        movementFlags |= 0x10000000u;
        setAnimation(s_fistsCombatSequence[punchIndex], 1.0f, false, true, false);
        unknown228 = punchIndex;
    } else if (isCurrentAnimation(getSpecificAnimation(165))) {
        movementFlags |= 0x1c000000u;
        setAnimation(s_fistsCombatSequence[0], 1.0f, false, true, false);
        punchIndex = 1;
        unknown228 = 1;
    } else {
        goto done;
    }
    {
        SoundManager* sound;
        switch (lrand48() % 3) {
        case 0:
            sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(145, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            break;
        case 1:
            sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(146, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            break;
        case 2:
            sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(154, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            break;
        }
    }
    if (target) {
        if (s_type[target->getObjectType()] == 8) {
            if (!PlayerTest::GetPlayer()->unknown372)
                goto hit;
        } else if (!(static_cast<Character*>(target)->unknown4 & 4u)) {
            goto skip;
        }
        if (s_type[target->getObjectType()] == 5) {
        hit:
            if (isTargetInRange(getWeapon()->getRange(), getWeapon()->getCone())) {
                victim = static_cast<Character*>(target);
                if (!victim->isDying() && victim->currentAnimation != 164 && !victim->isDead()
                    && (!victim->isDown() || (unsigned)(currentAnimation - 90) <= 1u)) {
                    float height = unknown156 * 0.5f;
                    victim->position();
                    showBloodSplash(irr::core::vector3d<float>(target->GetPosition().X, target->GetPosition().Y,
                                        target->GetPosition().Z + height),
                        irr::core::vector3d<float>(0.0f, 0.0f, 0.0f));
                    victim->punched(currentAnimation, getWeapon()->getDamage(), this);
                    nextPunch();
                }
            }
        } else if (s_type[target->getObjectType()] == 3) {
            target->applyDamage(5, this, true);
            nextPunch();
        }
    }
skip:
    punched = true;
done:
    movementFlags &= ~0x20000000u;
    return punched;
}

Character::~Character()
{
    if (__builtin_expect(s_nodePoolID[objectType] == 255, 1) && shadowNode)
        Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->removeChild(shadowNode);
    if (bloodPuddle) {
        s_bloodpuddle = -1;
        bloodPuddle = 0;
    }
}

void Character::die(bool animate)
{
    unknown264 = 0;
    if (!isPlayer() && Lock::getInstance()->target == this)
        Lock::getInstance()->setTarget(0);
    if (animate && !isCurrentAnimation(86) && !isCurrentAnimation(162) && !isCurrentAnimation(175)
        && !isCurrentAnimation(24) && !isCurrentAnimation(25) && !isCurrentAnimation(17)
        && !isCurrentAnimation(18) && !isCurrentAnimation(19) && !isCurrentAnimation(20) && !isCurrentAnimation(21)) {
        if (__builtin_expect(!(movementFlags & 0x08000000u), 0))
            setAnimation(175, 1.0f, false, false, false);
        else
            setAnimation(86, 1.0f, false, false, false);
        movementFlags |= 0x2000u;
    } else {
        movementFlags |= 0x4000u;
    }
    showBloodPuddle(shadowNode->getAbsolutePosition());
    if (isPlayer())
        removeBloodPuddle();
    AchievementManager::s_achievementManager->recordDeath(*this);
}

void Character::goToVehicle(Vehicle* value, bool left, bool run, bool, bool)
{
    setVehicle(value);
    irr::core::vector3d<float> point;
    if (left)
        point = vehicle->leftDoor->getAbsolutePosition() + vehicle->GetRight() * 75.0f;
    else
        point = vehicle->rightDoor->getAbsolutePosition() + (-vehicle->GetRight()) * 75.0f;
    if (run)
        runToLocation(point);
    else
        walkToLocation(point);
}

Character::Character(int type)
    : LevelObject(type), facing(0.0f, 0.0f, 0.0f),
      unknown68(0.0f), unknown72(0.0f), unknown76(0.0f), destinationLimitSquared(10000),
      animationSpeedMultiplier(1), unknown156(0.0f), shadowBaseHeight(0.0f),
      unknown164Pointer(0), unknown168Pointer(0), skinMesh(0), shadowNode(0), collisionBody(0),
      vehicle(0), entryDoor(0), lastHitVehicle(0), unknown212(0), maxHealth(100), health(100),
      movementFlags(0), nextAnimation(-1), unknown248(0), unknown252(100), unknown256(false),
      target(0), unknown264(0), turnSpeed(1.0f), turning(false), unknown289(false), bloodPuddle(0)
{
    punchIndex = 0;
    unknown228 = 0;
    kickIndex = 5;
    setAnimation(-1, 1.0f, false, false, false);
}

#include "PlayerEvent.h"

#include "../core/VideoDriver.h"
void Character::debug(irr::video::IVideoDriver* driver)
{
    irr::core::vector3d<float> right = GetRight();
    irr::core::vector3d<float> front = GetFront();
    const irr::core::matrix4& transform = sceneNode->getAbsoluteTransformation();
    irr::core::vector3d<float> up(transform[8], transform[9], transform[10]);
    irr::core::vector3d<float> position = GetPosition();
    {
    irr::core::vector3d<float> scaledRight = right * 300.0f;
    irr::core::vector3d<float> end(scaledRight.X + position.X, scaledRight.Y + position.Y, position.Z);
    driver->draw3DLine(position, end, irr::video::SColor(255, 0, 0, 255));
    }
    {
    irr::core::vector3d<float> scaledFront = front * 300.0f;
    irr::core::vector3d<float> end(scaledFront.X + position.X, scaledFront.Y + position.Y, position.Z);
    driver->draw3DLine(position, end, irr::video::SColor(255, 0, 255, 0));
    }
    {
    irr::core::vector3d<float> scaledUp = up * 300.0f;
    irr::core::vector3d<float> end(scaledUp.X + position.X, scaledUp.Y + position.Y, scaledUp.Z + position.Z);
    driver->draw3DLine(position, end, irr::video::SColor(255, 255, 0, 0));
    }
}

void Character::hijacked()
{
    movementFlags &= ~0x10400u;
    setAnimation(164, 1.0f, false, false, false);
    irr::core::quaternion rotation;
    irr::core::vector3d<float> forward(0.0f, 0.0f, 1.0f);
    const irr::core::matrix4& transform = sceneNode->getAbsoluteTransformation();
    rotation.rotationFromTo(forward, irr::core::vector3d<float>(transform[8], transform[9], transform[10]));
    SetRotation(rotation * GetRotation());
    if (vehicle) {
        getPhysicAttributes()->SetPhysicInfo(*vehicle->getPhysicAttributes()->info, 0);
        resetCollisions();
        SetTarget(vehicle);
        setVehicle(0);
    }
    if (!isPlayer()) {
        SoundManager* sound;
        int id;
        if (lrand48() % 2 == 1) {
            sound = SoundManager::getInstance();
            switch (driverBehavior) { case 0: id = 61; break; default: id = 90; break; }
        } else {
            sound = SoundManager::getInstance();
            switch (driverBehavior) { case 0: id = 235; break; default: id = 233; break; }
        }
        sound->unknown140 = true;
        sound->playEx(id, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        movementFlags |= 0x40000000u;
    }
}

void Character::hitByCar(int direction, float speed, LevelObject* source)
{
    if (movementFlags & 0x10000u)
        return;
    int damage = 0;
    if (speed < 50.0f) {
        if (isPlayer()) {
            speed = 1.0f;
            damage = int(float(getMaxHealth()) / 3.0f * 0.2999999821186065673828125f);
        } else {
            speed = 1.0f;
            damage = int(float(getMaxHealth()) * 0.2999999821186065673828125f);
        }
    }
    if (speed >= 50.0f) {
        if (isPlayer())
            damage = int(float(getMaxHealth()) / 3.0f);
        else
            damage = int(float(getMaxHealth()));
        speed = 2.0f;
    }
    applyDamage(damage, source, true);
    switch (direction) {
    case 0: case 1: setAnimation(19, speed, false, true, false); break;
    case 2: setAnimation(18, speed, false, true, false); break;
    case 3: setAnimation(17, speed, false, true, false); break;
    case 6: case 7: setAnimation(20, speed, false, true, false); break;
    case 4: case 5: setAnimation(21, speed, false, true, false); break;
    }
    if (isPlayer()) {
        PlayerTest::GetPlayer()->unknown384[0] = 1;
        if (lrand48() % 100 < 50) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(151, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        } else {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(129, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        }
    } else {
        if (health <= 0)
            die(false);
        static_cast<NPC*>(this)->setHitByCar(true);
    }
}

#include "../core/Collada.h"
static const char characterAnimationResource[] = "./anim_ingame.bdae";
static const char characterShadowNodeName[] = "shadow-node";
void Character::bindAnimation(const char* rootName, AnimationInfo& info, irr::scene::ISceneNode* node)
{
    if (!node) node = sceneNode;
    info.unknown0 = irr::collada::CColladaDatabase::constructAnimator(characterAnimationResource, &irr::collada::CColladaDatabase::DefaultFactory);
    if (!s_timelineController) {
        s_timelineController = info.unknown0->getTimelineCtrl();
        ++s_timelineController->references;
        s_fistsCombatSequence[0] = 144;
        s_fistsCombatSequence[1] = 94;
        s_fistsCombatSequence[2] = 92;
        s_fistsCombatSequence[3] = 93;
        s_fistsCombatSequence[4] = 95;
        s_fistsCombatSequence[5] = 90;
        s_fistsCombatSequence[6] = 91;
    }
    info.unknown0->setTimelineCtrl(0);
    info.unknown0->onBind(node);
    info.unknown0->drop();
    info.unknown4 = node->getSceneNodeFromUID(rootName);
    info.shadowNode = node->getSceneNodeFromUID(characterShadowNodeName);
    info.shadowNode->getChildren().first->value->setRenderingLayer(1);
    GS3DStuff::SetColor(info.shadowNode, irr::video::SColor(255, 0, 0, 0), GS3DStuff::Color3);
    GS3DStuff::SetColor(info.shadowNode, irr::video::SColor(255, 255, 255, 255), GS3DStuff::Color0);
    GS3DStuff::SetColor(info.shadowNode, irr::video::SColor(255, 255, 255, 255), GS3DStuff::Color1);
    GS3DStuff::SetColor(info.shadowNode, irr::video::SColor(255, 255, 255, 255), GS3DStuff::Color2);
    GS3DStuff::SetMaterialFlag(info.shadowNode, irr::video::MaterialFlag1024, false);
    GS3DStuff::SetMaterialFlag(info.shadowNode, irr::video::MaterialFlag512, false);
    GS3DStuff::SetMaterialFlag(info.shadowNode, irr::video::MaterialFlag4, true);
    GS3DStuff::SetMaterialFlag(info.shadowNode, irr::video::MaterialFlag16, true);
    Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(info.shadowNode);
    info.skinMesh = GS3DStuff::FindAMesh(node);
}

void Character::Update(int elapsed)
{
    LevelObject::Update(elapsed);
    if (unknown24->info->unknown0 == PhysicAttributes::MATERIAL_TYPE_DEATH_WATER)
        health = 0;
    if (movementFlags & 0x4000u) goto pursue;
    if (movementFlags & 0x2000u) goto pursue;
    if (health <= 0) die(true);
pursue:
    if (unknown264) {
        if (isDead() || unknown264->isDead()) {
            unknown264 = 0;
        } else if (!vehicle) {
            if (reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())) == unknown264) {
                PlayerTest* player = PlayerTest::GetPlayer();
                if ((player->flags240 & 0x400u) && static_cast<SavePositionInterface&>(*player).getVehicle())
                    goto turningStep;
            }
            {
                const irr::core::vector3d<float> position = GetPosition();
                const float distance = position.getDistanceFromSQ(unknown264->GetPosition());
                if (distance > 90000.0f)
                    runToLocation(unknown264->GetPosition());
                else if (distance > 22500.0f)
                    walkToLocation(unknown264->GetPosition());
                else {
                    goToIdle();
                    turnToward(unknown264->GetPosition());
                }
            }
        }
    }
turningStep:
    if (turning && turnToward(turnDirection, turnSpeed)) {
        setAnimation(getSpecificAnimation(165), 1.0f, false, false, false);
        turning = false;
        turnDirection = irr::core::vector3d<float>(0.0f, 0.0f, 0.0f);
    }
    checkForWeaponReload();
    if (unknown256 && !isCurrentAnimation(15) && !isCurrentAnimation(13)
        && !isCurrentAnimation(16) && !isCurrentAnimation(14)) {
        movementFlags &= ~0x400u;
        resetCollisions();
        setVehicle(0);
        unknown256 = false;
    }
}

#include "NPCEvent.h"
#include "../core/EventManager.h"
void Character::exitVehicle(bool left)
{
    if (vehicle) {
        vehicle->flags344 &= ~0x800u;
        if (vehicle->getDriver() == this)
            vehicle->setDriver(0);
        if (vehicle->immobilized) {
            vehicle->mobilize();
            if (vehicle->getDriver()->isPlayer())
                Application::GetInstance()->GetControlManager()->unlock();
        }
    }
    movementFlags &= ~0x30400u;
    setAnimation(getSpecificAnimation(165), 1.0f, true, false, false);
    irr::core::quaternion rotation;
    irr::core::vector3d<float> forward(0.0f, 0.0f, 1.0f);
    const irr::core::matrix4& transform = sceneNode->getAbsoluteTransformation();
    rotation.rotationFromTo(forward, irr::core::vector3d<float>(transform[8], transform[9], transform[10]));
    SetRotation(rotation * GetRotation());
    positionAtDoor(left);
    resetCollisions();
    setVehicle(0);
    unknown256 = false;
    if (s_type[objectType] == 5) {
        NPC* npc = static_cast<NPC*>(this);
        if (npc->category428 == 3) {
            AIManager::getInstance()->removeAI(npc);
            AIManager::getInstance()->addAI(npc, static_cast<gameloft::ai::StateID>(8));
        } else if (unknown289) {
            AIManager::getInstance()->addAI(npc, static_cast<gameloft::ai::StateID>(8));
            if (s_type[target->getObjectType()] == 3 && static_cast<Vehicle*>(target)->getDriver())
                npc->attackTarget(static_cast<Vehicle*>(target)->getDriver());
            else
                npc->attackTarget(target);
        } else if (npc->category428 <= 2) {
            Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(1), npc));
        }
    }
}

// Existing partial Box2D SDK destructor interface reused from GS3DStuff.cpp.
#include "../vehicles/VehicleBodyShapes.h"

int Character::getSpecificAnimation(int id)
{
    switch (id) {
    case 0:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 208;
            if (getWeapon()->isTwoHanded()) return 205;
            return 0;
        case 1: return 0;
        case 2: return 0;
        }
        break;
    case 165:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 169;
            if (getWeapon()->isTwoHanded()) return 166;
            return 165;
        case 1: return 36;
        case 2: return 42;
        }
        break;
    case 179:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 170;
            if (getWeapon()->isTwoHanded()) return 167;
            return 179;
        case 1: return 179;
        case 2: return 179;
        }
        break;
    case 180:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 171;
            if (getWeapon()->isTwoHanded()) return 168;
            return 180;
        case 1: return 38;
        case 2: return 43;
        }
        break;
    case 188:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 192;
            if (getWeapon()->isTwoHanded()) return 189;
            return 188;
        case 1: return 39;
        case 2: return 44;
        }
        break;
    case 198:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 193;
            if (getWeapon()->isTwoHanded()) return 190;
            return 198;
        case 1: return 198;
        case 2: return 198;
        }
        break;
    case 200:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 194;
            if (getWeapon()->isTwoHanded()) return 191;
            return 200;
        case 1: return 200;
        case 2: return 200;
        }
        break;
    case 202:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 206;
            if (getWeapon()->isTwoHanded()) return 203;
            return 202;
        case 1: return 40;
        case 2: return 48;
        }
        break;
    case 212:
        switch (unknown212) {
        case 0:
            if (getWeapon()->getWeaponType() == 7) return 207;
            if (getWeapon()->isTwoHanded()) return 204;
            return 212;
        case 1: return 41;
        case 2: return 49;
        }
        break;
    }
    return -1;
}

extern "C" void _ZN5EvNPCD1Ev(void*) __attribute__((weak));
extern "C" void _ZN8EvPlayerD1Ev(void*) __attribute__((weak));
#include "../characters/NPCEvent.h"
#include "../core/EventManager.h"
#include "PlayerEvent.h"
inline __attribute__((always_inline)) void playPunchedSound(int id)
{
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(id, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
}
void Character::punched(int animation, int damage, LevelObject* attacker)
{
    if (movementFlags & 0x10000u)
        return;
    applyDamage(damage, attacker, true);
    int voice = -1;
    if (!isPlayer() && lrand48() % 100 < 30) {
        switch (lrand48() % 3) {
        case 0: switch (driverBehavior) { case 0: voice = 245; break; default: voice = 242; break; } break;
        case 1: switch (driverBehavior) { case 0: voice = 231; break; default: voice = 238; break; } break;
        case 2: switch (driverBehavior) { case 0: voice = 240; break; default: voice = 237; break; } break;
        }
    }
    switch (animation) {
    case 90: case 91:
        setAnimation(162, 1.0f, false, false, false);
        if (isPlayer()) playPunchedSound(129);
        break;
    case 92:
        setAnimation(85, 1.0f, false, false, false);
        if (isPlayer()) playPunchedSound(129);
        if (voice != -1) playPunchedSound(voice);
        break;
    case 93: case 94:
        setAnimation(84, 1.0f, false, false, false);
        if (isPlayer()) playPunchedSound(151);
        if (voice != -1) playPunchedSound(voice);
        break;
    case 95:
        setAnimation(86, 1.0f, false, false, false);
        if (isPlayer()) playPunchedSound(129);
        if (voice != -1) playPunchedSound(voice);
        break;
    case 144:
        setAnimation(83, 1.0f, false, false, false);
        if (isPlayer()) playPunchedSound(151);
        if (voice != -1) playPunchedSound(voice);
        break;
    }
    switch (lrand48() % 3) {
    case 0: playPunchedSound(152); break;
    case 1: playPunchedSound(128); break;
    case 2: playPunchedSound(139); break;
    }
    if (s_type[getObjectType()] == 5) {
        EventManager* events = Application::GetInstance()->GetEventManager();
        unsigned int storage[sizeof(EvNPC) / sizeof(unsigned int)];
        EvNPC* event = new (storage) EvNPC(static_cast<EvNPC::State>(8), static_cast<NPC*>(this));
        events->raise(*event);
        _ZN5EvNPCD1Ev(event);
        if (static_cast<NPC*>(this)->category428 == 3) {
            unsigned int storage[sizeof(EvPlayer) / sizeof(unsigned int)];
            EvPlayer* event = new (storage) EvPlayer(3);
            events->raise(*event);
            _ZN8EvPlayerD1Ev(event);
        }
    }
    if (Lock::getInstance()->target == this)
        Lock::getInstance()->billboard->activateAnimation();
}
void Character::goToCombatIdle()
{
    const unsigned int combatIdleFlag = 0x04000000u;
    switch (getWeapon()->getWeaponType()) {
    case 0:
        movementFlags |= combatIdleFlag;
        setAnimation(89, 1.0f, true, false, false);
        break;
    case 1:
        movementFlags |= combatIdleFlag;
        if (s_type[getObjectType()] == 5 &&
            static_cast<NPC*>(this)->category428 == 3)
            setAnimation(55, 1.0f, true, false, false);
        else
            setAnimation(50, 1.0f, true, false, false);
        break;
    case 2:
        movementFlags |= combatIdleFlag;
        setAnimation(59, 1.0f, true, false, false);
        break;
    case 4:
        movementFlags |= combatIdleFlag;
        setAnimation(73, 1.0f, true, false, false);
        break;
    case 3:
        movementFlags |= combatIdleFlag;
        setAnimation(73, 1.0f, true, false, false);
        break;
    case 5:
        movementFlags |= combatIdleFlag;
        setAnimation(50, 1.0f, true, false, false);
        break;
    case 6:
        movementFlags |= combatIdleFlag;
        setAnimation(59, 1.0f, true, false, false);
        break;
    case 7:
        movementFlags |= combatIdleFlag;
        setAnimation(64, 1.0f, true, false, false);
        break;
    case 8:
        movementFlags |= combatIdleFlag;
        setAnimation(64, 1.0f, true, false, false);
        break;
    }
}

void Character::ready(float speed)
{
    if (!isCurrentAnimation(getSpecificAnimation(165))) return;
    switch (getWeapon()->getWeaponType()) {
    case 0:
        setAnimation(143, speed, false, false, false);
        punchIndex = 0;
        unknown228 = 0;
        kickIndex = 5;
        break;
    case 1:
        if (s_type[objectType] == 5 && static_cast<NPC*>(this)->category428 == 3)
            setAnimation(141, speed, false, false, false);
        else
            setAnimation(140, speed, false, false, false);
        break;
    case 2:
        setAnimation(142, speed, false, false, false);
        break;
    case 4:
        setAnimation(146, speed, false, false, false);
        break;
    case 3:
        setAnimation(146, speed, false, false, false);
        break;
    case 5:
        setAnimation(140, speed, false, false, false);
        break;
    case 6:
        setAnimation(142, speed, false, false, false);
        break;
    case 7:
        setAnimation(138, speed, false, false, false);
        break;
    case 8:
        setAnimation(145, speed, false, false, false);
        break;
    }
}

void Character::initPhysic()
{
    if (collisionBody) return;
    if (!unknown24) unknown24 = new PhysicAttributes(1,0);
    if (vehicle) unknown24->SetPhysicInfo(*vehicle->unknown24->info,0);
    b2BodyDef body;
    body.linearDamping = 0.0f;
    body.angularDamping = 0.0f;
    body.isBullet = false;
    body.position = b2Vec2(GetPosition().X / 100.0f, GetPosition().Y / 100.0f);
    body.allowSleep = false;
    collisionBody = PhysicAttributes::s_world->CreateBody(&body);
    b2CircleDef shape;
    shape.radius = 0.5f;
    shape.restitution = 0.0f;
    shape.density = 1.0f;
    shape.friction = 0.3f;
    if (static_cast<void*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())) == this) {
        shape.filter.categoryBits = 2;
        shape.filter.maskBits = 0xffff;
    } else {
        shape.filter.categoryBits = 4;
        shape.filter.maskBits = 0xffff;
    }
    shape.filter.groupIndex = unknown24->getIndex()+1;
    collisionFilter = shape.filter;
    collisionBody->CreateShape(&shape);
    collisionBody->SetMassFromShapes();
    collisionBody->data = new PhysicsBodyData(this,static_cast<irr::scene::ISceneNode*>(getSkinMesh()));
}



struct CharacterThrowOutView {
    unsigned char unknown0[0xbc];
    Vehicle* vehicle;
};

extern "C" {
void _ZN9Character17positionInVehicleEb(Character* self, bool left);
void _ZN9Character4showEv(Character* self);
}

static inline bool hasDriver(const Character* driver)
{
    return driver != 0;
}

extern "C" void _ZN9Character14throwOutDriverEb(Character* self, bool left)
{
    CharacterThrowOutView* view = reinterpret_cast<CharacterThrowOutView*>(self);
    if (!view->vehicle)
        return;
    Character* driver = view->vehicle->getDriver();
    if (!hasDriver(driver))
        return;

    self->getPhysicAttributes()->SetPhysicInfo(*view->vehicle->getPhysicAttributes()->info, 0);
    if (driver->isPlayer()) {
        view->vehicle->Stop();
        self->setAnimation(view->vehicle->getLeftThrowAnimation(), 1.0f, false, true, false);
        static_cast<PlayerTest*>(driver)->stopDriving(static_cast<playertest::PlayerCarState::ePlayerCarState>(14), true);
        return;
    }
    _ZN9Character17positionInVehicleEb(driver, left);
    _ZN9Character4showEv(driver);
    if (left) {
        self->setAnimation(view->vehicle->getLeftThrowAnimation(), 1.0f, false, true, false);
        driver->setAnimation(view->vehicle->getLeftThrownAnimation(), 1.0f, false, true, false);
        view->vehicle->setDriver(0);
    } else {
        _ZN9Character17positionInVehicleEb(self, false);
        _ZN9Character4showEv(self);
        view->vehicle->openDoorFromInside(true);
        driver->setAnimation(view->vehicle->getLeftEjectAnimation(), 1.0f, false, true, left);
        view->vehicle->setDriver(self);
    }
}
