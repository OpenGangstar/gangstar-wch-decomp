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
#include "../core/PhysicsBodyDef.h"
#include "../core/SafeDelete.h"
#include "../core/SceneNode.h"
#include "../core/MeshBufferInterfaces.h"
#include "../core/MeshSceneInterfaces.h"
#include "../vehicles/Vehicle.h"

// Observed prefix of the Box2D contact record.
struct b2ContactPoint {
    b2Shape* shape1;
    b2Shape* shape2;
    b2Vec2 position;
    b2Vec2 velocity;
    b2Vec2 normal;
};

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

void ContactListener::Remove(const b2ContactPoint* point)
{
    b2Shape* first = point->shape1;
    const PhysicsBodyData* firstData = static_cast<const PhysicsBodyData*>(first->GetBody()->GetUserData());
    LevelObject* firstOwner = firstData ? firstData->owner : 0;
    b2Shape* second = point->shape2;
    const PhysicsBodyData* secondData = static_cast<const PhysicsBodyData*>(second->GetBody()->GetUserData());
    LevelObject* secondOwner = secondData ? secondData->owner : 0;

    if ((firstOwner && LevelObject::s_type[firstOwner->getObjectType()] == 12)
        || (secondOwner && LevelObject::s_type[secondOwner->getObjectType()] == 12))
        return;

    if (first->IsSensor()) {
        if (!second->IsSensor() && firstOwner)
            --static_cast<Vehicle*>(firstOwner)->sensorContactCount;
    } else if (second->IsSensor() && secondOwner) {
        --static_cast<Vehicle*>(secondOwner)->sensorContactCount;
    }
}

void ContactListener::Result(const b2ContactResult*)
{
}

#include "../ai/NPC.h"
extern "C" bool _ZNK3irr4core8vector3dIfE6equalsERKS2_f(
    const irr::core::vector3d<float>* self, const irr::core::vector3d<float>& other, float tolerance) __attribute__((weak));
// Character::destination (+92) is private; read it through a file-local view.
struct CharacterDestinationView {
    unsigned char unknown0[92];
    irr::core::vector3d<float> destination;
};
static inline bool IsCategory(unsigned int category, unsigned int value)
{
    return category == value;
}
static inline bool IsMoving(unsigned int category)
{
    if (category == 0) return true;
    if (category == 1) return true;
    return category == 2;
}

void ContactListener::Persist(const b2ContactPoint* point)
{
    const PhysicsBodyData* firstData = static_cast<const PhysicsBodyData*>(point->shape1->GetBody()->GetUserData());
    LevelObject* first = firstData ? firstData->owner : 0;
    const PhysicsBodyData* secondData = static_cast<const PhysicsBodyData*>(point->shape2->GetBody()->GetUserData());
    LevelObject* second = secondData ? secondData->owner : 0;
    if (!second) {
        if (first) {
        if (LevelObject::s_type[first->getObjectType()] == 5) {
            NPC* npc = static_cast<NPC*>(first);
            if ((IsMoving(npc->category428)) && !npc->getPathToFollow()) {
                if (!_ZNK3irr4core8vector3dIfE6equalsERKS2_f(&npc->unknown296, irr::core::vector3d<float>(0.0f, 0.0f, 0.0f), 0.000001f)) {
                    npc->unknown296 += irr::core::vector3d<float>(point->normal.x, point->normal.y, 0.0f);
                    npc->setDestination(first->GetPosition() + npc->unknown296 * 500.0f, 100);
                    if (npc->flags356 & 4) {
                        npc->Character::runToLocation(irr::core::vector3d<float>(reinterpret_cast<const CharacterDestinationView*>(npc)->destination));
                    }
                } else {
                    npc->unknown296 = irr::core::vector3d<float>(point->normal.x, point->normal.y, 0.0f);
                }
            }
        }
        }
    } else if (__builtin_expect(!first && secondData, 0)) {
        if (LevelObject::s_type[second->getObjectType()] == 5) {
            NPC* npc = static_cast<NPC*>(second);
            if ((IsMoving(npc->category428)) && !npc->getPathToFollow()) {
                if (!_ZNK3irr4core8vector3dIfE6equalsERKS2_f(&npc->unknown296, irr::core::vector3d<float>(0.0f, 0.0f, 0.0f), 0.000001f)) {
                    npc->unknown296 += irr::core::vector3d<float>(point->normal.x, point->normal.y, 0.0f);
                    npc->setDestination(second->GetPosition() + npc->unknown296 * 500.0f, 100);
                    if (npc->flags356 & 4) {
                        npc->Character::runToLocation(irr::core::vector3d<float>(reinterpret_cast<const CharacterDestinationView*>(npc)->destination));
                    }
                } else {
                    npc->unknown296 = irr::core::vector3d<float>(point->normal.x, point->normal.y, 0.0f);
                }
            }
        }
    }
}

#include "PhysicInfo.h"

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


template void SafeDelete<b2World>(b2World*&);

void PhysicAttributes::InitWorld()
{
    b2AABB bounds;
    bounds.lowerBound.x = -2000.0f;
    bounds.lowerBound.y = -2000.0f;
    bounds.upperBound.x = 2000.0f;
    bounds.upperBound.y = 2000.0f;
    const b2Vec2 gravity(0.0f, 0.0f);
    s_world = new b2World(bounds, gravity, true);
    s_world->SetPositionCorrection(true);
    s_world->SetContinuousPhysics(false);
    s_contactListener = new ContactListener;
    s_contactFilter = new ContactFilter;
    s_world->SetContactListener(s_contactListener);
    s_world->SetContactFilter(s_contactFilter);
    b2BodyDef definition;
    s_groundBody = s_world->CreateBody(&definition);
}

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

struct AStarNode {
    // Native default record: invalid keys, zero costs/state, invalid final key.
    AStarNode() : triangleOffset(65535), region(65535),
        parentTriangleOffset(65535), parentRegion(65535), cost(0), pathCost(0),
        unknown16(0), unknown18(0), unknown20(65535) {}
    unsigned short triangleOffset, region;
    unsigned short parentTriangleOffset, parentRegion;
    float cost, pathCost;
    unsigned short unknown16, unknown18, unknown20;
};

irr::core::vector3d<float> PhysicAttributes::GetPathPos(int index)
{
    using irr::core::vector3d;
    using irr::scene::IMeshBuffer;
    using irr::scene::IMeshSceneNode;

    if (index < pathLength - 1) {
        const unsigned short offset = path.data[index].triangleOffset;
        const unsigned short bufferIndex = path.data[index].region;
        ++index;
        const unsigned short nextOffset = path.data[index].triangleOffset;
        const unsigned short nextBufferIndex = path.data[index].region;

        IMeshBuffer* buffer = static_cast<IMeshSceneNode*>(s_heightmap)->getMesh()->getMeshBuffer(bufferIndex);
        unsigned short* indices = buffer->getIndices();
        unsigned short* nextIndices = static_cast<IMeshSceneNode*>(s_heightmap)
            ->getMesh()->getMeshBuffer(nextBufferIndex)->getIndices();

        bool foundFirst = false;
        int firstIndex;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (indices[offset + i] == nextIndices[nextOffset + j]) {
                    if (foundFirst) {
                        const vector3d<float>& first = buffer->getPosition(indices[firstIndex]);
                        const vector3d<float>& second = buffer->getPosition(indices[offset + i]);
                        return (first + second) * 0.5f + s_heightmap->getAbsolutePosition()
                            + vector3d<float>(0.0f, 0.0f, 3.0f);
                    }
                    firstIndex = offset + i;
                    foundFirst = true;
                }
            }
        }
    } else if (index == pathLength - 1) {
        return pathTarget;
    }
    return vector3d<float>();
}

irr::core::vector3d<float> PhysicAttributes::GetTriCenter(unsigned short bufferIndex, unsigned short triangleOffset)
{
    irr::scene::IMeshSceneNode* node = static_cast<irr::scene::IMeshSceneNode*>(s_heightmap);
    irr::scene::IMeshBuffer* buffer = node->getMesh()->getMeshBuffer(bufferIndex);
    unsigned short* indices = buffer->getIndices();
    const irr::core::vector3d<float> a = buffer->getPosition(indices[triangleOffset]);
    const irr::core::vector3d<float> b = buffer->getPosition(indices[triangleOffset + 1]);
    const irr::core::vector3d<float> c = buffer->getPosition(indices[triangleOffset + 2]);
    return (a + b + c) * (1.0f / 3.0f) + s_heightmap->getAbsolutePosition();
}

