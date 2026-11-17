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
#include "../characters/PlayerTest.h"
#include "../persistence/StringManager.h"
#include "WidgetDialog.h"
#include "MenuState.h"
#include "../rendering/CharacterVisibility.h"
#include "../hud/MenuManager.h"

extern "C" {
void _ZN8RenderFX10FormatTextEPKcS1_z(RenderFX* fx, const char* name, const char* format, ...);
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
    int GetLastPressedButton() const;

private:
    template <bool show>
    void SetButtonsVisible();

    MenuButtonInfo buttons[5];
    int titleTextId;
    int backButtonTextId;
    int activeButton;
    int pressedButton;
};

class BlackBox : public MenuWidget {
public:
    enum eState { Thin, Wide, StateCount };
    BlackBox();
    void SetState(eState state);

private:
    int state;
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

class Statistics : public MenuWidget {
public:
    Statistics();
    void Update(bool advanceFirst);
    virtual void Show();
    virtual void Enable();
    virtual void Disable();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    int unknown20, unknown24, unknown28, unknown32;
    gameswf::character* animation;
    unsigned char unknown40[56];
    int unknown96;
    unsigned char unknown100[256];
};

class Achievements : public MenuWidget {
public:
    Achievements();
    void Update(bool advanceFirst);
    void Reset();
    virtual void Show();
    virtual void Enable();
    virtual void Disable();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    int unknown20, unknown24, unknown28, unknown32, unknown36;
    gameswf::character* animation;
    unsigned char unknown44[96];
    int unknown140;
};

class Objective : public MenuWidget {
public:
    Objective();
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
    void SetObjectiveText(int id);

private:
    int textId;
    bool expanded;
};

class Achievement : public MenuWidget {
public:
    Achievement();
    virtual bool AutoHide() const;
    virtual void UpdateLocalization();
    void SetTitle(int id);

private:
    int titleId;
};

class Help : public MenuWidget {
public:
    Help();
    void SetTextId(int id);
    virtual void UpdateLocalization();

private:
    int textId;
};

class GameSetting : public MenuWidget {
public:
    GameSetting();
    void HideButtonOk();
    void HideSelection();
    void SetTitleId(int id);
    void SetValueId(int id);
    void SetValue(const char* value);
    void SetTitle(const char* title);
    void ShowSelection();
    void ShowButtonOk();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    int titleTextId;
    int valueTextId;
};

class Language : public MenuWidget {
public:
    Language();
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    int selection;
    static const int s_languageIds[6];
};

class Controls : public MenuWidget {
public:
    Controls();
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    int selection;
    int previousSelection;
};

class Volumes : public MenuWidget {
public:
    Volumes();
    virtual void Show();
    virtual void Hide(bool);
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
    void SetPlaylist(int playlist);

private:
    static int s_playlist;
    int selectedPlaylist;
};

class Corruption : public MenuWidget {
public:
    Corruption();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
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

class BackgroundDemoBuy : public MenuWidget {
public:
    BackgroundDemoBuy();
};

class DemoBuy : public MenuWidget {
public:
    DemoBuy();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
};

class Tutorial : public MenuWidget {
public:
    explicit Tutorial(const char* name);
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
    bool IsCursorPressed() const;

protected:
    int unknown20;
    int unknown24;
    int unknown28;
    bool cursorPressed;
    int unknown36;
};

class BlockingTutorial : public Tutorial {
public:
    BlockingTutorial();
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();
};

class BackgroundMainMenu : public MenuWidget {
public:
    BackgroundMainMenu();
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

int Widgets::IGMenu::GetLastPressedButton() const
{
    return pressedButton;
}

static const char widgetBlackBoxName[] = "widgetBlackBox";
static const char blackBoxThinAnimation[] = "thin";
static const char blackBoxWideAnimation[] = "wide";

Widgets::BlackBox::BlackBox()
    : MenuWidget(widgetBlackBoxName), state(Thin)
{
}

void Widgets::BlackBox::SetState(eState next)
{
    if (!IsVisible() || state == next)
        return;
    state = next;
    switch (next) {
    case Thin:
        renderFX->PlayAnim(character, blackBoxThinAnimation, 0);
        break;
    case Wide:
        renderFX->PlayAnim(character, blackBoxWideAnimation, 0);
        break;
    default:
        break;
    }
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

static const char widgetStatisticsName[] = "widgetStatistics";
static const char widgetStatisticsAnimation[] = "widgetStatistics.anim";
static const char widgetAchievementsName[] = "widgetAchievements";
static const char widgetAchievementsAnimation[] = "widgetAchievements.content.anim";
static const char widgetObjectiveName[] = "widgetObjective";
static const char widgetAchievementName[] = "widgetAchievement";

Widgets::Statistics::Statistics()
    : MenuWidget(widgetStatisticsName), unknown20(0), unknown24(-1),
      unknown28(0), unknown32(0), animation(0), unknown96(0)
{
    memset(unknown100, -1, sizeof(unknown100));
    animation = renderFX->Find(widgetStatisticsAnimation);
    renderFX->GotoFrame(animation, 0, false);
}

Widgets::Achievements::Achievements()
    : MenuWidget(widgetAchievementsName), unknown20(0), unknown24(-1),
      unknown28(0), unknown32(0), unknown36(-1), animation(0), unknown140(0)
{
    animation = renderFX->Find(widgetAchievementsAnimation);
    renderFX->GotoFrame(animation, 0, false);
}

namespace {
struct WidgetAnimationMethods {
    void (*beforePlayState[35])();
    int (*getPlayState)(const gameswf::character*);
    void (*beforeCurrentFrame[39])();
    int (*getCurrentFrame)(const gameswf::character*);
};

inline const WidgetAnimationMethods& widgetAnimationMethods(const gameswf::character* animation)
{
    return **reinterpret_cast<const WidgetAnimationMethods* const*>(animation);
}

template <int extraPages>
inline void updateInfoWidget(MenuWidget* widget, gameswf::character* animation,
                             int& page, const int& pageCount, bool advanceFirst)
{
    if (widgetAnimationMethods(animation).getPlayState(animation) != 0)
        return;
    if (advanceFirst)
        page = pageCount ? (page + 1) % (pageCount + extraPages) : 0;
    widget->UpdateLocalization();
    page = pageCount ? (page + 1) % (pageCount + extraPages) : 0;
}
}

void Widgets::Statistics::Update(bool advanceFirst)
{
    updateInfoWidget<4>(this, animation, unknown20, unknown96, advanceFirst);
}

void Widgets::Achievements::Update(bool advanceFirst)
{
    updateInfoWidget<2>(this, animation, unknown20, unknown140, advanceFirst);
}

void Widgets::Achievements::Reset()
{
    unknown20 = unknown140;
    renderFX->GotoFrame(animation, 0, true);
}

void Widgets::Achievements::Show()
{
    MenuWidget::Show();
    unknown20 = unknown140;
    UpdateLocalization();
    unknown20 = unknown140 ? (unknown20 + 1) % (unknown140 + 2) : 0;
    renderFX->GotoFrame(animation, 0, true);
}

void Widgets::Statistics::Enable()
{
    MenuWidget::Enable();
    unknown20 = unknown96;
    renderFX->GotoFrame(animation, 0, true);
}

void Widgets::Achievements::Enable()
{
    MenuWidget::Enable();
    Reset();
}

void Widgets::Statistics::Disable()
{
    MenuWidget::Disable();
    unknown32 = widgetAnimationMethods(animation).getCurrentFrame(animation);
    renderFX->GotoFrame(animation, unknown32, false);
}

void Widgets::Achievements::Disable()
{
    MenuWidget::Disable();
    unknown32 = widgetAnimationMethods(animation).getCurrentFrame(animation);
    renderFX->GotoFrame(animation, unknown32, false);
}

Widgets::Objective::Objective()
    : MenuWidget(widgetObjectiveName), textId(-1), expanded(false)
{
}

void Widgets::Objective::SetObjectiveText(int id)
{
    textId = id;
}

static const char objectiveOpen[] = "open";
static const char objectiveClose[] = "close";
static const char objectiveButton[] = "widgetObjective.btnObjective";
static const char objectiveArrowUp[] = "up";
static const char objectiveArrowDown[] = "down";
static const char objectiveArrow[] = "widgetObjective.arrow";

void Widgets::Objective::Show()
{
    MenuWidget::Show();
    renderFX->GotoFrame(character, expanded ? objectiveOpen : objectiveClose, false);
    renderFX->GotoFrame(objectiveButton, expanded ? objectiveOpen : objectiveClose, false);
    renderFX->GotoFrame(objectiveArrow, expanded ? objectiveArrowUp : objectiveArrowDown, false);
}

Widgets::Achievement::Achievement()
    : MenuWidget(widgetAchievementName), titleId(-1)
{
}

void Widgets::Achievement::SetTitle(int id)
{
    titleId = id;
}

bool Widgets::Achievement::AutoHide() const
{
    return false;
}

static const char achievementCaptionPath[] = "widgetAchievement.anim.txtAchievement";
static const char achievementTitlePath[] = "widgetAchievement.anim.txtName";
static const char objectiveTextPath[] = "widgetObjective.text";
static const char objectiveButtonPath[] = "widgetObjective.btnObjective.text";

void Widgets::Achievement::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, achievementCaptionPath,
                               _ZNK13StringManager9getStringEi(strings, 0x308c), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, achievementTitlePath,
                               _ZNK13StringManager9getStringEi(strings, titleId), true);
}

void Widgets::Objective::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    MenuManager::getInstance();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    if (textId != -1) {
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, objectiveTextPath,
                                   _ZNK13StringManager9getStringEi(strings, textId), true);
    }
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, objectiveButtonPath,
                               _ZNK13StringManager9getStringEi(strings, 0x1038), true);
}

