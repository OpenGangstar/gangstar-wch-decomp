/*
 * Item
 *
 * Original file: Item.cpp
 * Area:          meta
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Item.cpp here, in the order they appear in the library.
 */

#include "../core/LocalStartupText.h"
#include "Item.h"
#include "Achievements.h"
#include "ItemScalarMath.h"
#include "../world/SceneNodeManager.h"
#include "../world/GameObjectManager.h"
#include "../scripting/ScriptManager.h"
#include "../missions/WantedLevelManager.h"
#include "../world/ObjectData.h"
#include "../app/CGameFactory.h"
#include "../app/Application.h"
#include "../combat/WeaponManager.h"
#include "../combat/Weapon.h"
#include "../hud/CHudManager.h"
#include "../audio/SoundManager.h"
#include "../core/CameraManager.h"
#include "../rendering/GameBillboardFactory.h"
#include "../core/Array.h"
#include "../core/Vector3.h"
#include "../core/LocalStartupStorage.h"

int Item::s_numHealthCrate;
int Item::s_numArmorVest;
irr::core::array<Item*, irr::core::irrAllocator<Item*> > Item::s_placedItems;

// The startup helper constructs the factory in one aligned word. Item.ld gives
// the original object name a typed view of this same storage, without extra data.
static unsigned int s_billboardFactoryStorage[1];
extern CGameBillboardFactory s_billboardFactory __attribute__((visibility("hidden")));

// Retail storage for the header-defined WantedLevelManager singleton.
extern WantedLevelManager _ZZN18WantedLevelManager11getInstanceEvE3wlm;

