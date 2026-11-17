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

#include "../core/SceneNode.h"

class LODSceneNode : public irr::scene::ISceneNode {
public:
    virtual ~LODSceneNode();
    virtual void OnAnimate(unsigned int time);
    virtual void render(void* context);
    virtual int getType() const;
    virtual void OnRegisterSceneNode();
    virtual const irr::core::aabbox3d<float>& getTransformedBoundingBox() const;
    const irr::core::aabbox3d<float>& GetMeshTransformedBoundingBox(const irr::scene::ISceneNode*) const;
    void computeLODLevel();
    void setLODNodesRotation(const irr::core::quaternion& rotation);
    void setLODNodesPosition(const irr::core::vector3d<float>& position);
    virtual const irr::core::aabbox3d<float>& getBoundingBox() const;
    const irr::core::aabbox3d<float>& GetMeshBoundingBox(const irr::scene::ISceneNode*) const;
    int getLODLevel() const;
    void ComputeLOD(unsigned int time);
    void setMaxDistance(int distance);

private:
    template<class T, void (irr::scene::ISceneNode::*SetTransform)(const T&)>
    inline __attribute__((always_inline)) void setLODNodesTransform(const T& transform)
    {
        for (int index = 0; static_cast<unsigned int>(index) < levelCount; ++index)
            (levels[index].sceneNode->*SetTransform)(transform);
    }

    struct LODEntry {
        float distanceSquared;
        irr::scene::ISceneNode* sceneNode;
    };
    LODEntry* levels;
    unsigned char unknown332[4];
    unsigned int levelCount;
    unsigned char unknown340[8];
    float maxDistanceSquared;
    float animationTime;
    int lodLevel;
};

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
    return GetMeshBoundingBox(levels[lodLevel].sceneNode);
}

void LODSceneNode::OnRegisterSceneNode()
{
    if (visible) {
        computeLODLevel();
        if (getLODLevel() != -1)
            levels[lodLevel].sceneNode->OnAnimate(static_cast<unsigned int>(animationTime));
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
    return GetMeshTransformedBoundingBox(levels[lodLevel].sceneNode);
}

void LODSceneNode::setLODNodesPosition(const irr::core::vector3d<float>& position)
{
    setLODNodesTransform<irr::core::vector3d<float>, &irr::scene::ISceneNode::setPosition>(position);
}

void LODSceneNode::setLODNodesRotation(const irr::core::quaternion& rotation)
{
    setLODNodesTransform<irr::core::quaternion, &irr::scene::ISceneNode::setRotation>(rotation);
}
