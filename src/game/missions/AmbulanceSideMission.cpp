/*
 * AmbulanceSideMission
 *
 * Original file: AmbulanceSideMission.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AmbulanceSideMission.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "SideMissionTimerText.h"
#include "Checkpoint.h"
#include "../characters/PhysicAttributes.h"
#include "../ai/NPC.h"
#include "AmbulanceSideMission.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_ambulancesidemission_transitions {
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

extern "C" {
static void __tcf_3()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_ambulancesidemission_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN20AmbulanceSideMissionC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN20AmbulanceSideMissionC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void AmbulanceSideMission::end()
{
}

int AmbulanceSideMission::getMoneyReward()
{
    return 2000;
}

int AmbulanceSideMission::getGoalMessage()
{
    return 0x30ed;
}

int AmbulanceSideMission::getStartMessage()
{
    return 0x30ec;
}

int AmbulanceSideMission::getEndMessage()
{
    return 0x30f6;
}

int AmbulanceSideMission::getObj1Message()
{
    return 0x30ee;
}

int AmbulanceSideMission::getObj2Message()
{
    return 0x30ef;
}

void AmbulanceSideMission::clean()
{
    removeCheckpoint(checkpoint);
    disableCheckpoints(dropOffCheckpoints);
}

bool AmbulanceSideMission::dropOff(irr::core::vector3d<float> position)
{
    if (!isInCheckpointsRange(position, dropOffCheckpoints))
        return false;
    disableCheckpoints(dropOffCheckpoints);
    return true;
}

extern "C" int sprintf(char*, const char*, ...);
extern const char ambulanceMissionTimerFormat[] __attribute__((visibility("hidden")));

void AmbulanceSideMission::begin(irr::core::vector3d<float> position, int level,
                            int& time, float& money)
{
    difficulty = level;
    float minDistance;
    float maxDistance;
    unsigned short surface;
    getRange(minDistance, maxDistance, level, 300, 400, 600, 700);
    checkpoint = addCheckpoint(27, position, minDistance, maxDistance,
        PhysicAttributes::MATERIAL_TYPE_SIDEWALK, surface);
    addNPC(-1, -1, checkpoint->GetPosition(), PhysicAttributes::MATERIAL_TYPE_SIDEWALK, surface);
    passenger->setAnimation(163, 1.0f, true, false, false);

    const int pickupTime = calculateTime(position, checkpoint->GetPosition(), difficulty == 1 ? 150 : 80, difficulty);
    const float pickupMoney = calculateMoney(position, checkpoint->GetPosition(), 75, difficulty);
    time += pickupTime;
    money = pickupMoney;
    position.getDistanceFrom(checkpoint->GetPosition());

    char totalText[8];
    char pickupText[8];
    const int totalTime = time;
    formatSideMissionTime(totalText, ambulanceMissionTimerFormat, totalTime);
    formatSideMissionTime(pickupText, ambulanceMissionTimerFormat, pickupTime);
}

AmbulanceSideMission::AmbulanceSideMission()
{
    dropOffCheckpoints.data = 0;
    dropOffCheckpoints.allocated = 0;
    dropOffCheckpoints.used = 0;
    dropOffCheckpoints.free_when_destroyed = true;
    dropOffCheckpoints.is_sorted = true;
    dropOffCheckpoints.unknown16 = 1;
    init();
    checkpoint = 0;
    getCheckpoints(24, dropOffCheckpoints);
}

bool AmbulanceSideMission::pickUp(irr::core::vector3d<float> position, int& time, float& money, int)
{
    if (!isInCheckpointRange(position, checkpoint))
        return false;

    fadeInFadeOut();
    removeNPC();
    removeCheckpoint(checkpoint);
    Checkpoint* destination = enableCheckpoints(dropOffCheckpoints, position);
    const int dropOffTime = calculateTime(position, destination->GetPosition(), 80, difficulty);
    const float dropOffMoney = calculateMoney(position, destination->GetPosition(), 75, difficulty);
    time += dropOffTime;
    money += dropOffMoney;
    position.getDistanceFrom(destination->GetPosition());

    char totalText[8];
    char dropOffText[8];
    const int totalTime = time;
    formatSideMissionTime(totalText, ambulanceMissionTimerFormat, totalTime);
    formatSideMissionTime(dropOffText, ambulanceMissionTimerFormat, dropOffTime);
    return true;
}

AmbulanceSideMission::~AmbulanceSideMission()
{
    ::operator delete(dropOffCheckpoints.data);
    dropOffCheckpoints.data = 0;
    dropOffCheckpoints.used = 0;
    dropOffCheckpoints.allocated = 0;
    dropOffCheckpoints.is_sorted = true;
    if (dropOffCheckpoints.free_when_destroyed)
        ::operator delete(dropOffCheckpoints.data);
}
