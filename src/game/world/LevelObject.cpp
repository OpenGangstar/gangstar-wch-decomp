/*
 * LevelObject
 *
 * Original file: LevelObject.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of LevelObject.cpp here, in the order they appear in the library.
 */

#include "../core/LocalStartupText.h"
#include "LevelObject.h"
#include "../core/CameraManager.h"
#include "../core/Physics.h"
#include "../characters/Character.h"
#include "../vehicles/Vehicle.h"
#include "../core/LocalStartupStorage.h"
#include "SceneNodeManager.h"
#include "../characters/PhysicAttributes.h"
#include "GameObjectManager.h"
#include "ObjectData.h"
#include "../app/Application.h"
#include "../core/Collada.h"
#include "../core/NativeStdio.h"
#include "../app/CGameFactory.h"
#include "../persistence/DataStream.h"
#include "ResStream.h"
#include "../rendering/GS3DStuff.h"
#include "../characters/PlayerTest.h"
#include "../core/Lock.h"

// Observed PhysicInfo prefix used by the ID accessors, not a complete layout.
// Never instantiate this view or infer the full record extent from it.
struct LevelObjectPhysicsInfoView {
    unsigned short materialID;
    unsigned char unknown2[6];
    unsigned short triangleID;
};

void operator delete(void*) throw();
extern "C" {
static void __tcf_3(void*) __attribute__((used));
static void __tcf_3(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

// Retail emits these base defaults as weak definitions. Keep them local to
// this partial source unit without changing callers' inline visibility.
float __attribute__((weak)) LevelObject::GetSpeed() const
{
    return 0.0f;
}

void __attribute__((weak)) LevelObject::photographed() {}

void __attribute__((weak)) LevelObject::clearPhotographed() {}

bool __attribute__((weak)) LevelObject::isPhotographed() const
{
    return false;
}

void __attribute__((weak)) LevelObject::setSpawnType(int) {}

int __attribute__((weak)) LevelObject::getMaxHealth() const
{
    return 0;
}

int __attribute__((weak)) LevelObject::getHealth() const
{
    return 0;
}

bool __attribute__((weak)) LevelObject::isDead()
{
    return true;
}

void* __attribute__((weak)) LevelObject::getSkinMesh()
{
    return 0;
}

void __attribute__((weak)) LevelObject::applyDamage(int, LevelObject*, bool) {}

void __attribute__((weak)) LevelObject::setAnimationSpeedMultiplier(int) {}

void __attribute__((weak)) LevelObject::setNextAnimation(const char*, int, bool, bool, bool) {}

void __attribute__((weak)) LevelObject::setNextAnimation(int, int, bool, bool, bool) {}

void __attribute__((weak)) LevelObject::shooted(int, LevelObject*) {}

LevelObject::LevelObject(int)
{
    unknown4 = 0;
    previous = 0;
    next = 0;
    sceneNode = 0;
    unknown20 = 0;
    unknown24 = 0;
    unknown28 = 0;
    objectList = 0;
    objectType = 0xff;
    unknown40 = -1;
    unknown44 = -1;
    unknown48 = -1;
}

unsigned short LevelObject::GetMatID() const
{
    const LevelObjectPhysicsInfoView* info =
        reinterpret_cast<const LevelObjectPhysicsInfoView*>(unknown24->info);
    return info->materialID;
}

void LevelObject::Stop() {}

void LevelObject::setupSceneNode(int, irr::scene::ISceneNode*, int, void**) {}

void LevelObject::debug(irr::video::IVideoDriver*) {}

void LevelObject::WarmUp() {}

void LevelObject::init() {}

void LevelObject::clean() {}

void LevelObject::setup()
{
    for (int i = 0; i < 256; ++i) {
        s_type[i] = -1;
        s_nodePoolID[i] = 0xff;
        s_nodePoolMinimumSize[i] = 0;
    }
}

bool LevelObject::isEnabled() const { return unknown4 & 1; }

bool LevelObject::isVisibleOnScreen()
{
    irr::scene::ISceneNode* mesh = static_cast<irr::scene::ISceneNode*>(getSkinMesh());
    if (!mesh) return false;
    const irr::scene::SViewFrustum* frustum = CameraManager::getInstance()->getCamera()->getViewFrustum();
    return frustum->intersects(mesh->getTransformedBoundingBox());
}

bool LevelObject::isWithinRange(float range)
{
    return CameraManager::getInstance()->getCamera()->getPosition().getDistanceFrom(GetPosition()) <= range;
}


irr::core::vector3d<float> LevelObject::GetPosition() const
{
    return sceneNode->getAbsolutePosition();
}

void LevelObject::SetPosition(const irr::core::vector3d<float>& position)
{
    if (sceneNode) {
        sceneNode->setPosition(position);
        sceneNode->updateAbsolutePosition(false);
    }
}

void LevelObject::SetRotation(const irr::core::quaternion& rotation)
{
    if (sceneNode) sceneNode->setRotation(rotation);
}

const irr::core::quaternion& LevelObject::GetRotation() const
{
    return sceneNode->getRotation();
}

void LevelObject::freeHighlights()
{
    delete[] s_highlights;
    s_highlights = 0;
    delete[] s_highlightsIcons;
    s_highlightsIcons = 0;
}

void LevelObject::SetName(const char* name)
{
    delete[] unknown28;
    unknown28 = new char[strlen(name) + 1];
    strcpy(unknown28, name);
}

int LevelObject::GetMetatype()
{
    if (objectType == 0xff) objectType = GameObjectManager::s_gom->GetMetatypeFromName(unknown28);
    return objectType;
}

void LevelObject::loadHighlights(const char* filename)
{
    ResStream buffer(filename, 1);
    DataStream stream(buffer, DataStream::BigEndian);
    int count = stream.ReadInt();
    s_highlights = new int[count];
    for (int i = 0; i < count; ++i) {
        char* name = stream.ReadAndAllocateString();
        s_highlights[i] = SceneNodeManager::getInstance()->findOrCreatePool(name, 6, CGameFactory::getInstance());
        delete[] name;
    }
    count = stream.ReadInt();
    s_highlightsIcons = new int[count];
    for (int i = 0; i < count; ++i) s_highlightsIcons[i] = stream.ReadInt();
    stream.Close();
    buffer.Close();
}

void LevelObject::SetRotation(const irr::core::vector3d<float>& rotation)
{
    if (sceneNode) sceneNode->setRotation(irr::core::quaternion(rotation * 0.017453292f));
}

irr::scene::ISceneNode* LevelObject::grabSceneNode(int id, void*** parameters)
{
    if (s_nodePoolID[objectType] != 0xff && !sceneNode) {
        sceneNode = SceneNodeManager::getInstance()->grab(s_nodePoolID[objectType], this, id, parameters);
        sceneNode->setPosition(irr::core::vector3d<float>(0, 0, 0));
        sceneNode->updateAbsolutePosition(false);
        GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag2, true);
        GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag4, true);
        GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag16, true);
        sceneNode->setVisible(true);
    }
    return sceneNode;
}

