/*
 * CustomSkyBoxSceneNode
 *
 * Original file: CustomSkyBoxSceneNode.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CustomSkyBoxSceneNode.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "CustomSkyBoxSceneNode.h"
#include "../core/VideoDriver.h"

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
static void _GLOBAL__I__ZN21CustomSkyBoxSceneNodeC2EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi() __attribute__((used));
static void _GLOBAL__I__ZN21CustomSkyBoxSceneNodeC2EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi()
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

int CustomSkyBoxSceneNode::getType() const
{
    return 's' | ('k' << 8) | ('y' << 16) | ('_' << 24);
}

const irr::core::aabbox3d<float>& CustomSkyBoxSceneNode::getBoundingBox() const
{
    return boundingBox;
}

irr::video::SMaterial& CustomSkyBoxSceneNode::getMaterial(unsigned int)
{
    return material;
}

unsigned int CustomSkyBoxSceneNode::getMaterialCount() const
{
    return 1;
}

void CustomSkyBoxSceneNode::OnRegisterSceneNode()
{
    if (visible)
        sceneManager->registerNodeForRendering(this, 0, 0, irr::scene::RenderPass2);
    ISceneNode::OnRegisterSceneNode();
}

irr::scene::ISceneNode* CustomSkyBoxSceneNode::clone(irr::scene::ISceneNode*, irr::scene::ISceneManager*)
{
    CustomSkyBoxSceneNode* copy = new CustomSkyBoxSceneNode(0, 0, id);
    copy->cloneMembers(this);
    copy->material = material;
    copy->drop();
    return copy;
}

class SkyBillboardInterface {
public:
    virtual void setSize(const irr::core::dimension2d<float>& size);
};

class SkyBillboard : public SkyBillboardInterface, public irr::scene::ISceneNode {};

void CustomSkyBoxSceneNode::render(void*)
{
    using namespace irr;
    video::IVideoDriver* driver = sceneManager->getVideoDriver();
    scene::ICameraSceneNode* camera = sceneManager->getActiveCamera();
    if (!camera || !driver)
        return;

    core::matrix4 world(absoluteTransformation, core::matrix4::EM4CONST_COPY);
    world.setTranslation(camera->getAbsolutePosition());
    driver->setTransform(video::ETS_WORLD, world);

    core::vector3d<float> position = cameraAnchor->getPosition();
    position.normalize();
    position *= 1000.0f;
    static_cast<scene::ISceneNode&>(*billboard).setPosition(position);
    static_cast<scene::ISceneNode&>(*billboard).updateAbsolutePosition(false);
    static_cast<scene::ISceneNode&>(*billboard).render(0);

    driver->setTransform(video::ETS_WORLD, world);
    driver->setMaterial(material);
    driver->drawVertexPrimitiveList(vertices, indices, 0, 46, 28, video::EVT_STANDARD,
                                    scene::EPT_TRIANGLES, video::EIT_16BIT, 0);
    driver->flush();
}

CustomSkyBoxSceneNode::~CustomSkyBoxSceneNode()
{
}
