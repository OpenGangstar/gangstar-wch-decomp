/*
 * RetroEffect
 *
 * Original file: RetroEffect.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of RetroEffect.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "RetroEffect.h"
#include "../app/Application.h"
#include "../core/IrrlichtDevice.h"
#include "../core/VideoDriver.h"
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
static void _GLOBAL__I__ZN11RetroEffectC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN11RetroEffectC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

static const char retroEffectTexture[] = "./effect.tga";

RetroEffect::RetroEffect()
    : HudElement(0, 0, true), texture(0)
{
    using namespace irr::video;
    texture = Application::GetInstance()->GetDevice()->getVideoDriver()->getTexture(retroEffectTexture);
    material.setType(MaterialType13);
    material.setTexture(0, texture);
    material.setFlag(static_cast<E_MATERIAL_FLAG>(4096), true);
    material.setFlag(MaterialFlag128, false);
    material.setFlag(MaterialFlag256, false);
    material.setFlag(MaterialFlag2, false);
    material.setFlag(MaterialFlag512, false);
}

RetroEffect::~RetroEffect()
{
    Application::GetInstance()->GetDevice()->getVideoDriver()->removeTexture(texture);
}
#include "../hud/MenuManager.h"
#include "../ui/WidgetDialog.h"
extern "C" long lrand48();

void RetroEffect::draw2d() const
{
    MenuWidget* widget = MenuManager::getInstance()->getWidgetByIndex(29);
    if (flags & 1) {
        if (!widget->IsVisible())
            widget->Show();

        irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();
        driver->set2DMaterial(const_cast<irr::video::SMaterial&>(material));
        driver->getViewPort();
        driver->draw2DImage(texture, irr::core::position2d<int>(lrand48() % 4 - 2, lrand48() % 4 - 2),
                            irr::core::rect<int>(0, 0, 854, 480), 0,
                            irr::video::SColor(255, 255, 255, 255), true);
        irr::video::SMaterial defaultMaterial;
        driver->set2DMaterial(defaultMaterial);
    } else {
        if (widget->IsVisible())
            widget->Hide(true);
    }
}
