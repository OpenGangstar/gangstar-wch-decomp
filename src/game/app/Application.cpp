/*
 * Application
 *
 * Original file: Application.cpp
 * Area:          app
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Application.cpp here, in the order they appear in the library.
 */

#include "Application.h"
#include "../core/ASprite.h"
#include "../core/SafeDelete.h"
#include "../input/CControlManager.h"
#include "../core/VideoDriver.h"
#include "../persistence/SaveGame.h"
#include "../persistence/SaveGameInterfaces.h"
#include "../audio/SoundManager.h"
#include "../vehicles/Vehicle.h"
#include "../core/GameEventMethods.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/VideoDriver.h"
#include "../ai/StateMachine.h"

void Application::GetScreenDimensions(int& width, int& height) const
{
    irr::core::dimension2d<unsigned int> dimensions = device->getVideoDriver()->getScreenSize();
    width = dimensions.Width;
    height = dimensions.Height;
}

// Recovered module startup family; storage remains local to this TU.
#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"
void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_application_transitions {
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
static void __tcf_5()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_application_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_application_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_application_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_application_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_application_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_application_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_application_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_application_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_application_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_application_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I_iAdditionMenuDepth() __attribute__((used));
static void _GLOBAL__I_iAdditionMenuDepth()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void Application::SetIsDemoVersion(bool enabled) { demoVersion = enabled; }
bool Application::GetIsDemoVersion() { return demoVersion; }
void __attribute__((noinline)) Application::ReInit(irr::IrrlichtDevice* newDevice) { device = newDevice; }
void Application::InitIPhoneFileSystem() {}
void Application::dumpMonitoredPointers() {}
void Application::SetDrawAll(bool enabled) { drawAll = enabled; }

CCustomMaterialRenderer* Application::GetMaterialRenderer() { return s_materialRenderer; }

void Application::SetDefaultLanguage(int language)
{
    if (static_cast<unsigned int>(language) <= 5)
        defaultLanguage = language;
}

void Application::ReInitWin32(irr::IrrlichtDevice* newDevice) { ReInit(newDevice); }

void Application::stopSoundThread()
{
    if (soundThreadPlaying) {
        SoundManager::getInstance()->stopLowFpsMusic();
        soundThreadPlaying = false;
    }
}

void Application::startSoundThread()
{
    if (soundNeedsInit) {
        SoundManager::getInstance()->init();
        RegisterForUpdate(SoundManager::getInstance());
        Vehicle::RegisterCarSoundsCallbacks();
        soundNeedsInit = false;
    }
    if (!soundThreadPlaying) {
        SoundManager::getInstance()->playLowFpsMusic(29, true);
        soundThreadPlaying = true;
    }
}

namespace stlp_priv {
template<class T> struct _List_node : RegistrationLink {
    T value;
};
}

#include "../core/NativeAllocator.h"
namespace std {
template<> stlp_priv::_List_node<irr::IEventReceiver*>* allocator<stlp_priv::_List_node<irr::IEventReceiver*> >::allocate(unsigned int count, const void* hint) __attribute__((weak));
template<> stlp_priv::_List_node<IUpdatable*>* allocator<stlp_priv::_List_node<IUpdatable*> >::allocate(unsigned int count, const void* hint) __attribute__((weak));
template<> stlp_priv::_List_node<IDrawable*>* allocator<stlp_priv::_List_node<IDrawable*> >::allocate(unsigned int count, const void* hint) __attribute__((weak));

// Partial view of the retail STLport list sentinel.
template<class T, class Alloc = allocator<T> > class list {
public:
    void remove(const T& value) __attribute__((weak));
};
}

namespace {
template<class T>
inline void removeRegistration(void* list, T*& object)
{
    if (object)
        static_cast<std::list<T*>*>(list)->remove(object);
}


}

void Application::UnRegisterForIrrlichtEvents(irr::IEventReceiver* receiver)
{
    removeRegistration(&eventReceivers, receiver);
}

void Application::UnRegisterForDrawingOnHUD(IDrawable* drawable)
{
    removeRegistration(&hudDrawables, drawable);
}

void Application::UnRegisterForDrawingInScene(IDrawable* drawable)
{
    removeRegistration(&sceneDrawables, drawable);
}

namespace {
template<class T>
inline void appendRegistration(void* list, stlp_priv::RegistrationLink*& tail, T* object)
{
    if (object) {
        typedef stlp_priv::_List_node<T*> Node;
        stlp_priv::RegistrationLink* root = static_cast<stlp_priv::RegistrationLink*>(list);
        Node* node = static_cast<std::allocator<Node>*>(list)->allocate(1, 0);
        node->value = object;
        stlp_priv::RegistrationLink* previous = tail;
        node->next = root;
        node->previous = previous;
        previous->next = node;
        tail = node;
    }
}
}

void Application::RegisterForIrrlichtEvents(irr::IEventReceiver* receiver)
{
    appendRegistration(&eventReceivers, eventReceivers._M_node._M_data.previous, receiver);
}

void Application::RegisterForDrawingInScene(IDrawable* drawable)
{
    appendRegistration(&sceneDrawables, sceneDrawables._M_node._M_data.previous, drawable);
}

void Application::RegisterForDrawingOnHUD(IDrawable* drawable)
{
    appendRegistration(&hudDrawables, hudDrawables._M_node._M_data.previous, drawable);
}

void Application::RegisterForUpdate(IUpdatable* object)
{
    appendRegistration(&updatables, updatables._M_node._M_data.previous, object);
}

void Application::Pause()
{
    stateMachine->sleep();
    if (GSLoading::isGameLoaded()) {
        SaveGame save;
        save.SampleAndSave(SaveGame::GetDefaultFilename());
    }
}

namespace {
const char resumeSpritePath[] __attribute__((section(".rodata.application_resume_sprite"))) =
    "./interrupt.bsprite";
const char logoSpritePath[] __attribute__((section(".rodata.application_logo_sprite"))) =
    "./gameloft_logo_01.bsprite";
}

void Application::StartGlobalResuming()
{
    resumeElapsed = 0;
    resumeFrame = 0;
    const unsigned int count = device->getVideoDriver()->getTextureManager()->getTextureCount();
    resumeInitialTextureCount = count;
    resumeTextureCount = count;
    if (!resumeSprite) {
        resumeSprite = new ASprite(resumeSpritePath);
        resumeSprite->unknown33 = false;
    }
}

namespace {
inline __attribute__((always_inline)) irr::video::IVideoDriver* beginSpriteFrame(
    irr::IrrlichtDevice* const& device, unsigned int background)
{
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    device->getSceneManager();
    device->getGUIEnvironment();
    driver->setClearColor(irr::video::SColor(255, background, background, background));
    driver->beginScene();
    driver->clearBuffers(3);
    driver->beginScene2D();
    return driver;
}

inline __attribute__((always_inline)) void endSpriteFrame(irr::video::IVideoDriver* driver)
{
    driver->endScene2D();
    driver->endScene();
    driver->swapBuffers(0);
}
}

template void SafeDelete<CControlManager>(CControlManager*&);

extern "C" int sWindowWidth;

void Application::LogoDraw()
{
    irr::video::IVideoDriver* driver = beginSpriteFrame(device, 255);
    logoSprite->PaintFrame(0, sWindowWidth / 3, 165, 0);
    endSpriteFrame(driver);
}

void Application::GlobalResumingDraw()
{
    irr::video::IVideoDriver* driver = beginSpriteFrame(device, 0);
    resumeSprite->PaintFrame(0, 0, 0, 0);
    resumeSprite->PaintFrame(1, 0, 0, 0);
    resumeSprite->PaintFrame(2 + 20 * resumeElapsed / resumeTextureCount, 0, 0, 0);
    endSpriteFrame(driver);
}

void Application::StartLogo()
{
    logoFrame = 0;
    logoFrameCount = 100;
    logoSprite = new ASprite(logoSpritePath);
    logoSprite->unknown33 = false;
}

void Application::LogoUpdate()
{
    if (logoFrame < logoFrameCount) {
        LogoDraw();
        if (++logoFrame == logoFrameCount) {
            delete logoSprite;
            logoSprite = 0;
        }
    }
}

namespace std {
template<class T> struct less;
template<class First, class Second> struct pair;
template<class Key, class Value, class Compare, class Alloc>
class map {
public:
    template<class Lookup> Value& operator[](const Lookup& key) __attribute__((weak));
};
}

namespace stlp_priv {
template<class Pair> struct _Select1st;
template<class Pair> struct _MapTraitsT;
template<class Key, class Compare, class Pair, class Select, class Traits, class Alloc>
class _Rb_tree {
public:
    unsigned int erase_unique(const Key& key) __attribute__((weak));
};
}

namespace {
typedef std::pair<void* const, const char*> MonitoredPointerEntry;
typedef std::allocator<MonitoredPointerEntry> MonitoredPointerAllocator;
typedef std::map<void*, const char*, std::less<void*>, MonitoredPointerAllocator> MonitoredPointerMap;
typedef stlp_priv::_Rb_tree<void*, std::less<void*>, MonitoredPointerEntry,
    stlp_priv::_Select1st<MonitoredPointerEntry>, stlp_priv::_MapTraitsT<MonitoredPointerEntry>,
    MonitoredPointerAllocator> MonitoredPointerTree;
}

namespace std {
template<> template<>
const char*& map<void*, const char*, less<void*>, MonitoredPointerAllocator>::operator[]<void*>(
    void* const& key) __attribute__((weak));
}

void Application::stopMonitoring(void* pointer)
{
    reinterpret_cast<MonitoredPointerTree*>(&monitoredPointers)->erase_unique(pointer);
}

void Application::startMonitoring(void* pointer, const char* name)
{
    (*reinterpret_cast<MonitoredPointerMap*>(&monitoredPointers))[pointer] = name;
}

// Observed IEvent-derived interface only; payload layout is not asserted.
class EvMouseMove : public IEvent {
public:
    virtual ~EvMouseMove() __attribute__((used)) {}
};

// Observed deletion interface only; payload and allocation extent remain unrecovered.
// Do not instantiate this partial event interface.
class EvKeyboard : public IEvent {
public:
    virtual ~EvKeyboard() __attribute__((used)) {}
};

// Observed event hierarchy only; no payload extent is asserted.
class EvMouseWheel : public IEvent {
public:
    virtual ~EvMouseWheel() __attribute__((used)) {}
};

// Partial event interface only; mouse-button payload remains unrecovered.
class EvMouseButton : public IEvent {
public:
    virtual ~EvMouseButton() __attribute__((used)) {}
};

bool Application::IsLogoOver()
{
    bool playing;
    if (logoFrame < logoFrameCount)
        playing = true;
    else
        playing = false;
    return !playing;
}

bool Application::IsGlobalResumingOver()
{
    bool resuming;
    if(resumeElapsed<resumeTextureCount)
        resuming=true;
    else
        resuming=false;
    return !resuming;
}

#include "../input/TouchScreenMouseEvent.h"
#include "../ui/MainMenu.h"
#include "../hud/MenuManager.h"
extern "C" int __android_log_print(int, const char*, const char*, ...);
static const char key_tag[] __attribute__((section(".rodata.application_key_tag"))) = "@d.d";
static const char key_back[] __attribute__((section(".rodata.application_key_back"))) = "------------------------appKeyReleased: TYPE_KEY_BACK:%d";
static const char key_igm[] __attribute__((section(".rodata.application_key_igm"))) = "------------------------appKeyReleased:TYPE_KEY_TO_IGM%d";
static const char key_mm[] __attribute__((section(".rodata.application_key_mm"))) = "------------------------appKeyReleased:TYPE_KEY_TO_MM%d";
static const char key_device[] __attribute__((section(".rodata.application_key_device"))) = "------------------------appKeyReleased:TYPE_KEY_TO_DEVICE%d";
static const char key_post[] __attribute__((section(".rodata.application_key_post"))) = "------------------------appKeyReleased:TYPE_KEY_TO_DEVICE:postEventFromUser";
static const char key_main[] __attribute__((section(".rodata.application_key_main"))) = "MainMenu";
void Application::ProcessKeyEvent(bool pressed, int type)
{
    irr::SEvent event;
    if (pressed) {
        event.type = irr::SEvent::MouseInputEvent;
        event.mouse.event = irr::SEvent::LeftPressed;
    } else {
        event.type = irr::SEvent::MouseInputEvent;
        event.mouse.event = irr::SEvent::LeftReleased;
    }
    if (type == 1) {
        __android_log_print(4, key_tag, key_back, !pressed);
        event.mouse.x = 20;
        event.mouse.y = 313;
        device->postEventFromUser(event);
    } else if (type == 2) {
        __android_log_print(4, key_tag, key_igm, !pressed);
        event.mouse.x = 33;
        event.mouse.y = 33;
        device->postEventFromUser(event);
    } else if (type == 3) {
        __android_log_print(4, key_tag, key_mm, !pressed);
        event.mouse.x = 66;
        event.mouse.y = 240;
        device->postEventFromUser(event);
    } else if (type == 4) {
        if (pressed) {
            __android_log_print(4, key_tag, key_device, 0);
        } else {
            __android_log_print(4, key_tag, key_device, 1);
            static_cast<Menus::MainMenu*>(MenuManager::getInstance()->getState(key_main))->SetPause(true);
        }
        return;
    }
    __android_log_print(4, key_tag, key_post);
}

#include "../hud/MenuManager.h"
extern bool bIsInCutscene;
extern int iAdditionMenuDepth;

extern "C" void nativeNotifyPause();

void Application::appKeyReleased(int key)
{
    if (stateMachine->states.back()->isKindOf(19) || bIsInCutscene)
        return;
    lastPressedKey = -1;
    if (key == 82) {
        if (stateMachine->states.back()->isKindOf(16)) {
            if (MenuManager::getInstance()->getDepth() - iAdditionMenuDepth <= 1)
                ProcessKeyEvent(false, 1);
        } else if (stateMachine->states.back()->isKindOf(1)) {
            ProcessKeyEvent(false, 2);
        }
    } else if (key == 4) {
        if (stateMachine->states.back()->isKindOf(16)) {
            if (MenuManager::getInstance()->getDepth() - iAdditionMenuDepth > 1)
                ProcessKeyEvent(false, 1);
            else
                ProcessKeyEvent(false, 3);
        } else if (stateMachine->states.back()->isKindOf(18)) {
            if (MenuManager::getInstance()->getDepth() - iAdditionMenuDepth > 1)
                ProcessKeyEvent(false, 1);
            else
                ProcessKeyEvent(false, 4);
        } else if (stateMachine->states.back()->isKindOf(1)) {
            ProcessKeyEvent(false, 2);
        } else if (stateMachine->states.back()->isKindOf(23)) {
            ProcessKeyEvent(false, 1);
        } else if (stateMachine->states.back()->isKindOf(22)) {
            ProcessKeyEvent(false, 1);
        } else if (stateMachine->states.back()->isKindOf(21)) {
            nativeNotifyPause();
        }
    }
}

#include "../hud/MenuManager.h"
extern bool bIsInCutscene;
extern int iAdditionMenuDepth;

void Application::appKeyPressed(int key)
{
    if (bIsInCutscene || lastPressedKey == key)
        return;
    lastPressedKey = key;
    if (key == 82) {
        if (stateMachine->states.back()->isKindOf(16)) {
            if (MenuManager::getInstance()->getDepth() - iAdditionMenuDepth <= 1)
                ProcessKeyEvent(true, 1);
        } else if (stateMachine->states.back()->isKindOf(1)) {
            ProcessKeyEvent(true, 2);
        }
    } else if (key == 4) {
        if (stateMachine->states.back()->isKindOf(16)) {
            if (MenuManager::getInstance()->getDepth() - iAdditionMenuDepth > 1)
                ProcessKeyEvent(true, 1);
            else
                ProcessKeyEvent(true, 3);
        } else if (stateMachine->states.back()->isKindOf(18)) {
            if (MenuManager::getInstance()->getDepth() - iAdditionMenuDepth > 1)
                ProcessKeyEvent(true, 1);
            else
                ProcessKeyEvent(true, 4);
        } else if (stateMachine->states.back()->isKindOf(1)) {
            ProcessKeyEvent(true, 2);
        } else if (stateMachine->states.back()->isKindOf(23)) {
            ProcessKeyEvent(true, 1);
        } else if (stateMachine->states.back()->isKindOf(22)) {
            ProcessKeyEvent(true, 1);
        }
    }
}


extern "C" int __android_log_print(int priority, const char* tag, const char* format, ...);

void Application::GlobalResumingUpdate()
{
    __android_log_print(4, "DINH.LETAN", "GlobalResumingUpdate:m_intStepTotal :%D ", resumeTextureCount);
    if (resumeElapsed < resumeTextureCount) {
        __android_log_print(4, "DINH.LETAN", "GlobalResumingUpdate:m_intSubStep :%D ", resumeFrame);
        if (stateMachine->states.back()->isKindOf(21)) {
            if (resumeFrame == 3)
                device->getVideoDriver()->getTextureManager()->reloadAllTextures();
        } else {
            device->getVideoDriver()->getTextureManager()->reloadTexture(resumeFrame);
        }
        ++resumeFrame;
        ++resumeElapsed;
        GlobalResumingDraw();
        if (resumeElapsed >= resumeTextureCount) {
            __android_log_print(4, "DINH.LETAN", "m_intStep == m_intStepTotal:m_intSubStep :%D ", resumeFrame);
            delete resumeSprite;
            resumeSprite = 0;
            if (stateMachine->states.back()->isKindOf(18)
                || stateMachine->states.back()->isKindOf(21))
                SoundManager::getInstance()->playLowFpsMusic(29, true);
        }
    }
}


extern "C" int __android_log_print(int priority, const char* tag, const char* format, ...);
static const char applicationUpdateLoop[] __attribute__((section(".rodata.application_update_loop"))) = "Loop @@@@@@@@@@@@@@@@@@@@";
static unsigned int s_frameUpdateStart;
static float s_frameTotalUpdateTime;
static unsigned int s_frameUpdateCount;
static float s_frameUpdateTime;

void Application::Update()
{
    if (!IsGlobalResumingOver()) {
        GlobalResumingUpdate();
        __android_log_print(4, "DINH.LETAN", applicationUpdateLoop);
        return;
    }
    irr::ITimer* timer = device->getTimer();
    unsigned int now = timer->getRealTime();
    if (!s_frameUpdateStart)
        s_frameUpdateStart = now;
    StateBase* state = stateMachine->states.back();
    _Update(now - lastUpdateTime);
    if (state == stateMachine->states.back())
        _Draw();
    lastUpdateTime = now;
    s_frameTotalUpdateTime += static_cast<float>(timer->getRealTime() - now);
    ++s_frameUpdateCount;
    if (s_frameTotalUpdateTime >= 1500.0f) {
        s_frameUpdateTime = s_frameTotalUpdateTime / s_frameUpdateCount;
        s_frameUpdateStart = 0;
        s_frameUpdateCount = 0;
        s_frameTotalUpdateTime = 0.0f;
    }
}

#include "../hud/CHudManager.h"
#include "../core/NativeStdio.h"
static const char numberFormat[] __attribute__((section(".rodata.application_number_format"))) = "%i";
void Application::displayNumberWithHUDSprite(int number, int horizontalAlign, int verticalAlign, const char* format)
{
    static const int frames[10] = {96,87,88,89,90,91,92,93,94,95};
    ASprite* sprite = hudManager->reviveSprite;
    if (!sprite)
        return;
    if (number < 0)
        number = 0;
    char buffer[12];
    if (format)
        sprintf(buffer,format,number);
    else
        sprintf(buffer,numberFormat,number);
    int width,height;
    GetScreenDimensions(width,height);
    if (verticalAlign < 0)
        height = 4;
    else if (verticalAlign > 0)
        height = height - 4 - sprite->GetFrameHeight(96);
    else
        height = (height - sprite->GetFrameHeight(96))/2;
    int textWidth = 0;
    int i = 0;
    char digit;
    while ((digit = buffer[i]) != 0) {
        textWidth += sprite->GetFrameWidth(frames[digit-'0']);
        ++i;
    }
    if (horizontalAlign < 0)
        width = 4;
    else if (horizontalAlign > 0)
        width = width-4-textWidth;
    else
        width = (width-textWidth)/2;
    i = 0;
    while ((digit = buffer[i]) != 0) {
        int frame = frames[digit-'0'];
        sprite->PaintFrame(frame,width,height,0);
        width += sprite->GetFrameWidth(frame);
        ++i;
    }
}


#include "../input/TouchScreenBase.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../ui/GSInGameMenu.h"

template<> GSInGameMenu* StateMachine::pushState<GSInGameMenu>() __attribute__((weak));
extern int needInterruptReload;
static bool isFirstTime = true;
static const char applicationResumeTag[] __attribute__((section(".rodata.application_resume_tag"))) = "m_stateMachine->wakeup();";
static const char applicationResumeMessage[] __attribute__((section(".rodata.application_resume_message"))) = "m_stateMachine->wakeup() 111111111111111";
static const char applicationResumeMap[] __attribute__((section(".rodata.application_resume_map"))) = "Map";

void Application::Resume()
{
    if (isFirstTime) {
        isFirstTime = false;
    } else if (needInterruptReload) {
        device->getVideoDriver()->getTextureManager()->unloadAllTextures();
        device->reinitDriver();
        if (!stateMachine->states.back()->isKindOf(21))
            StartGlobalResuming();
        StartGlobalResuming();
        if (stateMachine->states.back()->isKindOf(21))
            MenuManager::getInstance()->preloadGlyphs(true);
        needInterruptReload = 0;
    }

    if (PlayerTest::GetPlayer() && !(PlayerTest::GetPlayer()->flags240 & 1)
        && !hudManager->isLocked())
        PlayerTest::GetPlayer()->Stop();
    lastUpdateTime = device->getTimer()->getRealTime();
    touchScreen->clear();
    stateMachine->wakeup();
    __android_log_print(4, applicationResumeTag, applicationResumeMessage);
    if (hudManager->isMinimapVisible() && !hudManager->isLocked()) {
        stateMachine->pushState<GSInGameMenu>();
    } else if (MenuManager::getInstance()->isInGameMenu()) {
        MenuManager::getInstance()->popTo(applicationResumeMap, false, true);
    } else if (IsGlobalResumingOver()) {
        SoundManager::getInstance()->resumeAllSounds();
    }
}

Application* Application::GetInstance()
{
    static Application app;
    return &app;
}

Application::~Application()
{
}

#include "../persistence/FileSystemWin32.h"
#include "../input/TouchScreenWin32.h"
#include "../input/AccelerometerWin32.h"
#include "../ui/OptionGameSettings.h"

void Application::InitWin32(irr::IrrlichtDevice* newDevice)
{
    fileSystem = new FileSystemWin32;
    touchScreen = new TouchScreenWin32;
    accelerometer = new AccelerometerWin32;
    RegisterForUpdate(touchScreen);
    RegisterForIrrlichtEvents(static_cast<TouchScreenWin32*>(touchScreen));
    RegisterForUpdate(accelerometer);
    RegisterForIrrlichtEvents(static_cast<AccelerometerWin32*>(accelerometer));
    Init(newDevice);
    Menus::OptionGameSettings::SetOrientation(static_cast<int>(Menus::OptionGameSettings::GetOrientation()));
}

#include "../core/FactoryFileSystem.h"
#include "../core/EventManager.h"
#include "../hud/CHudManager.h"
#include "../persistence/StringManager.h"
#include "../persistence/FileManager.h"
#include "../ui/Preferences.h"
#include "../hud/MenuManager.h"
#include "../core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.h"
#include "../core/MemHint.h"
#include "GSMoviePlayer.h"

extern const char* _IRR_REAL_RES_PATH_;
extern "C" void srand48(long seed);
template<> GSMoviePlayer* StateMachine::switchState<GSMoviePlayer>() __attribute__((weak));
static const char applicationTextStyles[] __attribute__((section(".rodata.application_text_styles"))) = "./TextStyles.gmap";
static const char applicationAchievements[] __attribute__((section(".rodata.application_achievements"))) = "./Achievements.gmap";

void Application::Init(irr::IrrlichtDevice* newDevice)
{
    device = newDevice;
    newDevice->getFileSystem()->changeWorkingDirectoryTo(_IRR_REAL_RES_PATH_);
    newDevice->setEventReceiver(this);
    irr::core::matrix4 transform;
    transform.setTranslation(irr::core::vector3d<float>(-0.375f, -0.375f, 0.0f));
    ASprite::s_global_transform = transform;
    eventManager = new EventManager;
    eventManager->groupCount = 0;
    for (int i = 0; i < 200; ++i) {
        eventManager->groups[i].eventID = -1;
        eventManager->groups[i].count = 0;
    }
    eventManager->pendingAttachCount = 0;
    eventManager->pendingDetachCount = 0;
    eventManager->queuedCount = 0;
    controlManager = new CControlManager;
    stateMachine = StateMachine::getInstance();
    weaponManager = new WeaponManager;
    stringManager = new StringManager;
    stringManager->loadPack(defaultLanguage);
    stringManager->switchPack(defaultLanguage);
    stringManager->loadStyles(applicationTextStyles);
    hudManager = new CHudManager;
    ScriptManager::getInstance()->setup();
    RegisterForUpdate(eventManager);
    RegisterForUpdate(hudManager);
    RegisterForDrawingInScene(stateMachine);
    lastUpdateTime = device->getTimer()->getRealTime();
    srand48(lastUpdateTime);
    targetFrameRate = 60;
    AchievementManager* achievements = AchievementManager::s_achievementManager;
    achievements->load(applicationAchievements);
    achievements->init();
    MenuManager::getInstance()->setup(defaultLanguage == 5);
    FileManager::Init();
    Preferences preferences;
    if (!preferences.LoadAndApply(Preferences::GetDefaultFilename())) {
        MenuManager::getInstance()->enableAsianFont(defaultLanguage == 5);
        MenuManager::getInstance()->preloadGlyphs(true);
    }
    stateMachine->switchState<GSMoviePlayer>();
    s_materialRenderer = new (irr::DefaultMemHint) CCustomMaterialRenderer_VERTEX_COLOR_ALPHA(
        static_cast<irr::video::CCommonGLDriver*>(newDevice->getVideoDriver()));
}

#include "../input/AccelerometerBase.h"
#include "../input/TouchScreenBase.h"
#include "../hud/CHudManager.h"
#include "../combat/WeaponManager.h"
#include "../persistence/StringManager.h"
#include "../persistence/FileSystemBase.h"
#include "../persistence/FileManager.h"
#include "../meta/Achievements.h"
#include "../rendering/GS3DStuff.h"
#include "../scripting/ScriptManager.h"
#include "../missions/Mission.h"
#include "../core/EventManager.h"
#include "../core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.h"
void Application::Quit()
{
    if (GSLoading::isGameLoaded()
        && static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getState() != 4) {
        SaveGame save;
        save.SampleAndSave(SaveGame::GetDefaultFilename());
    }
    stopSoundThread();
    UnRegisterForUpdate(SoundManager::getInstance());
    AchievementManager::s_achievementManager->clear();
    if (stateMachine)
        while (static_cast<int>(stateMachine->states.size()) > 0)
            stateMachine->popState();
    GS3DStuff::tearDown();
    // Concrete type is not recovered. The native ABI calls its deleting
    // destructor through vtable slot1 with the unchanged object receiver.
    if (unknown60) {
        typedef void (*DeletingDestructor)(void*);
        DeletingDestructor* table = *reinterpret_cast<DeletingDestructor**>(unknown60);
        table[1](unknown60);
    }
    unknown60 = 0;
    if (unknown52)
        ::operator delete(unknown52);
    unknown52 = 0;
    delete accelerometer;
    accelerometer = 0;
    delete touchScreen;
    touchScreen = 0;
    delete fileSystem;
    fileSystem = 0;
    SafeDelete(controlManager);
    delete hudManager;
    hudManager = 0;
    delete weaponManager;
    weaponManager = 0;
    delete stringManager;
    stringManager = 0;
    delete eventManager;
    eventManager = 0;
    Vehicle::UnRegisterCarSoundsCallbacks();
    if (device) {
        device->closeDevice();
        device->drop();
    }
    if (s_materialRenderer && !s_materialRenderer->drop()) {
        delete s_materialRenderer;
        s_materialRenderer = 0;
    }
    FileManager::Destroy();
}

#include "ApplicationListIterator.h"

void Application::_Update(int elapsed)
{
    typedef stlp_priv::_List_iterator<IUpdatable*, std::_Nonconst_traits<IUpdatable*> > iterator;
    iterator first(updatables._M_node._M_data.next);
    const double time = elapsed;
    iterator last(&updatables._M_node._M_data);
    for (; first != last; ++first)
        (*first)->update(time);
    stateMachine->update(time);
    MenuManager::getInstance()->update(stateMachine);
    device->getVideoDriver();
    device->getSceneManager()->getParameters();
}

#include "ApplicationListIterator.h"
#include "../scripting/ScriptManager.h"
void Application::_Draw()
{
    if (!stateMachine->isDrawable())
        return;
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* scene = device->getSceneManager();
    device->getGUIEnvironment();
    driver->setClearColor(irr::video::SColor(255, 0, 0, 0));
    driver->beginScene();
    driver->clearBuffers(3);
    scene->update(-123456.0f, false);
    if (drawAll)
        scene->drawAll(0);
    typedef stlp_priv::_List_iterator<IDrawable*, std::_Nonconst_traits<IDrawable*> > iterator;
    {
        iterator first(sceneDrawables._M_node._M_data.next);
        iterator last(&sceneDrawables._M_node._M_data);
        for (; first != last; ++first)
            (*first)->draw();
    }
    driver->beginScene2D();
    {
        iterator first(hudDrawables._M_node._M_data.next);
        iterator last(&hudDrawables._M_node._M_data);
        for (; first != last; ++first)
            (*first)->draw2d();
    }
    stateMachine->draw2d();
    ScriptManager::getInstance()->draw();
    driver->endScene2D();
    MenuManager::getInstance()->draw(StateMachine::getInstance());
    driver->endScene();
    driver->swapBuffers(0);
}

// Literal reconstruction of the observed Android platform stub.
// Its unconditional write to address zero is not resolved to any known field.
// Return type is provisional without a live call-site use.
void Application::InitIPhone(irr::IrrlichtDevice*, float, float, float, float)
{
    InitIPhoneFileSystem();
    *static_cast<bool*>(0) = true;
}

extern "C" int nativedetectPhoneLang();
Application::Application()
    : fileSystem(0), unknown96(0.0f), drawAll(false), soundNeedsInit(true),
      soundThreadPlaying(false)
{
    touchScreen=0;
    accelerometer=0;
    unknown52=0;
    unknown60=0;
    stateMachine=0;
    controlManager=0;
    hudManager=0;
    weaponManager=0;
    unknown100=0;
    defaultLanguage=nativedetectPhoneLang();
    unknown144[0]=0;
    lastPressedKey=-1;
}