static const char widgetHelpName[] = "widgetHelp";

Widgets::Help::Help()
    : MenuWidget(widgetHelpName), textId(-1)
{
}

static const char widgetGameSettingName[] = "widgetGameSetting";

Widgets::GameSetting::GameSetting()
    : MenuWidget(widgetGameSettingName), titleTextId(-1), valueTextId(-1)
{
}

static const char widgetLanguageName[] = "widgetLanguage";

static const char helpTextPath[] = "widgetHelp.text";
static const char gameSettingTitlePath[] = "widgetGameSetting.txtTitle";
static const char gameSettingValuePath[] = "widgetGameSetting.txtValue";

void Widgets::Help::SetTextId(int id)
{
    textId = id;
}

void Widgets::Help::UpdateLocalization()
{
    if (textId != -1) {
        StringManager* strings = Application::GetInstance()->GetStringManager();
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, helpTextPath,
                                   _ZNK13StringManager9getStringEi(strings, textId), true);
    }
}

void Widgets::GameSetting::UpdateLocalization()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    if (titleTextId != -1) {
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, gameSettingTitlePath,
                                   _ZNK13StringManager9getStringEi(strings, titleTextId), true);
    }
    if (valueTextId != -1) {
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, gameSettingValuePath,
                                   _ZNK13StringManager9getStringEi(strings, valueTextId), true);
    }
}

