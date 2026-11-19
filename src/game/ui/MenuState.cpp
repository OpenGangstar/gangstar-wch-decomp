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
#include "../core/NativeStdio.h"
#include "../core/NativeStrings.h"
#include "../ai/StateMachine.h"
#include "MenuDialogs.h"
#include "MainMenu.h"
#include "../hud/MenuManager.h"
#include "../hud/CHudManager.h"
#include "../meta/Achievements.h"
#include "../audio/SoundManager.h"
#include "../app/Application.h"
#include "../persistence/DataStream.h"
#include "../persistence/FileStream.h"
#include "../persistence/SaveGame.h"
#include "../world/ResStream.h"
#include "../rendering/GS3DStuff.h"
#include "../scripting/ScriptManager.h"
#include "../missions/Mission.h"
#include "../characters/PlayerTest.h"

extern "C" {
void _ZN11MenuManager3popEb(MenuManager* manager, bool restoreFocus);
void _ZN11MenuManager10clearFocusEv(MenuManager* manager);
void _ZN11MenuManager17allowCheatsUnlockEb(MenuManager* manager, bool allow);
void _ZN7Widgets5Title7SetIconEPKc(void* title, const char* icon);
void _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(void* menu, int button, bool active);
void _ZN7Widgets6IGMenu11HideButtonsEv(void* menu);
void _ZN7Widgets6IGMenu12SetTitleTextEi(void* menu, int text);
void _ZN7Widgets6Arrows12SetPageCountEiib(MenuWidget* arrows, int count, int page, bool enabled);
void _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(void* menu, int button, int text, bool enabled);
void _ZN7Widgets6IGMenu17SetBackButtonTextEi(void* menu, int text);
void _ZN7Widgets6IGMenu9GoToFrameEPKc(void* menu, const char* frame);
void _ZN7Widgets8BlackBox8SetStateENS0_6eStateE(void* box, int state);
extern int _ZN11MenuManager20s_CarRentalDataCountE;
bool _ZN9GSLoading12isGameLoadedEv();
void _ZN7Widgets7Volumes11SetPlaylistEi(MenuWidget* widget, int playlist);
void _ZN7Widgets10Corruption14SetWantedLevelEi(MenuWidget* widget, int level);
}

