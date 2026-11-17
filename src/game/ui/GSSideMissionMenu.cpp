/*
 * GSSideMissionMenu
 *
 * Original file: GSSideMissionMenu.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GSSideMissionMenu.cpp here, in the order they appear in the library.
 */

#include "GSSideMissionMenu.h"
#include "../ai/StateMachine.h"

#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
extern StateMachine _ZZN12StateMachine11getInstanceEvE2sm __attribute__((weak));
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_gssidemissionmenu_transitions {
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

void GSSideMissionMenu::draw(const StateMachine*) {}

void GSSideMissionMenu::draw2d(const StateMachine*) {}

extern "C" {
static void __tcf_3()
{
    _ZZN12StateMachine11getInstanceEvE2sm.~StateMachine();
}
}

GSSideMissionMenu::GSSideMissionMenu() : unknown4(0), unknown8(0), unknown12(0), unknown16(0), stoppedVehicle(0) {}

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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_gssidemissionmenu_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN17GSSideMissionMenuC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN17GSSideMissionMenuC2Ev()
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

GSSideMissionMenu::~GSSideMissionMenu() {}

#include "../app/Application.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../scripting/ScriptManager.h"

void GSSideMissionMenu::dtor(const StateMachine*)
{
    MenuManager::getInstance()->showTexts();
    Application::GetInstance()->GetHudManager()->show();
    ScriptManager::getInstance()->resume();
}

#include "../app/Application.h"
#include "../characters/PlayerTest.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../input/TouchScreenBase.h"
#include "../missions/SideMission.h"
#include "../missions/SideMissionManager.h"
#include "../scripting/ScriptManager.h"
#include "../vehicles/Vehicle.h"

namespace Menus { class Dialog; }
extern "C" void _ZN5Menus6Dialog10SetMessageEi(Menus::Dialog*, int);
static const char sideMissionConfirmName[] = "Confirm";

void GSSideMissionMenu::ctor(const StateMachine*)
{
    Application::GetInstance()->GetTouchScreen()->clear();
    ScriptManager::getInstance()->pause();
    Application::GetInstance()->GetHudManager()->hide();
    unknown16 = MenuManager::getInstance()->getDepth();
    MenuManager::getInstance()->hideTexts();
    Menus::Dialog* confirm = static_cast<Menus::Dialog*>(MenuManager::getInstance()->getState(sideMissionConfirmName));
    _ZN5Menus6Dialog10SetMessageEi(confirm, SideMissionManager::s_currentMission->getStartMessage());
    MenuManager::getInstance()->push(sideMissionConfirmName, false);
    stoppedVehicle = static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle();
    if (stoppedVehicle)
        stoppedVehicle->Stop();
}
