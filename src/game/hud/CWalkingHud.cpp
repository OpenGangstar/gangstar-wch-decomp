/*
 * CWalkingHud
 *
 * Original file: CWalkingHud.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CWalkingHud.cpp here, in the order they appear in the library.
 */

#include "CWalkingHud.h"
#include "CHudManager.h"
#include "HudElement.h"
#include "SpyGauge.h"

inline bool CWalkingHud::isWalkingHud() const { return true; }

CWalkingHud::CWalkingHud(CHudManager* hudManager) : IHud(hudManager)
{
    unknown8 = 0x3000f1c1;
}

CWalkingHud::~CWalkingHud() {}

void CWalkingHud::nearCar()
{
    if (isVisible())
        manager->enterCarButton->show();
    unknown8 |= 0x20;
}

void CWalkingHud::notNearCar()
{
    manager->enterCarButton->hide();
    unknown8 &= ~0x20u;
}

void CWalkingHud::nearShop()
{
    if (isVisible())
        manager->enterShopButton->show();
    unknown8 |= 0x04000000;
}

bool CWalkingHud::isNearShop() const
{
    return manager->enterShopButton->isVisible();
}

void CWalkingHud::notNearShop()
{
    manager->enterShopButton->hide();
    unknown8 &= ~0x04000000u;
}

void CWalkingHud::showSpyGauge(bool show)
{
    if (show) {
        manager->spyGauge->show();
        unknown8 |= 0x02000000;
    } else {
        manager->spyGauge->hide();
        unknown8 &= ~0x02000000u;
    }
}

void CWalkingHud::showCash(bool show)
{
    if (show)
        unknown8 |= 0x8000;
    else
        unknown8 &= ~0x8000u;
}

void CWalkingHud::toggleWeaponSelector(bool show)
{
    if (show) {
        unknown8 |= 0x100;
        manager->weaponSelector->show();
        manager->weaponSelectorExtra->show();
        unknown8 |= 0x2000;
        manager->weaponSelectorControl->show();
    } else {
        unknown8 &= ~0x100u;
        manager->weaponSelector->hide();
        manager->weaponSelectorExtra->hide();
        unknown8 &= ~0x2000u;
        manager->weaponSelectorControl->hide();
    }
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
static void _GLOBAL__I__ZN11CWalkingHudC2EP11CHudManager() __attribute__((used));
static void _GLOBAL__I__ZN11CWalkingHudC2EP11CHudManager()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
