/*
 * SideMissionManager
 *
 * Original file: SideMissionManager.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SideMissionManager.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../app/Application.h"
#include "../audio/SoundManager.h"
#include "../characters/PlayerTest.h"
#include "../hud/CHudManager.h"
#include "../meta/Achievements.h"
#include "../scripting/ScriptManager.h"
#include "Mission.h"
#include "SideMissionManager.h"
#include "SideMission.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../ai/StateMachine.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_sidemissionmanager_transitions {
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
static void __tcf_4()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_sidemissionmanager_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN18SideMissionManager22s_ambulanceSideMissionE() __attribute__((used));
static void _GLOBAL__I__ZN18SideMissionManager22s_ambulanceSideMissionE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void SideMissionManager::debug()
{
}

int SideMissionManager::s_step;

void SideMissionManager::confirm()
{
    s_step = 4;
}

SideMission* SideMissionManager::s_ambulanceSideMission;
SideMission* SideMissionManager::s_deliverySideMission;
SideMission* SideMissionManager::s_taxiSideMission;
SideMission* SideMissionManager::s_currentMission;
int SideMissionManager::s_nextMissionTimer;

extern "C" long lrand48();

void SideMissionManager::setNextMissionTimer()
{
    s_nextMissionTimer = 2000 + lrand48() % 1000;
}

bool SideMissionManager::isInSideMission()
{
    return s_currentMission && s_currentMission->inProgress();
}

void SideMissionManager::update(unsigned int elapsed)
{
    switch (s_step) {
    case 0:
        initMission();
        if (s_currentMission) {
            setNextMissionTimer();
            s_step = 1;
        }
        break;
    case 1:
        s_nextMissionTimer -= elapsed;
        if (isMissionAvailable()) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(116, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            Application::GetInstance()->GetHudManager()->toggleRadioCB(true);
            s_currentMission->init();
            s_step = 2;
        }
        break;
    case 3:
        s_step = 4;
        break;
    case 4:
        s_currentMission->start();
        s_step = 5;
        break;
    case 5:
        s_currentMission->update(elapsed);
        if (!isInSideMission())
            s_step = 6;
        break;
    case 6: {
        const int reward = s_currentMission->getReward();
        PlayerTest::GetPlayer()->addCash(reward, 3000);
        AchievementManager::s_achievementManager->recordMissionCash(reward);
        if (s_currentMission->finished())
            s_step = 0;
        else {
            setNextMissionTimer();
            s_step = 3;
        }
        break;
    }
    }
}

bool SideMissionManager::isMissionAvailable()
{
    if (isInSideMission())
        return false;
    if (static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getState() == 4)
        return false;
    return s_nextMissionTimer <= 0;
}