void PhysicAttributes::CreateNeighborTris(irr::scene::ISceneNode* node, int id)
{
    node->updateAbsolutePosition(false);
    // The retail fork recognizes these two mesh node types as heightmaps.
    if (node->getType() == 0x6d656164 || node->getType() == 0x73656164) {
        if (!s_heightmap) {
            ++node->references;
            s_heightmap = node;
        }
    } else {
        --id;
    }
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        CreateNeighborTris(child->value, ++id);
    }
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
    if (path.free_when_destroyed)
        ::operator delete(path.data);
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

namespace {
struct JumpShapeData {
    unsigned char unknown0[8];
    float heights[4];
    unsigned char unknown24;
    unsigned char flags;
};

inline __attribute__((always_inline)) void setJumpVertex(irr::core::vector3d<float>& vertex,
    b2Body* body, const b2Vec2& local, const float& height)
{
    const b2XForm& transform = body->GetXForm();
    b2Vec2 rotated;
    rotated.x = local.x * transform.rotation[0] + local.y * transform.rotation[2];
    rotated.y = local.x * transform.rotation[1] + local.y * transform.rotation[3];
    b2Vec2 world;
    world.x = rotated.x + transform.position.x;
    world.y = rotated.y + transform.position.y;
    vertex = irr::core::vector3d<float>(world.x * 100.0f, world.y * 100.0f, height);
}
}

void PhysicAttributes::SetCurrentJumpShape(b2Shape* shape)
{
    const b2PolygonShape* polygon = static_cast<const b2PolygonShape*>(shape);
    const JumpShapeData* data = static_cast<const JumpShapeData*>(shape->GetBody()->GetUserData());
    setJumpVertex(jumpVertices[0], shape->GetBody(), polygon->vertices[0], data->heights[0]);
    setJumpVertex(jumpVertices[1], shape->GetBody(), polygon->vertices[1], data->heights[1]);
    setJumpVertex(jumpVertices[2], shape->GetBody(), polygon->vertices[2], data->heights[2]);
    setJumpVertex(jumpVertices[3], shape->GetBody(), polygon->vertices[3], data->heights[3]);
    jumpVertices[4] = (jumpVertices[0] + jumpVertices[1] + jumpVertices[2] + jumpVertices[3]) * 0.25f;
    hasJumpShape = true;
    jumpFlags = data->flags;
}

void PhysicInfo::Reset(b2World* world)
{
    unknown0 = static_cast<unsigned short>(-1);
    unknown4 = 0;
    vector12 = irr::core::vector3d<float>(0,0,0);
    vector24 = irr::core::vector3d<float>(0,0,0);
    vector36 = irr::core::vector3d<float>(0,0,0);
    vector48 = irr::core::vector3d<float>(0,0,0);
    unknown60 = false;
    unknown76 = static_cast<unsigned short>(-1);
    unknown78 = static_cast<unsigned short>(-1);
    unknown80 = static_cast<unsigned short>(-1);
    unknown8 = static_cast<unsigned short>(-1);
    unknown82 = 1;
    unknown84 = false;
    onGround = true;
    wasOnGround = true;
    if (world) {
        for (int i=0; i<12; ++i) {
            if (bodies[i]) {
                if (bodies[i]->data) {
                    ::operator delete(bodies[i]->data);
                    bodies[i]->data = 0;
                }
                world->DestroyBody(bodies[i]);
                bodies[i] = 0;
            }
        }
    }
}

#include "../core/UnsignedShortArray.h"

template<class T> void SafeDeleteArray(T*& object) __attribute__((weak));
template<class T> void SafeDeleteArray(T*& object)
{
    delete[] object;
    object = 0;
}
template void SafeDeleteArray<irr::core::array<unsigned short> >(irr::core::array<unsigned short>*&);

bool PhysicAttributes::SegmentsIntersect(const irr::core::vector3d<float>& a,
    const irr::core::vector3d<float>& b, const irr::core::vector3d<float>& c,
    const irr::core::vector3d<float>& d)
{
    if (a.X == b.X && a.Y == b.Y)
        return false;
    if (c.X != d.X || c.Y != d.Y) {
        float denominator = (d.Y - c.Y) * (b.X - a.X) - (d.X - c.X) * (b.Y - a.Y);
        float numeratorA = (d.X - c.X) * (a.Y - c.Y) - (d.Y - c.Y) * (a.X - c.X);
        float numeratorB = (b.X - a.X) * (a.Y - c.Y) - (b.Y - a.Y) * (a.X - c.X);
        if (denominator == 0.0f)
            return !(numeratorA != 0.0f || numeratorB != 0.0f);
        float u = numeratorA / denominator;
        float v = numeratorB / denominator;
        return u >= 0.0f && u <= 1.0f && v >= 0.0f && v <= 1.0f;
    }
    return false;
}

void PhysicAttributes::UpdateEdgesCollisions(int slot)
{
    PhysicInfo& current = info[slot];
    if (!current.onGround)
        return;
    for (int i = 0; i < 12; ++i) {
        if (current.bodies[i]) {
            if (current.bodies[i]->data) {
                ::operator delete(current.bodies[i]->data);
                current.bodies[i]->data = 0;
            }
            s_world->DestroyBody(current.bodies[i]);
            current.bodies[i] = 0;
        }
    }
    unsigned short* indices = static_cast<irr::scene::IMeshSceneNode*>(s_heightmap)->getMesh()->getMeshBuffer(current.unknown0)->getIndices();
    AddCollisionShapes(slot, indices[current.unknown8]);
    AddCollisionShapes(slot, indices[current.unknown8 + 1]);
    AddCollisionShapes(slot, indices[current.unknown8 + 2]);
    for (int edge = 0; edge < 3; ++edge) {
        unsigned short triangle = s_neighbors[current.unknown0][edge][static_cast<unsigned short>(current.unknown8 / 3)];
        unsigned short region = s_neighbors[current.unknown0][edge + 3][static_cast<unsigned short>(current.unknown8 / 3)];
        if (triangle != 65535 && region != 65535) {
            unsigned short* adjacent = static_cast<irr::scene::IMeshSceneNode*>(s_heightmap)->getMesh()->getMeshBuffer(region)->getIndices();
            for (int vertex = 0; vertex < 3; ++vertex) {
                unsigned short candidate = adjacent[triangle + vertex];
                if (candidate != indices[current.unknown8] && candidate != indices[current.unknown8 + 1] && candidate != indices[current.unknown8 + 2]) {
                    AddCollisionShapes(slot, candidate);
                    break;
                }
            }
        }
    }
}

template<class T>
static inline void cleanPhysicArray(T*& pointer)
{
    delete[] pointer;
    pointer=0;
}

void PhysicAttributes::Clean()
{
    if(s_heightmap) {
        int count=static_cast<irr::scene::IMeshSceneNode*>(s_heightmap)->getMesh()->getMeshBufferCount();
        for(int i=0;i<count;++i) {
            for(int j=0;j<8;++j)
                cleanPhysicArray(s_neighbors[i][j]);
            cleanPhysicArray(s_neighbors[i]);
            cleanPhysicArray(s_neighborsWrongWay[i]);
            SafeDeleteArray(s_overlapping[i]);
        }
        cleanPhysicArray(s_neighbors);
        cleanPhysicArray(s_neighborsWrongWay);
        cleanPhysicArray(s_neighborsCnt);
        cleanPhysicArray(s_cliffVertexKeyMap);
        cleanPhysicArray(s_cliffTriMap);
        cleanPhysicArray(s_overlapping);
        for(int i=0;i<2;++i)
            cleanPhysicArray(s_nodeCost[i]);
        cleanPhysicArray(s_nodeCost);
        s_heightmap->drop();
    }
}