void LevelObject::Update(int)
{
    if (s_nodePoolID[objectType] == 0xff) return;
    if (sceneNode) {
        if (!(unknown4 & 2)) dropSceneNode();
    } else if (unknown4 & 2) {
        grabSceneNode(0, 0);
    }
}

void LevelObject::showHighlight(int id)
{
    if (id >= 0) {
        unknown44 = s_highlightsIcons[id];
        int pool = s_highlights[id];
        if (unknown20 || !sceneNode) return;
        unknown20 = SceneNodeManager::getInstance()->grab(pool, 0, 0, 0);
        unknown48 = pool;
        GS3DStuff::SetMaterialFlag(unknown20, irr::video::MaterialFlag2, true);
        GS3DStuff::SetMaterialFlag(unknown20, irr::video::MaterialFlag4, true);
        GS3DStuff::SetMaterialFlag(unknown20, irr::video::MaterialFlag16, true);
        sceneNode->addChild(unknown20);
        unknown20->setVisible(true);
        unknown20->getAnimators().first->animator->getTimelineCtrl()->setLoop(true);
        irr::core::matrix4 identity;
        unknown20->setRelativeTransformation(identity);
        unknown20->updateAbsolutePosition(false);
    } else {
        if (!unknown20) return;
        unknown20->setVisible(false);
        if (unknown48 == 0xff) return;
        if (sceneNode) sceneNode->removeChild(unknown20);
        if (SceneNodeManager::getInstance()->drop(unknown48, unknown20))
            unknown20 = 0;
    }
}

void LevelObject::dropSceneNode()
{
    if (s_nodePoolID[objectType] != 0xff && sceneNode) {
        if (unknown20 && hasHighlightPool()) showHighlight(-1);
        sceneNode->setVisible(false);
        if (SceneNodeManager::getInstance()->drop(s_nodePoolID[objectType], sceneNode))
            sceneNode = 0;
    }
}

