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
#include "PlayerTest.h"
#include "../ai/NPC.h"
#include "PhysicAttributes.h"
#include "../core/Physics.h"
#include "../app/Application.h"
#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"

irr::scene::ITimelineController* Character::s_timelineController;

extern "C" float acosf(float);
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

bool Character::isPlayer() const
{
    return this == reinterpret_cast<Character*>(
        static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
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