void PhysicAttributes::Init(unsigned short region,unsigned short surface,const irr::core::vector3d<float>& position)
{
    info->unknown4=reinterpret_cast<unsigned int>(s_heightmap);
    info->unknown0=region;
    info->unknown8=surface;
    irr::core::vector3d<float> origin=reinterpret_cast<irr::scene::ISceneNode*>(info->unknown4)->getAbsolutePosition();
    irr::scene::IMeshBuffer* buffer=static_cast<irr::scene::IMeshSceneNode*>(reinterpret_cast<irr::scene::ISceneNode*>(info->unknown4))->getMesh()->getMeshBuffer(info->unknown0);
    unsigned short* indices=buffer->getIndices();
    info->vector12=origin+buffer->getPosition(indices[info->unknown8]);
    info->vector24=origin+buffer->getPosition(indices[info->unknown8+1]);
    info->vector36=origin+buffer->getPosition(indices[info->unknown8+2]);
    irr::core::vector3d<float> first=info->vector12-info->vector24;
    irr::core::vector3d<float> second=info->vector36-info->vector24;
    info->vector48=irr::core::vector3d<float>(
        (-first.Y)*second.Z+first.Z*second.Y,
        second.X*(-first.Z)+first.X*second.Z,
        second.Y*(-first.X)+first.Y*second.X).normalize();
    info->unknown64=position;
    UpdateEdgesCollisions(0);
}


#include "../core/NativeStdio.h"
#include "../core/PathName.h"
#include "../core/Debug_Log.h"
void* operator new[](unsigned int);
static const char loadArraysMode[]="rb";
static const char loadArraysError[]="ERROR-fopen=0: PhysicAttributes::LoadArrays-fullname='%s' \n";
void PhysicAttributes::LoadArrays(char* filename)
{
    char fullName[255];
    ekd_makestringfile255(filename,fullName);
    NativeFile* file=fopen(fullName,loadArraysMode);
    if(!file) ekd_debug_out(loadArraysError,fullName);
    int count=0;
    fread(&count,4,1,file);
    s_neighborsCnt=new unsigned short[count];
    s_neighbors=new unsigned short**[count];
    s_neighborsWrongWay=new unsigned char*[count];
    s_overlapping=new irr::core::array<unsigned short>*[count];
    fread(s_neighborsCnt,2,count,file);
    for(int i=0;i<count;++i) {
        s_neighbors[i]=new unsigned short*[8];
        s_neighborsWrongWay[i]=new unsigned char[static_cast<unsigned short>(s_neighborsCnt[i]/3)];
        s_overlapping[i]=new irr::core::array<unsigned short>[static_cast<unsigned short>(s_neighborsCnt[i]/3)];
    }
    for(int i=0;i<count;++i) {
        for(int j=0;j<8;++j) {
            *reinterpret_cast<unsigned short**>(reinterpret_cast<unsigned char*>(s_neighbors[i])+j*4)=new unsigned short[static_cast<unsigned short>(*reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(s_neighborsCnt)+i*2)/3)];
            fread(*reinterpret_cast<unsigned short**>(reinterpret_cast<unsigned char*>(s_neighbors[i])+j*4),2,static_cast<unsigned short>(*reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(s_neighborsCnt)+i*2)/3),file);
        }
    }
    for(int i=0;i<count;++i)
        fread(s_neighborsWrongWay[i],1,static_cast<unsigned short>(s_neighborsCnt[i]/3),file);
    fread(&MATERIAL_TYPE_ROAD,4,1,file);
    fread(&MATERIAL_TYPE_SIDEWALK,4,1,file);
    fread(&MATERIAL_TYPE_PARK,4,1,file);
    fread(&MATERIAL_TYPE_BUILDING_BASE,4,1,file);
    fread(&MATERIAL_TYPE_INTERSECTION,4,1,file);
    fread(&MATERIAL_TYPE_CLIFF,4,1,file);
    fread(&MATERIAL_TYPE_WATER,4,1,file);
    fread(&MATERIAL_TYPE_DEATH_WATER,4,1,file);
    unsigned short length;
    fread(&length,2,1,file);
    s_cliffVertexKeyMap=new unsigned short[length];
    fread(s_cliffVertexKeyMap,2,length,file);
    fread(&length,2,1,file);
    s_cliffTriMap=new unsigned short[length];
    fread(s_cliffTriMap,2,length,file);
    for(int i=0;i<count;++i) {
        for(int j=0;j<static_cast<unsigned short>(s_neighborsCnt[i]/3);++j) {
            unsigned short overlapLength;
            fread(&overlapLength,1,2,file);
            for(int k=0;k<overlapLength/2;++k) {
                unsigned short pair[2];
                fread(pair,2,2,file);
                s_overlapping[i][j].push_back(pair[0]);
                s_overlapping[i][j].push_back(pair[1]);
            }
        }
    }
    fclose(file);
    s_nodeCost=new float*[2];
    s_nodeCost[0]=new float[count];
    s_nodeCost[1]=new float[count];
    s_nodeCost[0][MATERIAL_TYPE_SIDEWALK]=1.0f;
    s_nodeCost[0][MATERIAL_TYPE_ROAD]=999.0f;
    s_nodeCost[0][MATERIAL_TYPE_PARK]=1.0f;
    s_nodeCost[0][MATERIAL_TYPE_BUILDING_BASE]=999.0f;
    s_nodeCost[0][MATERIAL_TYPE_INTERSECTION]=999.0f;
    s_nodeCost[0][MATERIAL_TYPE_CLIFF]=999.0f;
    s_nodeCost[0][MATERIAL_TYPE_WATER]=999.0f;
    s_nodeCost[0][MATERIAL_TYPE_DEATH_WATER]=999.0f;
    s_nodeCost[1][MATERIAL_TYPE_SIDEWALK]=999.0f;
    s_nodeCost[1][MATERIAL_TYPE_ROAD]=1.0f;
    s_nodeCost[1][MATERIAL_TYPE_PARK]=999.0f;
    s_nodeCost[1][MATERIAL_TYPE_BUILDING_BASE]=999.0f;
    s_nodeCost[1][MATERIAL_TYPE_INTERSECTION]=1.0f;
    s_nodeCost[1][MATERIAL_TYPE_CLIFF]=999.0f;
    s_nodeCost[1][MATERIAL_TYPE_WATER]=999.0f;
    s_nodeCost[1][MATERIAL_TYPE_DEATH_WATER]=999.0f;
}


extern "C" float _ZN16PhysicAttributes9GetHeightEiRKN3irr4core8vector3dIfEEbb(
    PhysicAttributes* self, int slot, const irr::core::vector3d<float>& position, bool useHeightmap, bool detailed);
extern "C" float _ZN16PhysicAttributes13GetJumpHeightERKN3irr4core8vector3dIfEEi(
    PhysicAttributes* self, const irr::core::vector3d<float>& position, int slot);

float PhysicAttributes::GetHeight(const irr::core::vector3d<float>& position, int slot, bool detailed)
{
    if (info[slot].unknown64.Z == 999999.0f)
        info[slot].unknown64 = position;
    info[slot].unknown60 = false;
    if (__builtin_expect(info[slot].unknown4 != 0, 1)) {
        s_currentUsed += 4;
        float height = _ZN16PhysicAttributes9GetHeightEiRKN3irr4core8vector3dIfEEbb(this, slot, position, true, detailed);
        if (height != 999999.0f) {
            info[slot].unknown64 = position;
            if (hasJumpShape) {
                if (slot == 0)
                    unknown116 = 0;
                const float jump = _ZN16PhysicAttributes13GetJumpHeightERKN3irr4core8vector3dIfEEi(this, position, slot);
                if (height < jump && jump != 999999.0f)
                    height = jump;
            }
            info[slot].unknown64.Z = height;
            return info[slot].unknown64.Z;
        }
    }
    return info[slot].unknown64.Z;
}


// Second, layout-equivalent view of jumpVertices.  Retail reloads vertices
// 1 and 2 after the reciprocal while vertex 0 stays in registers; reading the
// barycentric terms through a distinct access path keeps FRE/DOM from merging
// them with the edge loads (the RTL CSE still merges vertex 0).
struct JumpShapeView {
    unsigned char unknown0[52];
    irr::core::vector3d<float> vertices[5];
};

