/*
 * GSInGameMenu
 *
 * Original file: GSInGameMenu.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GSInGameMenu.cpp here, in the order they appear in the library.
 */

#include "GSInGameMenu.h"

#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_gsingamemenu_transitions {
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

void GSInGameMenu::draw(const StateMachine*) {}

extern "C" {
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

GSInGameMenu::GSInGameMenu() : unknown4(0), unknown8(0), unknown12(0), unknown16(0) {}

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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_gsingamemenu_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN12GSInGameMenu12s_skipFadeInE() __attribute__((used));
static void _GLOBAL__I__ZN12GSInGameMenu12s_skipFadeInE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

GSInGameMenu::~GSInGameMenu() {}

bool GSInGameMenu::s_skipFadeIn = false;

void GSInGameMenu::skipFadeIn()
{
    s_skipFadeIn = true;
}

#include "../app/Application.h"
#include "../core/IrrlichtDevice.h"
#include "../core/CameraManager.h"
#include "../audio/SoundManager.h"
#include "../core/VideoDriver.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../input/TouchScreenBase.h"
#include "../scripting/ScriptManager.h"

extern "C" bool _ZNK11MenuManager14isCurrentStateEPKc(const MenuManager*, const char*);

void GSInGameMenu::dtor(const StateMachine*)
{
    MenuManager* menuManager = MenuManager::getInstance();
    menuManager->showTexts();
    Application* app = Application::GetInstance();
    ScriptManager::getInstance()->resume();
    if (!_ZNK11MenuManager14isCurrentStateEPKc(menuManager, "BlockingTutorial"))
        app->GetHudManager()->unlock();
    app->GetTouchScreen()->clear();
    CameraManager::getInstance()->setTouchScreenInputs(true);
}

extern int iAdditionMenuDepth;

void GSInGameMenu::ctor(const StateMachine*)
{
    iAdditionMenuDepth = unknown16 = MenuManager::getInstance()->getDepth();
    unknown8 = unknown12 = 150;
    unknown4 = 0;
    Application* app = Application::GetInstance();
    ScriptManager::getInstance()->pause();
    MenuManager::getInstance()->hideTexts();
    SoundManager::getInstance()->pauseAllSounds();
    app->GetHudManager()->lock();
    app->GetTouchScreen()->clear();
    CameraManager::getInstance()->setTouchScreenInputs(false);
}

void GSInGameMenu::draw2d(const StateMachine*)
{
    int alpha;
    switch (unknown4) {
    case 0:
        alpha = 255 - static_cast<int>(unknown8) * 255 / static_cast<int>(unknown12);
        break;
    case 2:
        alpha = static_cast<int>(unknown8) * 255 / static_cast<int>(unknown12);
        break;
    default:
        return;
    }
    if (alpha > 0) {
        Application* app = Application::GetInstance();
        irr::video::IVideoDriver* driver = app->GetDevice()->getVideoDriver();
        int width, height;
        app->GetScreenDimensions(width, height);
        driver->draw2DRectangle(irr::video::SColor(alpha, 0, 0, 0),
            irr::core::rect<int>(0, 0, width, height));
    }
}

#include "../ai/StateMachine.h"
#include "../characters/PlayerTest.h"
extern "C" void _ZN11MenuManager13topSetVisibleEb(MenuManager*, bool);
// Retail shares the tail of a merged "LightingMap" literal for this name.
extern const char inGameMenuMapName[] __attribute__((visibility("hidden")));

void GSInGameMenu::update(StateMachine* machine)
{
    Application* app = Application::GetInstance();
    switch (static_cast<int>(unknown4)) {
    case 0:
        unknown8 = static_cast<int>(static_cast<int>(unknown8) - machine->getTimeStamp());
        if (static_cast<int>(unknown8) <= 0) {
            unknown4 = 1;
            _ZN11MenuManager13topSetVisibleEb(MenuManager::getInstance(), false);
            MenuManager::getInstance()->push(inGameMenuMapName, false);
            app->GetTouchScreen()->clear();
            app->SetDrawAll(false);
            app->GetHudManager()->hide();
            Application::GetInstance()->GetTouchScreen()->clear();
        }
        break;
    case 1:
        if (MenuManager::getInstance()->getDepth() <= static_cast<int>(unknown16)) {
            unknown4 = 2;
            app->SetDrawAll(true);
            app->GetHudManager()->show();
            unknown8 = unknown12 = 350;
            if (s_skipFadeIn) {
                unknown8 = 0;
                s_skipFadeIn = false;
            }
            _ZN11MenuManager13topSetVisibleEb(MenuManager::getInstance(), true);
        }
        break;
    case 2:
        unknown8 = static_cast<int>(static_cast<int>(unknown8) - machine->getTimeStamp());
        if (static_cast<int>(unknown8) <= 0) {
            SoundManager::getInstance()->resumeAllSounds();
            SoundManager* sound = SoundManager::getInstance();
            int ambient = PlayerTest::GetPlayer()->getAmbientSound();
            sound->unknown140 = true;
            sound->playEx(ambient, 0, true, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            Application::GetInstance()->GetTouchScreen()->clear();
            machine->popState();
        }
        break;
    }
}
