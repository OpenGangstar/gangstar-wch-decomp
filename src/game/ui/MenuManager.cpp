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

#include "../hud/CHudManager.h"
#include "../world/ResStream.h"

struct RenderFX::InitializationParameters {
    InitializationParameters()
        : driver(0), textureLoader(0), glyphCacheWidth(0), glyphCacheHeight(0),
          unknown16(0), unknown20(0), unknown24(true) {}
    irr::video::IVideoDriver* driver;
    irr::video::ITexture* (*textureLoader)(const char*, int, int);
    int glyphCacheWidth;
    int glyphCacheHeight;
    int unknown16;
    int unknown20;
    bool unknown24;
};

namespace Widgets {
class MainMenu : public MenuWidget { public: MainMenu(); private: unsigned char unknown20[36]; };
class IGMenu : public MenuWidget { public: IGMenu(); private: unsigned char unknown20[56]; };
class Objective : public MenuWidget { public: Objective(); private: unsigned char unknown20[8]; };
class Shop : public MenuWidget { public: Shop(); private: unsigned char unknown20[56]; };
class MapLegend : public MenuWidget { public: MapLegend(); private: unsigned char unknown20[36]; };
class Corruption : public MenuWidget { public: Corruption(); private: unsigned char unknown20[4]; };
class Mission : public MenuWidget { public: Mission(); private: unsigned char unknown20[4]; };
class Volumes : public MenuWidget { public: Volumes(); private: unsigned char unknown20[4]; };
class Controls : public MenuWidget { public: Controls(); private: unsigned char unknown20[8]; };
class Language : public MenuWidget { public: Language(); private: unsigned char unknown20[4]; };
class Achievement : public MenuWidget { public: Achievement(); private: unsigned char unknown20[4]; };
class Achievements : public MenuWidget { public: Achievements(); private: unsigned char unknown20[124]; };
class Statistics : public MenuWidget { public: Statistics(); private: unsigned char unknown20[336]; };
class Help : public MenuWidget { public: Help(); private: unsigned char unknown20[4]; };
class About : public MenuWidget { public: About(); private: unsigned char unknown20[68]; };
class Title : public MenuWidget { public: Title(); private: unsigned char unknown20[4]; };
class Money : public MenuWidget { public: Money(); };
class ContentBox : public MenuWidget { public: ContentBox(); };
class Arrows : public MenuWidget { public: Arrows(); private: unsigned char unknown20[8]; };
class BackgroundInGame : public MenuWidget { public: BackgroundInGame(); };
class BackgroundMainMenu : public MenuWidget { public: BackgroundMainMenu(); };
class Tutorial : public MenuWidget { public: explicit Tutorial(const char* name); private: unsigned char unknown20[20]; };
class BlockingTutorial : public MenuWidget { public: BlockingTutorial(); private: unsigned char unknown20[20]; };
class GameSetting : public MenuWidget { public: GameSetting(); private: unsigned char unknown20[8]; };
class BlackBox : public MenuWidget { public: BlackBox(); private: unsigned char unknown20[4]; };
class DemoBuy : public MenuWidget { public: DemoBuy(); };
class BackgroundDemoBuy : public MenuWidget { public: BackgroundDemoBuy(); };
}

namespace Menus {
class MainMenu : public MenuState { public: MainMenu(); private: unsigned char unknown104[4]; };
class Map : public MenuState { public: Map(); private: unsigned char unknown104[8]; };
class ServiceMissions : public MenuState { public: ServiceMissions(); };
class ServiceWeaponShop : public MenuState { public: explicit ServiceWeaponShop(const char* name); private: unsigned char unknown104[12]; };
class ServiceCarRental : public MenuState { public: explicit ServiceCarRental(const char* name); private: unsigned char unknown104[8]; };
class ServiceCorruption : public MenuState { public: ServiceCorruption(); };
class OptionVolumes : public MenuState { public: OptionVolumes(); private: unsigned char unknown104[4]; };
class OptionControls : public MenuState { public: OptionControls(); };
class OptionLanguage : public MenuState { public: OptionLanguage(); };
class OptionGameSettings : public MenuState { public: OptionGameSettings(); private: unsigned char unknown104[56]; };
class InfoHelp : public MenuState { public: InfoHelp(); private: unsigned char unknown104[4]; };
class InfoAbout : public MenuState { public: InfoAbout(); private: unsigned char unknown104[4]; };
class InfoAchievements : public MenuState { public: InfoAchievements(); private: unsigned char unknown104[4]; };
class InfoStatistics : public MenuState { public: InfoStatistics(); private: unsigned char unknown104[4]; };
class Confirm : public MenuState { public: explicit Confirm(const char* name); private: unsigned char unknown104[8]; };
class Achievement : public MenuState { public: Achievement(); private: unsigned char unknown104[4]; };
class BlockingTutorial : public MenuState { public: BlockingTutorial(); };
class Tutorial : public MenuState { public: explicit Tutorial(const char* name); };
class InGameWeaponShop : public MenuState { public: InGameWeaponShop(); private: unsigned char unknown104[12]; };
class InGameCarRental : public MenuState { public: InGameCarRental(); private: unsigned char unknown104[8]; };
class CarRepair : public MenuState { public: CarRepair(); private: unsigned char unknown104[8]; };
class CopBribe : public MenuState { public: CopBribe(); private: unsigned char unknown104[8]; };
class Splash : public MenuState { public: Splash(); };
}

