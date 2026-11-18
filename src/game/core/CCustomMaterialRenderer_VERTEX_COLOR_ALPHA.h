#ifndef WCH_CUSTOM_VERTEX_RENDERER_H
#define WCH_CUSTOM_VERTEX_RENDERER_H
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
    CCommonGLMaterialRenderer(CCommonGLDriver* value) : driver(value) {}
    virtual ~CCommonGLMaterialRenderer() {}
protected:
    CCommonGLDriver* driver;
};
} }
class CCustomMaterialRenderer_VERTEX_COLOR_ALPHA : public irr::video::CCommonGLMaterialRenderer {
public:
    CCustomMaterialRenderer_VERTEX_COLOR_ALPHA(irr::video::CCommonGLDriver* value) : irr::video::CCommonGLMaterialRenderer(value) {}
    virtual ~CCustomMaterialRenderer_VERTEX_COLOR_ALPHA() {}
    virtual void onSetMaterial(const irr::video::SMaterial&,const irr::video::SMaterial&,bool,irr::video::IMaterialRendererServices*);
    virtual void onUnsetMaterial();
    virtual bool isTransparent() const;
    virtual unsigned int getVertexAttributeMask() const;
};

#endif
