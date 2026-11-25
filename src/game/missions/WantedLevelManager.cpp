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
#include "WantedLevelEvents.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
#include "../core/GameEventMethods.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../meta/Achievements.h"
#include "../scripting/ScriptManager.h"
#include "../ai/NPC.h"
#include "../characters/NPCEvent.h"
#include "../characters/NPCVehicleEvent.h"
#include "../characters/PlayerEvent.h"
#include "../characters/PlayerTest.h"
#include "../core/NativeStdio.h"

class EvWantedEscaped : public IEvent {
public:
    EvWantedEscaped() { eventID = 24; }
    virtual ~EvWantedEscaped() __attribute__((used)) {}
};

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
#include "../ai/StateMachine.h"

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

class GSBlockingTutorial;
template<> GSBlockingTutorial* StateMachine::pushState<GSBlockingTutorial>() __attribute__((weak));

void WantedLevelManager::_processWantedLevel()
{
    if (locked) {
        unknown8 = lockedLevel;
        return;
    }
    if (unknown8 == lockedLevel)
        return;
    if (unknown8 > lockedLevel && !s_bTutoWantedLevel &&
        !ScriptManager::getInstance()->isInCinematic() && ScriptManager::getInstance()->unknown78) {
        s_bTutoWantedLevel = true;
        MenuManager::getInstance()->setTutorialIds(0x3080, 0x3081);
        StateMachine::getInstance()->pushState<GSBlockingTutorial>();
    }

    Application* application = Application::GetInstance();
    if (unknown8 > lockedLevel)
        unknown76 = true;
    application->GetHudManager()->wantedMeter->setWantedLevel(unknown8);
    if (unknown8 == 0) {
        application->GetEventManager()->raise(EvWantedEscaped());
        unknown20 = 0;
        unknown16 = 0;
    } else {
        application->GetEventManager()->raise(EvWantedLevelChanged());
        switch (unknown8) {
        case 1: unknown16 = 0; unknown20 = 0; break;
        case 2: unknown16 = 3; unknown20 = 1; break;
        case 3: unknown16 = 8; unknown20 = 3; break;
        case 4: unknown16 = 14; unknown20 = 6; break;
        case 5: unknown16 = 20; unknown20 = 10; break;
        }
    }
    AchievementManager::s_achievementManager->recordWantedLevel(unknown8);
}

static const char footArrived[] = "%i cops: +1 foot cop\n";
static const char footRemoved[] = "%i cops: -1 foot cop\n";
static const char carArrived[] = "%i cops: +1 cop car\n";
static const char carRemoved[] = "%i cops: -1 cop car\n";
void WantedLevelManager::onEvent(const IEvent* event, const EventManager*)
{
    lockedLevel = unknown8;
    switch (event->getEventID()) {
    case 16: {
        const EvNPC* npcEvent = static_cast<const EvNPC*>(event);
        if (npcEvent->getNPC()->category428 != 3)
            return;
        if (npcEvent->getState() == 18) {
            printf(footArrived, ++unknown72);
            unknown76 = true;
        } else if (npcEvent->getState() == 19)
            printf(footRemoved, --unknown72);
        break;
    }
    case 19: {
        const EvNPCVehicle* vehicleEvent = static_cast<const EvNPCVehicle*>(event);
        switch (vehicleEvent->getType()) {
        case 18:
            printf(carArrived, ++unknown72);
            unknown76 = true;
            break;
        case 19:
            printf(carRemoved, --unknown72);
            break;
        }
        break;
    }
    case 22:
        unknown56 = 0.0;
        switch (static_cast<const EvPlayer*>(event)->getState()) {
        case 0:
            ++unknown16;
            break;
        case 3:
        case 4:
        case 5:
            if (unknown8 <= 0)
                unknown8 = 1;
            break;
        case 7:
            ++unknown20;
            // fall through
        case 6:
        case 8:
            if (unknown8 <= 1)
                unknown8 = 2;
            break;
        }
        break;
    }

    if (PlayerTest::GetPlayer()->contextWord == 1)
        unknown8 = 0;
    else if (unknown16 > 2 && unknown8 <= 0)
        unknown8 = 1;
    else if (unknown16 > 2 && unknown8 < 2)
        unknown8 = 2;
    else if ((unknown16 > 7 || unknown20 > 2) && unknown8 <= 2)
        unknown8 = 3;
    else if ((unknown16 > 13 || unknown20 > 5) && unknown8 <= 3)
        unknown8 = 4;
    else if ((unknown16 > 19 || unknown20 > 9) && unknown8 <= 4)
        unknown8 = 5;
    _processWantedLevel();
}
