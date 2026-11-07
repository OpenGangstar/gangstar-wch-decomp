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

irr::scene::ITimelineController* Character::s_timelineController;

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

void Character::goToIdle()
{
    if (!isCurrentAnimation(getSpecificAnimation(165)))
        setAnimation(getSpecificAnimation(165), 1.0f, true, false, false);
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

void Character::setDestination(const irr::core::vector3d<float>& point, int limit)
{
    destination = point;
    destinationLimitSquared = limit * limit;
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
