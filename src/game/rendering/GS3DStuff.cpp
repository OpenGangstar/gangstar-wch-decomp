/*
 * GS3DStuff
 *
 * Original file: GS3DStuff.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GS3DStuff.cpp here, in the order they appear in the library.
 */

#include "GS3DStuff.h"
#include "../scripting/ScriptManager.h"
#include "../meta/Race.h"
#include "../input/CControlManager.h"
#include "../characters/Character.h"
#include "../world/SceneNodeManager.h"
#include "../hud/MiniMap.h"
#include "../core/CameraManager.h"
#include "../characters/PhysicAttributes.h"
#include "../world/TrailMgr.h"
#include "../combat/WeaponManager.h"
#include "../app/GSLoading.h"
#include "../meta/Item.h"
#include "../ui/Shop.h"
#include "../vehicles/Vehicle.h"
#include "LODSceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/MeshBufferInterfaces.h"
#include "../core/MeshSceneInterfaces.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../app/CGameFactory.h"
#include "../world/MapSingleton.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "CustomBillboardSceneNode.h"
#include "CustomSkyBoxSceneNode.h"
#include "../core/NativeStdio.h"
#include "../core/NativeStrings.h"
#include "../core/PlacementNew.h"
#include "../core/PointerVector.h"
#include "../core/Lock.h"
#include "../app/Application.h"
#include "../persistence/DataStream.h"
#include "../input/TouchScreenBase.h"
#include "../audio/SoundManager.h"
#include "../characters/PlayerTest.h"
#include "../hud/CHudManager.h"
#include "../core/EventManager.h"
#include "../ai/AIManagerSingleton.h"
#include "../core/SafeDelete.h"
#include "../core/PhysicsBodyDef.h"
#include "../core/Geometry.h"
#include "../core/FactoryProducts.h"
#include "../core/VideoDriver.h"
#include "../world/SpawnPoint.h"
#include "../world/GameObjectManager.h"
#include "../world/LevelObject.h"
#include "../world/ResStream.h"
#include "../world/World.h"
#include "../world/WorldDescriptor.h"

// Altered Box2D 2.0.1 b2ShapeDef/b2PolygonDef inline definition excerpt
// (Copyright (c) 2006-2007 Erin Catto, zlib licence), corroborated by retail stores.
enum b2ShapeType { e_unknownShape = -1, e_circleShape, e_polygonShape, e_shapeTypeCount };
class b2ShapeDef {
public:
    b2ShapeDef()
    {
        type = e_unknownShape;
        userData = 0;
        friction = 0.2f;
        restitution = 0.0f;
        density = 0.0f;
        filter.categoryBits = 0x0001;
        filter.maskBits = 0xFFFF;
        filter.groupIndex = 0;
        isSensor = false;
    }
    virtual ~b2ShapeDef() {}
    b2ShapeType type;
    void* userData;
    float friction;
    float restitution;
    float density;
    bool isSensor;
    b2FilterData filter;
};

class b2PolygonDef : public b2ShapeDef {
public:
    b2PolygonDef() { type = e_polygonShape; vertexCount = 0; }
    virtual ~b2PolygonDef() __attribute__((used)) {}
    b2Vec2 vertices[8];
    int vertexCount;
};

class CollisionBodyDef {
public:
    inline CollisionBodyDef() __attribute__((used));
    inline ~CollisionBodyDef();

private:
    friend class OctTreeAABB;
    irr::core::array<b2Body*>* bodies;
    irr::core::array<b2BodyDef*>* bodyDefinitions;
    irr::core::array<b2PolygonDef*>* polygonDefinitions;
    bool inQueryResults;
    bool unknown13;
    int references;
};

class OctTreeAABB {
public:
    struct RootNode {
        RootNode() : sceneNode(0), collision(0), spawn(0),
            bounds(irr::core::vector3d<float>(-1.0f, -1.0f, -1.0f))
        {
            bounds.MaxEdge = irr::core::vector3d<float>(1.0f, 1.0f, 1.0f);
        }
        inline ~RootNode();
        irr::scene::ISceneNode* sceneNode;
        CollisionBodyDef* collision;
        SpawnPoint* spawn;
        irr::core::aabbox3d<float> bounds;
    };

    struct OctTreeAABBNode {
        inline OctTreeAABBNode(int& nodeId, int depth, irr::core::array<RootNode*>* roots,
            unsigned int maxDepth, irr::core::aabbox3d<float> bounds) __attribute__((used));
        inline ~OctTreeAABBNode();
        void getPolysIter(const irr::core::aabbox3d<float>& box,
            irr::core::array<CollisionBodyDef*>* collisions, irr::core::array<SpawnPoint*>* spawns,
            irr::core::array<irr::scene::ISceneNode*>* nodes) const __attribute__((weak));
        irr::core::aabbox3d<float> bounds;
        irr::core::array<RootNode*>* roots;
        OctTreeAABBNode* children[8];
        int depth;
    };

    OctTreeAABB(irr::scene::ISceneNode* node, unsigned int maxDepth);
    inline ~OctTreeAABB();
    inline void BuildSpawnPointNodes(irr::core::array<RootNode*>* roots) __attribute__((used));
    inline int CountRenderableNodes(irr::scene::ISceneNode* node) __attribute__((used));
    inline void BuildRootNodes(irr::scene::ISceneNode* node,
        irr::core::array<RootNode*>* roots) __attribute__((used));
    inline void calculatePolys(const irr::core::aabbox3d<float>& box,
        irr::core::array<CollisionBodyDef*>* collisions, irr::core::array<SpawnPoint*>* spawns,
        irr::core::array<irr::scene::ISceneNode*>* nodes) __attribute__((used));
private:
    OctTreeAABBNode* root;
    irr::core::array<RootNode*>* roots;
    int nodeId;
    int nodeCount;
};

namespace {
template<class T>
inline __attribute__((always_inline)) void safeDeletePointerArray(irr::core::array<T*>*& array)
{
    irr::core::array<T*>* storage = array;
    if (storage) {
        if (storage->free_when_destroyed)
            ::operator delete(storage->data);
        delete storage;
    }
    array = 0;
}

template<class T>
inline __attribute__((always_inline)) irr::core::array<T*>* newPointerArray()
{
    irr::core::array<T*>* array = new irr::core::array<T*>;
    array->data = 0;
    array->allocated = 0;
    array->used = 0;
    array->free_when_destroyed = true;
    array->is_sorted = true;
    array->unknown16 = 1;
    return array;
}

template<class T>
inline void clearPointerArray(irr::core::array<T*>& array)
{
    ::operator delete(array.data);
    array.data = 0;
    array.used = 0;
    array.allocated = 0;
    array.is_sorted = true;
}
}

template<> void SafeDelete(irr::core::array<irr::scene::ISceneNode*>*& array) __attribute__((weak));
template<> void SafeDelete(irr::core::array<irr::scene::ISceneNode*>*& array)
{
    safeDeletePointerArray(array);
}

template<> void SafeDelete(irr::core::array<b2PolygonDef*>*& array) __attribute__((weak));
template<> void SafeDelete(irr::core::array<b2PolygonDef*>*& array)
{
    safeDeletePointerArray(array);
}

template<> void SafeDelete(irr::core::array<b2BodyDef*>*& array) __attribute__((weak));
template<> void SafeDelete(irr::core::array<b2BodyDef*>*& array)
{
    safeDeletePointerArray(array);
}

template<> void SafeDelete(irr::core::array<b2Body*>*& array) __attribute__((weak));
template<> void SafeDelete(irr::core::array<b2Body*>*& array)
{
    safeDeletePointerArray(array);
}

template<> void SafeDelete(irr::core::array<CollisionBodyDef*>*& array) __attribute__((weak));
template<> void SafeDelete(irr::core::array<CollisionBodyDef*>*& array)
{
    safeDeletePointerArray(array);
}

namespace {
struct OctTreeQueryFrame {
    const OctTreeAABB::OctTreeAABBNode* node;
    int child;
    int mode;
};

inline bool nextOctTreeQueryNode(OctTreeQueryFrame* frames, int& depth,
    const OctTreeAABB::OctTreeAABBNode*& node, int& mode)
{
    while (depth > 0) {
        OctTreeQueryFrame& frame = frames[--depth];
        if (frame.child <= 6) {
            ++frame.child;
            mode = frame.mode;
            node = frame.node->children[frame.child];
            ++depth;
            if (node)
                return true;
        }
    }
    return false;
}

// Copy of nextOctTreeQueryNode used at one call site only (keeps the
// aliased-vop count below alias grouping, which would block the store sink).
inline bool nextOctTreeQueryNodeHinted(OctTreeQueryFrame* frames, int& depth,
    const OctTreeAABB::OctTreeAABBNode*& node, int& mode)
{
    while (depth > 0) {
        OctTreeQueryFrame& frame = frames[--depth];
        // No-code hint: two in-bounds byte loads from this frame (first byte of
        // .node and of .mode; unsigned char may alias any object) that are live
        // across the child test and only feed the identical-arm test below. They take r1/r0 in greg, so the
        // shared frames-base pseudo conflicts with r0 and gets retail's r6
        // (depth*2 then gets r0). Crossjump deletes the test; the loads die.
        const int x = reinterpret_cast<const unsigned char*>(&frame)[0];
        const int y = reinterpret_cast<const unsigned char*>(&frame)[8];
        if (frame.child <= 6) {
            int c;
            // Identical arms: merged after reload, so the test emits no code.
            if (x == y) c = ++frame.child; else c = ++frame.child;
            mode = frame.mode;
            node = frame.node->children[c];
            ++depth;
            if (node)
                return true;
        }
    }
    return false;
}
}

// Shift indexing keeps retail's index-first address operand order.
inline OctTreeAABB::RootNode* rootAt(OctTreeAABB::RootNode* const* data, int i)
{
    return *reinterpret_cast<OctTreeAABB::RootNode* const*>(
        (i << 2) + reinterpret_cast<int>(data));
}


// Byte-pointer form for the null-collision branch: reassoc leaves pointer
// arithmetic alone, so PRE's base-first insertion survives at the spawn reload.
inline OctTreeAABB::RootNode* rootAtF1(OctTreeAABB::RootNode* const* data, int i)
{ return *reinterpret_cast<OctTreeAABB::RootNode* const*>(reinterpret_cast<const char*>(data) + (i << 2)); }


namespace {
// Inlined box predicates; inlining remaps their temporaries (spill-slot order).
inline bool boxesTouch(const irr::core::aabbox3d<float>& a, const irr::core::aabbox3d<float>& b)
{
    return a.MinEdge.X <= b.MaxEdge.X && a.MinEdge.Y <= b.MaxEdge.Y && a.MinEdge.Z <= b.MaxEdge.Z &&
           a.MaxEdge.X >= b.MinEdge.X && a.MaxEdge.Y >= b.MinEdge.Y && a.MaxEdge.Z >= b.MinEdge.Z;
}
inline bool boxContains(const irr::core::aabbox3d<float>& box, const irr::core::aabbox3d<float>& b)
{
    return box.MinEdge.X <= b.MinEdge.X && box.MinEdge.Y <= b.MinEdge.Y && box.MinEdge.Z <= b.MinEdge.Z &&
           box.MaxEdge.X >= b.MaxEdge.X && box.MaxEdge.Y >= b.MaxEdge.Y && box.MaxEdge.Z >= b.MaxEdge.Z;
}
}

void OctTreeAABB::OctTreeAABBNode::getPolysIter(
    const irr::core::aabbox3d<float>& box,
    irr::core::array<CollisionBodyDef*>* collisions,
    irr::core::array<SpawnPoint*>* spawns,
    irr::core::array<irr::scene::ISceneNode*>* nodes) const
{
    OctTreeQueryFrame frames[10];
    int depth = 0;
    const OctTreeAABBNode* node = this;
    int mode = 0;
    do {
    top:
        if (mode != 2) {
            if (!(boxesTouch(node->bounds, box))) {
                if (nextOctTreeQueryNodeHinted(frames, depth, node, mode))
                    goto top;
                return;
            }
            mode = box.MinEdge.X <= bounds.MinEdge.X &&
                   box.MinEdge.Y <= bounds.MinEdge.Y &&
                   box.MinEdge.Z <= bounds.MinEdge.Z &&
                   box.MaxEdge.X >= bounds.MaxEdge.X &&
                   box.MaxEdge.Y >= bounds.MaxEdge.Y &&
                   box.MaxEdge.Z >= bounds.MaxEdge.Z ? 2 : 1;
        }
        if (node->roots) {
            const irr::core::array<RootNode*>* roots = node->roots;
            const int count = static_cast<int>(roots->used);
            for (int i = 0; i < count; ++i) {
                CollisionBodyDef* collision = rootAt(roots->data, i)->collision;
                if (collision) {
                    if (collision->inQueryResults)
                        continue;
                    collisions->push_back(collision);
                    if (rootAt(roots->data, i)->sceneNode)
                        nodes->push_back(rootAt(roots->data, i)->sceneNode);
                    collision->inQueryResults = true;
                } else {
                    if (rootAtF1(roots->data, i)->sceneNode)
                        nodes->push_back(rootAtF1(roots->data, i)->sceneNode);
            /* no-code: always-false object-size test, folded by objsz and removed by
               store_ccp before PRE; shifts SSA-name recycling so PRE builds the
               spawn reload base-first like retail. */
            if (__builtin_object_size(&frames[depth], 0) == 0) { mode = 1; }
                    if (rootAtF1(roots->data, i)->spawn)
                        spawns->push_back(rootAtF1(roots->data, i)->spawn);
                }
            }
            if (nextOctTreeQueryNode(frames, depth, node, mode))
                goto top;
            return;
        } else {
            frames[depth].node = node;
            frames[depth].mode = mode;
            // Re-read of the value just stored: RTL CSE turns it into a separate
            // parent copy, so the loaded child keeps node's register and ivopts
            // picks retail's child counter plus &children[1] pointer IV.
            const OctTreeAABBNode* const parent = frames[depth].node;
            int child = 0;
            node = parent->children[0];
            while (!node) {
                ++child;
                if (child == 8)
                    break;
                node = parent->children[child];
            }
            if (node) {
                frames[depth++].child = child;
            } else if (nextOctTreeQueryNode(frames, depth, node, mode)) {
                goto top;
            } else {
                return;
            }
        }
    } while (depth > 0);
}


template<> void SafeDelete(irr::core::array<SpawnPoint*>*& array) __attribute__((weak));
template<> void SafeDelete(irr::core::array<SpawnPoint*>*& array)
{
    safeDeletePointerArray(array);
}

template<> void SafeDelete(irr::core::array<OctTreeAABB::RootNode*>*& array) __attribute__((weak));
template<> void SafeDelete(irr::core::array<OctTreeAABB::RootNode*>*& array)
{
    safeDeletePointerArray(array);
}

CollisionBodyDef::CollisionBodyDef()
    : bodies(newPointerArray<b2Body>()), bodyDefinitions(newPointerArray<b2BodyDef>()),
      polygonDefinitions(newPointerArray<b2PolygonDef>()), inQueryResults(false), unknown13(false),
      references(1)
{
}

CollisionBodyDef::~CollisionBodyDef()
{
    if (--references == 0) {
        for (int i = 0; static_cast<unsigned int>(i) < bodyDefinitions->used; ++i) {
            b2BodyDef* definition = bodyDefinitions->data[i];
            if (definition->userData) {
                ::operator delete(definition->userData);
                definition->userData = 0;
            }
            b2BodyDef*& entry = bodyDefinitions->data[i];
            if (entry)
                delete entry;
            entry = 0;
        }
        for (int i = 0; static_cast<unsigned int>(i) < polygonDefinitions->used; ++i) {
            b2PolygonDef*& entry = polygonDefinitions->data[i];
            delete entry;
            entry = 0;
        }

        SafeDelete(bodies);
        SafeDelete(bodyDefinitions);
        SafeDelete(polygonDefinitions);
    }
}

