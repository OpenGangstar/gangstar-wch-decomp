/*
 * Gauge
 *
 * Original file: Gauge.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Gauge.cpp here, in the order they appear in the library.
 */

#include "Gauge.h"
#include "../core/ASprite.h"

void Gauge::update(double) {}

void Gauge::setPercentage(float percentage)
{
    const float width = fillWidth;
    fillRight = static_cast<int>(width - width * percentage);
}

void Gauge::draw2d() const
{
    HudElement::draw2d();
    if (!hideFill) {
        sprite->setClip(fillLeft, 0, fillRight, -1);
        sprite->PaintFrame(fillFrame, 0, 0, 0);
        sprite->setClip(0, 0, -1, -1);
    }
    sprite->PaintFrame(overlayFrame, 0, 0, 0);
}

Gauge::~Gauge() {}

Gauge::Gauge(ASprite* image, int firstFrame, int fill, int overlay)
    : HudElement(image, firstFrame, false)
{
    fillRight = -1;
    unknown72 = 0.0;
    hideFill = false;
    fillLeft = 0;
    fillFrame = fill;
    overlayFrame = overlay;
    const SpriteFrame* entry = sprite->GetFrame(frame);
    const SpriteFrameModule* part = sprite->GetFModule(entry->firstModule);
    const SpriteModule* module = sprite->GetModule(part->module);
    fillWidth = module->width;
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
static void _GLOBAL__I__ZN5GaugeC2EP7ASpriteiii() __attribute__((used));
static void _GLOBAL__I__ZN5GaugeC2EP7ASpriteiii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
