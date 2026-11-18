#include "Material.h"
#include "VideoDriver.h"
namespace irr { namespace video {
class IMaterialRendererServices;
// Native driver call/state view only; no complete object extent asserted.
class CCommonGLDriver : public IVideoDriver {
public:
    virtual void unknown126();
    virtual void unknown127();
    virtual void unknown128();
    virtual void unknown129();
    virtual void unknown130();
    virtual void unknown131();
    virtual void unknown132();
    virtual void unknown133();
    virtual void unknown134();
    virtual void unknown135();
    virtual void unknown136();
    virtual void unknown137();
    virtual void unknown138();
    virtual void unknown139();
    virtual void unknown140();
    virtual void unknown141();
    virtual void unknown142();
    virtual void setBasicRenderStates(const SMaterial&, const SMaterial&, bool);
    bool setTexture(unsigned int layer, const ITexture* texture);
    struct SShadowState { struct STexEnv { int mode; unsigned char unknown4[64]; }; };
    unsigned char unknown4[428];
    unsigned int activeTexture;
    unsigned char unknown436[1120];
    SShadowState::STexEnv textureEnvironment[4];
};
} }
/*
 * CCustomMaterialRenderer_VERTEX_COLOR_ALPHA
 *
 * Original file: CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_0()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE() __attribute__((used));
static void _GLOBAL__I__ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}


#include "SceneNode.h"
namespace irr { namespace video {
struct SMaterial;
class IMaterialRendererServices;
class CCommonGLDriver;
// The remaining renderer virtual methods and vtable are retail imports.
class IMaterialRenderer : public virtual IReferenceCounted {
public:
    virtual void onSetMaterial(const SMaterial&,const SMaterial&,bool,IMaterialRendererServices*);
    virtual bool onRender(IMaterialRendererServices*,E_VERTEX_TYPE);
    virtual void onUnsetMaterial();
    virtual bool isTransparent() const;
    virtual unsigned int getVertexAttributeMask() const=0;
    virtual int getRenderCapability() const;
    virtual ~IMaterialRenderer() {}
};
class CCommonGLMaterialRenderer : public IMaterialRenderer {
public:
    virtual ~CCommonGLMaterialRenderer() {}
protected:
    CCommonGLDriver* driver;
};
} }
class CCustomMaterialRenderer_VERTEX_COLOR_ALPHA : public irr::video::CCommonGLMaterialRenderer {
public:
    virtual ~CCustomMaterialRenderer_VERTEX_COLOR_ALPHA() {}
    virtual void onSetMaterial(const irr::video::SMaterial&,const irr::video::SMaterial&,bool,irr::video::IMaterialRendererServices*);
    virtual void onUnsetMaterial();
    virtual bool isTransparent() const;
    virtual unsigned int getVertexAttributeMask() const;
};

bool CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::isTransparent() const
{
    return false;
}

unsigned int CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::getVertexAttributeMask() const
{
    return 0x15u;
}


extern "C" void glTexEnvi(unsigned int, unsigned int, int);
void CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::onSetMaterial(const irr::video::SMaterial& material,
    const irr::video::SMaterial& previous, bool reset, irr::video::IMaterialRendererServices*)
{
    driver->setTexture(0, material.layers[0].texture);
    driver->setBasicRenderStates(material, previous, reset);
    int& mode = driver->textureEnvironment[driver->activeTexture - 0x84c0].mode;
    if (mode != 0x2101) {
        glTexEnvi(0x2300, 0x2200, 0x2101);
        mode = 0x2101;
    }
}

extern "C" void glTexEnvi(unsigned int, unsigned int, int);
void CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::onUnsetMaterial()
{
    int& mode=driver->textureEnvironment[driver->activeTexture-0x84c0].mode;
    if (mode != 0x2100) {
        glTexEnvi(0x2300, 0x2200, 0x2100);
        mode=0x2100;
    }
}