template void SafeDelete<CollisionBodyDef>(CollisionBodyDef*&);

void GS3DStuff::freeGameData(irr::scene::ISceneNode* node)
{
    CollisionBodyDef* data = static_cast<CollisionBodyDef*>(node->getGameData());
    if (data) {
        SafeDelete(data);
        node->setGameData(0);
    }
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        freeGameData(child->value);
    }
}

OctTreeAABB::RootNode::~RootNode()
{
    SafeDelete(collision);
    delete spawn;
    spawn = 0;
}

OctTreeAABB::OctTreeAABBNode::~OctTreeAABBNode()
{
    for (unsigned int i = 0; i < 8; ++i)
        delete children[i];
    SafeDelete(roots);
}

template void SafeDelete<OctTreeAABB::RootNode>(OctTreeAABB::RootNode*&);
template void SafeDelete<OctTreeAABB::OctTreeAABBNode>(OctTreeAABB::OctTreeAABBNode*&);

OctTreeAABB::~OctTreeAABB()
{
    SafeDelete(root);
    for (int i = 0; static_cast<unsigned int>(i) < roots->used; ++i)
        SafeDelete(roots->data[i]);
    clearPointerArray(*roots);
    SafeDelete(roots);
}

template void SafeDelete<OctTreeAABB>(OctTreeAABB*&);

namespace {
template<class Value>
inline __attribute__((always_inline)) void applyToChildren(irr::scene::ISceneNode* node,
    void (*apply)(irr::scene::ISceneNode*, Value), Value value)
{
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        apply(child->value, value);
    }
}

template<class First, class Second>
inline __attribute__((always_inline)) void applyToChildren(irr::scene::ISceneNode* node,
    void (*apply)(irr::scene::ISceneNode*, First, Second), First first, Second second)
{
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        apply(child->value, first, second);
    }
}
}

void GS3DStuff::SetVisibility(irr::scene::ISceneNode* node, bool visible)
{
    if (node->getMaterialCount())
        node->setVisible(visible);

    applyToChildren(node, SetVisibility, visible);
}

void GS3DStuff::SetCulling(irr::scene::ISceneNode* node, irr::scene::E_CULLING_TYPE type)
{
    node->setAutomaticCulling(type);

    applyToChildren(node, SetCulling, type);
}

void GS3DStuff::SetMaterialType(irr::scene::ISceneNode* node, irr::video::E_MATERIAL_TYPE type)
{
    if (node->getMaterialCount()) {
        node->setMaterialType(type);
        node->notifyMaterialChanged();
    }

    applyToChildren(node, SetMaterialType, type);
}

void GS3DStuff::SetMaterialFlag(irr::scene::ISceneNode* node, irr::video::E_MATERIAL_FLAG flag, bool enabled)
{
    if (node->getMaterialCount())
        node->setMaterialFlag(flag, enabled);

    applyToChildren(node, SetMaterialFlag, flag, enabled);
}

void GS3DStuff::SetMaterialTexture(irr::scene::ISceneNode* node, irr::video::ITexture* texture)
{
    if (node->getMaterialCount())
        node->setMaterialTexture(0, texture);

    applyToChildren(node, SetMaterialTexture, texture);
}

namespace {
const int colladaMeshNode = 0x6d656164;
const int colladaSkinnedNode = 0x73656164;
const int lodNode = 0x6e646f6c;
const char planeNodeMarker[] = "Plane";
const char jumpNodeMarker[] = "Jump";
const char pivotNodeMarker[] = "_PIVOT";
}

void OctTreeAABB::BuildSpawnPointNodes(irr::core::array<RootNode*>* roots)
{
    for (SpawnPointList::Node* entry = SpawnPoint::s_spawnPoints.head; entry; entry = entry->next) {
        SpawnPoint* spawn = entry->value;
        roots->push_back(new RootNode);
        RootNode* root = roots->data[roots->used - 1];
        root->spawn = spawn;
        root->bounds.MaxEdge = spawn->getPosition();
        root->bounds.MinEdge = spawn->getPosition();
    }
}

int OctTreeAABB::CountRenderableNodes(irr::scene::ISceneNode* node)
{
    const int type = node->getType();
    int count = type == colladaMeshNode || type == colladaSkinnedNode || type == lodNode;
    if (node->getType() != lodNode) {
        for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
             child != node->getChildren().end(); child = child->next) {
            count += CountRenderableNodes(child->value);
        }
    }
    return count;
}

void OctTreeAABB::BuildRootNodes(irr::scene::ISceneNode* node, irr::core::array<RootNode*>* roots)
{
    node->updateAbsolutePosition(false);
    irr::scene::SceneNodeList::Node* child = node->getChildren().begin();

    char value[256];
    if (GS3DStuff::getProperty(node->getUserProperty(), GameFactoryProperties::billboard, value) &&
        atoi(value) == 1) {
        roots->push_back(new RootNode);
        RootNode* root = roots->data[roots->used - 1];
        CollisionBodyDef* collision = static_cast<CollisionBodyDef*>(node->getGameData());
        root->sceneNode = node;
        root->collision = collision;
        node->setVisible(false);
        root->bounds = node->getTransformedBoundingBox();
        irr::scene::ISceneNode* parent = node->getParent();
        Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(node);
        if (parent)
            CCustomSceneManager::CleanParents(parent);
        return;
    }

    if (node->getType() == colladaMeshNode || node->getType() == colladaSkinnedNode ||
        node->getType() == lodNode) {
        roots->push_back(new RootNode);
        RootNode* root = roots->data[roots->used - 1];
        root->collision = static_cast<CollisionBodyDef*>(node->getGameData());
        node->setVisible(false);
        root->bounds = node->getTransformedBoundingBox();
        node->SetOption(irr::scene::SceneOption1, node->getAnimators().getSize() == 0);
    }

    while (child != node->getChildren().end()) {
        irr::scene::ISceneNode* current = child->value;
        child = child->next;
        BuildRootNodes(current, roots);
    }
}

void OctTreeAABB::calculatePolys(const irr::core::aabbox3d<float>& box,
    irr::core::array<CollisionBodyDef*>* collisions, irr::core::array<SpawnPoint*>* spawns,
    irr::core::array<irr::scene::ISceneNode*>* nodes)
{
    if (collisions) {
        for (int i = 0; static_cast<unsigned int>(i) < collisions->used; ++i) {
            CollisionBodyDef* collision = collisions->data[i];
            if (collision)
                collision->inQueryResults = false;
        }
        collisions->used = 0;
    }
    if (spawns)
        spawns->used = 0;
    if (nodes)
        nodes->used = 0;
    root->getPolysIter(box, collisions, spawns, nodes);
}

irr::scene::ISceneNode* GS3DStuff::FindAMesh(irr::scene::ISceneNode* node)
{
    node->updateAbsolutePosition(false);
    if ((node->getType() == colladaMeshNode || node->getType() == colladaSkinnedNode) &&
        !strstr(node->getUID(), planeNodeMarker) && !strstr(node->getUID(), jumpNodeMarker)) {
        return node;
    }

    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        irr::scene::ISceneNode* mesh = FindAMesh(child->value);
        if (mesh)
            return mesh;
    }
    return 0;
}

void GS3DStuff::CleanNode(irr::scene::ISceneNode* node)
{
    if (!node)
        return;

    const irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
    while (child != node->getChildren().end()) {
        irr::scene::ISceneNode* childNode = child->value;
        child = child->next;
        CleanNode(childNode);
    }

    if (strstr(node->getName(), pivotNodeMarker)) {
        const irr::scene::SceneNodeList::Node* first = node->getChildren().begin();
        if (first == node->getChildren().end())
            node->remove();
    }
}

void GS3DStuff::AddRenderables(irr::scene::ISceneNode* node,
    irr::core::array<irr::scene::ISceneNode*>& renderables, irr::scene::ESCENE_NODE_TYPE type)
{
    if (!node)
        return;

    if (node->getType() == type)
        renderables.push_back(node);
    if (type == irr::scene::ESNT_ANY) {
        node->setVisible(true);
        renderables.push_back(node);
    }

    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        AddRenderables(child->value, renderables, type);
    }
}

namespace {
const char nodeTypeFormat[] __attribute__((section(".rodata.gs_node_type_format"))) = "Node->getType(): %c%c%c%c\n";
const char leafTypeFormat[] __attribute__((section(".rodata.gs_leaf_type_format"))) = "LEAF: %c%c%c%c\n";
const char indentation[] __attribute__((section(".rodata.gs_indent"))) = "  ";

}

/* STLport-derived inline structure, adapted to observed ARM32 char policy.
 * Copyright (c) 1994 Hewlett-Packard Company
 * Copyright (c) 1996,1997 Silicon Graphics Computer Systems, Inc.
 * Copyright (c) 1997 Moscow Center for SPARC Technology
 * Copyright (c) 1999 Boris Fomitchev
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 * Permission to use or copy this software for any purpose is hereby granted
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 * Modified: char-only private view; retain native allocation/append bindings
 * and observed operator-delete policy, without reconstructing allocators.
 */
#include "../core/NativeAllocator.h"
namespace {
class NativeIndentBase;
class NativeIndent;
}
extern "C" {
void _ZN9stlp_priv12_String_baseIcSaIcEE17_M_allocate_blockEj(NativeIndentBase*, unsigned int)
    __attribute__((weak));
void _ZNSs6appendEPKc(NativeIndent*, const char*) __attribute__((weak));
}
namespace {
class NativeIndentProxy : public std::allocator<char> {
public:
    char* _M_data;
    NativeIndentProxy(const std::allocator<char>& allocator, char* end)
        : std::allocator<char>(allocator), _M_data(end) {}
};
class NativeIndentBase {
    union Buffers { char* _M_dynamic_buf; char _M_static_buf[16]; } _M_buffers;
protected:
    char* _M_finish;
    NativeIndentProxy _M_end_of_storage;
    bool _M_using_static_buf() const {
        return _M_end_of_storage._M_data == _M_buffers._M_static_buf + 16;
    }
    void _M_deallocate_block() {
        if (!_M_using_static_buf() && _M_buffers._M_dynamic_buf != 0)
            ::operator delete(_M_buffers._M_dynamic_buf);
    }
    NativeIndentBase(const std::allocator<char>& allocator, unsigned int n)
        : _M_finish(_M_buffers._M_static_buf),
          _M_end_of_storage(allocator, _M_buffers._M_static_buf + 16) {
        _ZN9stlp_priv12_String_baseIcSaIcEE17_M_allocate_blockEj(this, n);
    }
    ~NativeIndentBase() { _M_deallocate_block(); }
    void _M_destroy_range() { /* char has trivial destruction */ }
public:
    static void verifyLayout() {
        typedef char Size[sizeof(NativeIndentBase)==24?1:-1];
        typedef char Alignment[__alignof__(NativeIndentBase)==4?1:-1];
        typedef char Finish[__builtin_offsetof(NativeIndentBase,_M_finish)==16?1:-1];
        typedef char End[__builtin_offsetof(NativeIndentBase,_M_end_of_storage)==20?1:-1];
        typedef char UnionSize[sizeof(Buffers)==16?1:-1];
        typedef char ProxySize[sizeof(NativeIndentProxy)==4?1:-1];
    }
};
class NativeIndent : protected NativeIndentBase {
    void _M_terminate_string() { *_M_finish = 0; }
public:
    explicit NativeIndent(const std::allocator<char>& allocator = std::allocator<char>())
        : NativeIndentBase(allocator, 16) { _M_terminate_string(); }
    ~NativeIndent() { _M_destroy_range(); }
};
typedef char DerivedSize[sizeof(NativeIndent)==24?1:-1];
typedef char DerivedAlignment[__alignof__(NativeIndent)==4?1:-1];
}

int GS3DStuff::PrintNodeProperties(irr::scene::ISceneNode* node, bool recursive, int depth)
{
    int count = 0;
    if (node->getType() == 0x79746d65 || node->getType() == 0x796d6d64 ||
        node->getType() == 0x6e656164 || node->getType() == 0x72676d73) {
        count = 1;
    } else {
        printf(nodeTypeFormat, static_cast<unsigned char>(node->getType()),
            (static_cast<unsigned int>(node->getType()) << 16 >> 24),
            (static_cast<unsigned int>(node->getType()) << 8 >> 24),
            (static_cast<unsigned int>(node->getType()) >> 24));
        count = 0;
    }

    irr::scene::SceneNodeList::Node* first = node->getChildren().begin();
    if (first == node->getChildren().end() &&
        node->getType() != 0x6d656164 && node->getType() != 0x73656164) {
        printf(leafTypeFormat, static_cast<unsigned char>(node->getType()),
            (static_cast<unsigned int>(node->getType()) << 16 >> 24),
            (static_cast<unsigned int>(node->getType()) << 8 >> 24),
            (static_cast<unsigned int>(node->getType()) >> 24));
    }

    NativeIndent indent;
    for (int index = 0; index < depth; ++index)
        _ZNSs6appendEPKc(&indent, indentation);

    if (recursive) {
        for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
             child != node->getChildren().end(); child = child->next)
            count += PrintNodeProperties(child->value, true, depth + 1);
    }
    return count;
}

void GS3DStuff::setSkyColor(bool enabled)
{
    static_cast<CustomSkyBoxSceneNode*>(skyBox)->setSkyColor(enabled);
}

void GS3DStuff::SetMaterialTypeCondition(irr::scene::ISceneNode* node,
    irr::video::E_MATERIAL_TYPE type, irr::video::ITexture* texture)
{
    for (unsigned int i = 0; i < node->getMaterialCount(); ++i) {
        if (node->getMaterial(i).layers[0].texture == texture) {
            node->getMaterial(i).setType(type);
            node->notifyMaterialChanged();
        }
    }

    applyToChildren(node, SetMaterialTypeCondition, type, texture);
}

void GS3DStuff::SetMaterial(irr::scene::ISceneNode* node, irr::video::SMaterial* material)
{
    for (int i = 0; static_cast<unsigned int>(i) < node->getMaterialCount(); ++i)
        node->getMaterial(i) = *material;

    applyToChildren(node, SetMaterial, material);
}
#include "../combat/Explosion.h"
#include "../combat/BulletTraceManager.h"

class b2BodyDef;
extern "C" {
extern irr::scene::ISceneNode* _ZN9Character13m_bloodSplashE;
void _ZN7b2World11DestroyBodyEP6b2Body(b2World* world, b2Body* body);
b2Body* _ZN7b2World10CreateBodyEPK9b2BodyDef(b2World* world, const b2BodyDef* definition);
void* _ZN6b2Body11CreateShapeEP10b2ShapeDef(b2Body* body, b2ShapeDef* definition);
}