float _ZN16PhysicAttributes13GetJumpHeightERKN3irr4core8vector3dIfEEi(
    PhysicAttributes* self, const irr::core::vector3d<float>& p, int)
{
    if (p.getDistanceFromSQ(self->jumpVertices[4]) < 2250000.0f) {
        const float px = p.X;
        const float py = p.Y;
        for (int i = 0; i < 4; ++i) {
            const irr::core::vector3d<float>& a = self->jumpVertices[i];
            const irr::core::vector3d<float>& b = self->jumpVertices[(i + 1) % 4];
            // Self-assignments keep TER from sinking the edge X term, the
            // b.Y load and the point X term into the cross product
            // (same-root-variable rule), matching retail evaluation order.
            float ex = b.X - a.X;
            float ey = b.Y;
            ey -= a.Y;
            float dx = px - a.X;
            float dy = py - a.Y;
            ex *= dy;
            dx = ey * dx;
            if (ex - dx < 0.0f)
                return 999999.0f;
        }
        const irr::core::vector3d<float>& a = self->jumpVertices[0];
        const irr::core::vector3d<float>& b = self->jumpVertices[1];
        const irr::core::vector3d<float>& c = self->jumpVertices[2];
        irr::core::vector3d<float> ab = b - a;
        irr::core::vector3d<float> ca = a - c;
        float inv = 1.0f / (ab.X * -ca.Y + ab.Y * ca.X);
        const JumpShapeView* view = reinterpret_cast<const JumpShapeView*>(self);
        const irr::core::vector3d<float>& vb = view->vertices[1];
        const irr::core::vector3d<float>& vc = view->vertices[2];
        float v = ((px - vb.X) * (vb.Y - vc.Y) - (vb.X - vc.X) * (py - vb.Y)) * inv;
        float u = ((px - vc.X) * (vc.Y - a.Y) - (vc.X - a.X) * (py - vc.Y)) * inv;
        ++self->unknown116;
        return ab.Z * u + a.Z - ca.Z * (1.0f - u - v);
    }
    self->hasJumpShape = false;
    self->unknown116 = 0;
    return 999999.0f;
}

AStarNode PhysicAttributes::FindLowerCostNode(irr::core::array<AStarNode>* nodes, int* index)
{
    AStarNode best;
    int minimum = 999999999;
    int selected = 0;
    for (int i = 0; nodes->size() > static_cast<unsigned int>(i); ++i) {
        if ((*nodes)[i].cost < minimum) {
            best = (*nodes)[i];
            minimum = (*nodes)[i].cost;
            selected = i;
        }
    }
    *index = selected;
    return best;
}

bool PhysicAttributes::IsPositionOnJump(const irr::core::vector3d<float>& p)
{
    if (!hasJumpShape)
        return false;
    bool outside = false;
    if (!(p.getDistanceFromSQ(jumpVertices[4]) < 90000.0f))
        outside = true;
    return !outside;
}

namespace irr { namespace core {
template<class T> class plane3d {
public:
    plane3d(const vector3d<T>& point,const vector3d<T>& normal): Normal(normal),D(-point.dotProduct(Normal)) {}
    vector3d<T> Normal;
    T D;
};
} }
float PhysicAttributes::IntersectSegmentWithHeightMap(const irr::core::vector3d<float>& start,
    const irr::core::vector3d<float>& end,irr::core::vector3d<float>& hit,irr::core::vector3d<float>& normal)
{
    irr::core::vector3d<float> delta=end-start;
    irr::core::vector3d<float> planeNormal=irr::core::vector3d<float>(delta.Y,-delta.X,0.0f).crossProduct(delta);
    planeNormal.normalize();
    irr::core::plane3d<float> plane(start,planeNormal);
    PhysicInfo temporary;
    if (!info[0].heightmap) return 1.0f;
    temporary.unknown0=info[0].unknown0;
    temporary.heightmap=info[0].heightmap;
    temporary.unknown8=info[0].unknown8;
    temporary.vector12=info[0].vector12;
    temporary.vector24=info[0].vector24;
    temporary.vector36=info[0].vector36;
    temporary.unknown76=info[0].unknown76;
    temporary.unknown78=info[0].unknown78;
    temporary.unknown80=info[0].unknown80;
    s_currentUsed+=4;
    if (!IntersectSegmentWithHeightMap(temporary,plane,start,end,hit,normal)) return 1.0f;
    return (hit-start).getLength()/(end-start).getLength();
}


extern "C" long lrand48();
extern "C" float fabsf(float);
extern "C" long lrand48();
// Whether `side` is one of the two wrong-way edges recorded in `wrongWay`.
static inline bool GNIsWrongWay(unsigned char wrongWay, int side)
{
    return (wrongWay & 3) == side + 1 || ((wrongWay >> 2) & 3) == side + 1;
}

// Unused variant kept as a no-code hint: its declarations keep the
// declaration numbering that the matched register allocation depends on.
static inline bool GNIsWrongWayEdge(unsigned char wrongWay, int side)
{
    return side + 1 == (wrongWay & 3) || side + 1 == ((wrongWay >> 2) & 3);
}

// GNIsWrongWay reading the flags itself, with the edge number evaluated
// before the table load (sets the compare operand order and reload order).
static inline bool GNIsWrongWayAt(int side, unsigned char* const* table, unsigned int buffer, unsigned int tri)
{
    return side + 1 == (table[buffer][tri] & 3) || side + 1 == ((table[buffer][tri] >> 2) & 3);
}

