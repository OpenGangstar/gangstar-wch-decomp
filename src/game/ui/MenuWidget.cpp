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
#include "../core/NativeStrings.h"
#include "../app/Application.h"
#include "../characters/PlayerTest.h"
#include "../persistence/StringManager.h"
#include "WidgetDialog.h"
#include "MenuState.h"
#include "../rendering/CharacterVisibility.h"
#include "../rendering/FlashMatrix.h"
#include "../rendering/RetailSwfString.h"
#include "../rendering/RetailSwfValue.h"
#include "../audio/SoundManager.h"
#include "../core/NativeStrings.h"
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

extern const char widgetHideAnimation[] __attribute__((visibility("hidden")));
extern const char widgetShowAnimation[] __attribute__((visibility("hidden")));

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

extern const char widgetButtonPrefix[] __attribute__((visibility("hidden")));

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

struct ControlChoice { int value; int textId; };

namespace Widgets {
struct MenuButtonInfo {
    int textId;
    bool enabled;
};

class IGMenu : public MenuWidget {
public:
    enum eButton { Invalid = -1, First, Second, Third, Fourth, Fifth, ButtonForceWidth = 0x7fffffff };
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
    int statisticIds[64];
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
    static const ControlChoice s_choiceSteerings[3];
    static const ControlChoice s_choiceThrottles[2];
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
    memset(statisticIds, -1, sizeof(statisticIds));
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

namespace Widgets {
class Shop : public MenuWidget {
public:
    Shop();
    void SetAvailabilityText(int id);
    int GetSelectedItem() const;
    void Reset();
    void SetItem(int index, int textId, int value, const char* frame, int flags);
    virtual void OnEvent(RenderFX::Event& event);
    virtual void UpdateLocalization();

private:
    struct Item {
        Item() : textId(-1), value(0), flags(0) {}
        int textId;
        int value;
        int flags;
    };
    Item items[4];
    int selectedItem;
    int availabilityTextId;
};
}

namespace {
const char shopWidgetName[] __attribute__((section(".rodata.widget_shop_name"))) = "widgetShop";
}

Widgets::Shop::Shop()
    : MenuWidget(shopWidgetName), selectedItem(-1), availabilityTextId(0x103b)
{
}

void Widgets::Shop::SetAvailabilityText(int id)
{
    availabilityTextId = id;
}

int Widgets::Shop::GetSelectedItem() const
{
    return selectedItem;
}

void Widgets::Shop::Reset()
{
    for (int index = 0; index < 4; ++index) {
        items[index].flags = 0;
        items[index].value = 0;
        items[index].textId = -1;
    }
}

static const char shopItemButtonPrefix[] = "btnItem";

void Widgets::Shop::OnEvent(RenderFX::Event& event)
{
    if (event.type != 6)
        return;

    const char* name = event.characterName;
    if (!strstr(name, shopItemButtonPrefix))
        return;

    selectedItem = name[7] - '0';
    if (listener)
        listener->Notify(this, 1);
    event.consumed = true;
}

namespace {
const char shopItemIconFormat[] __attribute__((section(".rodata.shop_item_icon_format"))) = "widgetShop.btnItem%d.icon";
}

void Widgets::Shop::SetItem(int index, int textId, int value, const char* frame, int flags)
{
    if (static_cast<unsigned int>(index) < 4) {
        items[index].textId = textId;
        items[index].value = value;
        items[index].flags = flags;
        if (frame) {
            char name[64];
            sprintf(name, shopItemIconFormat, index);
            renderFX->GotoFrame(name, frame, false);
        }
    }
}

namespace {
const char shopButtonPath[] __attribute__((section(".rodata.shop_button_path"))) = "widgetShop.btnItem%d";
const char shopNamePath[] __attribute__((section(".rodata.shop_name_path"))) = "widgetShop.btnItem%d.txtName";
const char shopPricePath[] __attribute__((section(".rodata.shop_price_path"))) = "widgetShop.btnItem%d.txtPrice";
const char shopAvailabilityPath[] __attribute__((section(".rodata.shop_availability_path"))) = "widgetShop.btnItem%d.txtAvailability";
}

void Widgets::Shop::UpdateLocalization()
{
    char name[128];
    StringManager* strings = Application::GetInstance()->GetStringManager();
    for (int i = 0; i < 4; ++i) {
        Item& item = items[i];
        sprintf(name, shopButtonPath, i);
        renderFX->SetVisible(name, item.flags & 4);
        if (item.flags & 4) {
            sprintf(name, shopNamePath, i);
            renderFX->SetText(name, item.textId == -1 ? localStartupEmptyText : _ZNK13StringManager9getStringEi(strings, item.textId), true);
            sprintf(name, shopPricePath, i);
            renderFX->SetText(name, strings->formatAmount(item.value, true, true), true);
            sprintf(name, shopButtonPath, i);
            renderFX->SetEnabled(name, item.flags & 1);
            sprintf(name, shopAvailabilityPath, i);
            renderFX->SetText(name, availabilityTextId == -1 || (item.flags & 2)
                ? localStartupEmptyText : _ZNK13StringManager9getStringEi(strings, availabilityTextId), true);
        }
    }
}

namespace Widgets {
class About : public MenuWidget {
public:
    About();
    void Update(bool advanceFirst);
    virtual void Show();
    virtual void Enable();
    virtual void Disable();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    int page;
    int unknown24;
    int unknown28;
    int unknown32;
    gameswf::character* animation;
    gameswf::character* credits[12];
};
}

void Widgets::About::Enable()
{
    MenuWidget::Enable();
    page = 0;
    renderFX->GotoFrame(animation, 0, true);
}

void Widgets::About::Disable()
{
    MenuWidget::Disable();
    unknown32 = widgetAnimationMethods(animation).getCurrentFrame(animation);
    renderFX->GotoFrame(animation, unknown32, false);
}

void Widgets::About::Update(bool advanceFirst)
{
    if (getCharacterPlayState(animation) == 0) {
        if (advanceFirst)
            page = (page + 1) % 280;
        UpdateLocalization();
        page = (page + 1) % 280;
    }
}

static const char aboutWidgetName[] = "widgetAbout";
static const char aboutCreditFormat[] = "txtAbout%d";

Widgets::About::About()
    : MenuWidget(aboutWidgetName), page(0), unknown24(-1), unknown28(0), unknown32(0), animation(0)
{
    char name[64];
    for (int index = 0; index < 12; ++index) {
        sprintf(name, aboutCreditFormat, index);
        credits[index] = renderFX->Find(name);
    }
}

static const char aboutAnimationName[] = "widgetAbout.anim";

void Widgets::About::Show()
{
    MenuWidget::Show();
    page = 0;
    if (!animation)
        animation = renderFX->Find(aboutAnimationName);
    renderFX->GotoFrame(animation, 0, true);
}

extern "C" {
const gameswf::matrix& _ZN7gameswf9character16get_world_matrixEv(gameswf::character* character);
}

static const char aboutTextButtonName[] = "btnTexts";

void Widgets::About::OnEvent(RenderFX::Event& event)
{
    if (strcmp(event.characterName, aboutTextButtonName) != 0)
        return;

    switch (event.type) {
    case 5: {
        const gameswf::matrix matrix = _ZN7gameswf9character16get_world_matrixEv(event.character);
        const gameswf::point& coordinates = *reinterpret_cast<const gameswf::point*>(event.unknown12);
        const float x = coordinates.x;
        const float y = coordinates.y;
        const gameswf::point input(x, y);
        gameswf::point point;
        matrix.transform(&point, input);

        if (unknown24 == -1) {
            const float mouseFrame = point.y / 20.0f;
            const float currentFrame = widgetAnimationMethods(animation).getCurrentFrame(animation);
            unknown24 = static_cast<int>(mouseFrame + currentFrame);
            unknown28 = page - 1;
        }
        const int frameOffset = static_cast<int>(static_cast<float>(unknown24) + point.y / -20.0f);
        int pageOffset = frameOffset / 20;
        if (frameOffset < 0)
            --pageOffset;
        const int newPage = (unknown28 + pageOffset) % 280;
        if (page != newPage) {
            page = newPage;
            UpdateLocalization();
        }
        if (frameOffset < 0) {
            const int remainder = frameOffset % 20;
            unknown32 = 19 - (remainder < 0 ? -remainder : remainder);
        } else {
            unknown32 = frameOffset % 20;
        }
        renderFX->GotoFrame(animation, unknown32, false);
        break;
    }
    case 6:
        _ZN11MenuManager10clearFocusEv(MenuManager::getInstance());
        // Fall through to finish the gesture.
    case 1:
        if (getCharacterPlayState(animation) != 0)
            renderFX->GotoFrame(animation, unknown32, true);
        unknown24 = -1;
        page = (page + (event.type != 6)) % 280;
        break;
    }
    event.consumed = true;
}

extern "C" char* strcat(char*, const char*);
extern "C" void _ZN11MenuManager13setMenuFXTextEPN7gameswf9characterEPKcbb(
    MenuManager*, gameswf::character*, const char*, bool, bool);

static const char aboutVersionToken[] = "%v";
static const char aboutVersionFormat[] = "%i.%i.%i";

void Widgets::About::UpdateLocalization()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    MenuManager* menu = MenuManager::getInstance();
    for (int i = 0; i < 12; ++i) {
        char buffer[512];
        int index = (page + i) % 280;
        if (index < 0)
            index += 280;
        strcpy(buffer, _ZNK13StringManager9getStringEi(strings, 0xb000 + index));
        char* token = strstr(buffer, aboutVersionToken);
        if (token) {
            *token = 0;
            char version[16];
            sprintf(version, aboutVersionFormat, 3, 5, 0);
            strcat(buffer, version);
        }
        _ZN11MenuManager13setMenuFXTextEPN7gameswf9characterEPKcbb(
            menu, credits[i], buffer, true, false);
    }
}

namespace Widgets {
class MapLegend : public MenuWidget {
public:
    MapLegend();
    virtual void Show();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    int textIds[8];
    bool expanded;
};
}

static const char widgetMapLegendName[] = "widgetMapLegend";

Widgets::MapLegend::MapLegend() : MenuWidget(widgetMapLegendName), expanded(false)
{
    textIds[0] = 0x105c;
    textIds[1] = 0x105b;
    textIds[2] = 0x1054;
    textIds[3] = 0x1056;
    textIds[4] = 0x1057;
    textIds[5] = 0x105a;
    textIds[6] = 0x1059;
    textIds[7] = 0x1058;
}

static const char mapLegendButton[] = "widgetMapLegend.btnLegend";

void Widgets::MapLegend::Show()
{
    MenuWidget::Show();
    renderFX->GotoFrame(character, expanded ? objectiveOpen : objectiveClose, false);
    renderFX->GotoFrame(mapLegendButton, expanded ? objectiveOpen : objectiveClose, false);
}

static const char mapLegendRowLabelFormat[] = "widgetMapLegend.group.txt%d";
static const char mapLegendButtonText[] = "widgetMapLegend.btnLegend.text";

void Widgets::MapLegend::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    MenuManager::getInstance();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    for (int row = 0; row < 8; ++row) {
        if (textIds[row] != -1) {
            char name[128];
            sprintf(name, mapLegendRowLabelFormat, row);
            _ZN8RenderFX7SetTextEPKcS1_b(renderFX, name, _ZNK13StringManager9getStringEi(strings, textIds[row]), true);
        }
    }
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, mapLegendButtonText, _ZNK13StringManager9getStringEi(strings, 0x1052), true);
}

