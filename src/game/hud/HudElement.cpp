/*
 * HudElement
 *
 * Original file: HudElement.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of HudElement.cpp here, in the order they appear in the library.
 */

#include "../core/LocalStartupText.h"
#include "HudElement.h"
#include "HudDrawColor.h"
#include "../core/ASprite.h"
#include "../core/Color.h"
#include "../core/LocalSdkStartupStorage.h"

void operator delete(void*) throw();

typedef char HudElementExtent[sizeof(HudElement) == 56 ? 1 : -1];
typedef char HudTouchRegionExtent[sizeof(HudTouchRegion) == 16 ? 1 : -1];

void HudElement::hide()
{
    flags &= ~3u;
    wasInRegionLastFrame = false;
}

void HudElement::show() { flags |= 1; }

bool HudElement::isVisible() const { return flags & 1; }

bool HudElement::isBlinking() const { return (flags >> 4) & 1; }

void HudElement::reset()
{
    flags &= ~2u;
    unknown52 = 0;
}

void HudElement::setHand(bool value)
{
    if (value) flags |= 8;
    else flags &= ~8u;
}

void HudElement::processTouch(long) {}

void HudElement::processTouchRelease() {}

bool HudElement::isUsed() const { return (flags >> 1) & 1; }

void HudElement::setUsed(bool value)
{
    if (value) flags |= 2;
    else flags &= ~2u;
}

void HudElement::draw() const {}

void HudElement::update(double) {}

HudTouchRegion HudElement::getTouchRegion() const
{
    HudTouchRegion result;
    result.coordinates[0] = touchRegion.coordinates[0];
    result.coordinates[1] = touchRegion.coordinates[1];
    result.coordinates[2] = touchRegion.coordinates[2];
    result.coordinates[3] = touchRegion.coordinates[3];
    return result;
}

void HudElement::SetElemRegion(float a, float b, float c, float d)
{
    touchRegion.coordinates[0] = a;
    touchRegion.coordinates[1] = b;
    touchRegion.coordinates[2] = c;
    touchRegion.coordinates[3] = d;
}

int HudElement::getDrawingLayer() const { return 0; }

void HudElement::blink(bool enabled, bool force)
{
    unknown52 = 0;
    if ((isVisible() || force) && enabled) flags |= 16;
    else flags &= ~16u;
}

void HudElement::updateBlinkTimer(int elapsed) { unknown52 += elapsed; }

void HudElement::setWasInRegionLastFrame(bool value) { wasInRegionLastFrame = value; }

void HudElement::draw2d() const
{
    if (!(flags & 1)) return;
    irr::video::SColor colors[4];
    if ((flags & 16) && (unknown52 & 256)) {
        setHudColor(colors[0],191,51);
        setHudColor(colors[1],191,51);
        setHudColor(colors[2],191,51);
        setHudColor(colors[3],191,51);
        ASprite::s_global_color = colors;
    } else {
        if (flags & 2) goto paint;
        if (flags & 4) {
            setHudColor(colors[0],128,255);
            setHudColor(colors[1],128,255);
            setHudColor(colors[2],128,255);
            setHudColor(colors[3],128,255);
            ASprite::s_global_color = colors;
        }
    }
paint:
    sprite->PaintFrame(frame,0,0,0);
    ASprite::s_global_color = 0;
}

HudElement::HudElement(ASprite* value, int firstFrame, bool hand)
    : flags(8), touchRegion(), unknown32(0.0f), unknown36(0.0f),
      sprite(value), frame(firstFrame), unknown52(0)
{
    if (hand) flags = 4;
}

HudElement::~HudElement() {}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
static void __tcf_2(void*) __attribute__((used));
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
        __aeabi_atexit(0, __tcf_2, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN10HudElementC2EP7ASpriteib() __attribute__((used));
static void _GLOBAL__I__ZN10HudElementC2EP7ASpriteib()
{
    __static_initialization_and_destruction_0(1, 65535);
}

static void __tcf_2(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}