static const char gameSettingLeftButton[] = "widgetGameSetting.btnLeft";
static const char gameSettingRightButton[] = "widgetGameSetting.btnRight";
static const char gameSettingSelectionBackground[] = "widgetGameSetting.selectionBackground";
static const char gameSettingOkButton[] = "widgetGameSetting.btnOk";
static const char gameSettingOkText[] = "widgetGameSetting.btnOk.text";

void Widgets::GameSetting::ShowSelection()
{
    renderFX->SetVisible(gameSettingLeftButton, true);
    renderFX->SetVisible(gameSettingRightButton, true);
    renderFX->SetVisible(gameSettingValuePath, true);
    renderFX->SetVisible(gameSettingSelectionBackground, true);
}

void Widgets::GameSetting::ShowButtonOk()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    renderFX->SetVisible(gameSettingOkButton, true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, gameSettingOkText,
                               _ZNK13StringManager9getStringEi(strings, 0x102b), true);
}

void Widgets::GameSetting::HideButtonOk()
{
    renderFX->SetVisible(gameSettingOkButton, false);
}

void Widgets::GameSetting::HideSelection()
{
    renderFX->SetVisible(gameSettingLeftButton, false);
    renderFX->SetVisible(gameSettingRightButton, false);
    renderFX->SetVisible(gameSettingValuePath, false);
    renderFX->SetVisible(gameSettingSelectionBackground, false);
}

void Widgets::GameSetting::SetTitleId(int id)
{
    titleTextId = id;
}

void Widgets::GameSetting::SetValueId(int id)
{
    valueTextId = id;
}

void Widgets::GameSetting::SetValue(const char* value)
{
    valueTextId = -1;
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, gameSettingValuePath, value, true);
}

void Widgets::GameSetting::SetTitle(const char* title)
{
    if (title) {
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, gameSettingTitlePath, title, true);
    }
}

Widgets::Language::Language()
    : MenuWidget(widgetLanguageName), selection(0)
{
}

static const char widgetCorruptionName[] = "widgetCorruption";

Widgets::Corruption::Corruption()
    : MenuWidget(widgetCorruptionName), wantedLevel(0)
{
}