extern "C" {
extern int _ZN11MenuManager20s_CarRentalDataCountE;
extern Structs::CarRental** _ZN11MenuManager15s_CarRentalDataE;
void _ZN7Structs9CarRental4ReadER10DataStream(Structs::CarRental* rental, DataStream& stream)
    __attribute__((long_call));
void _ZN7gameswf5arrayIP10MenuWidgetE6resizeEi(void* array, int size) __attribute__((long_call));
}

static const char setupCarRentals[] = "./CarRentals.gmap";
static const char setupMenuFile[] = "./newmenu.swf";
static const char setupWidgetConfirm[] = "widgetConfirm";
static const char setupWidgetCarRepair[] = "widgetCarRepair";
static const char setupWidgetTutorial[] = "widgetTutorial";
static const char setupWidgetSplash[] = "widgetSplash";
static const char setupWidgetRetroEffect[] = "widgetRetroEffect";
static const char setupStateCharacter[] = "dummy";
static const char setupServiceWeaponShop[] = "ServiceWeaponShop";
static const char setupServiceCarRental[] = "ServiceCarRental";
static const char setupConfirm[] = "Confirm";
static const char setupTutorial[] = "Tutorial";

struct SetupMiniMapView {
    unsigned char unknown0[44];
    int unknown44;
};