extern const char mapLegendButtonName[] __attribute__((visibility("hidden")));
static const char mapLegendArrow[] = "widgetMapLegend.arrow";

void Widgets::MapLegend::OnEvent(RenderFX::Event& event)
{
    MenuWidget::OnEvent(event);
    switch (event.type) {
    case 6:
        if (strcmp(event.characterName, mapLegendButtonName) == 0) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(220, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            expanded = !expanded;
            renderFX->GotoFrame(character, expanded ? objectiveOpen : objectiveClose, false);
            renderFX->GotoFrame(mapLegendButton, expanded ? objectiveOpen : objectiveClose, false);
            renderFX->GotoFrame(mapLegendArrow, expanded ? objectiveArrowDown : objectiveArrowUp, false);
            event.consumed = true;
        }
        break;
    }
}

static const char corruptButtonName[] = "btnCorrupt";

void Widgets::Corruption::OnEvent(RenderFX::Event& event)
{
    if (event.type != 6 || strcmp(event.characterName, corruptButtonName) != 0)
        return;

    if (listener)
        listener->Notify(this, 1);
    event.consumed = true;
}

static const char corruptionBadgeGroup[] = "widgetCorruption.badges";
static const char corruptionTitle[] = "widgetCorruption.txtTitle";
static const char corruptionSlashField[] = "widgetCorruption.txtSlash";
static const char corruptionPrice[] = "widgetCorruption.txtPrice";
static const char corruptionValue[] = "widgetCorruption.txtValue";
static const char corruptionPerBadge[] = "widgetCorruption.txtPerBadge";
static const char corruptionButton[] = "widgetCorruption.btnCorrupt";
static const char corruptionButtonText[] = "widgetCorruption.btnCorrupt.text";
static const char corruptionNoWantedLevel[] = "widgetCorruption.badges.txtWantedLevel0";
static const char corruptionSlash[] = "/";