namespace {
const irr::scene::ESCENE_NODE_TYPE visibilityColladaMesh = static_cast<irr::scene::ESCENE_NODE_TYPE>(0x6d656164);
const irr::scene::ESCENE_NODE_TYPE visibilityColladaSkin = static_cast<irr::scene::ESCENE_NODE_TYPE>(0x73656164);
const irr::scene::ESCENE_NODE_TYPE visibilitySkyBox = static_cast<irr::scene::ESCENE_NODE_TYPE>(0x5f796b73);
const irr::scene::ESCENE_NODE_TYPE visibilityUnknown = static_cast<irr::scene::ESCENE_NODE_TYPE>(0x6e6b6e75);

struct VisibilityFrustumView {
    unsigned char planes[108];
    irr::core::aabbox3d<float> boundingBox;
};

struct VisibilityCollisionView {
    irr::core::array<b2Body*>* bodies;
    irr::core::array<b2BodyDef*>* bodyDefinitions;
    irr::core::array<b2ShapeDef*>* shapeDefinitions;
    bool inQueryResults;
    bool active;
};

struct VisibilityWeaponView {
    unsigned char unknown0[68];
    irr::scene::ISceneNode* node;
};

struct VisibilityObjectView {
    unsigned char unknown0[16];
    irr::scene::ISceneNode* sceneNode;
    irr::scene::ISceneNode* shadowNode;
    unsigned char unknown24[60];
    CustomBillboardSceneNode* itemBillboard;
    unsigned char unknown88[88];
    irr::scene::ISceneNode* vehicleNode;
    unsigned char unknown180[492];
    irr::scene::ISceneNode* characterNode;
    unsigned char unknown676[120];
    VisibilityWeaponView* weapons[4];
    unsigned char unknown812[4];
    irr::scene::ISceneNode* characterNode816;
    unsigned char unknown820[76];
    irr::scene::ISceneNode* characterNode896;
};

inline irr::scene::ISceneNode* visibilityNodeAt(const void* object, int offset)
{
    return *reinterpret_cast<irr::scene::ISceneNode* const*>(static_cast<const char*>(object) + offset);
}

inline irr::scene::ISceneNode* visibilityBillboardAt(const void* object, int offset)
{
    CustomBillboardSceneNode* billboard =
        *reinterpret_cast<CustomBillboardSceneNode* const*>(static_cast<const char*>(object) + offset);
    return billboard;
}

inline irr::core::array<irr::scene::ISceneNode*>& visibilityRenderables(CCustomSceneManager* manager)
{
    // The named locals are inlined into every call; the extra declarations keep
    // checkVehicleProximity's retail stack-slot order later in this file.
    CCustomSceneManager* sceneManager = manager;
    void* list = sceneManager->getRenderableNodeList();
    irr::core::array<irr::scene::ISceneNode*>* nodes = static_cast<irr::core::array<irr::scene::ISceneNode*>*>(list);
    return *nodes;
}

template<class T>
inline int visibilityFind(const irr::core::array<T*>& array, T* const& element)
{
    for (unsigned int i = 0; i < array.used; ++i)
        if (element == array.data[i])
            return i;
    return -1;
}
}

void GS3DStuff::updateVisibility(unsigned int elapsed)
{
    b2World* world = PhysicAttributes::s_world;
    CCustomSceneManager* manager =
        reinterpret_cast<CCustomSceneManager*>(Application::GetInstance()->GetDevice()->getSceneManager());
    visibilityRenderables(manager).used = 0;
    // The default box (-1, -1, -1)-(1, 1, 1) keeps the insn count that gives
    // gcse retail's hash-table size, and so retail's spill-slot order.
    irr::core::aabbox3d<float> box;
    irr::scene::ICameraSceneNode* camera = CameraManager::getInstance()->getCamera();
    box = reinterpret_cast<const VisibilityFrustumView*>(camera->getViewFrustum())->boundingBox;
    irr::core::vector3d<float> direction = camera->getTarget() - camera->getPosition();
    direction.normalize();

    LastVisibleNodes->used = 0;
    LastVisibleSceneNodes->used = 0;
    const int nodeCount = VisibleNodes->used;
    for (int i = 0; i < nodeCount; ++i)
        LastVisibleNodes->push_back(VisibleNodes->data[i]);
    const int sceneNodeCount = VisibleSceneNodes->used;
    for (int i = 0; i < sceneNodeCount; ++i)
        LastVisibleSceneNodes->push_back(VisibleSceneNodes->data[i]);
    sceneOcttree->calculatePolys(box, VisibleNodes, VisibleSpawnPoint, VisibleSceneNodes);

    // The pointer round trip keeps this counter out of loop canonicalisation, which
    // leaves retail's SSA name recycling for the later loops.
    for (unsigned int i = 0; i < LastVisibleSceneNodes->used; i = reinterpret_cast<unsigned int>(reinterpret_cast<char*>(i) + 1)) {
        if (LastVisibleSceneNodes->data[i]->isVisible()
            && visibilityFind(*VisibleSceneNodes, LastVisibleSceneNodes->data[i]) == -1)
            LastVisibleSceneNodes->data[i]->setVisible(false);
    }
    for (unsigned int i = 0; i < VisibleSceneNodes->used; ++i) {
        if (!VisibleSceneNodes->data[i]->isVisible())
            VisibleSceneNodes->data[i]->setVisible(true);
        AddRenderables(VisibleSceneNodes->data[i], visibilityRenderables(manager), irr::scene::ESNT_ANY);
    }
    // Pointer round trip: see above.
    for (unsigned int i = 0; i < VisibleSpawnPoint->used; i = reinterpret_cast<unsigned int>(reinterpret_cast<char*>(i) + 1))
        VisibleSpawnPoint->data[i]->Update(elapsed);
    // Pointer round trip: see above.
    for (unsigned int i = 0; i < LastVisibleNodes->used; i = reinterpret_cast<unsigned int>(reinterpret_cast<char*>(i) + 1)) {
        VisibilityCollisionView* collision = reinterpret_cast<VisibilityCollisionView*>(LastVisibleNodes->data[i]);
        if (collision->active && visibilityFind(*VisibleNodes, LastVisibleNodes->data[i]) == -1) {
            // The two counters give retail's "x = j + 1; j = x" latch.
            for (unsigned int j = 0, x = 0; x < collision->bodies->used; j = x) {
                _ZN7b2World11DestroyBodyEP6b2Body(world, collision->bodies->data[x]);
                x = j + 1;
            }
            collision->bodies->used = 0;
            reinterpret_cast<VisibilityCollisionView*>(LastVisibleNodes->data[i])->active = false;
        }
    }

    if (Explosion::s_explosion && Explosion::s_explosion->isVisible())
        AddRenderables(Explosion::s_explosion, visibilityRenderables(manager), irr::scene::ESNT_ANY);
    if (_ZN9Character13m_bloodSplashE && _ZN9Character13m_bloodSplashE->isVisible())
        AddRenderables(_ZN9Character13m_bloodSplashE, visibilityRenderables(manager), irr::scene::ESNT_ANY);

    for (LevelObject* object = gom->GetFirst(0); object; object = object->next) {
        const VisibilityObjectView* view = reinterpret_cast<const VisibilityObjectView*>(object);
        // A guarded body rather than an early continue gives retail's block layout.
        if (view->sceneNode && view->sceneNode->isVisible()) {
        if (LevelObject::s_type[object->getObjectType()] == 15)
            AddRenderables(view->itemBillboard, visibilityRenderables(manager), visibilityColladaMesh);
        if (LevelObject::s_type[object->getObjectType()] == 5) {
            AddRenderables(view->vehicleNode, visibilityRenderables(manager), visibilityColladaMesh);
            AddRenderables(view->sceneNode, visibilityRenderables(manager), visibilityColladaSkin);
            AddRenderables(view->sceneNode, visibilityRenderables(manager), visibilityColladaMesh);
        } else if (LevelObject::s_type[object->getObjectType()] == 3) {
            AddRenderables(view->sceneNode, visibilityRenderables(manager), visibilityColladaSkin);
            AddRenderables(view->sceneNode, visibilityRenderables(manager), visibilityColladaMesh);
            AddRenderables(view->characterNode, visibilityRenderables(manager), visibilityColladaMesh);
            if (view->characterNode816 && view->characterNode816->isVisible())
                AddRenderables(view->characterNode816, visibilityRenderables(manager), irr::scene::ESNT_ANY);
            if (view->characterNode896 && view->characterNode896->isVisible())
                AddRenderables(view->characterNode896, visibilityRenderables(manager), irr::scene::ESNT_ANY);
            for (int k = 0; k < 4; ++k) {
                if (view->weapons[k] && view->weapons[k]->node && view->weapons[k]->node->isVisible())
                    AddRenderables(view->weapons[k]->node, visibilityRenderables(manager), irr::scene::ESNT_ANY);
            }
        } else {
            AddRenderables(view->sceneNode, visibilityRenderables(manager), visibilityColladaMesh);
        }
        if (view->shadowNode)
            AddRenderables(view->shadowNode, visibilityRenderables(manager), visibilityColladaMesh);
        }
    }

    visibilityRenderables(manager).push_back(sunGlow ? reinterpret_cast<irr::scene::ISceneNode*>(reinterpret_cast<unsigned char*>(sunGlow) + 4) : 0);
    AddRenderables(skyBox, visibilityRenderables(manager), visibilitySkyBox);
    AddRenderables(s_bulletManager, visibilityRenderables(manager), visibilityUnknown);
    AddRenderables(visibilityNodeAt(playerTest, 20), visibilityRenderables(manager), visibilityColladaSkin);
    AddRenderables(visibilityNodeAt(playerTest, 20), visibilityRenderables(manager), visibilityColladaMesh);
    AddRenderables(visibilityNodeAt(playerTest, 180), visibilityRenderables(manager), visibilityColladaMesh);
    {
        CustomBillboardSceneNode* billboard = Lock::getInstance()->billboard;
        irr::scene::ISceneNode* lockNode = billboard;
        AddRenderables(lockNode, visibilityRenderables(manager), visibilityColladaMesh);
    }
    if (Explosion::getExplosionNode() && Explosion::getExplosionNode()->isVisible())
        AddRenderables(Explosion::getExplosionNode(), visibilityRenderables(manager), visibilityColladaMesh);
    if (_ZN9Character13m_bloodSplashE && _ZN9Character13m_bloodSplashE->isVisible())
        AddRenderables(_ZN9Character13m_bloodSplashE, visibilityRenderables(manager), visibilityColladaMesh);
    // An unsigned counter gives retail's ivtmp-first impact address.
    for (unsigned int i = 0; i < 8; ++i)
        AddRenderables(s_bulletManager->getImpacts()[i], visibilityRenderables(manager), visibilityColladaMesh);
    // Pointer round trip: see above.
    for (unsigned int i = 0; i < lightsNodes.used; i = reinterpret_cast<unsigned int>(reinterpret_cast<char*>(i) + 1))
        visibilityRenderables(manager).push_back(lightsNodes.data[i]);

    for (unsigned int i = 0; i < VisibleNodes->used; ++i) {
        VisibilityCollisionView* collision = reinterpret_cast<VisibilityCollisionView*>(VisibleNodes->data[i]);
        if (!collision->active) {
            // The two counters give retail's "x = j + 1; j = x" latch.
            for (unsigned int j = 0, x = 0; x < collision->bodyDefinitions->used; j = x) {
                b2Body* body = _ZN7b2World10CreateBodyEPK9b2BodyDef(world, collision->bodyDefinitions->data[x]);
                _ZN6b2Body11CreateShapeEP10b2ShapeDef(body, collision->shapeDefinitions->data[x]);
                collision->bodies->push_back(body);
                x = j + 1;
            }
            reinterpret_cast<VisibilityCollisionView*>(VisibleNodes->data[i])->active = true;
        }
    }
}


void irr::video::ITexture::setMinFilter(unsigned char filter)
{
    if (minFilter != filter) {
        minFilter = filter;
        filterDirtyFlags |= 1;
    }
}

void irr::video::ITexture::setMagFilter(unsigned char filter)
{
    if (magFilter != filter) {
        magFilter = filter;
        filterDirtyFlags |= 2;
    }
}

void irr::video::ITexture::setLodBias(float bias)
{
    if (lodBias != bias) {
        lodBias = bias;
        filterDirtyFlags |= 32;
    }
}

void GS3DStuff::SetMaterialFiltering(irr::scene::ISceneNode* node, bool enabled, bool force)
{
    for (int i = 0; static_cast<unsigned int>(i) < node->getMaterialCount(); ++i) {
        irr::video::ITexture* texture = node->getMaterial(i).layers[0].texture;
        if (texture) {
            if (enabled) {
                texture->setMagFilter(1);
                texture->setMinFilter(1);
            } else if (force) {
                texture->setLodBias(-3.0f);
                texture->setMagFilter(1);
                texture->setMinFilter(1);
            } else {
                texture->setMagFilter(force);
                texture->setMinFilter(force);
            }
        }
    }

    applyToChildren(node, SetMaterialFiltering, enabled, force);
}

bool GS3DStuff::getProperty(const void* properties, const char* name, char* output)
{
    if (!properties) return false;
    const char* text = *static_cast<const char* const*>(properties);
    const char* found = strstr(text, name);
    if (!found) return false;
    const char* end = strchr(found, ';');
    if (!end) {
        end = strchr(found, '\n');
        if (!end) end = text + strlen(text);
    }
    const char* value = strchr(found, '=') + 1;
    int length = end - value;
    memcpy(output, value, length);
    output[length + 1] = 0;
    return true;
}

namespace GameFactoryProperties {
const char billboard[] __attribute__((section(".rodata.game_factory_billboard"))) = "billboard";
}


BulletTraceManager* GS3DStuff::s_bulletManager;
TrailMgr* GS3DStuff::s_TrailMgr;
irr::scene::ISceneNode* GS3DStuff::skyBox;
irr::scene::ISceneNode* GS3DStuff::city;
GameObjectManager* GS3DStuff::gom;
irr::video::ITexture* GS3DStuff::skyBoxTexture;
OctTreeAABB* GS3DStuff::sceneOcttree;
irr::scene::ISceneNode* GS3DStuff::sunNode;
irr::core::array<CollisionBodyDef*>* GS3DStuff::VisibleNodes;
irr::core::array<CollisionBodyDef*>* GS3DStuff::LastVisibleNodes;
irr::core::array<irr::scene::ISceneNode*>* GS3DStuff::VisibleSceneNodes;
irr::core::array<irr::scene::ISceneNode*>* GS3DStuff::LastVisibleSceneNodes;
irr::core::array<SpawnPoint*>* GS3DStuff::VisibleSpawnPoint;
int GS3DStuff::s_perfConfig;
Structs::PhonePerformanceProfile GS3DStuff::s_phonePerformanceProfile;
unsigned int GS3DStuff::lastTime;

// Only the touch-screen and event-manager words at 44 and 56 are observed here.
struct ApplicationEventView {
    unsigned char unknown0[44];
    TouchScreenBase* touchScreen;
    unsigned char unknown48[8];
    EventManager* eventManager;
};

GS3DStuff::GS3DStuff() : unknownFlag20(false), drawable(false), unknown24(0) {}
GS3DStuff::~GS3DStuff()
{
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->eventManager->detach(4, this);
}

void GS3DStuff::draw(const StateMachine*)
{
    Lock::getInstance()->render();
}

