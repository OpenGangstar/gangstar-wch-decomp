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
#include "../core/VideoDriver.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/Debug_Log.h"
#include "../core/PathName.h"
#include "MenuState.h"
#include "WidgetDialog.h"
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
    unsigned int consumedCursorCount;
    unsigned char beforeWidgets[4];
    MenuWidget** widgets;
    int widgetCount;
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

MenuManager* MenuManager::getInstance()
{
    static MenuManager mgr;
    return &mgr;
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

extern "C" bool _ZN11MenuManager22updateWidgetVisibilityEv(MenuManager* manager)
{
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    bool allHidden = true;
    for (int index = 0; index < 32; ++index) {
        MenuWidget* widget = index < fields.widgetCount ? fields.widgets[index] : 0;
        if (widget->IsVisible()) {
            allHidden = false;
        } else if (isCharacterVisible(widget->getCharacter())) {
            if (getCharacterPlayState(widget->getCharacter()) == 1)
                setCharacterVisible(widget->getCharacter(), false);
            else
                allHidden = false;
        }
    }
    return allHidden;
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

extern "C" void _ZN7gameswf5arrayIP10MenuWidgetE14release_bufferEv(void*) __attribute__((weak));

inline MenuManager::WidgetStorage::~WidgetStorage()
{
    _ZN7gameswf5arrayIP10MenuWidgetE14release_bufferEv(this);
}

inline MenuManager::OwnedBuffer::~OwnedBuffer()
{
    // Keep the owned-buffer cleanup on the retail fall-through path.
    if (__builtin_expect(ownsData, true))
        ::operator delete(data);
}

inline MenuManager::OwnedBuffer::OwnedBuffer()
    : data(0), unknown4(0), unknown8(0), ownsData(true), unknown13(true)
{
}

inline MenuManager::WidgetStorage::WidgetStorage() : elements(0), size(0), capacity(0)
{
}

inline MenuManager::Entry::Entry()
{
    unknown4 = 0.0f;
    unknown0 = 0.0f;
    unknown8 = 0.0f;
    unknown12 = 0;
}

MenuManager::MenuManager()
    : unknown4(0), unknown8(0), unknown12(0), unknown16(0), unknown20(0), unknown24(0),
      unknown40(0.5f), unknown44(0), unknown48(0), unknown52(0), unknown56(0),
      mapMode(0), unknown64(0.01f), inGameMenu(0), tutorialId(-1), tutorialTextId(-1),
      repairCost(0), unknown100(1), unknown184(0), menuFX(0), unknown192(0),
      widgetVisibility(false), clearingFocus(false), charAutoLineFeed(17), asianFont(false),
      animsEnabled(true), cheatsUnlocked(false), cheatsUnlockAllowed(false),
      consumedCursorCount(0), unknown416(-1), unknown432(false)
{
    memset(unknown336, 0, sizeof(unknown336));
    memset(textIds, -2, sizeof(textIds));
    memset(texts, 0, sizeof(texts));
    memset(unknown168, -1, sizeof(unknown168));
}

MenuManager::~MenuManager()
{
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

namespace {
struct NamedMenuTexture {
    void* vtable;
    const char* name;
};
}

struct TexturePointerCopyTag {};

extern "C" void _ZNSt6vectorIPN3irr5video8ITextureESaIS3_EE18_M_insert_overflowEPS3_RKS3_RKSt11__true_typejb(
    MenuTextureStorage* textures, irr::video::ITexture** position,
    irr::video::ITexture* const& texture, const TexturePointerCopyTag&,
    unsigned int count, bool atEnd) __attribute__((long_call));

irr::video::ITexture* SwfTextureLoader(const char* name, int, int)
{
    irr::video::ITexture* texture = Application::GetInstance()->GetDevice()->getVideoDriver()->getTexture(name);
    if (texture) {
        if (s_textures.end != s_textures.capacityEnd) {
            *s_textures.end = texture;
            ++s_textures.end;
        } else {
            _ZNSt6vectorIPN3irr5video8ITextureESaIS3_EE18_M_insert_overflowEPS3_RKS3_RKSt11__true_typejb(
                &s_textures, s_textures.end, texture, TexturePointerCopyTag(), 1, true);
        }
    }
    return texture;
}

extern "C" void _ZN11MenuManager11freeTextureEPKc(const char* name)
{
    int count = s_textures.end - s_textures.begin;
    for (int index = 0; index < count; ++index) {
        const NamedMenuTexture* texture =
            reinterpret_cast<const NamedMenuTexture*>(s_textures.begin[index]);
        if (strstr(texture->name, name)) {
            irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();
            driver->removeTexture(s_textures.begin[index]);
            --count;
            s_textures.begin[index] = s_textures.begin[count];
            --index;
        }
    }
}
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

void MenuManager::updateLocalization()
{
    Application::GetInstance();
    for (int index = 0; index < 32; ++index) {
        MenuWidget* widget = getWidgetByIndex(index);
        if (widget->IsVisible())
            widget->UpdateLocalization();
    }
    for (int index = 0; index < 17; ++index) {
        const eText slot = static_cast<eText>(index);
        const int previousId = textIds[index];
        _ZN11MenuManager7setTextENS_5eTextEiPi(this, slot, -1, 0);
        _ZN11MenuManager7setTextENS_5eTextEiPi(this, slot, previousId, 0);
    }
}

extern "C" {
void _ZNK3Map4drawEv(const Map*);
void _ZNK11MenuManager8_drawMapEv(const MenuManager*);
void glFlush();
}
void MenuManager::draw(const StateMachine*)
{
    if (widgetVisibility && charAutoLineFeed == 0)
        return;
    Application* application = Application::GetInstance();
    if (inGameMenu != 0) {
        application->GetDevice()->getVideoDriver()->beginScene2D();
        _ZNK3Map4drawEv(Map::getInstance());
        MenuState* state = static_cast<MenuState*>(reinterpret_cast<MyMenuFX*>(menuFX)->GetState(menuMapStateName));
        if (getDepth() == state->GetDepth())
            _ZNK11MenuManager8_drawMapEv(this);
        application->GetDevice()->getVideoDriver()->endScene2D();
        glFlush();
    }
    reinterpret_cast<MyMenuFX*>(menuFX)->SetOrientation(static_cast<gameswf::orientation_mode>(0));
    RenderFX* render = reinterpret_cast<MyMenuFX*>(menuFX);
    const irr::core::rect<int>& widthViewport = Application::GetInstance()->GetDevice()->getVideoDriver()->getViewPort();
    const int width = widthViewport.LowerRightCorner.X - widthViewport.UpperLeftCorner.X;
    const irr::core::rect<int>& heightViewport = Application::GetInstance()->GetDevice()->getVideoDriver()->getViewPort();
    const int height = heightViewport.LowerRightCorner.Y - heightViewport.UpperLeftCorner.Y;
    render->SetViewport(0, 0, width, height);
    reinterpret_cast<MyMenuFX*>(menuFX)->Render();
}

struct GlyphOptimizerEntry { const char* font; const char* size; const char* name; };
extern "C" const GlyphOptimizerEntry _ZN11MenuManager19s_GlypOptimizerDataE[14];
extern "C" const char* _ZN13StringManager9LANGUAGESE[7];
static const char preloadFormat[]="%s.%s.%s.glyph";
static const char preloadBinaryMode[]="rb";
static const char preloadError[]="ERROR-fopen=0: MenuManager::preloadGlyphs-name='%s' \n";
extern "C" void _ZN8RenderFX10ClearFontsEPN7gameswf14player_contextE(gameswf::player_context*);
extern "C" void _ZN8RenderFX13PreloadGlyphsEv(RenderFX*);
struct PreloadStringFields { void* vtable; int language; };
struct PreloadRootFields { unsigned char beforeCharacter[16]; gameswf::character* character; };
struct PreloadCharacterMethods { void (*firstMethods[2])(); bool (*is)(const gameswf::character*,int); };
void MenuManager::preloadGlyphs(bool clearFonts)
{
    MenuManager* manager=this;
    char text[1025];
    char name[255];
    const char* language = _ZN13StringManager9LANGUAGESE[
        reinterpret_cast<PreloadStringFields*>(Application::GetInstance()->GetStringManager())->language];
    if (clearFonts)
        _ZN8RenderFX10ClearFontsEPN7gameswf14player_contextE(0);
    MenuManagerFocusFields& fields = *reinterpret_cast<MenuManagerFocusFields*>(manager);
    if (asianFont)
        return;
    RenderFX* render = reinterpret_cast<MyMenuFX*>(menuFX);
    gameswf::character* root = reinterpret_cast<PreloadRootFields*>(
        reinterpret_cast<MyMenuFX*>(MenuManager::getInstance()->getMenuFX())->GetRoot())->character;
    const gameswf::array<gameswf::character*>& characters = render->FindCharacters(root,0,0);
    for (int index=0; index<characters.size; ++index) {
        gameswf::character* character = characters.elements[index];
        const PreloadCharacterMethods& methods = **reinterpret_cast<const PreloadCharacterMethods* const*>(character);
        if (methods.is(character,30))
            _ZN11MenuManager13setMenuFXTextEPN7gameswf9characterEPKcbb(manager,characters.elements[index],localStartupEmptyText,false,false);
    }
    for (int index=0; index<14; ++index) {
        const GlyphOptimizerEntry& entry = _ZN11MenuManager19s_GlypOptimizerDataE[index];
        sprintf(name,preloadFormat,entry.font,language,entry.size);
        NativeFile* file=fopen(name,preloadBinaryMode);
        if (!file)
            ekd_debug_out(preloadError,name);
        fseek(file,0,2);
        int size=ftell(file);
        fseek(file,0,0);
        fread(text,size,1,file);
        text[size]=0;
        _ZN11MenuManager13setMenuFXTextEPKcS1_bb(manager,entry.name,text,false,false);
    }
    _ZN8RenderFX13PreloadGlyphsEv(reinterpret_cast<MyMenuFX*>(menuFX));
    for (int index=0; index<17; ++index)
        _ZN11MenuManager7setTextENS_5eTextEiPi(manager,static_cast<MenuManager::eText>(index),-1,0);
}

#include "../app/ApplicationStorage.h"
#include "../app/ApplicationListIterator.h"
#include "../core/PointerVector.h"
#include "../core/Point2D.h"
#include "../input/TouchIDListSupport.h"
#include "../input/TouchScreenBase.h"
namespace stlp_priv {
template<> struct _List_node<Point2D<short>*> : _List_node_base {
    Point2D<short>* value;
};
}
namespace std {
template<> stlp_priv::_List_node<Point2D<short>*>*
allocator<stlp_priv::_List_node<Point2D<short>*> >::allocate(unsigned int, const void*) __attribute__((weak));
}
namespace map_point_list_detail {
typedef stlp_priv::_List_node_base NodeBase;
struct _List_iterator_base {
    NodeBase* _M_node;
    _List_iterator_base(NodeBase* x) : _M_node(x) {}
    void _M_incr() { _M_node = _M_node->_M_next; }
    void _M_decr() { _M_node = _M_node->_M_prev; }
};
template<class T, class Traits> struct _List_iterator : public _List_iterator_base {
    typedef typename Traits::reference reference;
    typedef _List_iterator<T, Traits> _Self;
    typedef _List_iterator<T, typename Traits::_NonConstTraits> iterator;
    typedef _List_iterator<T, typename Traits::_ConstTraits> const_iterator;
    typedef stlp_priv::_List_node<T> _Node;
    explicit _List_iterator(NodeBase* x) : _List_iterator_base(x) {}
    _List_iterator() : _List_iterator_base(0) {}
    _List_iterator(const iterator& x) : _List_iterator_base(x._M_node) {}
    reference operator*() const { return static_cast<_Node*>(this->_M_node)->value; }
    _Self& operator++() { this->_M_incr(); return *this; }
    bool operator==(const_iterator y) const { return this->_M_node == y._M_node; }
    bool operator!=(const_iterator y) const { return this->_M_node != y._M_node; }
};
}
namespace stlp_priv {
template<> class _List_base<Point2D<short>*, std::allocator<Point2D<short>*> > {
protected:
    typedef std::allocator<Point2D<short>*> Allocator;
    typedef _List_node<Point2D<short>*> Node;
    typedef std::allocator<Node> NodeAllocator;
    typedef _STLP_alloc_proxy<_List_node_base, Node, NodeAllocator> AllocProxy;
    AllocProxy _M_node;
    explicit _List_base(const Allocator& allocator)
        : _M_node(NodeAllocator(allocator), _List_node_base()) { _M_empty_initialize(); }
    ~_List_base() { clear(); }
    void clear() __attribute__((weak));
    void _M_empty_initialize() {
        _M_node._M_data._M_next = &_M_node._M_data;
        _M_node._M_data._M_prev = _M_node._M_data._M_next;
    }
};
}
namespace std {
template<class T, class Alloc> class list;
template<> class list<Point2D<short>*, allocator<Point2D<short>*> >
    : public stlp_priv::_List_base<Point2D<short>*, allocator<Point2D<short>*> > {
    typedef stlp_priv::_List_base<Point2D<short>*, allocator<Point2D<short>*> > Base;
public:
    typedef Point2D<short>* value_type;
    typedef allocator<value_type> allocator_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef unsigned int size_type;
    typedef map_point_list_detail::_List_iterator<value_type, _Nonconst_traits<value_type> > iterator;
    typedef map_point_list_detail::_List_iterator<value_type, _Const_traits<value_type> > const_iterator;
    list() : Base(allocator_type()) {}
    iterator begin() { return iterator(this->_M_node._M_data._M_next); }
    const_iterator begin() const { return const_iterator(this->_M_node._M_data._M_next); }
    iterator end() { return iterator(&this->_M_node._M_data); }
    const_iterator end() const { return const_iterator(const_cast<stlp_priv::_List_node_base*>(&this->_M_node._M_data)); }
    reference front() { return *begin(); }
    reference back() { iterator last = end(); last._M_decr(); return *last; }
    size_type size() const {
        int count = 0;
        const_iterator current(begin());
        const_iterator last(end());
        while (current != last) {
            ++current;
            ++count;
        }
        return count;
    }
    iterator insert(iterator position, const_reference value) {
        stlp_priv::_List_node_base* inserted = _M_create_node(value);
        stlp_priv::_List_node_base* next = position._M_node;
        stlp_priv::_List_node_base* previous = next->_M_prev;
        inserted->_M_next = next;
        inserted->_M_prev = previous;
        previous->_M_next = inserted;
        next->_M_prev = inserted;
        return iterator(inserted);
    }
    void push_back(const_reference value) { insert(end(), value); }
private:
    stlp_priv::_List_node_base* _M_create_node(const_reference value) {
        Node* node = this->_M_node.allocate(1, 0);
        std::_Copy_Construct(&node->value, value);
        return node;
    }
};
}
typedef std::list<Point2D<short>*, std::allocator<Point2D<short>*> > MapPointList;
extern "C" {
void _ZN11MenuManager10_scrollMapERKSt4listIP7Point2DIsESaIS3_EE(MenuManager*, const MapPointList&);
void _ZN11MenuManager8_zoomMapERKSt4listIP7Point2DIsESaIS3_EE(MenuManager*, const MapPointList&);
float sqrtf(float);
}
struct MenuManagerMapFields {
    void* vtable;
    int width;
    int height;
    unsigned char unknown12[16];
    int offsetX;
    unsigned char unknown32[16];
    int previousX;
    int previousY;
    int previousDistance;
    int mapMode;
};
void MenuManager::updateMap()
{
    MenuManagerMapFields& fields = *reinterpret_cast<MenuManagerMapFields*>(this);
    TouchScreenBase* touch = Application::GetInstance()->GetTouchScreen();
    const TouchIDList ids = touch->getTouchIDList();
    MapPointList points;
    for (TouchIDList::const_iterator i = ids.begin(); i != ids.end(); ++i) {
        Point2D<short>* first = touch->getFirstTouchPoint(*i);
        if (first->x > fields.offsetX && first->x < fields.offsetX + fields.width
            && first->y > 0 && first->y < fields.height)
            points.push_back(touch->getTouchPoint(*i));
    }
    if (static_cast<int>(points.size()) != fields.mapMode) {
        fields.mapMode = points.size();
        if (fields.mapMode == 1) {
            Point2D<short>* point = points.front();
            int x = point->x;
            int y = point->y;
            fields.previousX = x;
            fields.previousY = y;
        } else if (fields.mapMode == 2) {
            Point2D<short>* first = points.front();
            Point2D<short>* last = points.back();
            float y = first->y - last->y;
            float x = first->x - last->x;
            fields.previousDistance = static_cast<int>(sqrtf(x * x + y * y));
        }
    } else {
        if (fields.mapMode == 1)
            _ZN11MenuManager10_scrollMapERKSt4listIP7Point2DIsESaIS3_EE(this, points);
        else if (fields.mapMode == 2)
            _ZN11MenuManager8_zoomMapERKSt4listIP7Point2DIsESaIS3_EE(this, points);
    }
}
