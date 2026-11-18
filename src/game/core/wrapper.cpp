/*
 * wrapper
 *
 * Original file: wrapper.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of wrapper.cpp here, in the order they appear in the library.
 */

#include "NativeStdio.h"
#include "PathName.h"

void ekd_makestringfile255(const char* name, char* destination)
{
    if (name[0] == '.' && name[1] == '/') strcpy(destination, name + 2);
    else strcpy(destination, name);
}

// Recovered module startup family; storage remains local to this TU.
#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"
void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_wrapper_transitions {
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
static void __tcf_4()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_wrapper_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I_mouseLButtHeld() __attribute__((used));
static void _GLOBAL__I_mouseLButtHeld()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
extern int m_timerForResume;
void appResume()
{
    m_timerForResume = 1;
}
}

extern "C" void nativeOpenBrowser(const char* url);
static const char twitterUrl[] __attribute__((section(".rodata.wrapper_twitter_url"))) =
    "http://ingameads.gameloft.com/redir/?from=GAN2&op=ANMP&game=GAN2&t=twitter";
extern "C" void launchTwitter()
{
    nativeOpenBrowser(twitterUrl);
}

#include "../app/Application.h"
static Application* app;
extern "C" void appOnKeyUp(int key)
{
    if (app)
        app->appKeyReleased(key);
}

extern "C" void appOnKeyDown(int key)
{
    if (app)
        app->appKeyPressed(key);
}


#include "../input/TouchScreenMouseEvent.h"
#include "IrrlichtDevice.h"
static irr::IrrlichtDevice* device;
extern "C" {
extern bool mouseLButtHeld;
extern int __pointerId;
void appOnTouch(int pointerId, int action, int x, int y)
{
    __pointerId = pointerId;
    irr::SEvent event;
    irr::SEvent::MouseEvent mouseEvent;
    switch (action) {
    case 0:
        mouseLButtHeld = false;
        event.type = irr::SEvent::MouseInputEvent;
        mouseEvent = irr::SEvent::LeftReleased;
        break;
    case 1:
        mouseLButtHeld = true;
        event.type = irr::SEvent::MouseInputEvent;
        mouseEvent = irr::SEvent::LeftPressed;
        break;
    case 2:
        if (!mouseLButtHeld)
            return;
        event.type = irr::SEvent::MouseInputEvent;
        mouseEvent = irr::SEvent::MouseMoved;
        break;
    default:
        return;
    }
    event.mouse.event = mouseEvent;
    event.mouse.x = static_cast<int>(x * 0.6666);
    event.mouse.y = static_cast<int>(y * 0.6666);
    device->postEventFromUser(event);
}
}

// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered Irrlicht 1.4.2 interfaces for the observed fork hierarchy.
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgement in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be clearly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
// Restricted native call interface from Irrlicht 1.4.2 source/Irrlicht/os.h.
// No Timer object is instantiated and no engine implementation is supplied.
namespace irr { namespace os {
class Timer { public: static void tick(); };
} }
extern "C" {
extern int mTimeCallbackFinished;
void appRun()
{
    if (m_timerForResume > 0) {
        --m_timerForResume;
        if (m_timerForResume == 0)
            app->Resume();
    } else {
        mTimeCallbackFinished = 0;
        irr::os::Timer::tick();
        app->Update();
        mTimeCallbackFinished = 1;
    }
}
}

#include "../app/NativeMedia.h"
extern "C" void nativeUnloadSoundBig(int sound);
extern "C" void _ZN11Application4QuitEv(Application* application);
extern "C" void appDeinit()
{
    nativeStopAllSounds();
    nativeUnloadSoundBig(-1);
    _ZN11Application4QuitEv(app);
}


#include "../input/AccelerometerBase.h"
extern "C" {
extern float m_AccX, m_AccY, m_AccZ;
void appOnAccelerometer(void)
{
    const float x = m_AccX = 0.11f * m_AccX;
    const float y = m_AccY = 0.11f * m_AccY;
    const float z = m_AccZ = 0.11f * m_AccZ;
    if (device && app)
        app->accelerometer->moved(x, y, z);
}
}

extern "C" void appPause()
{
    app->Pause();
    m_timerForResume = 0;
}

#include "DeviceFactory.h"
extern "C" {
extern int _IRR_REAL_RES_SIZE_;
extern char* _IRR_REAL_RES_PATH_;
extern int sWindowWidth, sWindowHeight;
}
static const char wrapperResourcePath[] __attribute__((section(".rodata.wrapper_resource_path"))) =
    "/sdcard/gameloft/games/gangstar/";
extern "C" void appInit(void)
{
    _IRR_REAL_RES_SIZE_ = 32;
    _IRR_REAL_RES_PATH_ = new char[_IRR_REAL_RES_SIZE_ + 1];
    memset(_IRR_REAL_RES_PATH_, 0, _IRR_REAL_RES_SIZE_ + 1);
    memcpy(_IRR_REAL_RES_PATH_, wrapperResourcePath, _IRR_REAL_RES_SIZE_);
    device = irr::createDevice(irr::video::DriverType9,
        irr::core::dimension2d<int>(static_cast<int>(sWindowWidth / 1.5),
                                  static_cast<int>(sWindowHeight / 1.5)),
        16, false, false, false, 0);
    app = Application::GetInstance();
    app->InitWin32(device);
}
