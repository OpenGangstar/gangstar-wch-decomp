/*
 * SpawnPoint
 *
 * Original file: SpawnPoint.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SpawnPoint.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_spawnpoint_transitions {
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


#include "SpawnPoint.h"

SpawnPoint::Center SpawnPoint::s_innerCenterCiv;
SpawnPoint::Center SpawnPoint::s_outterCenterCiv;
SpawnPoint::Center SpawnPoint::s_innerCenterCar;
SpawnPoint::Center SpawnPoint::s_outterCenterCar;
SpawnPoint::Center SpawnPoint::s_innerCenterParkedCar;
SpawnPoint::Center SpawnPoint::s_outterCenterParkedCar;

struct SpawnPointList {
    struct Node { Node* next; };
    Node* head;
    Node* tail;
    unsigned int count;
};

SpawnPointList SpawnPoint::s_spawnPoints;

extern "C" {
static void __tcf_6() __attribute__((used));
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::scripted_vehicle_trans, 21);
        SpawnPoint::s_innerCenterCiv.x = 0.0f;
        SpawnPoint::s_innerCenterCiv.y = 0.0f;
        SpawnPoint::s_innerCenterCiv.z = 0.0f;
        SpawnPoint::s_outterCenterCiv.x = 0.0f;
        SpawnPoint::s_outterCenterCiv.y = 0.0f;
        SpawnPoint::s_outterCenterCiv.z = 0.0f;
        SpawnPoint::s_innerCenterCar.x = 0.0f;
        SpawnPoint::s_innerCenterCar.y = 0.0f;
        SpawnPoint::s_innerCenterCar.z = 0.0f;
        SpawnPoint::s_outterCenterCar.x = 0.0f;
        SpawnPoint::s_outterCenterCar.y = 0.0f;
        SpawnPoint::s_outterCenterCar.z = 0.0f;
        SpawnPoint::s_innerCenterParkedCar.x = 0.0f;
        SpawnPoint::s_innerCenterParkedCar.y = 0.0f;
        SpawnPoint::s_innerCenterParkedCar.z = 0.0f;
        SpawnPoint::s_outterCenterParkedCar.x = 0.0f;
        SpawnPoint::s_outterCenterParkedCar.y = 0.0f;
        SpawnPoint::s_outterCenterParkedCar.z = 0.0f;
        SpawnPoint::s_spawnPoints.head = 0;
        SpawnPoint::s_spawnPoints.tail = 0;
        SpawnPoint::s_spawnPoints.count = 0;
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_6), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN10SpawnPoint16s_innerCenterCivE() __attribute__((used));
static void _GLOBAL__I__ZN10SpawnPoint16s_innerCenterCivE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_5()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

extern "C" {
static void __tcf_6()
{
    while (SpawnPoint::s_spawnPoints.head) {
        SpawnPointList::Node* node = SpawnPoint::s_spawnPoints.head;
        SpawnPointList::Node* next = node->next;
        ::operator delete(node);
        SpawnPoint::s_spawnPoints.head = next;
    }
    SpawnPoint::s_spawnPoints.tail = 0;
    SpawnPoint::s_spawnPoints.count = 0;
}
}
