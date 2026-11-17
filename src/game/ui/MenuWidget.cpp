/*
 * MenuWidget
 *
 * Original file: MenuWidget.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MenuWidget.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/NativeStdio.h"
#include "../app/Application.h"
#include "WidgetDialog.h"
#include "MenuState.h"
#include "../rendering/CharacterVisibility.h"
#include "../hud/MenuManager.h"

extern "C" {
void _ZN11MenuManager10clearFocusEv(MenuManager* manager);
void _ZN11MenuManager13setMenuFXTextEPKcS1_bb(MenuManager* manager, const char* name, const char* text, bool first, bool second);
const char* _ZNK13StringManager9getStringEi(const StringManager* strings, int id);
void _ZN8RenderFX7SetTextEPKcS1_b(RenderFX* fx, const char* name, const char* text, bool option);
}

void MenuWidget::SetListener(MenuState* state)
{
    if (listener && listener != state)
        listener->Notify(this, 0);
    listener = state;
}

namespace {
struct MenuRenderFXStorage {
    unsigned char prefix[0xbc];
    RenderFX* renderFX;
};

inline RenderFX* getWidgetRenderFX()
{
    return reinterpret_cast<const MenuRenderFXStorage*>(MenuManager::getInstance())->renderFX;
}

}

MenuWidget::MenuWidget(const char* name)
    : character(0), renderFX(getWidgetRenderFX()), listener(0), visible(false), enabled(true)
{
    character = getWidgetRenderFX()->Find(name);
    if (character)
        setCharacterVisible(character, visible);
}

MenuWidget::~MenuWidget()
{
}

bool MenuWidget::IsVisible() const
{
    return visible;
}

bool MenuWidget::AutoHide() const
{
    return true;
}

bool MenuWidget::IsEnabled() const
{
    return enabled;
}

void MenuWidget::OnEvent(RenderFX::Event&)
{
}

void MenuWidget::UpdateLocalization()
{
}

static const char widgetHideAnimation[] = "hide";
static const char widgetShowAnimation[] = "show";

void MenuWidget::Hide(bool animate)
{
    visible = false;
    if (!animate || !renderFX->PlayAnim(character, widgetHideAnimation, 0))
        setCharacterVisible(character, visible);
}

void MenuWidget::Show()
{
    visible = true;
    setCharacterVisible(character, true);
    renderFX->PlayAnim(character, widgetShowAnimation, 0);
}

static const char widgetButtonPrefix[] = "btn";

void MenuWidget::Enable()
{
    const gameswf::array<gameswf::character*>& buttons =
        renderFX->FindCharacters(character, widgetButtonPrefix, 1);
    for (int i = 0; i < buttons.size; ++i)
        renderFX->SetEnabled(buttons.elements[i], true);
    enabled = true;
}

void MenuWidget::Disable()
{
    const gameswf::array<gameswf::character*>& buttons =
        renderFX->FindCharacters(character, widgetButtonPrefix, 2);
    for (int i = 0; i < buttons.size; ++i) {
        if (isCharacterVisible(buttons.elements[i]))
            renderFX->SetEnabled(buttons.elements[i], false);
    }
    enabled = false;
}

void Widgets::ConfirmPayment::SetPrice(int amount)
{
    price = amount;
}

void Widgets::Dialog::SetMessage(int id)
{
    messageId = id;
}

int Widgets::Dialog::GetPressedButton() const
{
    return pressedButton;
}

void Widgets::Dialog::Show()
{
    MenuWidget::Show();
    pressedButton = -1;
}

Widgets::Dialog::Dialog(const char* name)
    : MenuWidget(name)
{
}

Widgets::Confirm::Confirm(const char* name)
    : Dialog(name)
{
}

static const char confirmWidgetName[] = "widgetConfirm";

Widgets::ConfirmPayment::ConfirmPayment()
    : Confirm(confirmWidgetName), price(0)
{
}

class Script;

namespace Widgets {
struct MenuButtonInfo {
    int textId;
    bool enabled;
};

class IGMenu : public MenuWidget {
public:
    enum eButton { Invalid = -1, First, Second, Third, Fourth, Fifth };
    IGMenu();
    virtual void Show();
    virtual void Disable();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
    virtual ~IGMenu();
    void HideButtons();
    void ShowButtons();
    void SetButtonInfo(eButton button, int id, bool enabled);
    void SetActiveButton(eButton button, bool refresh);
    void SetTitleText(int id);
    void SetBackButtonText(int id);

private:
    template <bool show>
    void SetButtonsVisible();

    MenuButtonInfo buttons[5];
    int titleTextId;
    int backButtonTextId;
    int activeButton;
};

class MainMenu : public MenuWidget {
public:
    enum eButton { First, Second, Third, Fourth, None };
    MainMenu();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
    void SetButtonInfo(eButton button, int id, bool enabled, bool show);
    int GetPressedButton() const;

private:
    MenuButtonInfo buttons[4];
    int pressedButton;
};

class Volumes : public MenuWidget {
public:
    void SetPlaylist(int playlist);

private:
    static int s_playlist;
};

class Corruption : public MenuWidget {
public:
    void SetWantedLevel(int level);

private:
    int wantedLevel;
};

class Mission : public MenuWidget {
public:
    Mission();
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
    void SetScript(const Script* value);

private:
    const Script* script;
};

class Money : public MenuWidget {
public:
    Money();
    virtual void Show();
    virtual void UpdateLocalization();
};

class Arrows : public MenuWidget {
public:
    Arrows();
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
    int GetCurrentPage() const;
    void SetPageCount(int count, int page, bool reset);

private:
    int pageCount;
    int currentPage;
};

class ContentBox : public MenuWidget {
public:
    ContentBox();
    virtual void Show();
};

class Title : public MenuWidget {
public:
    Title();
    virtual void Show();
    virtual void UpdateLocalization();
    void SetTextId(int id);
    void SetIcon(const char* icon);

private:
    int textId;
};

class BackgroundInGame : public MenuWidget {
public:
    BackgroundInGame();
    virtual void Show();
};
}

void Widgets::IGMenu::SetTitleText(int id)
{
    titleTextId = id;
}

void Widgets::IGMenu::SetBackButtonText(int id)
{
    backButtonTextId = id;
}

static const char igMenuButtonFormat[] = "widgetIGMenu.groupBoutons.btnMenu%d";
static const char igMenuBackText[] = "widgetIGMenu.btnBack.text";
static const char igMenuTitleText[] = "widgetIGMenu.txtTitle.text";
static const char igMenuButtonTextFormat[] = "widgetIGMenu.groupBoutons.btnMenu%d.text";
extern const char activateAnimation[] __attribute__((visibility("hidden")));
extern const char disabledAnimation[] __attribute__((visibility("hidden")));
static const char igMenuSelected[] = "selected";
static const char widgetIGMenuName[] = "widgetIGMenu";

Widgets::IGMenu::IGMenu()
    : MenuWidget(widgetIGMenuName), titleTextId(-1), backButtonTextId(-1), activeButton(5)
{
    for (int i = 0; i < 5; ++i) {
        buttons[i].textId = -1;
        buttons[i].enabled = true;
    }
}

Widgets::IGMenu::~IGMenu()
{
}

void Widgets::IGMenu::Show()
{
    MenuWidget::Show();
    ShowButtons();
}

void Widgets::IGMenu::Disable()
{
    MenuWidget::Disable();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    MenuManager* manager = MenuManager::getInstance();
    const char* text = _ZNK13StringManager9getStringEi(strings, backButtonTextId);
    _ZN11MenuManager13setMenuFXTextEPKcS1_bb(manager, igMenuBackText, text, true, false);
}

void Widgets::IGMenu::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    MenuManager* manager = MenuManager::getInstance();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    const char* title = titleTextId == -1
        ? localStartupEmptyText : _ZNK13StringManager9getStringEi(strings, titleTextId);
    _ZN11MenuManager13setMenuFXTextEPKcS1_bb(manager, igMenuTitleText, title, true, false);

    char name[128];
    for (int i = 0; i < 5; ++i) {
        if (buttons[i].textId != -1) {
            sprintf(name, igMenuButtonTextFormat, i);
            const char* text = _ZNK13StringManager9getStringEi(strings, buttons[i].textId);
            _ZN11MenuManager13setMenuFXTextEPKcS1_bb(manager, name, text, true, false);
        }
    }
    const char* backText = _ZNK13StringManager9getStringEi(strings, backButtonTextId);
    _ZN11MenuManager13setMenuFXTextEPKcS1_bb(manager, igMenuBackText, backText, true, false);
    _ZN11MenuManager10clearFocusEv(manager);
}

void Widgets::IGMenu::SetActiveButton(eButton button, bool refresh)
{
    char name[128];
    if (!refresh && activeButton == button)
        return;
    if (activeButton < 5) {
        sprintf(name, igMenuButtonFormat, activeButton);
        renderFX->GotoFrame(name, buttons[activeButton].enabled ? activateAnimation : disabledAnimation, false);
    }
    activeButton = button;
    if (button <= Fifth) {
        sprintf(name, igMenuButtonFormat, button);
        renderFX->SetFocus(name, 0);
        renderFX->GotoFrame(name, igMenuSelected, false);
    }
}

template <bool show>
inline __attribute__((always_inline)) void Widgets::IGMenu::SetButtonsVisible()
{
    char name[64];
    for (int button = 0; button < 5; ++button) {
        sprintf(name, igMenuButtonFormat, button);
        renderFX->SetVisible(name, show);
    }
}

void Widgets::IGMenu::HideButtons()
{
    SetButtonsVisible<false>();
}

void Widgets::IGMenu::ShowButtons()
{
    SetButtonsVisible<true>();
}

void Widgets::IGMenu::SetButtonInfo(eButton button, int id, bool enabled)
{
    buttons[button].textId = id;
    buttons[button].enabled = enabled;
    char name[64];
    sprintf(name, igMenuButtonFormat, button);
    renderFX->SetEnabled(name, enabled);
}

static const char mainMenuButtonFormat[] = "widgetMainMenu.btnMain%d";
static const char widgetMainMenuName[] = "widgetMainMenu";
static const char widgetMainMenuTwitterName[] = "widgetMainMenu.btnTwitter";
static const char widgetMainMenuDoubleOptionName[] = "widgetMainMenu.DoubleOption";

int Widgets::MainMenu::GetPressedButton() const
{
    return pressedButton;
}

void Widgets::MainMenu::SetButtonInfo(eButton button, int id, bool enabled, bool show)
{
    buttons[button].textId = id;
    buttons[button].enabled = enabled;
    char name[64];
    sprintf(name, mainMenuButtonFormat, button);
    renderFX->SetEnabled(name, enabled);
    renderFX->SetVisible(name, show);
}

Widgets::MainMenu::MainMenu()
    : MenuWidget(widgetMainMenuName), pressedButton(None)
{
    for (int i = 0; i < 4; ++i) {
        buttons[i].textId = -1;
        buttons[i].enabled = true;
    }
    renderFX->SetVisible(widgetMainMenuTwitterName, false);
    renderFX->SetVisible(widgetMainMenuDoubleOptionName, false);
}

static const char mainMenuButtonTextFormat[] = "widgetMainMenu.btnMain%d.text";
static const char mainMenuMoreText[] = "widgetMainMenu.btnMore.text";
static const char mainMenuTwitterText[] = "widgetMainMenu.btnTwitter.text";

void Widgets::MainMenu::UpdateLocalization()
{
    char name[64];
    StringManager* strings = Application::GetInstance()->GetStringManager();
    for (int i = 0; i < 4; ++i) {
        if (buttons[i].textId != -1) {
            sprintf(name, mainMenuButtonTextFormat, i);
            _ZN8RenderFX7SetTextEPKcS1_b(renderFX, name, _ZNK13StringManager9getStringEi(strings, buttons[i].textId), true);
        }
    }
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, mainMenuMoreText, _ZNK13StringManager9getStringEi(strings, 0x1010), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, mainMenuTwitterText, _ZNK13StringManager9getStringEi(strings, 0x1080), false);
}

int Widgets::Volumes::s_playlist = -2;

void Widgets::Volumes::SetPlaylist(int playlist)
{
    s_playlist = playlist;
}

void Widgets::Corruption::SetWantedLevel(int level)
{
    wantedLevel = level;
}

static const char widgetMissionName[] = "widgetMission";

Widgets::Mission::Mission()
    : MenuWidget(widgetMissionName), script(0)
{
}

static const char widgetMoneyName[] = "widgetMoney";

Widgets::Money::Money()
    : MenuWidget(widgetMoneyName)
{
}

static const char widgetArrowsName[] = "widgetArrows";

Widgets::Arrows::Arrows()
    : MenuWidget(widgetArrowsName), pageCount(0), currentPage(0)
{
}

static const char widgetContentBoxName[] = "widgetContentBox";

Widgets::ContentBox::ContentBox()
    : MenuWidget(widgetContentBoxName)
{
}

static const char widgetTitleName[] = "widgetTitle";

Widgets::Title::Title()
    : MenuWidget(widgetTitleName), textId(-1)
{
}

static const char widgetBGName[] = "widgetBG";

Widgets::BackgroundInGame::BackgroundInGame()
    : MenuWidget(widgetBGName)
{
}

void Widgets::Mission::SetScript(const Script* value)
{
    script = value;
}

int Widgets::Arrows::GetCurrentPage() const
{
    return currentPage;
}

void Widgets::Arrows::SetPageCount(int count, int page, bool reset)
{
    bool changed = pageCount != count;
    pageCount = count;
    if (changed || reset)
        currentPage = page >= 0 && page < count && !reset ? page : 0;
    if (listener && (reset || changed))
        listener->Notify(this, 2);
    setCharacterVisible(character, pageCount > 1);
}

static const char widgetTitleIcon[] = "widgetTitle.icon";

void Widgets::Title::SetIcon(const char* icon)
{
    if (icon)
        renderFX->GotoFrame(widgetTitleIcon, icon, false);
    else
        renderFX->GotoFrame(widgetTitleIcon, 0, false);
}

void Widgets::Title::SetTextId(int id)
{
    textId = id;
}

void Widgets::Mission::Show()
{
    MenuWidget::Show();
}

void Widgets::Money::Show()
{
    MenuWidget::Show();
}

void Widgets::Arrows::Show()
{
    MenuWidget::Show();
}

void Widgets::ContentBox::Show()
{
    MenuWidget::Show();
}

void Widgets::Title::Show()
{
    MenuWidget::Show();
}

void Widgets::BackgroundInGame::Show()
{
    MenuWidget::Show();
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_menuwidget_transitions {
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
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_menuwidget_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN10MenuWidgetC2EPKc() __attribute__((used));
static void _GLOBAL__I__ZN10MenuWidgetC2EPKc()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
