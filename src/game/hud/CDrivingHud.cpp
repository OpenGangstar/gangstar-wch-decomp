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
 * CDrivingHud
 *
 * Original file: CDrivingHud.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CDrivingHud.cpp here, in the order they appear in the library.
 */

#include "CDrivingHud.h"
#include "CHudManager.h"
#include "SpyGauge.h"
#include "HudElement.h"
#include "../combat/Ammo.h"
#include "../ui/AnimatedButton.h"

CDrivingHud::CDrivingHud(CHudManager* hudManager) : IHud(hudManager)
{
    unknown8 = 0x19c0e198;
}

CDrivingHud::~CDrivingHud() {}

void CDrivingHud::showSpyGauge(bool show)
{
    if (show) {
        manager->spyGauge->show();
        unknown8 |= 0x02000000;
    } else {
        manager->spyGauge->hide();
        unknown8 &= ~0x02000000u;
    }
}

void CDrivingHud::showCash(bool show)
{
    if (show)
        unknown8 |= 0x8000;
    else
        unknown8 &= ~0x8000u;
}

void CDrivingHud::toggleWeaponSelector(bool show)
{
    if (show) {
        unknown8 |= 0x100;
        manager->weaponSelector->show();
        manager->weaponSelectorExtra->show();
        unknown8 |= 0x2000;
        manager->ammoDisplay->show();
    } else {
        unknown8 &= ~0x100u;
        manager->weaponSelector->hide();
        manager->weaponSelectorExtra->hide();
        unknown8 &= ~0x2000u;
        manager->ammoDisplay->hide();
    }
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_cdrivinghud_transitions {
extern const unsigned int civPassive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scriptedNpc_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civAggressive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int gangMember_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_trans[] __attribute__((visibility("hidden")));
extern const unsigned int swat_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civ_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int guard_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scripted_vehicle_trans[] __attribute__((visibility("hidden")));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_3()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_cdrivinghud_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11CDrivingHudC2EP11CHudManager() __attribute__((used));
static void _GLOBAL__I__ZN11CDrivingHudC2EP11CHudManager()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "CHudManager.h"
#include "HudElement.h"
#include "../app/Application.h"
#include "../input/CControlManager.h"
#include "../input/CDrivingControlHandler.h"

// Read only observed component pointers; concrete element types remain partial.
static inline HudElement* drivingComponent(CHudManager* manager,unsigned int offset)
{
    return *reinterpret_cast<HudElement**>(reinterpret_cast<unsigned char*>(manager)+offset);
}

void CDrivingHud::hide()
{
    visible=false;
    drivingComponent(manager,36)->hide();
    drivingComponent(manager,44)->hide();
    drivingComponent(manager,48)->hide();
    drivingComponent(manager,40)->hide();
    drivingComponent(manager,52)->hide();
    drivingComponent(manager,60)->hide();
    drivingComponent(manager,64)->hide();
    drivingComponent(manager,56)->hide();
    drivingComponent(manager,80)->hide();
    drivingComponent(manager,84)->hide();
    drivingComponent(manager,88)->hide();
    drivingComponent(manager,92)->hide();
    drivingComponent(manager,96)->hide();
    drivingComponent(manager,100)->hide();
    drivingComponent(manager,136)->hide();
    drivingComponent(manager,184)->hide();
    drivingComponent(manager,188)->hide();
    drivingComponent(manager,164)->hide();
    drivingComponent(manager,140)->hide();
    drivingComponent(manager,144)->hide();
    drivingComponent(manager,148)->hide();
    drivingComponent(manager,156)->hide();
    drivingComponent(manager,160)->hide();
    drivingComponent(manager,104)->hide();
    drivingComponent(manager,108)->hide();
    drivingComponent(manager,152)->hide();
    drivingComponent(manager,168)->hide();
    drivingComponent(manager,128)->hide();
    if(unknown8&(1u<<23))
        static_cast<CDrivingControlHandler*>(Application::GetInstance()->GetControlManager()->drivingHandler)->disableAccelerometer();
}

#include "../characters/PlayerTest.h"
#include "../vehicles/Vehicle.h"

void CDrivingHud::show()
{
    visible=true;
    if(unknown8&(1u<<0)) {
        drivingComponent(manager,36)->show();
    }
    if(unknown8&(1u<<1)) {
        drivingComponent(manager,40)->show();
    }
    if(unknown8&(1u<<2)) {
        drivingComponent(manager,52)->show();
        drivingComponent(manager,56)->show();
    }
    if(unknown8&(1u<<3)) {
        drivingComponent(manager,60)->show();
        drivingComponent(manager,64)->show();
    }
    if(unknown8&(1u<<16)) {
        drivingComponent(manager,44)->show();
    }
    if(unknown8&(1u<<17)) {
        drivingComponent(manager,48)->show();
    }
    if(unknown8&(1u<<22)) {
        drivingComponent(manager,96)->show();
        drivingComponent(manager,100)->show();
    }
    if(unknown8&(1u<<20)) {
        drivingComponent(manager,80)->show();
    }
    if(unknown8&(1u<<21)) {
        drivingComponent(manager,84)->show();
    }
    if(unknown8&(1u<<18)) {
        drivingComponent(manager,88)->show();
    }
    if(unknown8&(1u<<19)) {
        drivingComponent(manager,92)->show();
    }
    if(unknown8&(1u<<7)) {
        drivingComponent(manager,136)->show();
    }
    if(unknown8&(1u<<8)) {
        drivingComponent(manager,184)->show();
        drivingComponent(manager,188)->show();
    }
    if(unknown8&(1u<<14)) {
        drivingComponent(manager,164)->show();
    }
    if(unknown8&(1u<<12)) {
        drivingComponent(manager,140)->show();
    }
    if(unknown8&(1u<<29)) {
        drivingComponent(manager,144)->show();
    }
    if(unknown8&(1u<<27)) {
        drivingComponent(manager,148)->show();
    }
    if(unknown8&(1u<<13)) {
        drivingComponent(manager,156)->show();
    }
    if(unknown8&(1u<<15)) {
        drivingComponent(manager,160)->show();
    }
    if(unknown8&(1u<<24)) {
        drivingComponent(manager,104)->show();
        drivingComponent(manager,108)->show();
    }
    if(unknown8&(1u<<25)) {
        drivingComponent(manager,152)->show();
    }
    if(unknown8&(1u<<28)) {
        drivingComponent(manager,168)->show();
    }
    if(unknown8&(1u<<4)) {
        if(PlayerTest::GetPlayer()->getVehicle()) {
            int type=PlayerTest::GetPlayer()->getVehicle()->GetMetatype();
            if(type==39 || type==153 || type==5)
                drivingComponent(manager,128)->show();
        }
    }
    if(unknown8&(1u<<23))
        static_cast<CDrivingControlHandler*>(Application::GetInstance()->GetControlManager()->drivingHandler)->unknown16=true;
}