void Widgets::Corruption::UpdateLocalization()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    renderFX->GotoFrame(corruptionBadgeGroup, wantedLevel, false);
    renderFX->SetVisible(corruptionTitle, wantedLevel != 0);
    renderFX->SetVisible(corruptionSlashField, wantedLevel != 0);
    renderFX->SetVisible(corruptionPrice, wantedLevel != 0);
    renderFX->SetVisible(corruptionValue, wantedLevel != 0);
    renderFX->SetVisible(corruptionPerBadge, wantedLevel != 0);
    renderFX->SetEnabled(corruptionButton, wantedLevel != 0);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, corruptionButtonText, _ZNK13StringManager9getStringEi(strings, 0x1050), true);
    renderFX->SetVisible(corruptionNoWantedLevel, wantedLevel == 0);
    if (wantedLevel == 0) {
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, corruptionNoWantedLevel, _ZNK13StringManager9getStringEi(strings, 0x104d), true);
    } else {
        PlayerTest* player = PlayerTest::GetPlayer();
        const bool canAfford = player->isRichAsCroesus() || player->cash >= 1500;
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, corruptionTitle, _ZNK13StringManager9getStringEi(strings, 0x104c), true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, corruptionSlashField, corruptionSlash, true);
        renderFX->SetEnabled(corruptionButton, canAfford);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, corruptionPrice, _ZNK13StringManager9getStringEi(strings, 0x104e), true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, corruptionPerBadge, _ZNK13StringManager9getStringEi(strings, 0x104f), true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, corruptionValue, strings->formatAmount(1500, true, true), true);
    }
}

extern "C" void _ZN11MenuManager3popEb(MenuManager*, bool);
static const char demoBuyConfirmButtonName[] = "btnBuy";
static const char menuBackButtonName[] = "btnBack";

void Widgets::DemoBuy::OnEvent(RenderFX::Event& event)
{
    const char* name = event.characterName;
    if (event.type == 6) {
        if (strcmp(name, demoBuyConfirmButtonName) == 0)
            event.consumed = true;
        else if (strcmp(name, menuBackButtonName) == 0)
            _ZN11MenuManager3popEb(MenuManager::getInstance(), true);
    }
}

static const char demoBuyConfirmText[] = "widgetBuy.btnBuy.text";
static const char demoBuyBackText[] = "widgetBuy.btnBack.text";
static const char demoBuyDescription0[] = "widgetBuy.groupTxt.txtBuy0";
static const char demoBuyDescription1[] = "widgetBuy.groupTxt.txtBuy1";

void Widgets::DemoBuy::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, demoBuyConfirmText, _ZNK13StringManager9getStringEi(strings, 0x1080), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, demoBuyBackText, _ZNK13StringManager9getStringEi(strings, 0x1027), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, demoBuyDescription0, _ZNK13StringManager9getStringEi(strings, 0x1081), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, demoBuyDescription1, _ZNK13StringManager9getStringEi(strings, 0x1082), true);
}

static const char tutorialOkButton[] = "btnOk";

void Widgets::BlockingTutorial::OnEvent(RenderFX::Event& event)
{
    Tutorial::OnEvent(event);
    if (event.consumed || event.type != 6 || strcmp(event.characterName, tutorialOkButton) != 0)
        return;

    if (listener)
        listener->Notify(this, 1);
    event.consumed = true;
}

static const char tutorialCloseButtonLabel[] = "btnClose";
static const char tutorialScrollButtonLabel[] = "btnScroll";
static const char tutorialPartFormat[] = "%s%s";
static const char tutorialScrollPart[] = ".group.btnScroll";
static const char tutorialArrowUpPart[] = ".group.arrowUp";
static const char tutorialArrowDownPart[] = ".group.arrowDown";

namespace {
struct TutorialCharacterName {
    unsigned char unknown0[136];
    unsigned char inlineName[12];
    const char* heapName;

    const char* c_str() const
    {
        return inlineName[0] == 255 ? heapName : reinterpret_cast<const char*>(inlineName + 1);
    }
};

inline const char* tutorialCharacterName(const gameswf::character* character)
{
    return reinterpret_cast<const TutorialCharacterName*>(character)->c_str();
}
}