namespace Menus {
} // namespace Menus
#include "InGameMenu.h"
namespace Menus {


class Infos : public InGameMenu {
public:
    explicit Infos(const char* name);
    virtual inline ~Infos() __attribute__((used));
    virtual void GotFocus();
    virtual void Update();
    virtual bool Notify(const MenuWidget* widget, int event);

protected:
    bool unknown104;
    bool unknown105;
};

class InfoStatistics : public Infos {
public:
    InfoStatistics();
    virtual ~InfoStatistics();
    virtual void GotFocus();
    virtual void OnFSCommand(const char* command, const char* args);
};

class InfoAchievements : public Infos {
public:
    InfoAchievements();
    virtual ~InfoAchievements();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void OnFSCommand(const char* command, const char* args);
    virtual bool Notify(const MenuWidget* widget, int event);
};

class InfoAbout : public Infos {
public:
    InfoAbout();
    virtual ~InfoAbout();
    virtual void GotFocus();
    virtual void OnFSCommand(const char* command, const char* args);
};

class InfoHelp : public Infos {
public:
    InfoHelp();
    virtual ~InfoHelp();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

struct HelpCategory {
    int title;
    int firstPage;
    int endPage;
};

static const HelpCategory s_helpCategories[] = {
    {4193, 4194, 4195},
    {4196, 4197, 4200},
    {4201, 4202, 4205},
    {4206, 4207, 4208},
    {4209, 4210, 4212},
    {4219, 4220, 4221},
};
static int s_helpPageCount;

} // namespace Menus
#include "OptionGameSettings.h"
namespace Menus {


class OptionLanguage : public Options {
public:
    OptionLanguage();
    virtual ~OptionLanguage();
    virtual void GotFocus();
};

class OptionControls : public Options {
public:
    OptionControls();
    virtual ~OptionControls();
    virtual void GotFocus();
};

class OptionVolumes : public Options {
public:
    OptionVolumes();
    virtual ~OptionVolumes();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);

protected:
    int selectedChannel;
};

class Services : public InGameMenu {
public:
    explicit Services(const char* name);
    virtual inline ~Services() __attribute__((used));
    virtual void GotFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

class ServiceCorruption : public Services {
public:
    ServiceCorruption();
    virtual ~ServiceCorruption();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

class ServiceMissions : public Services {
public:
    ServiceMissions();
    virtual ~ServiceMissions();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

class Tutorial : public MenuState {
public:
    explicit Tutorial(const char* name);
    virtual inline ~Tutorial();
    virtual void Show();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};



class Splash : public MenuState {
public:
    Splash();
    virtual ~Splash();
};

class ServiceCarRental : public Services {
public:
    explicit ServiceCarRental(const char* name);
    virtual inline ~ServiceCarRental() __attribute__((used));
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual bool Notify(const MenuWidget* widget, int event);

protected:
    float scale;
    int selectedVehicle;
};

class ServiceWeaponShop : public Services {
public:
    explicit ServiceWeaponShop(const char* name);
    void Refresh();
    virtual inline ~ServiceWeaponShop() __attribute__((used));
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual bool Notify(const MenuWidget* widget, int event);

protected:
    float scale;
    bool inGame;
    int selectedWeapon;
};

class Map : public InGameMenu {
public:
    Map();
    virtual ~Map();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual void OnEvent(RenderFX::Event& event);
    virtual bool Notify(const MenuWidget* widget, int event);

protected:
    bool unknown104;
    bool unknown105;
    int inputDelay;
};

class Achievement : public MenuState {
public:
    Achievement();
    void SetAchievement(const AchievementManager::Achievement* achievement);
    virtual ~Achievement();
    virtual void Show();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();

protected:
    int displayTime;
};

class BlockingTutorial : public Tutorial {
public:
    BlockingTutorial();
    virtual ~BlockingTutorial();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

class InGameCarRental : public ServiceCarRental {
public:
    InGameCarRental();
    virtual ~InGameCarRental();
    virtual void Hide();
    virtual void GotFocus();
};

class InGameWeaponShop : public ServiceWeaponShop {
public:
    InGameWeaponShop();
    virtual ~InGameWeaponShop();
    virtual void Hide();
    virtual void GotFocus();
};

class CopBribe : public ConfirmPayment {
public:
    CopBribe();
    virtual ~CopBribe();
};

class CarRepair : public ConfirmPayment {
public:
    CarRepair();
    virtual ~CarRepair();
};
}

Menus::InGameMenu::InGameMenu(const char* name)
    : MenuState(name)
{
    int ids[2];
    ids[0] = 27;
    ids[1] = 1;
    widgetIds.append(ids, 2);
}

Menus::Infos::Infos(const char* name)
    : InGameMenu(name), unknown104(false)
{
    int ids[2];
    ids[0] = 17;
    ids[1] = 19;
    widgetIds.append(ids, 2);
}

static const char infoStatisticsName[] = "InfoStatistics";

Menus::InfoStatistics::InfoStatistics()
    : Infos(infoStatisticsName)
{
    unknown105 = true;
    const int widgetId = 12;
    widgetIds.append(&widgetId, 1);
}

static const char infoAchievementsName[] = "InfoAchievements";

Menus::InfoAchievements::InfoAchievements()
    : Infos(infoAchievementsName)
{
    unknown105 = true;
    int ids[3];
    ids[0] = 11;
    ids[1] = 18;
    ids[2] = 15;
    widgetIds.append(ids, 3);
}

static const char infoAboutName[] = "InfoAbout";

Menus::InfoAbout::InfoAbout()
    : Infos(infoAboutName)
{
    unknown105 = true;
    const int widgetId = 14;
    widgetIds.append(&widgetId, 1);
}

static const char infoHelpName[] = "InfoHelp";

Menus::InfoHelp::InfoHelp()
    : Infos(infoHelpName)
{
    int ids[3];
    ids[0] = 18;
    ids[1] = 15;
    ids[2] = 13;
    widgetIds.append(ids, 3);
    if (s_helpPageCount == 0) {
        for (unsigned i = 0; i < sizeof(s_helpCategories) / sizeof(s_helpCategories[0]); ++i)
            s_helpPageCount += s_helpCategories[i].endPage - s_helpCategories[i].firstPage;
    }
}

Menus::Options::Options(const char* name)
    : InGameMenu(name)
{
    int ids[2];
    ids[0] = 17;
    ids[1] = 19;
    widgetIds.append(ids, 2);
}

static const char optionGameSettingsName[] = "OptionGameSettings";
static const char scriptChapterStartupPath[] = "./ScriptChapterStartup.array";

Menus::OptionGameSettings::OptionGameSettings()
    : Options(optionGameSettingsName)
{
    int ids[2];
    ids[0] = 18;
    ids[1] = 26;
    widgetIds.append(ids, 2);
    memset(selections, 0, sizeof(selections));
    ResStream resource(scriptChapterStartupPath, 1);
    DataStream stream(resource, DataStream::BigEndian);
    const int count = stream.ReadInt();
    int* chapter = chapterStartup;
    for (int i = 0; i < count; ++i)
        *chapter++ = stream.ReadInt();
    stream.Stream::Close();
}

static const char optionLanguageName[] = "OptionLanguage";

Menus::OptionLanguage::OptionLanguage()
    : Options(optionLanguageName)
{
    const int widgetId = 9;
    widgetIds.append(&widgetId, 1);
}

static const char optionControlsName[] = "OptionControls";

Menus::OptionControls::OptionControls()
    : Options(optionControlsName)
{
    const int widgetId = 8;
    widgetIds.append(&widgetId, 1);
}

static const char optionVolumesName[] = "OptionVolumes";

Menus::OptionVolumes::OptionVolumes()
    : Options(optionVolumesName), selectedChannel(-2)
{
    const int widgetId = 7;
    widgetIds.append(&widgetId, 1);
}

Menus::Services::Services(const char* name)
    : InGameMenu(name)
{
    int ids[2];
    ids[0] = 17;
    ids[1] = 19;
    widgetIds.append(ids, 2);
}

static const char serviceCorruptionName[] = "ServiceCorruption";

Menus::ServiceCorruption::ServiceCorruption()
    : Services(serviceCorruptionName)
{
    int ids[2];
    ids[0] = 16;
    ids[1] = 5;
    widgetIds.append(ids, 2);
}

static const char serviceMissionsName[] = "ServiceMissions";

Menus::ServiceMissions::ServiceMissions()
    : Services(serviceMissionsName)
{
    int ids[3];
    ids[0] = 6;
    ids[1] = 18;
    ids[2] = 15;
    widgetIds.append(ids, 3);
}

Menus::Tutorial::Tutorial(const char* name)
    : MenuState(name)
{
    const int widgetId = 23;
    widgetIds.append(&widgetId, 1);
}

namespace {
inline int findWidgetId(const gameswf::array<int>& ids, int id)
{
    for (int i = 0; i < ids.size; ++i) {
        if (ids.elements[i] == id)
            return i;
    }
    return -1;
}
}

static const char mainMenuName[] = "MainMenu";

bool Menus::MainMenu::GameContinue() const
{
    return unknown104;
}

Menus::MainMenu::MainMenu()
    : MenuState(mainMenuName), unknown104(false), unknown105(false), unknown106(false)
{
    int ids[2];
    ids[0] = 0;
    ids[1] = 20;
    widgetIds.append(ids, 2);
}

static const char splashName[] = "Splash";

Menus::Splash::Splash()
    : MenuState(splashName)
{
    const int widgetId = 25;
    widgetIds.append(&widgetId, 1);
}

Menus::ServiceCarRental::ServiceCarRental(const char* name)
    : Services(name), scale(1.0f), selectedVehicle(-1)
{
    int ids[3];
    ids[0] = 16;
    ids[1] = 3;
    ids[2] = 18;
    widgetIds.append(ids, 3);
}

Menus::ServiceWeaponShop::ServiceWeaponShop(const char* name)
    : Services(name), scale(1.0f), inGame(false), selectedWeapon(-1)
{
    int ids[] = {17, 16, 3, 18};
    widgetIds.append(ids, 4);
}

static const char mapName[] = "Map";

Menus::Map::Map()
    : InGameMenu(mapName), unknown104(false), unknown105(false), inputDelay(0)
{
    int ids[2];
    ids[0] = 2;
    ids[1] = 4;
    widgetIds.append(ids, 2);
}

static const char achievementName[] = "Achievement";

Menus::Achievement::Achievement()
    : MenuState(achievementName), displayTime(0)
{
    const int widgetId = 10;
    widgetIds.append(&widgetId, 1);
}

static const char blockingTutorialName[] = "BlockingTutorial";

Menus::BlockingTutorial::BlockingTutorial()
    : Tutorial(blockingTutorialName)
{
    gameswf::array<int>* ids = &widgetIds;
    const int index = findWidgetId(*ids, 23);
    if (index >= 0)
        ids->remove(index);
    const int widgetId = 24;
    ids->append(&widgetId, 1);
}

static const char inGameCarRentalName[] = "InGameCarRental";

Menus::InGameCarRental::InGameCarRental()
    : ServiceCarRental(inGameCarRentalName)
{
    gameswf::array<int>* ids = &widgetIds;
    const int index = findWidgetId(*ids, 19);
    if (index >= 0)
        ids->remove(index);
    scale = 0.75f;
}

static const char inGameWeaponShopName[] = "InGameWeaponShop";

Menus::InGameWeaponShop::InGameWeaponShop()
    : ServiceWeaponShop(inGameWeaponShopName)
{
    gameswf::array<int>* ids = &widgetIds;
    const int index = findWidgetId(*ids, 19);
    if (index >= 0)
        ids->remove(index);
    scale = 0.75f;
    inGame = true;
}

static const char copBribeName[] = "CopBribe";

Menus::CopBribe::CopBribe()
    : ConfirmPayment(copBribeName)
{
}

static const char carRepairName[] = "CarRepair";

Menus::CarRepair::CarRepair()
    : ConfirmPayment(carRepairName)
{
}

Menus::MainMenu::~MainMenu()
{
}

Menus::Splash::~Splash()
{
}

inline Menus::ServiceCarRental::~ServiceCarRental()
{
}

inline Menus::ServiceWeaponShop::~ServiceWeaponShop()
{
}

Menus::Map::~Map()
{
}

Menus::Achievement::~Achievement()
{
}

Menus::InGameCarRental::~InGameCarRental()
{
}

Menus::InGameWeaponShop::~InGameWeaponShop()
{
}

Menus::CopBribe::~CopBribe()
{
}

Menus::CarRepair::~CarRepair()
{
}

inline Menus::InGameMenu::~InGameMenu()
{
}

inline Menus::Infos::~Infos()
{
}

inline Menus::Options::~Options()
{
}

inline Menus::Services::~Services()
{
}

inline Menus::Tutorial::~Tutorial()
{
}

Menus::BlockingTutorial::~BlockingTutorial()
{
}

void MenuState::Show()
{
    depth = MenuManager::getInstance()->getDepth();
}

void Menus::Tutorial::Show()
{
    MenuState::Show();
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(213, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
}

Menus::InfoStatistics::~InfoStatistics()
{
}

Menus::InfoAchievements::~InfoAchievements()
{
}

Menus::InfoHelp::~InfoHelp()
{
}

Menus::InfoAbout::~InfoAbout()
{
}

Menus::OptionGameSettings::~OptionGameSettings()
{
}

Menus::OptionLanguage::~OptionLanguage()
{
}

Menus::OptionControls::~OptionControls()
{
}

Menus::OptionVolumes::~OptionVolumes()
{
}

Menus::ServiceCorruption::~ServiceCorruption()
{
}

Menus::ServiceMissions::~ServiceMissions()
{
}

void MenuFX::State::Create()
{
}

MenuState::~MenuState()
{
    widgetIds.release_buffer();
}

inline Menus::Dialog::~Dialog()
{
}

inline Menus::Confirm::~Confirm()
{
}

inline Menus::ConfirmPayment::~ConfirmPayment()
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

void MenuState::LostFocus()
{
}

namespace {
struct MenuWidgetTable {
    unsigned char prefix[0x1a4];
    void** widgets;
    int count;
};

inline void* getWidgetByIndex(MenuManager* manager, int index)
{
    const MenuWidgetTable& table =
        *reinterpret_cast<const MenuWidgetTable*>(manager);
    return index < table.count ? table.widgets[index] : 0;
}

inline void* getWidgetByIndex(int index)
{
    return getWidgetByIndex(MenuManager::getInstance(), index);
}
}

void Menus::InGameMenu::GotFocus()
{
    MenuState::GotFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(1))->SetListener(this);
}

void Menus::InfoStatistics::GotFocus()
{
    Infos::GotFocus();
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(1), 1, true);
}

void Menus::InfoAchievements::GotFocus()
{
    Infos::GotFocus();
    MenuManager* manager = MenuManager::getInstance();
    MenuWidget* arrows = static_cast<MenuWidget*>(getWidgetByIndex(manager, 18));
    arrows->SetListener(this);
    _ZN7Widgets6Arrows12SetPageCountEiib(arrows, 3, 0, !unknown104);
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), 0, true);
}

void Menus::InfoAbout::GotFocus()
{
    Infos::GotFocus();
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(1), 3, true);
}

