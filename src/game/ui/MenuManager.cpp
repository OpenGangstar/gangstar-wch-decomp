/*
 * MenuManager
 *
 * Original file: MenuManager.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MenuManager.cpp here, in the order they appear in the library.
 */

#include "../hud/MenuManager.h"
#include "../audio/SoundManager.h"
#include "../app/Application.h"
#include "../hud/TargetMarker.h"
#include "../persistence/FileSystemBase.h"
#include "../persistence/DataStream.h"
#include "../world/MapSingleton.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/NativeStdio.h"
#include "../core/Debug_Log.h"
#include "../core/PathName.h"
#include "MenuState.h"
#include "../rendering/CharacterVisibility.h"

class MyMenuFX : public MenuFX {
public:
    virtual ~MyMenuFX();
    int stackDepth() const { return stateStack.size; }
    void ClearStates();
    void ClearFocus();
};

extern "C" const short* _tolower_tab_;

char* StrToLower(char* text)
{
    const int length = strlen(text);
    for (int index = 0; index < length; ++index) {
        const unsigned char character = text[index];
        text[index] = _tolower_tab_[character + 1];
    }
    return text;
}

extern "C" int feof(NativeFile* file);

namespace {
struct NativeFileFlags {
    unsigned char beforeFlags[12];
    unsigned short flags;
};
}

int fs_close_func(void* file)
{
    return fclose(static_cast<NativeFile*>(file)) == -1 ? -1 : 0;
}

int fs_get_eof_func(void* file)
{
    unsigned int eof = feof(static_cast<NativeFile*>(file));
    // Normalize any nonzero EOF result to one.
    return ((0u - eof) | eof) >> 31;
}

int fs_tell_func(const void* file)
{
    return ftell(static_cast<NativeFile*>(const_cast<void*>(file)));
}

int fs_seek_to_end_func(void* file)
{
    return fseek(static_cast<NativeFile*>(file), 0, 2) == -1 ? -1 : 0;
}

int fs_seek_func(int offset, void* file)
{
    NativeFileFlags& state = *static_cast<NativeFileFlags*>(file);
    state.flags &= ~0x60;
    return fseek(static_cast<NativeFile*>(file), offset, 0) == -1 ? -1 : 0;
}

int fs_write_func(const void* source, int length, void* file)
{
    return fwrite(source, 1, length, static_cast<NativeFile*>(file));
}

int fs_read_func(void* destination, int length, void* file)
{
    return fread(destination, 1, length, static_cast<NativeFile*>(file));
}

static const char menuFileOpenError[] = "ERROR-fopen=0: fs_open_func-fullname='%s' \n";

void* fs_open_func(const char* name, const char* mode)
{
    char fullName[255];
    ekd_makestringfile255(name, fullName);
    NativeFile* file = fopen(fullName, mode);
    if (!file)
        ekd_debug_out(menuFileOpenError, fullName);
    return file;
}

static const char menuTexts[] = "Texts";
static const char dialogArrow[] = "dialogArrow";

void MenuManager::showTexts()
{
    reinterpret_cast<MyMenuFX*>(menuFX)->SetVisible(menuTexts, true);
}

void MenuManager::hideTexts()
{
    reinterpret_cast<MyMenuFX*>(menuFX)->SetVisible(menuTexts, false);
}

void* MenuManager::getState(const char* name) const
{
    return reinterpret_cast<MyMenuFX*>(menuFX)->GetState(name);
}

void MyMenuFX::ClearStates()
{
    for (int index = 0; index < registeredStates.size; ++index)
        delete registeredStates.elements[index];
    registeredStates.resize(0);
}

namespace Structs {
struct CarRental {
    char* name;
    int unknown4;
    int unknown8;
    int unknown12;

    void Read(DataStream& stream);
};

void CarRental::Read(DataStream& stream)
{
    name = stream.ReadAndAllocateString();
    unknown4 = stream.ReadInt();
    unknown8 = stream.ReadInt();
    unknown12 = stream.ReadInt();
}
}

MyMenuFX::~MyMenuFX()
{
}

void MyMenuFX::ClearFocus()
{
    SetFocus(static_cast<gameswf::character*>(0), 0);
}

namespace {
struct MenuManagerFocusFields {
    unsigned char beforeInGameMenu[68];
    int inGameMenu;
    int tutorialId;
    int tutorialTextId;
    unsigned char beforeMenuFX[108];
    MyMenuFX* menuFX;
    int unknown192;
    bool widgetVisibility;
    bool clearingFocus;
    unsigned char beforeTextSlots[2];
    int textIds[17];
    const char* texts[17];
    unsigned char beforeAsianFont[72];
    bool asianFont;
    unsigned char beforeCheatsUnlockAllowed[2];
    bool cheatsUnlockAllowed;
};
}

