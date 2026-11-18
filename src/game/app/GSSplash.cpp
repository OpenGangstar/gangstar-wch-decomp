/*
 * GSSplash
 *
 * Original file: GSSplash.cpp
 * Area:          app
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GSSplash.cpp here, in the order they appear in the library.
 */

#include "GSSplash.h"

#include "../core/LocalSdkStartupStorage.h"

#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

GSSplash::GSSplash() {}

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
    }
}

extern "C" {
static void _GLOBAL__I_m_splash() __attribute__((used));
static void _GLOBAL__I_m_splash()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_3()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

GSSplash::~GSSplash() {}

#include "Application.h"
#include "../input/TouchScreenBase.h"
#include "../hud/MenuManager.h"
extern "C" void _ZN11MenuManager3popEb(MenuManager*, bool);

void GSSplash::dtor(const StateMachine*)
{
    Application::GetInstance()->GetTouchScreen()->clear();
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(14), -1, 0);
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(13), -1, 0);
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(1), -1, 0);
    _ZN11MenuManager3popEb(MenuManager::getInstance(), true);
}

#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
static const char splashMenuName[]="Splash";
extern "C" bool m_splash;
void GSSplash::ctor(const StateMachine*)
{
    Application::GetInstance()->GetTouchScreen()->clear();
    MenuManager::getInstance()->showTexts();
    MenuManager::getInstance()->push(splashMenuName,true);
    startedAt=Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    m_splash=true;
}

#include "../audio/SoundManager.h"
#include "../core/SceneNode.h"
#include "../core/Rect.h"
extern bool m_splash;
extern "C" unsigned char nativeIsVideoPlayDone(void);
extern "C" void* _ZN12StateMachine11switchStateI10GSMainMenuEEPT_v(StateMachine*) __attribute__((weak));
void GSSplash::update(StateMachine* machine)
{
    if (m_splash) {
        SoundManager::getInstance()->init();
        if (nativeIsVideoPlayDone()) {
            SoundManager::getInstance()->playLowFpsMusic(29,true);
            m_splash=false;
        }
    }
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(1),0x5002,0);
    Application* application=Application::GetInstance();
    if (application->GetDevice()->getTimer()->getRealTime() & 0x200)
        MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(13),0x5001,0);
    else
        MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(13),-1,0);
    TouchScreenBase* touch=application->GetTouchScreen();
    const irr::core::rect<float> region(0,0,480,320);
    if (touch->isRegionPressed(region)) {
        SoundManager::getInstance()->stopLowFpsMusic();
        _ZN12StateMachine11switchStateI10GSMainMenuEEPT_v(machine);
    }
}
