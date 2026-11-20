/*
 * GSCarRepairMenu
 *
 * Original file: GSCarRepairMenu.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GSCarRepairMenu.cpp here, in the order they appear in the library.
 */

#include "GSCarRepairMenu.h"
#include "../audio/SoundManager.h"
#include "../ai/StateMachine.h"
#include "../meta/Achievements.h"
#include "../input/TouchScreenBase.h"
#include "MenuDialogs.h"
#include "../characters/PlayerTest.h"
#include "../vehicles/Vehicle.h"
#include "../app/Application.h"
#include "../hud/MenuManager.h"
#include "../hud/CHudManager.h"
#include "../scripting/ScriptManager.h"

#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"
#include "../core/VideoDriver.h"
#include "../core/IrrlichtDevice.h"

void GSCarRepairMenu::draw2d(const StateMachine*)
{
    if (unknown4 == 0)
        return;

    int alpha;
    switch (unknown4) {
    case 2:
        alpha = 255;
        goto draw;
    case 3:
        alpha = unknown12 * 255 / unknown8;
        break;
    case 1:
        alpha = 255 - unknown12 * 255 / unknown8;
        break;
    default:
        return;
    }
    if (alpha <= 0)
        return;

draw:
    Application* app = Application::GetInstance();
    irr::video::IVideoDriver* driver = app->GetDevice()->getVideoDriver();
    int width, height;
    app->GetScreenDimensions(width, height);
    driver->draw2DRectangle(irr::video::SColor(alpha, 0, 0, 0),
        irr::core::rect<int>(0, 0, width, height));
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
extern StateMachine _ZZN12StateMachine11getInstanceEvE2sm __attribute__((weak));
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_gscarrepairmenu_transitions {
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

void GSCarRepairMenu::draw(const StateMachine*) {}

extern "C" {
static void __tcf_3()
{
    _ZZN12StateMachine11getInstanceEvE2sm.~StateMachine();
}
}

void GSCarRepairMenu::dtor(const StateMachine*)
{
    MenuManager::getInstance()->showTexts();
    Application::GetInstance()->GetHudManager()->show();
    ScriptManager::getInstance()->resume();
}

void GSCarRepairMenu::ctor(const StateMachine*)
{
    Application::GetInstance()->GetTouchScreen()->clear();
    ScriptManager::getInstance()->pause();
    Application::GetInstance()->GetHudManager()->hide();
    unknown16 = MenuManager::getInstance()->getDepth();
    MenuManager::getInstance()->hideTexts();
    Menus::ConfirmPayment* dialog = static_cast<Menus::ConfirmPayment*>(MenuManager::getInstance()->getState("CarRepair"));
    dialog->SetMessage(0x302b);
    dialog->SetPrice(MenuManager::getInstance()->getRepairCost());
    MenuManager::getInstance()->push("CarRepair", false);
    unknown20 = static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle();
    if (unknown20) unknown20->Stop();
}

GSCarRepairMenu::GSCarRepairMenu() : unknown4(0), unknown8(0), unknown12(0), unknown16(0), unknown20(0) {}

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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_gscarrepairmenu_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN15GSCarRepairMenuC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN15GSCarRepairMenuC2Ev()
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

void GSCarRepairMenu::update(StateMachine* machine)
{
    if (unknown16 < MenuManager::getInstance()->getDepth()) return;
    unknown12 -= machine->getTimeStamp();
    switch (unknown4) {
    case 0: {
        bool confirmed = static_cast<Menus::Confirm*>(MenuManager::getInstance()->getState("CarRepair"))->Confirmed();
        if (!confirmed || !unknown20) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(219, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            StateMachine::getInstance()->popState();
            break;
        }
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(214, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        PlayerTest* player = PlayerTest::GetPlayer();
        player->subCash(MenuManager::getInstance()->getRepairCost());
        AchievementManager* achievements = AchievementManager::s_achievementManager;
        achievements->recordRepair(MenuManager::getInstance()->getRepairCost());
        unknown4 = 1;
        unknown12 = 250;
        unknown8 = 250;

        break;
    }
    case 1:
        if (unknown12 < 0) {
            unknown4 = 2;
            unknown12 = 1000;
            unknown8 = 1000;
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(212, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            unknown20->repair();
        }
        break;
    case 2:
        if (unknown12 < 0) {
            unknown4 = 3;
            unknown12 = 250;
            unknown8 = 250;
        }
        break;
    case 3:
        if (unknown12 < 0) StateMachine::getInstance()->popState();
        break;
    }
}

GSCarRepairMenu::~GSCarRepairMenu() {}
