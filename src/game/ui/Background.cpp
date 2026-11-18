/*
 * Background
 *
 * Original file: Background.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Background.cpp here, in the order they appear in the library.
 */

#include "Background.h"
#include "../app/Application.h"
#include "../core/VideoDriver.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"

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
static void _GLOBAL__I__ZN10BackgroundC2EP7ASpritei() __attribute__((used));
static void _GLOBAL__I__ZN10BackgroundC2EP7ASpritei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

Background::Background(ASprite* sprite, int frame)
    : HudElement(sprite, frame, false)
{
    blackoutElapsed = 0;
    blackoutActive = false;
}

void Background::update(double elapsed)
{
    if (blackoutActive) {
        blackoutElapsed += elapsed;
        if (blackoutElapsed > 250) {
            blackoutElapsed = 0;
            blackoutActive = false;
        }
    }
}

void Background::draw2d() const
{
    if (blackoutActive) {
        Application* app = Application::GetInstance();
        irr::video::IVideoDriver* driver = app->GetDevice()->getVideoDriver();
        int width, height;
        app->GetScreenDimensions(width, height);
        driver->draw2DRectangle(irr::video::SColor(255, 0, 0, 0),
                                irr::core::rect<int>(0, 0, width, height), 0);
    }
    HudElement::draw2d();
}

Background::~Background()
{
}
