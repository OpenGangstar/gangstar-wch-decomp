/*
 * AnimatedButton
 *
 * Original file: AnimatedButton.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AnimatedButton.cpp here, in the order they appear in the library.
 */

#include "AnimatedButton.h"
#include "../characters/AnimObject.h"
#include "../core/ASprite.h"

void AnimatedButton::grayOut(bool gray)
{
    if (gray)
        flags |= 32;
    else
        flags &= ~32u;
}

void AnimatedButton::setAnim(int animation)
{
    animationObject->SetAnim(animation);
}

void AnimatedButton::update(double elapsed)
{
    VirtualButton::update(elapsed);
    animationObject->UpdateFrame();
}

AnimatedButton::AnimatedButton(ASprite* image, int animation, EvVButton::ButtonType::Type type)
    : VirtualButton(image, animation, type, true)
{
    animationObject = new AnimObject;
    animationObject->sprite = image;
    animationObject->SetAnim(animation);
    const int spriteFrame = sprite->GetFrameFromAFrame(animation, 0);
    const SpriteFrame* entry = sprite->GetFrame(spriteFrame);
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

// Recovered translation-unit SDK string startup callbacks.
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
static void _GLOBAL__I__ZN14AnimatedButtonC2EP7ASpriteiN9EvVButton10ButtonType4TypeE() __attribute__((used));
static void _GLOBAL__I__ZN14AnimatedButtonC2EP7ASpriteiN9EvVButton10ButtonType4TypeE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
