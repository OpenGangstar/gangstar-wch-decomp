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
#include "../core/Color.h"

template<class T>
void SafeDelete(T*& value)
{
    delete value;
    value = 0;
}

template void SafeDelete<AnimObject>(AnimObject*&);

inline AnimatedButton::~AnimatedButton()
{
    SafeDelete(animationObject);
}

void AnimatedButton::grayOut(bool gray)
{
    if (gray)
        flags |= 32;
    else
        flags &= ~32u;
}

void AnimatedButton::setWeaponAnim(int weapon)
{
    switch (weapon) {
    case 0:
        animationObject->SetAnim(15);
        break;
    case 1:
        animationObject->SetAnim(16);
        break;
    case 2:
        animationObject->SetAnim(23);
        break;
    case 3:
        animationObject->SetAnim(18);
        break;
    case 4:
        animationObject->SetAnim(21);
        break;
    case 5:
        animationObject->SetAnim(17);
        break;
    case 6:
        animationObject->SetAnim(22);
        break;
    case 7:
        animationObject->SetAnim(19);
        break;
    case 8:
        animationObject->SetAnim(20);
        break;
    case 9:
        animationObject->SetAnim(24);
        break;
    }
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

static inline void setGrayColor(irr::video::SColor& color)
{
    color.b = 255;
    color.g = 255;
    color.r = 255;
    color.a = 160;
}

static inline void setBlinkColor(irr::video::SColor& color)
{
    color.a = 255;
    color.b = 255;
    color.g = 255;
    color.r = 51;
}

void AnimatedButton::draw2d() const
{
    if (!isVisible())
        return;

    irr::video::SColor colors[4];
    if (flags & 32) {
        setGrayColor(colors[0]);
        setGrayColor(colors[1]);
        setGrayColor(colors[2]);
        setGrayColor(colors[3]);
        ASprite::s_global_color = colors;
    } else if ((flags & 16) && (unknown52 & 256)) {
        setBlinkColor(colors[0]);
        setBlinkColor(colors[1]);
        setBlinkColor(colors[2]);
        setBlinkColor(colors[3]);
        ASprite::s_global_color = colors;
    }
    animationObject->Draw();
    ASprite::s_global_color = 0;
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