irr::core::vector3d<float> PhysicAttributes::GetNextRandomPos(int slot, int mode, irr::core::vector3d<float> position)
{
    using irr::core::vector3d;
    PhysicInfo& physic = info[slot];
    // No-code hint: four dead scoped locals (removed by DCE) shift the local
    // variable numbering so the loop PHI copies keep retail's order.
    { int d0 = 0; (void)d0; }
    { int d1 = 0; (void)d1; }
    { int d2 = 0; (void)d2; }
    { int d3 = 0; (void)d3; }
    if (physic.unknown8 == 0xffff)
        return position;
    irr::scene::IMeshBuffer* meshBuffer = static_cast<irr::scene::IMeshSceneNode*>(s_heightmap)
        ->getMesh()->getMeshBuffer(physic.unknown0);
    unsigned short* indices = meshBuffer->getIndices();
    const unsigned short buffer = physic.unknown80;
    const int previous = physic.unknown78;
    const unsigned short side = physic.unknown76;
    if (side == 0xffff) {
        int i;
        float best = 9999999.0f;
        int bestEdge = 0;
        for (i = 0; i < 3; ++i) {
            const unsigned short tri = physic.unknown8 / 3;
            const unsigned short next = s_neighbors[physic.unknown0][i][tri];
            const unsigned short neighbor = s_neighbors[physic.unknown0][i + 3][tri];
            if (next == 0xffff || s_nodeCost[mode][neighbor] == 999.0f)
                continue;
            if (mode == 1) {
                if (GNIsWrongWay(s_neighborsWrongWay[physic.unknown0][tri], i))
                    continue;
            }
            const vector3d<float>& p0 = meshBuffer->getPosition(indices[physic.unknown8 + i]);
            const vector3d<float>& p1 = meshBuffer->getPosition(indices[(i + 1) % 3 + physic.unknown8]);
            const vector3d<float> middle = (p0 + p1) * 0.5f + s_heightmap->getAbsolutePosition();
            const float distance = middle.getDistanceFromSQ(position);
            if (distance < best) {
                best = distance;
                bestEdge = i;
            }
        }
        physic.unknown76 = bestEdge;
        physic.unknown78 = physic.unknown8;
        physic.unknown80 = physic.unknown0;
    } else {
        // Byte offset computed first: retail adds side * 4 before the row load.
        const int sideOffset = side * 4;
        const int tri = previous / 3;
        physic.unknown78 = (*reinterpret_cast<unsigned short**>(reinterpret_cast<char*>(s_neighbors[buffer]) + sideOffset))[tri];
        physic.unknown80 = s_neighbors[buffer][side + 3][tri];
    }

    const int start = lrand48() % 3;
    int i = start;
    bool wrapped = false;
    int chosen = -1;
    while (!(wrapped && i == start)) {
        if (i > 2) {
            i = 0;
            wrapped = true;
            if (i == start)
                break;
        }
        const unsigned short tri = physic.unknown78 / 3;
        const unsigned short next = s_neighbors[physic.unknown80][i][tri];
        // No-code hint: dead copy of position (removed by DCE).
        { irr::core::vector3d<float> d(position); (void)d; }
        const unsigned short neighbor = s_neighbors[physic.unknown80][i + 3][tri];
        if (next == 0xffff || s_nodeCost[mode][neighbor] == 999.0f) {
            // No-code hint: dead copy of position (removed by DCE); with the one
            // above it frees SSA names that PRE reuses, giving retail's operand
            // order for the wrong-way exit compare below.
            { irr::core::vector3d<float> d(position); (void)d; }
            ++i;
            continue;
        }
        if (next == previous) {
            chosen = i;
            ++i;
            continue;
        }
        if (mode == 1) {
            if (GNIsWrongWayAt(i, s_neighborsWrongWay, physic.unknown80, tri)) {
                ++i;
                continue;
            }
        }
        chosen = i;
        break;
    }

    int exitEdge = chosen;
    // Fallback first, then the mode 1 default: this block order sets retail's
    // reload register rotation.
    if (mode != 1 && chosen == -1) {
        unsigned short surface;
        const vector3d<float> destination = GetRandomDestination(MATERIAL_TYPE_SIDEWALK, surface, position, 0.0f, 0.0f);
        physic.unknown80 = MATERIAL_TYPE_SIDEWALK;
        physic.unknown78 = surface;
        physic.unknown76 = 0xffff;
        return destination;
    }
    if (chosen == -1)
        exitEdge = 0;
    if (mode == 1 && ((s_neighborsWrongWay[physic.unknown80][(unsigned short)(physic.unknown78 / 3)] >> 4) & 3) == exitEdge + 1) {
        const unsigned int oldTri = physic.unknown78;
        const int oldBuffer = physic.unknown80;
        const unsigned short tri = oldTri / 3;
        physic.unknown78 = s_neighbors[oldBuffer][exitEdge][tri];
        physic.unknown80 = s_neighbors[oldBuffer][exitEdge + 3][tri];
        const unsigned short nextTri = physic.unknown78 / 3;
        for (int j = 0; j < 3; ++j) {
            if (s_neighbors[physic.unknown80][j][nextTri] == oldTri
                && s_neighbors[physic.unknown80][j + 3][nextTri] == oldBuffer) {
                physic.unknown76 = (j + 1) % 3;
                break;
            }
        }
    } else {
        physic.unknown76 = exitEdge;
    }
    if (physic.unknown80 == MATERIAL_TYPE_ROAD
        && s_neighbors[physic.unknown80][physic.unknown76 + 3][(unsigned short)(physic.unknown78 / 3)] == MATERIAL_TYPE_INTERSECTION)
        physic.unknown84 = true;

    irr::scene::IMeshBuffer* edgeBuffer = static_cast<irr::scene::IMeshSceneNode*>(s_heightmap)
        ->getMesh()->getMeshBuffer(physic.unknown80);
    unsigned short* edgeIndices = edgeBuffer->getIndices();
    const vector3d<float> edge = edgeBuffer->getPosition(edgeIndices[(physic.unknown76 + 1) % 3 + physic.unknown78])
        - edgeBuffer->getPosition(edgeIndices[physic.unknown78 + physic.unknown76]);
    int lanes = (s_neighborsWrongWay[physic.unknown80][(unsigned short)(physic.unknown78 / 3)] & 0xc0) >> 6;
    if (lanes == 0)
        lanes = 1;
    const float width = 1.0f / (lanes * 2.0f);
    if (physic.unknown82 > lanes)
        physic.unknown82 = lanes;
    return edgeBuffer->getPosition(edgeIndices[physic.unknown78 + physic.unknown76])
        + edge * (physic.unknown82 * 2.0f - 1.0f) * width + s_heightmap->getAbsolutePosition();
}
irr::core::vector3d<float> PhysicAttributes::GetRandomDestination(unsigned short material, unsigned short& surface,
    const irr::core::vector3d<float>& origin, float minimum, float maximum)
{
    const int start = static_cast<int>(lrand48() % s_neighborsCnt[material]) / 3;
    minimum *= minimum;
    maximum *= maximum;
    const float middle = (minimum + maximum) * 0.5f;
    irr::core::vector3d<float> best(0.0f, 0.0f, 0.0f);
    irr::core::vector3d<float> center;
    float bestDistance = 1.0e9f;
    if (start > 1) {
        for (int i = start; i != start - 1; ++i) {
            if (i >= static_cast<unsigned short>(s_neighborsCnt[material] / 3))
                i = 0;
            const unsigned short triangle = i * 3;
            center = GetTriCenter(material, triangle);
            const float distance = center.getDistanceFromSQ(origin);
            if (minimum <= distance && maximum >= distance) {
                surface = triangle;
                return center;
            }
            if (fabsf(distance - middle) < bestDistance) {
                surface = triangle;
                bestDistance = fabsf(distance - middle);
                best = center;
            }
        }
    } else {
        for (int i = 0; i < static_cast<unsigned short>(s_neighborsCnt[material] / 3); ++i) {
            const unsigned short triangle = i * 3;
            center = GetTriCenter(material, triangle);
            const float distance = center.getDistanceFromSQ(origin);
            if (minimum <= distance && maximum >= distance) {
                surface = triangle;
                return center;
            }
            if (fabsf(distance - middle) < bestDistance) {
                surface = triangle;
                bestDistance = fabsf(distance - middle);
                best = center;
            }
        }
    }
    return best;
}

// Irrlicht ISceneNode::getAbsolutePosition() copy.
static inline irr::core::vector3d<float> SHAbsolutePosition(irr::scene::ISceneNode* node)
{
    irr::core::vector3d<float> position = node->getAbsolutePosition();
    return position;
}

// Irrlicht array::operator[](u32).
static inline const unsigned short& SHOverlapAt(const irr::core::array<unsigned short>& overlap, unsigned int index)
{
    return overlap.data[index];
}

// Not declared in PhysicAttributes.h; defined through its mangled name.
extern "C" float _ZN16PhysicAttributes19SetHeightAttributesERKN3irr4core8vector3dIfEEP10PhysicInfo(
    PhysicAttributes* self, const irr::core::vector3d<float>& position, PhysicInfo* info)
{
    using irr::core::vector3d;
    typedef PhysicAttributes PA;
    vector3d<float> a, b, c;
    vector3d<float> pa, pb, pc, ab, bc, ca;
    const vector3d<float> offset = SHAbsolutePosition(PA::s_heightmap);
    for (int k = 0; k < PA::s_overlapping[info->unknown0][(unsigned short)(info->unknown8 / 3)].used; k += 2) {
        const irr::core::array<unsigned short>& overlap = PA::s_overlapping[info->unknown0][(unsigned short)(info->unknown8 / 3)];
        const unsigned short buffer = SHOverlapAt(overlap, k);
        const unsigned short index = SHOverlapAt(overlap, k + 1);
        irr::scene::IMeshBuffer* meshBuffer = static_cast<irr::scene::IMeshSceneNode*>(PA::s_heightmap)
            ->getMesh()->getMeshBuffer(buffer);
        unsigned short* indices = meshBuffer->getIndices();
        const unsigned short flags = PA::s_neighbors[buffer][7][(unsigned short)(index / 3)];
        if ((flags & 3) == 1 || (flags & 3) == 2)
            continue;
        a = offset + meshBuffer->getPosition(indices[index]);
        b = offset + meshBuffer->getPosition(indices[index + 1]);
        c = offset + meshBuffer->getPosition(indices[index + 2]);
        pa = position - a;
        pb = position - b;
        pc = position - c;
        ab = b - a;
        bc = c - b;
        ca = a - c;
        if (pa.Y * ab.X - pa.X * ab.Y < 0.0f && PA::SegmentsIntersect(info->unknown64, position, a, b)) {
            info->unknown0 = buffer;
            info->heightmap = PA::s_heightmap;
            info->unknown8 = index;
            return _ZN16PhysicAttributes19SetHeightAttributesERKN3irr4core8vector3dIfEEP10PhysicInfo(self, position, info);
        }
        if (pb.Y * bc.X - pb.X * bc.Y < 0.0f && PA::SegmentsIntersect(info->unknown64, position, b, c)) {
            info->unknown0 = buffer;
            info->heightmap = PA::s_heightmap;
            info->unknown8 = index;
            return _ZN16PhysicAttributes19SetHeightAttributesERKN3irr4core8vector3dIfEEP10PhysicInfo(self, position, info);
        }
        if (pc.Y * ca.X - pc.X * ca.Y < 0.0f && PA::SegmentsIntersect(info->unknown64, position, c, a)) {
            info->unknown0 = buffer;
            info->heightmap = PA::s_heightmap;
            info->unknown8 = index;
            return _ZN16PhysicAttributes19SetHeightAttributesERKN3irr4core8vector3dIfEEP10PhysicInfo(self, position, info);
        }
        const float inverse = 1.0f / (ab.X * -ca.Y + ab.Y * ca.X);
        const float u = ((position.X - b.X) * (b.Y - c.Y) - (b.X - c.X) * (position.Y - b.Y)) * inverse;
        const float v = ((position.X - c.X) * (c.Y - a.Y) - (c.X - a.X) * (position.Y - c.Y)) * inverse;
        info->unknown0 = buffer;
        info->heightmap = PA::s_heightmap;
        info->unknown8 = index;
        info->vector12 = a;
        info->vector24 = b;
        info->vector36 = c;
        const vector3d<float> ba = a - b;
        const vector3d<float> cb = c - b;
        info->vector48 = cb.crossProduct(ba).normalize();
        info->unknown60 = true;
        return ab.Z * v + a.Z - ca.Z * (1.0f - v - u);
    }
    return 999999.0f;
}

