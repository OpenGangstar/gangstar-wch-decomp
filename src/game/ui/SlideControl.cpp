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

SlideControl::SlideControl(ASprite* sprite, int trackFrame, int handleFrame,
                           SlideControlMode mode)
    : HudElement(sprite, trackFrame, true)
{
    this->mode = mode;
    unknown76 = 0.0f;
    unknown80 = 0.0f;
    unknown84 = 0.0f;
    knobCenterX = 0.0f;
    knobCenterY = 0.0f;
    releasedUp = false;
    releasedRight = false;
    this->handleFrame = handleFrame;

    const int trackIndex = frame;
    const SpriteFrame* trackSpriteFrame = this->sprite->GetFrame(trackIndex);
    const SpriteFrameModule* track = this->sprite->GetFModule(static_cast<int>(trackSpriteFrame->firstModule));
    const float trackY = track->y;
    const float trackX = track->x;
    unknown32 = trackX;
    unknown36 = trackY;
    const SpriteModule* trackModule = this->sprite->GetModule(track->module);
    const SpriteFrame* knobSpriteFrame = this->sprite->GetFrame(this->handleFrame);
    const SpriteFrameModule* knob = this->sprite->GetFModule(knobSpriteFrame->firstModule);
    unknown80 = 0;
    unknown84 = 0;
    const SpriteModule* knobModule = this->sprite->GetModule(knob->module);
    const float centerY = (knobModule->height >> 1) + knob->y;
    const float centerX = (knobModule->width >> 1) + knob->x;
    knobCenterX = centerX;
    knobCenterY = centerY;

    if (this->mode == Horizontal) {
        horizontal = true;
        const int halfHeightDifference = (trackModule->height - knobModule->height) >> 1;
        minimumX = knob->x - track->x - halfHeightDifference;
        maximumX = track->x + trackModule->width - knob->x - knobModule->width - halfHeightDifference;
        const float left = track->x;
        const float top = track->y - 20;
        float right = trackModule->width;
        const int regionHeight = (trackModule->height + 20) << 1;
        right = left + right;
        // Stored again below; the extra use keeps the add in place so the
        // stores follow it as in retail. Flow removes this first store.
        touchRegion.coordinates[2] = right;
        touchRegion.coordinates[0] = left;
        touchRegion.coordinates[1] = top;
        touchRegion.coordinates[2] = right;
        const float heightFloat = regionHeight;
        touchRegion.coordinates[3] = top + heightFloat;
    } else {
        horizontal = false;
        const int halfWidthDifference = (trackModule->width - knobModule->width) >> 1;
        minimumY = knob->y - track->y - halfWidthDifference;
        maximumY = track->y + trackModule->height - knob->y - knobModule->height - halfWidthDifference;
        const float left = track->x - 16;
        const float top = track->y;
        float right = (trackModule->width + 16) << 1;
        const short regionHeight = trackModule->height;
        right = left + right;
        // Stored again below; the extra use keeps the add in place so the
        // stores follow it as in retail. Flow removes this first store.
        touchRegion.coordinates[2] = right;
        touchRegion.coordinates[0] = left;
        touchRegion.coordinates[1] = top;
        touchRegion.coordinates[2] = right;
        const float heightFloat = regionHeight;
        touchRegion.coordinates[3] = top + heightFloat;
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

#include "../ui/SlideControl.h"
#include "../app/Application.h"
#include "../input/TouchScreenBase.h"
#include "../core/EventManager.h"
#include "../core/GameEventMethods.h"
#include "../input/DirectionalStickEvents.h"
#include "../core/NativeStdio.h"
static const char invalidSlideTouch[] __attribute__((section(".rodata.slide_invalid_touch"))) =
    "SlideControl::processTouch: received invalid touchID: %i\n";

void SlideControl::processTouch(long touch)
{
    if (!(flags & 1))
        return;

    TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
    const Point2D<short>* current = screen->getTouchPoint(touch);
    if (!current) {
        printf(invalidSlideTouch, static_cast<int>(touch));
        return;
    }

    const Point2D<short>* first = screen->getFirstTouchPoint(touch);
    int x, y;
    if (horizontal) {
        x = current->x - first->x;
        y = current->y - first->y;
    } else {
        x = static_cast<int>(current->x - knobCenterX);
        y = static_cast<int>(current->y - knobCenterY);
    }

    const int mode = this->mode;
    if (mode == Horizontal)
        y = 0;
    if (mode == Vertical || !x) {
        if (!y)
            return;
        x = 0;
    }

    float xOffset, yOffset;
    if (mode == Horizontal) {
        if (x < 0) {
            rightward = false;
            const int negX = -x;
            const int limit = minimumX;
            if (negX > limit) {
                unknown76 = 1.0f;
                xOffset = static_cast<float>(-limit);
                yOffset = static_cast<float>(y);
            } else {
                xOffset = static_cast<float>(x);
                const float extent = static_cast<float>(limit);
                const float fraction = xOffset / extent;
                unknown76 = fraction > 0.0f ? fraction : -xOffset / extent;
                yOffset = static_cast<float>(y);
            }
        } else {
            rightward = true;
            if (x > maximumX) {
                unknown76 = 1.0f;
                xOffset = static_cast<float>(maximumX);
                yOffset = static_cast<float>(y);
            } else {
                const float offset = static_cast<float>(x);
                const float extent = static_cast<float>(maximumX);
                const float fraction = offset / extent;
                unknown76 = fraction > 0.0f ? fraction : -offset / extent;
                xOffset = offset;
                yOffset = static_cast<float>(y);
            }
        }
    } else if (y < 0) {
        upward = true;
        const int negY = -y;
        const int limit = minimumY;
        if (negY > limit) {
            unknown76 = 1.0f;
            xOffset = static_cast<float>(x);
            yOffset = static_cast<float>(-limit);
        } else {
            unknown76 = static_cast<float>(negY) / static_cast<float>(limit);
            xOffset = static_cast<float>(x);
            yOffset = static_cast<float>(y);
        }
    } else {
        const int limit = maximumY;
        upward = false;
        if (y > limit) {
            unknown76 = 1.0f;
            xOffset = static_cast<float>(x);
            yOffset = static_cast<float>(limit);
        } else {
            yOffset = static_cast<float>(y);
            unknown76 = yOffset / static_cast<float>(limit);
            xOffset = static_cast<float>(x);
        }
    }

    if (this->mode == Horizontal)
        Application::GetInstance()->GetEventManager()->raise(EvLeftRightStickMove(rightward, unknown76));
    else
        Application::GetInstance()->GetEventManager()->raise(EvUpDownStickMove(upward, unknown76));

    unknown80 = xOffset;
    unknown84 = yOffset;
    flags |= 2;
}
