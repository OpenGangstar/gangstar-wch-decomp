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
        unsigned int : 1;
        unsigned int waiting : 1;
        unsigned int : 2;
        unsigned int attacking : 1;
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

void NPC::acquireTarget()
{
    if (!target)
        target = GameObjectManager::s_gom->getAttackableTarget(this);
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

    irr::scene::ISceneNode* leftModel = 0;
    irr::scene::ISceneNode* rightModel = 0;
    if (weapon->getWeaponType() != 0) {
        if (swapHands) {
            leftModel = weapon->projectileSceneNode();
            if (weapon->isDouble())
                rightModel = weapon->secondarySceneNode();
        } else {
            rightModel = weapon->projectileSceneNode();
            if (weapon->isDouble())
                leftModel = weapon->secondarySceneNode();
        }
    }
    attachWeaponToHand(leftHand, leftModel);
    attachWeaponToHand(rightHand, rightModel);
}

void NPC::attackTarget(LevelObject* object)
{
    equipWeapon(false, false);
    if (object) {
        SetTarget(object);
    } else {
        acquireTarget();
        SetTarget(target);
    }

    if (!(flags356 & 0x40u)) {
        MovementFlags flags;
        flags.word = flags356 & ~0x800000u;
        flags.bits.attacking = 1;
        flags356 = flags.word;
        attackState452 = false;
    }
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

bool __attribute__((weak)) NPC::isTargetable()
{
    if (isDead())
        return false;
    const bool dying = isDying();
    if (dying)
        return false;
    if (__builtin_expect((unknown4 & 4u) != 0, 0))
        return true;
    return dying;
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

void NPC::clearGoToVehicle()
{
    flags356 &= ~0x2800u;
    movementFlags &= ~0x001e0000u;
}

#include "../characters/PlayerTest.h"

void NPC::_arrest()
{
    PlayerTest* player = PlayerTest::GetPlayer();
    if (player->unknown417)
        player->unknown424 = false;
    else {
        player->_SetTarget(0, true);
        player->unknown424 = true;
    }
}

#include "../vehicles/Vehicle.h"
irr::core::vector3d<float> NPC::GetPosition() const
{
    if ((movementFlags & 0x400u) && !(unknown4 & 2u))
        return vehicle->GetPosition();
    return LevelObject::GetPosition();
}

void NPC::wait(int duration)
{
    if (!isDead()) {
        setAnimation(getSpecificAnimation(165), 1.0f, true, false, false);
        waitElapsed = 0;
        waitDuration = duration;
        MovementFlags flags;
        flags.word = flags356 & ~0x17u;
        flags.bits.waiting = 1;
        flags356 = flags.word;
    }
}

void NPC::UpdateSceneNode()
{
    updatePosition(GetRotation());
}

void NPC::Stop()
{
    Character::Stop();
    flags356 &= ~3u;
}

#include "../rendering/GS3DStuff.h"
void NPC::clean()
{
    AIManager::getInstance()->removeAI(this);
    cleanTimer = -5000;
    if (sceneNode) {
        GS3DStuff::SetAlpha(sceneNode, 255, GS3DStuff::Color0);
        GS3DStuff::SetMaterialType(sceneNode, static_cast<irr::video::E_MATERIAL_TYPE>(0));
    }
    Character::clean();
    flags356 = 0;
    unknown320 = 0;
}

#include "../rendering/GS3DStuff.h"
#include "../core/Color.h"
static const char npcAnimationRootName[] = "Bip01-node";
static const char npcLeftWeaponNodeName[] = "l_h_weapon-node";
static const char npcRightWeaponNodeName[] = "r_h_weapon-node";
void NPC::setupSceneNode(int id, irr::scene::ISceneNode* node, int count, void** parameters)
{
    LevelObject::setupSceneNode(id, node, count, parameters);
    AnimationInfo animation;
    bindAnimation(npcAnimationRootName, animation, node);
    GS3DStuff::SetColor(node, irr::video::SColor(255, 63, 63, 63), GS3DStuff::Color3);
    parameters[0] = animation.unknown0;
    parameters[1] = animation.unknown4;
    parameters[2] = animation.skinMesh;
    parameters[3] = animation.shadowNode;
    parameters[4] = node->getSceneNodeFromUID(npcLeftWeaponNodeName);
    parameters[5] = node->getSceneNodeFromUID(npcRightWeaponNodeName);
}

irr::scene::ISceneNode* NPC::grabSceneNode(int, void***)
{
    void** parameters;
    irr::scene::ISceneNode* node = LevelObject::grabSceneNode(6, &parameters);
    *reinterpret_cast<void**>(unknown164) = parameters[0];
    *reinterpret_cast<void**>(unknown164 + 4) = parameters[1];
    skinMesh = parameters[2];
    shadowNode = static_cast<irr::scene::ISceneNode*>(parameters[3]);
    shadowNode->setVisible(true);
    leftHand = static_cast<irr::scene::ISceneNode*>(parameters[4]);
    rightHand = static_cast<irr::scene::ISceneNode*>(parameters[5]);
    return node;
}

void NPC::SetWeapon(int type)
{
    weaponType = type;
    if (weapon && weapon->getWeaponType() != 0) {
        GameObjectManager::s_gom->RemoveAndDestroy(weapon);
        weapon = 0;
    }
    if (!weapon) {
        weapon = WeaponManager::createWeapon(0);
        GameObjectManager::s_gom->AddGameObjectOfType(LevelObject::s_type[weapon->getObjectType()]);
    }
}

void NPC::enable()
{
    Character::enable();
    flags356 = 0;
    health = maxHealth;
    SetWeapon(weaponType);
}

void NPC::dropSceneNode()
{
    LevelObject::dropSceneNode();
    *reinterpret_cast<void**>(unknown164) = 0;
    *reinterpret_cast<void**>(unknown164 + 4) = 0;
    skinMesh = 0;
    shadowNode = 0;
    rightHand = 0;
    leftHand = 0;
}

#include "../world/SceneNodeManager.h"

void NPC::WarmUp()
{
    LevelObject::WarmUp();
    if (s_nodePoolID[objectType] != 255)
        SceneNodeManager::getInstance()->manage(s_nodePoolID[objectType], this, 6);
}

#include "../audio/SoundManager.h"

void NPC::flee(const irr::core::vector3d<float>& point)
{
    if (isDead())
        return;
    flags356 &= ~0x1cu;
    flags356 |= 0x400004u;
    setDestination(point, 100);
    Character::runToLocation(point);
    if (isCurrentAnimation(34))
        setAnimation(35, 1.0f, false, false, false);
    if (!(flags356 & 2u)) {
        SoundManager* sound = SoundManager::getInstance();
        int soundId = 91;
        if (!driverBehavior) soundId = 65;
        sound->unknown140 = true;
        sound->playEx(soundId, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
    }
    flags356 |= 2u;
}

void NPC::flee()
{
    if (targetingCharacter)
        flee(targetingCharacter->GetPosition());
    else
        flee(-GetFront());
}

void NPC::notifyAttacked(LevelObject* source)
{
    if (source)
        SetTarget(source);
    Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(9), this));
}

void NPC::applyDamage(int amount, LevelObject* source, bool)
{
    if (unknown4 & 4u) {
        health -= amount;
        notifyAttacked(source);
    }
}

void NPC::switchAnim()
{
    Character::switchAnimation();
    if (isCurrentAnimation(83) || isCurrentAnimation(84) || isCurrentAnimation(85)) {
        if (flags356 & 0x40u)
            goToCombatIdle();
        else if (flags356 & 4u)
            setAnimation(getSpecificAnimation(165), 1.0f, true, false, false);
    } else if (isCurrentAnimation(96)) {
        setAnimation(getSpecificAnimation(165), 1.0f, true, false, false);
    }
}

#include "../scripting/ScriptManager.h"

void NPC::tagForKill(bool tagged)
{
    if (tagged) {
        flags356 |= 0x100000u;
        unknown4 |= 4u;
        ScriptManager::getInstance()->displayOnMinimap(this, true, true);
        showHighlight(0);
    } else {
        flags356 &= ~0x100000u;
        ScriptManager::getInstance()->displayOnMinimap(this, false, true);
        showHighlight(-1);
    }
}

void NPC::init()
{
    Character::init();
    SetWeapon(weaponType);
    if ((unknown4 & 1u) || (unknown4 & 128u))
        initPhysic();
    setAnimation(getSpecificAnimation(165), 1.0f, true, false, false);
    targetingCharacter = 0;
    lastHitVehicle = 0;
    movementFlags = 0;
    waitDuration = 0;
    unknown340 = 0;
    unknown344 = 0;
    waitElapsed = -1;
    flags356 = 0;
}

void NPC::clearOnAlert()
{
    SetTarget(0);
    if (flags356 & 0x200u)
        Application::GetInstance()->GetEventManager()->raise(EvNPC(EvNPC::DeathFlag512, this));
    flags356 &= ~0x12380u;
}

#include "../meta/Achievements.h"
void NPC::setHitByCar(bool hit)
{
    if (hit) {
        flags356 |= 0x400u;
        setVehicle(0);
        AchievementManager::s_achievementManager->recordRanOverPed();
    } else if (flags356 & 0x400u) {
        Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(21), this));
        flags356 &= ~0x400u;
    }
}

