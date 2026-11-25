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
#include "../core/IrrlichtDevice.h"
#include "../app/Application.h"

void operator delete(void*) throw();

namespace {
// File-local view of the ITexture filter state written by the constructors.
struct SkyTextureView {
    unsigned char unknown0[38];
    unsigned char unknown38;
    unsigned char unknown39;
    unsigned char unknown40[4];
    float lodBias;
    unsigned char unknown48[8];
    unsigned int filterDirtyFlags;
};
inline void setSkyTextureUnknown38(irr::video::ITexture* texture, unsigned char value)
{
    SkyTextureView* view = reinterpret_cast<SkyTextureView*>(texture);
    if (view->unknown38 != value) { view->unknown38 = value; view->filterDirtyFlags |= 4; }
}
inline void setSkyTextureUnknown39(irr::video::ITexture* texture, unsigned char value)
{
    SkyTextureView* view = reinterpret_cast<SkyTextureView*>(texture);
    if (view->unknown39 != value) { view->unknown39 = value; view->filterDirtyFlags |= 8; }
}
}

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
    v.position.X = x; v.position.Y = y; v.position.Z = z;
    v.normal.X = nx; v.normal.Y = ny; v.normal.Z = nz;
    v.color = color;
    v.uv.X = tu; v.uv.Y = tv;
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