static const char widgetControlsName[] = "widgetControls";

Widgets::Controls::Controls()
    : MenuWidget(widgetControlsName), selection(-1), previousSelection(-1)
{
}

static const char languageTitlePath[] = "widgetLanguage.txtTitle";
static const char languageValuePath[] = "widgetLanguage.txtValue";
static const char languageOkPath[] = "widgetLanguage.btnOk.text";
const int Widgets::Language::s_languageIds[6] = {
    0x1002, 0x1003, 0x1004, 0x1005, 0x1006, 0x1007
};

namespace {
struct StringManagerLanguage {
    unsigned char prefix[4];
    int language;
};
}

void Widgets::Language::Show()
{
    MenuWidget::Show();
    const StringManager* strings = Application::GetInstance()->GetStringManager();
    selection = reinterpret_cast<const StringManagerLanguage*>(strings)->language;
    UpdateLocalization();
}

void Widgets::Language::UpdateLocalization()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, languageTitlePath,
                               _ZNK13StringManager9getStringEi(strings, 0x1001), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, languageValuePath,
                               _ZNK13StringManager9getStringEi(strings, s_languageIds[selection]), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, languageOkPath,
                               _ZNK13StringManager9getStringEi(strings, 0x102b), true);
}

void Widgets::Controls::Show()
{
    MenuWidget::Show();
    UpdateLocalization();
}

static const char widgetVolumesName[] = "widgetVolumes";

Widgets::Volumes::Volumes()
    : MenuWidget(widgetVolumesName), selectedPlaylist(-2)
{
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

static const char widgetBGMainName[] = "widgetBGMain";
static const char widgetBuyName[] = "widgetBuy";
static const char widgetTutoBlockName[] = "widgetTutoBlock";
static const char blockingTutorialCloseButton[] = "widgetTutoBlock.group.btnClose";

bool Widgets::Tutorial::IsCursorPressed() const
{
    return cursorPressed;
}

Widgets::BackgroundDemoBuy::BackgroundDemoBuy()
    : MenuWidget(widgetBGMainName)
{
}

Widgets::DemoBuy::DemoBuy()
    : MenuWidget(widgetBuyName)
{
}

Widgets::Tutorial::Tutorial(const char* name)
    : MenuWidget(name), unknown20(-1), unknown24(0), unknown28(0),
      cursorPressed(false), unknown36(0)
{
}

Widgets::BlockingTutorial::BlockingTutorial()
    : Tutorial(widgetTutoBlockName)
{
}

void Widgets::Tutorial::Show()
{
    MenuWidget::Show();
    renderFX->PlayAnim(character, widgetShowAnimation, 0);
    cursorPressed = false;
    unknown20 = -1;
    unknown24 = 0;
    unknown28 = 0;
}

void Widgets::BlockingTutorial::Show()
{
    Tutorial::Show();
    renderFX->SetVisible(blockingTutorialCloseButton, false);
}

Widgets::BackgroundMainMenu::BackgroundMainMenu()
    : MenuWidget(widgetBGMainName)
{
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

static const char widgetArrowsText[] = "widgetArrows.text";
static const char widgetArrowsPageFormat[] = "%d/%d";
static const char widgetTitleText[] = "widgetTitle.text";

void Widgets::Arrows::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    _ZN8RenderFX10FormatTextEPKcS1_z(renderFX, widgetArrowsText, widgetArrowsPageFormat,
                                    currentPage + 1, pageCount);
}

void Widgets::Title::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    if (textId != -1) {
        StringManager* strings = Application::GetInstance()->GetStringManager();
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, widgetTitleText,
                                   _ZNK13StringManager9getStringEi(strings, textId), true);
    }
}

static const char widgetMoneyLabel[] = "widgetMoney.group.txtMoney";
static const char widgetMoneyAmount[] = "widgetMoney.group.txtAmount";
static const char blockingTutorialOkText[] = "widgetTutoBlock.group.btnOk.text";

void Widgets::Money::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, widgetMoneyLabel,
                               _ZNK13StringManager9getStringEi(strings, 0x105d), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, widgetMoneyAmount,
                               strings->formatAmount(PlayerTest::GetPlayer()->cash, true, true), true);
}

void Widgets::BlockingTutorial::UpdateLocalization()
{
    Tutorial::UpdateLocalization();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, blockingTutorialOkText,
                               _ZNK13StringManager9getStringEi(strings, 0x102b), true);
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
