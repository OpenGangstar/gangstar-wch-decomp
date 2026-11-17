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
#include "../world/GameObjectManager.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "../core/LocalStartupText.h"
#include "../characters/PlayerTest.h"
#include "../app/Application.h"
#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"
#include "../hud/CHudManager.h"
#include "../input/CControlManager.h"
#include "NPC.h"
#include "../characters/NPCVehicleEvent.h"
#include "../vehicles/Vehicle.h"
#include "../core/GameEventMethods.h"
#include "../core/Physics.h"
#include "../core/SceneNode.h"
#include "../core/NativeStrings.h"
#include "../core/Quaternion.h"
#include "../core/CameraManager.h"
#include "../core/Lock.h"
#include "../meta/Achievements.h"
#include "../scripting/ScriptManager.h"
#include "../ui/Shop.h"

extern "C" float sqrtf(float);

namespace {
const char carOpenDoor[] = "car_open_door";
const char carEnterLow[] = "car_enter_car_low";
const char carEnterHigh[] = "car_enter_car_hi";
const char carCloseInsideLow[] = "car_close_door_from_inside_low";
const char carCloseInsideHigh[] = "car_close_door_from_inside_hi";
const char carExitLow[] = "car_exit_low";
const char carExitHigh[] = "car_exit_hi";
}

int PlayerTest::getCarAnimName(const char* name, bool left)
{
    if (strcmp(carOpenDoor, name) == 0) {
        if (left)
            return 22;
        return 23;
    }
    if (strcmp(carEnterLow, name) == 0) {
        if (left)
            return 11;
        return 12;
    }
    if (strcmp(carEnterHigh, name) == 0) {
        if (left)
            return 9;
        return 10;
    }
    if (strcmp(carCloseInsideLow, name) == 0) {
        if (left)
            return 3;
        return 4;
    }
    if (strcmp(carCloseInsideHigh, name) == 0) {
        if (left)
            return 1;
        return 2;
    }
    if (strcmp(carExitLow, name) == 0) {
        if (left)
            return 15;
        return 16;
    }
    if (strcmp(carExitHigh, name) == 0) {
        if (left)
            return 13;
        return 14;
    }
    return -1;
}

void PlayerTest::applyDamage(int amount, LevelObject* source, bool bypassArmor)
{
    Application::GetInstance()->GetControlManager()->exitSniping(!ScriptManager::getInstance()->isInCinematic());

    if (damageDisabled)
        return;

    if (!(flags240 & 0x400u) || !vehicle) {
        int& armor = contextValues[contextWord];
        const int previousArmor = armor;
        if (previousArmor > 0 && !bypassArmor) {
            armor = previousArmor - amount;
            amount -= previousArmor;
            if (amount < 0)
                amount = 0;
        }
        health -= amount;
    } else {
        vehicle->applyDamage(amount, source, bypassArmor);
        AchievementManager::s_achievementManager->recordDamage(amount);
    }
}

void PlayerTest::Stop()
{
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    character->Character::Stop();
    if (vehicle)
        vehicle->Stop();

    b2Body* body = collisionBody;
    body->linearVelocity.y = 0.0f;
    body->linearVelocity.x = 0.0f;
    collisionBody->angularVelocity = 0.0f;
    _SetTarget(0, false);
}

#include "../missions/Reward.h"

static const unsigned int meshHiddenFlag = 0x800u;
static const unsigned int scriptedMovementFlag = 0x8000u;
static const unsigned int moveToTargetFlag = 0x1000u;

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