namespace {
// Inline expansion of irr::video::SMaterial::setTexture used by the constructor.
inline void setSkyMaterialTexture(irr::video::SMaterial& material, unsigned int layer, irr::video::ITexture* texture)
{
    if (material.layers[layer].texture != texture) {
        material.dirtyFlags |= 2;
        if (texture)
            ++texture->references;
        if (material.layers[layer].texture)
            material.layers[layer].texture->drop();
        material.layers[layer].texture = texture;
    }
}
}
CustomSkyBoxSceneNode::CustomSkyBoxSceneNode(irr::video::ITexture* texture, irr::scene::ISceneNode* parent, int id)
    : irr::scene::ISceneNode(id, irr::core::vector3d<float>(0, 0, 0), irr::core::quaternion(),
                             irr::core::vector3d<float>(1, 1, 1))
{
    using namespace irr;
    using video::SColor;
    IrrlichtDevice* device = Application::GetInstance()->GetDevice();
    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    (void)driver;

    setAutomaticCulling(scene::EAC_OFF);
    boundingBox.reset(0, 0, 0);
    material.setType(28);
    material.setFlag(video::MaterialFlag4, false);
    material.setFlag(video::MaterialFlag2, false);
    material.setFlag(video::MaterialFlag256, false);
    material.setFlag(video::MaterialFlag16, false);
    setSkyTextureUnknown38(texture, 1);
    setSkyTextureUnknown39(texture, 1);
    setSkyMaterialTexture(material, 0, texture);
    setSkyTextureUnknown38(texture, 1);
    setSkyTextureUnknown39(texture, 1);

    SkyColorView* view = reinterpret_cast<SkyColorView*>(this);
    view->c3 = SColor(255, 225, 184, 140);
    view->c2 = SColor(255, 255, 255, 255);
    view->c1 = SColor(255, 255, 242, 160);
    view->c0 = SColor(150, 255, 235, 50);
    setVertex(vertices[0], 4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.25f);
    setVertex(vertices[1], 4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 0.25f);
    setVertex(vertices[2], 4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.5f);
    setVertex(vertices[3], -4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 0.5f);
    setVertex(vertices[4], -4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 0.75f);
    setVertex(vertices[5], -4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 0.75f);
    setVertex(vertices[6], -4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 0.0f, 1.0f);
    setVertex(vertices[7], 4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c3, 1.0f, 1.0f);
    setVertex(vertices[8], 4560.0f, 261.25f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.125f);
    setVertex(vertices[9], 4560.0f, 261.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.125f);
    setVertex(vertices[10], 4560.0f, 261.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.375f);
    setVertex(vertices[11], -4560.0f, 261.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.375f);
    setVertex(vertices[12], -4560.0f, 261.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.625f);
    setVertex(vertices[13], -4560.0f, 261.25f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.625f);
    setVertex(vertices[14], -4560.0f, 261.25f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 0.0f, 0.875f);
    setVertex(vertices[15], 4560.0f, 261.25f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c2, 1.0f, 0.875f);
    setVertex(vertices[16], 4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.0f);
    setVertex(vertices[17], 4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 1.0f, 0.0f);
    setVertex(vertices[18], 4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.25f);
    setVertex(vertices[19], -4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 1.0f, 0.25f);
    setVertex(vertices[20], -4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, view->c1, 0.0f, 0.5f);
    SColor color;
    color = view->c1;
    setVertex(vertices[21], -4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 1.0f, 0.5f);
    setVertex(vertices[22], -4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.75f);
    setVertex(vertices[23], 4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 1.0f, 0.75f);
    setVertex(vertices[24], 4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[25], 4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[26], 4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[27], -4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[28], -4560.0f, 1306.25f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[29], -4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[30], -4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[31], 4560.0f, 1306.25f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    color = view->c0;
    setVertex(vertices[32], 4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[33], 4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[34], 4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[35], -4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[36], -4560.0f, 4560.0f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[37], -4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[38], -4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[39], 4560.0f, 4560.0f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    color = view->c3;
    setVertex(vertices[40], 4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[41], 4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[42], -4560.0f, -783.75f, -4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);
    setVertex(vertices[43], -4560.0f, -783.75f, 4560.0f, 0.0f, 1.0f, 0.0f, color, 0.0f, 0.0f);

    unsigned short* index = indices;
    for (int i = 0; i < 8; i += 2) {
        *index++ = i;
        *index++ = i + 8;
        *index++ = (i + 1) % 8;
        *index++ = (i + 1) % 8;
        *index++ = i + 8;
        *index++ = (i + 1) % 8 + 8;
    }
    for (int i = 0; i < 8; i += 2) {
        *index++ = i + 8;
        *index++ = i + 16;
        *index++ = (i + 1) % 8 + 8;
        *index++ = (i + 1) % 8 + 8;
        *index++ = i + 16;
        *index++ = (i + 1) % 8 + 16;
    }
    for (int i = 0; i < 8; i += 2) {
        *index++ = i + 24;
        *index++ = i + 32;
        *index++ = (i + 1) % 8 + 24;
        *index++ = (i + 1) % 8 + 24;
        *index++ = i + 32;
        *index++ = (i + 1) % 8 + 32;
    }
    *index++ = 32; *index++ = 35; *index++ = 33;
    *index++ = 35; *index++ = 32; *index++ = 37;
    *index++ = 40; *index++ = 41; *index++ = 43;
    *index++ = 41; *index++ = 42; *index++ = 43;

    billboard = reinterpret_cast<SkyBillboard*>(smgr->addBillboardSceneNode(
        0, core::dimension2d<float>(10, 10), core::vector3d<float>(0, 0, 0), -1,
        SColor(255, 255, 255, 255), SColor(255, 255, 255, 255)));
    billboard->setMaterialTexture(0, Application::GetInstance()->GetDevice()->getVideoDriver()->getTexture("./add-sun.tga"));
    billboard->setMaterialType(video::MaterialType13);
    billboard->setMaterialFlag(video::MaterialFlag4, true);
    billboard->setMaterialFlag(video::MaterialFlag2, false);
    billboard->setMaterialFlag(video::MaterialFlag128, false);
    billboard->setMaterialFlag(video::MaterialFlag256, false);
    billboard->setMaterialFlag(video::MaterialFlag512, false);
    billboard->setSize(core::dimension2d<float>(1024, 1024));
    cameraAnchor = static_cast<scene::ICameraSceneNode*>(parent);
    core::vector3d<float> position = parent->getPosition();
    position.normalize();
    position *= 1000.0f;
    billboard->setPosition(position);
    billboard->setVisible(false);
    smgr->getActiveCamera()->addChild(billboard);
}

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
