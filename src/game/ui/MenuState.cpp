/*
 * MenuState
 *
 * Original file: MenuState.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MenuState.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "../core/LocalStartupText.h"
#include "../ai/StateMachine.h"
#include "MenuDialogs.h"
#include "../hud/MenuManager.h"

extern "C" {
void _ZN11MenuManager3popEb(MenuManager* manager, bool restoreFocus);
void _ZN11MenuManager10clearFocusEv(MenuManager* manager);
}

void MenuFX::State::Create()
{
}

inline MenuFX::State::State(const char* stateName)
{
    __builtin_strcpy(name, stateName);
    firstCharacter.set_ref(0);
    secondCharacter.set_ref(0);
    unknown80 = 0;
}

MenuState::MenuState(const char* name)
    : MenuFX::State(name), widgetIds(), unknown96(false), depth(0)
{
}

Menus::Dialog::Dialog(const char* name)
    : MenuState(name)
{
}

Menus::Confirm::Confirm(const char* name)
    : Dialog(name), confirmed(false)
{
    const int widgetId = 21;
    widgetIds.append(&widgetId, 1);
}

Menus::ConfirmPayment::ConfirmPayment(const char* name)
    : Confirm(name)
{
    gameswf::array<int>* ids = &widgetIds;
    int index = -1;
    for (int i = 0; i < ids->size; ++i) {
        if (ids->elements[i] == 21) {
            index = i;
            break;
        }
    }
    if (index >= 0)
        ids->remove(index);
    const int widgetId = 28;
    ids->append(&widgetId, 1);
}

void MenuFX::State::Show()
{
}

void MenuFX::State::Hide()
{
}

void MenuFX::State::GotFocus()
{
}

void MenuFX::State::LostFocus()
{
}

void MenuFX::State::Update()
{
}

void MenuFX::State::Update(int)
{
    Update();
}

void MenuFX::State::OnEvent(RenderFX::Event&)
{
}

void MenuFX::State::OnFSCommand(const char*, const char*)
{
}

bool MenuFX::State::CanHandleEvent(RenderFX::Event&)
{
    return true;
}

bool MenuState::IsModal() const
{
    return false;
}

bool Menus::Confirm::IsModal() const
{
    return true;
}

bool MenuState::Notify(const MenuWidget*, int)
{
    return false;
}

int MenuState::GetDepth() const
{
    return depth;
}

void MenuState::Update()
{
}

void MenuState::Create()
{
}

namespace {
struct MenuWidgetTable {
    unsigned char prefix[0x1a4];
    void** widgets;
    int count;
};

inline void* getWidgetByIndex(int index)
{
    const MenuWidgetTable& table =
        *reinterpret_cast<const MenuWidgetTable*>(MenuManager::getInstance());
    return index < table.count ? table.widgets[index] : 0;
}
}

bool Menus::Confirm::Confirmed() const
{
    return confirmed;
}

Widgets::ConfirmPayment* Menus::ConfirmPayment::GetWidget()
{
    return static_cast<Widgets::ConfirmPayment*>(getWidgetByIndex(28));
}

Widgets::Confirm* Menus::Confirm::GetWidget()
{
    return static_cast<Widgets::Confirm*>(getWidgetByIndex(21));
}

void Menus::Dialog::SetMessage(int id)
{
    GetWidget()->SetMessage(id);
}

bool Menus::Confirm::Notify(const MenuWidget* widget, int event)
{
    MenuState::Notify(widget, event);
    MenuManager* manager = MenuManager::getInstance();
    const MenuWidget* dialog = GetWidget();
    if (widget == dialog && event == 1) {
        confirmed = static_cast<const Widgets::Dialog*>(widget)->GetPressedButton() == 11;
        _ZN11MenuManager3popEb(manager, true);
        return true;
    }
    return false;
}

void Menus::Dialog::GotFocus()
{
    MenuState::GotFocus();
    GetWidget()->SetListener(this);
    _ZN11MenuManager10clearFocusEv(MenuManager::getInstance());
}

void Menus::Confirm::GotFocus()
{
    Dialog::GotFocus();
    confirmed = false;
}

void Menus::Dialog::LostFocus()
{
    MenuState::LostFocus();
    GetWidget()->SetListener(0);
}

void Menus::ConfirmPayment::SetPrice(int amount)
{
    Widgets::ConfirmPayment* widget =
        static_cast<Widgets::ConfirmPayment*>(getWidgetByIndex(28));
    widget->SetPrice(amount);
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_6() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_menustate_transitions {
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
static void __tcf_6()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_6), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_menustate_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_menustate_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_menustate_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_menustate_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_menustate_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_menustate_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_menustate_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_menustate_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_menustate_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_menustate_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN9MenuStateC2EPKc() __attribute__((used));
static void _GLOBAL__I__ZN9MenuStateC2EPKc()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
