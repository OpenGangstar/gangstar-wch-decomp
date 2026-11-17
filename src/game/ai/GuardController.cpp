/*
 * GuardController
 *
 * Original file: GuardController.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GuardController.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_guardcontroller_transitions {
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

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_guardcontroller_transitions::scripted_vehicle_trans, 21);
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
static void _GLOBAL__I__ZN15GuardControllerC2EP3NPCN8gameloft2ai7StateIDE() __attribute__((used));
static void _GLOBAL__I__ZN15GuardControllerC2EP3NPCN8gameloft2ai7StateIDE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_3()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

#include "NPCController.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
class GuardController : public NPCController {
public:
    GuardController(NPC*, gameloft::ai::StateID);
    virtual ~GuardController();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void switchState(gameloft::ai::StateID, gameloft::ai::TransitionCondition);
};
GuardController::~GuardController()
{
    Application::GetInstance()->GetEventManager()->detach(16, this);
    Application::GetInstance()->GetEventManager()->detach(22, this);
}

#include "NPC.h"
GuardController::GuardController(NPC* value, gameloft::ai::StateID initial)
    : NPCController(initial, value, reinterpret_cast<const gameloft::ai::Transition&>(gameloft::ai::guard))
{
    npc->flags356 &= ~0x40000u;
    Application::GetInstance()->GetEventManager()->attach(16, this);
    Application::GetInstance()->GetEventManager()->attach(22, this);
    GuardController::switchState(static_cast<gameloft::ai::StateID>(3), static_cast<gameloft::ai::TransitionCondition>(19));
}

#include "../characters/PlayerTest.h"
#include "../combat/Weapon.h"
#include "../vehicles/Vehicle.h"
void GuardController::switchState(gameloft::ai::StateID next, gameloft::ai::TransitionCondition)
{
    switch (next) {
    case 1:
        npc->runToLocation(npc->searchOrigin);
        npc->flags356 |= 0x80000u;
        break;
    case 2:
        npc->wait(5);
        break;
    case 3: {
        npc->clearOnAlert();
        npc->goToIdle();
        PlayerTest* player = PlayerTest::GetPlayer();
        NPC* value;
        LevelObject* target;
        if ((player->flags240 & 0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle()) {
            value = npc;
            target = PlayerTest::GetPlayer()->getVehicle();
        } else {
            value = npc;
            target = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
        }
        value->SetTarget(target);
        value->flags356 |= 0x80u;
        break;
    }
    case 8:
        npc->attackTarget(npc->target);
        break;
    case 10: {
        npc->flags356 &= ~0x40u;
        if (npc->getWeapon()->getWeaponType() != 8) {
            PlayerTest* player = PlayerTest::GetPlayer();
            if ((player->flags240 & 0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle())
                npc->runToLocation(PlayerTest::GetPlayer()->getVehicle()->GetPosition());
            else
                npc->runToLocation(static_cast<SavePositionInterface&>(*PlayerTest::GetPlayer()).position());
        }
        break;
    }
    }
    state = next;
}
