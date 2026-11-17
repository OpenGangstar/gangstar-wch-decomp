/*
 * CopController
 *
 * Original file: CopController.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CopController.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_copcontroller_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_copcontroller_transitions::scripted_vehicle_trans, 21);
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN13CopController20s_hasAttemptedArrestE() __attribute__((used));
static void _GLOBAL__I__ZN13CopController20s_hasAttemptedArrestE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

#include "NPCController.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
class CopController : public NPCController {
public:
    CopController(NPC*, gameloft::ai::StateID);
    virtual ~CopController();
    virtual void onEvent(const IEvent*,const EventManager*);
    virtual void switchState(gameloft::ai::StateID,gameloft::ai::TransitionCondition);
    static bool s_hasAttemptedArrest;
private:
    unsigned int unknown16;
    bool unknown20;
};
CopController::~CopController()
{
    if (unknown20)
        s_hasAttemptedArrest=false;
    EventManager* events=Application::GetInstance()->GetEventManager();
    events->detach(16,this);
    events->detach(23,this);
    events->detach(24,this);
    events->detach(22,this);
}

CopController::CopController(NPC* npc,gameloft::ai::StateID initial)
    : NPCController(initial,npc,reinterpret_cast<const gameloft::ai::Transition&>(gameloft::ai::cop)), unknown16(0), unknown20(false)
{
    CopController::switchState(initial,gameloft::ai::UnknownTransitionCondition);
    EventManager* events=Application::GetInstance()->GetEventManager();
    events->attach(16,this);
    events->attach(23,this);
    events->attach(24,this);
    events->attach(22,this);
}

#include "NPC.h"
#include "../characters/PlayerTest.h"
#include "../characters/PlayerEvent.h"
#include "../vehicles/Vehicle.h"
void CopController::switchState(gameloft::ai::StateID next,gameloft::ai::TransitionCondition condition)
{
    switch (next) {
    case static_cast<gameloft::ai::StateID>(1):
        npc->goToNextPoint(false);
        break;
    case static_cast<gameloft::ai::StateID>(2):
        npc->wait(5);
        break;
    case static_cast<gameloft::ai::StateID>(6):
        npc->goToLocation(PlayerTest::GetPlayer()->position());
        break;
    case static_cast<gameloft::ai::StateID>(10):
        npc->flags356 &= ~0x40u;
        npc->runToLocation(PlayerTest::GetPlayer()->position());
        break;
    case static_cast<gameloft::ai::StateID>(8): {
        LevelObject* target=reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
        PlayerTest* player=PlayerTest::GetPlayer();
        if ((player->flags240&0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle())
            target=static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle();
        if (condition==static_cast<gameloft::ai::TransitionCondition>(21)) {
            if (npc->target==static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle())
                Application::GetInstance()->GetEventManager()->raise(EvPlayer(4));
            else {
                switchState(static_cast<gameloft::ai::StateID>(1),static_cast<gameloft::ai::TransitionCondition>(21));
                return;
            }
        }
        NPC* controlled=npc;
        controlled->SetTarget(target);
        controlled->flags356 |= 0x180u;
        if (WantedLevelManager::getInstance()->unknown8<=1)
            npc->flags356 |= 0x40000u;
        else
            npc->flags356 &= ~0x40000u;
        if (static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle()==target && !s_hasAttemptedArrest) {
            s_hasAttemptedArrest=true;
            unknown20=true;
            npc->goToVehicle(static_cast<Vehicle*>(static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle()),true,true,false,true);
        } else {
            npc->attackTarget(target);
        }
        break;
    }
    }
    state=next;
}
