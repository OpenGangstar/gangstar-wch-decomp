/*
 * SlideControl
 *
 * Original file: SlideControl.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SlideControl.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "SlideControl.h"
#include "../input/StickReleaseEvents.h"
#include "../app/Application.h"
#include "../input/TouchScreenBase.h"
#include "../core/ASprite.h"
#include "../hud/HudDrawColor.h"

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
static void _GLOBAL__I__ZN12SlideControlC2EP7ASpriteiiNS_16SlideControlModeE() __attribute__((used));
static void _GLOBAL__I__ZN12SlideControlC2EP7ASpriteiiNS_16SlideControlModeE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

SlideControl::~SlideControl()
{
}

void SlideControl::reset()
{
    flags &= ~2u;
    unknown76 = 0.0f;
    unknown80 = 0.0f;
    unknown84 = 0.0f;
}

void SlideControl::update(double)
{
    if (!(flags & 1))
        return;

    TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
    const irr::core::rect<float>& region = reinterpret_cast<const irr::core::rect<float>&>(touchRegion);
    const long id = screen->getTouchIDInitiatedInRegion(region);
    if (id != -1)
        processTouch(id);
    else
        processTouchRelease();
}

void SlideControl::draw2d() const
{
    if (!(flags & 1))
        return;

    irr::video::SColor colors[4];
    if ((flags & 16) && (unknown52 & 256)) {
        setHudColor(colors[0], 191, 51);
        setHudColor(colors[1], 191, 51);
        setHudColor(colors[2], 191, 51);
        setHudColor(colors[3], 191, 51);
        ASprite::s_global_color = colors;
    } else if (!(flags & 2)) {
        setHudColor(colors[0], 128, 255);
        setHudColor(colors[1], 128, 255);
        setHudColor(colors[2], 128, 255);
        setHudColor(colors[3], 128, 255);
        ASprite::s_global_color = colors;
    }

    sprite->PaintFrame(frame, 0, 0, 0);
    sprite->PaintFrame(handleFrame, static_cast<int>(unknown80), static_cast<int>(unknown84), 0);
    ASprite::s_global_color = 0;
}

extern "C" void _ZN24EvLeftRightStickReleasedD1Ev(void*) __attribute__((weak));
extern "C" void _ZN21EvUpDownStickReleasedD1Ev(void*) __attribute__((weak));

void SlideControl::processTouchRelease()
{
    if (!(flags & 1u))
        return;

    unsigned int horizontalStorage[sizeof(EvLeftRightStickReleased) / sizeof(unsigned int)];
    unsigned int verticalStorage[sizeof(EvUpDownStickReleased) / sizeof(unsigned int)];
    if (flags & 2u) {
        if (mode == Horizontal) {
            EventManager* events = Application::GetInstance()->GetEventManager();
            EvLeftRightStickReleased* event = new (horizontalStorage) EvLeftRightStickReleased(releasedRight, unknown76);
            events->raise(*event);
            _ZN24EvLeftRightStickReleasedD1Ev(event);
        } else {
            EventManager* events = Application::GetInstance()->GetEventManager();
            EvUpDownStickReleased* event = new (verticalStorage) EvUpDownStickReleased(releasedUp, unknown76);
            events->raise(*event);
            _ZN21EvUpDownStickReleasedD1Ev(event);
        }
    }
    unknown80 = 0.0f;
    unknown84 = 0.0f;
    flags &= ~2u;
}
