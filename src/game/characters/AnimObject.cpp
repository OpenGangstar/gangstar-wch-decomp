/*
 * AnimObject
 *
 * Original file: AnimObject.cpp
 * Area:          characters
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AnimObject.cpp here, in the order they appear in the library.
 */

#include "AnimObject.h"
#include "../core/ASprite.h"

float PlayPolicy_Onetime(float, float, float end) { return end; }

void AnimObject::Unload() { sprite = 0; }
void AnimObject::Load() { Unload(); }

AnimObject::AnimObject() : sprite(0)
{
    Reset();
    frameStep = 0.5f;
}

AnimObject::~AnimObject() { Unload(); }

void AnimObject::SetPosition(float px, float py, float pz)
{
    x = px;
    y = py;
    z = pz;
}

void AnimObject::ChangeAnim(int id) { animation = id; }
void AnimObject::Restart() { frame = 0.0f; }

void AnimObject::SetAnim(int id)
{
    if (id != animation || id + 1 <= 0) {
        ChangeAnim(id);
        Restart();
        frameLimit = 0x00ffffff;
    }
}

void AnimObject::SetAnim(int id, int limit)
{
    SetAnim(id);
    frameLimit = limit;
}

void AnimObject::Draw()
{
    if (sprite && animation >= 0) {
        int animationFrame = sprite->GetAFrame(animation, static_cast<int>(frame));
        int px = static_cast<int>(x);
        int py = static_cast<int>(y);
        sprite->PaintAFrame(animation, animationFrame, px, py, 0);
    }
}

extern "C" float fmodf(float value, float divisor);
float FSelect(float value, float positive, float negative);

float PlayPolicy_Loop(float start, float end, float next)
{
    float duration = end - start;
    if (next >= 0.0f)
        return fmodf(next, duration);
    float wrapped = fmodf(next + duration, duration);
    return wrapped + FSelect(wrapped, 0.0f, duration);
}

void AnimObject::UpdateFrame()
{
    if (!sprite || animation < 0)
        return;
    float duration = static_cast<float>(sprite->GetAnimDuration(animation));
    float next = frameStep * speed + frame;
    if (frameLimit)
        frame = PlayPolicy_Loop(0.0f, duration, next);
    else
        frame = PlayPolicy_Onetime(0.0f, duration, next);
    if (duration <= frame)
        frame = duration - 1.0f;
    else if (frame < 0.0f)
        frame = 0.0f;
}

void AnimObject::Update(int) { UpdateFrame(); }

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
static void _GLOBAL__I__Z7FSelectfff() __attribute__((used));
static void _GLOBAL__I__Z7FSelectfff()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
