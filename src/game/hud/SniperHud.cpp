#include "../ui/AnimatedButton.h"
#include "CCameraHud.h"
#include "SniperHud.h"
#include "HealthBar.h"
#include "ArmorBar.h"
#include "CarBar.h"
#include "../vehicles/Wheel.h"

#include "../core/ASprite.h"
#include "../core/PointerVector.h"
#include "../ui/VirtualButton.h"
#include "../ui/SlideControl.h"
#include "../ui/Cash.h"
#include "../ui/Background.h"
#include "../rendering/RetroEffect.h"
#include "MiniMap.h"
#include "../missions/WantedMeter.h"
#include "../audio/Radio.h"
#include "../ui/ToggleButton.h"
#include "../missions/Reward.h"
#include "../combat/HitWarning.h"

/*
 * SniperHud
 *
 * Original file: SniperHud.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SniperHud.cpp here, in the order they appear in the library.
 */

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
static void _GLOBAL__I__ZN10CSniperHudC2EP11CHudManager() __attribute__((used));
static void _GLOBAL__I__ZN10CSniperHudC2EP11CHudManager()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "IHud.h"
#include "SniperHud.h"
CSniperHud::~CSniperHud() {}
CSniperHud::CSniperHud(CHudManager* hudManager) : IHud(hudManager)
{
    unknown8=0x60007100;
}

#include "CHudManager.h"
#include "HudElement.h"

// Read only observed component pointers; their concrete element types remain partial.
static inline HudElement* sniperComponent(CHudManager* manager,unsigned int offset)
{
    return *reinterpret_cast<HudElement**>(reinterpret_cast<unsigned char*>(manager)+offset);
}

void CSniperHud::hide()
{
    visible=false;
    sniperComponent(manager,36)->hide();
    manager->enterCarButton->hide();
    manager->enterShopButton->hide();
    sniperComponent(manager,76)->hide();
    manager->minimap->hide();
    sniperComponent(manager,140)->hide();
    sniperComponent(manager,144)->hide();
    sniperComponent(manager,148)->hide();
    sniperComponent(manager,156)->hide();
    sniperComponent(manager,160)->hide();
    sniperComponent(manager,164)->hide();
    sniperComponent(manager,184)->hide();
    manager->weaponSelectorExtra->hide();
    sniperComponent(manager,152)->hide();
    sniperComponent(manager,168)->hide();
    sniperComponent(manager,112)->hide();
    sniperComponent(manager,120)->hide();
    sniperComponent(manager,124)->hide();
}

void CSniperHud::show()
{
    visible=true;
    if(unknown8&1u)sniperComponent(manager,36)->show();
    if(unknown8&(1u<<5))manager->enterCarButton->show();
    if(unknown8&(1u<<26))manager->enterShopButton->show();
    if(unknown8&(1u<<6))sniperComponent(manager,76)->show();
    if(unknown8&(1u<<7))manager->minimap->show();
    if(unknown8&(1u<<12))sniperComponent(manager,140)->show();
    if(unknown8&(1u<<29))sniperComponent(manager,144)->show();
    if(unknown8&(1u<<27))sniperComponent(manager,148)->show();
    if(unknown8&(1u<<13))sniperComponent(manager,156)->show();
    if(unknown8&(1u<<15))sniperComponent(manager,160)->show();
    if(unknown8&(1u<<14))sniperComponent(manager,164)->show();
    if(unknown8&(1u<<8)) {
        sniperComponent(manager,184)->show();
        manager->weaponSelectorExtra->show();
    }
    if(unknown8&(1u<<25))sniperComponent(manager,152)->show();
    if(unknown8&(1u<<28))sniperComponent(manager,168)->show();
    if(unknown8&(1u<<30)) {
        sniperComponent(manager,112)->show();
        sniperComponent(manager,120)->show();
        sniperComponent(manager,124)->show();
    }
}