// Irrlicht aabbox3d::getCenter().
static inline irr::core::vector3d<float> GetBoxCenter(const irr::core::aabbox3d<float>& box)
{
    return (box.MinEdge + box.MaxEdge) * 0.5f;
}

// Not declared in PhysicAttributes.h; defined through its mangled name.
extern "C" void _ZN16PhysicAttributes19SetHeightAttributesEPN3irr5scene10ISceneNodeERKNS0_4core8vector3dIfEER10PhysicInfo(
    PhysicAttributes* self, irr::scene::ISceneNode* node, const irr::core::vector3d<float>& position, PhysicInfo& info)
{
    using irr::core::vector3d;

    vector3d<float> offset;
    vector3d<float> a, b, c;
    vector3d<float> pa, pb, pc, ab, bc, ca;
    int type = node->getType();
    if (type == 0x6d656164 || type == 0x73656164) {
        const irr::core::aabbox3d<float>& box = node->getTransformedBoundingBox();
        const vector3d<float> point(position.X, position.Y, GetBoxCenter(node->getTransformedBoundingBox()).Z);
        if (point.X >= box.MinEdge.X && point.X <= box.MaxEdge.X
            && point.Y >= box.MinEdge.Y && point.Y <= box.MaxEdge.Y
            && point.Z >= box.MinEdge.Z && point.Z <= box.MaxEdge.Z) {
            for (int i = 0; static_cast<irr::scene::IMeshSceneNode*>(node)->getMesh()->getMeshBufferCount() > (unsigned int)i; ++i) {
                irr::scene::IMeshBuffer* buffer = static_cast<irr::scene::IMeshSceneNode*>(node)->getMesh()->getMeshBuffer(i);
                unsigned short* indices = buffer->getIndices();
                offset = SHAbsolutePosition(node);
                for (unsigned int j = 0; j < buffer->getIndexCount(); j += 3) {
                    int flags = PhysicAttributes::s_neighbors[i][7][j / 3] & 3;
                    if (flags == 1 || flags == 2)
                        continue;
                    a = offset + buffer->getPosition(indices[j]);
                    b = offset + buffer->getPosition(indices[j + 1]);
                    c = offset + buffer->getPosition(indices[j + 2]);
                    pa = position - a;
                    pb = position - b;
                    pc = position - c;
                    ab = b - a;
                    bc = c - b;
                    ca = a - c;
                    if (pa.Y * ab.X - pa.X * ab.Y < 0.0f || pb.Y * bc.X - pb.X * bc.Y < 0.0f || pc.Y * ca.X - pc.X * ca.Y < 0.0f)
                        continue;
                    info.unknown0 = i;
                    info.heightmap = node;
                    info.unknown8 = j;
                    info.vector12 = a;
                    info.vector24 = b;
                    info.vector36 = c;
                    const vector3d<float> ba = info.vector12 - info.vector24;
                    const vector3d<float> cb = info.vector36 - info.vector24;
                    info.vector48 = cb.crossProduct(ba).normalize();
                    info.unknown60 = true;
                    info.unknown64 = position;
                    return;
                }
            }
        }
    }
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next)
        _ZN16PhysicAttributes19SetHeightAttributesEPN3irr5scene10ISceneNodeERKNS0_4core8vector3dIfEER10PhysicInfo(
            self, child->value, position, info);
}

PhysicAttributes::PhysicAttributes(int type, b2Body* b)
{
    infoCount = type;
    PhysicInfo* p = new PhysicInfo[type];
    info = p;
    pathLength = 0;
    pathTarget = irr::core::vector3d<float>(0.0f, 0.0f, 0.0f);
    body = b;
    hasJumpShape = false;
    unknown116 = 0;
    if (!s_PoolID) {
        s_PoolID = new bool[50];
        for (int i = 0; i < 50; ++i)
            s_PoolID[i] = false;
    }
    for (int i = 0; i < 50; ++i) {
        if (!s_PoolID[i]) {
            index = i;
            s_PoolID[i] = true;
            break;
        }
    }
}

// ---- ContactFilter::ShouldCollide (appended to preserve earlier decl UIDs) ----
#include "../core/Geometry.h"
#include "PlayerTest.h"
// Probe view: retail Character float at 0x9c (Character::unknown156, private).
struct ContactHeightOwner { unsigned char unknown0[156]; float heightOffset; };
static inline bool IsEmptyFilter(const b2FilterData& filter)
{
    return filter.categoryBits == 0 && filter.groupIndex == 0 && filter.maskBits == 0;
}

bool ContactFilter::ShouldCollide(b2Shape* first, b2Shape* second)
{
    const b2FilterData& filter1 = first->GetFilterData();
    const b2FilterData& filter2 = second->GetFilterData();
    if (IsEmptyFilter(filter1) || IsEmptyFilter(filter2))
        return false;
    bool collide = ((filter1.categoryBits == 0 || filter2.categoryBits == 0) && filter1.groupIndex == filter2.groupIndex)
        // No-code hint (PRED_CALL) on the second mask test, matching retail's layout.
        || ((filter1.maskBits & filter2.categoryBits) != 0
            && (__builtin_prefetch(&filter2), (filter1.categoryBits & filter2.maskBits) != 0));
    if (!collide)
        return false;

    const PhysicsBodyData* data1 = static_cast<const PhysicsBodyData*>(first->GetBody()->GetUserData());
    if (!data1)
        return true;
    // No-code hint (PRED_CALL): retail's frequencies treat the rest as guarded.
    __builtin_prefetch(data1);
    const PhysicsBodyData* data2 = static_cast<const PhysicsBodyData*>(second->GetBody()->GetUserData());
    if (!data2)
        return true;
    // No-code hint (PRED_CALL): retail's frequencies treat the rest as guarded.
    __builtin_prefetch(data2);

    float low1, high1, low2, high2;
    if (data1->node) {
        LevelObject* owner = data1->owner;
        int type = LevelObject::s_type[owner->getObjectType()];
        if (type == 3 && owner->getPhysicAttributes()->unknown116 > 0 && !data2->node)
            return false;
        if (type == 5 || static_cast<LevelObject*>(PlayerTest::GetPlayer()) == owner) {
            // Retail re-reads data1->owner after the GetPlayer() call.
            LevelObject* object = data1->owner;
            low1 = object->GetPosition().Z - reinterpret_cast<ContactHeightOwner*>(object)->heightOffset - 25.0f;
            high1 = low1 + 150.0f + 25.0f;
        } else {
            const irr::core::aabbox3d<float>& box = data1->node->getTransformedBoundingBox();
            low1 = box.MinEdge.Z;
            high1 = box.MaxEdge.Z;
        }
    } else if (data1->unknown24) {
        low1 = irr::core::min_(data1->unknown20, irr::core::min_(data1->unknown16, irr::core::min_(data1->upperHeight, data1->lowerHeight)));
        high1 = irr::core::max_(irr::core::max_(irr::core::max_(data1->lowerHeight, data1->upperHeight), data1->unknown16), data1->unknown20);
    } else {
        if (filter1.categoryBits == 0 || filter2.categoryBits == 0
            || (first->GetBody()->GetXForm().position.x > -450.0f && first->GetBody()->GetXForm().position.x < -405.0f
                && first->GetBody()->GetXForm().position.y > -560.0f && first->GetBody()->GetXForm().position.y < -420.0f))
            low1 = data1->lowerHeight;
        else
            low1 = -999999.0f;
        high1 = data1->upperHeight;
    }
    if (data2->node) {
        LevelObject* owner = data2->owner;
        int type = LevelObject::s_type[owner->getObjectType()];
        if (type == 3 && owner->getPhysicAttributes()->unknown116 > 0 && !data1->node)
            return false;
        if (type == 5 || static_cast<LevelObject*>(PlayerTest::GetPlayer()) == owner) {
            // Retail re-reads data2->owner after the GetPlayer() call.
            LevelObject* object = data2->owner;
            low2 = object->GetPosition().Z - reinterpret_cast<ContactHeightOwner*>(object)->heightOffset - 25.0f;
            high2 = low2 + 150.0f + 25.0f;
        } else {
            const irr::core::aabbox3d<float>& box = data2->node->getTransformedBoundingBox();
            low2 = box.MinEdge.Z;
            high2 = box.MaxEdge.Z;
        }
    } else if (data2->unknown24) {
        // Same min_ chain as data1, written as in-place updates of low2.
        const float& lowest = irr::core::min_(data2->upperHeight, data2->lowerHeight);
        if (data2->unknown16 < lowest)
            low2 = data2->unknown16;
        else
            low2 = lowest;
        if (data2->unknown20 < low2)
            low2 = data2->unknown20;
        high2 = irr::core::max_(irr::core::max_(irr::core::max_(data2->lowerHeight, data2->upperHeight), data2->unknown16), data2->unknown20);
    } else {
        if (filter1.categoryBits == 0 || filter2.categoryBits == 0
            || (second->GetBody()->GetXForm().position.x > -450.0f && second->GetBody()->GetXForm().position.x < -405.0f
                && second->GetBody()->GetXForm().position.y > -560.0f && second->GetBody()->GetXForm().position.y < -420.0f))
            low2 = data2->lowerHeight;
        else
            low2 = -999999.0f;
        high2 = data2->upperHeight;
    }

    bool overlap = low1 < high2 && high1 > low2;
    if (data1->unknown24) {
        b2Body* body1 = first->GetBody();
        b2Body* body2 = second->GetBody();
        if (body2->linearVelocity.x * body1->transform.rotation[2] + body2->linearVelocity.y * body1->transform.rotation[3] > 0.0f) {
            data2->owner->getPhysicAttributes()->SetCurrentJumpShape(first);
            return false;
        }
    } else if (data2->unknown24) {
        b2Body* body1 = first->GetBody();
        b2Body* body2 = second->GetBody();
        // Documented no-code hint: retail lays this jump-shape path out as cold.
        if (__builtin_expect(body1->linearVelocity.x * body2->transform.rotation[2] + body1->linearVelocity.y * body2->transform.rotation[3] > 0.0f, 0)) {
            data1->owner->getPhysicAttributes()->SetCurrentJumpShape(second);
            return false;
        }
    } else {
        // No-code hint (PRED_CALL): balances the guarded expect call above.
        __builtin_prefetch(data2);
    }
    return overlap;
}