void PlayerTest::setClosestShop(Shop* shop)
{
    if (closestShop && closestShop != shop)
        closestShop->trigger(false);
    closestShop = shop;
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

void PlayerTest::toggleLock()
{
    if (targetLocked) {
        _SetTarget(0, true);
    } else {
        lockRequested = !lockRequested;
        lockUpdatePending = false;
    }
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

void PlayerTest::onTargetCancelled()
{
    Stop();
    CameraManager::getInstance()->setTouchScreenInputs(true);
    unknown368 = 0;
    flags240 &= ~moveToTargetFlag;
}

void PlayerTest::showMesh()
{
    flags240 &= ~meshHiddenFlag;
    shadowNode->setVisible(true);
}

void PlayerTest::resumeAttacking()
{
    attackState = 1;
    flags240 &= ~0x200u;
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

void PlayerTest::jumpFinished()
{
    const int distance = currentJumpDistance / 100;
    if (distance > 0)
        AchievementManager::s_achievementManager->recordJump(distance);
    currentJumpDistance = 0;
}

void PlayerTest::driftFinished()
{
    const int distance = currentDriftDistance / 100;
    if (distance > 0)
        AchievementManager::s_achievementManager->recordDrift(distance);
    currentDriftDistance = 0;
}

void PlayerTest::addDistanceDriven(float distance)
{
    currentDistanceDriven += distance;
    if (currentDistanceDriven >= 100000) {
        currentDistanceDriven = 0;
        AchievementManager::s_achievementManager->recordKmDriven();
    }
}

void PlayerTest::UpdateSceneNode()
{
    if (_GetTarget())
        isFacingTarget();

    SavePositionInterface* position = this;
    Character* character = reinterpret_cast<Character*>(position);
    character->updatePosition(position->GetRotation());
}

void PlayerTest::ResetPlayerTest(bool)
{
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    const irr::core::vector3d<float> front = character->GetFront();
    facing.x = front.X;
    facing.y = front.Y;
    facing.z = front.Z;
    character->setCameraOffset(irr::core::vector3d<float>(0.0f, 1.0f, 0.0f));
    character->setAnimation(165, 1.0f, false, false, false);
    character->resetCollisions();
}

void PlayerTest::finishedStopDriving()
{
    CControlManager* controls = Application::GetInstance()->GetControlManager();
    unknown324 = 0;
    if (!ScriptManager::getInstance()->isInCinematic()) {
        if (unknown372 == 16) {
            Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
            CameraManager::getInstance()->enterMode(0, character, 0.0f, 1);
        }
        CameraManager::getInstance()->setTouchScreenInputs(true);
    }

    controls->exitCar(!(flags240 & 0x400u) && !ScriptManager::getInstance()->isInCinematic());
    if (!ScriptManager::getInstance()->isInCinematic())
        controls->unlock();

    static_cast<SavePrimaryInterface*>(this)->getWeapon()->show();
    if (vehicle && vehicle->immobilized)
        vehicle->mobilize();
    static_cast<SavePrimaryInterface*>(this)->setVehicle(0);
    vehicleVisibleInCinematic = true;
    unknown372 = 0;
}

void PlayerTest::setVehicle(Vehicle* value)
{
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    character->Character::setVehicle(value);
    if (!value)
        return;

    if (unknown316 != value) {
        GameObjectManager* manager = GameObjectManager::s_gom;
        manager->RemoveGameObjectOfType(vehicle->getSpawnType());
        GameObjectManager::s_gom->AddGameObjectOfType(11);
        vehicle->setSpawnType(11);
    }
    setLastUsedVehicle(value);
}

void PlayerTest::SetSpeed()
{
    const float x = collisionBody->linearVelocity.x;
    const float y = collisionBody->linearVelocity.y;
    speed = sqrtf(x * x + y * y);
}

void PlayerTest::setLastUsedVehicle(Vehicle* replacement)
{
    Vehicle* previous = static_cast<Vehicle*>(unknown316);
    if (previous && (previous->flags344 & 0x10000u))
        previous->rent(false);
    unknown316 = replacement;
}

void PlayerTest::justStoleCar(Vehicle* car)
{
    if (!car)
        return;
    if (!car->getHasBeenStolen() && !car->getName() && !(car->flags344 & 0x10000u)) {
        AchievementManager* achievements = AchievementManager::s_achievementManager;
        achievements->recordCarStolen(car->getUniqueId());
    }
    car->setHasBeenStolen();
    car->resetPreviousPos();
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

void PlayerTest::stopMoving(bool fast)
{
    const float speed = fast ? 2.0f : 1.0f;
    if (static_cast<int>(flags240 << 29) < 0) {
        setAnim(reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*this))->getSpecificAnimation(198), false, true, false, speed);
    } else if (static_cast<int>(flags240 << 30) < 0) {
        setAnim(reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*this))->getSpecificAnimation(212), false, true, false, speed);
    }

    // Use the same movement-mode update as Character::Stop.
    const int upperFlags = static_cast<int>(flags240) >> 8;
    const unsigned int preservedFlags = static_cast<unsigned int>(upperFlags) << 8;
    flags240 = preservedFlags | 1u;
}