void Widgets::Tutorial::OnEvent(RenderFX::Event& event)
{
    switch (event.type) {
    case 1:
        if (unknown20 != -1 && strstr(event.characterName, widgetButtonPrefix) == event.characterName) {
            unknown20 = -1;
            cursorPressed = false;
            MenuManager::getInstance()->consumeCursor();
        }
        event.consumed = true;
        break;
    case 4:
        cursorPressed = true;
        MenuManager::getInstance()->consumeCursor();
        event.consumed = true;
        break;
    case 5:
        if (unknown36 > 75 && cursorPressed && strcmp(tutorialScrollButtonLabel, event.characterName) == 0) {
            const gameswf::matrix matrix = _ZN7gameswf9character16get_world_matrixEv(event.character);
            const gameswf::point& coordinates = *reinterpret_cast<const gameswf::point*>(event.unknown12);
            const gameswf::point input(coordinates.x, coordinates.y);
            gameswf::point point;
            matrix.transform(&point, input);

            if (unknown20 == -1) {
                unknown20 = static_cast<int>(point.y / 20.0f);
                unknown28 = unknown24;
            }
            unknown24 = unknown28 + static_cast<int>(unknown20 + point.y / -20.0f) / 3;
            if (unknown24 < 0)
                unknown24 = 0;
            if (unknown24 > 24)
                unknown24 = 24;

            char name[64];
            sprintf(name, tutorialPartFormat, tutorialCharacterName(character), tutorialScrollPart);
            renderFX->GotoFrame(name, unknown24, false);
            sprintf(name, tutorialPartFormat, tutorialCharacterName(character), tutorialArrowUpPart);
            renderFX->SetVisible(name, unknown24 > 0);
            sprintf(name, tutorialPartFormat, tutorialCharacterName(character), tutorialArrowDownPart);
            renderFX->SetVisible(name, unknown24 < 24);
            MenuManager::getInstance()->consumeCursor();
        }
        event.consumed = true;
        break;
    case 6:
        if (strcmp(tutorialCloseButtonLabel, event.characterName) != 0) {
            unknown20 = -1;
            cursorPressed = false;
            MenuManager::getInstance()->consumeCursor();
            break;
        }
        if (listener)
            listener->Notify(this, 1);
        event.consumed = true;
        break;
    }
}

static const char igMenuButtonName[] = "btnMenu";

void Widgets::IGMenu::OnEvent(RenderFX::Event& event)
{
    MenuWidget::OnEvent(event);
    MenuManager::getInstance();
    StringManager* strings = Application::GetInstance()->GetStringManager();

    switch (event.type) {
    case 0:
    case 1: {
        const char* name = event.characterName;
        if (strstr(name, igMenuButtonName)) {
            if (activeButton == name[7] - '0')
                SetActiveButton(static_cast<eButton>(activeButton), true);
            event.consumed = true;
        } else if (strcmp(name, menuBackButtonName) == 0) {
            MenuManager* manager = MenuManager::getInstance();
            const char* text = _ZNK13StringManager9getStringEi(strings, backButtonTextId);
            _ZN11MenuManager13setMenuFXTextEPKcS1_bb(manager, igMenuBackText, text, true, false);
        }
        break;
    }
    case 6: {
        const char* name = event.characterName;
        if (strcmp(name, menuBackButtonName) == 0) {
            if (listener)
                listener->Notify(this, 1);
            event.consumed = true;
        } else if (strstr(name, igMenuButtonName)) {
            const int current = activeButton;
            const int button = name[7] - '0';
            if (current != button) {
                pressedButton = button;
                if (listener)
                    listener->Notify(this, 2);
            } else {
                SetActiveButton(static_cast<eButton>(current), true);
            }
            event.consumed = true;
        }
        break;
    }
    default:
        break;
    }
}

void Widgets::Volumes::Hide(bool animate)
{
    if (selectedPlaylist != s_playlist) {
        if (s_playlist == -2) {
            SoundManager::getInstance()->useBuiltInRadio();
        } else {
            SoundManager::getInstance()->useIPodRadio();
            SoundManager::getInstance()->setPlaylist(s_playlist);
        }
    }
    if (!SoundManager::getInstance()->isLowFpsMusicPlaying())
        SoundManager::getInstance()->stop(35, -1, 0);
    MenuWidget::Hide(animate);
}

static const char confirmPaymentFormat[] = "%s <font color=\"#00CC66\">%s</font>";
static const char confirmPaymentMessagePath[] = "widgetConfirm.txtMessage";

void Widgets::ConfirmPayment::UpdateLocalization()
{
    Confirm::UpdateLocalization();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    const int id = GetMessageId();
    const char* message = id == -1 ? localStartupEmptyText : _ZNK13StringManager9getStringEi(strings, id);
    char text[1024];
    sprintf(text, confirmPaymentFormat, message, strings->formatAmount(price, true, true));
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, confirmPaymentMessagePath, text, true);
}

void Widgets::Statistics::OnEvent(RenderFX::Event& event)
{
    if (strcmp(event.characterName, tutorialScrollButtonLabel) != 0)
        return;

    switch (event.type) {
    case 5: {
        const gameswf::matrix matrix = _ZN7gameswf9character16get_world_matrixEv(event.character);
        const gameswf::point& coordinates = *reinterpret_cast<const gameswf::point*>(event.unknown12);
        const float x = coordinates.x;
        const float y = coordinates.y;
        const gameswf::point input(x, y);
        gameswf::point point;
        matrix.transform(&point, input);

        if (unknown24 == -1) {
            const float mouseFrame = point.y / 20.0f;
            const float currentFrame = widgetAnimationMethods(animation).getCurrentFrame(animation);
            unknown24 = static_cast<int>(mouseFrame + currentFrame);
            unknown28 = unknown20 - 1;
        }
        const int frameOffset = static_cast<int>(static_cast<float>(unknown24) + point.y / -20.0f);
        int pageOffset = frameOffset / 36;
        if (frameOffset < 0)
            --pageOffset;
        const int newPage = unknown96 ? (unknown28 + pageOffset) % (unknown96 + 4) : 0;
        if (unknown20 != newPage) {
            unknown20 = newPage;
            if (unknown20 < 0)
                unknown20 += unknown96 + 4;
            UpdateLocalization();
        }
        if (frameOffset < 0) {
            const int remainder = frameOffset % 36;
            unknown32 = 35 - (remainder < 0 ? -remainder : remainder);
        } else {
            unknown32 = frameOffset % 36;
        }
        renderFX->GotoFrame(animation, unknown32, false);
        break;
    }
    case 6:
        _ZN11MenuManager10clearFocusEv(MenuManager::getInstance());
        // Fall through to finish the gesture.
    case 1:
        if (getCharacterPlayState(animation) != 0)
            renderFX->GotoFrame(animation, unknown32, true);
        unknown24 = -1;
        unknown20 = unknown96 ? (unknown20 + (event.type != 6)) % (unknown96 + 4) : 0;
        break;
    }
    event.consumed = true;
}

