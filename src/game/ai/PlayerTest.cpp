/*
 * PlayerTest
 *
 * Original file: PlayerTest.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of PlayerTest.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../world/MapSingleton.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "../core/LocalStartupText.h"
#include "../characters/PlayerTest.h"
#include "../app/Application.h"
#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"
#include "../hud/CHudManager.h"
#include "NPC.h"
#include "../characters/NPCVehicleEvent.h"
#include "../vehicles/Vehicle.h"
#include "../core/GameEventMethods.h"
#include "../core/SceneNode.h"
#include "../meta/Achievements.h"
#include "../scripting/ScriptManager.h"

class Reward {
public:
    void setMessage(int amount, int maximum);
};

static const unsigned int meshHiddenFlag = 0x800u;
static const unsigned int scriptedMovementFlag = 0x8000u;

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_playertest_transitions {
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
static void __tcf_5()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

PlayerTest* PlayerTest::s_player;

PlayerTest* PlayerTest::GetPlayer()
{
    return s_player;
}

LevelObject* PlayerTest::_GetTarget()
{
    return getTarget();
}

int PlayerTest::getMarkerType()
{
    return -1;
}

void PlayerTest::hideMesh()
{
    flags240 |= meshHiddenFlag;
    shadowNode->setVisible(false);
}

void PlayerTest::hideAllAnims()
{
    sceneNode->setVisible(false);
}

void PlayerTest::initMoveTo(const Vehicle* vehicle)
{
    unknown368 = const_cast<Vehicle*>(vehicle);
}

void PlayerTest::richAsCroesus(bool enabled)
{
    richAsCroesusEnabled = enabled;
}

bool PlayerTest::isRichAsCroesus() const
{
    return richAsCroesusEnabled;
}

void PlayerTest::setCash(int value)
{
    if (!richAsCroesusEnabled || cash < value)
        cash = value;
}

int PlayerTest::getAmbientSound() const
{
    switch (contextWord) {
    case Context0: return 101;
    case Context1: return 100;
    default: return -1;
    }
}

void PlayerTest::addCurrentDriftDistance(float distance)
{
    currentDriftDistance += distance;
}

void PlayerTest::addCurrentJumpDistance(float distance)
{
    currentJumpDistance += distance;
}

void PlayerTest::addPhotoTarget(LevelObject* target)
{
    photoTargets.push_back(target);
}

void PlayerTest::clearPhotoTargets()
{
    ::operator delete(photoTargets.data);
    photoTargets.used = 0;
    photoTargets.allocated = 0;
    photoTargets.data = 0;
    photoTargets.is_sorted = true;
}

void PlayerTest::playCurAnimFromStart()
{
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    character->resetAnimation();
}

Vehicle* PlayerTest::getVehicle() const
{
    if (ScriptManager::getInstance()->isInCinematic() && !vehicleVisibleInCinematic &&
        !ScriptManager::getInstance()->areBlockingCommandsSkipped())
        return 0;
    return vehicle;
}

void PlayerTest::addCash(int amount, int maximum)
{
    if (richAsCroesusEnabled && amount <= 0)
        return;
    Application::GetInstance()->GetHudManager()->reward->setMessage(amount, maximum);
    cash += amount;
}

void PlayerTest::lockSwitchWeapon()
{
    weaponSwitchLocked = true;
}

void PlayerTest::unlockSwitchWeapon()
{
    weaponSwitchLocked = false;
}

void PlayerTest::runToLocation(const irr::core::vector3d<float>& point)
{
    SavePositionInterface* position = this;
    if (!position->isDead()) {
        flags240 |= scriptedMovementFlag;
        Character* character = reinterpret_cast<Character*>(position);
        character->setDestination(point, 100);
        character->Character::runToLocation(point);
    }
}

void PlayerTest::walkToLocation(const irr::core::vector3d<float>& point)
{
    SavePositionInterface* position = this;
    if (!position->isDead()) {
        flags240 |= scriptedMovementFlag;
        Character* character = reinterpret_cast<Character*>(position);
        character->setDestination(point, 100);
        character->Character::walkToLocation(point);
    }
}

void PlayerTest::showMesh()
{
    flags240 &= ~meshHiddenFlag;
    shadowNode->setVisible(true);
}

void PlayerTest::switchWeapon(bool unarmed)
{
    if (weaponSwitchLocked)
        return;

    Application* app = Application::GetInstance();
    if (unarmed)
        app->GetHudManager()->switchWeapon(0);
    else
        app->GetHudManager()->switchWeapon();

    app->GetWeaponManager()->getCurrentWeapon();
    // The partial PlayerTest layout uses SavePositionInterface for its Character base.
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    character->switchWeapon();
    LevelObject* currentTarget = getTarget();
    if (currentTarget && LevelObject::s_type[currentTarget->getObjectType()] == 5)
        static_cast<NPC*>(currentTarget)->notifyTargeted(true, character);
    static_cast<SavePrimaryInterface*>(this)->getWeapon()->show();
}

Weapon* PlayerTest::getWeapon() const
{
    return Application::GetInstance()->GetWeaponManager()->getCurrentWeapon();
}

void PlayerTest::subCash(int amount)
{
    if (richAsCroesusEnabled && amount >= 0)
        return;
    cash -= amount;
    AchievementManager::s_achievementManager->recordCashSpent(amount);
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_playertest_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_playertest_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_playertest_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_playertest_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_playertest_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_playertest_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_playertest_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_playertest_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_playertest_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_playertest_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN10PlayerTest10switchAnimEv() __attribute__((used));
static void _GLOBAL__I__ZN10PlayerTest10switchAnimEv()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

inline EvNPCVehicle::~EvNPCVehicle()
{
}