void Menus::InfoHelp::GotFocus()
{
    Infos::GotFocus();
    MenuManager* manager = MenuManager::getInstance();
    MenuWidget* arrows = static_cast<MenuWidget*>(getWidgetByIndex(manager, 18));
    arrows->SetListener(this);
    _ZN7Widgets6Arrows12SetPageCountEiib(arrows, s_helpPageCount, 0, !unknown104);
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), 2, true);
}

static const char fourButtonMenuFrame[] = "Show4";
static const char infosMenuFrame[] = "Show5";

namespace {
template <int first, int second, int third, int fourth, int title, bool showFifthSlot>
inline void configureFourButtonMenu(MenuManager* manager)
{
    void* menu = getWidgetByIndex(manager, 1);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 0, first, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 1, second, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 2, third, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 3, fourth, true);
    _ZN7Widgets6IGMenu12SetTitleTextEi(menu, title);
    _ZN7Widgets6IGMenu17SetBackButtonTextEi(menu, 0x1027);
    _ZN7Widgets6IGMenu9GoToFrameEPKc(menu, showFifthSlot ? infosMenuFrame : fourButtonMenuFrame);
    _ZN7Widgets8BlackBox8SetStateENS0_6eStateE(getWidgetByIndex(manager, 27), 0);
}
}

