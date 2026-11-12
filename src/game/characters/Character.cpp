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
#include "../audio/SoundManager.h"
#include "../world/GameObjectManager.h"
#include "../vehicles/Vehicle.h"
#include "PlayerTest.h"
#include "../ai/NPC.h"
#include "PhysicAttributes.h"
#include "../core/Physics.h"
#include "../app/Application.h"
#include "../input/CControlManager.h"
#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"
#include "../rendering/GS3DStuff.h"
#include "../world/SceneNodeManager.h"

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

void Character::setAnimation(const char* name, int speed, bool a, bool b, bool c)
{
    const int id = s_timelineController->getClipIndex(name);
    setAnimation(id, static_cast<float>(speed), a, b, c);
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
        unknown289[0] = 1;
    vehicle->showHighlight(-1);
    movementFlags |= 0x10000;
    vehicle->immobilize();
    unknown248[8] = 1;
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
            shape->filter.categoryBits = collisionCategory;
            shape->filter.maskBits = collisionMask;
            shape->filter.groupIndex = collisionGroup;
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
