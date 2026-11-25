/*
 * LODSceneNode
 *
 * Original file: LODSceneNode.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of LODSceneNode.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN12LODSceneNodeC2EiRKN3irr4core8vector3dIfEERKNS1_10quaternionES5_() __attribute__((used));
static void _GLOBAL__I__ZN12LODSceneNodeC2EiRKN3irr4core8vector3dIfEERKNS1_10quaternionES5_()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

#include "LODSceneNode.h"
#include "../core/FactoryProducts.h"

LODSceneNode::LODSceneNode(int id, const irr::core::vector3d<float>& position,
    const irr::core::quaternion& rotation, const irr::core::vector3d<float>& scale)
    : ISceneNode(id, position, rotation, scale)
{
    levels.data = 0;
    levels.allocated = 0;
    levels.used = 0;
    levels.free_when_destroyed = true;
    levels.is_sorted = true;
    levels.unknown16 = 1;
    maxDistanceSquared = 100000000.0f;
    animationTime = 0.0f;
    lodLevel = 0;
}

void LODSceneNode::render(void*)
{
}

int LODSceneNode::getLODLevel() const
{
    return lodLevel;
}

void LODSceneNode::ComputeLOD(unsigned int)
{
}

void LODSceneNode::OnAnimate(unsigned int time)
{
    animationTime = static_cast<float>(time);
}

void LODSceneNode::setMaxDistance(int distance)
{
    maxDistanceSquared = static_cast<float>(distance * distance);
}

int LODSceneNode::getType() const
{
    return 'l' | ('o' << 8) | ('d' << 16) | ('n' << 24);
}

const irr::core::aabbox3d<float>& LODSceneNode::getBoundingBox() const
{
    return GetMeshBoundingBox(levels.data[lodLevel].sceneNode);
}

void LODSceneNode::OnRegisterSceneNode()
{
    if (visible) {
        computeLODLevel();
        if (getLODLevel() != -1)
            levels.data[lodLevel].sceneNode->OnAnimate(static_cast<unsigned int>(animationTime));
    }
}

const irr::core::aabbox3d<float>& LODSceneNode::GetMeshBoundingBox(
    const irr::scene::ISceneNode* node) const
{
    const int colladaMeshNode = 0x6d656164;
    const int colladaSkinnedNode = 0x73656164;
    if (node->getType() == colladaMeshNode || node->getType() == colladaSkinnedNode)
        return node->getBoundingBox();

    return GetMeshBoundingBox(node->getChildren().begin()->value);
}

const irr::core::aabbox3d<float>& LODSceneNode::getTransformedBoundingBox() const
{
    return GetMeshTransformedBoundingBox(levels.data[lodLevel].sceneNode);
}

void LODSceneNode::setLODNodesPosition(const irr::core::vector3d<float>& position)
{
    setLODNodesTransform<irr::core::vector3d<float>, &irr::scene::ISceneNode::setPosition>(position);
}

void LODSceneNode::setLODNodesRotation(const irr::core::quaternion& rotation)
{
    setLODNodesTransform<irr::core::quaternion, &irr::scene::ISceneNode::setRotation>(rotation);
}

LODSceneNode::~LODSceneNode()
{
    for (int index = 0; static_cast<unsigned int>(index) < levels.used; ++index)
        levels.data[index].sceneNode->drop();
    if (__builtin_expect(levels.free_when_destroyed, true))
        ::operator delete(levels.data);
}

void LODSceneNode::addAnimator(irr::scene::ISceneNodeAnimator* animator)
{
    for (int i = 0; static_cast<unsigned int>(i) < levels.used; ++i)
        levels.data[i].sceneNode->addAnimator(animator);
}

void LODSceneNode::removeAnimators()
{
    for (int index = 0; static_cast<unsigned int>(index) < levels.used; ++index)
        levels.data[index].sceneNode->removeAnimators();
}

void LODSceneNode::addLOD(irr::scene::ISceneNode* node, float distance)
{
    int index = 0;
    for (; static_cast<unsigned int>(index) != levels.used; ++index) {
        if (distance < levels.data[index].distanceSquared)
            break;
    }

    const SLODLevel level = { distance * distance, node };
    levels.insert(level, index);
    ++node->references;
    irr::scene::ISceneNode* parent = node->getParent();
    addChild(node);
    if (parent)
        CCustomSceneManager::CleanParents(parent);
    node->setVisible(false);
}

#include "../core/NativeSceneChildList.h"
// Genuine member ABI: this in r0, actual SDK const-list reference in r0.
extern "C" const irr::core::list<irr::scene::ISceneNode*>&
_ZNK3irr5scene10ISceneNode11getChildrenEv(const irr::scene::ISceneNode* node);

typedef char NativeChildListExtent[(sizeof(irr::core::list<irr::scene::ISceneNode*>) == 12) ? 1 : -1];
typedef char NativeConstIteratorExtent[(sizeof(irr::core::list<irr::scene::ISceneNode*>::ConstIterator) == 4) ? 1 : -1];

const irr::core::aabbox3d<float>& LODSceneNode::GetMeshTransformedBoundingBox(
    const irr::scene::ISceneNode* node) const
{
    const int colladaMeshNode = 0x6d656164;
    const int colladaSkinnedNode = 0x73656164;
    if (node->getType() == colladaMeshNode || node->getType() == colladaSkinnedNode)
        return node->getTransformedBoundingBox();

    for (irr::core::list<irr::scene::ISceneNode*>::ConstIterator child =
             _ZNK3irr5scene10ISceneNode11getChildrenEv(node).begin();
         child != _ZNK3irr5scene10ISceneNode11getChildrenEv(node).end(); ++child) {
        return GetMeshTransformedBoundingBox(*child);
    }
}
void LODSceneNode::computeLODLevel()
{
    irr::core::vector3d<float> cameraPosition = sceneManager->getActiveCamera()->getPosition();
    float distance = cameraPosition.getDistanceFromSQ(getLODNode(0)->getAbsolutePosition());
    if (distance > maxDistanceSquared) {
        if (lodLevel != -1) {
            setLODVisible(lodLevel, false);
            lodLevel = -1;
        }
        return;
    }
    for (int i = levels.size() - 1; i >= 0; --i) {
        if (distance > levels[i].distanceSquared) {
            if (lodLevel != i) {
                if (lodLevel != -1)
                    setLODVisible(lodLevel, false);
                lodLevel = i;
                setLODVisible(lodLevel, true);
            }
            return;
        }
    }
}