NPC::~NPC()
{
    if (weapon)
        GameObjectManager::s_gom->RemoveAndDestroy(weapon);
    weapon = 0;
    clean();
}

extern "C" {
extern irr::collada::CColladaFactory _ZZN12CGameFactory11getInstanceEvE2gf __attribute__((weak));
void _ZN12CGameFactoryD1Ev(irr::collada::CColladaFactory*) __attribute__((weak));
static void __tcf_1() __attribute__((used));
static void __tcf_1()
{
    _ZN12CGameFactoryD1Ev(&_ZZN12CGameFactory11getInstanceEvE2gf);
}
}

#include "../characters/PlayerTest.h"
void NPC::OnDespawn()
{
    if (weapon)
        GameObjectManager::s_gom->RemoveAndDestroy(weapon);
    weapon = 0;
    if (flags356 & 0x200u) {
        Application::GetInstance()->GetEventManager()->raise(EvNPC(EvNPC::DeathFlag512, this));
        flags356 &= ~0x200u;
    }
    Character::OnDespawn();
    for (LevelObject* object = GameObjectManager::s_gom->GetFirst(0); object; object = object->next) {
        if (LevelObject::s_type[object->getObjectType()] == 5) {
            Character* character = static_cast<Character*>(object);
            if (character->target == this)
                character->SetTarget(0);
        }
    }
    PlayerTest* player = PlayerTest::GetPlayer();
    if (player->getTarget() == this) {
        player->SetTarget(0);
        player->_SetTarget(0, true);
    }
}

