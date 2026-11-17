#ifndef WCH_RENDERING_CUSTOM_SKY_BOX_SCENE_NODE_H
#define WCH_RENDERING_CUSTOM_SKY_BOX_SCENE_NODE_H

#include "../core/Geometry.h"
#include "../core/Material.h"
#include "../core/SceneNode.h"

class SkyBillboard;

class CustomSkyBoxSceneNode : public irr::scene::ISceneNode {
public:
    CustomSkyBoxSceneNode(irr::video::ITexture*, irr::scene::ISceneNode*, int);
    virtual ~CustomSkyBoxSceneNode();
    virtual void OnRegisterSceneNode();
    virtual irr::scene::ISceneNode* clone(irr::scene::ISceneNode*, irr::scene::ISceneManager*);
    virtual void render(void*);
    virtual const irr::core::aabbox3d<float>& getBoundingBox() const;
    virtual irr::video::SMaterial& getMaterial(unsigned int);
    virtual unsigned int getMaterialCount() const;
    virtual int getType() const;
    void setSkyColor(bool enabled);

private:
    irr::core::aabbox3d<float> boundingBox;
    struct SkyVertex {
        float position[3];
        float normal[3];
        irr::video::SColor color;
        float uv[2];
    };
    unsigned short indices[84];
    SkyVertex vertices[46];
    unsigned char unknown2176[16];
    irr::video::SMaterial material;
    SkyBillboard* billboard;
    irr::scene::ICameraSceneNode* cameraAnchor;
};

#endif