#include "PlayerTest.h"
#include "../combat/Rocket.h"
#include "PlayerEvent.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
#include "../input/CControlManager.h"
extern "C" float sqrtf(float);
// Probe views of private retail fields (Rocket +60/+92, Character +92, NPC +356/+428).
struct ContactRocketView { unsigned char unknown0[60]; LevelObject* owner; unsigned char unknown64[28]; bool exploded; };
struct ContactNpcView {
    unsigned char unknown0[92]; irr::core::vector3d<float> destination;
    unsigned char unknown104[252]; unsigned int flags356;
    unsigned char unknown360[68]; unsigned int category428;
};
// Integer view of Character::lastHitVehicle (+196): the retail null test is
// not predicted by the pointer heuristic, which sets the hit-by-car block weight.
struct ContactCharacterView { unsigned char unknown0[196]; unsigned int lastHitVehicle; };
void ContactListener::Add(const b2ContactPoint* point)
{
    const PhysicsBodyData* firstData = static_cast<const PhysicsBodyData*>(point->shape1->GetBody()->GetUserData());
    LevelObject* first = 0;
    if (firstData)
        first = firstData->owner;
    const PhysicsBodyData* secondData = static_cast<const PhysicsBodyData*>(point->shape2->GetBody()->GetUserData());
    LevelObject* second = 0;
    if (secondData)
        second = secondData->owner;

    if (first && LevelObject::s_type[first->getObjectType()] == 12) {
        if (second && (reinterpret_cast<ContactRocketView*>(first)->owner == second || point->shape2->IsSensor()))
            return;
        if (!reinterpret_cast<ContactRocketView*>(first)->exploded) {
            if (second && LevelObject::s_type[second->getObjectType()] == 3 && !second->isDead()) {
                static_cast<Vehicle*>(second)->unknown924 = 5000;
                static_cast<Rocket*>(first)->explode(false);
                return;
            }
            static_cast<Rocket*>(first)->explode(true);
            return;
        }
    }
    if (second && LevelObject::s_type[second->getObjectType()] == 12) {
        if (first && (reinterpret_cast<ContactRocketView*>(second)->owner == first || point->shape1->IsSensor()))
            return;
        if (!reinterpret_cast<ContactRocketView*>(second)->exploded) {
            if (first && LevelObject::s_type[first->getObjectType()] == 3 && !first->isDead()) {
                static_cast<Vehicle*>(first)->unknown924 = 5000;
                static_cast<Rocket*>(second)->explode(false);
                return;
            }
            static_cast<Rocket*>(second)->explode(true);
            return;
        }
    }
    if (point->shape1->IsSensor() && first && LevelObject::s_type[first->getObjectType()] == 3) {
        if (point->shape2->IsSensor())
            return;
        Vehicle* vehicle = static_cast<Vehicle*>(first);
        ++vehicle->sensorContactCount;
        if (vehicle->turnSoundPlaying)
            return;
        if (!(vehicle->flags344 & 0x800))
            return;
        if (vehicle->isDead())
            return;
        if (PlayerTest::GetPlayer() == second || PlayerTest::GetPlayer()->getVehicle() == second)
            vehicle->playHorn();
        return;
    }
    if (point->shape2->IsSensor() && second && LevelObject::s_type[second->getObjectType()] == 3) {
        if (point->shape1->IsSensor())
            return;
        Vehicle* vehicle = static_cast<Vehicle*>(second);
        ++vehicle->sensorContactCount;
        if (vehicle->turnSoundPlaying)
            return;
        if (!(vehicle->flags344 & 0x800))
            return;
        if (vehicle->isDead())
            return;
        if (PlayerTest::GetPlayer() == first || PlayerTest::GetPlayer()->getVehicle() == first)
            vehicle->playHorn();
        return;
    }

    bool firstVehicle = false;
    if (first) {
        if (second) {
            Character* character = 0;
            Vehicle* vehicle = 0;
            bool playerDriving = false;
            int playerFlag = 0;
            int type = LevelObject::s_type[first->getObjectType()];
            if (type == 3) {
                // Dead test (DOM folds it, no code) before the first-object driver block;
                // the address-taken label keeps that block separate, so it keeps the 99%
                // profile share and its cold trace is placed after the second object's.
                if (__builtin_expect(({ struct L { int k; } u = { type }; L t = u; t.k != 3; }), 0))
                    goto secondTypeTest;
                // Second dead test (no code): its 1% edge warms the second object's player
                // arm so its null-base stub precedes the first object's (retail order).
                if (__builtin_expect(({ struct L { int k; } u = { type }; L t = u; t.k != 3; }), 0))
                    goto secondPlayerArm;
                ({
                firstVehicleType:
                    void* const l = &&firstVehicleType;
                    (void)l;
                });
                vehicle = static_cast<Vehicle*>(first);
                if (vehicle->getDriver() == PlayerTest::GetPlayer())
                    playerDriving = true;
            } else if (type == 5) {
                character = static_cast<NPC*>(first);
            } else if (type == 8) {
                character = static_cast<PlayerTest*>(first);
                // The byte copy nests the bool store-flag in a QImode conversion
                // after TER, so it expands into a QI temp and keeps retail's zero-extend.
                const bool flagged = static_cast<PlayerTest*>(character)->unknown372;
                const unsigned char flagByte = flagged;
                playerFlag = flagByte;
            }
        secondTypeTest:
            type = LevelObject::s_type[second->getObjectType()];
            if (type == 3) {
                vehicle = static_cast<Vehicle*>(second);
                if (vehicle->getDriver() == PlayerTest::GetPlayer())
                    playerDriving = true;
            } else if (type == 5) {
                character = static_cast<NPC*>(second);
            } else if (type == 8) {
            secondPlayerArm:
                character = static_cast<PlayerTest*>(second);
                // The byte copy nests the bool store-flag in a QImode conversion
                // after TER, so it expands into a QI temp and keeps retail's zero-extend.
                const bool flagged = static_cast<PlayerTest*>(character)->unknown372;
                const unsigned char flagByte = flagged;
                playerFlag = flagByte;
            }
            if (character && vehicle && vehicle->GetSpeed() > 18.0f && !reinterpret_cast<ContactCharacterView*>(character)->lastHitVehicle
                && !character->isDying() && !character->isDead() && !playerFlag) {
                float speed = sqrtf(point->velocity.x * point->velocity.x + point->velocity.y * point->velocity.y) / 1000.0f * 3600.0f;
                if (speed > 18.0f) {
                    // best is declared before direction so out-of-SSA gives direction the
                    // lower pseudo and the higher stack slot ([sp,#40]) as in retail.
                    float best = 0.0f;
                    int direction = 0;
                    const irr::core::vector3d<float> axis1 = character->GetFront();
                    float dot = irr::core::vector3d<float>(-point->velocity.x, -point->velocity.y, 0.0f).dotProduct(axis1);
                    if (best < dot) {
                        best = dot;
                        direction = 1;
                    }
                    const irr::core::vector3d<float> axis2 = character->GetRight();
                    dot = irr::core::vector3d<float>(-point->velocity.x, -point->velocity.y, 0.0f).dotProduct(axis2);
                    if (best < dot) {
                        best = dot;
                        direction = 3;
                    }
                    const irr::core::vector3d<float> axis3 = character->GetFront();
                    dot = irr::core::vector3d<float>(point->velocity.x, point->velocity.y, 0.0f).dotProduct(axis3);
                    if (best < dot) {
                        best = dot;
                        direction = 0;
                    }
                    const irr::core::vector3d<float> axis4 = character->GetRight();
                    dot = irr::core::vector3d<float>(point->velocity.x, point->velocity.y, 0.0f).dotProduct(axis4);
                    if (best < dot)
                        direction = 2;
                    if (!character->isPlayer())
                        character->SetTarget(vehicle);
                    else
                        Application::GetInstance()->GetControlManager()->lock();
                    character->lastHitVehicle = vehicle;
                    character->hitByCar(direction, speed, vehicle);
                    if (playerDriving && !character->isPlayer() && character->getHealth() <= 0) {
                        // Identical arms (crossjumped after reload, no code): the two hi-register
                        // compares each take a reload, advancing reload's spill-register rotation
                        // by two so the following s_type GOT reloads use retail's registers.
                        if (__builtin_expect(reinterpret_cast<unsigned long>(character) > 1 && reinterpret_cast<unsigned long>(vehicle) > 1, 0))
                            PlayerTest::GetPlayer()->onObjectKilled(character);
                        else
                            PlayerTest::GetPlayer()->onObjectKilled(character);
                    }
                }
            }
        }
        if (LevelObject::s_type[first->getObjectType()] == 3) {
            float dot = -point->velocity.x * point->normal.x + -point->velocity.y * point->normal.y;
            static_cast<Vehicle*>(first)->collision(irr::core::vector3d<float>(point->normal.x * dot, point->normal.y * dot, 0.0f), ({
                int otherType;
                if (second) {
                stypeArm:
                    otherType = LevelObject::s_type[second->getObjectType()];
                } else {
                    otherType = -1;
                }
                // Taking the s_type arm's address keeps its label used, so CSE paths stop there as in retail.
                void* const l = &&stypeArm;
                (void)l;
                otherType;
            }));
            firstVehicle = true;
        }
    }
    if (second && LevelObject::s_type[second->getObjectType()] == 3) {
        // The collision target is a merge: on the first-pair path it is the
        // player's vehicle just proven equal to second (retail keeps the copy).
        Vehicle* secondVehicle;
        if (!firstVehicle) {
            secondVehicle = static_cast<Vehicle*>(second);
        } else {
            // Each arm restores the collision target to second on entry; the
            // raise path carries the proven-equal vehicle in its own variable.
            PlayerTest* player = PlayerTest::GetPlayer();
            Vehicle* hit;
            // The address-taken label (no code) starts the getVehicle call block after the
            // edge from the metatype test, so the call heuristic leaves that edge at 29%.
            if ((first->GetMetatype() == 38 ? ((secondVehicle = static_cast<Vehicle*>(second)), ({ raiseHit: void* const l = &&raiseHit; (void)l; }), (hit = player->getVehicle()) == second)
                                             : ((secondVehicle = static_cast<Vehicle*>(second)), false))
                || (second->GetMetatype() == 38 && first == player->getVehicle() && ((hit = secondVehicle), true))) {
                // Identical call arms (merged after reload, no code) give the
                // arm1-entry target a use on the raise path, so sink keeps it there.
                if (secondVehicle)
                    Application::GetInstance()->GetEventManager()->raise(EvPlayer(4));
                else
                    Application::GetInstance()->GetEventManager()->raise(EvPlayer(4));
                secondVehicle = hit;
            }
        }
        float dot = point->normal.x * point->velocity.x + point->normal.y * point->velocity.y;
        secondVehicle->collision(irr::core::vector3d<float>(point->normal.x * dot, point->normal.y * dot, 0.0f),
            first ? LevelObject::s_type[first->getObjectType()] : -1);
        // The vehicle path keeps its own first-object test (retail lays it out
        // after the second collision and falls into the lone-second NPC check).
        ({
        // Taking this label's address ends the collision block here, so the
        // first-object arms are not threaded through the call.
        lonePairTest:
            void* const l = &&lonePairTest;
            (void)l;
        });
        if (first)
            return;
    }
    if (!second) {
        if (first) {
            const int firstType = LevelObject::s_type[first->getObjectType()];
            if (firstType == 5) {
                NPC* npc = static_cast<NPC*>(first);
                ContactNpcView* view = reinterpret_cast<ContactNpcView*>(npc);
                // Branch hints only (no code): they lift this block's REG_FREQ so global
                // allocation orders side.X, the X*500 product and side.Y as retail (r7/r8/sl).
                if ((IsCategory(view->category428, 0) || __builtin_expect(IsCategory(view->category428, 1), 0) || __builtin_expect(IsCategory(view->category428, 2), 1)) && !npc->getPathToFollow()) {
                    irr::core::vector3d<float> side(point->normal.y, -point->normal.x, 0.0f);
                    // Two dead tests (DOM folds them, no code; firstType is 5 here): their 1%
                    // profile edges give the cold negation stub frequency 3, so it leads the
                    // tail stubs as in retail without changing any REG_FREQ bucket.
                    if (__builtin_expect(({ struct L { int k; } u = { firstType }; L t = u; t.k != 5; }), 0))
                        goto firstSideFlip;
                    if (__builtin_expect(({ struct L { int k; } u = { firstType }; L t = u; t.k != 5; }), 0))
                        goto firstSideFlip;
                    // Branch hint only (no code): the cold negation stubs are laid out in retail order.
                    if (__builtin_expect(side.dotProduct(npc->GetFront()) < 0.0f, 0)) {
                    firstSideFlip:
                        side = -side;
                    }
                    npc->setDestination(npc->GetPosition() + side * 500.0f, 100);
                    if (view->flags356 & 4)
                        npc->Character::runToLocation(irr::core::vector3d<float>(view->destination));
                }
            }
        }
    } else if (!first) {
            // Reading the type through NPC* gives PRE a different load, so it is recomputed (retail).
            if (LevelObject::s_type[static_cast<NPC*>(second)->getObjectType()] == 5) {
                NPC* npc = static_cast<NPC*>(second);
                ContactNpcView* view = reinterpret_cast<ContactNpcView*>(npc);
                if ((IsCategory(view->category428, 0) || IsCategory(view->category428, 1) || IsCategory(view->category428, 2)) && !npc->getPathToFollow()) {
                    irr::core::vector3d<float> side(point->normal.y, -point->normal.x, 0.0f);
                    // Branch hint only (no code): the cold negation stubs are laid out in retail order.
                    if (__builtin_expect(side.dotProduct(npc->GetFront()) < 0.0f, 0))
                        side = -side;
                    npc->setDestination(npc->GetPosition() + side * 500.0f, 100);
                    if (view->flags356 & 4)
                        npc->Character::runToLocation(irr::core::vector3d<float>(view->destination));
                }
            }
    }
}