void LevelObject::disable()
{
    if (!isEnabled()) return;
    if (this == PlayerTest::GetPlayer()->getTarget()) {
        PlayerTest::GetPlayer()->SetTarget(0);
        if (Lock::getInstance()->target == this) Lock::getInstance()->setTarget(0);
    }
    GameObjectManager* manager = GameObjectManager::s_gom;
    unknown4 &= ~0x403u;
    if (sceneNode) {
        sceneNode->setVisible(false);
        if (hasSceneNodePool()) dropSceneNode();
    }
    manager->Remove(this);
    manager->Add(this, 2);
    manager->RemoveGameObjectOfType(getSpawnType());
    setSpawnType(s_type[objectType]);
    clearPhotographed();
}

void LevelObject::enable()
{
    unknown4 &= ~0x400u;
    if (!isEnabled()) {
        GameObjectManager* manager = GameObjectManager::s_gom;
        unknown4 |= 3;
        if (hasSceneNodePool() && !sceneNode) grabSceneNode(0, 0);
        if (sceneNode) sceneNode->setVisible(true);
        GameObjectManager::s_gom->Remove(this);
        GameObjectManager::s_gom->Add(this, 0);
        manager->AddGameObjectOfType(s_type[objectType]);
    }
}

void LevelObject::Load(const Structs::GameObjectBasic& data, irr::collada::CColladaFactory* factory)
{
    unknown28 = data.name;
    unknown40 = data.list;
    unknown4 = data.flags;
    objectType = GetMetatype();
    unknown44 = data.highlight;
    if (s_type[objectType] == -1) {
        s_type[objectType] = data.type;
        s_nodePoolMinimumSize[objectType] = data.poolSize;
    }
    if (data.sceneName[0]) {
        if (data.nodeName[0]) {
            sceneNode = irr::collada::CColladaDatabase::constructNode(data.sceneName, data.nodeName, factory);
        } else if (unknown4 & 0x200) {
            s_nodePoolID[objectType] = SceneNodeManager::getInstance()->findOrCreatePool(
                data.sceneName, s_nodePoolMinimumSize[objectType], factory);
        } else {
            sceneNode = irr::collada::CColladaDatabase::constructScene(data.sceneName, factory);
        }
    }
    delete[] data.nodeName;
    SetPosition(irr::core::vector3d<float>(data.position.X, data.position.Y, data.position.Z));
    SetRotation(irr::core::vector3d<float>(data.rotation.X, data.rotation.Y, data.rotation.Z));
    if (sceneNode) {
        GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag2, true);
        GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag4, true);
        GS3DStuff::SetMaterialFlag(sceneNode, irr::video::MaterialFlag16, true);
        GS3DStuff::SetColor(sceneNode, irr::video::SColor(255, 0, 0, 0), GS3DStuff::Color3);
        GS3DStuff::SetColor(sceneNode, irr::video::SColor(255, 255, 255, 255), GS3DStuff::Color0);
        GS3DStuff::SetColor(sceneNode, irr::video::SColor(255, 255, 255, 255), GS3DStuff::Color1);
        GS3DStuff::SetColor(sceneNode, irr::video::SColor(255, 255, 255, 255), GS3DStuff::Color2);
        sceneNode->setScale(irr::core::vector3d<float>(float(data.scale.X) * 0.01f, float(data.scale.Y) * 0.01f, float(data.scale.Z) * 0.01f));
        sceneNode->setVisible((unknown4 & 3) == 3);
        sceneNode->updateAbsolutePosition(false);
        Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(sceneNode);
    }
    objectList = GameObjectManager::s_gom->getObjectList(unknown40);
    setSpawnType(s_type[objectType]);
    delete[] data.sceneName;
}

LevelObject::~LevelObject()
{
    Application::GetInstance()->GetDevice()->getSceneManager();
    if (hasHighlightPool() && unknown20) {
        SceneNodeManager::getInstance()->drop(unknown48, unknown20);
    }
    if (sceneNode) {
        if (hasSceneNodePool()) {
            dropSceneNode();
        } else {
            sceneNode->remove();
            sceneNode->drop();
        }
    }
    delete[] unknown28;
    if (unknown24) {
        delete unknown24;
        unknown24 = 0;
    }
}

