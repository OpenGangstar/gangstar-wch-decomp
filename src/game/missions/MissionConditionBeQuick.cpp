/*
 * MissionConditionBeQuick
 *
 * Original file: MissionConditionBeQuick.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MissionConditionBeQuick.cpp here, in the order they appear in the library.
 */

#include "MissionConditionBeQuick.h"
#include "MissionTimerText.h"
#include "../scripting/ScriptManager.h"

inline __attribute__((used)) int IMissionCondition::cause() const
{
    return -1;
}

MissionConditionBeQuick::MissionConditionBeQuick(int duration)
    : duration(duration)
{
}

void MissionConditionBeQuick::draw()
{
}

inline __attribute__((used)) IMissionCondition::~IMissionCondition();

bool MissionConditionBeQuick::evaluate(int elapsed)
{
    if (duration <= 0) {
        MenuManager::getInstance()->setText(MenuManager::MissionTimerText, static_cast<const char*>(0), 0);
        return false;
    }

    if (!ScriptManager::getInstance()->isInCinematic()) {
        char text[8];
        showMissionTimer(text, duration);
        duration -= elapsed;
    } else if (MenuManager::getInstance()->getText(MenuManager::MissionTimerText)) {
        MenuManager::getInstance()->setText(MenuManager::MissionTimerText, static_cast<const char*>(0), 0);
    }
    return true;
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_missionconditionbequick_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_missionconditionbequick_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN23MissionConditionBeQuickC2Ei() __attribute__((used));
static void _GLOBAL__I__ZN23MissionConditionBeQuickC2Ei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

MissionConditionBeQuick::~MissionConditionBeQuick()
{
    MenuManager::getInstance()->setText(MenuManager::MissionTimerText, static_cast<const char*>(0), 0);
}