extern "C" {
int _ZN11MenuManager19s_currentSequenceIdE;
extern int _ZN7Widgets7Volumes10s_playlistE;
}

extern "C" bool _ZNK11MenuManager14getTutorialIdsERiS0_(
    const MenuManager* manager, int& id, int& textId)
{
    const MenuManagerFocusFields& fields = *reinterpret_cast<const MenuManagerFocusFields*>(manager);
    id = fields.tutorialId;
    textId = fields.tutorialTextId;
    return id != -1 && textId != -1;
}

extern "C" void _ZN11MenuManager17allowCheatsUnlockEb(MenuManager* manager, bool allow)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    fields.cheatsUnlockAllowed = allow;
    _ZN11MenuManager19s_currentSequenceIdE = 0;
}

extern "C" int _ZNK11MenuManager11getPlaylistEv(const MenuManager*)
{
    return _ZN7Widgets7Volumes10s_playlistE;
}

extern "C" int _ZNK11MenuManager9getTextIdENS_5eTextE(
    const MenuManager* manager, MenuManager::eText slot)
{
    const MenuManagerFocusFields& fields = *reinterpret_cast<const MenuManagerFocusFields*>(manager);
    if (static_cast<unsigned int>(slot) < 17)
        return fields.textIds[slot];
    return -1;
}

const char* MenuManager::getText(eText slot) const
{
    const MenuManagerFocusFields& fields = *reinterpret_cast<const MenuManagerFocusFields*>(this);
    if (static_cast<unsigned int>(slot) < 17)
        return fields.texts[slot];
    return 0;
}

extern "C" const char* _ZNK13StringManager9getStringEi(const StringManager* strings, int id);

extern "C" bool _ZN11MenuManager7setTextENS_5eTextEPKcPi(
    MenuManager* manager, MenuManager::eText slot, const char* text, int* arguments);

extern "C" bool _ZN11MenuManager7setTextENS_5eTextEiPi(
    MenuManager* manager, MenuManager::eText slot, int textId, int* arguments)
{
    if (static_cast<unsigned int>(slot) < 17 &&
        _ZNK11MenuManager9getTextIdENS_5eTextE(manager, slot) != textId) {
        const char* text = textId == -1 ? 0
            : _ZNK13StringManager9getStringEi(Application::GetInstance()->GetStringManager(), textId);
        if (_ZN11MenuManager7setTextENS_5eTextEPKcPi(manager, slot, text, arguments)) {
            MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
            fields.textIds[slot] = textId;
            return true;
        }
        return false;
    }
    if (textId == -1) {
        _ZN11MenuManager7setTextENS_5eTextEPKcPi(manager, slot, 0, arguments);
        return true;
    }
    return false;
}

extern "C" void _ZN11MenuManager15hideDialogArrowEv(MenuManager* manager)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    fields.menuFX->SetVisible(dialogArrow, false);
}

extern "C" void _ZN11MenuManager15showDialogArrowEv(MenuManager* manager)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    fields.menuFX->SetVisible(dialogArrow, true);
}

extern "C" bool _ZNK11MenuManager14isCurrentStateEPKc(const MenuManager* manager, const char* name)
{
    const MenuManagerFocusFields& fields = *reinterpret_cast<const MenuManagerFocusFields*>(manager);
    MenuFX::State* state = fields.menuFX->GetState(name);
    return state == fields.menuFX->GetCurrentState();
}

extern "C" void _ZN11MenuManager10clearFocusEv(MenuManager* manager)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    fields.clearingFocus = true;
    fields.menuFX->ClearFocus();
    fields.clearingFocus = false;
}

extern "C" bool _ZN11MenuManager15enableAsianFontEb(MenuManager* manager, bool enabled)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    if (fields.asianFont == enabled)
        return false;
    fields.asianFont = enabled;
    return true;
}

extern "C" char* strcat(char* destination, const char* source);

static const char asianFontStart[] = "<font size=\"90%%\">";
static const char asianFontFormat[] = "<font size=\"90%%\">%s</font>";
extern const char asianFontEnd[8] __attribute__((visibility("hidden")));
static char menuTextFormatBuffer[1024];

extern "C" void _ZN11MenuManager16formatMenuFXTextEPN7gameswf9characterEPKcz(
    MenuManager* manager, gameswf::character* character, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    if (fields.asianFont) {
        menuTextFormatBuffer[0] = 0;
        strcat(menuTextFormatBuffer, asianFontStart);
        strcat(menuTextFormatBuffer, format);
        memcpy(menuTextFormatBuffer + strlen(menuTextFormatBuffer), asianFontEnd, sizeof(asianFontEnd));
        fields.menuFX->FormatHTML(character, menuTextFormatBuffer, arguments);
    } else {
        fields.menuFX->FormatText(character, format, arguments);
    }
    __builtin_va_end(arguments);
}

