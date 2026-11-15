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
#include "../core/VideoDriver.h"
#include "../persistence/SaveGame.h"
#include "../persistence/SaveGameInterfaces.h"
#include "../audio/SoundManager.h"
#include "../vehicles/Vehicle.h"
#include "../core/GameEventMethods.h"
#include "../core/SceneNode.h"
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
struct RegistrationLink {
    RegistrationLink* next;
    RegistrationLink* previous;
};
template<class T> struct _List_node : RegistrationLink {
    T value;
};
}

namespace std {
template<class T> class allocator {
public:
    T* allocate(unsigned int count, const void* hint) __attribute__((weak));
};

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
    removeRegistration(unknownPrefix + 28, receiver);
}

void Application::UnRegisterForDrawingOnHUD(IDrawable* drawable)
{
    removeRegistration(unknownPrefix + 20, drawable);
}

void Application::UnRegisterForDrawingInScene(IDrawable* drawable)
{
    removeRegistration(unknownPrefix + 12, drawable);
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
    appendRegistration(unknownPrefix + 28, *reinterpret_cast<stlp_priv::RegistrationLink**>(unknownPrefix + 32), receiver);
}

void Application::RegisterForDrawingInScene(IDrawable* drawable)
{
    appendRegistration(unknownPrefix + 12, *reinterpret_cast<stlp_priv::RegistrationLink**>(unknownPrefix + 16), drawable);
}

void Application::RegisterForDrawingOnHUD(IDrawable* drawable)
{
    appendRegistration(unknownPrefix + 20, *reinterpret_cast<stlp_priv::RegistrationLink**>(unknownPrefix + 24), drawable);
}

void Application::RegisterForUpdate(IUpdatable* object)
{
    appendRegistration(unknownPrefix + 4, *reinterpret_cast<stlp_priv::RegistrationLink**>(unknownPrefix + 8), object);
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
