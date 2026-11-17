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
#include "../ai/StateMachine.h"
#include "MenuDialogs.h"
#include "../hud/MenuManager.h"
#include "../audio/SoundManager.h"
#include "../persistence/DataStream.h"
#include "../world/ResStream.h"

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
}

namespace Menus {
class InGameMenu : public MenuState {
public:
    explicit InGameMenu(const char* name);
    virtual inline ~InGameMenu() __attribute__((used));
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

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

class Options : public InGameMenu {
public:
    explicit Options(const char* name);
    virtual inline ~Options() __attribute__((used));
    virtual void GotFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

class OptionGameSettings : public Options {
public:
    OptionGameSettings();
    virtual ~OptionGameSettings();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);

private:
    int selections[8];
    int chapterStartup[6];
};

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

class MainMenu : public MenuState {
public:
    MainMenu();
    virtual ~MainMenu();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual bool Notify(const MenuWidget* widget, int event);
    virtual void SetPause(bool paused);

protected:
    bool unknown104;
    bool unknown105;
    bool unknown106;
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
    void* unknown108;
};

class Achievement : public MenuState {
public:
    Achievement();
    virtual ~Achievement();
    virtual void Show();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();

protected:
    int unknown104;
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
    : InGameMenu(mapName), unknown104(false), unknown105(false), unknown108(0)
{
    int ids[2];
    ids[0] = 2;
    ids[1] = 4;
    widgetIds.append(ids, 2);
}

static const char achievementName[] = "Achievement";

Menus::Achievement::Achievement()
    : MenuState(achievementName), unknown104(0)
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

inline MenuFX::State::~State()
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

namespace {
template <int first, int second, int third, int fourth, int title>
inline void configureFourButtonMenu(MenuManager* manager)
{
    void* menu = getWidgetByIndex(manager, 1);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 0, first, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 1, second, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 2, third, true);
    _ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib(menu, 3, fourth, true);
    _ZN7Widgets6IGMenu12SetTitleTextEi(menu, title);
    _ZN7Widgets6IGMenu17SetBackButtonTextEi(menu, 0x1027);
    _ZN7Widgets6IGMenu9GoToFrameEPKc(menu, fourButtonMenuFrame);
    _ZN7Widgets8BlackBox8SetStateENS0_6eStateE(getWidgetByIndex(manager, 27), 0);
}
}

void Menus::Options::GotFocus()
{
    InGameMenu::GotFocus();
    configureFourButtonMenu<0x1011, 0x100d, 0x1000, 0x1017, 0x1036>(MenuManager::getInstance());
}

void Menus::Services::GotFocus()
{
    InGameMenu::GotFocus();
    configureFourButtonMenu<0x103d, 0x1039, 0x103a, 0x103c, 0x1035>(MenuManager::getInstance());
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