void GS3DStuff::ctor(const StateMachine*)
{
    SoundManager* sound = SoundManager::getInstance();
    int ambientSound = PlayerTest::GetPlayer()->getAmbientSound();
    sound->unknown140 = true;
    sound->playEx(ambientSound, 0, true, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    Application::GetInstance()->GetHudManager()->show();
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->touchScreen->clear();
}

void GS3DStuff::wakeup(const StateMachine*)
{
    lastTime = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->touchScreen->clear();
}

void GS3DStuff::resume(const StateMachine*)
{
    lastTime = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->touchScreen->clear();
}

static const char eventFormat[] __attribute__((section(".rodata.gs_event_format"))) = "%i\n";
static const char touchEventText[] __attribute__((section(".rodata.gs_touch_event"))) = "TOUCHSCREEN_PRESS";

void GS3DStuff::onEvent(const IEvent* event, const EventManager*)
{
    printf(eventFormat, event->getEventID());
    switch (event->getEventID()) {
    case 4: puts(touchEventText); break;
    }
}

void Structs::PhonePerformanceProfile::Read(DataStream& stream)
{
    unknown0 = stream.ReadInt();
    unknown4 = stream.ReadInt();
    textureNameSuffix = stream.ReadAndAllocateString();
}


BulletTraceManager* GS3DStuff::GetBulletManager() { return s_bulletManager; }
TrailMgr* GS3DStuff::GetTrailMgr() { return s_TrailMgr; }
irr::scene::ISceneNode* GS3DStuff::OptimizeHierarchy(irr::scene::ISceneNode*) { return 0; }
void GS3DStuff::dtor(const StateMachine*) {}
irr::scene::ISceneNode* GS3DStuff::getSkyBox() { return skyBox; }
irr::video::ITexture* GS3DStuff::getSkyBoxTexture() { return skyBoxTexture; }
char* GS3DStuff::getTextureNameSuffix() { return s_phonePerformanceProfile.textureNameSuffix; }
OctTreeAABB* GS3DStuff::getSceneOctTree() { return sceneOcttree; }
void GS3DStuff::draw2d(const StateMachine*) {}

namespace {
const char cityPartsFile[] = "./cityparts.array";
}

int GS3DStuff::loadCityDesc(const char*, char**& parts)
{
    World::GetInstance();
    ResStream resource(cityPartsFile, 1);
    DataStream stream(resource, DataStream::BigEndian);
    int count = stream.ReadInt();
    parts = new char*[count];
    for (int i = 0; i < count; ++i)
        parts[i] = stream.ReadAndAllocateString();
    stream.Close();
    resource.Close();
    return count;
}

void GS3DStuff::loadCityGameObjects(const WorldDescriptor& descriptor, bool spawnPointsOnly)
{
    World::GetInstance()->AddFromDescriptor(descriptor, spawnPointsOnly);
}

void GS3DStuff::forceDespawn(LevelObject* object)
{
    gom->despawn(object);
}

void GS3DStuff::forceDespawn(int type)
{
    LevelObject* object = gom->GetFirst(0);
    PlayerTest* player = PlayerTest::GetPlayer();
    while (object) {
        if ((object->unknown4 & 0x490) && LevelObject::s_type[object->getObjectType()] == type
            && player->unknown368 != object && player->unknown312 != object && player->unknown316 != object)
            object = gom->despawn(object);
        else
            object = object->next;
    }
}

namespace {
const char cityPropsAlpha[] = "props_alpha.tga";
const char cityPropsAlphaAlt[] = "props_alpha_01.tga";
}

void GS3DStuff::loadCityPart(const WorldDescriptor& descriptor, irr::scene::ISceneNode*& parent)
{
    irr::IrrlichtDevice* device = Application::GetInstance()->GetDevice();
    irr::scene::ISceneManager* manager = device->getSceneManager();
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneNode* node = irr::collada::CColladaDatabase::constructScene(
        descriptor.scenePath, &irr::collada::CColladaDatabase::DefaultFactory);
    if (!node)
        return;

    SetMaterialTypeCondition(node, irr::video::MaterialType15, driver->getTexture(cityPropsAlpha));
    SetMaterialTypeCondition(node, irr::video::MaterialType15, driver->getTexture(cityPropsAlphaAlt));
    AddXRef(node);
    SetMaterialFlag(node, irr::video::MaterialFlag2, true);
    SetMaterialFlag(node, irr::video::MaterialFlag4, true);
    SetMaterialFlag(node, irr::video::MaterialFlag16, true);
    SetMaterialFiltering(node, false, true);
    SetCulling(node, irr::scene::EAC_FRUSTUM_BOX);
    if (!parent)
        parent = manager->addEmptySceneNode(0, -1);
    parent->addChild(node);
    node->drop();
}

void GS3DStuff::loadCityVisual(const WorldDescriptor& descriptor)
{
    loadCityPart(descriptor, city);
}

irr::scene::ISceneNode* GS3DStuff::loadCityPart(const char* path)
{
    World* world = World::GetInstance();
    WorldDescriptor descriptor(path);
    world->AddFromDescriptor(descriptor, false);
    loadCityPart(descriptor, city);
    return city;
}


GS3DLightNodes GS3DStuff::lightsNodes;

void operator delete(void*) throw();
extern "C" {
static void __tcf_9() __attribute__((used));
static void __tcf_10() __attribute__((used));
static void __tcf_9()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_gs3dstuff_transitions {
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_9), &__dso_handle);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::scripted_vehicle_trans, 21);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        GS3DLightNodes& nodes = GS3DStuff::lightsNodes;
        nodes.data = 0;
        nodes.allocated = 0;
        nodes.used = 0;
        nodes.free_when_destroyed = true;
        nodes.is_sorted = true;
        nodes.unknown16 = 1;
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_10), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN9GS3DStuff15s_bulletManagerE() __attribute__((used));
static void _GLOBAL__I__ZN9GS3DStuff15s_bulletManagerE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_10()
{
    GS3DLightNodes& nodes = GS3DStuff::lightsNodes;
    if (nodes.free_when_destroyed)
        ::operator delete(nodes.data);
}
}

int GS3DStuff::s_orientation = 3;
bool GS3DStuff::b_isAutoOri = true;

void GS3DStuff::SetCurrentOrientation(irr::video::E_ORTHO_ORIENTATION orientation)
{
    s_orientation = orientation;
    irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();
    driver->setOrthoOrientation(static_cast<irr::video::E_ORTHO_ORIENTATION>(s_orientation));
    driver->setOrientation3D(static_cast<irr::video::E_ORTHO_ORIENTATION>(s_orientation));
}

static const char lodDistanceProperty[] __attribute__((section(".rodata.gs_lod_distance"))) = "lod";
static const char lodMaximumProperty[] __attribute__((section(".rodata.gs_lod_maximum"))) = "lodmax";

LODSceneNode* GS3DStuff::parseSceneNodeForLOD(irr::scene::ISceneNode* node, LODSceneNode* lod)
{
    char value[16];
    if (getProperty(node->getUserProperty(), lodDistanceProperty, value)) {
        if (!lod) {
            lod = new LODSceneNode(-1, irr::core::vector3d<float>(),
                irr::core::quaternion(), irr::core::vector3d<float>(1.0f, 1.0f, 1.0f));
        }
        lod->addLOD(node, static_cast<float>(atoi(value) * 100));
    }

    if (getProperty(node->getUserProperty(), lodMaximumProperty, value)) {
        if (!lod) {
            lod = new LODSceneNode(-1, irr::core::vector3d<float>(),
                irr::core::quaternion(), irr::core::vector3d<float>(1.0f, 1.0f, 1.0f));
            lod->addLOD(node, 0.0f);
        }
        lod->setMaxDistance(atoi(value) * 100);
    }

    irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
    while (child != node->getChildren().end()) {
        irr::scene::ISceneNode* current = child->value;
        child = child->next;
        lod = parseSceneNodeForLOD(current, lod);
    }
    return lod;
}

namespace {
// Observed 28-byte static-body payload. No original runtime type name is asserted.
struct StaticBodyData {
    LevelObject* owner;
    irr::scene::ISceneNode* node;
    float lowerHeight;
    float upperHeight;
    float height2;
    float height3;
    bool jump;
    unsigned char identifier;
    // Non-jump overload (tag argument unused): same stores, heights stored right after
    // owner. The order only changes which reload registers the identifier byte gets.
    StaticBodyData(int, float a, float b, float c, float d, bool special, unsigned char id)
    {
        owner = 0;
        lowerHeight = a;
        upperHeight = b;
        node = 0;
        jump = special;
        height2 = c;
        height3 = d;
        identifier = id;
    }
    StaticBodyData(float a, float b, float c, float d, bool special, unsigned char id)
    {
        owner = 0;
        node = 0;
        jump = special;
        lowerHeight = a;
        upperHeight = b;
        height2 = c;
        height3 = d;
        identifier = id;
    }
};

// File-local view of Box2D 2.0.1 b2BodyDef with the upstream constructor
// store order (same layout as the shared PhysicsBodyDef.h view).
struct StaticBodyDef {
    StaticBodyDef()
    {
        massData.center.x = 0.0f;
        massData.center.y = 0.0f;
        massData.mass = 0.0f;
        massData.I = 0.0f;
        userData = 0;
        position.x = 0.0f;
        position.y = 0.0f;
        angle = 0.0f;
        linearDamping = 0.0f;
        angularDamping = 0.0f;
        allowSleep = true;
        isSleeping = false;
        fixedRotation = false;
        isBullet = false;
    }
    b2MassData massData;
    void* userData;
    b2Vec2 position;
    float angle, linearDamping, angularDamping;
    bool allowSleep, isSleeping, fixedRotation, isBullet;
};

// File-local view of the retail IMeshBuffer vtable: slot 9 is getVertexCount.
class StaticMeshBufferView {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual void unknown6(); virtual void unknown7(); virtual void unknown8();
    virtual unsigned int getVertexCount() const;
};

// File-local view of the CollisionBodyDef definition arrays.
struct CollisionBodyDefView {
    irr::core::array<b2Body*>* bodies;
    irr::core::array<b2BodyDef*>* bodyDefinitions;
    irr::core::array<b2PolygonDef*>* polygonDefinitions;
};

// Irrlicht 1.4.2 matrix4::rotateVect(out, in).
inline void rotateVectInto(const irr::core::CMatrix4<float>& m,
    irr::core::vector3d<float>& out, const irr::core::vector3d<float>& in)
{
    out.X = in.X*m[0] + in.Y*m[4] + in.Z*m[8];
    out.Y = in.X*m[1] + in.Y*m[5] + in.Z*m[9];
    out.Z = in.X*m[2] + in.Y*m[6] + in.Z*m[10];
}
}

// irr::core::CMatrix4<float>::getRotationDegrees() const, weak engine definition.
extern "C" irr::core::vector3d<float> _ZNK3irr4core8CMatrix4IfE18getRotationDegreesEv(
    const irr::core::CMatrix4<float>*) __attribute__((weak));

// CreateStaticBodies()::ID, the jump-body identifier counter. The function is
// defined through its mangled extern "C" name, so the function-local static is
// spelled at file scope under its retail mangled name (local binding, .bss).
static unsigned char _ZZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_E2ID = 0;

extern "C" void _ZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_(
    irr::scene::ISceneNode* node, irr::scene::ISceneNode* owner,
    irr::scene::ISceneNode* transform, irr::scene::ISceneNode* context)
{
    using irr::core::vector3d;
    node->updateAbsolutePosition(false);
    const bool jump = strstr(node->getUID(), jumpNodeMarker) != 0;
    if (node->getType() == colladaMeshNode || node->getType() == colladaSkinnedNode) {
        // Branch-prediction hints only (no code): the no-code prefetches mark guarded
        // calls and the one-field aggregate tests are known false after SRA, so the
        // jump-marker test block gets retail's frequency and trace position.
        if (strstr(node->getUID(), planeNodeMarker)) {
            __builtin_prefetch(node);
            if (({ struct L { int k; } u = { 0 }; L t = u; t.k == 1; })) {
                __builtin_prefetch(node);
                goto planeFail;
            }
            goto marker;
        }
        planeFail:
        if (jump)
            goto marker;
    } else if (({ struct L { int k; } u = { 0 }; L t = u; t.k == 1; })) {
        __builtin_prefetch(node);
        goto planeFail;
    }
    goto children;
    marker: {
        node->setVisible(false);
        // Branch-likelihood hint (documented): marker meshes are quads.
        if (__builtin_expect(reinterpret_cast<StaticMeshBufferView*>(static_cast<irr::scene::IMeshSceneNode*>(node)->getMesh()->getMeshBuffer(0))->getVertexCount() != 4, 0))
            return;
        StaticBodyDef* body = new StaticBodyDef;
        const vector3d<float> position = node->getAbsolutePosition();
        const vector3d<float> angles = _ZNK3irr4core8CMatrix4IfE18getRotationDegreesEv(&node->getAbsoluteTransformation());
        StaticBodyDef* const target = body;
        b2Vec2 p;
        p.y = position.Y / 100.0f;
        p.x = position.X / 100.0f;
        target->position = p;
        const float angle = angles.Z * 0.01745329238474369f;
        body->angle = angle;
        transform->updateAbsolutePosition(false);
        irr::scene::IMeshBuffer* mesh = static_cast<irr::scene::IMeshSceneNode*>(node)->getMesh()->getMeshBuffer(0);
        int start = 0;
        if (__builtin_expect(({ struct L { int k; } u = { 0 }; L t = u; t.k != 0; }), 0)) goto scanStart;
        if (jump) {
            scanStart:
            // Prediction hints only (no code): the aggregate-hidden 4, the expected-false
            // continue and the no-code prefetch give the scan loop the iteration estimate
            // that rotates it into retail's block order.
            for (; start < ({ struct L { int k; } u = { 4 }; L t = u; t.k; }); ++start) {
                if (mesh->getPosition(start).X < 0.0f && mesh->getPosition(start).Y < 50.0f) {
                    if (__builtin_expect(({ struct L { int k; } u = { 0 }; L t = u; t.k != 0; }), 0))
                        continue;
                    break;
                } else
                    __builtin_prefetch(node);
            }
        }
        vector3d<float> vertices[4];
        if (jump) { unsigned char identifier; unsigned int end;
            // Exit as a separate XOR test (no early iteration count, retail i != end order);
            // the known-false aggregate break and the no-code prefetch on the guard's skip
            // path only restore this loop's estimated frequencies.
            unsigned int i = start; end = i + 4; if (i < end) for (;;) {
                if (({ struct L { int k; } u = { 0 }; L t = u; t.k != 0; })) break; rotateVectInto(transform->getAbsoluteTransformation(), vertices[i - start], mesh->getPosition(i & 3)); const unsigned int left = ++i ^ end; if (left == 0) break; } else __builtin_prefetch(node);
            const float height = transform->getAbsoluteTransformation()[14]; StaticBodyDef* const target = body; identifier = _ZZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_E2ID++;
            target->userData = new StaticBodyData(height + vertices[0].Z, height + vertices[1].Z,
                height + vertices[2].Z, height + vertices[3].Z, true,
                identifier);
        } else
            goto elseData;
        b2PolygonDef* polygon;
        polyStart:
        polygon = new b2PolygonDef;
        {
        if (jump) {
            // Both native virtual queries are retained although their results are unused.
            transform->getAbsoluteTransformation();
            transform->getAbsoluteTransformation();
            const irr::core::quaternion rotation(0.0f, 0.0f, angle);
            for (unsigned int i = 0; i < 4; ++i) {
                polygon->vertices[i].x = (rotation * vertices[i]).X / 100.0f;
                polygon->vertices[i].y = (rotation * vertices[i]).Y / 100.0f;
            }
        } else if (!mesh->getIndices()[3] || !mesh->getIndices()[4] || !mesh->getIndices()[5]) {
            // No-code hint: k's final value (4) is only known after the loop optimisers, so
            // endx == end is copy-propagated into the exit XOR after reassociation and the
            // compare keeps retail's operand order.
            { const unsigned int end = start + 4; unsigned int i = start; unsigned int k = 0; do ++k; while (k < 4); const unsigned int endx = end + (k - 4); if (i < end) for (;;) {
                // Known false after SRA; only lowers this loop's estimated frequency.
                if (__builtin_expect(({ struct L { int k; } u = { 0 }; L t = u; t.k != 0; }), 1)) break;
                const vector3d<float>& vertex = mesh->getPosition(i & 3);
                const float y = vertex.Y;
                polygon->vertices[i - start].x = vertex.X / 100.0f;
                polygon->vertices[i - start].y = y / 100.0f;
                const unsigned int left = ++i ^ endx;
                if (left == 0) break;
            } }
        } else {
            // No-code hint: k's final value (4) is only known after the loop optimisers, so
            // endx == end is copy-propagated into the exit XOR after reassociation and the
            // compare keeps retail's operand order.
            { const unsigned int end = start + 4; unsigned int i = start; unsigned int k = 0; do ++k; while (k < 4); const unsigned int endx = end + (k - 4); if (i < end) for (;;) {
                const unsigned int index = i & 3;
                vector3d<float> vertex;
                if (index == 2)
                    vertex = mesh->getPosition(3);
                else if (index == 3)
                    vertex = mesh->getPosition(2);
                else
                    vertex = mesh->getPosition(index);
                polygon->vertices[i - start].x = vertex.X / 100.0f;
                polygon->vertices[i - start].y = vertex.Y / 100.0f;
                const unsigned int left = ++i ^ endx;
                if (left == 0) break;
            } }
        }
        polygon->vertexCount = 4;
        polygon->density = 1.0f;
        polygon->restitution = 0.0f;
        polygon->filter.categoryBits = 1;
        polygon->filter.maskBits = 0xFFFF;
        CollisionBodyDef* data = static_cast<CollisionBodyDef*>(owner->getGameData());
        if (!data) {
            data = new CollisionBodyDef;
            owner->setGameData(data);
        }
        CollisionBodyDefView* view = reinterpret_cast<CollisionBodyDefView*>(data);
        view->bodyDefinitions->push_back(reinterpret_cast<b2BodyDef*&>(body));
        view->polygonDefinitions->push_back(polygon);
        irr::scene::ISceneNode* parent = node->getParent();
        node->remove();
        if (parent)
            CCustomSceneManager::CleanParents(parent);
        return;
        }
        elseData: {
            const irr::core::aabbox3d<float>& bounds = transform->getTransformedBoundingBox();
            const float upper = bounds.MaxEdge.Z;
            const float lower = bounds.MinEdge.Z;
            body->userData = new StaticBodyData(0, lower, upper, 0.0f, 0.0f, false, 0);
        }
        goto polyStart;
    }
    children:
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end();) {
        irr::scene::ISceneNode* entry = child->value;
        child = child->next;
        _ZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_(entry, owner, transform, context);
    }
}