void MenuManager::setup(bool)
{
    ResStream resource(setupCarRentals, 1);
    DataStream stream(resource, DataStream::BigEndian);
    _ZN11MenuManager20s_CarRentalDataCountE = stream.ReadInt();
    if (_ZN11MenuManager20s_CarRentalDataCountE > 0) {
        _ZN11MenuManager15s_CarRentalDataE = new Structs::CarRental*[_ZN11MenuManager20s_CarRentalDataCountE + 1];
        memset(_ZN11MenuManager15s_CarRentalDataE, 0,
               (_ZN11MenuManager20s_CarRentalDataCountE + 1) * sizeof(Structs::CarRental*));
        for (int i = 0; i < _ZN11MenuManager20s_CarRentalDataCountE; ++i) {
            const int length = stream.ReadInt();
            const int next = stream.Tell() + length;
            Structs::CarRental* record = new Structs::CarRental();
            _ZN7Structs9CarRental4ReadER10DataStream(record, stream);
            if (stream.Tell() != next)
                stream.Seek(next, 0);
            _ZN11MenuManager15s_CarRentalDataE[i] = record;
        }
    }

    unknown44 = reinterpret_cast<const SetupMiniMapView*>(
        Application::GetInstance()->GetHudManager()->minimap)->unknown44;
    for (int i = 0; i < 4; ++i) {
        entries[i].unknown4 = -1.0f;
        entries[i].unknown0 = -1.0f;
        entries[i].unknown12 = 0;
    }

    RenderFX::InitializationParameters parameters;
    irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();
    parameters.glyphCacheWidth = 512;
    parameters.glyphCacheHeight = 512;
    parameters.unknown24 = true;
    parameters.driver = driver;
    parameters.textureLoader = SwfTextureLoader;
    RenderFX::Initialize(parameters);

    MyMenuFX* fx = new MyMenuFX();
    menuFX = reinterpret_cast<MenuFXPrefix*>(fx);
    fx->Load(setupMenuFile, 0);
    reinterpret_cast<MyMenuFX*>(menuFX)->SetInputBehavior(4);

    _ZN7gameswf5arrayIP10MenuWidgetE6resizeEi(&widgets, 32);
    widgets.elements[0] = new Widgets::MainMenu();
    widgets.elements[1] = new Widgets::IGMenu();
    widgets.elements[2] = new Widgets::Objective();
    widgets.elements[3] = new Widgets::Shop();
    widgets.elements[4] = new Widgets::MapLegend();
    widgets.elements[5] = new Widgets::Corruption();
    widgets.elements[6] = new Widgets::Mission();
    widgets.elements[7] = new Widgets::Volumes();
    widgets.elements[8] = new Widgets::Controls();
    widgets.elements[9] = new Widgets::Language();
    widgets.elements[10] = new Widgets::Achievement();
    widgets.elements[11] = new Widgets::Achievements();
    widgets.elements[12] = new Widgets::Statistics();
    widgets.elements[13] = new Widgets::Help();
    widgets.elements[14] = new Widgets::About();
    widgets.elements[15] = new Widgets::Title();
    widgets.elements[16] = new Widgets::Money();
    widgets.elements[17] = new Widgets::ContentBox();
    widgets.elements[18] = new Widgets::Arrows();
    widgets.elements[19] = new Widgets::BackgroundInGame();
    widgets.elements[20] = new Widgets::BackgroundMainMenu();
    widgets.elements[21] = new Widgets::Confirm(setupWidgetConfirm);
    widgets.elements[22] = new MenuWidget(setupWidgetCarRepair);
    widgets.elements[23] = new Widgets::Tutorial(setupWidgetTutorial);
    widgets.elements[24] = new Widgets::BlockingTutorial();
    widgets.elements[25] = new MenuWidget(setupWidgetSplash);
    widgets.elements[29] = new MenuWidget(setupWidgetRetroEffect);
    widgets.elements[26] = new Widgets::GameSetting();
    widgets.elements[27] = new Widgets::BlackBox();
    widgets.elements[28] = new Widgets::ConfirmPayment();
    widgets.elements[30] = new Widgets::DemoBuy();
    widgets.elements[31] = new Widgets::BackgroundDemoBuy();

    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::MainMenu(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::Map(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::ServiceMissions(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::ServiceWeaponShop(setupServiceWeaponShop), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::ServiceCarRental(setupServiceCarRental), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::ServiceCorruption(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::OptionVolumes(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::OptionControls(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::OptionLanguage(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::OptionGameSettings(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::InfoHelp(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::InfoAbout(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::InfoAchievements(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::InfoStatistics(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::Confirm(setupConfirm), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::Achievement(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::BlockingTutorial(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::Tutorial(setupTutorial), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::InGameWeaponShop(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::InGameCarRental(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::CarRepair(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::CopBribe(), setupStateCharacter);
    reinterpret_cast<MyMenuFX*>(menuFX)->RegisterState(new Menus::Splash(), setupStateCharacter);

    for (int i = 0; i < 17; ++i)
        _ZN11MenuManager7setTextENS_5eTextEiPi(this, static_cast<eText>(i), -1, 0);
    _ZN11MenuManager15hideDialogArrowEv(this);
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

#include "../missions/WantedLevelManager.h"
#include "../hud/CHudManager.h"
#include "../hud/MiniMap.h"
#include "../core/Vector3.h"
#include "../core/Rect.h"
#include "../characters/AnimObject.h"
#include "../meta/Item.h"
#include "Shop.h"

struct DrawMapBoundsView {
    unsigned char unknown0[44];
    float minX, minY, maxX, maxY;
};
struct DrawMapTrackingLink {
    DrawMapTrackingLink* next;
    DrawMapTrackingLink* previous;
};
struct DrawMapTrackingNode : DrawMapTrackingLink {
    LevelObject* object;
    AnimObject* marker;
};
struct DrawMapMiniMapView {
    unsigned char unknown0[60];
    DrawMapTrackingLink trackedObjects;
};
struct DrawMapItemView {
    unsigned char unknown0[88];
    int itemType;
};
struct MenuManagerViewportFields {
    unsigned char unknown0[12];
    int left;
    int top;
    int right;
    int bottom;
    int offsetX;
};

extern "C" void _ZNK11MenuManager8_drawMapEv(const MenuManager* self)
{
    const MenuManagerViewportFields& view = *reinterpret_cast<const MenuManagerViewportFields*>(self);
    const DrawMapBoundsView* map=reinterpret_cast<const DrawMapBoundsView*>(Map::getInstance());
    const irr::core::rect<float> bounds(map->minX,map->minY,map->maxX,map->maxY);
    irr::core::dimension2d<int> size;
    Map::getInstance()->getScaledSize(size);
    const DrawMapMiniMapView* minimap=reinterpret_cast<const DrawMapMiniMapView*>(Application::GetInstance()->GetHudManager()->minimap);
    DrawMapTrackingLink* link=minimap->trackedObjects.next;
    while (link!=&minimap->trackedObjects) {
        DrawMapTrackingNode* node=static_cast<DrawMapTrackingNode*>(link);
        LevelObject* object=node->object;
        const int type=LevelObject::s_type[object->getObjectType()];
        if(type==13) {
            if(!static_cast<Shop*>(object)->unlocked()) { link=link->next; continue; }
        } else if(type==15 && reinterpret_cast<const DrawMapItemView*>(object)->itemType==3) {
            if(WantedLevelManager::getInstance()->unknown8<=0 || !static_cast<Item*>(object)->unlocked()) { link=link->next; continue; }
        }
        const irr::core::vector3d<float> position=object->GetPosition();
        const irr::core::position2d<int> point(static_cast<int>(size.Width*((position.X-bounds.UpperLeftCorner.X)/(bounds.LowerRightCorner.X-bounds.UpperLeftCorner.X))),
                                               static_cast<int>(size.Height*((-position.Y-bounds.UpperLeftCorner.Y)/(bounds.LowerRightCorner.Y-bounds.UpperLeftCorner.Y))));
        if (__builtin_expect(view.left <= point.X && view.top <= point.Y && view.right >= point.X && view.bottom >= point.Y, 1)) {
            AnimObject* marker=node->marker;
            marker->SetPosition(view.offsetX-view.left+point.X,point.Y-view.top,0);
            marker->Draw();
        }
        link=link->next;
    }
    TargetMarker::getInstance()->draw();
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

#include "../characters/PlayerTest.h"
#include "../vehicles/Vehicle.h"
#include "../hud/CHudManager.h"
#include "../hud/MiniMap.h"
#include "../characters/AnimObject.h"

struct MarkerMapFields {
    unsigned char unknown0[44];
    irr::core::rect<float> bounds;
};
struct MarkerTargetFields {
    unsigned char unknown0[16];
    int offsetX, offsetY;
    bool enabled;
};
struct MarkerManagerFields {
    void* vtable;
    int unknown4, unknown8;
    int left, top, right, bottom;
    int mapScreenX;
};
struct MarkerLink { MarkerLink* next; MarkerLink* previous; };
struct MarkerTracking { LevelObject* object; AnimObject* marker; bool flag; };
struct MarkerNode : MarkerLink { MarkerTracking data; };
struct MarkerIterator {
    MarkerLink* node;
    explicit MarkerIterator(MarkerLink* x) : node(x) {}
    MarkerIterator(const MarkerIterator& x) : node(x.node) {}
    MarkerTracking& operator*() const { return static_cast<MarkerNode*>(node)->data; }
    MarkerIterator& operator++() { node = node->next; return *this; }
    bool operator!=(MarkerIterator y) const { return node != y.node; }
};
struct MarkerList {
    MarkerLink head;
    MarkerIterator begin() { return MarkerIterator(head.next); }
    MarkerIterator end() { return MarkerIterator(&head); }
};
struct MarkerMiniMapFields { unsigned char unknown0[60]; MarkerList trackedObjects; };

void MenuManager::updateMarkers()
{
    MarkerManagerFields& fields = *reinterpret_cast<MarkerManagerFields*>(this);
    PlayerTest* player = PlayerTest::GetPlayer();
    const irr::core::vector3d<float> position = player->GetPosition();
    float playerX = position.X;
    float playerY = position.Y;
    Vehicle* vehicle = player->getVehicle();
    if (vehicle) {
        const irr::core::vector3d<float> vehiclePosition = vehicle->GetPosition();
        playerX = vehiclePosition.X;
        playerY = vehiclePosition.Y;
    }
    MarkerMapFields* map = reinterpret_cast<MarkerMapFields*>(Map::getInstance());
    const irr::core::rect<float> bounds = map->bounds;
    const float relativeX = (playerX - bounds.UpperLeftCorner.X) / (bounds.LowerRightCorner.X - bounds.UpperLeftCorner.X);
    const float relativeY = (-playerY - bounds.UpperLeftCorner.Y) / (bounds.LowerRightCorner.Y - bounds.UpperLeftCorner.Y);
    irr::core::dimension2d<int> size;
    Map::getInstance()->getScaledSize(size);
    const irr::core::position2d<int> pos(static_cast<int>(static_cast<float>(size.Width) * relativeX),
                                         static_cast<int>(static_cast<float>(size.Height) * relativeY));
    if (pos.X >= fields.left && pos.Y >= fields.top && pos.X <= fields.right && pos.Y <= fields.bottom) {
        const int offset = fields.mapScreenX - fields.left;
        const int top = fields.top;
        MarkerTargetFields* marker = reinterpret_cast<MarkerTargetFields*>(TargetMarker::getInstance());
        marker->offsetX = offset;
        marker->offsetY = pos.Y - top;
        marker->offsetX += pos.X;
        TargetMarker::getInstance()->setEnabled(true);
    } else {
        TargetMarker::getInstance()->setEnabled(false);
    }
    MarkerMiniMapFields* minimap = reinterpret_cast<MarkerMiniMapFields*>(Application::GetInstance()->GetHudManager()->minimap);
    for (MarkerIterator it = minimap->trackedObjects.begin(); it != minimap->trackedObjects.end(); ++it) {
        if ((*it).flag)
            (*it).marker->UpdateFrame();
    }
}

struct ScrollMapFields {
    void* vtable;
    int width;
    int height;
    int left;
    int top;
    int right;
    int bottom;
    unsigned char unknown28[20];
    int previousX;
    int previousY;
};
struct ScrollMapClip {
    unsigned char unknown0[28];
    irr::core::rect<int> clip;
};
extern "C" void _ZN11MenuManager10_scrollMapERKSt4listIP7Point2DIsESaIS3_EE(MenuManager* self, const MapPointList& points)
{
    ScrollMapFields& f = *reinterpret_cast<ScrollMapFields*>(self);
    const Point2D<short>* point = *points.begin();
    int y, x;
    x = point->x;
    y = point->y;
    int dx = f.previousX - x;
    int dy = f.previousY - y;
    irr::core::dimension2d<int> size;
    Map::getInstance()->getScaledSize(size);
    f.left += dx;
    f.right += dx;
    f.top += dy;
    f.bottom += dy;
    if (f.left + dx <= 0) {
        f.left = 0;
        f.right = f.width;
    } else if (f.right + dx >= size.Width) {
        f.left = size.Width - f.width;
        f.right = size.Width;
    }
    if (f.top + dy <= 0) {
        f.top = 0;
        f.bottom = f.height;
    } else if (f.bottom + dy >= size.Height) {
        f.bottom = size.Height;
        f.top = size.Height - f.height;
    }
    ScrollMapClip* map = reinterpret_cast<ScrollMapClip*>(Map::getInstance());
    map->clip.UpperLeftCorner.X = f.left;
    map->clip.UpperLeftCorner.Y = f.top;
    map->clip.LowerRightCorner.X = f.right;
    map->clip.LowerRightCorner.Y = f.bottom;
    f.previousX = x;
    f.previousY = y;
}

#include "../core/Material.h"
struct ZoomFields {
    void* vtable;
    int width, height, left, top, right, bottom, panel;
    float zoom, maximum, minimum;
    int unknown44, previousX, previousY, previousDistance, mode;
    float step;
};
struct ZoomMapFields {
    irr::video::ITexture* texture;
    float rotation, scale, offsetX, offsetY;
    int screenX, screenY, left, top, right, bottom;
};
extern "C" void _ZN11MenuManager8_zoomMapERKSt4listIP7Point2DIsESaIS3_EE(MenuManager* manager, const MapPointList& points)
{
    ZoomFields& m = *reinterpret_cast<ZoomFields*>(manager);
    Point2D<short>* first = *points.begin();
    MapPointList::const_iterator tail = points.end();
    tail._M_decr();
    Point2D<short>* last = *tail;
    float y = first->y - last->y;
    float x = first->x - last->x;
    int distance = static_cast<int>(sqrtf(x * x + y * y));
    int delta = distance - m.previousDistance;
    if (delta < 0) delta = -delta;
    float old = m.zoom;
    if (distance < m.previousDistance) {
        m.zoom += delta * m.step;
        if (m.zoom >= m.maximum) m.zoom = m.maximum;
    } else if (distance > m.previousDistance) {
        m.zoom -= delta * m.step;
        if (m.zoom <= m.minimum) m.zoom = m.minimum;
    }
    m.previousDistance = distance;
    if (m.zoom != old) {
        const irr::core::dimension2d<int>& size = reinterpret_cast<ZoomMapFields*>(Map::getInstance())->texture->getSize();
        int halfWidth = m.width / 2;
        float textureWidth = size.Width;
        float oldInverse = 1.0f / old;
        float textureHeight = size.Height;
        float inverse = 1.0f / m.zoom;
        int scaledWidth = textureWidth * inverse;
        int scaledHeight = textureHeight * inverse;
        int centerY = static_cast<int>(static_cast<float>(scaledHeight) * (static_cast<float>(m.height / 2 + m.top) / (oldInverse * textureHeight)));
        int centerX = static_cast<int>(static_cast<float>(scaledWidth) * (static_cast<float>(halfWidth + m.left) / (textureWidth * oldInverse)));
        m.left = centerX - halfWidth;
        m.top = centerY - m.height / 2;
        m.right = m.left + m.width;
        m.bottom = m.top + m.height;
        if (m.left <= 0) { m.left = 0; m.right = m.width; }
        else if (static_cast<int>(textureWidth * (1.0f / m.zoom)) <= m.right) { m.left = scaledWidth - m.width; m.right = scaledWidth; }
        if (m.top <= 0) { m.top = 0; m.bottom = m.height; }
        else if (m.bottom >= scaledHeight) { m.top = scaledHeight - m.height; m.bottom = scaledHeight; }
        ZoomMapFields* map = reinterpret_cast<ZoomMapFields*>(Map::getInstance());
        map->left = m.left; map->top = m.top; map->right = m.right; map->bottom = m.bottom;
    }
    reinterpret_cast<ZoomMapFields*>(Map::getInstance())->scale = m.zoom;
}

#include "../core/Geometry.h"
extern "C" float acosf(float);
extern "C" double sqrt(double) __attribute__((const));
struct InitMapPoint { float X, Y; };
extern "C" void _ZN11MenuManager19_positionMapOnPointERN3irr4core8vector2dIfEE(MenuManager*, InitMapPoint&);
struct InitMapMarker { unsigned char unknown0[12]; float angle; };
void MenuManager::initMap()
{
    ZoomFields& m = *reinterpret_cast<ZoomFields*>(this);
    int height, width;
    Application::GetInstance()->GetScreenDimensions(width, height);
    m.width = height;
    m.height = height;
    m.panel = width - height;
    m.maximum = static_cast<float>(reinterpret_cast<ZoomMapFields*>(Map::getInstance())->texture->getSize().Width) / m.width;
    reinterpret_cast<ZoomMapFields*>(Map::getInstance())->rotation = 0.0f;
    int panel = m.panel;
    ZoomMapFields* map = reinterpret_cast<ZoomMapFields*>(Map::getInstance());
    map->screenX = panel;
    map->screenY = 0;
    PlayerTest* player = PlayerTest::GetPlayer();
    irr::core::vector3d<float> position = player->GetPosition();
    Vehicle* vehicle = player->getVehicle();
    if (vehicle)
        position = vehicle->GetPosition();
    InitMapPoint point = { position.X, position.Y };
    _ZN11MenuManager19_positionMapOnPointERN3irr4core8vector2dIfEE(this, point);
    irr::core::vector3d<float> front;
    const irr::core::vector3d<float> playerFront = player->GetFront();
    front.X = playerFront.X;
    front.Z = playerFront.Z;
    front.Y = playerFront.Y;
    if (vehicle)
        front = vehicle->GetFront();
    float dot = front.dotProduct(irr::core::vector3d<float>(0.0f, 1.0f, 0.0f));
    float length = front.getLength();
    float cosine = dot / length;
    float angle = acosf(irr::core::clamp(cosine, -1.0f, 1.0f));
    if (!(front.X > 0.0f))
        angle = -angle;
    reinterpret_cast<InitMapMarker*>(TargetMarker::getInstance())->angle = angle;
}


namespace {
// Menu state refreshed when the cheat sequence completes.
const char menuUpdateSettingsState[] = "OptionGameSettings";
}

extern "C" {
double _ZNK12StateMachine12getTimeStampEv(const StateMachine* machine);
void _ZN8RenderFX12UpdateCursorERNS_6CursorEi(RenderFX* render, void* cursor, int index);
bool _ZNK7Widgets8Tutorial15IsCursorPressedEv(const MenuWidget* widget);
void _ZN5Menus18OptionGameSettings7RefreshEv(void* state);
extern const int _ZN11MenuManager25s_cheatActivationSequenceE[];
TouchIDList& _ZNSt4listIlSaIlEEaSERKS1_(TouchIDList* list, const TouchIDList& other) __attribute__((weak));
}

void MenuManager::update(StateMachine* machine)
{
    consumedCursorCount = 0;
    if (getDepth() > 0) {
        unknown192 += _ZNK12StateMachine12getTimeStampEv(machine);
        TouchScreenBase* touch = Application::GetInstance()->GetTouchScreen();
        for (int i = 0; i < unknown184; ++i)
            entries[i].unknown12 = 0;
        TouchIDList ids = touch->getTouchIDList();
        if (isCheatsUnlockAllowed() && !cheatsUnlocked && ids.size() != 0) {
            const MenuCheatZone& zone = s_cheatActivationZones[
                _ZN11MenuManager25s_cheatActivationSequenceE[_ZN11MenuManager19s_currentSequenceIdE]];
            if (touch->isRegionPressed(reinterpret_cast<const irr::core::rect<float>&>(zone))) {
                ++_ZN11MenuManager19s_currentSequenceIdE;
                cheatsUnlocked = _ZN11MenuManager19s_currentSequenceIdE == 8;
                touch->clear();
                _ZNSt4listIlSaIlEEaSERKS1_(&ids, touch->getTouchIDList());
                if (cheatsUnlocked) {
                    void* state = getState(menuUpdateSettingsState);
                    if (getDepth() == static_cast<MenuState*>(state)->GetDepth())
                        _ZN5Menus18OptionGameSettings7RefreshEv(state);
                    SoundManager* sound = SoundManager::getInstance();
                    sound->unknown140 = true;
                    sound->playEx(217, 0, false, 1.0f, 0, true, 1.0f, 0);
                    sound->unknown140 = false;
                }
            } else {
                _ZN11MenuManager19s_currentSequenceIdE = 0;
            }
        }
        for (TouchIDList::const_iterator it = ids.begin(); it != ids.end(); ++it) {
            int index;
            for (index = 0; index < unknown184; ++index) {
                if (unknown168[index] == -1 || unknown168[index] == *it)
                    break;
            }
            if (index < 4) {
                if (unknown168[index] == -1) {
                    ++unknown184;
                    unknown168[index] = *it;
                }
                Point2D<short>* point = touch->getTouchPoint(unknown168[index]);
                entries[index].unknown12 = 1;
                entries[index].unknown0 = point->x;
                entries[index].unknown4 = point->y;
            }
        }
        for (int i = 0; i < unknown184; ++i)
            _ZN8RenderFX12UpdateCursorERNS_6CursorEi(reinterpret_cast<RenderFX*>(menuFX), &entries[i], i);
        for (int i = 0; i < unknown184; ++i) {
            if (entries[i].unknown12 == 0) {
                entries[i] = entries[unknown184 - 1];
                unknown168[i] = unknown168[unknown184 - 1];
                unknown168[unknown184 - 1] = -1;
                --unknown184;
                --i;
            }
        }
        MenuWidget* widget = getWidgetByIndex(23);
        if (consumedCursorCount == 0 && widget->IsVisible()
            && _ZNK7Widgets8Tutorial15IsCursorPressedEv(widget))
            consumeCursor();
    }
    if (!widgetVisibility)
        widgetVisibility = _ZN11MenuManager22updateWidgetVisibilityEv(this);
    if (!widgetVisibility || charAutoLineFeed != 0)
        reinterpret_cast<RenderFX*>(menuFX)->Update(static_cast<int>(_ZNK12StateMachine12getTimeStampEv(machine)), false);
}

#include "../rendering/RetailSwfString.h"
#include "../rendering/RetailSwfValue.h"

namespace {
// Text slot clip names, in eText order, then the property names read and written.
const char textCarName[] = "Texts.txtCarName";
const char textCopyright[] = "Texts.txtCopyright";
const char textCutsceneDialog[] = "Texts.txtCutsceneDialog";
const char textYName[] = "_y";
const char textCutsceneSkipButton[] = "Texts.txtCutsceneSkipButton";
const char textFailureEvent[] = "Texts.txtFailureEvent";
const char textFailureCause[] = "Texts.txtFailureCause";
const char textFailureTouchScreen[] = "Texts.txtFailureTouchScreen";
const char textLoadingTitle[] = "Texts.txtLoadingTitle";
const char textLoadingPerc[] = "Texts.txtLoadingPerc";
const char textMissionObjective[] = "Texts.txtMissionObjective";
const char textMissionCompleted[] = "Texts.txtMissionCompleted";
const char textMissionTitle[] = "Texts.txtMissionTitle";
const char textRaceTimer[] = "Texts.txtRaceTimer";
const char textSplashTouchScreen[] = "Texts.txtSplashTouchScreen";
const char textSplashMoreGames[] = "Texts.txtSplashMoreGames";
const char textTimer[] = "Texts.txtTimer";
const char textWarning[] = "Texts.txtWarning";
const char textHeightProperty[] = "textHeight";

// Partial field view of the text slots; never constructed or copied.
struct MenuManagerTextFields {
    unsigned char beforeMenuFX[188];
    MyMenuFX* menuFX;
    unsigned char beforeTexts[76];
    const char* texts[17];
    gameswf::character* characters[17];
    int visibleTexts;
    unsigned char beforeDialogY[8];
    int dialogY;
};

// gameswf::character member accessors at vtable slots 7 and 8.
struct TextMemberMethods {
    void (*beforeSetMember[7])();
    bool (*setMember)(gameswf::character*, const gameswf::tu_stringi&, const gameswf::as_value&);
    bool (*getMember)(gameswf::character*, const gameswf::tu_stringi&, gameswf::as_value*);
};

inline const TextMemberMethods& textMemberMethods(const gameswf::character* character)
{
    return **reinterpret_cast<const TextMemberMethods* const*>(character);
}
}

extern "C" void _ZN7gameswf8as_value10set_doubleEd(gameswf::as_value* value, double number);

extern "C" bool _ZN11MenuManager7setTextENS_5eTextEPKcPi(
    MenuManager* manager, MenuManager::eText slot, const char* text, int* arguments)
{
    MenuManagerTextFields& fields = *reinterpret_cast<MenuManagerTextFields*>(manager);
    if (static_cast<unsigned int>(slot) > 16)
        return false;
    if (fields.characters[slot] == 0) {
        switch (slot) {
        case 0: fields.characters[0] = fields.menuFX->Find(textCarName); break;
        case 1: fields.characters[1] = fields.menuFX->Find(textCopyright); break;
        case 2:
            fields.characters[2] = fields.menuFX->Find(textCutsceneDialog);
            if (fields.dialogY == -1) {
                gameswf::as_value y;
                textMemberMethods(fields.characters[2]).getMember(
                    fields.characters[2], gameswf::tu_stringi(textYName), &y);
                fields.dialogY = static_cast<int>(y.to_number());
            }
            break;
        case 3: fields.characters[3] = fields.menuFX->Find(textCutsceneSkipButton); break;
        case 4: fields.characters[4] = fields.menuFX->Find(textFailureEvent); break;
        case 5: fields.characters[5] = fields.menuFX->Find(textFailureCause); break;
        case 6: fields.characters[6] = fields.menuFX->Find(textFailureTouchScreen); break;
        case 7: fields.characters[7] = fields.menuFX->Find(textLoadingTitle); break;
        case 8: fields.characters[8] = fields.menuFX->Find(textLoadingPerc); break;
        case 9: fields.characters[9] = fields.menuFX->Find(textMissionObjective); break;
        case 10: fields.characters[10] = fields.menuFX->Find(textMissionCompleted); break;
        case 11: fields.characters[11] = fields.menuFX->Find(textMissionTitle); break;
        case 12: fields.characters[12] = fields.menuFX->Find(textRaceTimer); break;
        case 13: fields.characters[13] = fields.menuFX->Find(textSplashTouchScreen); break;
        case 14: fields.characters[14] = fields.menuFX->Find(textSplashMoreGames); break;
        case 15: fields.characters[15] = fields.menuFX->Find(textTimer); break;
        case 16: fields.characters[16] = fields.menuFX->Find(textWarning); break;
        }
    }
    gameswf::character* character = fields.characters[slot];
    if (character == 0)
        return false;
    if (!isCharacterVisible(character) && text)
        ++fields.visibleTexts;
    else if (isCharacterVisible(fields.characters[slot]) && !text)
        --fields.visibleTexts;
    gameswf::character* shown = fields.characters[slot];
    const bool visible = text != 0;
    setCharacterVisible(shown, visible);
    fields.texts[slot] = text;
    if (!visible)
        return true;
    _ZN11MenuManager13setMenuFXTextEPN7gameswf9characterEPKcbb(
        manager, fields.characters[slot], text, true, false);
    gameswf::as_value value;
    if (arguments || slot == 2) {
        textMemberMethods(fields.characters[slot]).getMember(
            fields.characters[slot], gameswf::tu_stringi(textHeightProperty), &value);
        int height = static_cast<int>(value.to_number());
        if (arguments)
            *arguments = height;
        if (slot == 2) {
            height += 4;
            if (arguments)
                *arguments = height;
            int screenWidth, screenHeight;
            Application::GetInstance()->GetScreenDimensions(screenWidth, screenHeight);
            const int bottom = screenHeight;
            const int dialogY = fields.dialogY;
            int y;
            if (height > bottom - dialogY)
                y = bottom - height;
            else
                y = dialogY;
            _ZN7gameswf8as_value10set_doubleEd(&value, y);
            textMemberMethods(fields.characters[slot]).setMember(
                fields.characters[slot], gameswf::tu_stringi(textYName), value);
        }
    }
    return true;
}