#include "../characters/PlayerTest.h"
void NPC::disable()
{
    if (isEnabled()) {
        if (flags356 & 0x200u) {
            Application::GetInstance()->GetEventManager()->raise(EvNPC(EvNPC::DeathFlag512, this));
            flags356 &= ~0x200u;
        }
        if (flags356 & 0x100000u) {
            tagForKill(false);
            ScriptManager::getInstance()->taggedKilled();
        }
        AIManager::getInstance()->removeAI(this);
        setPathToFollow(0);
        activePath = 0;
        activeWaypoint = 0;
        Character::disable();
        for (LevelObject* object = GameObjectManager::s_gom->GetFirst(0); object; object = object->next) {
            if (LevelObject::s_type[object->getObjectType()] == 5) {
                NPC* npc = static_cast<NPC*>(object);
                if (npc->target == this)
                    npc->SetTarget(0);
            }
        }
        PlayerTest* player = PlayerTest::GetPlayer();
        if (player->getTarget() == this) {
            static_cast<SavePositionInterface&>(*player).SetTarget(0);
            player->_SetTarget(0, true);
        }
    }
}

NPC::NPC(int type)
    : Character(type), weapon(0), targetingCharacter(0), unknown316(0), unknown320(0),
      activePath(0), activeWaypoint(0), unknown340(0), unknown344(0), waitDuration(0),
      waitElapsed(-1), flags356(0), searchRadiusScale(1.0f), searchRadiusSquared(0.0f),
      unknown396(0), unknown400(0), unknown432(10.0f), unknown436(true),
      pathToFollow(0), currentWaypoint(-1), unknown448(0), attackState452(false)
{
}

void NPC::goToVehicle(Vehicle* value, bool left, bool run, bool force, bool flag)
{
    if (isDead())
        return;
    flags356 &= 0xffffbfe0u;
    if (run)
        flags356 |= 2u;
    else
        flags356 |= 1u;
    if (force) {
        flags356 |= 0x800u;
        flags356 &= ~0x2000u;
    }
    if (flag)
        flags356 |= 0x2000u;
    if (vehicle != value && value) {
        setVehicle(value);
        if (left) {
            *reinterpret_cast<irr::scene::ISceneNode**>(unknown192) = vehicle->leftDoor;
            setDestination(vehicle->leftDoor->getAbsolutePosition(), 100);
        } else {
            *reinterpret_cast<irr::scene::ISceneNode**>(unknown192) = vehicle->rightDoor;
            setDestination(vehicle->rightDoor->getAbsolutePosition(), 100);
        }
        if (run)
            Character::runToLocation(irr::core::vector3d<float>(adjustedDestination));
        else
            Character::walkToLocation(irr::core::vector3d<float>(adjustedDestination));
    }
}

#include "../world/ObjectData.h"
extern "C" irr::collada::CColladaFactory* _ZN12CGameFactory11getInstanceEv() __attribute__((weak));

void NPC::Load(const Structs::NPC& data)
{
    LevelObject::Load(data, _ZN12CGameFactory11getInstanceEv());
    category428 = data.unknown72;
    health = maxHealth = data.unknown96;
    unknown212 = data.unknown76;
    driverBehavior = data.unknown92;
    weaponType = data.unknown112;
    cashDrop = data.unknown80;
    faction = data.unknown88;
    unknown404 = data.unknown104;
    unknown408 = data.unknown100;
    unknown412 = data.unknown84;
    searchRadiusSquared = static_cast<float>(data.unknown108);
    if (__builtin_expect(s_nodePoolID[objectType] == 255, 1)) {
        bindAnimation(npcAnimationRootName, *reinterpret_cast<AnimationInfo*>(unknown164), 0);
        leftHand = sceneNode->getSceneNodeFromUID(npcLeftWeaponNodeName);
        rightHand = sceneNode->getSceneNodeFromUID(npcRightWeaponNodeName);
        GS3DStuff::SetColor(sceneNode, irr::video::SColor(255, 63, 63, 63), GS3DStuff::Color3);
    }
}