#include "../meta/Achievements.h"

static const char statisticsEntryFormat[] = "widgetStatistics.anim.btnScroll.entry%d";

void Widgets::Statistics::UpdateLocalization()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    MenuManager* menu = MenuManager::getInstance();
    for (int row = 0; row < 7; ++row) {
        char name[128];
        int index = (unknown20 + row) % (unknown96 + 4);
        if (index < 0)
            index += unknown96 + 4;
        if (index < unknown96) {
            AchievementManager::Stat* stat = AchievementManager::s_achievementManager->getStatFromID(statisticIds[index]);
            sprintf(name, statisticsEntryFormat, row * 2);
            _ZN11MenuManager13setMenuFXTextEPKcS1_bb(menu, name, _ZNK13StringManager9getStringEi(strings, reinterpret_cast<const Structs::Stat*>(stat)->fields[2]), true, false);
            sprintf(name, statisticsEntryFormat, row * 2 + 1);
            char value[32];
            _ZN11MenuManager13setMenuFXTextEPKcS1_bb(menu, name, stat->formatString(value), true, false);
        } else {
            sprintf(name, statisticsEntryFormat, row * 2);
            _ZN11MenuManager13setMenuFXTextEPKcS1_bb(menu, name, localStartupEmptyText, false, false);
            sprintf(name, statisticsEntryFormat, row * 2 + 1);
            _ZN11MenuManager13setMenuFXTextEPKcS1_bb(menu, name, localStartupEmptyText, false, false);
        }
    }
}

void Widgets::Achievements::OnEvent(RenderFX::Event& event)
{
    if (strcmp(event.characterName, tutorialScrollButtonLabel) != 0)
        return;

    switch (event.type) {
    case 5: {
        const gameswf::matrix matrix = _ZN7gameswf9character16get_world_matrixEv(event.character);
        const gameswf::point& coordinates = *reinterpret_cast<const gameswf::point*>(event.unknown12);
        const float x = coordinates.x;
        const float y = coordinates.y;
        const gameswf::point input(x, y);
        gameswf::point point;
        matrix.transform(&point, input);

        if (unknown24 == -1) {
            const float mouseFrame = point.y / 20.0f;
            const float currentFrame = widgetAnimationMethods(animation).getCurrentFrame(animation);
            unknown24 = static_cast<int>(mouseFrame + currentFrame);
            unknown28 = unknown20 - 1;
        }
        const int frameOffset = static_cast<int>(static_cast<float>(unknown24) + point.y / -20.0f);
        int pageOffset = frameOffset / 70;
        if (frameOffset < 0)
            --pageOffset;
        const int newPage = unknown140 ? (unknown28 + pageOffset) % (unknown140 + 2) : 0;
        if (unknown20 != newPage) {
            unknown20 = newPage;
            if (unknown20 < 0)
                unknown20 += unknown140 + 2;
            UpdateLocalization();
        }
        if (frameOffset < 0) {
            const int remainder = frameOffset % 70;
            unknown32 = 69 - (remainder < 0 ? -remainder : remainder);
        } else {
            unknown32 = frameOffset % 70;
        }
        renderFX->GotoFrame(animation, unknown32, false);
        break;
    }
    case 6:
        _ZN11MenuManager10clearFocusEv(MenuManager::getInstance());
        // Fall through to finish the gesture.
    case 1:
        if (getCharacterPlayState(animation) != 0)
            renderFX->GotoFrame(animation, unknown32, true);
        unknown24 = -1;
        unknown20 = unknown140 ? (unknown20 + (event.type != 6)) % (unknown140 + 2) : 0;
        break;
    }
    event.consumed = true;
}

static const char mainButtonPrefix[] = "btnMain";
static const char mainTwitterButton[] = "btnTwitter";
static const char mainInfoButton[] = "btnInfo";
static const char mainMoreButton[] = "btnMore";

void Widgets::MainMenu::OnEvent(RenderFX::Event& event)
{
    MenuWidget::OnEvent(event);
    MenuManager::getInstance();
    switch (event.type) {
    case 6: {
        const char* name = event.characterName;
        if (strstr(name, mainButtonPrefix)) {
            pressedButton = name[7] - '0';
            if (buttons[pressedButton].enabled) {
                if (listener)
                    listener->Notify(this, 1);
            } else {
                SoundManager* sound = SoundManager::getInstance();
                sound->unknown140 = true;
                sound->playEx(215, 0, false, 1.0f, 0, true, 1.0f, 0);
                sound->unknown140 = false;
            }
            event.consumed = true;
        } else if (strcmp(name, mainTwitterButton) == 0) {
            if (listener)
                listener->Notify(this, 2);
            event.consumed = true;
        } else if (strcmp(name, mainInfoButton) == 0) {
            if (listener)
                listener->Notify(this, 3);
            event.consumed = true;
        } else if (strcmp(name, mainMoreButton) == 0) {
            if (listener)
                listener->Notify(this, 4);
            event.consumed = true;
        }
        break;
    }
    }
}

static const char volumesPlaylistPath[] = "widgetVolumes.playlist";

void Widgets::Volumes::Show()
{
    MenuWidget::Show();
    selectedPlaylist = s_playlist;
    renderFX->SetVisible(volumesPlaylistPath, SoundManager::getInstance()->canUseIPod());
    SoundManager::getInstance()->initIPod();
    UpdateLocalization();
    if (!SoundManager::getInstance()->isLowFpsMusicPlaying()) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(35, 0, true, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }
}

static const char arrowLeftLabel[] = "btnArrowLeft";
static const char arrowRightLabel[] = "btnArrowRight";

