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

PhysicInfo::PhysicInfo()
{
    unknown64.Z = 999999.0f;
    for (int i = 0; i < 12; ++i)
        bodies[i] = 0;
    Reset(0);
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
    jumpCenter = (jumpVertices[0] + jumpVertices[1] + jumpVertices[2] + jumpVertices[3]) * 0.25f;
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