void Menus::Infos::GotFocus()
{
    InGameMenu::GotFocus();
    MenuManager* manager = MenuManager::getInstance();
    static_cast<MenuState*>(manager->getState(mapName))->GetDepth();
    configureFourButtonMenu<0x105e, 0x105f, 0x1060, 0x100e, 0x1037, true>(manager);
}

void Menus::Options::GotFocus()
{
    InGameMenu::GotFocus();
    configureFourButtonMenu<0x1011, 0x100d, 0x1000, 0x1017, 0x1036, false>(MenuManager::getInstance());
}

void Menus::Services::GotFocus()
{
    InGameMenu::GotFocus();
    configureFourButtonMenu<0x103d, 0x1039, 0x103a, 0x103c, 0x1035, false>(MenuManager::getInstance());
}

namespace {
inline __attribute__((always_inline)) int settingsPageCount(const MenuManager* manager)
{
    return _ZN9GSLoading12isGameLoadedEv() && manager->areCheatsUnlocked() ? 7 : 1;
}
}

Menus::OptionGameSettings::stGameSetting::eOrientation Menus::OptionGameSettings::GetOrientation()
{
    if (GS3DStuff::b_isAutoOri)
        return stGameSetting::OrientationAuto;
    return GS3DStuff::s_orientation == 3 ? stGameSetting::Orientation0 : stGameSetting::Orientation1;
}

void Menus::OptionGameSettings::SetOrientation(stGameSetting::eOrientation)
{
    GS3DStuff::SetCurrentOrientation(irr::video::OrthoOrientation0);
    GS3DStuff::b_isAutoOri = false;
}

void Menus::OptionGameSettings::SetOrientation(int orientation)
{
    SetOrientation(static_cast<stGameSetting::eOrientation>(orientation));
}

void Menus::OptionGameSettings::Refresh()
{
    MenuManager* manager = MenuManager::getInstance();
    MenuWidget* arrows = static_cast<MenuWidget*>(getWidgetByIndex(manager, 18));
    _ZN7Widgets6Arrows12SetPageCountEiib(arrows, settingsPageCount(manager), 0, true);
}

void Menus::OptionGameSettings::GotFocus()
{
    Options::GotFocus();
    MenuManager* manager = MenuManager::getInstance();
    _ZN11MenuManager17allowCheatsUnlockEb(manager, true);
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), 3, true);
    MenuWidget* arrows = static_cast<MenuWidget*>(getWidgetByIndex(manager, 18));
    arrows->SetListener(this);
    _ZN7Widgets6Arrows12SetPageCountEiib(arrows, settingsPageCount(manager), 0, true);
    static_cast<MenuWidget*>(getWidgetByIndex(manager, 26))->SetListener(this);
}

void Menus::OptionLanguage::GotFocus()
{
    Options::GotFocus();
    MenuManager* manager = MenuManager::getInstance();
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), 2, true);
    static_cast<MenuWidget*>(getWidgetByIndex(manager, 9))->SetListener(this);
}

void Menus::OptionControls::GotFocus()
{
    Options::GotFocus();
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(1), 1, true);
}

void Menus::OptionVolumes::GotFocus()
{
    MenuManager* manager = MenuManager::getInstance();
    MenuWidget* volumes = static_cast<MenuWidget*>(getWidgetByIndex(manager, 7));
    _ZN7Widgets7Volumes11SetPlaylistEi(volumes, selectedChannel);
    volumes->SetListener(this);
    Options::GotFocus();
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), 0, true);
}

namespace {
template <int button, int& itemCount>
inline void configureShopWidgets(MenuState* state, const int& selectedItem)
{
    MenuManager* manager = MenuManager::getInstance();
    static_cast<MenuWidget*>(getWidgetByIndex(manager, 3))->SetListener(state);
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), button, true);
    MenuWidget* arrows = static_cast<MenuWidget*>(getWidgetByIndex(manager, 18));
    arrows->SetListener(state);
    const int count = itemCount;
    const int page = selectedItem < 0 ? 0 : selectedItem / 4;
    const int pages = (count - 1) / 4 + 1;
    _ZN7Widgets6Arrows12SetPageCountEiib(arrows, pages, page, true);
}
}

void Menus::ServiceCorruption::GotFocus()
{
    Services::GotFocus();
    MenuManager* manager = MenuManager::getInstance();
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), 3, true);
    MenuWidget* corruption = static_cast<MenuWidget*>(getWidgetByIndex(manager, 5));
    corruption->SetListener(this);
    _ZN7Widgets10Corruption14SetWantedLevelEi(corruption, WantedLevelManager::getInstance()->unknown8);
}

void Menus::ServiceCarRental::GotFocus()
{
    Services::GotFocus();
    configureShopWidgets<2, _ZN11MenuManager20s_CarRentalDataCountE>(this, selectedVehicle);
}

void Menus::ServiceWeaponShop::GotFocus()
{
    Services::GotFocus();
    configureShopWidgets<1, MenuManager::s_WeaponShopDataCount>(this, selectedWeapon);
}

void Menus::InGameCarRental::GotFocus()
{
    ServiceCarRental::GotFocus();
    void* menu = getWidgetByIndex(1);
    _ZN7Widgets6IGMenu11HideButtonsEv(menu);
    _ZN7Widgets6IGMenu12SetTitleTextEi(menu, 0x103a);
}

void Menus::InGameWeaponShop::GotFocus()
{
    ServiceWeaponShop::GotFocus();
    void* menu = getWidgetByIndex(1);
    _ZN7Widgets6IGMenu11HideButtonsEv(menu);
    _ZN7Widgets6IGMenu12SetTitleTextEi(menu, 0x3020);
}

void Menus::Achievement::GotFocus()
{
    MenuState::GotFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(10))->SetListener(this);
}

void Menus::OptionVolumes::LostFocus()
{
    Options::GotFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(7))->SetListener(0);
}

extern "C" void _ZN7Widgets8MainMenu13SetButtonInfoENS0_7eButtonEibb(void*, int, int, bool, bool);

