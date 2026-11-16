/*
 * ToggleButton
 *
 * Original file: ToggleButton.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ToggleButton.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK string startup callbacks.
#include "ToggleButton.h"
#include "../core/ASprite.h"
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_0()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN12ToggleButtonC2EP7ASpriteii() __attribute__((used));
static void _GLOBAL__I__ZN12ToggleButtonC2EP7ASpriteii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void ToggleButton::processTouchRelease()
{
    if (flags & 1) {
        toggled = !toggled;
        VirtualButton::processTouchRelease();
    }
}

void ToggleButton::draw2d() const
{
    if (flags & 1) {
        if (toggled)
            HudElement::draw2d();
        else
            sprite->PaintFrame(inactiveFrame, 0, 0, 0);
    }
}
