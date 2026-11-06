/*
 * WantedLevelManager
 *
 * Original file: WantedLevelManager.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of WantedLevelManager.cpp here, in the order they appear in the library.
 */

#include "WantedLevelManager.h"
#include "WantedMeter.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
#include "../hud/CHudManager.h"

void WantedLevelManager::storeWantedLevel()
{
    savedLevel = unknown8;
    savedLockedLevel = lockedLevel;
    savedUnknown16 = unknown16;
    savedUnknown20 = unknown20;
}

void WantedLevelManager::lock(int level)
{
    if (level != -1)
        lockedLevel = level;
    locked = true;
}

void WantedLevelManager::unlock()
{
    locked = false;
}

void WantedLevelManager::restoreWantedLevel()
{
    unknown8 = savedLevel;
    lockedLevel = savedLockedLevel;
    unknown16 = savedUnknown16;
    unknown20 = savedUnknown20;
    Application* application = Application::GetInstance();
    unsigned int level = unknown8;
    application->GetHudManager()->wantedMeter->setWantedLevel(level);
    _processWantedLevel();
}

void WantedLevelManager::resetWantedLevel()
{
    unknown76 = false;
    unknown8 = 0;
    unknown16 = 0;
    unknown20 = 0;
    Application::GetInstance()->GetHudManager()->wantedMeter->resetTimer();
    Application* application = Application::GetInstance();
    unsigned int level = unknown8;
    application->GetHudManager()->wantedMeter->setWantedLevel(level);
    _processWantedLevel();
    lockedLevel = 0;
}

void WantedLevelManager::clean()
{
    EventManager* events = Application::GetInstance()->GetEventManager();
    events->detach(22, this);
    events->detach(16, this);
    events->detach(19, this);
}

WantedLevelManager::~WantedLevelManager()
{
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_wantedlevelmanager_transitions {
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
static void __tcf_5()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_wantedlevelmanager_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN18WantedLevelManager18s_bTutoWantedLevelE() __attribute__((used));
static void _GLOBAL__I__ZN18WantedLevelManager18s_bTutoWantedLevelE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
