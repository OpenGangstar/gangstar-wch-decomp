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
#include "../app/Application.h"
#include "../hud/TargetMarker.h"
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
    void ClearStates();
    void ClearFocus();
};

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

MyMenuFX::~MyMenuFX()
{
}

void MyMenuFX::ClearFocus()
{
    SetFocus(static_cast<gameswf::character*>(0), 0);
}

namespace {
struct MenuManagerFocusFields {
    unsigned char beforeTutorialIds[72];
    int tutorialId;
    int tutorialTextId;
    unsigned char beforeMenuFX[108];
    MyMenuFX* menuFX;
    unsigned char beforeClearingFocus[5];
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

extern "C" void _ZN11MenuManager13topSetVisibleEb(MenuManager* manager, bool visible)
{
    if (manager->getDepth() > 0) {
        MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
        setCharacterVisible(fields.menuFX->GetCurrentState()->getCharacter(), visible);
    }
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