// No-code DECL_UID pad (12 enumerators): keeps the following functions' temporaries ordered as in retail.
enum { WCH_CSB_PAD0, WCH_CSB_PAD1, WCH_CSB_PAD2, WCH_CSB_PAD3, WCH_CSB_PAD4, WCH_CSB_PAD5, WCH_CSB_PAD6, WCH_CSB_PAD7, WCH_CSB_PAD8, WCH_CSB_PAD9, WCH_CSB_PAD10, WCH_CSB_PAD11 };

void GS3DStuff::AddToSceneMgr(irr::scene::ISceneNode* node, irr::scene::ISceneNode* parent)
{
    node->updateAbsolutePosition(false);
    irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
    while (child != node->getChildren().end()) {
        irr::scene::ISceneNode* current = child->value;
        child = child->next;
        AddToSceneMgr(current, parent);
    }

    const int type = node->getType();
    const int octTreeNode = 0x7474636f;
    if (type == octTreeNode || type == colladaMeshNode || type == colladaSkinnedNode) {
        node->updateAbsolutePosition(false);
        node->setPosition(node->getAbsolutePosition());
        node->setRotation(irr::core::quaternion(node->getAbsoluteTransformation()));
        node->SetOption(irr::scene::SceneOption1, node->getAnimators().getSize() == 0);

        if (type == colladaMeshNode || type == colladaSkinnedNode) {
            irr::scene::IMeshSceneNode* meshNode = static_cast<irr::scene::IMeshSceneNode*>(node);
            for (unsigned int i = 0; i < meshNode->getMesh()->getMeshBufferCount(); ++i) {
                meshNode->getMesh()->getMeshBuffer(i)->setHardwareMappingHint(
                    irr::scene::EHM_STATIC, irr::scene::EBT_VERTEX_AND_INDEX);
            }
        }

        parent->addChild(node);
        node->removeAll();
    }
}

extern "C" void _ZN10DataStreamD1Ev(void*) __attribute__((weak));

void GS3DStuff::loadPerformanceProfile(const char* name)
{
    ResStream resource(name, 1);
    unsigned int streamStorage[sizeof(DataStream) / sizeof(unsigned int)];
    DataStream& stream = *new (streamStorage) DataStream(resource, DataStream::BigEndian);
    stream.ReadInt();
    for (int index = 0; index < s_perfConfig; ++index) {
        stream.Skip(stream.ReadInt());
    }
    stream.ReadInt();
    s_phonePerformanceProfile.Read(stream);
    if (!s_phonePerformanceProfile.textureNameSuffix[0]) {
        delete[] s_phonePerformanceProfile.textureNameSuffix;
        s_phonePerformanceProfile.textureNameSuffix = 0;
    }
    stream.Stream::Close();
    resource.BufferStream::Close();
    _ZN10DataStreamD1Ev(&stream);
}

namespace {
const char selectorPath[] __attribute__((section(".rodata.perf_selector"))) = "./PhonePerformanceSelector.array";
}

void GS3DStuff::setPerformanceType(const char* name)
{
    ResStream resource(selectorPath, 1);
    DataStream stream(resource, DataStream::BigEndian);
    const int configs = stream.ReadInt();
    s_perfConfig = 0;
    for (int index = 0; index < configs; ++index) {
        const int names = stream.ReadInt();
        for (int i = 0; i < names; ++i) {
            char* profile = stream.ReadAndAllocateString();
            if (strcmp(name, profile) == 0) {
                s_perfConfig = index;
                delete[] profile;
                goto finish;
            }
            delete[] profile;
        }
    }
finish:
    stream.Close();
    resource.Close();
}

void GS3DStuff::unload()
{
    Application* application = Application::GetInstance();
    application->GetControlManager()->lock();
    static_cast<Race*>(ScriptManager::getInstance()->getRace())->reset();
    AIManager::getInstance()->clean();
    ScriptManager::getInstance()->unload();
    GameObjectManager::s_gom->Clear();
    Character::freeBloodObjects();
    SceneNodeManager::getInstance()->tearDown();

    if (application->GetHudManager()->minimap)
        static_cast<MiniMap*>(application->GetHudManager()->minimap)->deregisterAllForMapTracking();
    application->GetHudManager()->init();

    for (int index = 0; static_cast<unsigned int>(index) < lightsNodes.used; ++index)
        lightsNodes.data[index]->remove();
    ::operator delete(lightsNodes.data);
    lightsNodes.data = 0;
    lightsNodes.used = 0;
    lightsNodes.allocated = 0;
    lightsNodes.is_sorted = true;

    freeGameData(Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode());
    if (sunNode)
        sunNode->drop();
    sunNode = 0;
    CameraManager::getInstance()->clean();
    PhysicAttributes::Clean();
    PhysicAttributes::s_heightmap = 0;
    Character::cleanTimelineController();
    Lock::clean();
    SafeDelete(sceneOcttree);
    playerTest = 0;
    SpawnPoint::ClearAllSpawnInstances();
    PhysicAttributes::CleanWorld();
    if (s_TrailMgr) {
        s_TrailMgr->CleanUp();
        delete s_TrailMgr;
        s_TrailMgr = 0;
    }
    LevelObject::freeHighlights();
    Map::getInstance()->clean();

    SafeDelete(VisibleNodes);
    SafeDelete(LastVisibleNodes);
    SafeDelete(VisibleSceneNodes);
    SafeDelete(LastVisibleSceneNodes);
    SafeDelete(VisibleSpawnPoint);

    irr::scene::ISceneManager* manager = application->GetDevice()->getSceneManager();
    manager->removeAll();
    reinterpret_cast<CCustomSceneManager*>(manager)->clean();
    Application::GetInstance()->GetWeaponManager()->clean();
    GSLoading::setGameLoaded(false);

    while (SoundManager::getInstance()->isSoundPlaying(218))
        SoundManager::getInstance()->update(0.0);

    Item::resetAchievementCounters();
    Shop::resetAchievementCounters();

    const float musicVolume = SoundManager::getInstance()->playbackVolume;
    const float effectsVolume = SoundManager::getInstance()->effectsPlaybackVolume;
    Vehicle::UnRegisterCarSoundsCallbacks();
    Application::GetInstance()->UnRegisterForUpdate(SoundManager::getInstance());
    SoundManager::getInstance()->clear();
    SoundManager::getInstance()->init();
    Application::GetInstance()->RegisterForUpdate(SoundManager::getInstance());
    SoundManager::getInstance()->allocBuffers();
    SoundManager::getInstance()->setMusicVolume(musicVolume);
    SoundManager::getInstance()->setSfxVolume(effectsVolume);
    Vehicle::RegisterCarSoundsCallbacks();
}

/* basic_string<char>::_M_append follows STLport 5.x _string.c.
 * Copyright (c) 1994 Hewlett-Packard Company
 * Copyright (c) 1996,1997 Silicon Graphics Computer Systems, Inc.
 * Copyright (c) 1997 Moscow Center for SPARC Technology
 * Copyright (c) 1999 Boris Fomitchev
 * Distributed under the notice reproduced above in this file.
 * Modified: char-only private view with the allocator and length-error calls
 * bound to their native symbols; helper bodies written inline.
 */
extern "C" {
char* _ZNSaIcE8allocateEjRj(std::allocator<char>*, unsigned int, unsigned int&) __attribute__((weak));
void _ZNK9stlp_priv12_String_baseIcSaIcEE21_M_throw_length_errorEv(const void*) __attribute__((weak, noreturn));
}
namespace std {
template<class T> struct char_traits;
template<class T, class Traits = char_traits<T>, class Alloc = allocator<T> >
class basic_string {
public:
    typedef unsigned int size_type;
    basic_string& append(const T* text);
private:
    struct Proxy : public Alloc { T* _M_data; };
    union Buffers { T* _M_dynamic_buf; T _M_static_buf[16]; } _M_buffers;
    T* _M_finish;
    Proxy _M_end_of_storage;
    bool _M_using_static_buf() const
    { return _M_end_of_storage._M_data == _M_buffers._M_static_buf + 16; }
    const T* _M_Start() const
    { return _M_using_static_buf() ? _M_buffers._M_static_buf : _M_buffers._M_dynamic_buf; }
    T* _M_Finish() { return _M_finish; }
    size_type size() const { return _M_finish - _M_Start(); }
    size_type max_size() const { return size_type(-1) / sizeof(T) - 1; }
    size_type capacity() const { return (_M_end_of_storage._M_data - _M_Start()) - 1; }
    void _M_throw_length_error() const __attribute__((noreturn))
    { _ZNK9stlp_priv12_String_baseIcSaIcEE21_M_throw_length_errorEv(this); }
    void _M_reset(T* start, T* finish, T* end)
    {
        _M_buffers._M_dynamic_buf = start;
        _M_finish = finish;
        _M_end_of_storage._M_data = end;
    }
    static void _M_construct_null(T* p) { *p = 0; }
    static T* __ucopy(const T* first, const T* last, T* result)
    {
        T* cur = result;
        for (int n = last - first; n > 0; --n) {
            *cur = *first;
            ++first;
            ++cur;
        }
        return cur;
    }
    static const size_type& max_ref(const size_type& a, const size_type& b) { return a < b ? b : a; }
    basic_string& _M_append(const T* first, const T* last) __attribute__((weak));
};
template<>
basic_string<char>& basic_string<char>::_M_append(const char* first, const char* last)
{
    if (first != last) {
        const size_type old_size = size();
        int n = last - first;
        if (n > max_size() || old_size > max_size() - n)
            _M_throw_length_error();
        if (old_size + n > capacity()) {
            size_type len = old_size + max_ref(old_size, static_cast<size_type>(n)) + 1;
            char* new_start = _ZNSaIcE8allocateEjRj(&_M_end_of_storage, len, len);
            char* new_finish = new_start;
            new_finish = __ucopy(_M_Start(), _M_Finish(), new_start);
            new_finish = __ucopy(first, last, new_finish);
            _M_construct_null(new_finish);
            if (_M_buffers._M_static_buf + 16 != _M_end_of_storage._M_data &&
                _M_buffers._M_dynamic_buf != 0)
                ::operator delete(_M_buffers._M_dynamic_buf);
            _M_reset(new_start, new_finish, new_start + len);
        } else {
            const char* f1 = first;
            ++f1;
            if (_M_using_static_buf()) {
                char* res = _M_Finish() + 1;
                int count = last - f1;
                if (count != 0)
                    memcpy(res, f1, count);
            } else
                __ucopy(f1, last, _M_Finish() + 1);
            _M_construct_null(_M_Finish() + n);
            *_M_finish = *first;
            _M_finish += n;
        }
    }
    return *this;
}
template<>
basic_string<char>& basic_string<char>::append(const char* text)
{
    return _M_append(text, text + strlen(text));
}
}


#include "../combat/Weapon.h"
#include "../combat/BulletTraceManager.h"
#include "../combat/WeaponManager.h"
#include "../hud/MenuManager.h"
#include "../ui/MainMenu.h"
#include "../core/Rect.h"

namespace irr { namespace scene {
// Observed call-only primary interface. The scene-node receiver is at +4.
class IBillboardSceneNode {
public:
    virtual void setSize(const core::dimension2d<float>&) = 0;
};
class CSceneManager { public: void collectAllNodes(); };
} }
extern "C" void _ZN11OctTreeAABBC1EPN3irr5scene10ISceneNodeEj(OctTreeAABB*, irr::scene::ISceneNode*, unsigned int) __attribute__((weak));
extern "C" int _ZNK11MenuManager11getPlaylistEv(const MenuManager*);
extern "C" bool _ZN13ScriptManager7debugOnE;

extern "C" {
static const int LoadingPercents[14] = {1,1,2,4,2,3,3,2,2,5,3,2,2,1};
}
// Loader-local definition of the SDK lifetime adapter; no shared-header body.
inline irr::core::quaternion::quaternion(irr::core::quaternion::uninitialized_t) {}

namespace {
static const char loadingProfile[] __attribute__((section(".rodata.gs_load_profile"))) = "./PhonePerformanceProfiles.gmap";
static const char loadingSun[] __attribute__((section(".rodata.gs_load_sun"))) = "sun_dummy-node";
static const char loadingHeightmap[] __attribute__((section(".rodata.gs_load_heightmap"))) = "./santa_monica_heightmap.bdae";
static const char loadingNavigation[] __attribute__((section(".rodata.gs_load_navigation"))) = "./nav_mesh_arrays.bin";
static const char loadingBackground[] __attribute__((section(".rodata.gs_load_background"))) = "./backgroundTex.tga";
static const char loadingGlow[] __attribute__((section(".rodata.gs_load_glow"))) = "./add-glow.tga";
static const char loadingMainMenu[] __attribute__((section(".rodata.gs_load_main_menu"))) = "MainMenu";
static const char loadingMissions[] __attribute__((section(".rodata.gs_load_missions"))) = "./Missions.gmap";
static const char loadingScripts[] __attribute__((section(".rodata.gs_load_scripts"))) = "./allscripts.gmap";
static const char loadingHighlights[] __attribute__((section(".rodata.gs_load_highlights"))) = "./Highlights.array";
static const char loadingBloodPuddle[] __attribute__((section(".rodata.gs_load_blood_puddle"))) = "./blood_puddle.bdae";
static const char loadingBloodParticle[] __attribute__((section(".rodata.gs_load_blood_particle"))) = "./p_blood_00.bdae";
struct LoadingApplicationFields { unsigned char prefix[88]; int targetFrameRate; };
struct LoadingObjectFields { unsigned char prefix[16]; irr::scene::ISceneNode* sceneNode; };
struct LoadingType15Fields { unsigned char prefix[88]; int value; };
struct LoadingRenderableFields { unsigned char prefix[8]; unsigned int count; };
inline __attribute__((always_inline)) irr::core::quaternion makeLoadingQuaternion(float x, float y, float z)
{
    irr::core::quaternion result((irr::core::quaternion::uninitialized_t()));
    result.set(x, y, z);
    return result;
}

inline irr::scene::ISceneNode& loadingBillboardNode(irr::scene::IBillboardSceneNode& billboard)
{
    return *reinterpret_cast<irr::scene::ISceneNode*>(reinterpret_cast<unsigned char*>(&billboard) + 4);
}
}