void Widgets::Arrows::OnEvent(RenderFX::Event& event)
{
    MenuWidget::OnEvent(event);
    switch (event.type) {
    case 6:
        const char* name = event.characterName;
        if (strcmp(name, arrowLeftLabel) == 0) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(220, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            if (pageCount > 0) {
                --currentPage;
                if (currentPage < 0)
                    currentPage = pageCount - 1;
            }
            event.consumed = true;
        } else if (strcmp(name, arrowRightLabel) == 0) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(220, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            if (pageCount > 0)
                currentPage = (currentPage + 1) % pageCount;
            event.consumed = true;
        }
        if (event.consumed) {
            UpdateLocalization();
            if (listener)
                listener->Notify(this, 1);
        }
        break;
    }
}

#include "../persistence/Persistence.h"
#include "Preferences.h"
extern "C" const char* _ZN8RenderFX5Event16GetCharacterPathEv(RenderFX::Event*) __attribute__((weak));
namespace {
struct VolumeBounds { float xmin, xmax, ymin, ymax; };
struct VolumeCharacterMethods {
    void (*slots[72])();
    void (*getBounds)(gameswf::character*, VolumeBounds*);
};
inline const float& volumeMin(const float& value, const float& high) { return value > high ? high : value; }
inline const float& volumeMax(const float& value, const float& low) { return value < low ? low : value; }
}
static const char volumesButton[] = "btnVolume";
static const char volumesMuteButton[] = "btnMute";
static const char volumesSfxPart[] = "barSFX";
static const char volumesMusicPart[] = "barMusic";
static const char volumesLeftButton[] = "btnLeft";
static const char volumesRightButton[] = "btnRight";
void Widgets::Volumes::OnEvent(RenderFX::Event& event)
{
    const char* path = _ZN8RenderFX5Event16GetCharacterPathEv(&event);
    switch (event.type) {
    case 4:
    case 5:
        if (strcmp(event.characterName, volumesButton) == 0) {
            VolumeBounds bounds;
            const VolumeCharacterMethods* methods = *reinterpret_cast<const VolumeCharacterMethods* const*>(event.character);
            methods->getBounds(event.character, &bounds);
            float volume = *reinterpret_cast<const float*>(event.unknown12) / (bounds.xmax - bounds.xmin) + 0.05f;
            volume = volumeMax(volumeMin(volume, 1.0f), 0.0f);
            if (strstr(path, volumesSfxPart))
                SoundManager::getInstance()->setSfxVolume(volume);
            else if (strstr(path, volumesMusicPart))
                SoundManager::getInstance()->setMusicVolume(volume);
            event.consumed = true;
        }
        break;
    case 1:
    case 6:
        if (!MenuManager::getInstance()->isClearingFocus()) {
            const char* name = event.characterName;
            if (strcmp(name, volumesButton) == 0) {
                if (strstr(path, volumesSfxPart)) {
                    SoundManager* sound = SoundManager::getInstance();
                    sound->unknown140 = true;
                    sound->playEx(225, 0, false, 1.0f, 0, true, 1.0f, 0);
                    sound->unknown140 = false;
                }
                _ZN11MenuManager10clearFocusEv(MenuManager::getInstance());
                event.consumed = true;
            } else if (event.type != 1) {
                if (strcmp(name, volumesMuteButton) == 0) {
                    if (strstr(path, volumesSfxPart)) {
                        SoundManager::getInstance()->setSfxVolume(0.0f);
                        event.consumed = true;
                    } else if (strstr(path, volumesMusicPart)) {
                        SoundManager::getInstance()->setMusicVolume(0.0f);
                        event.consumed = true;
                    }
                } else if (strcmp(name, volumesLeftButton) == 0) {
                    SoundManager* sound = SoundManager::getInstance();
                    sound->unknown140 = true;
                    sound->playEx(220, 0, false, 1.0f, 0, true, 1.0f, 0);
                    sound->unknown140 = false;
                    if (listener) listener->Notify(this, 1);
                    event.consumed = true;
                } else if (strcmp(name, volumesRightButton) == 0) {
                    SoundManager* sound = SoundManager::getInstance();
                    sound->unknown140 = true;
                    sound->playEx(220, 0, false, 1.0f, 0, true, 1.0f, 0);
                    sound->unknown140 = false;
                    if (listener) listener->Notify(this, 2);
                    event.consumed = true;
                }
            }
        }
        break;
    }
    if (event.consumed) {
        Preferences preferences;
        preferences.SampleAndSave(Preferences::GetDefaultFilename());
        UpdateLocalization();
    }
}

#include "../missions/Mission.h"
#include "../missions/MissionData.h"
#include "../scripting/Script.h"
#include "../scripting/ScriptManager.h"
static const char missionObjectivePath[] = "widgetMission.txtObjective";
static const char missionMessagePath[] = "widgetMission.txtMessage";
static const char missionLocationTitlePath[] = "widgetMission.txtLocationTitle";
static const char missionLocationValuePath[] = "widgetMission.txtLocationValue";
static const char missionTypeTitlePath[] = "widgetMission.txtTypeTitle";
static const char missionTypeValuePath[] = "widgetMission.txtTypeValue";
static const char missionCashTitlePath[] = "widgetMission.txtCashRewardTitle";
static const char missionCashValuePath[] = "widgetMission.txtCashRewardValue";
static const char missionIconPath[] = "widgetMission.iconNPC";
static const char missionButtonPath[] = "widgetMission.btnStartMission";
static const char missionButtonTextPath[] = "widgetMission.btnStartMission.text";

