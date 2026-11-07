/*
 * SpawnPoint
 *
 * Original file: SpawnPoint.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SpawnPoint.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_spawnpoint_transitions {
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


#include "SpawnPoint.h"
#include "GameObjectManager.h"
#include "LevelObject.h"
#include "../ai/AIManagerSingleton.h"
#include "../ai/NPC.h"
#include "../characters/PhysicAttributes.h"
#include "../characters/PlayerTest.h"
#include "../core/MemHint.h"
#include "../core/Randomizer.h"
#include "../vehicles/Vehicle.h"

// The vehicle's spawn node is observed at offset 672 in the retail layout.
struct VehicleSpawnNodeView {
    unsigned char prefix[672];
    irr::scene::ISceneNode* node;
};

SpawnPoint::SpawnConstants SpawnPoint::s_carSpawnCst =
    {3, 3, 500, 1000, 2000, 4000, 6250000, 3039, 32397042, 3900};
SpawnPoint::SpawnConstants SpawnPoint::s_civSpawnCst =
    {5, 3, 1000, 2000, 5000, 8000, 4000000, 1000, 9000000, 1700};
SpawnPoint::SpawnConstants SpawnPoint::s_prisonerSpawnCst =
    {16, 5, 1000, 2000, 5000, 8000, 4000000, 1000, 9000000, 1700};
SpawnPoint::SpawnConstants SpawnPoint::s_parkedCarSpawnCst =
    {11, 2, 500, 1000, 2000, 4000, 6250000, 1500, 10240000, 3000};

SpawnPoint::Center SpawnPoint::s_innerCenterCiv;
SpawnPoint::Center SpawnPoint::s_outterCenterCiv;
SpawnPoint::Center SpawnPoint::s_innerCenterCar;
SpawnPoint::Center SpawnPoint::s_outterCenterCar;
SpawnPoint::Center SpawnPoint::s_innerCenterParkedCar;
SpawnPoint::Center SpawnPoint::s_outterCenterParkedCar;

SpawnPointList SpawnPoint::s_spawnPoints;
LevelObject* SpawnPoint::s_spawnPool[SpawnPoolSize];
unsigned char SpawnPoint::s_spawnedCops;
unsigned char** SpawnPoint::s_spawnMetatypes;
unsigned char* SpawnPoint::s_metatypesCount;
const SpawnPoint::SpawnConstants** SpawnPoint::s_metatypesSpawnCst;

void SpawnPoint::add(SpawnPoint* point)
{
    SpawnPointList::Node* node = new (irr::DefaultMemHint) SpawnPointList::Node;
    node->next = 0;
    node->previous = 0;
    node->value = point;
    ++s_spawnPoints.count;
    if (!s_spawnPoints.head)
        s_spawnPoints.head = node;
    node->previous = s_spawnPoints.tail;
    if (s_spawnPoints.tail)
        s_spawnPoints.tail->next = node;
    s_spawnPoints.tail = node;
}

SpawnPoint::~SpawnPoint() {}

void __attribute__((weak)) SpawnPoint::SetRotation(const irr::core::vector3d<float>& degrees)
{
    const float radiansPerDegree = 0.0174532925f;
    const irr::core::quaternion radians(degrees * radiansPerDegree);
    rotation.X = radians.X;
    rotation.Y = radians.Y;
    rotation.Z = radians.Z;
    rotation.W = radians.W;
}

void SpawnPoint::resetSpawnTime(int minimum, int maximum)
{
    int range = maximum - minimum;
    spawnTime = minimum + irr::os::Randomizer::rand() % range;
}

static inline const SpawnPoint::Center& selectSpawnCenter(int type,
    const SpawnPoint::Center& car, const SpawnPoint::Center& parkedCar,
    const SpawnPoint::Center& civilian)
{
    if (type == 3)
        return car;
    if (type == 11)
        return parkedCar;
    return civilian;
}

const SpawnPoint::Center& SpawnPoint::GetOutterSpawnCenter() const
{
    return selectSpawnCenter(s_metatypesSpawnCst[spawnGroup]->type,
        s_outterCenterCar, s_outterCenterParkedCar, s_outterCenterCiv);
}

const SpawnPoint::Center& SpawnPoint::GetInnerSpawnCenter() const
{
    return selectSpawnCenter(s_metatypesSpawnCst[spawnGroup]->type,
        s_innerCenterCar, s_innerCenterParkedCar, s_innerCenterCiv);
}

static inline __attribute__((always_inline)) bool isCopMetatype(LevelObject* object)
{
    return object->GetMetatype() == 48 || object->GetMetatype() == 161 || object->GetMetatype() == 38;
}

void SpawnPoint::releaseSpawnObject(LevelObject* object)
{
    GameObjectManager::s_gom->RemoveGameObjectOfType(object->getSpawnType());
    for (int i = 0; i < SpawnPoolSize; ++i) {
        if (!s_spawnPool[i]) {
            s_spawnPool[i] = object;
            if (isCopMetatype(object) && s_spawnedCops)
                --s_spawnedCops;
            return;
        }
    }
}

LevelObject* SpawnPoint::getSpawnObject(int metatype)
{
    GameObjectManager* manager = GameObjectManager::s_gom;
    for (int i = 0; i < SpawnPoolSize; ++i) {
        if (s_spawnPool[i] && s_spawnPool[i]->GetMetatype() == metatype) {
            LevelObject* object = s_spawnPool[i];
            s_spawnPool[i] = 0;
            if (isCopMetatype(object))
                ++s_spawnedCops;
            if (object)
                manager->Add(object, object->unknown40);
            return object;
        }
    }
    return 0;
}

void SpawnPoint::spawn()
{
    GameObjectManager* manager = GameObjectManager::s_gom;
    int random = irr::os::Randomizer::rand();
    int metatype = s_spawnMetatypes[spawnGroup][random % s_metatypesCount[spawnGroup]];
    int spawnedCops = s_spawnedCops;
    if (spawnedCops < WantedLevelManager::getInstance()->unknown8) {
        if (random & 1) {
            PlayerTest* player = PlayerTest::GetPlayer();
            int type = s_metatypesSpawnCst[spawnGroup]->type;
            if (type == 5)
                metatype = player->contextWord == 0 ? 48 : 161;
            else if (type == 3)
                metatype = 38;
        }
    } else if (metatype == 48 || metatype == 38 || metatype == 161) {
        return;
    }

    LevelObject* object = getSpawnObject(metatype);
    if (!object)
        return;

    manager->AddGameObjectOfType(s_metatypesSpawnCst[spawnGroup]->type);
    object->setSpawnType(s_metatypesSpawnCst[spawnGroup]->type);
    object->OnSpawn();
    const irr::core::quaternion orientation = rotation;
    object->SetRotation(orientation);
    irr::core::vector3d<float> spawnPosition = position;
    object->SetPosition(spawnPosition);
    object->getPhysicAttributes()->Init(materialId, triangleId, object->GetPosition());
    spawnPosition.Z = object->getPhysicAttributes()->GetHeight(spawnPosition, 0, false);
    object->SetPosition(spawnPosition);

    int type = LevelObject::s_type[object->getObjectType()];
    if (type == 3) {
        Vehicle* vehicle = static_cast<Vehicle*>(object);
        VehicleSpawnNodeView* visual = reinterpret_cast<VehicleSpawnNodeView*>(vehicle);
        visual->node->setRotation(orientation);
        visual->node->setPosition(vehicle->GetPosition());
        if (s_metatypesSpawnCst[spawnGroup]->type != 11) {
            vehicle->setSpeed();
            AIManager::getInstance()->addAI(vehicle, static_cast<gameloft::ai::StateID>(0));
        }
    } else if (type == 5) {
        AIManager::getInstance()->addAI(static_cast<NPC*>(object), static_cast<gameloft::ai::StateID>(0));
    }
    object->GetMetatype();
    delete[] object->unknown28;
    object->unknown28 = 0;
}

LevelObject* SpawnPoint::spawn(int metatype)
{
    PlayerTest* player = PlayerTest::GetPlayer();
    const irr::core::vector3d<float> origin = player->position();
    const irr::core::quaternion orientation = player->GetRotation();
    const unsigned short material = player->GetMatID();
    const unsigned short triangle = player->GetTriID();
    irr::core::vector3d<float> position(origin);
    GameObjectManager* manager = GameObjectManager::s_gom;
    LevelObject* object = getSpawnObject(metatype);
    if (object) {
        manager->AddGameObjectOfType(LevelObject::s_type[object->getObjectType()]);
        object->setSpawnType(LevelObject::s_type[object->getObjectType()]);
        object->OnSpawn();
        object->SetRotation(orientation);
        object->SetPosition(position);
        object->getPhysicAttributes()->Init(material, triangle, object->GetPosition());
        position.Z = object->getPhysicAttributes()->GetHeight(position, 0, false);
        object->SetPosition(position);
        object->GetMetatype();
        delete[] object->unknown28;
        object->unknown28 = 0;
    }
    return object;
}

void SpawnPoint::ClearAllSpawnInstances()
{
    for (LevelObject** slot = s_spawnPool; slot != s_spawnPool + SpawnPoolSize; ++slot) {
        delete *slot;
        *slot = 0;
    }
    if (s_spawnMetatypes) {
        for (int i = 0; i < SpawnPoolSize; ++i) {
            unsigned char*& entry = s_spawnMetatypes[i];
            delete[] entry;
            entry = 0;
        }
        delete[] s_spawnMetatypes;
    }
    s_spawnMetatypes = 0;
    delete[] s_metatypesCount;
    s_metatypesCount = 0;
    delete[] s_metatypesSpawnCst;
    s_metatypesSpawnCst = 0;
}

SpawnPoint::SpawnPoint(int) : materialId(0) {}

void SpawnPoint::Update(int elapsed)
{
    if (spawnTime > 0) {
        spawnTime -= elapsed;
        return;
    }

    int minimum;
    int maximum;
    if (!canSpawn()) {
        const SpawnConstants& constants = *s_metatypesSpawnCst[spawnGroup];
        minimum = constants.retryMin;
        maximum = constants.retryMax;
    } else {
        spawn();
        const SpawnConstants& constants = *s_metatypesSpawnCst[spawnGroup];
        minimum = constants.respawnMin;
        maximum = constants.respawnMax;
    }
    resetSpawnTime(minimum, maximum);
}

extern "C" {
static void __tcf_6() __attribute__((used));
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_spawnpoint_transitions::scripted_vehicle_trans, 21);
        SpawnPoint::s_innerCenterCiv.x = 0.0f;
        SpawnPoint::s_innerCenterCiv.y = 0.0f;
        SpawnPoint::s_innerCenterCiv.z = 0.0f;
        SpawnPoint::s_outterCenterCiv.x = 0.0f;
        SpawnPoint::s_outterCenterCiv.y = 0.0f;
        SpawnPoint::s_outterCenterCiv.z = 0.0f;
        SpawnPoint::s_innerCenterCar.x = 0.0f;
        SpawnPoint::s_innerCenterCar.y = 0.0f;
        SpawnPoint::s_innerCenterCar.z = 0.0f;
        SpawnPoint::s_outterCenterCar.x = 0.0f;
        SpawnPoint::s_outterCenterCar.y = 0.0f;
        SpawnPoint::s_outterCenterCar.z = 0.0f;
        SpawnPoint::s_innerCenterParkedCar.x = 0.0f;
        SpawnPoint::s_innerCenterParkedCar.y = 0.0f;
        SpawnPoint::s_innerCenterParkedCar.z = 0.0f;
        SpawnPoint::s_outterCenterParkedCar.x = 0.0f;
        SpawnPoint::s_outterCenterParkedCar.y = 0.0f;
        SpawnPoint::s_outterCenterParkedCar.z = 0.0f;
        SpawnPoint::s_spawnPoints.head = 0;
        SpawnPoint::s_spawnPoints.tail = 0;
        SpawnPoint::s_spawnPoints.count = 0;
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_6), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN10SpawnPoint16s_innerCenterCivE() __attribute__((used));
static void _GLOBAL__I__ZN10SpawnPoint16s_innerCenterCivE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_5()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

extern "C" {
static void __tcf_6()
{
    while (SpawnPoint::s_spawnPoints.head) {
        SpawnPointList::Node* node = SpawnPoint::s_spawnPoints.head;
        SpawnPointList::Node* next = node->next;
        ::operator delete(node);
        SpawnPoint::s_spawnPoints.head = next;
    }
    SpawnPoint::s_spawnPoints.tail = 0;
    SpawnPoint::s_spawnPoints.count = 0;
}
}
