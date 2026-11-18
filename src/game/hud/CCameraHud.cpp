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
 * CCameraHud
 *
 * Original file: CCameraHud.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CCameraHud.cpp here, in the order they appear in the library.
 */

#include "IHud.h"

inline bool IHud::isVisible() const { return visible; }

inline bool IHud::isWalkingHud() const { return false; }

#include "CCameraHud.h"

CCameraHud::CCameraHud(CHudManager* hudManager) : IHud(hudManager)
{
    unknown8 = 0xa0005100;
}

CCameraHud::~CCameraHud() {}

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
static void _GLOBAL__I__ZN10CCameraHudC2EP11CHudManager() __attribute__((used));
static void _GLOBAL__I__ZN10CCameraHudC2EP11CHudManager()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "CHudManager.h"
#include "HudElement.h"

// Read only observed component pointers; their concrete element types remain partial.
static inline HudElement* cameraComponent(CHudManager* manager,unsigned int offset)
{
    return *reinterpret_cast<HudElement**>(reinterpret_cast<unsigned char*>(manager)+offset);
}

void CCameraHud::hide()
{
    visible=false;
    cameraComponent(manager,36)->hide();
    manager->enterCarButton->hide();
    manager->enterShopButton->hide();
    cameraComponent(manager,76)->hide();
    manager->minimap->hide();
    cameraComponent(manager,140)->hide();
    cameraComponent(manager,144)->hide();
    cameraComponent(manager,148)->hide();
    cameraComponent(manager,156)->hide();
    cameraComponent(manager,160)->hide();
    cameraComponent(manager,164)->hide();
    cameraComponent(manager,184)->hide();
    manager->weaponSelectorExtra->hide();
    cameraComponent(manager,152)->hide();
    cameraComponent(manager,168)->hide();
    cameraComponent(manager,116)->hide();
    cameraComponent(manager,120)->hide();
    cameraComponent(manager,124)->hide();
}

void CCameraHud::show()
{
    visible=true;
    if(unknown8&1u)cameraComponent(manager,36)->show();
    if(unknown8&(1u<<5))manager->enterCarButton->show();
    if(unknown8&(1u<<26))manager->enterShopButton->show();
    if(unknown8&(1u<<6))cameraComponent(manager,76)->show();
    if(unknown8&(1u<<7))manager->minimap->show();
    if(unknown8&(1u<<12))cameraComponent(manager,140)->show();
    if(unknown8&(1u<<29))cameraComponent(manager,144)->show();
    if(unknown8&(1u<<27))cameraComponent(manager,148)->show();
    if(unknown8&(1u<<13))cameraComponent(manager,156)->show();
    if(unknown8&(1u<<15))cameraComponent(manager,160)->show();
    if(unknown8&(1u<<14))cameraComponent(manager,164)->show();
    if(unknown8&(1u<<8)) {
        cameraComponent(manager,184)->show();
        manager->weaponSelectorExtra->show();
    }
    if(unknown8&(1u<<25))cameraComponent(manager,152)->show();
    if(unknown8&(1u<<28))cameraComponent(manager,168)->show();
    if(unknown8&(1u<<31)) {
        cameraComponent(manager,116)->show();
        cameraComponent(manager,120)->show();
        cameraComponent(manager,124)->show();
    }
}