void Widgets::Mission::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    StringManager* strings=Application::GetInstance()->GetStringManager();
    ::Mission* missions=static_cast< ::Mission*>(ScriptManager::getInstance()->getMission());
    Structs::Mission* data=script ? missions->mission(script->getMissionId()) : 0;
    bool hasMission=data!=0;
    bool noMission=data==0;
    renderFX->SetVisible(missionObjectivePath,hasMission);
    renderFX->SetVisible(missionMessagePath,noMission);
    renderFX->SetVisible(missionLocationTitlePath,hasMission);
    renderFX->SetVisible(missionLocationValuePath,hasMission);
    renderFX->SetVisible(missionTypeTitlePath,hasMission);
    renderFX->SetVisible(missionTypeValuePath,hasMission);
    renderFX->SetVisible(missionCashTitlePath,hasMission);
    renderFX->SetVisible(missionCashValuePath,hasMission);
    renderFX->SetVisible(missionIconPath,hasMission);
    renderFX->SetEnabled(missionButtonPath,hasMission);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionButtonTextPath,_ZNK13StringManager9getStringEi(strings,0x103e),true);
    if (hasMission) {
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionObjectivePath,_ZNK13StringManager9getStringEi(strings,data->unknown28),true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionLocationTitlePath,_ZNK13StringManager9getStringEi(strings,0x103f),true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionLocationValuePath,_ZNK13StringManager9getStringEi(strings,data->unknown20),true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionTypeTitlePath,_ZNK13StringManager9getStringEi(strings,0x1040),true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionTypeValuePath,_ZNK13StringManager9getStringEi(strings,data->unknown32),true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionCashTitlePath,_ZNK13StringManager9getStringEi(strings,0x1043),true);
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionCashValuePath,strings->formatAmount(data->unknown4,false,true),true);
        renderFX->GotoFrame(missionIconPath,data->unknown12,false);
    } else {
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX,missionMessagePath,_ZNK13StringManager9getStringEi(strings,0x104b),true);
    }
}

static const char volumeSfxText[] = "widgetVolumes.txtSFX";
static const char volumeSfxSlider[] = "widgetVolumes.barSFX.btnVolume";
static const char volumeMuteOn[] = "on";
static const char volumeSfxMute[] = "widgetVolumes.barSFX.btnMute";
static const char volumeValueFormat[] = "%d";
static const char volumeSfxValue[] = "widgetVolumes.barSFX.txtVolume";
static const char volumeMusicText[] = "widgetVolumes.txtMusic";
static const char volumeMusicSlider[] = "widgetVolumes.barMusic.btnVolume";
static const char volumeMusicMute[] = "widgetVolumes.barMusic.btnMute";
static const char volumeMusicValue[] = "widgetVolumes.barMusic.txtVolume";
static const char volumePlaylistTitle[] = "widgetVolumes.playlist.txtTitle";
static const char volumePlaylistFormat[] = "<font face=\"fontall\">%s</font>";
static const char volumePlaylistValue[] = "widgetVolumes.playlist.txtValue";
static const char volumeMuteOff[] = "off";

void Widgets::Volumes::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    StringManager* strings = Application::GetInstance()->GetStringManager();
    SoundManager::getInstance();
    const float effects = SoundManager::getInstance()->effectsPlaybackVolume;
    const float music = SoundManager::getInstance()->playbackVolume;

    renderFX->SetText(volumeSfxText, _ZNK13StringManager9getStringEi(strings, 0x1013), true);
    renderFX->GotoFrame(volumeSfxSlider, static_cast<int>(effects * 10.0f), false);
    renderFX->GotoFrame(volumeSfxMute, effects ? volumeMuteOn : volumeMuteOff, false);
    _ZN8RenderFX10FormatTextEPKcS1_z(renderFX, volumeSfxValue, volumeValueFormat, static_cast<int>(effects * 100.0f));

    renderFX->SetText(volumeMusicText, _ZNK13StringManager9getStringEi(strings, 0x1012), true);
    renderFX->GotoFrame(volumeMusicSlider, static_cast<int>(music * 10.0f), false);
    renderFX->GotoFrame(volumeMusicMute, music ? volumeMuteOn : volumeMuteOff, false);
    _ZN8RenderFX10FormatTextEPKcS1_z(renderFX, volumeMusicValue, volumeValueFormat, static_cast<int>(music * 100.0f));

    renderFX->SetText(volumePlaylistTitle, _ZNK13StringManager9getStringEi(strings, 0x1014), true);
    char formatted[256];
    char playlistName[128];
    if (s_playlist == -2) {
        strcpy(playlistName, _ZNK13StringManager9getStringEi(strings, 0x1015));
    } else if (s_playlist == -1) {
        strcpy(playlistName, _ZNK13StringManager9getStringEi(strings, 0x1016));
    } else {
        SoundManager::getInstance()->getPlaylistName(s_playlist, playlistName);
        const gameswf::tu_string name(playlistName);
        if (name.utf8_length() > 20) {
            const gameswf::tu_string shortened = name.utf8_substring(0, 17);
            strcpy(playlistName, shortened.c_str());
            int end = strlen(playlistName);
            if (playlistName[end - 1] == ' ')
                --end;
            playlistName[end++] = '.';
            playlistName[end++] = '.';
            playlistName[end++] = '.';
            playlistName[end] = 0;
        }
    }
    sprintf(formatted, volumePlaylistFormat, playlistName);
    renderFX->SetText(volumePlaylistValue, formatted, true);
}


extern "C" bool _ZNK11MenuManager14getTutorialIdsERiS0_(const MenuManager*, int& title, int& body);

namespace {
// Authentic get_name const-reference API adapted to observed retail name+136.
// Partial field view only, never constructed or copied; no complete character claim.
struct TutorialLocalizationNameFields {
    unsigned char opaque[136];
    gameswf::tu_string name;
    const gameswf::tu_string& get_name() const { return name; }
};

struct TutorialTextMethods {
    void (*beforeGetMember[8])();
    bool (*getMember)(gameswf::character*, const gameswf::tu_stringi&, gameswf::as_value*);
};

inline const TutorialTextMethods& tutorialTextMethods(const gameswf::character* character)
{
    return **reinterpret_cast<const TutorialTextMethods* const*>(character);
}
}

static const char tutorialTitleSuffix[] = ".group.txtTitle";
static const char tutorialContentSuffix[] = ".group.btnScroll.txtContent";
static const char tutorialTextHeightName[] = "textHeight";

