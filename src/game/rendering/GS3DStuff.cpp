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

class b2ShapeDef {
public:
    virtual ~b2ShapeDef() {}
};

class b2PolygonDef : public b2ShapeDef {
public:
    virtual ~b2PolygonDef() __attribute__((used)) {}
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
        inline ~OctTreeAABBNode();
        void getPolysIter(const irr::core::aabbox3d<float>& box,
            irr::core::array<CollisionBodyDef*>* collisions, irr::core::array<SpawnPoint*>* spawns,
            irr::core::array<irr::scene::ISceneNode*>* nodes) const __attribute__((weak));
        irr::core::aabbox3d<float> bounds;
        irr::core::array<RootNode*>* roots;
        OctTreeAABBNode* children[8];
        int depth;
    };

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
    unsigned char unknown8[8];
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

namespace std {
template<class T> struct char_traits;
template<class T, class Traits = char_traits<T>, class Alloc = allocator<T> >
class basic_string {
public:
    basic_string& append(const T* text);
private:
    basic_string& _M_append(const T* first, const T* last) __attribute__((weak));
};
template<>
basic_string<char>& basic_string<char>::append(const char* text)
{
    return _M_append(text, text + strlen(text));
}
}

extern "C" {
extern std::vector<Item*> _ZZN9GS3DStuff6updateEP12StateMachineE9pickables
    __attribute__((visibility("hidden")));

static void __tcf_8() __attribute__((used));
static void __tcf_8()
{
    typedef stlp_priv::_Vector_base<Item*, std::allocator<Item*> > Base;
    static_cast<Base&>(_ZZN9GS3DStuff6updateEP12StateMachineE9pickables).~Base();
}
}

extern "C" {
extern std::vector<Vehicle*> _ZZN9GS3DStuff6updateEP12StateMachineE8vehicles
    __attribute__((visibility("hidden")));

static void __tcf_7() __attribute__((used));
static void __tcf_7()
{
    typedef stlp_priv::_Vector_base<Vehicle*, std::allocator<Vehicle*> > Base;
    static_cast<Base&>(_ZZN9GS3DStuff6updateEP12StateMachineE8vehicles).~Base();
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