void Menus::MainMenu::GotFocus()
{
    MenuState::GotFocus();
    MenuWidget* menu = static_cast<MenuWidget*>(getWidgetByIndex(0));
    menu->SetListener(this);
    _ZN7Widgets8MainMenu13SetButtonInfoENS0_7eButtonEibb(menu, 0, 0x1025, FileStream::Exist(SaveGame::GetDefaultFilename()), true);
    _ZN7Widgets8MainMenu13SetButtonInfoENS0_7eButtonEibb(menu, 1, 0x1022, true, true);
    _ZN7Widgets8MainMenu13SetButtonInfoENS0_7eButtonEibb(menu, 2, 0x102e, true, true);
    _ZN7Widgets8MainMenu13SetButtonInfoENS0_7eButtonEibb(menu, 3, 0x101d, true, true);
}

extern "C" {
void nativeNotifyPause();
void nativeExit();
void _ZN11Application4QuitEv(Application*);
void* _ZN12StateMachine11getInstanceEv() __attribute__((weak));
void* _ZN12StateMachine11switchStateI9GSLoadingEEPT_v(void*) __attribute__((weak));
}

namespace {
const char confirmMenuName[] __attribute__((section(".rodata.main_menu_confirm"))) = "Confirm";
}
void Menus::MainMenu::Update()
{
    MenuState::Update();
    if (unknown105) {
        unknown105 = false;
        Confirm* confirmation = static_cast<Confirm*>(MenuManager::getInstance()->getState(confirmMenuName));
        if (confirmation->Confirmed()) {
            unknown104 = false;
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(214, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            _ZN12StateMachine11switchStateI9GSLoadingEEPT_v(_ZN12StateMachine11getInstanceEv());
        } else {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(219, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        }
    }
    if (unknown106) {
        unknown106 = false;
        Confirm* confirmation = static_cast<Confirm*>(MenuManager::getInstance()->getState(confirmMenuName));
        if (confirmation->Confirmed()) {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(214, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
            _ZN11Application4QuitEv(Application::GetInstance());
            nativeExit();
        } else {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(219, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        }
    } else if (paused) {
        paused = false;
        MenuManager::getInstance()->getState(confirmMenuName);
        nativeNotifyPause();
    }
}

void Menus::MainMenu::SetPause(bool value)
{
    paused = value;
}

void Menus::MainMenu::LostFocus()
{
    MenuState::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(0))->SetListener(0);
}

void Menus::ServiceMissions::LostFocus()
{
    MenuState::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(18))->SetListener(0);
}

void Menus::Map::LostFocus()
{
    MenuState::LostFocus();
    MenuManager::getInstance()->cleanupMap();
}

void Menus::InGameMenu::LostFocus()
{
    MenuState::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(1))->SetListener(0);
}

void Menus::InfoAchievements::LostFocus()
{
    _ZN7Widgets5Title7SetIconEPKc(getWidgetByIndex(15), 0);
    InGameMenu::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(18))->SetListener(0);
}

void Menus::InfoHelp::LostFocus()
{
    InGameMenu::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(18))->SetListener(0);
}

void Menus::OptionGameSettings::LostFocus()
{
    InGameMenu::LostFocus();
    MenuManager* manager = MenuManager::getInstance();
    _ZN11MenuManager17allowCheatsUnlockEb(manager, false);
    static_cast<MenuWidget*>(getWidgetByIndex(manager, 18))->SetListener(0);
    static_cast<MenuWidget*>(getWidgetByIndex(manager, 26))->SetListener(0);
}

void Menus::ServiceCorruption::LostFocus()
{
    InGameMenu::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(5))->SetListener(0);
}

void Menus::ServiceCarRental::LostFocus()
{
    InGameMenu::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(18))->SetListener(0);
}

void Menus::ServiceWeaponShop::LostFocus()
{
    InGameMenu::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(18))->SetListener(0);
}

void Menus::Achievement::LostFocus()
{
    MenuState::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(10))->SetListener(0);
}

void Menus::Tutorial::GotFocus()
{
    MenuState::GotFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(23))->SetListener(this);
}

void Menus::Tutorial::LostFocus()
{
    MenuState::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(23))->SetListener(0);
}

void Menus::BlockingTutorial::GotFocus()
{
    MenuState::GotFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(24))->SetListener(this);
}

void Menus::BlockingTutorial::LostFocus()
{
    MenuState::LostFocus();
    static_cast<MenuWidget*>(getWidgetByIndex(24))->SetListener(0);
}

