/*
 * WantedMeter
 *
 * Original file: WantedMeter.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of WantedMeter.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "WantedLevelManagerSingleton.h"
#include "../characters/AnimObject.h"
#include "WantedMeter.h"
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

extern "C" {
static void __tcf_3()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11WantedMeterC2EP7ASpritei() __attribute__((used));
static void _GLOBAL__I__ZN11WantedMeterC2EP7ASpritei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void WantedMeter::draw2d() const
{
    if (!(flags & 1))
        return;
    const int level = WantedLevelManager::getInstance()->unknown8;
    for (int i = 0; i < level; ++i)
        stars[i]->Draw();
}

WantedMeter::~WantedMeter()
{
    for (int i = 0; i < 5; ++i)
        delete stars[i];
}

#include "WantedMeter.h"
#include "../characters/AnimObject.h"

void WantedMeter::update(double)
{
    if (!(flags & 1))
        return;

    int firstAnimation = frame;
    if (__builtin_expect(WantedLevelManager::getInstance()->unknown72 <= 0, 1))
        firstAnimation += 5;

    for (int i = 0; i < 5; ++i) {
        stars[i]->SetAnim(firstAnimation + i);
        stars[i]->UpdateFrame();
    }
}

#include "../core/ASprite.h"

WantedMeter::WantedMeter(ASprite* image, int animation)
    : HudElement(image, animation, true), wantedLevel(0), timer(0)
{
    for (int i = 0; i < 5; ++i) {
        AnimObject* star = new AnimObject;
        stars[i] = star;
        star->sprite = image;
        stars[i]->SetAnim(animation + i);
    }

    const int firstFrame = sprite->GetFrameFromAFrame(animation, 0);
    const SpriteFrame* first = sprite->GetFrame(firstFrame);
    const SpriteFrameModule* firstPart = sprite->GetFModule(first->firstModule);
    const int lastFrame = sprite->GetFrameFromAFrame(animation + 4, 0);
    const SpriteFrame* last = sprite->GetFrame(lastFrame);
    const SpriteFrameModule* lastPart = sprite->GetFModule(last->firstModule);
    const SpriteModule* module = sprite->GetModule(lastPart->module);
    const short left = firstPart->x;
    const float x = left;
    const float y = firstPart->y;
    float right = lastPart->x + module->width - left;
    const short height = module->height;
    right = x + right;
    // Stored again below; the extra use keeps the add in place so the
    // stores follow it as in retail. Flow removes this first store.
    touchRegion.coordinates[2] = right;
    touchRegion.coordinates[0] = x;
    touchRegion.coordinates[1] = y;
    touchRegion.coordinates[2] = right;
    const float heightFloat = height;
    touchRegion.coordinates[3] = y + heightFloat;
}