bool LevelObject::canSeeLevelObject(LevelObject* other, irr::core::vector3d<float>& point)
{
    b2World* world = PhysicAttributes::s_world;
    b2Shape* shapes[100] = {0};
    b2AABB bounds;
    if (GetPosition().X > other->GetPosition().X) {
        bounds.lowerBound.x = other->GetPosition().X / 100.0f;
        bounds.upperBound.x = GetPosition().X / 100.0f;
    } else {
        bounds.lowerBound.x = GetPosition().X / 100.0f;
        bounds.upperBound.x = other->GetPosition().X / 100.0f;
    }
    if (GetPosition().Y > other->GetPosition().Y) {
        bounds.lowerBound.y = other->GetPosition().Y / 100.0f;
        bounds.upperBound.y = GetPosition().Y / 100.0f;
    } else {
        bounds.lowerBound.y = GetPosition().Y / 100.0f;
        bounds.upperBound.y = other->GetPosition().Y / 100.0f;
    }
    if (bounds.lowerBound.x == bounds.upperBound.x) bounds.upperBound.x += 0.01f;
    if (bounds.lowerBound.y == bounds.upperBound.y) bounds.upperBound.y += 0.01f;
    world->Query(bounds, shapes, 100);
    float fraction = 1.0f;
    b2Vec2 normal;
    b2Segment segment;
    segment.p1.x = GetPosition().X / 100.0f;
    segment.p1.y = GetPosition().Y / 100.0f;
    segment.p2.x = other->GetPosition().X / 100.0f;
    segment.p2.y = other->GetPosition().Y / 100.0f;
    for (int i = 0; i < 100; ++i) {
        b2Shape* shape = shapes[i];
        if (!shape) break;
        if ((shape->GetFilterData().categoryBits == 0 &&
             (shape->GetFilterData().groupIndex != unknown24->getIndex() + 1 || shape->GetFilterData().maskBits == 0)) ||
            shape->IsSensor()) continue;
        PhysicsBodyData* data = static_cast<PhysicsBodyData*>(shape->GetBody()->GetUserData());
        if (other->LevelObject::getSpawnType() == 3 &&
            data->owner == static_cast<Vehicle*>(other)->getDriver()) continue;
        if (data && (data->owner == this || data->owner == other)) continue;
        if (shape->TestSegment(shape->GetBody()->GetXForm(), &fraction, &normal, segment, 1.0f)) {
            if (data->node != 0 || data->lowerHeight == data->upperHeight) break;
            float height = GetPosition().Z + (other->GetPosition().Z - GetPosition().Z) * fraction;
            if (LevelObject::getSpawnType() == 5 ||
                reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())) == this)
                height += 75.0f;
            if (height < data->lowerHeight || height > data->upperHeight) fraction = 1.0f;
            else break;
        }
    }
    irr::core::vector3d<float> start = GetPosition();
    irr::core::vector3d<float> end = other->GetPosition();
    irr::core::vector3d<float> heightNormal;
    if (LevelObject::getSpawnType() == 3) start.Z += 100.0f;
    else if (LevelObject::getSpawnType() == 5 ||
        reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())) == this)
        start.Z += 75.0f;
    if (other->LevelObject::getSpawnType() == 3) end.Z += 100.0f;
    else if (other->LevelObject::getSpawnType() == 5 ||
        reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())) == other)
        end.Z += 75.0f;
    float heightFraction = unknown24->IntersectSegmentWithHeightMap(start, end, point, heightNormal);
    if (heightFraction > fraction) {
        point = start + (end - start) * fraction;
    }
    return heightFraction == 1.0f && fraction == 1.0f;
}

void LevelObject::OnDespawn() { unknown4 &= ~1u; }
void LevelObject::OnSpawn() { unknown4 |= 0x81; }

unsigned short LevelObject::GetTriID() const
{
    const LevelObjectPhysicsInfoView* info =
        reinterpret_cast<const LevelObjectPhysicsInfoView*>(unknown24->info);
    return info->triangleID;
}

irr::core::vector3d<float> LevelObject::GetFront() const
{
    const irr::core::matrix4& matrix = sceneNode->getAbsoluteTransformation();
    return -irr::core::vector3d<float>(matrix[4], matrix[5], matrix[6]);
}

irr::core::vector3d<float> LevelObject::GetRight() const
{
    const irr::core::matrix4& matrix = sceneNode->getAbsoluteTransformation();
    return -irr::core::vector3d<float>(matrix[0], matrix[1], matrix[2]);
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_level_transitions {
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
        __aeabi_atexit(0, __tcf_3, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_level_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_level_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_level_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_level_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_level_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_level_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_level_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_level_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_level_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_level_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11LevelObject12s_highlightsE() __attribute__((used));
static void _GLOBAL__I__ZN11LevelObject12s_highlightsE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