void PlayerTest::_SetTarget(LevelObject* replacement, bool changeCamera)
{
    if (target && LevelObject::s_type[target->getObjectType()] == 5) {
        Character* character = reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*this));
        static_cast<NPC*>(target)->notifyTargeted(false, character);
    }

    target = replacement;
    if (!replacement) {
        targetLocked = false;
        lockRequested = false;
        if (CameraManager::getInstance()->getMode() == 1 ||
            (changeCamera && !(flags240 & 0xfeu))) {
            CameraManager* camera = CameraManager::getInstance();
            Character* character = reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*this));
            camera->enterMode(0, character, 0.3f, 0);
        }
    } else {
        targetLocked = true;
        lockUpdatePending = false;
        if (LevelObject::s_type[replacement->getObjectType()] == 5)
            static_cast<NPC*>(replacement)->notifyTargeted(
                true, reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*this)));
        Character* character = reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*this));
        if (changeCamera)
            CameraManager::getInstance()->enterMode(1, character, 0.3f, 0);
        character->goToCombatIdle();
    }
    Lock::getInstance()->setTarget(target);
}

void PlayerTest::acquireTarget()
{
    Weapon* weapon = Application::GetInstance()->GetWeaponManager()->getCurrentWeapon();
    if (target)
        return;
    LevelObject* replacement = getAttackableTarget(reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(this)), weapon, 0);
    if (replacement && replacement != target) {
        _SetTarget(replacement, true);
        lockRequested = true;
    }
}

#include "../characters/PlayerEvent.h"
#include "../core/EventManager.h"
#include "../audio/SoundManager.h"
void PlayerTest::startDriving()
{
    SoundManager::getInstance()->stop(PlayerTest::GetPlayer()->getAmbientSound(), -1, 0);
    static_cast<SavePrimaryInterface*>(this)->setVehicle(static_cast<Vehicle*>(unknown312));
    Application::GetInstance()->GetEventManager()->raise(EvPlayer(9));
    vehicle->startDriving();
    hideMesh();
    CameraManager::getInstance()->setTouchScreenInputs(true);
    ScriptManager::getInstance()->playerDrives(static_cast<Vehicle*>(unknown312));
}

#include "../characters/PlayerEvent.h"
#include "../core/EventManager.h"
bool PlayerTest::shoot(float elapsed, bool pressed)
{
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    if (character->Character::shoot(elapsed, pressed)) {
        Application::GetInstance()->GetEventManager()->raise(EvPlayer(2));
        return true;
    }
    return false;
}

#include "../characters/PlayerEvent.h"
#include "../core/EventManager.h"
#include "../audio/SoundManager.h"
#include "../characters/PhysicAttributes.h"
void PlayerTest::stopDriving(playertest::PlayerCarState::ePlayerCarState state, bool left)
{
    vehicleVisibleInCinematic = false;
    SoundManager* sound = SoundManager::getInstance();
    int ambient = PlayerTest::GetPlayer()->getAmbientSound();
    sound->unknown140 = true;
    sound->playEx(ambient, 0, true, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    if (ScriptManager::getInstance()->areBlockingCommandsSkipped())
        reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this))->resetCollisions();
    else
        unknown260 = true;
    reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this))->positionInVehicle(left);
    sceneNode->setRotation(vehicle->GetRotation() * irr::core::quaternion(0.0f, 0.0f, 1.57079632679489661923f));
    vehicle->stopDriving();
    Application* app = Application::GetInstance();
    app->GetControlManager()->lock();
    showMesh();
    if (physicAttributes)
        physicAttributes->SetPhysicInfo(*vehicle->getPhysicAttributes()->info, 0);
    flags240 &= ~0x400u;
    if (vehicle->GetSpeed() > 18.0f && state == static_cast<playertest::PlayerCarState::ePlayerCarState>(6)) {
        vehicle->openDoorFromInside(true);
        unknown372 = 9;
    } else {
        unknown372 = state;
    }
    app->GetEventManager()->raise(EvPlayer(10));
    ScriptManager::getInstance()->playerDrives(0);
}

