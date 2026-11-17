/*
 * Revive
 *
 * Original file: Revive.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Revive.cpp here, in the order they appear in the library.
 */

#include "Revive.h"
#include "WantedLevelManagerSingleton.h"
#include "../characters/AnimObject.h"
#include "WantedLevelManager.h"
#include "../app/Application.h"
#include "../characters/PlayerTest.h"
#include "../hud/CHudManager.h"
#include "../ui/Cash.h"
#include "../combat/WeaponManager.h"
#include "../scripting/ScriptManager.h"
#include "../scripting/Script.h"
#include "../ui/GSBustedMenu.h"
#include "../ui/Message.h"

void Revive::finishCashLostAnims()
{
    cashAnimationTime = 0;
}

void Revive::draw2d()
{
    if (__builtin_expect(state != 3, 0))
        return;
    cashLost->Draw();
    cashRemaining->Draw();
    cash->draw2d();
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
namespace retail_revive_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_revive_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_revive_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_revive_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_revive_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_revive_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_revive_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_revive_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_revive_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_revive_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_revive_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN6ReviveC2Eb() __attribute__((used));
static void _GLOBAL__I__ZN6ReviveC2Eb()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

Revive::~Revive()
{
    delete cashLost;
    delete cashRemaining;
    delete cash;
}


Revive::Revive(bool busted)
    : busted(busted), cashAnimationTime(0)
{
    ASprite* sprite = Application::GetInstance()->GetHudManager()->reviveSprite;
    cashLost = new AnimObject;
    cashLost->sprite = sprite;
    cashRemaining = new AnimObject;
    cashRemaining->sprite = sprite;
    unknown12 = 0;
    cash = new Cash(sprite, 75, 74, 85, 85, 73);

    int penalty = 200;
    if (this->busted)
        penalty = (WantedLevelManager::getInstance()->unknown8 + 1) * 50;
    if (penalty > PlayerTest::GetPlayer()->cash)
        penalty = PlayerTest::GetPlayer()->cash;
    cash->SetCash(penalty);
    cash->AlignLeft();
    cash->SetPosition(8, 152);
    PlayerTest::GetPlayer()->subCash(penalty);
    state = 2;
}

template<> GSBustedMenu* StateMachine::pushState<GSBustedMenu>() __attribute__((weak));

bool Revive::update(int elapsed)
{
    if (cashAnimationTime > 0)
        cashAnimationTime -= elapsed;

    switch (state) {
    case 0:
        state = 2;
        return false;
    case 2: {
        ScriptManager* scripts = ScriptManager::getInstance();
        if (scripts->isSkipButtonVisible())
            scripts->hideSkipButton();
        if (scripts->findScript(17)->getState() == Script::State2) {
            state = 4;
            return false;
        }

        if (busted) {
            if (scripts->findScript(90)->getState() == Script::State2)
                return false;
            PlayerTest::GetPlayer()->lockSwitchWeapon();
        } else {
            Script* deathScript = scripts->findScript(91);
            Application::GetInstance()->GetWeaponManager()->lockAllWeapons();
            Application::GetInstance()->GetHudManager()->switchWeapon();
            PlayerTest::GetPlayer()->setContextArmor(0);
            if (deathScript->getState() == Script::State2)
                return false;
        }

        cashLost->SetAnim(12);
        cashRemaining->SetAnim(13);
        state = 3;
        return false;
    }
    case 3: {
        const int remaining = cash->GetCash();
        if (cashLost->animation == 12 && !cashLost->IsAnimOver()) {
            if (cashRemaining->animation == 13 && !cashRemaining->IsAnimOver())
                cashRemaining->Update(elapsed);
            cashLost->Update(elapsed);
            if (cashLost->IsAnimOver()) {
                const int text = busted ? 0x305e : 0x305b;
                cashAnimationTime = 2000;
                static_cast<Message*>(Application::GetInstance()->GetHudManager()->message172)
                    ->setMessage(text, cashAnimationTime, static_cast<MenuManager::eText>(9));
                cash->show();
            }
        } else if (cashLost->animation == 14 && !cashLost->IsAnimOver()) {
            cashLost->Update(elapsed);
            if (cashLost->IsAnimOver())
                goto finish;
        } else if (cashAnimationTime <= 0) {
            MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(9),
                static_cast<const char*>(0), 0);
            cashLost->SetAnim(14);
        }
        if (remaining != 0)
            return false;
finish:
        PlayerTest::GetPlayer()->unlockSwitchWeapon();
        if (busted && Application::GetInstance()->GetWeaponManager()->getKeepWeaponsWhenBustedCost() > 0) {
            const int cost = Application::GetInstance()->GetWeaponManager()->getKeepWeaponsWhenBustedCost();
            PlayerTest* player = PlayerTest::GetPlayer();
            if (player->isRichAsCroesus() || player->cash >= cost) {
                StateMachine::getInstance()->pushState<GSBustedMenu>();
                return true;
            }
        }
        break;
    }
    case 4:
        PlayerTest::GetPlayer()->setCash(0);
        break;
    default:
        return false;
    }

    Application::GetInstance()->GetWeaponManager()->lockAllWeapons();
    PlayerTest::GetPlayer()->setContextArmor(0);
    return true;
}
