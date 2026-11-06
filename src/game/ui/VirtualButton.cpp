/*
 * VirtualButton
 *
 * Original file: VirtualButton.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of VirtualButton.cpp here, in the order they appear in the library.
 */

#include "VirtualButton.h"
#include "../app/Application.h"
#include "../core/ASprite.h"
#include "../input/TouchScreenBase.h"

void VirtualButton::update(double)
{
    if (flags & 1) {
        TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
        const irr::core::rect<float>& region = reinterpret_cast<const irr::core::rect<float>&>(touchRegion);
        const long id = screen->getTouchIDInitiatedInRegion(region);
        if (id != -1)
            processTouch(id);
        else if (isUsed())
            processTouchRelease();
        wasInRegionLastFrame = screen->getTouchIDInRegion(region) != -1;
    }
}

VirtualButton::VirtualButton(ASprite* image, int firstFrame, EvVButton::ButtonType::Type type, bool hand)
    : HudElement(image, firstFrame, hand), buttonType(type)
{
    const SpriteFrame* entry = sprite->GetFrame(firstFrame);
    const SpriteFrameModule* part = sprite->GetFModule(entry->firstModule);
    const SpriteModule* module = sprite->GetModule(part->module);
    const float x = part->x;
    const float y = part->y;
    const float width = module->width;
    const short height = module->height;
    const float right = x + width;
    touchRegion.coordinates[0] = x;
    touchRegion.coordinates[1] = y;
    touchRegion.coordinates[2] = right;
    const float heightFloat = height;
    touchRegion.coordinates[3] = y + heightFloat;
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
static void _GLOBAL__I__ZN13VirtualButtonC2EP7ASpriteiN9EvVButton10ButtonType4TypeEb() __attribute__((used));
static void _GLOBAL__I__ZN13VirtualButtonC2EP7ASpriteiN9EvVButton10ButtonType4TypeEb()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}