bool PlayerTest::orientTowards(irr::core::vector3d<float> direction)
{
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    const irr::core::vector3d<float> right = character->GetRight();
    const float dot = right.dotProduct(direction.normalize());
    float angle = dot * (700.0f * unknown336);
    sceneNode->setRotation(sceneNode->getRotation() * irr::core::quaternion(0.0f, 0.0f, angle * -0.017453292519943295f));
    const irr::core::vector3d<float> front = character->GetFront();
    facing.x = front.X;
    facing.y = front.Y;
    facing.z = front.Z;
    return dot < 0.01f && dot > -0.01f;
}

#include "../core/VideoDriver.h"
void PlayerTest::debug(irr::video::IVideoDriver* driver)
{
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    irr::core::vector3d<float> right = character->GetRight();
    irr::core::vector3d<float> front = character->GetFront();
    const irr::core::matrix4& transform = sceneNode->getAbsoluteTransformation();
    irr::core::vector3d<float> up(transform[8], transform[9], transform[10]);
    irr::core::vector3d<float> position = character->GetPosition();
    {
    irr::core::vector3d<float> scaledRight = right * 200.0f;
    irr::core::vector3d<float> end(scaledRight.X + position.X, scaledRight.Y + position.Y, position.Z);
    driver->draw3DLine(position, end, irr::video::SColor(255, 0, 0, 255));
    }
    {
    irr::core::vector3d<float> scaledFront = front * 200.0f;
    irr::core::vector3d<float> end(scaledFront.X + position.X, scaledFront.Y + position.Y, position.Z);
    driver->draw3DLine(position, end, irr::video::SColor(255, 0, 255, 0));
    }
    {
    irr::core::vector3d<float> scaledUp = up * 200.0f;
    irr::core::vector3d<float> end(scaledUp.X + position.X, scaledUp.Y + position.Y, scaledUp.Z + position.Z);
    driver->draw3DLine(position, end, irr::video::SColor(255, 255, 0, 0));
    }
}

#include "../characters/PhysicAttributes.h"
#include "../rendering/GS3DStuff.h"
void PlayerTest::teleportTo(const LevelObject* destination)
{
    SavePositionInterface* position=static_cast<SavePositionInterface*>(this);
    if ((flags240&0x400u) && position->getVehicle()) {
        stopDriving(playertest::PlayerCarState::MovingOut,true);
        if (static_cast<SavePrimaryInterface*>(this)->getVehicle())
            static_cast<SavePrimaryInterface*>(this)->getVehicle()->Stop();
        position->setAnimation(165,1.0f,false,false,false);
        unknown324=0;
        Application::GetInstance()->GetControlManager()->exitCar(!ScriptManager::getInstance()->isInCinematic());
        static_cast<SavePrimaryInterface*>(this)->getWeapon()->show();
        static_cast<SavePrimaryInterface*>(this)->setVehicle(0);
    }
    unknown372=0;
    position->setNextAnimation(165,1,false,false,false);
    GS3DStuff::s_vehicle=0;
    ResetPlayerTest(false);
    Application::GetInstance()->GetHudManager()->walking();
    sceneNode->setRotation(destination->GetRotation());
    position->position(reinterpret_cast<const SaveVector3&>(static_cast<const irr::core::vector3d<float>&>(destination->GetPosition())));
    PhysicAttributes* physics=physicAttributes;
    unsigned short material=destination->GetMatID();
    unsigned short triangle=destination->GetTriID();
    physics->Init(material,triangle,position->position());
}