extern "C" void _ZN11MenuManager16formatMenuFXTextEPKcS1_z(
    MenuManager* manager, const char* name, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    _ZN11MenuManager16formatMenuFXTextEPN7gameswf9characterEPKcz(
        manager, fields.menuFX->Find(name), format, arguments);
    __builtin_va_end(arguments);
}


static char asianFontTextBuffer[1024];

extern "C" void _ZN11MenuManager13setMenuFXTextEPN7gameswf9characterEPKcbb(
    MenuManager* manager, gameswf::character* character, const char* text, bool html, bool scaleAsianFont)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    if (fields.asianFont && scaleAsianFont) {
        sprintf(asianFontTextBuffer, asianFontFormat, text);
        fields.menuFX->SetText(character, asianFontTextBuffer, html);
    } else {
        fields.menuFX->SetText(character, text, html);
    }
}

extern "C" void _ZN11MenuManager13setMenuFXTextEPKcS1_bb(
    MenuManager* manager, const char* name, const char* text, bool html, bool scaleAsianFont)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    _ZN11MenuManager13setMenuFXTextEPN7gameswf9characterEPKcbb(
        manager, fields.menuFX->Find(name), text, html, scaleAsianFont);
}

namespace {
struct FontRenderSettings {
    unsigned char beforeFlag[8];
    bool enabled;
};

struct FontPlayerContext {
    unsigned char beforeSettings[12];
    FontRenderSettings* settings;
};

struct FontPlayer {
    unsigned char beforeContext[96];
    FontPlayerContext* context;
};

struct FontRoot {
    unsigned char beforePlayer[168];
    void* playerProxy;
    FontPlayer* player;
};
}

extern "C" void _ZNK7gameswf8weak_ptrINS_6playerEE11check_proxyEv(const void*)
    __attribute__((long_call));

static const char requestedFontFormat[] = "%s%s.ttf";
static const char asianFontFileFormat[] = "%sfont02.ttf";
static const char standardFontFileFormat[] = "%sfont01.ttf";

extern "C" {
void _ZN11MenuManagerD1Ev(MenuManager* manager);
extern MenuManager _ZZN11MenuManager11getInstanceEvE3mgr __attribute__((visibility("hidden")));

static void __tcf_7(void*) __attribute__((used));
static void __tcf_7(void*)
{
    _ZN11MenuManagerD1Ev(&_ZZN11MenuManager11getInstanceEvE3mgr);
}
}

bool get_fontfile(const char* name, bool, bool, char* destination, int)
{
    char lowerName[256];
    strcpy(lowerName, name);
    const char* resourcesPath = Application::GetInstance()->GetFileSystem()->getResourcesPath();
    sprintf(destination, requestedFontFormat, resourcesPath, StrToLower(lowerName));

    MyMenuFX* menu = reinterpret_cast<MyMenuFX*>(MenuManager::getInstance()->getMenuFX());
    FontRoot* root = reinterpret_cast<FontRoot*>(menu->GetRoot());
    if (root) {
        _ZNK7gameswf8weak_ptrINS_6playerEE11check_proxyEv(&root->playerProxy);
        root->player->context->settings->enabled = true;
    }
    const MenuManagerFocusFields& fields =
        *reinterpret_cast<const MenuManagerFocusFields*>(MenuManager::getInstance());
    if (fields.asianFont)
        sprintf(destination, asianFontFileFormat, resourcesPath);
    else
        sprintf(destination, standardFontFileFormat, resourcesPath);
    return true;
}

extern "C" void _ZN11MenuManager13topSetVisibleEb(MenuManager* manager, bool visible)
{
    if (manager->getDepth() > 0) {
        MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
        setCharacterVisible(fields.menuFX->GetCurrentState()->getCharacter(), visible);
    }
}

extern "C" int strcmp(const char* left, const char* right);
extern const char menuMapStateName[] __attribute__((visibility("hidden")));

static inline __attribute__((always_inline)) void finishMenuTransition(
    MenuManager* manager, MenuManagerFocusFields& fields, const char* name)
{
    fields.widgetVisibility = false;
    fields.unknown192 = 0;
    if (strcmp(name, menuMapStateName) == 0)
        fields.inGameMenu = manager->getDepth();
    static_cast<MenuState*>(fields.menuFX->GetCurrentState())->UpdateLocalization();
}

extern "C" void _ZN11MenuManager8switchToEPKcb(MenuManager* manager, const char* name, bool silent)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    if (manager->getDepth() <= 0 && !silent) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(223, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }

    fields.menuFX->SwitchMenu(name);
    finishMenuTransition(manager, fields, name);
}

