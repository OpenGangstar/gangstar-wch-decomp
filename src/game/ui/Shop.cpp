/*
 * Shop
 *
 * Original file: Shop.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Shop.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "Shop.h"

bool Shop::unlocked() const
{
    return unknown4 & 1;
}

bool Shop::triggered() const
{
    return triggerActive;
}

int Shop::getId()
{
    return shopId;
}
#include "../ai/StateMachine.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_shop_transitions {
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_shop_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_shop_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_shop_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_shop_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_shop_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_shop_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_shop_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_shop_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_shop_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_shop_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN4Shop15s_numShopWeaponE() __attribute__((used));
static void _GLOBAL__I__ZN4Shop15s_numShopWeaponE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

#include "../world/ObjectData.h"
#include "../app/Application.h"
#include "../hud/CHudManager.h"
#include "../hud/MiniMap.h"
#include "../core/CameraManager.h"
#include "../world/GameObjectManager.h"
int Shop::s_numShopWeapon;
int Shop::s_numShopRental;

void Shop::Load(const Structs::CheckpointShop& data)
{
    Checkpoint::Load(data);
    radius = data.unknown88;
    static_cast<LevelObject*>(this)->setAnimation(0, 1, true, false, false);

    MiniMap* minimap = static_cast<MiniMap*>(Application::GetInstance()->GetHudManager()->minimap);
    if (minimap)
        minimap->registerForMapTracking(this, false);

    switch (GetMetatype()) {
    case 31:
        shopId = s_numShopRental++;
        break;
    case 33:
        shopId = s_numShopWeapon++;
        break;
    }
}

#include "GSCarRentalMenu.h"
#include "GSCarRepairMenu.h"
#include "GSWeaponShopMenu.h"
#include "../characters/PlayerTest.h"
#include "../hud/MenuManager.h"
#include "../meta/Achievements.h"
#include "../scripting/ScriptManager.h"
#include "../vehicles/Vehicle.h"

void Shop::trigger(bool enabled)
{
    if (!(unknown4 & 2u))
        return;
    triggerActive = enabled;
    if (!enabled)
        return;

    switch (GetMetatype()) {
    case 31:
        StateMachine::getInstance()->pushState<GSCarRentalMenu>();
        AchievementManager::s_achievementManager->recordShopCarRental(shopId);
        break;
    case 32: {
        PlayerTest* player = PlayerTest::GetPlayer();
        Vehicle* car = static_cast<SavePrimaryInterface*>(player)->getVehicle();
        if (!car)
            return;
        if (car->getHealth() == car->getMaxHealth()) {
            ScriptManager::getInstance()->message(0x302d);
        } else if (car->getMaxHealth() > 0) {
            const int fullPrice = car->getRepairPrice();
            const int price = fullPrice * (car->getMaxHealth() - car->getHealth()) / car->getMaxHealth();
            if (player->isRichAsCroesus() || price <= player->cash) {
                MenuManager::getInstance()->setRepairCost(price);
                StateMachine::getInstance()->pushState<GSCarRepairMenu>();
            } else {
                ScriptManager::getInstance()->message(0x302c);
            }
        }
        break;
    }
    case 33:
        StateMachine::getInstance()->pushState<GSWeaponShopMenu>();
        AchievementManager::s_achievementManager->recordShopWeapon(shopId);
        break;
    }
}

Shop::Shop(int type)
    : Checkpoint(type), triggerActive(false)
{
}

Shop::~Shop()
{
    MiniMap* map = static_cast<MiniMap*>(Application::GetInstance()->GetHudManager()->minimap);
    if (map)
        map->deregisterForMapTracking(this);
}

void Shop::resetAchievementCounters()
{
    s_numShopWeapon = 0;
    s_numShopRental = 0;
}

void Shop::lock()
{
    MiniMap* map = static_cast<MiniMap*>(Application::GetInstance()->GetHudManager()->minimap);
    if (map)
        map->deregisterForMapTracking(this);
    disable();
}

void Shop::unlock()
{
    const irr::core::vector3d<float> position = GetPosition();
    const float distanceSquared = position.getDistanceFromSQ(
        CameraManager::getInstance()->getCamera()->getPosition());
    const float visibilityDistanceSquared = 100000000.0f;

    if (distanceSquared > visibilityDistanceSquared) {
        unknown4 |= 1u;
        GameObjectManager::s_gom->Remove(this);
        GameObjectManager::s_gom->Add(this, 1);
    } else {
        enable();
    }

    MiniMap* map = static_cast<MiniMap*>(Application::GetInstance()->GetHudManager()->minimap);
    if (map)
        map->registerForMapTracking(this, false);
}

void Shop::Update(int elapsed)
{
    Checkpoint::Update(elapsed);
    if (!(unknown4 & 2u))
        return;

    if (GetMetatype() == 32) {
        PlayerTest* player = PlayerTest::GetPlayer();
        if ((player->flags240 & 0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle()) {
            Vehicle* car = static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle();
            if (car) {
                const int distanceSquared = static_cast<int>(car->GetPosition().getDistanceFromSQ(GetPosition()));
                if (distanceSquared < radius * radius) {
                    if (!triggerActive)
                        trigger(true);
                } else if (triggerActive) {
                    trigger(false);
                }
            }
        }
    } else {
        PlayerTest* player = PlayerTest::GetPlayer();
        if (reinterpret_cast<unsigned int>(this) - reinterpret_cast<unsigned int>(player->closestShop) == 0u)
            return;

        const float radiusSquared = static_cast<float>(radius * radius);
        if (radiusSquared > static_cast<SavePositionInterface*>(player)->position().getDistanceFromSQ(GetPosition()))
            player->setClosestShop(this);
    }
}