#include "../vehicles/CarSoundCallbacks.h"
extern "C" void _ZN11MenuManager8tearDownEv(MenuManager*);

namespace {
template<class T>
inline __attribute__((always_inline)) void deletePointerArray(irr::core::array<T*>* storage)
{
    if (storage) {
        if (storage->free_when_destroyed)
            ::operator delete(storage->data);
        delete storage;
    }
}
template<class T>
inline __attribute__((always_inline)) void deletePointerArraySplit(irr::core::array<T*>* storage)
{
    if (storage) {
        if (!storage->free_when_destroyed) {
            ::operator delete(storage);
        } else {
            ::operator delete(storage->data);
            ::operator delete(storage);
        }
    }
}
}

void GS3DStuff::tearDown()
{
    AIManager::getInstance()->clean();
    GameObjectManager::s_gom->Clear();
    SceneNodeManager::getInstance()->tearDown();
    ScriptManager::getInstance()->tearDown();
    _ZN11MenuManager8tearDownEv(MenuManager::getInstance());

    for (int index = 0; static_cast<unsigned int>(index) < lightsNodes.used; ++index)
        lightsNodes.data[index]->remove();
    ::operator delete(lightsNodes.data);
    lightsNodes.data = 0;
    lightsNodes.used = 0;
    lightsNodes.allocated = 0;
    lightsNodes.is_sorted = true;

    freeGameData(Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode());
    if (sunNode)
        sunNode->drop();
    CameraManager::getInstance()->clean();
    PhysicAttributes::Clean();
    Character::cleanTimelineController();
    Lock::clean();
    SafeDelete(sceneOcttree);
    SpawnPoint::ClearAllSpawnInstances();
    delete playerTest;
    playerTest = 0;
    PhysicAttributes::CleanWorld();
    if (s_TrailMgr) {
        s_TrailMgr->CleanUp();
        delete s_TrailMgr;
        s_TrailMgr = 0;
    }
    LevelObject::freeHighlights();
    Map::getInstance()->clean();
    CarSounds::Clean();
    SoundManager::getInstance()->clear();

    deletePointerArraySplit(VisibleNodes);
    deletePointerArray(LastVisibleNodes);
    deletePointerArray(VisibleSceneNodes);
    deletePointerArraySplit(LastVisibleSceneNodes);
    deletePointerArraySplit(VisibleSpawnPoint);
}


extern "C" void _ZNK3irr4core8aabbox3dIfE8getEdgesEPNS0_8vector3dIfEE(const irr::core::aabbox3d<float>*,
    irr::core::vector3d<float>*) __attribute__((weak));
extern "C" bool _ZNK3irr4core8vector3dIfE6equalsERKS2_f(const irr::core::vector3d<float>*,
    const irr::core::vector3d<float>&, float) __attribute__((weak));

static inline void octAddInternalPoint(irr::core::aabbox3d<float>& box, float x, float y, float z)
{
    if (x>box.MaxEdge.X) box.MaxEdge.X=x;
    if (y>box.MaxEdge.Y) box.MaxEdge.Y=y;
    if (z>box.MaxEdge.Z) box.MaxEdge.Z=z;
    if (x<box.MinEdge.X) box.MinEdge.X=x;
    if (y<box.MinEdge.Y) box.MinEdge.Y=y;
    if (z<box.MinEdge.Z) box.MinEdge.Z=z;
}
static inline void octAddInternalPoint(irr::core::aabbox3d<float>& box, const irr::core::vector3d<float>& p)
{
    octAddInternalPoint(box, p.X, p.Y, p.Z);
}
// Evaluating the corner as arguments puts its loads in the loop header block,
// so ivopts meets the corners use before the children store (retail IV order).
static inline irr::core::aabbox3d<float> octChildBox(const irr::core::vector3d<float>& c, float x, float y, float z)
{
    irr::core::aabbox3d<float> b(c);
    octAddInternalPoint(b, x, y, z);
    return b;
}
static inline bool octLE(const irr::core::vector3d<float>& a, const irr::core::vector3d<float>& b)
{ return a.X<=b.X && a.Y<=b.Y && a.Z<=b.Z; }
static inline bool octGE(const irr::core::vector3d<float>& a, const irr::core::vector3d<float>& b)
{ return a.X>=b.X && a.Y>=b.Y && a.Z>=b.Z; }

OctTreeAABB::OctTreeAABBNode::OctTreeAABBNode(
    int& count, int parentDepth, irr::core::array<RootNode*>* incoming,
    unsigned int limit, irr::core::aabbox3d<float> inputBounds)
    : bounds(), roots(0)
{
    using namespace irr::core;
    depth = parentDepth + 1;
    ++count;
    children[0] = 0;
    for (unsigned int i = 0; i < 8; ++i)
        children[i] = 0;

    if (!incoming->used) {
        SafeDelete(incoming);
        return;
    }

    bounds = inputBounds;
    const vector3d<float> center = (bounds.MinEdge + bounds.MaxEdge) * 0.5f;
    vector3d<float> corners[8];
    _ZNK3irr4core8aabbox3dIfE8getEdgesEPNS0_8vector3dIfEE(&bounds, corners);
    if (incoming->used <= limit || ({
            const bool flat = _ZNK3irr4core8vector3dIfE6equalsERKS2_f(&bounds.MinEdge, bounds.MaxEdge, 0.000001f);
            // Identical arms (crossjumped after reload, no code; the selecting test is then
            // deleted).  The first four compares (this in r9, the spilled count and limit, the
            // &incoming equivalence) each take one reload, so reload's spill-register rotation
            // ends on r6 and the roots store and the loop preheader reload into r1/r2/r3 as in
            // retail.  The remaining compares inherit those reloads; they only add RTL insns so
            // gcse1's hash table has 77 buckets (PRE gives the reallocate literal the lower
            // stack slot, as in retail).
            if (__builtin_expect(reinterpret_cast<unsigned long>(this) > 1 && reinterpret_cast<unsigned long>(&count) > 1
                                 && limit > 1 && reinterpret_cast<unsigned long>(&incoming) > 1
                                 && limit > 2 && &incoming != reinterpret_cast<array<RootNode*>**>(2)
                                 && limit > 3 && &incoming != reinterpret_cast<array<RootNode*>**>(3)
                                 && limit > 4 && &incoming != reinterpret_cast<array<RootNode*>**>(4)
                                 && limit > 5 && &incoming != reinterpret_cast<array<RootNode*>**>(5)
                                 && limit > 6 && &incoming != reinterpret_cast<array<RootNode*>**>(6)
                                 && limit > 7 && &incoming != reinterpret_cast<array<RootNode*>**>(7)
                                 && limit > 8 && &incoming != reinterpret_cast<array<RootNode*>**>(8)
                                 && limit > 9 && &incoming != reinterpret_cast<array<RootNode*>**>(9)
                                 && limit > 10 && &incoming != reinterpret_cast<array<RootNode*>**>(10)
                                 && limit > 11 && &incoming != reinterpret_cast<array<RootNode*>**>(11), 0)) {
                if (flat)
                    goto leafRoots;
            } else {
                if (flat)
                    goto leafRoots;
            }
            false;
        })) {
    leafRoots:
        roots = incoming;
        return;
    }

    for (unsigned int i = 0; i < 8; ++i) {
        aabbox3d<float> childBounds = octChildBox(center, corners[i].X, corners[i].Y, corners[i].Z);
        const unsigned int capacity = incoming->used;
        array<RootNode*>* const created = newPointerArray<RootNode>();
        created->reallocate(capacity);
        array<RootNode*>* childRoots = created;
        unsigned int intersections = 0;
        for (unsigned int j = 0; j < incoming->used; ++j) {
            RootNode*& root = incoming->data[j];
            const aabbox3d<float>& box = root->bounds;
            if ((octLE(childBounds.MinEdge, box.MaxEdge) && octGE(childBounds.MaxEdge, box.MinEdge))) {
                childRoots->push_back(root);
                ++intersections;
            }
        }

        if (intersections) {
            // Two dead corner loads plus the grown and child copies emit no code;
            // DCE releases their SSA names, which SRA later recycles, so the
            // childBounds MinEdge PHIs outrank the box loads and the intersection
            // compares keep retail's box-first (fcmpge) orientation.
            { float dead0_ = corners[i].Y; (void)dead0_; }
            { float dead1_ = corners[i].Y; (void)dead1_; }
            const unsigned int grown = intersections;
            childRoots->reallocate(grown);
            OctTreeAABBNode* const child = new OctTreeAABBNode(count, depth, childRoots, limit, childBounds);
            children[i] = child;
        } else {
            SafeDelete(childRoots);
        }
    }

    if (depth != 1)
        SafeDelete(incoming);
}
// No-code DECL_UID pad (5 enumerators): keeps later functions' temporaries ordered as in retail.
enum { WCH_OCT_PAD0, WCH_OCT_PAD1, WCH_OCT_PAD2, WCH_OCT_PAD3, WCH_OCT_PAD4 };

int GS3DStuff::load(int step, int& percent)
{
    Application* application = Application::GetInstance();
    irr::IrrlichtDevice* device = application->GetDevice();
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* manager = device->getSceneManager();
    percent += LoadingPercents[step];
    switch (step) {
    case 0:
        loadPerformanceProfile(loadingProfile);
        SceneNodeManager::getInstance()->setup();
        driver->addMaterialRenderer(reinterpret_cast<irr::video::IMaterialRenderer*>(Application::GetInstance()->GetMaterialRenderer()), 0);
        return 1;
    case 1:
        driver->setOption(128, true);
        lastTime = device->getTimer()->getRealTime();
        reinterpret_cast<LoadingApplicationFields*>(application)->targetFrameRate = 100;
        return 2;
    case 2:
        GameObjectManager::Setup();
        LevelObject::setup();
        s_cityPartsNum = loadCityDesc(cityPartsFile, s_cityParts);
        s_curCityPart = 0;
        s_curCityStep = 0;
        city = 0;
        return 3;
    case 3: {
        WorldDescriptor descriptor(s_cityParts[s_curCityPart]);
        if (s_curCityStep == 0) {
            loadCityVisual(descriptor);
            ++s_curCityPart;
        } else {
            loadCityGameObjects(descriptor, true);
            ++s_curCityPart;
        }
        if (s_curCityPart >= s_cityPartsNum) {
            s_curCityPart = 0;
            ++s_curCityStep;
        }
        if (s_curCityPart < s_cityPartsNum && s_curCityStep <= 1)
            return 3;
        return 4;
    }
    case 4: {
        sunNode = city->getSceneNodeFromUID(loadingSun);
        ++sunNode->references;
        city->getSceneNodesFromType(irr::scene::ESNT_LIGHT, lightsNodes);
        for (int i = 0; i < lightsNodes.used; ++i) {
            irr::scene::ISceneNode* parent = lightsNodes.data[i]->getParent();
            manager->getRootSceneNode()->addChild(lightsNodes.data[i]);
            if (parent)
                CCustomSceneManager::CleanParents(parent);
            lightsNodes.data[i]->setRelativeTransformation(const_cast<irr::core::matrix4&>(lightsNodes.data[i]->getAbsoluteTransformation()));
        }
        irr::video::IVideoDriver* currentDriver = Application::GetInstance()->GetDevice()->getVideoDriver();
        SetMaterialTypeCondition(city, irr::video::MaterialType15, currentDriver->getTexture(cityPropsAlpha));
        SetMaterialTypeCondition(city, irr::video::MaterialType15, currentDriver->getTexture(cityPropsAlphaAlt));
        OctTreeAABB* createdTree = static_cast<OctTreeAABB*>(::operator new(sizeof(OctTreeAABB)));
        _ZN11OctTreeAABBC1EPN3irr5scene10ISceneNodeEj(createdTree, city, 20);
        sceneOcttree = createdTree;
        SetVisibility(city, true);
        CCustomSceneManager* custom = reinterpret_cast<CCustomSceneManager*>(manager);
        custom->setBatchRoot(city);
        manager->disableCulling();
        reinterpret_cast<irr::scene::CSceneManager*>(manager)->collectAllNodes();
        manager->enableCulling();
        custom->compileBatch();
        custom->toggleCullBatch();
        reinterpret_cast<LoadingRenderableFields*>(custom->getRenderableNodeList())->count = 0;
        return 5;
    }
    case 5:
        gom = GameObjectManager::s_gom;
        for (int i = 0; i < s_cityPartsNum; ++i) {
            WorldDescriptor descriptor(s_cityParts[i]);
            loadCityGameObjects(descriptor, false);
            delete[] s_cityParts[i];
        }
        delete[] s_cityParts;
        SpawnPoint::CreateAllSpawnInstances();
        CameraManager::getInstance();
        CameraManager::getInstance()->getCamera()->setFarValue(9000.0f);
        return 6;
    case 6: {
        irr::scene::ISceneNode* heightmap = irr::collada::CColladaDatabase::constructScene(loadingHeightmap, &irr::collada::CColladaDatabase::DefaultFactory);
        PhysicAttributes::CreateNeighborTris(heightmap, 0);
        heightmap->drop();
        PhysicAttributes::LoadArrays(const_cast<char*>(loadingNavigation));
        PhysicAttributes::InitWorld();
        LastVisibleNodes = newPointerArray<CollisionBodyDef>();
        VisibleNodes = newPointerArray<CollisionBodyDef>();
        LastVisibleSceneNodes = newPointerArray<irr::scene::ISceneNode>();
        VisibleSceneNodes = newPointerArray<irr::scene::ISceneNode>();
        VisibleSpawnPoint = newPointerArray<SpawnPoint>();
        return 7;
    }
    case 7: {
        driver->setOption(16, false);
        skyBox = new CustomSkyBoxSceneNode(driver->getTexture(loadingBackground), sunNode, 0);
        skyBoxTexture = skyBox->getMaterial(0).layers[0].texture;
        driver->setOption(16, true);
        manager->getRootSceneNode()->addChild(skyBox);
        skyBox->setRotation(makeLoadingQuaternion(-1.5707963705062866f, 0, 0));
        skyBox->drop();
        return 8;
    }
    case 8: {
        sunGlow = manager->addBillboardSceneNode(0, irr::core::dimension2d<float>(10,10),
            irr::core::vector3d<float>(0,0,0), -1,
            irr::video::SColor(255,255,255,255), irr::video::SColor(255,255,255,255));
        loadingBillboardNode(*sunGlow).setMaterialTexture(0, driver->getTexture(loadingGlow));
        loadingBillboardNode(*sunGlow).setMaterialType(irr::video::MaterialType13);
        loadingBillboardNode(*sunGlow).setMaterialFlag(irr::video::MaterialFlag2, false);
        loadingBillboardNode(*sunGlow).setMaterialFlag(static_cast<irr::video::E_MATERIAL_FLAG>(128), false);
        loadingBillboardNode(*sunGlow).setMaterialFlag(irr::video::MaterialFlag256, false);
        loadingBillboardNode(*sunGlow).setMaterialFlag(irr::video::MaterialFlag512, false);
        sunGlow->setSize(irr::core::dimension2d<float>(2048,2048));
        irr::core::vector3d<float> position = sunNode->getPosition();
        position.normalize();
        position *= 1000.0f;
        loadingBillboardNode(*sunGlow).setPosition(position);
        loadingBillboardNode(*sunGlow).setRenderingLayer(-1);
        loadingBillboardNode(*sunGlow).setVisible(true);
        manager->getActiveCamera()->addChild(sunGlow ? &loadingBillboardNode(*sunGlow) : 0);
        return 9;
    }
    case 9: {
        b2World* const world = PhysicAttributes::s_world;
        playerTest = new PlayerTest(world);
        const unsigned char type = reinterpret_cast<const unsigned char*>(playerTest)[40];
        gom->AddGameObjectOfType(LevelObject::s_type[type]);
        application->GetWeaponManager()->init();
        application->GetWeaponManager()->setPlayer(reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(playerTest)));
        CHudManager* hud = application->GetHudManager();
        LevelObject* followed = reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(playerTest));
        MiniMap* map = reinterpret_cast<MiniMap*>(hud->minimap);
        if (map)
            map->setFollowedObject(followed);
        playerTest->switchContext(PlayerTest::Context0, false);
        return 10;
    }
    case 10:
        for (int i = 0; i < 3; ++i) {
            for (LevelObject* object = gom->GetFirst(i); object; object = object->next) {
                switch (LevelObject::s_type[object->getObjectType()]) {
                case 5: object->init(); break;
                case 15:
                    if (reinterpret_cast<LoadingType15Fields*>(object)->value == 3) {
                        MiniMap* map = reinterpret_cast<MiniMap*>(application->GetHudManager()->minimap);
                        if (map)
                            map->registerForMapTracking(object, false);
                    }
                    break;
                case 4: application->GetWeaponManager()->addWeapon(static_cast<Weapon*>(object)); break;
                }
                CleanNode(reinterpret_cast<LoadingObjectFields*>(object)->sceneNode);
            }
        }
        return 11;
    case 11: {
        GSLoading::setGameLoaded(true);
        ScriptManager* scripts = ScriptManager::getInstance();
        _ZN13ScriptManager7debugOnE = false;
        scripts->loadMissions(loadingMissions);
        bool continuing = static_cast<Menus::MainMenu*>(MenuManager::getInstance()->getState(loadingMainMenu))->GameContinue();
        scripts->loadScript(loadingScripts, continuing);
        LevelObject::loadHighlights(loadingHighlights);
        Character::loadBloodObjects(loadingBloodPuddle, loadingBloodParticle);
        ScriptManager::s_playerTest = playerTest;
        CameraManager::getInstance()->enterMode(0,
            reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(playerTest)), 0, 0);
        return 12;
    }
    case 12:
        s_bulletManager = new BulletTraceManager();
        manager->getRootSceneNode()->addChild(s_bulletManager);
        s_bulletManager->drop();
        s_TrailMgr = new TrailMgr();
        s_TrailMgr->Init(4, 60, 0, 600, 25.0f, 0.15f);
        driver->setFog(irr::video::SColor(255,255,218,160), true,
            static_cast<float>(s_phonePerformanceProfile.unknown4 - 13000),
            static_cast<float>(s_phonePerformanceProfile.unknown4 + 10000), 0.00001f, false, false);
        driver->setOrientation3D(irr::video::OrthoOrientation0);
        driver->setOrthoOrientation(irr::video::OrthoOrientation0);
        WantedLevelManager::getInstance();
        return 13;
    case 13: {
        SoundManager::getInstance()->allocBuffers();
        CameraManager::getInstance()->setTouchScreenInputs(!ScriptManager::getInstance()->isInCinematic());
        application->SetDrawAll(true);
        CControlManager* controls = Application::GetInstance()->GetControlManager();
        controls->init();
        if (controls->isLocked())
            controls->unlock();
        int playlist = _ZNK11MenuManager11getPlaylistEv(MenuManager::getInstance());
        if (playlist > -2) {
            SoundManager::getInstance()->initIPod();
            SoundManager::getInstance()->useIPodRadio();
            SoundManager::getInstance()->setPlaylist(playlist);
        }
        return 14;
    }
    }
}

