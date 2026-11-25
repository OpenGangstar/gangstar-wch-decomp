/*
 * GSFailure
 *
 * Original file: GSFailure.cpp
 * Area:          app
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GSFailure.cpp here, in the order they appear in the library.
 */

#include "GSFailure.h"
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
namespace retail_gsfailure_transitions {
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

#include "Application.h"
#include "../core/VideoDriver.h"
#include "../core/IrrlichtDevice.h"
#include "../scripting/ScriptManager.h"
#include "../missions/Mission.h"
#include "../hud/MenuManager.h"
#include "../characters/AnimObject.h"
extern "C" int _ZN13ScriptManager15getFailureCauseEv();
void GSFailure::draw2d(const StateMachine*)
{
    Application* app = Application::GetInstance();
    int width, height;
    app->GetScreenDimensions(width, height);
    irr::video::IVideoDriver* driver = app->GetDevice()->getVideoDriver();
    if (_ZN13ScriptManager15getFailureCauseEv() & 6) {
        int alpha = timer > 0 ? 128 - timer * 128 / 1000 : 128;
        if (alpha > 0) {
            irr::video::SColor color(alpha, 0, 0, 0);
            if (_ZN13ScriptManager15getFailureCauseEv() & 2)
                color.r = 255;
            else
                color.b = 255;
            driver->draw2DRectangle(color, irr::core::rect<int>(0, 0, width, height));
        }
    }
    animation->Draw();
    if (animation->IsAnimOver()) {
        int text, value;
        if (_ZN13ScriptManager15getFailureCauseEv() & 4) {
            text = 0x305a;
            value = -1;
        } else if (_ZN13ScriptManager15getFailureCauseEv() & 2) {
            text = 0x305d;
            value = -1;
        } else {
            value = static_cast<Mission*>(ScriptManager::getInstance()->getMission())->failureCause();
            text = 0x304d;
        }
        MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(4), text, 0);
        MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(5), value, 0);
        if (timer < 0 && (timer & 0x200))
            MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(6), 0x5001, 0);
        else
            MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(6), -1, 0);
    }
}

extern "C" {
static void __tcf_3()
{
    _ZZN12StateMachine11getInstanceEvE2sm.~StateMachine();
}
}

GSFailure::GSFailure() : animation(0), timer(0) {}

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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_gsfailure_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN9GSFailure14s_bCutsceneDieE() __attribute__((used));
static void _GLOBAL__I__ZN9GSFailure14s_bCutsceneDieE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

GSFailure::~GSFailure() {}

#include "../characters/PlayerTest.h"
#include "Application.h"
#include "../hud/MenuManager.h"
#include "../hud/CHudManager.h"
#include "../scripting/ScriptManager.h"
#include "../input/CControlManager.h"
#include "../characters/AnimObject.h"
void GSFailure::dtor(const StateMachine*)
{
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(4),-1,0);
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(5),-1,0);
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(6),-1,0);
    delete animation;
    Application::GetInstance()->GetHudManager()->show();
    ScriptManager::getInstance()->resume();
    Application::GetInstance()->GetControlManager()->unlock();
    PlayerTest::GetPlayer()->Stop();
}


#include "Application.h"
#include "../input/TouchScreenBase.h"
#include "../hud/CHudManager.h"
#include "../scripting/ScriptManager.h"
#include "../missions/Mission.h"
#include "../characters/AnimObject.h"
#include "../core/CameraManager.h"
#include "../audio/SoundManager.h"
#include "../characters/PlayerTest.h"
void* operator new(unsigned int);
void GSFailure::ctor(const StateMachine*)
{
    Application* app = Application::GetInstance();
    app->GetTouchScreen()->clear();
    app->GetHudManager()->hide();
    ScriptManager::getInstance()->pause();
    animation = new AnimObject;
    animation->sprite = static_cast<ASprite*>(ScriptManager::getInstance()->getCinematicsHudSprite());
    animation->SetPosition(0, 0, 0);
    animation->SetAnim(4, 0);
    CameraManager::getInstance()->setTouchScreenInputs(false);
    timer = 1000;
    if (static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getState() == 5)
        ScriptManager::getInstance()->missionIdle();
    else
        ScriptManager::getInstance()->missionFail();
    SoundManager::getInstance()->beginCutscene();
    if (PlayerTest::GetPlayer()->isDead()) {
        SoundManager::getInstance()->stop(119, -1, 0);
        animation->SetAnim(4, 0);
        SoundManager::getInstance()->playPriorityAudio(18, false);
    } else if (PlayerTest::GetPlayer()->unknown424) {
        SoundManager::getInstance()->stop(119, -1, 0);
        animation->SetAnim(6, 0);
        SoundManager::getInstance()->playPriorityAudio(18, false);
    } else {
        animation->SetAnim(5, 0);
        SoundManager::getInstance()->playPriorityAudio(22, false);
    }
}