void operator delete(void*) throw();
extern "C" {
static void __tcf_2(void*) __attribute__((used));
static void __tcf_2(void*)
{
    _ZZN18WantedLevelManager11getInstanceEvE3wlm.WantedLevelManager::~WantedLevelManager();
}
static void __tcf_4(void*) __attribute__((used));
static void __tcf_4(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
static void __tcf_5(void*) __attribute__((used));
static void __tcf_5(void*)
{
    reinterpret_cast<CGameBillboardFactory*>(s_billboardFactoryStorage)->CGameBillboardFactory::~CGameBillboardFactory();
}
static void __tcf_6(void*) __attribute__((used));
static void __tcf_6(void*)
{
    if (Item::s_placedItems.free_when_destroyed)
        ::operator delete(Item::s_placedItems.data);
}
}

void Item::resetAchievementCounters()
{
    s_numHealthCrate = 0;
    s_numArmorVest = 0;
}

void Item::debug(irr::video::IVideoDriver*)
{
}

void Item::unlock()
{
    unknown96 = unknown92;
}

bool Item::unlocked() const
{
    return unknown96 >= unknown92;
}

int Item::getId() const
{
    return id;
}

void Item::SetPosition(const irr::core::vector3d<float>& value)
{
    LevelObject::SetPosition(value);
    Transformation::SetPosition(value);
}

void Item::WarmUp()
{
    LevelObject::WarmUp();
    if (s_nodePoolID[getObjectType()] != 0xff)
        SceneNodeManager::getInstance()->manage(s_nodePoolID[getObjectType()], this, 2);
}

namespace ItemNodeNames {
static const char collectibleGlow[] __attribute__((section(".rodata.item_collectible_glow"))) = "collectible_glow_dummy-node";
static const char badgeGlow[] __attribute__((section(".rodata.item_badge_glow"))) = "badge_glow_dummy-node";
static const char badgeScene[] __attribute__((section(".rodata.item_badge_scene"))) = "./badge_glow.bdae";
static const char collectibleScene[] __attribute__((section(".rodata.item_collectible_scene"))) = "./collectible_glow.bdae";
}
struct ItemSceneParameters {
    irr::scene::ISceneNode* node;
    int pool;
};

void Item::setupSceneNode(int id, irr::scene::ISceneNode* node, int count, void** parameters)
{
    LevelObject::setupSceneNode(id, node, count, parameters);
    ItemSceneParameters& values = *reinterpret_cast<ItemSceneParameters*>(parameters);
    values.node = node->getSceneNodeFromUID(ItemNodeNames::collectibleGlow);
    if (values.node) {
        values.pool = SceneNodeManager::getInstance()->findOrCreatePool(
            ItemNodeNames::collectibleScene, s_nodePoolMinimumSize[getObjectType()] * 2,
            &s_billboardFactory);
    } else {
        values.node = node->getSceneNodeFromUID(ItemNodeNames::badgeGlow);
        values.pool = SceneNodeManager::getInstance()->findOrCreatePool(
            ItemNodeNames::badgeScene, s_nodePoolMinimumSize[getObjectType()],
            &s_billboardFactory);
    }
}

void Item::dropSceneNode()
{
    Transformation::dropSceneNode();
    attachedNode = 0;
    SceneNodeManager::getInstance()->drop(billboardPool,
        reinterpret_cast<const irr::scene::ISceneNode*>(
            static_cast<const irr::collada::CSceneNode*>(billboard)));
    billboard = 0;
}

Item::~Item()
{
}

Item::Item(int type) : Transformation(type)
{
    billboard = 0;
    itemType = -1;
    unknown92 = 0;
    unknown96 = static_cast<unsigned int>(-1);
    attachedNode = 0;
    unknown104 = 0;
    billboardPool = -1;
    id = -1;
}

void Item::removeAllPlacedItems()
{
    for (int i = 0; i < s_placedItems.used; ++i)
        GameObjectManager::s_gom->RemoveAndDestroy(s_placedItems.data[i]);
    ::operator delete(s_placedItems.data);
    s_placedItems.data = 0;
    s_placedItems.used = 0;
    s_placedItems.allocated = 0;
    s_placedItems.is_sorted = true;
}

int Item::isUsable()
{
    int value = 0;
    switch (itemType) {
    case 1: {
        PlayerTest* player = PlayerTest::GetPlayer();
        value = player->contextValues[*reinterpret_cast<const int*>(&player->context)] < 200;
        break;
    }
    case 2:
        value = PlayerTest::GetPlayer()->getHealth() < PlayerTest::GetPlayer()->getMaxHealth();
        break;
    case 3: {
        int wanted = WantedLevelManager::getInstance()->unknown8;
        // The retail code lays out the nonzero path as the fallthrough.
        if (__builtin_expect(wanted != 0, 1))
            wanted = 1;
        value = wanted;
        break;
    }
    case 0: case 4: case 5: case 6: case 7: case 8: case 9:
        value = 1;
        break;
    }
    return value;
}

void Item::hide()
{
    dropSceneNode();
    unknown4 &= ~2u;
    if (unknown44 != -1 && itemType != 3)
        ScriptManager::displayOnMinimap(this, false, true);
    objectList->Remove(this);
    GameObjectManager::s_gom->Add(this, 1);
}

void Item::show()
{
    grabSceneNode(0, 0);
    unknown4 |= 2;
    reinterpret_cast<irr::scene::ISceneNode&>(
        static_cast<irr::collada::CSceneNode&>(*billboard)).setVisible(true);
    if (unknown44 != -1 && itemType != 3)
        ScriptManager::displayOnMinimap(this, true, true);
    objectList->Remove(this);
    GameObjectManager::s_gom->Add(this, 0);
}

void Item::place(int type, irr::core::vector3d<float> position)
{
    int metatype;
    switch (type) {
    case 0: metatype = 16; break;
    case 1: metatype = 6; break;
    case 2: metatype = 69; break;
    case 3: metatype = 114; break;
    case 4: metatype = 9; break;
    case 5: metatype = 1; break;
    case 6: metatype = 129; break;
    case 7: metatype = 156; break;
    case 8: metatype = 124; break;
    case 9: metatype = 131; break;
    default: return;
    }
    Item* item = static_cast<Item*>(GameObjectManager::s_gom->CreateGameObjectFromMetatype(metatype));
    GameObjectManager::s_gom->AddGameObjectOfType(s_type[item->getObjectType()]);
    item->SetPosition(position);
    item->unknown4 |= 1;
    GameObjectManager::s_gom->Add(item, 1);
    item->unlock();
    s_placedItems.push_back(item);
}

void Item::lock()
{
    if (unknown4 & 0x100) {
        dropSceneNode();
        GameObjectManager::s_gom->RemoveAndDestroy(this);
    } else {
        if (unknown4 & 2)
            hide();
        unknown96 = 0;
    }
}

void Item::Load(const Structs::Item& data)
{
    Transformation::Load(data, CGameFactory::getInstance());
    itemType = data.unknown80;
    unknown92 = data.unknown88;
    unknown104 = data.unknown84;
    if (itemType == 3 && WantedLevelManager::getInstance()->unknown8 == 0) {
        lock();
        unknown96 = unknown92 - 1;
    } else {
        unlock();
    }
    delete[] unknown28;
    unknown28 = 0;
    switch (itemType) {
    case 1: id = s_numArmorVest++; break;
    case 2: id = s_numHealthCrate++; break;
    }
}

void Item::Update(int elapsed)
{
    LevelObject::Update(elapsed);
    if (unlocked()) {
        if (itemType == 3 && WantedLevelManager::getInstance()->unknown8 == 0) {
            lock();
            unknown96 = unknown92 - 1;
            return;
        }
        float distanceSquared = GetPosition().getDistanceFromSQ(
            CameraManager::getInstance()->getCamera()->getPosition());
        if (unknown4 & 2) {
            if (distanceSquared > 25000000.0f)
                hide();
        } else if (distanceSquared <= 25000000.0f) {
            show();
        }
    } else if (itemType != 3 || WantedLevelManager::getInstance()->unknown8 != 0) {
        unknown96 += elapsed;
        if (unknown96 >= unknown92)
            unlock();
    }
}

void Item::drop(int type, irr::core::vector3d<float> position, int amount)
{
    switch (type) {
    case 42: type = 156; break;
    case 155: type = 156; break;
    case 0: type = 1; break;
    case 8: type = 9; break;
    case 41: type = 9; break;
    case 123: type = 124; break;
    case 128: type = 129; break;
    case 130: type = 131; break;
    }
    Item* item = static_cast<Item*>(GameObjectManager::s_gom->CreateGameObjectFromMetatype(type));
    GameObjectManager::s_gom->AddGameObjectOfType(s_type[item->getObjectType()]);
    item->SetPosition(position);
    if (amount)
        item->unknown104 = amount;
    item->unknown4 |= 0x101;
    GameObjectManager::s_gom->Add(item, 1);
    item->unlock();
    item->OnSpawn();
}

void Item::addAmmo(int type, int amount)
{
    WeaponManager* manager = Application::GetInstance()->GetWeaponManager();
    manager->setAmmo(type, manager->getAmmo(type, PlayerTest::AnyContext) + amount,
        PlayerTest::AnyContext);
}

void Item::addWeapon(int type)
{
    WeaponManager* manager = Application::GetInstance()->GetWeaponManager();
    Weapon* weapon = manager->getWeaponInList(type, PlayerTest::AnyContext);
    if (!weapon->isLocked()) {
        Weapon* secondary = 0;
        switch (type) {
        case 1: secondary = manager->getWeaponInList(2, PlayerTest::AnyContext); break;
        case 5: secondary = manager->getWeaponInList(6, PlayerTest::AnyContext); break;
        default: break;
        }
        if (secondary && secondary->isLocked()) {
            secondary->unlock();
            if (manager->getWeaponLimitedTo(PlayerTest::AnyContext) == -1 &&
                (manager->getCurrentWeapon()->getWeaponType() < weapon->getWeaponType() ||
                 manager->getCurrentWeapon()->getWeaponType() == 9))
                Application::GetInstance()->GetHudManager()->switchWeapon(secondary->getWeaponType());
        }
    } else {
        weapon->unlock();
        if (manager->getWeaponLimitedTo(PlayerTest::AnyContext) == -1 &&
                (manager->getCurrentWeapon()->getWeaponType() < weapon->getWeaponType() ||
                 manager->getCurrentWeapon()->getWeaponType() == 9))
            Application::GetInstance()->GetHudManager()->switchWeapon(weapon->getWeaponType());
    }
}


void Item::animate(bool start, bool loop, bool)
{
    irr::scene::ISceneNode* node = sceneNode;
    if (start && node) {
        const irr::scene::SceneAnimatorList& animators = node->getAnimators();
        if (animators.getSize()) {
            irr::scene::ITimelineController* controller = (*animators.begin())->getTimelineCtrl();
            if (controller) {
                controller->setLoop(loop);
                controller->jumpTo(controller->startTime);
            }
        }
    }
}

void Item::add()
{
    switch (itemType) {
    case 0:
        PlayerTest::GetPlayer()->addCash(unknown104, 3000);
        AchievementManager::s_achievementManager->recordDroppedCash(unknown104);
        break;
    case 1: {
        PlayerTest* player = PlayerTest::GetPlayer();
        player->addContextArmor(unknown104);
        AchievementManager::s_achievementManager->recordArmor(*this);
        break;
    }
    case 2: {
        PlayerTest* player = PlayerTest::GetPlayer();
        player->health += unknown104;
        if (player->health > player->maximumHealth)
            player->health = player->maximumHealth;
        AchievementManager::s_achievementManager->recordHealthPack(*this);
        break;
    }
    case 3: {
        WantedLevelManager* manager = WantedLevelManager::getInstance();
        int wanted = WantedLevelManager::getInstance()->unknown8 - unknown104;
        wanted = irr::core::clamp(wanted, 0, 5);
        manager->unknown8 = wanted;
        manager->_processWantedLevel();
        AchievementManager::s_achievementManager->recordBadgesEscaped(unknown104);
        break;
    }
    case 4: addWeapon(1); addAmmo(0, unknown104); break;
    case 5: addWeapon(3); addAmmo(1, unknown104); break;
    case 6: addWeapon(4); addAmmo(2, unknown104); break;
    case 7: addWeapon(5); addAmmo(3, unknown104); break;
    case 8: addWeapon(7); addAmmo(4, unknown104); break;
    case 9: addWeapon(8); addAmmo(5, unknown104); break;
    }
}


irr::scene::ISceneNode* Item::grabSceneNode(int, void***)
{
    void** parameters = 0;
    Transformation::grabSceneNode(2, &parameters);
    irr::scene::ISceneNode* root = sceneNode;
    ItemSceneParameters& values = *reinterpret_cast<ItemSceneParameters*>(parameters);
    billboardPool = values.pool;
    attachedNode = values.node;
    billboard = static_cast<CustomBillboardSceneNode*>(
        static_cast<irr::collada::CSceneNode*>(
            SceneNodeManager::getInstance()->grab(billboardPool, 0, 0, 0)));
    animate(true, true, true);
    billboard->setScale(attachedNode->getScale());
    billboard->setPosition(root->getPosition() + attachedNode->getPosition());
    billboard->updateAbsolutePosition(false);
    return root;
}

void Item::playPickupSound()
{
    switch (itemType) {
    case 0: {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(147, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        break;
    }
    case 1: {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(150, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        break;
    }
    case 2: {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(130, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        break;
    }
    case 3: {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(156, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        break;
    }
    case 4: case 5: case 6: case 7: case 8: case 9: {
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(143, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        break;
    }
    }
}

void Item::pickup()
{
    if (unlocked() && isUsable()) {
        add();
        playPickupSound();
        lock();
    }
}

namespace retail_item_transitions {
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
        __aeabi_atexit(0, __tcf_4, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_item_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_item_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_item_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_item_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_item_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_item_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_item_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_item_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_item_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_item_transitions::scripted_vehicle_trans, 21);
        new (s_billboardFactoryStorage) CGameBillboardFactory;
        __aeabi_atexit(0, __tcf_5, &__dso_handle);
        Item::s_placedItems.data = 0;
        Item::s_placedItems.allocated = 0;
        Item::s_placedItems.used = 0;
        Item::s_placedItems.free_when_destroyed = true;
        Item::s_placedItems.is_sorted = true;
        Item::s_placedItems.unknown16 = 1;
        __aeabi_atexit(0, __tcf_6, &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN4Item16s_numHealthCrateE() __attribute__((used));
static void _GLOBAL__I__ZN4Item16s_numHealthCrateE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
