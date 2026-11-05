/*
 * SwipeButton
 *
 * Original file: SwipeButton.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SwipeButton.cpp here, in the order they appear in the library.
 */

#include "SwipeButton.h"
#include "../app/Application.h"
#include "../core/ASprite.h"
#include "../input/TouchScreenBase.h"

void SwipeButton::processTouchRelease() {}

void SwipeButton::draw2d() const
{
    if (flags & 1)
        sprite->PaintFrame(frame, 0, 0, 0);
}

void SwipeButton::processTouch(long touch)
{
    if (flags & 1) {
        TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
        int direction = screen->getSwipeDirection(touch);
        if (direction == 0) {
            swipeDirection = 0;
        } else {
            swipeDirection = direction;
            screen->clearTouchPoint(touch);
        }
    }
}

void SwipeButton::update(double)
{
    if (flags & 1) {
        long touch = Application::GetInstance()->GetTouchScreen()->getTouchIDInitiatedInRegion(
            reinterpret_cast<const irr::core::rect<float>&>(touchRegion));
        if (touch != -1)
            processTouch(touch);
    }
}

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_2()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11SwipeButtonC2EP7ASpritei() __attribute__((used));
static void _GLOBAL__I__ZN11SwipeButtonC2EP7ASpritei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
