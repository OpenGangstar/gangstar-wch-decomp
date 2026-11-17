/*
 * CivPassiveController
 *
 * Original file: CivPassiveController.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CivPassiveController.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_civpassivecontroller_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_civpassivecontroller_transitions::scripted_vehicle_trans, 21);
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN20CivPassiveControllerC2EP3NPCRKN8gameloft2ai10TransitionENS3_7StateIDE() __attribute__((used));
static void _GLOBAL__I__ZN20CivPassiveControllerC2EP3NPCRKN8gameloft2ai10TransitionENS3_7StateIDE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "NPCController.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
#include "CivPassiveController.h"
CivPassiveController::~CivPassiveController()
{
    Application::GetInstance()->GetEventManager()->detach(16, this);
    Application::GetInstance()->GetEventManager()->detach(22, this);
}

#include "NPC.h"
CivPassiveController::CivPassiveController(NPC* value, const gameloft::ai::Transition& rules, gameloft::ai::StateID initial)
    : NPCController(initial, value, rules)
{
    if (initial == static_cast<gameloft::ai::StateID>(1))
        npc->goToNextPoint(false);
    Application::GetInstance()->GetEventManager()->attach(16, this);
    Application::GetInstance()->GetEventManager()->attach(22, this);
}

#include "NPC.h"
#include "../characters/PhysicAttributes.h"
void CivPassiveController::switchState(gameloft::ai::StateID next, gameloft::ai::TransitionCondition condition)
{
    switch (next) {
    case 1:
        npc->goToNextPoint(condition == 21);
        break;
    case 2:
        npc->wait(2);
        break;
    case 4:
        npc->freeze();
        break;
    case 5:
        npc->flee(npc->getPhysicAttributes()->GetNextRandomPos(0, 0, npc->GetPosition()));
        break;
    }
    state = next;
}

#include "../characters/PlayerEvent.h"
#include "../characters/PlayerTest.h"
#include "../vehicles/Vehicle.h"
void CivPassiveController::onEvent(const IEvent* event, const EventManager* sender)
{
    NPCController::onEvent(event, sender);
    if (event->getEventID() == 22) {
        const EvPlayer* playerEvent = static_cast<const EvPlayer*>(event);
        switch (playerEvent->getState()) {
        case 9:
            if (state == 8) {
                LevelObject* previous = npc->target;
                if (reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())) == previous)
                    npc->SetTarget(PlayerTest::GetPlayer()->getVehicle());
            }
            break;
        case 10:
            if (state == 8 && npc->target == PlayerTest::GetPlayer()->getVehicle())
                npc->SetTarget(reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())));
            break;
        }
    }
}
