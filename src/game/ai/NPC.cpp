/*
 * NPC
 *
 * Original file: NPC.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of NPC.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "AIManagerSingleton.h"
#include "NPC.h"
#include "../characters/PhysicAttributes.h"
#include "../world/Path.h"
#include "../app/Application.h"
#include "../characters/NPCEvent.h"
#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"
#include "../core/EventManager.h"
#include "../meta/Item.h"
#include "../world/GameObjectManager.h"

namespace {
union MovementFlags {
    unsigned int word;
    struct {
        unsigned int walking : 1;
        unsigned int running : 1;
    } bits;
};

inline unsigned int setMovementMode(unsigned int word, bool running)
{
    // Updating a bitfield in a local word reproduces GCC's mask and single store.
    MovementFlags flags;
    if (running) {
        flags.word = word & 0xffffbfe2u;
        flags.bits.running = 1;
    } else {
        flags.word = word & 0xffffbfe1u;
        flags.bits.walking = 1;
    }
    return flags.word;
}
}

namespace {
const unsigned int photographedFlag = 1u << 17;
}

Weapon* __attribute__((weak)) NPC::getWeapon() const
{
    return weapon;
}

void __attribute__((weak)) NPC::photographed()
{
    flags356 |= photographedFlag;
}

void __attribute__((weak)) NPC::clearPhotographed()
{
    flags356 &= ~photographedFlag;
}

bool __attribute__((weak)) NPC::isPhotographed() const
{
    return (flags356 & photographedFlag) != 0;
}

void NPC::attachWeaponToHand(irr::scene::ISceneNode* hand, irr::scene::ISceneNode* model)
{
    if (hand) {
        hand->removeAll();
        if (model) {
            hand->addChild(model);
            hand->setVisible(true);
            model->setVisible(true);
        }
    }
}

void NPC::goToLocation(const irr::core::vector3d<float>& point)
{
    if (flags356 & 0x8000u)
        runToLocation(point);
    else
        walkToLocation(point);
}

bool NPC::isCop()
{
    switch (GetMetatype()) {
    case 48:
    case 49:
    case 111:
    case 161:
    case 162:
        return true;
    default:
        return false;
    }
}

void NPC::runToLocation(const irr::core::vector3d<float>& point)
{
    if (!isDead()) {
        flags356 = setMovementMode(flags356, true);
        setDestination(point, 100);
        Character::runToLocation(point);
    }
}

void NPC::walkToLocation(const irr::core::vector3d<float>& point)
{
    if (!isDead()) {
        flags356 = setMovementMode(flags356, false);
        setDestination(point, 100);
        Character::walkToLocation(point);
    }
}

const Path* NPC::getPathToFollow() const
{
    return pathToFollow;
}

void NPC::setCurrentWaypoint(int waypoint)
{
    currentWaypoint = waypoint;
}

int NPC::getCurrentWaypoint() const
{
    return currentWaypoint;
}

void NPC::loopPathToFollow(bool loop)
{
    if (loop)
        flags356 |= 0x00200000u;
    else
        flags356 &= ~0x00200000u;
}

void NPC::setPathToFollow(const Path* path)
{
    currentWaypoint = -1;
    pathToFollow = path;
    loopPathToFollow(false);
}

bool NPC::isLoopingOnPathToFollow() const
{
    return (flags356 & 0x00200000u) != 0;
}

irr::core::vector3d<float> NPC::getNextWaypoint()
{
    irr::core::vector3d<float> point;
    if (activePath && activeWaypoint < activePath->getSize()) {
        activePath->getWaypoint(activeWaypoint++, point);
        if (isLoopingOnPathToFollow())
            activeWaypoint %= activePath->getSize();
    }
    return point;
}

bool NPC::getNextPoint(irr::core::vector3d<float>& point)
{
    const Path* path = getPathToFollow();
    if (!path || path != activePath) {
        activePath = path;
        activeWaypoint = 0;
    }
    if (activePath) {
        setCurrentWaypoint(activeWaypoint);
        if (activeWaypoint >= activePath->getSize())
            return false;
        point = getNextWaypoint();
    } else {
        point = getPhysicAttributes()->GetNextRandomPos(0, 0, GetPosition());
    }
    return true;
}

void NPC::goToNextPoint(bool repeat)
{
    if (repeat && activeWaypoint > 0)
        --activeWaypoint;

    irr::core::vector3d<float> point;
    if (getNextPoint(point)) {
        flags356 |= 0x00400000u;
        goToLocation(point);
    } else {
        flags356 &= ~0x00400000u;
        goToIdle();
    }
}

void NPC::equipWeapon(bool forceUnarmed, bool swapHands)
{
    GameObjectManager::s_gom->RemoveAndDestroy(weapon);
    weapon = 0;
    if (forceUnarmed || (!isDead() && (flags356 & 0x40000u)))
        weapon = WeaponManager::createWeapon(0);
    else
        weapon = WeaponManager::createWeapon(weaponType);

    irr::scene::ISceneNode* leftModel;
    irr::scene::ISceneNode* rightModel;
    if (weapon->getWeaponType() != 0) {
        if (swapHands) {
            leftModel = weapon->projectileSceneNode();
            if (weapon->isDouble())
                rightModel = weapon->secondarySceneNode();
            else
                rightModel = 0;
        } else {
            rightModel = weapon->projectileSceneNode();
            if (weapon->isDouble())
                leftModel = weapon->secondarySceneNode();
            else
                leftModel = 0;
        }
    } else {
        leftModel = 0;
        rightModel = 0;
    }
    attachWeaponToHand(leftHand, leftModel);
    attachWeaponToHand(rightHand, rightModel);
}

void NPC::notifyTargeted(bool targeted, Character* by)
{
    Application* app = Application::GetInstance();
    EventManager* events = app->GetEventManager();
    Weapon* currentWeapon = app->GetWeaponManager()->getCurrentWeapon();
    if (targeted) {
        targetingCharacter = by;
        if (currentWeapon->isGun() || currentWeapon->isProjectile())
            events->raise(EvNPC(EvNPC::Targeted, this));
        else
            events->raise(EvNPC(EvNPC::Untargeted, this));
    } else {
        events->raise(EvNPC(EvNPC::Untargeted, this));
    }
}

void NPC::die(bool flag)
{
    Character::die(flag);
    EventManager* events = Application::GetInstance()->GetEventManager();
    events->raise(EvNPCDeath(this));
    if (flags356 & 0x200u) {
        events->raise(EvNPC(EvNPC::DeathFlag512, this));
        flags356 &= ~0x200u;
    }
    events->raise(EvNPC(EvNPC::Death, this));
    flags356 &= ~0x2dfu;
    equipWeapon(false, false);
    irr::core::vector3d<float> position = GetPosition();
    if (weapon->dropsOnNPCDeath()) {
        Item::drop(weapon->GetMetatype(), position, 0);
        position.Y += 50.0f;
        GameObjectManager::s_gom->RemoveAndDestroy(weapon);
        weapon = 0;
    }
    if (cashDrop > 0)
        Item::drop(16, position, cashDrop);
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_npc_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_npc_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_npc_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_npc_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_npc_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_npc_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_npc_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_npc_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_npc_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_npc_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_npc_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN3NPC16s_combatSXFTimerE() __attribute__((used));
static void _GLOBAL__I__ZN3NPC16s_combatSXFTimerE()
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
