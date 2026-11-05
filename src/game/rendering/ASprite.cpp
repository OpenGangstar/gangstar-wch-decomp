/*
 * ASprite
 *
 * Original file: ASprite.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ASprite.cpp here, in the order they appear in the library.
 */

#include "../core/ASprite.h"
#include "../core/Matrix4.h"

struct SpriteAnimation {
    short count;
    short firstFrame;
    unsigned char unknown4[8];
};

struct SpriteData {
    unsigned char unknown0[32];
    unsigned int modules;
    unsigned char unknown36[4];
    unsigned int frames;
    unsigned int frameModules;
    unsigned int animations;
    unsigned int animationFrames;
};

const SpriteBounds& ASprite::GetFrameBoundingRect(int frame) const
{
    return GetFrame(frame)->bounds;
}

int ASprite::GetFrameFromAFrame(int animation, int frame) const
{
    const char* bytes = reinterpret_cast<const char*>(data);
    const SpriteAnimation* entry = reinterpret_cast<const SpriteAnimation*>(bytes + (data->animations + animation * 12));
    int index = entry->firstFrame + frame;
    return *reinterpret_cast<const unsigned short*>(bytes + (data->animationFrames + index * 9));
}

const SpriteBounds& ASprite::GetAnimFrameBoundingRect(int animation, int frame) const
{
    return GetFrameBoundingRect(GetFrameFromAFrame(animation, frame));
}

// Recovered translation-unit SDK string startup callbacks.
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
        new (&ASprite::s_global_transform) irr::core::matrix4;
    }
}

extern "C" {
static void _GLOBAL__I__ZN7ASprite18s_global_transformE() __attribute__((used));
static void _GLOBAL__I__ZN7ASprite18s_global_transformE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
