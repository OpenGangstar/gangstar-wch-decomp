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
#include "../core/IrrlichtDevice.h"
#include "../characters/NPCEvent.h"
#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"
#include "../core/EventManager.h"
#include "../meta/Item.h"
#include "../world/GameObjectManager.h"

int NPC::s_combatSXFTimer;

namespace {
union MovementFlags {
    unsigned int word;
    struct {
        unsigned int walking : 1;
        unsigned int running : 1;
        unsigned int : 1;
        unsigned int waiting : 1;
        unsigned int frozen : 1;
        unsigned int : 1;
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
    unknown164Pointer = parameters[0];
    unknown168Pointer = parameters[1];
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
    unknown164Pointer = 0;
    unknown168Pointer = 0;
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
            entryDoor = vehicle->leftDoor;
            setDestination(vehicle->leftDoor->getAbsolutePosition(), 100);
        } else {
            entryDoor = vehicle->rightDoor;
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
        bindAnimation(npcAnimationRootName, *reinterpret_cast<AnimationInfo*>(&unknown164Pointer), 0);
        leftHand = sceneNode->getSceneNodeFromUID(npcLeftWeaponNodeName);
        rightHand = sceneNode->getSceneNodeFromUID(npcRightWeaponNodeName);
        GS3DStuff::SetColor(sceneNode, irr::video::SColor(255, 63, 63, 63), GS3DStuff::Color3);
    }
}

#include "../core/VideoDriver.h"
void NPC::debug(irr::video::IVideoDriver* driver)
{
    irr::core::vector3d<float> position = GetPosition();
    position.Z = 25.0f + position.Z;
    irr::core::vector3d<float> a(position.X - 50.0f, position.Y - 50.0f, position.Z);
    irr::core::vector3d<float> b(position.X - 50.0f, position.Y + 50.0f, position.Z);
    irr::core::vector3d<float> c(position.X + 50.0f, position.Y + 50.0f, position.Z);
    irr::core::vector3d<float> d(position.X + 50.0f, position.Y - 50.0f, position.Z);
    driver->draw3DLine(a, b, irr::video::SColor(255, 0, 0, 0));
    driver->draw3DLine(b, c, irr::video::SColor(255, 0, 0, 0));
    driver->draw3DLine(c, d, irr::video::SColor(255, 0, 0, 0));
    driver->draw3DLine(d, a, irr::video::SColor(255, 0, 0, 0));
}

#include "../core/Geometry.h"
void NPC::UpdateCarPosIfUnderWheel()
{
    if (lastHitVehicle) {
        const irr::core::aabbox3d<float> bounds=static_cast<irr::scene::ISceneNode*>(skinMesh)->getTransformedBoundingBox();
        if (bounds.MinEdge.X <= lastHitVehicle->wheelPosition0.X &&
            bounds.MaxEdge.X >= lastHitVehicle->wheelPosition0.X &&
            bounds.MinEdge.Y <= lastHitVehicle->wheelPosition0.Y &&
            bounds.MaxEdge.Y >= lastHitVehicle->wheelPosition0.Y &&
            bounds.MinEdge.Z <= lastHitVehicle->wheelPosition0.Z &&
            bounds.MaxEdge.Z >= lastHitVehicle->wheelPosition0.Z)
            lastHitVehicle->wheelGroundHeights[0]=bounds.MaxEdge.Z;
        if (bounds.MinEdge.X <= lastHitVehicle->wheelPosition1.X &&
            bounds.MaxEdge.X >= lastHitVehicle->wheelPosition1.X &&
            bounds.MinEdge.Y <= lastHitVehicle->wheelPosition1.Y &&
            bounds.MaxEdge.Y >= lastHitVehicle->wheelPosition1.Y &&
            bounds.MinEdge.Z <= lastHitVehicle->wheelPosition1.Z &&
            bounds.MaxEdge.Z >= lastHitVehicle->wheelPosition1.Z)
            lastHitVehicle->wheelGroundHeights[1]=bounds.MaxEdge.Z;
        if (bounds.MinEdge.X <= lastHitVehicle->wheelPosition2.X &&
            bounds.MaxEdge.X >= lastHitVehicle->wheelPosition2.X &&
            bounds.MinEdge.Y <= lastHitVehicle->wheelPosition2.Y &&
            bounds.MaxEdge.Y >= lastHitVehicle->wheelPosition2.Y &&
            bounds.MinEdge.Z <= lastHitVehicle->wheelPosition2.Z &&
            bounds.MaxEdge.Z >= lastHitVehicle->wheelPosition2.Z)
            lastHitVehicle->wheelGroundHeights[2]=bounds.MaxEdge.Z;
        if (bounds.MinEdge.X <= lastHitVehicle->wheelPosition3.X &&
            bounds.MaxEdge.X >= lastHitVehicle->wheelPosition3.X &&
            bounds.MinEdge.Y <= lastHitVehicle->wheelPosition3.Y &&
            bounds.MaxEdge.Y >= lastHitVehicle->wheelPosition3.Y &&
            bounds.MinEdge.Z <= lastHitVehicle->wheelPosition3.Z &&
            bounds.MaxEdge.Z >= lastHitVehicle->wheelPosition3.Z)
            lastHitVehicle->wheelGroundHeights[3]=bounds.MaxEdge.Z;
    }
}

extern "C" long lrand48();

void NPC::freeze()
{
    if (isDead()) return;
    MovementFlags flags;
    flags.word = flags356 & ~15u;
    flags.bits.frozen = 1;
    flags356 = flags.word;
    if (targetingCharacter)
        turnToward(targetingCharacter->GetPosition());
    setAnimation(37, 1.0f, false, false, false);
    int soundId;
    switch (lrand48() % 2) {
    case 0: soundId = 88; if (!driverBehavior) soundId = 86; break;
    case 1: soundId = 76; if (!driverBehavior) soundId = 73; break;
    default: return;
    }
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(soundId, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
}

void NPC::triggerCombatSFX(int type)
{
    if (!type) return;
    const int now = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    if (now < s_combatSXFTimer + 5000) return;
    if (lrand48() % 100 <= 50) {
        s_combatSXFTimer = now;
        return;
    }
    int soundId;
    switch (type) {
    case 1: soundId = 72; if (lrand48() % 2 == 1) soundId = 68; break;
    case 2: soundId = 56; if (lrand48() % 2 == 1) soundId = 84; break;
    case 3: soundId = 96; break;
    case 5: soundId = 87; break;
    case 4: soundId = 58; break;
    case 6:
        if (!(lrand48() % 2 == 1)) soundId = 55;
        else soundId = 64;
        break;
    default: return;
    }
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(soundId, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    for (LevelObject* object = GameObjectManager::s_gom->GetFirst(0); object; object = object->next) {
        if (LevelObject::s_type[object->getObjectType()] == 5) {
            NPC* npc = static_cast<NPC*>(object);
            if (npc->flags356 & 0x40u)
                npc->attackState452 = true;
        }
    }
}

bool NPC::isOutsideSearchRadius()
{
    if (category428 != 5)
        return false;
    bool inside = false;
    if (!(GetPosition().getDistanceFromSQ(searchOrigin) > searchRadiusSquared))
        inside = true;
    return !inside;
}

bool NPC::isUnderCar()
{
    if (!lastHitVehicle)
        return false;
    irr::core::vector3d<float> corners[4];
    lastHitVehicle->getCollisionRect(corners, 50.0f);
    irr::core::vector3d<float> pos = GetPosition();
    irr::core::vector3d<float> d0 = pos - corners[0];
    irr::core::vector3d<float> e0 = corners[1] - corners[0];
    irr::core::vector3d<float> d1 = pos - corners[1];
    irr::core::vector3d<float> e1 = corners[2] - corners[1];
    irr::core::vector3d<float> d2 = pos - corners[2];
    irr::core::vector3d<float> e2 = corners[3] - corners[2];
    irr::core::vector3d<float> d3 = pos - corners[3];
    irr::core::vector3d<float> e3 = corners[0] - corners[3];
    if (d0.Y * e0.X - d0.X * e0.Y < 0.0f)
        return false;
    if (d1.Y * e1.X - d1.X * e1.Y < 0.0f)
        return false;
    if (d2.Y * e2.X - d2.X * e2.Y < 0.0f)
        return false;
    return !(d3.Y * e3.X - d3.X * e3.Y < 0.0f);
}

#include "../characters/PlayerTest.h"
#include "../meta/Factions.h"
static inline bool areFactionsHostile(unsigned int otherFaction, int faction)
{
    if (faction == 2)
        return otherFaction == 1;
    if (faction == 1)
        return otherFaction == 2;
    return false;
}

bool NPC::isHostileTo(LevelObject* object)
{
    if (flags356 & 0x40u) {
        if (target == object)
            return true;
        if (object == static_cast<LevelObject*>(PlayerTest::GetPlayer()))
            return Factions::isFactionEnemy(faction);
        if (LevelObject::s_type[object->getObjectType()] == 5)
            return areFactionsHostile(static_cast<NPC*>(object)->faction, faction);
    }
    return false;
}


static inline bool isPlayerInVehicle(PlayerTest* player)
{
    return (player->flags240 & 0x400u) && static_cast<Character&>(*player).getVehicle();
}

// NPC::SetTarget is declared in NPC.h; define it by mangled name so the
// shared header is unchanged. Character fields are reached through one view and
// the NPC flags word through another, so the target store and the flags load are
// not disambiguated (retail keeps the store ahead of the load).
struct SetTargetCharacterView {
    unsigned char pad0[236];
    unsigned int movementFlags;
    unsigned char pad240[20];
    LevelObject* target;
};
struct SetTargetNPCView {
    unsigned char pad0[356];
    unsigned int flags356;
};

// The target store address is formed as self + (offset of flags356 in a view of
// object - 356). The value is self; the form materialises the 356 constant before
// the store, which gives retail's global register allocation (offset pseudo after
// the flags pseudo). It forms an address from a possibly null object without
// dereferencing it.
extern "C" void _ZN3NPC9SetTargetEP11LevelObject(NPC* self, LevelObject* object)
{
    SetTargetCharacterView* c = reinterpret_cast<SetTargetCharacterView*>(self);
    SetTargetNPCView* v = reinterpret_cast<SetTargetNPCView*>(self);
    int soundId;
    if (self->isCop() && !((c->movementFlags & 0x400u) && static_cast<Character*>(self)->getVehicle())
        && !c->target && object) {
        switch (lrand48() % 5) {
        case 2: goto case2;
        case 4: goto case4;
        case 0: goto case0;
        default: goto store;
        }
    play:
        {
            SoundManager* sound = SoundManager::getInstance();
            sound->unknown140 = true;
            sound->playEx(soundId, 0, false, 1.0f, 0, true, 1.0f, 0);
            sound->unknown140 = false;
        }
    }
store:
    {
        SetTargetNPCView* w = reinterpret_cast<SetTargetNPCView*>(object);
        int d = reinterpret_cast<char*>(&w->flags356) - reinterpret_cast<char*>(object);
        reinterpret_cast<SetTargetCharacterView*>(reinterpret_cast<char*>(self) + (d - 356))->target
            = object;
    }
    if (v->flags356 & 0x2800u) {
        if (!object) {
            v->flags356 &= ~0x2800u;
            return;
        }
        PlayerTest* player = PlayerTest::GetPlayer();
        if ((player && object == static_cast<LevelObject*>(player)
             && !isPlayerInVehicle(PlayerTest::GetPlayer()))
            || (LevelObject::s_type[object->getObjectType()] == 5
                && !((reinterpret_cast<SetTargetCharacterView*>(object)->movementFlags & 0x400u)
                     && static_cast<Character*>(object)->getVehicle())))
            v->flags356 &= ~0x2800u;
    }
    return;
case4:
    soundId = 64;
    goto play;
case0:
    soundId = 97;
    goto play;
case2:
    soundId = 79;
    goto play;
}

#include "../scripting/ScriptManager.h"
#include "../core/Geometry.h"

namespace {
// Partial field views used by the detection pass; never constructed or copied.
struct NPCDetectFields {
    unsigned char beforeSceneNode[16];
    irr::scene::ISceneNode* sceneNode;
    unsigned char beforeTarget[240];
    LevelObject* target;
    unsigned char beforeFlags[92];
    unsigned int flags356;
    unsigned char beforeRadius[28];
    float searchRadiusSquared;
    unsigned char beforeCategory[36];
    unsigned int category428;
};

struct DetectCharacterFields {
    unsigned char beforeSceneNode[16];
    irr::scene::ISceneNode* sceneNode;
    unsigned char beforeMovementFlags[216];
    unsigned int movementFlags;
};

struct DetectPlayerFields {
    unsigned char beforeMovementFlags[240];
    unsigned int movementFlags;
};

inline void markDetected(NPCDetectFields& fields)
{
    MovementFlags flags;
    flags.word = fields.flags356 | 0x200u;
    flags.bits.waiting = 0;
    fields.flags356 = flags.word;
}

// Detection flag word with the detected bit (0x200) named, so the word is
// read before the bit is set.
union DetectFlags {
    unsigned int word;
    struct {
        unsigned int : 3;
        unsigned int waiting : 1;
        unsigned int : 5;
        unsigned int detected : 1;
    } bits;
};

inline void markDetectedBits(NPCDetectFields& fields)
{
    DetectFlags flags;
    flags.word = fields.flags356;
    flags.bits.detected = 1;
    flags.bits.waiting = 0;
    fields.flags356 = flags.word;
}
}

extern "C" float acosf(float);
extern "C" double sqrt(double);

extern "C" void _ZN3NPC7_detectEv(NPC* npc)
{
    NPCDetectFields& fields = *reinterpret_cast<NPCDetectFields*>(npc);
    if (ScriptManager::getInstance()->isInCinematic())
        fields.flags356 |= 0x800000u;
    else
        fields.flags356 &= ~0x800000u;
    if (!fields.target || !fields.sceneNode
        || !reinterpret_cast<DetectCharacterFields*>(fields.target)->sceneNode)
        return;
    const int type = LevelObject::s_type[fields.target->getObjectType()];
    // Taking the label address only pins the redirect block's label; the
    // value is unused, so no computed jump exists.
    void* const redirectLabel = &&vehicleRedirect;
    (void)redirectLabel;
    switch (type) {
    case 5:
    case 8:
    vehicleRedirect:
        if ((reinterpret_cast<DetectCharacterFields*>(fields.target)->movementFlags & 0x400u)
            && static_cast<Character*>(fields.target)->getVehicle())
            fields.target = static_cast<Character*>(fields.target)->getVehicle();
        break;
    }
    EventManager* events = Application::GetInstance()->GetEventManager();
    PlayerTest* player = PlayerTest::GetPlayer();
    irr::core::vector3d<float> delta = fields.target->GetPosition() - npc->GetPosition();
    const float distanceSquared = delta.getLengthSQ();
    irr::core::vector3d<float> point(0.0f, 0.0f, 0.0f);
    if (fields.flags356 & 0x100u) {
        if (distanceSquared <= fields.searchRadiusSquared
            && npc->canSeeLevelObject(fields.target, point)) {
            if (!(fields.flags356 & 0x200u)) {
                events->raise(EvNPC(static_cast<EvNPC::State>(18), npc));
                markDetected(fields);
            }
            if (fields.category428 == 3 && fields.target == player && distanceSquared <= 40000.0f
                && static_cast<int>(reinterpret_cast<DetectPlayerFields*>(player)->movementFlags) < 0)
                npc->_arrest();
        } else if (fields.flags356 & 0x200u) {
            fields.flags356 &= ~0x240u;
            events->raise(EvNPC(static_cast<EvNPC::State>(19), npc));
        }
    } else {
        if (distanceSquared <= fields.searchRadiusSquared
            && npc->canSeeLevelObject(fields.target, point)) {
            if (!(fields.flags356 & 0x200u)) {
                const float dot = delta.dotProduct(npc->GetFront());
                const double length = sqrt(distanceSquared);
                const float cosine = dot / (static_cast<float>(length) * npc->GetFront().getLength());
                if (acosf(irr::core::clamp(cosine, -1.0f, 1.0f)) <= 1.5f
                    || distanceSquared <= 0.0625f * fields.searchRadiusSquared) {
                    events->raise(EvNPC(static_cast<EvNPC::State>(18), npc));
                    markDetectedBits(fields);
                }
                if (fields.target == player && distanceSquared <= 40000.0f
                    && static_cast<int>(reinterpret_cast<DetectPlayerFields*>(player)->movementFlags) < 0)
                    npc->_arrest();
            }
        } else if (fields.flags356 & 0x200u) {
            fields.flags356 &= ~0x240u;
            events->raise(EvNPC(static_cast<EvNPC::State>(19), npc));
        }
    }
}
// File-local view of NPC+316, the target remembered while attacking a vehicle.
struct NPCRememberedTargetView { unsigned char unknown0[316]; LevelObject* rememberedTarget; };
static inline bool isRidingVehicle(unsigned int movementFlags, Character* character)
{
    return (movementFlags&0x400u) && character->getVehicle();
}

// NPC fields used by attackTarget are private; reach them through a layout view.
// Character members used here are private to Character.
struct NPCAttackCharacterView {
    unsigned char pad0[236];
    unsigned int movementFlags;
    unsigned char pad240[12];
    int unknown252;
    unsigned char pad256[4];
    LevelObject* target;
};
extern "C" void _ZN9Character16turnTowardTargetEf(Character*, float);
extern "C" bool _ZN9Character14isFacingTargetEP11LevelObject(Character*, LevelObject*);
struct NPCAttackTargetView {
    unsigned char pad0[308];
    Weapon* weapon;
    unsigned char pad312[4];
    unsigned int unknown316;
    unsigned char pad320[20];
    int unknown340;
    int unknown344;
    unsigned char pad348[8];
    unsigned int flags356;
    unsigned char pad360[32];
    int weaponType;
    int unknown396;
    int unknown400;
    int unknown404;
    int unknown408;
    unsigned char pad412[12];
    int faction;
    unsigned char pad428[4];
    float unknown432;
    bool unknown436;
};
extern "C" void _ZN3NPC13acquireTargetEv(NPC*);
extern "C" void _ZN3NPC11equipWeaponEbb(NPC*, bool, bool);
extern "C" bool _ZN9Character18isCurrentAnimationEi(Character*, int);
extern "C" int _ZN9Character20getSpecificAnimationEi(Character*, int);
extern "C" void _ZN9Character11runToTargetEi(Character* self, int distance);
struct NPCAttackObjectTypeView { unsigned char pad0[36]; unsigned char objectType; };
extern "C" bool _ZN3NPC12attackTargetEv(NPC* self)
{
    NPCAttackCharacterView* c=reinterpret_cast<NPCAttackCharacterView*>(self);
    NPCAttackTargetView* v=reinterpret_cast<NPCAttackTargetView*>(self);
    Application* app=Application::GetInstance();
    EventManager* events=app->GetEventManager();
    LevelObject* current=c->target;
    if(!current){
        _ZN3NPC13acquireTargetEv(self);
        current=c->target;
        if(!current){self->goToIdle();events->raise(EvNPC(static_cast<EvNPC::State>(13),self));v->flags356&=~0x40u;return false;}
    }
    if(v->faction==2 && LevelObject::s_type[current->getObjectType()]!=8 && current->getHealth()<=25){
        c->target=0;events->raise(EvNPC(static_cast<EvNPC::State>(12),self));return false;
    }
    if(c->target->isDead()){c->target=0;return false;}
    if((LevelObject::s_type[c->target->getObjectType()]==5 || LevelObject::s_type[c->target->getObjectType()]==8) && _ZN9Character18isCurrentAnimationEi(static_cast<Character*>(c->target),164))return false;
    // The movement-flag test is a separate check; together with the single
    // targetType lookup below this keeps native expansion and reload order.
    if(_ZN9Character18isCurrentAnimationEi(self,164)||_ZN9Character18isCurrentAnimationEi(self,86)||_ZN9Character18isCurrentAnimationEi(self,175))return false;if(c->movementFlags&0x100000u)return false;
    int targetType=LevelObject::s_type[reinterpret_cast<NPCAttackObjectTypeView*>(c->target)->objectType];
    // Nested test keeps the goToVehicle exit ahead of the type reload in RTL order.
    if(targetType==3){ if(v->weapon->getWeaponType()==0){self->goToVehicle(static_cast<Vehicle*>(c->target),true,true,false,true);return false;} }
    if((LevelObject::s_type[reinterpret_cast<NPCAttackObjectTypeView*>(c->target)->objectType]==5||LevelObject::s_type[reinterpret_cast<NPCAttackObjectTypeView*>(c->target)->objectType]==8) && isRidingVehicle(reinterpret_cast<NPCAttackCharacterView*>(c->target)->movementFlags,static_cast<Character*>(c->target))){
        if(v->weapon->getWeaponType()==0){self->goToVehicle(static_cast<Character*>(c->target)->getVehicle(),true,true,false,true);return false;}
        v->unknown316=reinterpret_cast<unsigned int>(c->target);self->SetTarget(static_cast<Character*>(c->target)->getVehicle());
    }
    else if(LevelObject::s_type[reinterpret_cast<NPCAttackObjectTypeView*>(c->target)->objectType]==3 && !static_cast<Vehicle*>(c->target)->getDriver()){
        NPCRememberedTargetView* memory=reinterpret_cast<NPCRememberedTargetView*>(self);
        if(memory->rememberedTarget){self->SetTarget(memory->rememberedTarget);v->unknown316=0;}else events->raise(EvNPC(static_cast<EvNPC::State>(13),self));
    }
    const irr::core::vector3d<float> position=self->GetPosition();
    const irr::core::vector3d<float> targetPosition=c->target->GetPosition();
    const float distance=position.getDistanceFrom(targetPosition);
    WeaponManager* weapons=app->GetWeaponManager();
    if(v->weapon->getWeaponType()==0 && v->weaponType!=0 && distance>weapons->getWeaponInList(0,static_cast<PlayerTest::eContext>(-1))->getRange() && !(v->flags356&0x80u)){
        _ZN3NPC11equipWeaponEbb(self,false,false);self->goToCombatIdle();
    }
    if(v->weapon->getWeaponType()==8){
        _ZN9Character16turnTowardTargetEf(self,v->unknown432);
        unsigned int now=app->GetDevice()->getTimer()->getRealTime();
        // Contrived prediction form: the facing test compares against a non-zero
        // constant through a one-field aggregate and the no-code prefetch marks
        // the deadline test as guarded; both only steer branch prediction.
        struct { unsigned int k; } facing={static_cast<unsigned int>(_ZN9Character14isFacingTargetEP11LevelObject(self,c->target))+1u};
        if(facing.k==1u)return false;
        __builtin_prefetch(self);
        if(!(now>static_cast<unsigned int>(v->unknown340+v->unknown344)))return false;
        v->unknown432=5.0f;
        if(__builtin_expect(distance>=v->weapon->getRange()*40,1) && distance<=v->weapon->getRange()*60)c->unknown252=20;
        else if(distance>v->weapon->getRange()*40)c->unknown252=13;
        else if(distance<v->weapon->getRange()*60)c->unknown252=25;
        else c->unknown252=0;
        bool attacked=!(v->flags356&0x800000u);
        // Contrived prediction form: the guard is compared against a non-zero
        // constant through a one-field aggregate, so the branch predictor sees an
        // equality test; later passes fold it back to the attacked test.
        struct { unsigned int k; } guard={static_cast<unsigned int>(attacked)+1u}; if(guard.k==2u)attacked=self->attack();
        v->unknown340=now;v->unknown344=lrand48()%1000+1500;return attacked;
    }
    if(distance>v->weapon->getRange()){
        if(!self->isOutsideSearchRadius())_ZN9Character11runToTargetEi(self,0);
        v->unknown436=true;c->unknown252=0;return false;
    }
    if(v->weapon->getWeaponType()!=0 && distance<=weapons->getWeaponInList(0,static_cast<PlayerTest::eContext>(-1))->getRange()){
        _ZN3NPC11equipWeaponEbb(self,true,false);self->goToCombatIdle();
    }
    v->weapon->getWeaponType();
    if(v->weapon->getWeaponType()==0){v->unknown396=0;v->unknown400=0;c->unknown252=16;}
    else if(distance>=static_cast<float>(v->weapon->getRange())*0.4f && distance<=static_cast<float>(v->weapon->getRange())*0.6f){
        v->unknown396=0;v->unknown400=lrand48()%5;if(v->weapon->getWeaponType()!=8)c->unknown252=16;else c->unknown252=20;
    }
    bool attacked=false;
    if(v->flags356&0x800000u){v->unknown396=0;v->unknown400=1;attacked=true;}
    if(v->unknown396<=v->unknown400){
        // The idle exit is placed ahead of the attack checks; the checks fall
        // through into the attack body.
        if(0){
        idle:
            self->goToCombatIdle();
            return attacked;
        }
        if(!(c->movementFlags&0x4000000u))goto idle;
        if(_ZN9Character18isCurrentAnimationEi(self,_ZN9Character20getSpecificAnimationEi(self,188)))goto idle;
        if(_ZN9Character18isCurrentAnimationEi(self,_ZN9Character20getSpecificAnimationEi(self,202)))goto idle;
        {
            _ZN9Character16turnTowardTargetEf(self,v->unknown432);
            unsigned int now=app->GetDevice()->getTimer()->getRealTime();
            // Facing flag join: the timer-deadline test is threaded out of line,
            // which keeps native reload register order for the 344 offset.
            bool facing=false; if(_ZN9Character14isFacingTargetEP11LevelObject(self,c->target))facing=true;
            if(!facing)return attacked;
            if(now>static_cast<unsigned int>(v->unknown340+v->unknown344)){
                v->unknown432=5.0f;
                if(!(v->flags356&0x800000u))attacked=self->attack();
                v->unknown340=now;++v->unknown396;
                if(v->weapon->getWeaponType()==0){v->unknown344=lrand48()%(v->unknown408-v->unknown404)+v->unknown404;return attacked;}
                else{v->unknown344=lrand48()%1000+1500;return attacked;}
            }
        }
        return attacked;
    }
    if(c->movementFlags&0x10000000u){if(!(c->movementFlags&0x20000000u))return attacked;}
    if(distance>static_cast<float>(v->weapon->getRange())*0.4f){
        if(!self->isOutsideSearchRadius())_ZN9Character11runToTargetEi(self,0);
        if(v->weapon->getWeaponType()==8)c->unknown252=13;else c->unknown252=0;
        if(lrand48()%1000>990){v->unknown396=0;v->unknown400=1;return attacked;}
        return attacked;
    }
    if(distance<static_cast<float>(v->weapon->getRange())*0.6f){
        if(!self->isOutsideSearchRadius()){v->weapon->getWeaponType();_ZN9Character11runToTargetEi(self,static_cast<int>(static_cast<float>(v->weapon->getRange())*0.5f));}
        v->unknown432=10.0f;
        if(lrand48()%1000>990){v->unknown396=0;v->unknown400=1;}
        if(v->weapon->getWeaponType()==8){c->unknown252=25;return attacked;}else{c->unknown252=100;return attacked;}
    }
    return attacked;
}
#include "../characters/PhysicInfo.h"
#include "../core/Physics.h"
void operator delete(void*) throw();
namespace {
// Partial field view: retail reads offset 320 as a Vehicle pointer; never constructed.
struct NPCUpdateFields {
    unsigned char beforeAvoidVehicle[320];
    Vehicle* avoidVehicle;
};
// Box2D-style inline vector helpers (b2Math operator* and operator+), y component first.
inline b2Vec2 npcVecScale(float s,const b2Vec2& a) { float y=s*a.y; return b2Vec2(s*a.x,y); }
inline b2Vec2 npcVecAdd(const b2Vec2& a,const b2Vec2& b) { float y=a.y+b.y; return b2Vec2(a.x+b.x,y); }
}
extern "C" void _ZN3NPC7_detectEv(NPC*);
extern "C" bool _ZN9Character6isDownEv(Character*) __attribute__((weak));
extern "C" bool _ZN9Character15updateAnimationEf(Character*,float);
void NPC::Update(int elapsed)
{
    unknown296=irr::core::vector3d<float>(0.0f,0.0f,0.0f);
    if(flags356&0x2000u) {
        LevelObject* initialTarget=target;
        PlayerTest* player;
        // Contrived prediction form: a one-field aggregate compare against a non-zero
        // constant replaces the pointer heuristic with opcode-nonequal (71%), so the
        // second GetPlayer trace is colder than the door stubs; folds back later.
        if(({ struct { unsigned int k; } tv={reinterpret_cast<unsigned int>(initialTarget)+1u}; tv.k==1u; }) ||
            ((player=PlayerTest::GetPlayer()) && initialTarget==reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player)) &&
                (!((player=PlayerTest::GetPlayer())->flags240&0x400u) || !static_cast<SavePositionInterface*>(player)->getVehicle())) ||
            (LevelObject::s_type[target->getObjectType()]==5 && (!(static_cast<Character*>(target)->movementFlags&0x400u) || !static_cast<Character*>(target)->getVehicle())) ||
            (LevelObject::s_type[target->getObjectType()]==3 && !static_cast<Vehicle*>(target)->getDriver())) {
            flags356&=~0x2000u;
            Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(13),this));
        }
    }
    if(ScriptManager::getInstance()->isInCinematic() && !unknown28 && category428!=3 && (flags356&0x40u)) {
        flags356&=~0x40u;
        Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(13),this));
    }
    if(isOutsideSearchRadius()) {
        Weapon* current=getWeapon();
        if(current && current->getWeaponType()!=0) {
            int range=current->getRange()*2;
            int cone=current->getCone();
            if(!isTargetInRange(static_cast<float>(range),static_cast<float>(cone)))
                Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(26),this));
        }
    }
    if(ScriptManager::getInstance()->isInCinematic() && !(flags356&0x2800u))
        adjustedDestination=destination;
    else CheckDestination();
    Character::Update(elapsed);
    PlayerTest* player=PlayerTest::GetPlayer();
    if(!isDead()) {
        if(flags356&0x80u) _ZN3NPC7_detectEv(this);
        collisionBody->angularVelocity=0.0f;
        b2Body* body=collisionBody;
        body->linearVelocity.y=0.0f;
        body->linearVelocity.x=0.0f;
        if(_ZN9Character6isDownEv(this) && health>0) {
            UpdateCarPosIfUnderWheel();
            unknown448+=elapsed;
            if(isUnderCar()) {
                if(unknown448>999) {
                    int damage=static_cast<int>(static_cast<float>(getMaxHealth())*0.29999998211860657f);
                    applyDamage(damage,lastHitVehicle,true);
                    unknown448=0;
                }
            } else if(!isCurrentAnimation(164)) {
                lastHitVehicle=0;
                if(unknown448>2999) {
                    setAnimation(164,1.0f,false,false,false);
                    unknown448=0;
                }
            }
        }
    } else {
        if(collisionBody && isCurrentAnimation(-1)) {
            if(collisionBody->data) {
                ::operator delete(collisionBody->data);
                collisionBody->data=0;
            }
            PhysicAttributes::s_world->DestroyBody(collisionBody);
            collisionBody=0;
        }
        if(flags356&0x100000u) {
            tagForKill(false);
            ScriptManager::getInstance()->taggedKilled();
        }
    }
    if(currentAnimation!=-1 && unknown164Pointer) {
        if(_ZN9Character15updateAnimationEf(this,static_cast<float>(elapsed))) switchAnim();
        if(!(unknown4&2u)) return;
    }
    if(!unknown28 && isDead() && _ZN9Character6isDownEv(this)) {
        cleanTimer+=elapsed;
        int alpha=static_cast<int>(static_cast<float>(cleanTimer)/3000.0f*-255.0f+255.0f);
        alpha=irr::core::clamp(alpha,0,255);
        if(alpha<255) {
            GS3DStuff::SetMaterialType(sceneNode,static_cast<irr::video::E_MATERIAL_TYPE>(25));
            GS3DStuff::SetAlpha(sceneNode,static_cast<unsigned char>(alpha),GS3DStuff::Color0);
            if(alpha==0) {
                GS3DStuff::forceDespawn(this);
                return;
            }
        }
    }
    if(_ZN9Character6isDownEv(this)) {
        UpdateSceneNode();
        if(lastHitVehicle) unknown448=0;
        return;
    }
    if(unknown24->info->unknown0==PhysicAttributes::MATERIAL_TYPE_CLIFF) {
        b2Body* body=collisionBody;
        b2Vec2 slope(unknown24->info->vector48.X,unknown24->info->vector48.Y);
        b2Vec2 velocity=body->linearVelocity;
        body->linearVelocity=npcVecAdd(npcVecScale(5.0f,slope),velocity);
    }
    float y,x;
    {
        const irr::core::vector3d<float>& position=GetPosition();
        y=position.Y;
        x=position.X;
    }
    shadowBaseHeight=unknown24->GetHeight(GetPosition(),0,false);
    sceneNode->setPosition(irr::core::vector3d<float>(x,y,shadowBaseHeight+unknown156));
    sceneNode->updateAbsolutePosition(false);
    if(!isDead()) {
        NPCUpdateFields& fields=*reinterpret_cast<NPCUpdateFields*>(this);
        if(fields.avoidVehicle && fields.avoidVehicle->isEnabled()) {
            if(fields.avoidVehicle->explosionFlag || fields.avoidVehicle->explosionFinished) flags356|=2u;
            else if(!(movementFlags&0x10000u) && !(flags356&0x800u)) {
                float distance=(GetPosition()-fields.avoidVehicle->GetPosition()).getLengthSQ();
                if(distance>=2250000.0f || (target && target->GetSpeed()>30.0f))
                    goToVehicle(fields.avoidVehicle,true,true,true,false);
            }
        }
        if(unknown264 && (unknown264==reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player)) ||
            LevelObject::s_type[unknown264->getObjectType()]==1 || LevelObject::s_type[unknown264->getObjectType()]==5)) {
            if((static_cast<Character*>(unknown264)->movementFlags&0x10000000u) && static_cast<Character*>(unknown264)->target!=target)
                attackTarget(static_cast<Character*>(unknown264)->target);
            else {
                // No-code hints (both tests vanish after reload: crossjump merges the identical
                // arms and the dead test operands are deleted). The prefetch keeps PRED_CALL on
                // the edge into this block. The s_world test's PIC-register reload advances the
                // reload rotation so the player null-check reload takes r1 (which also gives the
                // SetTarget argument order); the elapsed test's reload, after the null check,
                // puts the getVehicle base reload back in r0.
                __builtin_prefetch(this);
                if(PhysicAttributes::s_world) SetTarget(0); else SetTarget(0);
                Character* pc=reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player));
                LevelObject* u;
                if(elapsed) u=unknown264; else u=unknown264;
                // Cast on the right-hand side gives retail's cmp operand order.
                if(pc==reinterpret_cast<Character*>(u)) {
                    // Branch hint (no code): the player-has-vehicle path is likely, so the
                    // getOutOfVehicle block is placed after the 0x2000 door stub.
                    if(__builtin_expect(static_cast<SavePrimaryInterface*>(player)->getVehicle()!=0,1)) {
                        if((player->flags240&0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle())
                            goToVehicle(static_cast<SavePrimaryInterface*>(player)->getVehicle(),false,true,true,false);
                    } else if(getVehicle() && !(unknown4&2u)) getOutOfVehicle(true,false);
                }
            }
        }
        if(flags356&0x800u) {
            Vehicle* previous=vehicle;
            if(previous) {
                vehicle=0;
                goToVehicle(previous,entryDoor==previous->leftDoor,(flags356&2u)!=0,true,false);
            } else flags356&=~0x800u;
        }
        if(flags356&0x2000u) {
            Vehicle* previous=vehicle;
            if(previous) {
                vehicle=0;
                goToVehicle(previous,entryDoor==previous->leftDoor,(flags356&2u)!=0,false,true);
            } else flags356&=~0x2000u;
        }
        if(!(flags356&0x400u)) {
            if((flags356&0x40u) && !(flags356&0x800u) && !(movementFlags&0x30000u) && !(flags356&0x2000u)) {
                if(!attackState452 && !_ZN9Character6isDownEv(this)) triggerCombatSFX(unknown412);
                _ZN3NPC12attackTargetEv(this);
            } else if((flags356&1u) || (flags356&2u)) {
                turnToward(irr::core::vector3d<float>(adjustedDestination));
                animationFlag149=true;
                // No-op write-backs (removed after reload) keep the destination loads as
                // separate pseudos, giving retail's dY reload into r5 and dx in r4.
                float dY=destination.Y;
                destination.Y=dY;
                float dX=destination.X;
                destination.X=dX;
                float dx=dX-x;
                float dy=dY-y;
                if(dx*dx+dy*dy<static_cast<float>(destinationLimitSquared)) {
                    flags356&=~3u;
                    // Contrived equality form: PRED_TREE_OPCODE_NONEQUAL joins PRED_CALL on the Stop edge.
                    unsigned int stopFlag=(flags356&0x400000u)^0x400000u;
                    if(stopFlag==0x400000u) Stop();
                    if(flags356&0x800u) {
                        if(vehicle && !vehicle->explosionFlag && !vehicle->explosionFinished) {
                            // Inverted arm order: the keep path precedes the door path in RTL,
                            // which gives retail's reload rotation for the 188-offset reloads.
                            if(!(vehicle->GetSpeed()<=10.0f)) {
                                if(vehicle) goto keep800;
                            } else {
                                // No-code hint: PRED_CALL makes the speed>10 path the fallthrough.
                                __builtin_prefetch(this);
                                if(vehicle) {
                                    irr::scene::ISceneNode* door=vehicle->getNearestDoorDummy(GetPosition());
                                    irr::core::vector3d<float> entryPosition(door->getAbsolutePosition().X,door->getAbsolutePosition().Y,GetPosition().Z);
                                    SetPosition(entryPosition);
                                    enterVehicle(door==vehicle->leftDoor,true,false);
                                }
                            }
                            // One shared clear for the door and vehicle-gone paths.
                            flags356&=~0x800u;
                            keep800:;
                        } else flags356&=~0x800u;
                    } else {
                    // No-code hint: PRED_CALL on this edge keeps the 0x800 path on the fallthrough.

                    if(flags356&0x2000u) {
                        if(vehicle) {
                            // Same inverted arm order as the 0x800 path.
                            if(!(vehicle->GetSpeed()<=10.0f)) {
                                if(vehicle) goto keep2000;
                            } else {
                                // No-code hint: PRED_CALL makes the speed>10 path the fallthrough.
                                __builtin_prefetch(this);
                                if(vehicle) {
                                    irr::scene::ISceneNode* door=vehicle->getNearestDoorDummy(GetPosition());
                                    irr::core::vector3d<float> entryPosition(door->getAbsolutePosition().X,door->getAbsolutePosition().Y,GetPosition().Z);
                                    SetPosition(entryPosition);
                                    enterVehicle(door==vehicle->leftDoor,false,true);
                                }
                            }
                        }
                        // One shared clear for the door, vehicle-gone and no-vehicle paths.
                        flags356&=~0x2000u;
                        keep2000:;
                    } else {
                        flags356|=0x4000u;
                        EvNPC event(static_cast<EvNPC::State>(1),this);
                        Application::GetInstance()->GetEventManager()->raise(event);
                        startTurn(8.0f);
                    }
                    }
                }
            } else if(flags356&8u) {
                b2Body* body=collisionBody;
                body->linearVelocity.y=0.0f;
                body->linearVelocity.x=0.0f;
                waitElapsed+=elapsed;
                if(waitElapsed/1000>waitDuration) {
                    Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(5),this));
                    flags356&=~8u;
                }
            } else if(flags356&16u) {
                b2Body* body=collisionBody;
                body->linearVelocity.y=0.0f;
                body->linearVelocity.x=0.0f;
            }
        }
        if((flags356&4u) && isCurrentAnimation(getSpecificAnimation(165))) {
            flags356|=0x8000u;
            goToNextPoint(false);
        }
    }
    UpdateSceneNode();
}