bool Menus::Tutorial::Notify(const MenuWidget* widget, int event)
{
    if (MenuState::Notify(widget, event))
        return true;

    MenuManager* manager = MenuManager::getInstance();
    if (getWidgetByIndex(manager, 23) != widget || event != 1)
        return false;

    _ZN11MenuManager3popEb(manager, true);
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(210, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    return true;
}

bool Menus::BlockingTutorial::Notify(const MenuWidget* widget, int event)
{
    if (Tutorial::Notify(widget, event))
        return true;

    MenuManager* manager = MenuManager::getInstance();
    if (getWidgetByIndex(manager, 24) != widget || event != 1)
        return false;

    _ZN11MenuManager3popEb(manager, true);
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(210, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    return true;
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

void MenuState::UpdateLocalization()
{
    const int count = widgetIds.size;
    MenuManager* manager = MenuManager::getInstance();
    for (int i = 0; i < count; ++i) {
        const int index = widgetIds.elements[i];
        MenuWidget* widget = static_cast<MenuWidget*>(index < 0 ? 0 : getWidgetByIndex(manager, index));
        widget->UpdateLocalization();
    }
}

void Menus::InGameCarRental::Hide()
{
    MenuState::Hide();
    StateMachine::getInstance()->popState();
}

void Menus::InGameWeaponShop::Hide()
{
    MenuState::Hide();
    StateMachine::getInstance()->popState();
}

void Menus::Map::OnEvent(RenderFX::Event& event)
{
    if (inputDelay > 0)
        event.consumed = true;
    else
        MenuState::OnEvent(event);
}

extern "C" void launchTwitter();

void Menus::Infos::Update()
{
    MenuState::Update();
    MenuManager* manager = MenuManager::getInstance();
    if (unknown104) {
        unknown104 = false;
        Confirm* confirmation = static_cast<Confirm*>(manager->getState(confirmMenuName));
        if (confirmation->Confirmed()) {
            launchTwitter();
        } else {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(219, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        }
    }
}

namespace {
const char updateStatisticsCommand[] __attribute__((section(".rodata.menu_update_statistics"))) = "UpdateStatistics";
const char updateAchievementsCommand[] __attribute__((section(".rodata.menu_update_achievements"))) = "UpdateAchievements";
const char updateAboutCommand[] __attribute__((section(".rodata.menu_update_about"))) = "UpdateAbout";

template<void (*Update)(void*, bool)>
inline void updateInfoWidget(const char* command, const char* updateCommand, int index, bool& pending)
{
    if (strcmp(command, updateCommand) == 0) {
        void* widget = getWidgetByIndex(index);
        Update(widget, pending);
        pending = false;
    }
}
}

extern "C" {
void _ZN7Widgets10Statistics6UpdateEb(void*, bool);
void _ZN7Widgets12Achievements6UpdateEb(void*, bool);
void _ZN7Widgets5About6UpdateEb(void*, bool);
}

void Menus::InfoStatistics::OnFSCommand(const char* command, const char*)
{
    updateInfoWidget<_ZN7Widgets10Statistics6UpdateEb>(command, updateStatisticsCommand, 12, unknown105);
}

void Menus::InfoAchievements::OnFSCommand(const char* command, const char*)
{
    updateInfoWidget<_ZN7Widgets12Achievements6UpdateEb>(command, updateAchievementsCommand, 11, unknown105);
}

void Menus::InfoAbout::OnFSCommand(const char* command, const char*)
{
    updateInfoWidget<_ZN7Widgets5About6UpdateEb>(command, updateAboutCommand, 14, unknown105);
}

extern "C" void _ZN7Widgets9Objective16SetObjectiveTextEi(void*, int);
extern "C" void* _ZN12StateMachine11switchStateI10GSMainMenuEEPT_v(StateMachine*) __attribute__((weak));

void Menus::Map::GotFocus()
{
    InGameMenu::GotFocus();
    inputDelay = 250;
    unknown105 = true;
    MenuManager* manager = MenuManager::getInstance();
    void* menu = getWidgetByIndex(manager, 1);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 0, 0x102d, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 1, 0x102e, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 2, 0x102f, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 3, 0x1009, true);
    _ZN7Widgets6IGMenu12SetTitleTextEi(menu, 0x1051);
    _ZN7Widgets6IGMenu17SetBackButtonTextEi(menu, 0x1026);
    _ZN7Widgets6IGMenu9GoToFrameEPKc(menu, fourButtonMenuFrame);

    void* objective = getWidgetByIndex(manager, 2);
    if (static_cast<const Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText() != -1) {
        _ZN7Widgets9Objective16SetObjectiveTextEi(objective,
            static_cast<const Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText());
    } else {
        _ZN7Widgets9Objective16SetObjectiveTextEi(objective, 0x1055);
    }
    manager->initMap();
    _ZN7Widgets8BlackBox8SetStateENS0_6eStateE(getWidgetByIndex(manager, 27), 1);
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(menu, 5, false);
}

void Menus::Map::Update()
{
    MenuState::Update();
    inputDelay = static_cast<int>(inputDelay - StateMachine::getInstance()->getTimeStamp());
    MenuManager* manager = MenuManager::getInstance();
    if (unknown104) {
        unknown104 = false;
        Confirm* confirmation = static_cast<Confirm*>(manager->getState(confirmMenuName));
        if (confirmation->Confirmed()) {
            if (static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getState() != 4) {
                SaveGame save;
                save.SampleAndSave(SaveGame::GetDefaultFilename());
            }
            PlayerTest::GetPlayer()->switchContext(PlayerTest::Context0, false);
            for (int i = 0; i < 17; ++i)
                manager->setText(static_cast<MenuManager::eText>(i), -1, 0);
            manager->enableAnims(false);
            manager->popAll(false);
            while (StateMachine::getInstance()->hasStates())
                StateMachine::getInstance()->popState();
            SoundManager::getInstance()->endCutscene();
            GS3DStuff::unload();
            _ZN12StateMachine11switchStateI10GSMainMenuEEPT_v(StateMachine::getInstance());
            return;
        } else {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(219, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        }
    }
    if (static_cast<int>(manager->consumedCursors()) <= 0) {
        manager->updateMap();
        manager->updateMarkers();
    }
}

namespace Widgets { class Achievement; }
extern "C" void _ZN7Widgets11Achievement8SetTitleEi(Widgets::Achievement*, int);
extern "C" void _ZN7Widgets11Achievement7SetIconEPKc(Widgets::Achievement*, const char*);
namespace retail_achievement_menu {
struct IconEntry {
    int textId;
    const char* icon;
};
extern const IconEntry icons[] __attribute__((visibility("hidden")));
}
void Menus::Achievement::SetAchievement(const AchievementManager::Achievement* achievement)
{
    Widgets::Achievement* widget = static_cast<Widgets::Achievement*>(
        getWidgetByIndex(MenuManager::getInstance(), 10));
    _ZN7Widgets11Achievement8SetTitleEi(widget, achievement->titleId);
    _ZN7Widgets11Achievement7SetIconEPKc(widget, retail_achievement_menu::icons[achievement->unknown0].icon);
}

void Menus::Achievement::Update()
{
    displayTime = static_cast<int>(displayTime -
        static_cast<StateMachine*>(_ZN12StateMachine11getInstanceEv())->getTimeStamp());
    ScriptManager* scripts = ScriptManager::getInstance();
    if (displayTime < 0 || scripts->isInCinematic() ||
        (static_cast<const Mission*>(scripts->getMission())->getState() != 0 &&
         static_cast<const Mission*>(scripts->getMission())->getState() != 4) ||
        Application::GetInstance()->GetHudManager()->isAnyMessageDisplayed()) {
        _ZN11MenuManager3popEb(MenuManager::getInstance(), true);
    }
}

void Menus::Achievement::Show()
{
    MenuState::Show();
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(217, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    displayTime = 5000;
}

bool Menus::InGameMenu::Notify(const MenuWidget* widget, int event)
{
    MenuManager* manager = MenuManager::getInstance();
    const MenuWidget* menu = static_cast<const MenuWidget*>(getWidgetByIndex(manager, 1));
    if (!(widget == menu && event == 1))
        return false;

    if (manager->isInGameMenu() < GetDepth()) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = event;
        sound->playEx(219, 0, false, 1.0f, 0, event, 1.0f, 0);
        sound->unknown140 = false;
    }
    _ZN11MenuManager3popEb(manager, false);
    return true;
}

namespace Widgets {
class Arrows : public MenuWidget { public: int GetCurrentPage() const; };
class Title : public MenuWidget { public: void SetTextId(int); void SetIcon(const char*); };
class Help : public MenuWidget { public: void SetTextId(int); void SetIcon(const char*); };
}
namespace Menus {
struct HelpSpecializedEntry {
    int textId;
    const char* icon;
};
extern const HelpSpecializedEntry s_helpSpecializedEntries[] __attribute__((visibility("hidden")));
}
static const char helpEmptyIcon[] = "empty";

bool Menus::InfoHelp::Notify(const MenuWidget* widget, int event)
{
    if (Infos::Notify(widget, event))
        return true;
    MenuManager* manager = MenuManager::getInstance();
    const Widgets::Arrows* arrows = static_cast<const Widgets::Arrows*>(getWidgetByIndex(manager, 18));
    if (widget != arrows || (event != 1 && event != 2))
        return false;
    const int page = arrows->GetCurrentPage();
    int firstPage = 0;
    unsigned int category = 0;
    for (; category < sizeof(s_helpCategories) / sizeof(s_helpCategories[0]); ++category) {
        const int pageCount = s_helpCategories[category].endPage - s_helpCategories[category].firstPage;
        const int categoryPage = page - firstPage;
        if (categoryPage < pageCount) {
            Widgets::Title* title = static_cast<Widgets::Title*>(getWidgetByIndex(manager, 15));
            title->SetTextId(s_helpCategories[category].title);
            title->UpdateLocalization();
            const int textId = categoryPage + s_helpCategories[category].firstPage;
            Widgets::Help* help = static_cast<Widgets::Help*>(getWidgetByIndex(manager, 13));
            help->SetTextId(textId);
            const char* icon = helpEmptyIcon;
            for (int entry = 0; entry < 10; ++entry) {
                if (s_helpSpecializedEntries[entry].textId == textId) {
                    icon = s_helpSpecializedEntries[entry].icon;
                    break;
                }
            }
            help->SetIcon(icon);
            help->UpdateLocalization();
            break;
        }
        firstPage += pageCount;
    }
    return true;
}

#include "../core/PointerVector.h"
#include "../scripting/Script.h"
namespace stlp_priv {
template<>
inline _Vector_base<Script*, std::allocator<Script*> >::_Vector_base()
{
    first = 0;
    limit = 0;
    last = 0;
}
}
void Menus::ServiceMissions::GotFocus()
{
    Services::GotFocus();
    MenuManager* manager = MenuManager::getInstance();
    _ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb(getWidgetByIndex(manager, 1), 0, true);
    ScriptManager* scripts = ScriptManager::getInstance();
    std::vector<Script*> available;
    scripts->getAvailableMissionScripts(available);
    const Mission* mission = static_cast<const Mission*>(ScriptManager::getInstance()->getMission());
    Application::GetInstance();
    int index = 0;
    int count = 0;
    for (; index < available.size(); ++index)
        if (mission->mission(available[index]->getMissionId()))
            ++count;
    MenuWidget* arrows = static_cast<MenuWidget*>(getWidgetByIndex(manager, 18));
    arrows->SetListener(this);
    _ZN7Widgets6Arrows12SetPageCountEiib(arrows, count, 0, true);
}

void MenuState::Hide()
{
    MenuManager* manager = MenuManager::getInstance();
    bool animate = manager->areAnimsEnabled();
    if (depth == 1) {
        for (int index = 0; index < 32; ++index) {
            MenuWidget* widget = manager->getWidgetByIndex(index);
            if (widget && widget->IsVisible() && widget->AutoHide()) {
                widget->Hide(animate);
            }
        }
    }
    depth = 0;
}

namespace Widgets {
class Achievements : public MenuWidget { public: void SetCategory(int); void Reset(); };
}

bool Menus::InfoAchievements::Notify(const MenuWidget* widget, int event)
{
    if (Infos::Notify(widget, event))
        return true;
    const Widgets::Arrows* arrows = static_cast<const Widgets::Arrows*>(
        getWidgetByIndex(MenuManager::getInstance(), 18));
    if (widget != arrows || (event != 1 && event != 2))
        return false;
    // Keep the native title-null fallback in the cold tail.
    MenuManager* titleManager = MenuManager::getInstance();
    const MenuWidgetTable& titleTable =
        *reinterpret_cast<const MenuWidgetTable*>(titleManager);
    Widgets::Title* title = static_cast<Widgets::Title*>(
        __builtin_expect(15 < titleTable.count, 1) ? titleTable.widgets[15] : 0);
    title->SetTextId(
        retail_achievement_menu::icons[arrows->GetCurrentPage()].textId);
    title->SetIcon(
        retail_achievement_menu::icons[arrows->GetCurrentPage()].icon);
    title->UpdateLocalization();
    // This native successful-load tail follows the title-null tail.
    MenuManager* achievementsManager = MenuManager::getInstance();
    const MenuWidgetTable& achievementsTable =
        *reinterpret_cast<const MenuWidgetTable*>(achievementsManager);
    Widgets::Achievements* achievements = static_cast<Widgets::Achievements*>(
        __builtin_expect(11 < achievementsTable.count, 0)
            ? achievementsTable.widgets[11] : 0);
    achievements->SetCategory(arrows->GetCurrentPage());
    if (event == 1) {
        achievements->Reset();
        achievements->UpdateLocalization();
    }
    return true;
}

namespace Widgets { class IGMenu : public MenuWidget { public: int GetLastPressedButton() const; }; }

extern "C" void _ZN11MenuManager8switchToEPKcb(MenuManager*, const char*, bool);

bool Menus::Options::Notify(const MenuWidget* widget, int event)
{
    if (InGameMenu::Notify(widget, event))
        return true;
    MenuManager* manager = MenuManager::getInstance();
    const Widgets::IGMenu* menu = static_cast<const Widgets::IGMenu*>(manager->getWidgetByIndex(1));
    if (widget != menu || event != 2)
        return false;
    SoundManager* sound = SoundManager::getInstance();
    bool& playbackOverride = sound->unknown140;
    playbackOverride = true;
    sound->playEx(222, 0, false, 1.0f, 0, true, 1.0f, 0);
    playbackOverride = false;
    switch (menu->GetLastPressedButton()) {
    case 0:
        _ZN11MenuManager8switchToEPKcb(manager, optionVolumesName, false);
        break;
    case 1:
        _ZN11MenuManager8switchToEPKcb(manager, optionControlsName, false);
        break;
    case 2:
        _ZN11MenuManager8switchToEPKcb(manager, optionLanguageName, false);
        break;
    case 3:
        _ZN11MenuManager8switchToEPKcb(manager, optionGameSettingsName, false);
        break;
    }
    return true;
}

extern "C" {
int _ZNK7Widgets6IGMenu20GetLastPressedButtonEv(const void*);
void _ZN11MenuManager8switchToEPKcb(MenuManager*, const char*, bool);
}
static const char servicesWeaponShopName[] = "ServiceWeaponShop";
static const char servicesCarRentalName[] = "ServiceCarRental";
bool Menus::Services::Notify(const MenuWidget* widget, int event)
{
    if (InGameMenu::Notify(widget, event))
        return true;
    MenuManager* manager = MenuManager::getInstance();
    const Widgets::IGMenu* menu = static_cast<const Widgets::IGMenu*>(manager->getWidgetByIndex(1));
    if (widget == menu && event == 2) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(222, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        switch (menu->GetLastPressedButton()) {
        case 0: _ZN11MenuManager8switchToEPKcb(manager, serviceMissionsName, false); break;
        case 1: _ZN11MenuManager8switchToEPKcb(manager, servicesWeaponShopName, false); break;
        case 2: _ZN11MenuManager8switchToEPKcb(manager, servicesCarRentalName, false); break;
        case 3: _ZN11MenuManager8switchToEPKcb(manager, serviceCorruptionName, false); break;
        }
        return true;
    }
    return false;
}

namespace Widgets {
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
}

bool Menus::OptionVolumes::Notify(const MenuWidget* widget, int event)
{
    if (Options::Notify(widget, event))
        return true;
    Widgets::Volumes* volumes = static_cast<Widgets::Volumes*>(MenuManager::getInstance()->getWidgetByIndex(7));
    if (widget != volumes)
        return false;
    const int previous = selectedChannel;
    int playlist;
    if (event == 1) {
        playlist = --selectedChannel;
        if (playlist < -2)
            playlist = selectedChannel = SoundManager::getInstance()->getPlaylistCount() - 1;
    } else if (event == 2) {
        ++selectedChannel;
        if (selectedChannel >= SoundManager::getInstance()->getPlaylistCount())
            playlist = selectedChannel = -2;
        else
            playlist = selectedChannel;
    } else {
        return false;
    }
    if (previous == playlist)
        return false;
    volumes->SetPlaylist(playlist);
    volumes->UpdateLocalization();
    return true;
}

bool Menus::Infos::Notify(const MenuWidget* widget, int event)
{
    if (InGameMenu::Notify(widget, event))
        return true;

    MenuManager* manager = MenuManager::getInstance();
    const Widgets::IGMenu* menu = static_cast<const Widgets::IGMenu*>(manager->getWidgetByIndex(1));
    if (!(widget == menu && event == 2))
        return false;

    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(222, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;

    switch (menu->GetLastPressedButton()) {
    case 0:
        _ZN11MenuManager8switchToEPKcb(manager, infoAchievementsName, false);
        break;
    case 1:
        _ZN11MenuManager8switchToEPKcb(manager, infoStatisticsName, false);
        break;
    case 2:
        _ZN11MenuManager8switchToEPKcb(manager, infoHelpName, false);
        break;
    case 3:
        _ZN11MenuManager8switchToEPKcb(manager, infoAboutName, false);
        break;
    case 4:
        _ZN11MenuManager10clearFocusEv(manager);
        if (_ZN9GSLoading12isGameLoadedEv()) {
            unknown104 = true;
            Dialog* confirmation = static_cast<Dialog*>(manager->getState(confirmMenuName));
            confirmation->SetMessage(static_cast<const Mission*>(ScriptManager::getInstance()->getMission())->getState() == 4
                ? 0x1021 : 0x1020);
            manager->push(confirmMenuName, false);
        } else {
            launchTwitter();
        }
        break;
    }
    return true;
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

bool Menus::ServiceWeaponShop::Notify(const MenuWidget* widget, int event)
{
    if (Services::Notify(widget, event))
        return true;
    MenuManager* manager = MenuManager::getInstance();
    Widgets::Arrows* arrows = static_cast<Widgets::Arrows*>(manager->getWidgetByIndex(18));
    Widgets::Shop* shop = static_cast<Widgets::Shop*>(manager->getWidgetByIndex(3));
    if (widget == arrows) {
        if (static_cast<unsigned int>(event) - 1u > 1u)
            return false;
        Refresh();
        return true;
    }
    if (widget == shop && event == 1) {
        const int selected = shop->GetSelectedItem();
        selectedWeapon = arrows->GetCurrentPage() * 4 + selected;
        static_cast<Dialog*>(manager->getState(confirmMenuName))->SetMessage(0x1024);
        manager->push(confirmMenuName, false);
        return true;
    }
    return false;
}

bool Menus::Map::Notify(const MenuWidget* widget, int event)
{
    if (InGameMenu::Notify(widget, event))
        return true;

    MenuManager* manager = MenuManager::getInstance();
    const Widgets::IGMenu* menu = static_cast<const Widgets::IGMenu*>(manager->getWidgetByIndex(1));
    if (!(widget == menu && event == 2))
        return false;

    switch (menu->GetLastPressedButton()) {
    case 1:
        manager->push(optionVolumesName, false);
        break;
    case 2:
        manager->push(infoAchievementsName, false);
        break;
    case 0:
        manager->push(serviceMissionsName, false);
        return true;
    case 3:
        unknown104 = true;
        Dialog* confirmation = static_cast<Dialog*>(manager->getState(confirmMenuName));
        confirmation->SetMessage(static_cast<const Mission*>(ScriptManager::getInstance()->getMission())->getState() == 4
            ? 0x1021 : 0x1020);
        manager->push(confirmMenuName, false);
        break;
    }
    return true;
}