#include "Application.h"
#include "../core/CameraManager.h"
#include "../characters/AnimObject.h"
#include "../scripting/ScriptManager.h"
#include "../scripting/Script.h"
#include "../audio/SoundManager.h"
#include "../meta/Achievements.h"
#include "../hud/CHudManager.h"
#include "../hud/MiniMap.h"
#include "../world/GameObjectManager.h"
#include "../world/LevelObject.h"
void GSFailure::update(StateMachine* machine)
{
    timer-=machine->getTimeStamp();
    if (!animation->IsAnimOver())
        animation->Update(machine->getTimeStamp());
    if (timer<=0) {
        CameraManager* camera=CameraManager::getInstance();
        camera->setTouchScreenInputs(true);
        if (ScriptManager::getInstance()->checkScreenPress()) {
            SoundManager::getInstance()->endCutscene();
            if (ScriptManager::getInstance()->findScript(17)->getState()!=Script::State2) {
                if (!s_bCutsceneDie && static_cast<SavePositionInterface&>(*PlayerTest::GetPlayer()).isDead()) {
                    ScriptManager::getInstance()->findScript(91)->setState(Script::State2,static_cast<PlayerTest::eContext>(-1));
                    s_bCutsceneDie=true;
                } else if (!s_bCutsceneBusted && PlayerTest::GetPlayer()->unknown424) {
                    ScriptManager::getInstance()->findScript(90)->setState(Script::State2,static_cast<PlayerTest::eContext>(-1));
                    s_bCutsceneBusted=true;
                } else if (!s_bCutsceneMissionFailed) {
                    ScriptManager::getInstance()->findScript(92)->setState(Script::State2,static_cast<PlayerTest::eContext>(-1));
                    s_bCutsceneMissionFailed=true;
                }
            }
            if (static_cast<SavePositionInterface&>(*PlayerTest::GetPlayer()).isDead() || PlayerTest::GetPlayer()->unknown424) {
                if (PlayerTest::GetPlayer()->unknown424)
                    AchievementManager::s_achievementManager->recordNbArrests();
                AchievementManager* achievements=AchievementManager::s_achievementManager;
                if (!achievements->IsAchievementCompleted(3) || achievements->IsAchievementCompleted(4))
                    ScriptManager::getInstance()->respawnFromBustedOrDie(PlayerTest::GetPlayer()->unknown424);
                CHudManager* hud=Application::GetInstance()->GetHudManager();
                LevelObject* player=reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
                if (hud->minimap) hud->minimap->setFollowedObject(player);
                PlayerTest::GetPlayer()->Respawn();
                GameObjectManager* objects=GameObjectManager::s_gom;
                for (LevelObject* object=objects->GetFirst(0);object;) {
                    LevelObject* next=object->next;
                    if (object->unknown4&128) objects->despawn(object);
                    object=next;
                }
            }
            PlayerTest* player=PlayerTest::GetPlayer();
            if ((player->flags240&1024) && static_cast<SavePositionInterface*>(player)->getVehicle())
                camera->enterMode(2,reinterpret_cast<LevelObject*>(PlayerTest::GetPlayer()->getVehicle()),0.0f,0);
            else
                camera->enterMode(0,reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())),0.0f,0);
            StateMachine::getInstance()->popState();
        }
    }
}