extern "C" void _ZN11MenuManager3popEb(MenuManager* manager, bool silent)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    bool poppedMap = false;
    if (manager->getDepth() > 0 &&
        strcmp(fields.menuFX->GetCurrentState()->getName(), menuMapStateName) == 0) {
        fields.inGameMenu = 0;
        poppedMap = true;
    }

    fields.unknown192 = 0;
    if (manager->getDepth() > 0)
        fields.menuFX->PopMenu();
    if (manager->getDepth() > 0)
        static_cast<MenuState*>(fields.menuFX->GetCurrentState())->UpdateLocalization();

    if (poppedMap && !silent) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(218, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }
}

extern "C" void _ZN11MenuManager5popToEPKcbb(
    MenuManager* manager, const char* name, bool popTarget, bool silent)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    while (manager->getDepth() > 0) {
        if (strcmp(fields.menuFX->GetCurrentState()->getName(), name) == 0)
            break;
        _ZN11MenuManager3popEb(manager, silent);
    }
    // Keep the retail fall-through to the return when the target stays on the stack.
    if (__builtin_expect(!popTarget, true))
        return;
    _ZN11MenuManager3popEb(manager, silent);
}

void MenuManager::popAll(bool silent)
{
    while (reinterpret_cast<MyMenuFX*>(menuFX)->stackDepth() > 0)
        _ZN11MenuManager3popEb(this, true);

    if (!silent) {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(218, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }
}

void MenuManager::push(const char* name, bool silent)
{
    if (!silent) {
        SoundManager* sound = SoundManager::getInstance();
        int soundId = getDepth() > 0 ? 222 : 223;
        sound->unknown140 = true;
        sound->playEx(soundId, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }

    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(this);
    fields.menuFX->PushMenu(name);
    finishMenuTransition(this, fields, name);
}

void MenuManager::cleanupMap()
{
    TargetMarker::getInstance()->setEnabled(true);
}

void MenuManager::resetWidgetVisibility() { widgetVisibility = false; }

void MenuManager::MenuPause() {}

void MenuManager::MenuResume() {}

void MenuManager::setTutorialIds(int id, int textId)
{
    tutorialId = id;
    tutorialTextId = textId;
}

void MenuManager::setRepairCost(int cost) { repairCost = cost; }

int MenuManager::getRepairCost() const { return repairCost; }

bool MenuManager::areCheatsUnlocked() const { return cheatsUnlocked; }

bool MenuManager::isCheatsUnlockAllowed() const { return cheatsUnlockAllowed; }

bool MenuManager::isClearingFocus() const { return clearingFocus; }

MenuFXPrefix* MenuManager::getMenuFX() { return menuFX; }

int MenuManager::isInGameMenu() const { return inGameMenu; }

unsigned int MenuManager::consumedCursors() const { return consumedCursorCount; }

void MenuManager::consumeCursor() { ++consumedCursorCount; }

int MenuManager::getCharAutoLineFeed() { return 17; }

void MenuManager::enableAnims(bool enabled) { animsEnabled = enabled; }

bool MenuManager::areAnimsEnabled() const { return animsEnabled; }

int MenuManager::getDepth() const { return menuFX->depth; }

int MenuManager::getMapMode() const { return mapMode; }

namespace irr {
namespace video {
class ITexture;
}
}

struct MenuTextureStorage {
    irr::video::ITexture** begin;
    irr::video::ITexture** end;
    irr::video::ITexture** capacityEnd;
};

static MenuTextureStorage s_textures;
MenuCheatZone MenuManager::s_cheatActivationZones[2];

extern "C" {
void _ZN9stlp_priv12_Vector_baseIPN3irr5video8ITextureESaIS4_EED1Ev(MenuTextureStorage*)
    __attribute__((weak));
static void __tcf_9() __attribute__((used));
static void __tcf_9()
{
    _ZN9stlp_priv12_Vector_baseIPN3irr5video8ITextureESaIS4_EED1Ev(&s_textures);
}
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_8() __attribute__((used));
static void __tcf_8()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_menumanager_transitions {
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_8), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_menumanager_transitions::scripted_vehicle_trans, 21);
        s_textures.begin = 0;
        s_textures.end = 0;
        s_textures.capacityEnd = 0;
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_9), &__dso_handle);
        MenuManager::s_cheatActivationZones[0].right = 100.0f;
        MenuManager::s_cheatActivationZones[0].left = 0.0f;
        MenuManager::s_cheatActivationZones[0].top = 0.0f;
        MenuManager::s_cheatActivationZones[1].left = 380.0f;
        MenuManager::s_cheatActivationZones[0].bottom = 50.0f;
        MenuManager::s_cheatActivationZones[1].top = 0.0f;
        MenuManager::s_cheatActivationZones[1].right = 480.0f;
        MenuManager::s_cheatActivationZones[1].bottom = 50.0f;
    }
}

extern "C" {
static void _GLOBAL__I__Z16SwfTextureLoaderPKcii() __attribute__((used));
static void _GLOBAL__I__Z16SwfTextureLoaderPKcii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
