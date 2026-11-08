/*
 * PhysicAttributes
 *
 * Original file: PhysicAttributes.cpp
 * Area:          characters
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of PhysicAttributes.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "PhysicAttributes.h"
#include "../core/Physics.h"
#include "../core/SafeDelete.h"
#include "../core/SceneNode.h"

// Emit the inline destructors while the key virtual methods remain retail imports.
class ContactListener : public b2ContactListener {
public:
    virtual ~ContactListener() __attribute__((used)) {}
    virtual void Add(const b2ContactPoint* point);
    virtual void Persist(const b2ContactPoint* point);
    virtual void Remove(const b2ContactPoint* point);
    virtual void Result(const b2ContactResult* result);
};

class ContactFilter : public b2ContactFilter {
public:
    virtual ~ContactFilter() __attribute__((used)) {}
    virtual bool ShouldCollide(b2Shape* first, b2Shape* second);
};

void ContactListener::Result(const b2ContactResult*)
{
}

struct PhysicInfo {
    PhysicInfo() __attribute__((weak));
    // The retail array allocation has an ARM EABI cookie.
    ~PhysicInfo() {}
    void Reset(b2World* world) __attribute__((weak));

    unsigned short unknown0;
    unsigned char unknown2[2];
    unsigned int unknown4;
    unsigned short unknown8;
    unsigned char unknown10[2];
    irr::core::vector3d<float> vector12, vector24, vector36, vector48;
    bool unknown60;
    unsigned char unknown61[3];
    irr::core::vector3d<float> unknown64;
    unsigned short unknown76, unknown78, unknown80;
    unsigned char unknown82[6];
    b2Body* bodies[12];
    bool onGround;
    bool wasOnGround;
    unsigned char unknown138[2];
};

void PhysicAttributes::SetIsOnGround(int slot, bool value)
{
    info[slot].wasOnGround = info[slot].onGround;
    info[slot].onGround = value;
}

void PhysicAttributes::ResetPhysicInfo()
{
    for (int i = 0; i < infoCount; ++i) {
        info[i].Reset(s_world);
        info[i].onGround = i == 0;
        info[i].wasOnGround = i == 0;
    }
}

PhysicInfo::PhysicInfo()
{
    unknown64.Z = 999999.0f;
    for (int i = 0; i < 12; ++i)
        bodies[i] = 0;
    Reset(0);
}

template void SafeDelete<b2World>(b2World*&);

void PhysicAttributes::CleanWorld()
{
    delete s_contactListener;
    s_contactListener = 0;
    delete s_contactFilter;
    s_contactFilter = 0;
    if (s_world && s_groundBody)
        s_world->DestroyBody(s_groundBody);
    if (s_world)
        SafeDelete(s_world);
    delete[] s_PoolID;
    s_PoolID = 0;
}

irr::scene::ISceneNode* PhysicAttributes::GetSceneNodeFromID(irr::scene::ISceneNode* node, int id)
{
    irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
    if (node->getID() == id)
        return node;
    for (; child != node->getChildren().end(); child = child->next) {
        irr::scene::ISceneNode* found = GetSceneNodeFromID(child->value, id);
        if (found)
            return found;
    }
    return 0;
}

void PhysicAttributes::SetPhysicInfo(const PhysicInfo& source, int slot)
{
    info[slot].vector12 = source.vector12;
    info[slot].vector24 = source.vector24;
    info[slot].vector36 = source.vector36;
    info[slot].unknown4 = source.unknown4;
    info[slot].unknown0 = source.unknown0;
    info[slot].unknown8 = source.unknown8;
    info[slot].vector48 = source.vector48;
    info[slot].unknown60 = true;
    info[slot].unknown64 = source.unknown64;
    UpdateEdgesCollisions(slot);
}

float PhysicAttributes::GetHeightFrom(int source, const irr::core::vector3d<float>& position, int slot)
{
    if (info[source].unknown4) {
        info[slot].unknown0 = info[source].unknown0;
        info[slot].unknown4 = info[source].unknown4;
        info[slot].unknown8 = info[source].unknown8;
        info[slot].vector12 = info[source].vector12;
        info[slot].vector24 = info[source].vector24;
        info[slot].vector36 = info[source].vector36;
        info[slot].unknown76 = info[source].unknown76;
        info[slot].unknown78 = info[source].unknown78;
        info[slot].unknown80 = info[source].unknown80;
        info[slot].unknown64 = info[source].unknown64;
    }
    return GetHeight(position, slot, true);
}

void operator delete(void*) throw();

PhysicAttributes::~PhysicAttributes()
{
    if (index >= 0) {
        s_PoolID[index] = false;
        for (int i = 0; i < infoCount; ++i) {
            for (int j = 0; j < 12; ++j) {
                if (info[i].bodies[j]) {
                    if (info[i].bodies[j]->GetUserData()) {
                        delete static_cast<PhysicsBodyData*>(info[i].bodies[j]->GetUserData());
                        info[i].bodies[j]->data = 0;
                    }
                    s_world->DestroyBody(info[i].bodies[j]);
                    info[i].bodies[j] = 0;
                }
            }
        }
        delete[] info;
    }
    if (ownedArray.free_when_destroyed)
        ::operator delete(ownedArray.data);
}

extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_physicattributes_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_physicattributes_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN16PhysicAttributes11s_neighborsE() __attribute__((used));
static void _GLOBAL__I__ZN16PhysicAttributes11s_neighborsE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