// Unapplied compile-time requirements; no current layout claim without GCC proof.
typedef char load_pointer_4[(sizeof(void*) == 4) ? 1 : -1];
typedef char load_quaternion_16[(sizeof(irr::core::quaternion) == 16) ? 1 : -1];
typedef char load_vector_12[(sizeof(irr::core::vector3d<float>) == 12) ? 1 : -1];
typedef char load_player_516[(sizeof(PlayerTest) == 516) ? 1 : -1];
typedef char load_octtree_16[(sizeof(OctTreeAABB) == 16) ? 1 : -1];
typedef char load_skybox_2304[(sizeof(CustomSkyBoxSceneNode) == 2304) ? 1 : -1];
typedef char load_bullet_1768[(sizeof(BulletTraceManager) == 1768) ? 1 : -1];
typedef char load_trail_24[(sizeof(TrailMgr) == 24) ? 1 : -1];
typedef char load_lights_20[(sizeof(GS3DLightNodes) == 20) ? 1 : -1];
typedef char load_array_20[(sizeof(irr::core::array<irr::scene::ISceneNode*>) == 20) ? 1 : -1];

namespace {
inline unsigned int colorAlpha(const irr::video::SColor& c) { return c.a; }
typedef unsigned int ColorWord __attribute__((may_alias));
inline __attribute__((always_inline)) bool sameColor(const irr::video::SColor& a, const irr::video::SColor& b)
{
    return reinterpret_cast<const ColorWord&>(a) == reinterpret_cast<const ColorWord&>(b);
}

inline __attribute__((always_inline)) void updateColorBlend(irr::video::SMaterial& m)
{
    if (!(m.flags40 & 2) || (m.unknown0 & 1) || sameColor(m.color84, m.color48)) {
        if (!(m.flags40 & 4))
            m.dirtyFlags |= 1;
        m.flags40 |= 4u;
    } else {
        if (m.flags40 & 4)
            m.dirtyFlags |= 1;
        m.flags40 &= ~4u;
    }
}
}

void GS3DStuff::SetAlpha(irr::scene::ISceneNode* node, unsigned char alpha, eColorType type)
{
    const int nodeType = node->getType();
    if (nodeType == 0x6d656164 || nodeType == 0x73656164) {
        if (type != Color0)
            return;

        irr::video::SMaterial& material = node->getMaterial(0);
        if ((unsigned int)alpha == colorAlpha(material.color84))
            return;

        material.dirtyFlags |= 8;
        material.color84.a = alpha;
        updateColorBlend(material);
    } else {
        applyToChildren(node, SetAlpha, alpha, type);
    }
}

namespace {
inline __attribute__((always_inline)) void setColor84(irr::video::SMaterial& m, const irr::video::SColor& c)
{
    if (sameColor(c, m.color84))
        return;
    m.dirtyFlags |= 8;
    m.color84 = c;
    updateColorBlend(m);
}

inline __attribute__((always_inline)) void setColor48(irr::video::SMaterial& m, const irr::video::SColor& c)
{
    if (sameColor(m.color48, c))
        return;
    m.dirtyFlags |= 4;
    m.color48 = c;
    updateColorBlend(m);
}

inline __attribute__((always_inline)) void setColor56(irr::video::SMaterial& m, const irr::video::SColor& c)
{
    if (sameColor(c, m.color56))
        return;
    m.dirtyFlags |= 4;
    m.color56 = c;
}

inline __attribute__((always_inline)) void setColor52(irr::video::SMaterial& m, const irr::video::SColor& c)
{
    if (sameColor(c, m.color52))
        return;
    m.dirtyFlags |= 4;
    m.color52 = c;
}
}

void GS3DStuff::SetColor(irr::scene::ISceneNode* node, irr::video::SColor color, eColorType type)
{
    const unsigned int a = color.a;
    const unsigned int b = color.b;
    const unsigned int g = color.g;
    const unsigned int r = color.r;
    const int nodeType = node->getType();
    if (nodeType == 0x6d656164 || nodeType == 0x73656164) {
        switch (type) {
        case Color0:
            setColor84(node->getMaterial(0), irr::video::SColor(a, r, g, b));
            break;
        case Color1:
            setColor48(node->getMaterial(0), irr::video::SColor(a, r, g, b));
            break;
        case Color2:
            setColor56(node->getMaterial(0), irr::video::SColor(a, r, g, b));
            break;
        case Color3:
            setColor52(node->getMaterial(0), irr::video::SColor(a, r, g, b));
            break;
        }
    } else {
        for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
             child != node->getChildren().end(); child = child->next) {
            SetColor(child->value, color, type);
        }
    }
}
namespace {
template<unsigned int offset>
inline unsigned int despawnWord(const LevelObject* object)
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(object) + offset);
}
}

LevelObject* GS3DStuff::checkForDespawn(LevelObject* object)
{
    using irr::core::vector3d;
    if (object->unknown4 & 0x490u) {
        PlayerTest* player = PlayerTest::GetPlayer();
        if (LevelObject::s_type[object->objectType] == 5 && !object->isDead()) {
            const vector3d<float> difference = static_cast<SavePositionInterface&>(*player).GetPosition() - object->GetPosition();
            if (despawnWord<428>(object) == 3 && (despawnWord<356>(object) & 0x200u) &&
                static_cast<float>(sqrt(difference.getLengthSQ())) < 15000.0f)
                return object;
        } else if (LevelObject::s_type[object->objectType] == 3 && !object->isDead()) {
            const vector3d<float> difference = static_cast<SavePositionInterface&>(*player).GetPosition() - object->GetPosition();
            if (despawnWord<240>(object) == 3 && (despawnWord<344>(object) & 0x1000u) &&
                static_cast<float>(sqrt(difference.getLengthSQ())) < 15000.0f)
                return object;
            if (object == player->unknown368 || object == player->unknown312 || object == player->unknown316)
                return object;
        }

        int distanceSquared = 9000000;
        const SpawnPoint::Center* center = &SpawnPoint::s_outterCenterCiv;
        if (LevelObject::s_type[object->objectType] == 3) {
            center = &SpawnPoint::s_outterCenterCar;
            distanceSquared = 32397042;
        }
        if ((object->unknown4 & 0x800u) ||
            object->GetPosition().getDistanceFromSQ(reinterpret_cast<const vector3d<float>&>(*center)) >= static_cast<float>(distanceSquared) ||
            LevelObject::s_type[object->objectType] == 12)
            object = gom->despawn(object);
    }
    return object;
}

#include "../world/LevelObject.h"
#include "../core/CameraManager.h"
#include "../core/Physics.h"
#include "../vehicles/Vehicle.h"
#include "../meta/Item.h"
#include "../world/SpawnPoint.h"
#include "../characters/PhysicAttributes.h"
#include "../world/SceneNodeManager.h"
#include "../world/TrailMgr.h"

// Partial call interfaces for the update loop. No complete layouts are asserted.

struct UpdateApplicationView {
    unsigned char unknown0[96];
    float accumulatedTime;
    int stepCount;
};
struct UpdateObjectView {
    unsigned int unknown0;
    unsigned int flags;
    unsigned int unknown8;
    LevelObject* next;
    irr::scene::ISceneNode* node;
};
struct UpdatePlayerBody {
    unsigned char unknown0[64];
    float value64;
    float value68;
};
struct UpdatePlayerView {
    unsigned char unknown0[184];
    UpdatePlayerBody* body;
    unsigned char unknown188[184];
    int value372;
};

inline bool updatePlayerInVehicle(const PlayerTest* player) {
    return (player->flags240 & 1024) && static_cast<const SavePositionInterface*>(player)->getVehicle();
}
inline bool updatePlayerInVehicleRef(const PlayerTest* player) {
    return (player->flags240 & 1024) && static_cast<const SavePositionInterface&>(*player).getVehicle();
}

namespace UpdateMath {
template<class T> inline const T& min(const T& a, const T& b) { return a < b ? a : b; }
template<class T> inline const T& max(const T& a, const T& b) { return a < b ? b : a; }
template<class T> inline const T clamp(const T& value, const T& low, const T& high) {
    return min(max(value, low), high);
}
}


extern "C" double _ZNK12StateMachine12getTimeStampEv(const StateMachine*);

void GS3DStuff::update(StateMachine* state)
{
    Application* application = Application::GetInstance();
    b2World* world = PhysicAttributes::s_world;
    if (s_vehicle) {
        s_vehicle->initializeDriver();
        s_vehicle = 0;
    }
    SceneNodeManager::getInstance()->update(static_cast<int>(_ZNK12StateMachine12getTimeStampEv(state)));
    unsigned int now = application->GetDevice()->getTimer()->getRealTime();
    unsigned int elapsed = now - lastTime;
    const int step = elapsed;
    CameraManager::getInstance()->getCamera();
    SpawnPoint::UpdateSpawnCenters();

    for (LevelObject* object = gom->GetFirst(1); object; object = object->next)
        object->Update(step);

    static std::vector<Vehicle*> vehicles;
    static std::vector<Item*> pickables;
    vehicles.clear();
    pickables.clear();
    LevelObject* object = gom->GetFirst(0);
    while (object) {
        LevelObject* checked = checkForDespawn(object);
        if (!checked) break;
        if (checked != object) {
            object = checked;
            continue;
        }
        LevelObject* next = object->next;
        UpdateObjectView* view = reinterpret_cast<UpdateObjectView*>(object);
        if (view->node && view->node->isVisible()) {
            switch (LevelObject::s_type[object->getObjectType()]) {
            case 3: vehicles.push_back(static_cast<Vehicle*>(object)); break;
            default: object->Update(elapsed); break;
            }
            if (view->flags & 8)
                pickables.push_back(static_cast<Item*>(object));
        }
        object = next;
    }
    playerTest->Update();
    UpdateApplicationView* app = reinterpret_cast<UpdateApplicationView*>(application);
    int frameDelta = UpdateMath::clamp(static_cast<int>(elapsed), 0, 250);
    app->accumulatedTime += frameDelta / 1000.0f;
    app->stepCount = 0;
    for (int i = 0; i < vehicles.size(); i++)
        vehicles[i]->Update(elapsed);
    while (app->accumulatedTime >= 1.0f / 60.0f) {
        for (int i = 0; i < vehicles.size(); i++)
            vehicles[i]->UpdatePhysic(1.0f / 60.0f);
        world->Step(1.0f / 60.0f, 10);
        for (int i = 0; i < vehicles.size(); i++)
            vehicles[i]->stepPhysic();
        app->accumulatedTime -= 1.0f / 60.0f;
        app->stepCount += 1.0f;
    }
    UpdatePlayerView* player = reinterpret_cast<UpdatePlayerView*>(playerTest);
    player->body->value64 = player->body->value68 = 0;
    if (!updatePlayerInVehicleRef(playerTest)) playerTest->UpdateSceneNode();
    for (int i = 0; i < vehicles.size(); i++)
        vehicles[i]->step();
    if (!updatePlayerInVehicle(playerTest)) {
        if (!reinterpret_cast<UpdatePlayerView*>(playerTest)->value372)
            checkVehicleProximity(vehicles);
    }
    checkPickableProximity(pickables);
    ScriptManager::getInstance()->update(elapsed);
    CameraManager::getInstance()->update(static_cast<float>(elapsed));
    WantedLevelManager::getInstance()->update(static_cast<double>(elapsed));
    s_TrailMgr->Update();
    lastTime = now;
    updateVisibility(elapsed);
    if (!drawable) {
        if (unknown24 > 0) {
            drawable = true;
            reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->eventManager->attach(4, this);
        }
        ++unknown24;
    }
}


