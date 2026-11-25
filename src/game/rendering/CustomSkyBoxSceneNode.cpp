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


template<class Vertex>
static inline void setVertex(Vertex& v, float x, float y, float z, float nx, float ny, float nz,
                             irr::video::SColor color, float tu, float tv)
{
    v.position[0] = x; v.position[1] = y; v.position[2] = z;
    v.normal[0] = nx; v.normal[1] = ny; v.normal[2] = nz;
    v.color = color;
    v.uv[0] = tu; v.uv[1] = tv;
}

struct SkyColorView {
    unsigned char before[0x880];
    irr::video::SColor c0, c1, c2, c3;
};

void CustomSkyBoxSceneNode::setSkyColor(bool enabled)
{
    using irr::video::SColor;
    SkyColorView* view = reinterpret_cast<SkyColorView*>(this);
    if (enabled) {
        view->c3 = SColor(255, 255, 255, 255);
        view->c2 = SColor(255, 150, 210, 220);
        view->c1 = SColor(255, 115, 153, 177);
        view->c0 = SColor(255, 55, 82, 95);
    } else {
        view->c3 = SColor(255, 255, 255, 255);
        view->c2 = SColor(255, 255, 255, 255);
        view->c1 = SColor(255, 255, 242, 160);
        view->c0 = SColor(150, 255, 235, 50);
    }
    setVertex(vertices[0], 4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.25f);
    setVertex(vertices[1], 4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 0.25f);
    setVertex(vertices[2], 4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.5f);
    setVertex(vertices[3], -4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 0.5f);
    setVertex(vertices[4], -4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.75f);
    setVertex(vertices[5], -4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 0.75f);
    setVertex(vertices[6], -4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 1.0f);
    setVertex(vertices[7], 4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 1.0f);
    setVertex(vertices[8], 4560.0f, 783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.125f);
    setVertex(vertices[9], 4560.0f, 783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.125f);
    setVertex(vertices[10], 4560.0f, 783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.375f);
    setVertex(vertices[11], -4560.0f, 783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.375f);
    setVertex(vertices[12], -4560.0f, 783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.625f);
    setVertex(vertices[13], -4560.0f, 783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.625f);
    setVertex(vertices[14], -4560.0f, 783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.875f);
    setVertex(vertices[15], 4560.0f, 783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.875f);
    setVertex(vertices[16], 4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[17], 4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 1.0f, 0.0f);
    setVertex(vertices[18], 4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.25f);
    setVertex(vertices[19], -4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 1.0f, 0.25f);
    setVertex(vertices[20], -4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.5f);
    setVertex(vertices[21], -4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 1.0f, 0.5f);
    setVertex(vertices[22], -4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.75f);
    setVertex(vertices[23], 4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 1.0f, 0.75f);
    setVertex(vertices[24], 4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[25], 4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[26], 4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[27], -4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[28], -4560.0f, 2090.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[29], -4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[30], -4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[31], 4560.0f, 2090.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[32], 4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[33], 4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[34], 4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[35], -4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[36], -4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[37], -4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[38], -4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[39], 4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c0, 0.0f, 0.0f);
    setVertex(vertices[40], 4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.0f);
    setVertex(vertices[41], 4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.0f);
    setVertex(vertices[42], -4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.0f);
    setVertex(vertices[43], -4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.0f);
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
