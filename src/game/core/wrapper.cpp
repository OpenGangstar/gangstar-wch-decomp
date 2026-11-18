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