#include "../core/Physics.h"
#include "../core/VideoDriver.h"
extern "C" void _ZN9GS3DStuff8DrawBodyEP6b2BodyN3irr5video6SColorE(GS3DStuff* self,
    b2Body* body, irr::video::SColor color)
{
    irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();
    // No-code hint: c3/c0/c1 first hold earlier real values (vehicle Z, player Z,
    // the else-arm height sum) so their rotation SSA partitions become out-of-SSA
    // temps created after the vtable spill temp -> spill slots c2<vfn<c3<c0<c1.
    float c3, c0, c1;
    c0 = GS3DStuff::playerTest->GetPosition().Z;
    float height;
    if (GS3DStuff::playerTest->getVehicle())
        height = 200.0f + (c3 = GS3DStuff::playerTest->getVehicle()->GetPosition().Z);
    else
        height = (c1 = c0 + 200.0f);
    for (b2Shape* shape = body->shapeList; shape; shape = shape->next) {
        const b2XForm& xf = body->GetXForm();
        float px, py;
        float c2;
        py = xf.position.y;
        px = xf.position.x;
        b2Vec2 points[4];
        b2PolygonShape* polygon = static_cast<b2PolygonShape*>(shape);
        const b2Vec2* v = polygon->vertices;
        // Rotation components read once (load order c0, c2, c1, c3); the
        // declaration order only sets their pseudo/spill-slot numbering.
        c0 = xf.rotation[0];
        c2 = xf.rotation[2];
        c1 = xf.rotation[1];
        c3 = xf.rotation[3];
        for (int i = 0; i < 4; ) {
            // No-code hint: increment at loop top + user label splits the header so
            // ivopts sees the points stores before the vertex loads (points IV init
            // emitted first in the preheader).
            int j = i++;
            load_v:
            float vx = v[j].x;
            float vy = v[j].y;
            float x = vx * c0 + c2 * vy;
            float y = vx * c1 + vy * c3;
            y = y + py;
            x = x + px;
            x = x * 100.0f;
            store_x:
            points[j].x = x;
            y = y * 100.0f;
            store_y:
            points[j].y = y;
        }
        for (int i = 0; i < 4; i++) {
            if (i == 3)
                driver->draw3DLine(irr::core::vector3d<float>(points[3].x, points[3].y, height),
                    irr::core::vector3d<float>(points[0].x, points[0].y, height), color);
            else
                driver->draw3DLine(irr::core::vector3d<float>(points[i].x, points[i].y, height),
                    irr::core::vector3d<float>(points[i + 1].x, points[i + 1].y, height), color);
        }
        PhysicsBodyData* data = static_cast<PhysicsBodyData*>(shape->GetBody()->GetUserData());
        if (data && !data->node) {
            driver->draw3DLine(irr::core::vector3d<float>(px * 100.0f, py * 100.0f, data->lowerHeight),
                irr::core::vector3d<float>((px + (c0 = xf.rotation[0]) /* no-code hint: later c0/c3 defs order their temp groups */) * 100.0f,
                    (py + xf.rotation[1]) * 100.0f, data->lowerHeight),
                irr::video::SColor(255, 0, 0, 255));
            driver->draw3DLine(irr::core::vector3d<float>(px * 100.0f, py * 100.0f, data->lowerHeight),
                irr::core::vector3d<float>((px + xf.rotation[2]) * 100.0f,
                    (py + (c3 = xf.rotation[3])) * 100.0f, data->lowerHeight),
                irr::video::SColor(255, 0, 255, 0));
            driver->draw3DLine(irr::core::vector3d<float>(px * 100.0f, py * 100.0f, data->lowerHeight),
                irr::core::vector3d<float>(px * 100.0f, py * 100.0f, data->upperHeight),
                irr::video::SColor(255, 255, 0, 0));
        } else {
            driver->draw3DLine(irr::core::vector3d<float>(px * 100.0f, py * 100.0f, height),
                irr::core::vector3d<float>((px + xf.rotation[0]) * 100.0f,
                    (py + xf.rotation[1]) * 100.0f, height),
                irr::video::SColor(255, 0, 0, 255));
            driver->draw3DLine(irr::core::vector3d<float>(px * 100.0f, py * 100.0f, height),
                irr::core::vector3d<float>((px + xf.rotation[2]) * 100.0f,
                    (py + xf.rotation[3]) * 100.0f, height),
                irr::video::SColor(255, 0, 255, 0));
        }
    }
}

extern "C" float fabsf(float);
extern "C" bool _ZNK7Vehicle11isDoorClearEbP6b2Body(const Vehicle* self, bool left, b2Body* body);

struct ProximityVehicleView {
    unsigned char unknown0[928];
    int proximityRange;
};

static inline bool inRange(float delta, float range)
{
    return fabsf(delta) < range;
}



static inline bool playerInVehicle(PlayerTest* player)
{
    return (player->flags240 & 0x400) && static_cast<SavePositionInterface*>(player)->getVehicle();
}


static inline bool isNear(const irr::core::vector3d<float>& delta, float range)
{
    return inRange(delta.X, range) && inRange(delta.Y, range) && inRange(delta.Z, range);
}

void GS3DStuff::checkPickableProximity(std::vector<Item*>& items)
{
    irr::core::vector3d<float> center;
    float range;
    if (playerInVehicle(playerTest)) {
        center = playerTest->getVehicle()->GetPosition();
        range = 300.0f;
    } else {
        center = static_cast<SavePositionInterface&>(*playerTest).GetPosition();
        range = 100.0f;
    }
    // The increment goes through a pointer round trip (a no-op on this 32-bit
    // target); it keeps the counter out of scalar evolution, as in retail.
    for (int i = 0; i < items.size(); i = reinterpret_cast<int>(reinterpret_cast<char*>(i) + 1)) {
        irr::core::vector3d<float> d = items[i]->GetPosition() - center;
        if (!isNear(d, range))
            continue;
        if (LevelObject::s_type[items[i]->getObjectType()] == 15)
            items[i]->pickup();
    }
}

static inline LevelObject* refreshNearCar(PlayerTest* const& playerTest)
{
    LevelObject* car;
    if ((car = playerTest->unknown312) != 0 || (car = playerTest->unknown368) != 0) {
        if (!car->isDead() && !ScriptManager::getInstance()->isInCinematic()) {
            Application::GetInstance()->GetHudManager()->nearCar();
            return car;
        }
    }
    Application::GetInstance()->GetHudManager()->notNearCar();
    return car;
}

namespace {
enum { colladaSceneNode = 0x6e656164, colladaInstanceNode = 3 };

struct ColladaInstanceView {
    int type;
    const char* const* url;
};

struct ColladaNodeView {
    unsigned int unknown0[16];
    int instanceCount;
    ColladaInstanceView* instances;
};

struct ColladaSceneNodeView {
    unsigned char unknown0[364];
    ColladaNodeView* sourceNode;
};

struct LODLevelView {
    float distanceSquared;
    irr::scene::ISceneNode* sceneNode;
};

struct LODSceneNodeView {
    unsigned char unknown0[328];
    LODLevelView* levels;
};
}

extern "C" void _ZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_(
    irr::scene::ISceneNode*, irr::scene::ISceneNode*, irr::scene::ISceneNode*, irr::scene::ISceneNode*);

void GS3DStuff::AddXRef(irr::scene::ISceneNode* node)
{
    ++node->references;
    node->updateAbsolutePosition(false);
    irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();

    if (node->getType() == colladaSceneNode) {
        bool replaced = false;
        const ColladaSceneNodeView* view = reinterpret_cast<const ColladaSceneNodeView*>(node);
        if (view->sourceNode) {
            for (int i = 0; i < view->sourceNode->instanceCount; ++i) {
                const ColladaInstanceView& instance = view->sourceNode->instances[i];
                if (instance.type != colladaInstanceNode || !*instance.url)
                    continue;

                irr::scene::ISceneNode* xref = irr::collada::CColladaDatabase::constructScene(
                    *instance.url, CGameFactory::getInstance());
                SetMaterialTypeCondition(xref, irr::video::MaterialType15, driver->getTexture(cityPropsAlpha));
                SetMaterialTypeCondition(xref, irr::video::MaterialType15, driver->getTexture(cityPropsAlphaAlt));
                irr::video::SColor black;
                // Dead store, overwritten by the constructor below; it only pads
                // the gcse hash table to retail's bucket count (GOT spill slots).
                const unsigned int wide = reinterpret_cast<unsigned int>(xref);
                reinterpret_cast<signed char&>(black.b) = static_cast<signed char>(wide * wide * wide * wide * wide * wide * wide * wide * wide);
                new (&black) irr::video::SColor(0, 0, 0, 0);
                SetColor(xref, black, Color3);
                SetCulling(xref, irr::scene::EAC_FRUSTUM_BOX);
                LODSceneNode* lod = parseSceneNodeForLOD(xref, 0);
                xref->setPosition(node->getPosition());
                xref->setRotation(node->getRotation());
                if (lod) {
                    lod->setLODNodesPosition(node->getPosition());
                    lod->setLODNodesRotation(node->getRotation());
                    const LODSceneNodeView* lodView = reinterpret_cast<const LODSceneNodeView*>(lod);
                    lodView->levels[0].sceneNode->setVisible(true);
                    irr::scene::ISceneNode* mesh = FindAMesh(lodView->levels[0].sceneNode);
                    char value[256];
                    // Taking the label address only pins the billboard block's
                    // label; the value is unused, so no computed jump exists.
                    void* const billboardLabel = &&billboardBlock;
                    (void)billboardLabel;
                    if (getProperty(lodView->levels[0].sceneNode->getUserProperty(),
                            GameFactoryProperties::billboard, value) && atoi(value) == 1)
                        goto billboardBlock;
                    _ZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_(
                        xref, mesh, mesh, 0);
                    {
                        irr::scene::ISceneNode* parent = lodView->levels[0].sceneNode->getParent();
                        node->getParent()->addChild(lodView->levels[0].sceneNode);
                        if (parent)
                            CCustomSceneManager::CleanParents(parent);
                    }
                billboardDone:
                    lod->drop();
                    goto xrefDrop;

                    // The billboard arm sits after the LOD release so it is expanded
                    // there; its own copy of the attach tail then rejoins at
                    // billboardDone. The non-billboard arm is written as the goto's
                    // fall-through so VRP threading moves it to the function end.
                billboardBlock:
                    _ZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_(
                        xref, lodView->levels[0].sceneNode, mesh, 0);
                    lodView->levels[0].sceneNode->setVisible(false);
                    {
                        irr::scene::ISceneNode* parent = lodView->levels[0].sceneNode->getParent();
                        node->getParent()->addChild(lodView->levels[0].sceneNode);
                        if (parent)
                            CCustomSceneManager::CleanParents(parent);
                    }
                    goto billboardDone;
                } else {
                    irr::scene::ISceneNode* mesh = FindAMesh(xref);
                    _ZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_(
                        xref, mesh, mesh, node);
                    irr::scene::ISceneNode* parent = xref->getParent();
                    node->getParent()->addChild(xref);
                    if (parent)
                        CCustomSceneManager::CleanParents(parent);
                }
            xrefDrop:
                xref->drop();

                irr::scene::ISceneNode* parent = node->getParent();
                node->remove();
                if (parent)
                    CCustomSceneManager::CleanParents(parent);
                replaced = true;
            }
        }

        if (node->getParent() && reinterpret_cast<const unsigned int&>(node->getChildren().first) ==
                reinterpret_cast<unsigned int>(node->getChildren().end())) {
            irr::scene::ISceneNode* parent = node->getParent();
            node->remove();
            if (parent)
                CCustomSceneManager::CleanParents(parent);
            goto release;
        }
        if (replaced)
            goto release;
    }

    {
        irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
        while (child != node->getChildren().end()) {
            irr::scene::ISceneNode* current = child->value;
            child = child->next;
            AddXRef(current);
        }
    }
release:
    node->drop();
}

extern "C" bool _ZN9GS3DStuff21checkVehicleProximityERSt6vectorIP7VehicleSaIS2_EE(GS3DStuff* self, std::vector<Vehicle*>& vehicles)
{
    PlayerTest* const& playerTest = GS3DStuff::playerTest;
    irr::core::vector3d<float> center = static_cast<SavePositionInterface&>(*playerTest).GetPosition();
    LevelObject* nearest = 0;
    irr::core::vector3d<float> best(0.0f, 0.0f, 0.0f);
    for (int i = 0; i < vehicles.size(); i++) {
        irr::core::vector3d<float> d = vehicles[i]->GetPosition() - center;
        Vehicle* vehicle = vehicles[i];
        float range = reinterpret_cast<ProximityVehicleView*>(vehicle)->proximityRange;
        if (inRange(d.X, range) && inRange(d.Y, range) && inRange(d.Z, range)
            && (!nearest || d.getLengthSQ() < best.getLengthSQ())
            && (_ZNK7Vehicle11isDoorClearEbP6b2Body(vehicle, true, playerTest->collisionBody)
                || _ZNK7Vehicle11isDoorClearEbP6b2Body(vehicles[i], false, playerTest->collisionBody))) {
            nearest = vehicles[i];
            best = d;
        }
    }
    if (nearest && !nearest->isDead()) {
        if (!Application::GetInstance()->GetHudManager()->isNearShop()) {
            Application::GetInstance()->GetHudManager()->nearCar();
            playerTest->unknown312 = nearest;
            return true;
        }
    }
    playerTest->unknown312 = 0;
    nearest = refreshNearCar(playerTest);
    return false;
}

extern "C" void _ZN3irr4core8aabbox3dIfE14addInternalBoxERKS2_(irr::core::aabbox3d<float>*,
    const irr::core::aabbox3d<float>&) __attribute__((weak));

OctTreeAABB::OctTreeAABB(irr::scene::ISceneNode* node, unsigned int maxDepth)
    : nodeId(0), nodeCount(0)
{
    roots = newPointerArray<RootNode>();
    int count = CountRenderableNodes(node);
    roots->reallocate(count);
    BuildRootNodes(node, roots);
    BuildSpawnPointNodes(roots);
    irr::core::aabbox3d<float> box(irr::core::vector3d<float>(-1.0f, -1.0f, -1.0f));
    box.MaxEdge = irr::core::vector3d<float>(1.0f, 1.0f, 1.0f);
    irr::core::array<RootNode*>* storage = roots;
    // Reading the count through a byte offset keeps the later null test, as in retail.
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(storage) + 8) != 0) {
        irr::core::vector3d<float> center = (roots->data[0]->bounds.MinEdge + roots->data[0]->bounds.MaxEdge) * 0.5f;
        box.MaxEdge = center;
        box.MinEdge = center;
        for (unsigned int i = 0; i < roots->used; ++i)
            _ZN3irr4core8aabbox3dIfE14addInternalBoxERKS2_(&box, roots->data[i]->bounds);
        nodeCount = count;
        root = new OctTreeAABBNode(nodeId, 0, roots, maxDepth, box);
    } else if (storage) {
        // Retail lays the data delete out as the fall-through path.
        if (__builtin_expect(storage->free_when_destroyed, 1))
            ::operator delete(storage->data);
        ::operator delete(storage);
    }
}