void Widgets::Tutorial::UpdateLocalization()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    int title, body;
    _ZNK11MenuManager14getTutorialIdsERiS0_(MenuManager::getInstance(), title, body);
    char name[128];
    const TutorialLocalizationNameFields& characterName = *reinterpret_cast<const TutorialLocalizationNameFields*>(character);
    const char* titleName = characterName.get_name().c_str();
    sprintf(name, tutorialPartFormat, titleName, tutorialTitleSuffix);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, name, _ZNK13StringManager9getStringEi(strings, title), true);
    sprintf(name, tutorialPartFormat, reinterpret_cast<const TutorialLocalizationNameFields*>(character)->get_name().c_str(), tutorialContentSuffix);
    gameswf::character* content = renderFX->Find(name);
    renderFX->SetText(content, _ZNK13StringManager9getStringEi(strings, body), true);
    gameswf::as_value height;
    tutorialTextMethods(content).getMember(content, gameswf::tu_stringi(tutorialTextHeightName), &height);
    unknown36 = static_cast<int>(height.to_number());
    sprintf(name, tutorialPartFormat, reinterpret_cast<const TutorialLocalizationNameFields*>(character)->get_name().c_str(), tutorialScrollPart);
    renderFX->GotoFrame(name, 0, false);
    sprintf(name, tutorialPartFormat, reinterpret_cast<const TutorialLocalizationNameFields*>(character)->get_name().c_str(), tutorialArrowUpPart);
    renderFX->SetVisible(name, false);
    sprintf(name, tutorialPartFormat, reinterpret_cast<const TutorialLocalizationNameFields*>(character)->get_name().c_str(), tutorialArrowDownPart);
    renderFX->SetVisible(name, unknown36 > 75);
}

static const char confirmMessageFormat[] = "%s.txtMessage";
static const char confirmYesFormat[] = "%s.btnYes.text";
static const char confirmNoFormat[] = "%s.btnNo.text";

void Widgets::Confirm::UpdateLocalization()
{
    StringManager* strings = Application::GetInstance()->GetStringManager();
    char name[128];
    if (GetMessageId() != -1) {
        sprintf(name, confirmMessageFormat, reinterpret_cast<const TutorialLocalizationNameFields*>(character)->get_name().c_str());
        _ZN8RenderFX7SetTextEPKcS1_b(renderFX, name, _ZNK13StringManager9getStringEi(strings, GetMessageId()), true);
    }
    sprintf(name, confirmYesFormat, reinterpret_cast<const TutorialLocalizationNameFields*>(character)->get_name().c_str());
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, name, _ZNK13StringManager9getStringEi(strings, 0x1029), true);
    sprintf(name, confirmNoFormat, reinterpret_cast<const TutorialLocalizationNameFields*>(character)->get_name().c_str());
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, name, _ZNK13StringManager9getStringEi(strings, 0x102a), true);
}

#include "../hud/CHudManager.h"


static const char controlsSteeringTitle[] = "widgetControls.steering.txtTitle";
static const char controlsSteeringValue[] = "widgetControls.steering.txtValue";
static const char controlsThrottleTitle[] = "widgetControls.throttle.txtTitle";
static const char controlsThrottleValue[] = "widgetControls.throttle.txtValue";

void Widgets::Controls::UpdateLocalization()
{
    MenuWidget::UpdateLocalization();
    Application* application = Application::GetInstance();
    if (selection == -1) {
        const int steering = static_cast<int>(application->GetHudManager()->steeringMode);
        for (int i = 0; i < 3; ++i) {
            if (s_choiceSteerings[i].value == steering) {
                selection = i;
                break;
            }
        }
    }
    if (previousSelection == -1) {
        const int throttle = static_cast<int>(application->GetHudManager()->throttleMode);
        for (int i = 0; i < 2; ++i) {
            if (s_choiceThrottles[i].value == throttle) {
                previousSelection = i;
                break;
            }
        }
    }

    StringManager* strings = Application::GetInstance()->GetStringManager();
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, controlsSteeringTitle, _ZNK13StringManager9getStringEi(strings, 0x1018), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, controlsSteeringValue, _ZNK13StringManager9getStringEi(strings, s_choiceSteerings[selection].textId), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, controlsThrottleTitle, _ZNK13StringManager9getStringEi(strings, 0x1019), true);
    _ZN8RenderFX7SetTextEPKcS1_b(renderFX, controlsThrottleValue, _ZNK13StringManager9getStringEi(strings, s_choiceThrottles[previousSelection].textId), true);
}

void Widgets::GameSetting::OnEvent(RenderFX::Event& event)
{
    MenuWidget::OnEvent(event);
    if (listener) switch (event.type) {
    case 6: {
        const char* name = event.characterName;
        SoundManager* sound;
        if (strcmp(name, volumesLeftButton) == 0) {
            sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(220, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            listener->Notify(this, 2);
            event.consumed = true;
        } else if (strcmp(name, volumesRightButton) == 0) {
            sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(220, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            listener->Notify(this, 3);
            event.consumed = true;
        } else if (strcmp(name, tutorialOkButton) == 0) {
            sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(214, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            listener->Notify(this, 1);
            event.consumed = true;
        }
        break;
    }
    }
}

#include "GSInGameMenu.h"

namespace {
struct MissionTeleportCommand {
    int opcode;
    const char* objectName;
};
}

static const char startMissionButton[] = "btnStartMission";
static const char missionMapName[] = "Map";

void Widgets::Mission::OnEvent(RenderFX::Event& event)
{
    switch (event.type) {
    case 6:
        if (strcmp(event.characterName, startMissionButton) == 0) {

    if (script) {
        const MissionTeleportCommand* command = reinterpret_cast<const MissionTeleportCommand*>(script->peekCommand(0));
        if (command->opcode == 64) {
            LevelObject* object = ScriptManager::findObject(command->objectName, false);
            if (object) {
                PlayerTest::GetPlayer()->teleportTo(object);
                GSInGameMenu::skipFadeIn();
                ScriptManager::getInstance()->missionSkipFadeOut();
            }
        }
        MenuManager::getInstance()->popTo(missionMapName, true, true);
        ScriptManager::getInstance()->finishReviveAnims();
    }
    event.consumed = true;
        }
        break;
    }
}
