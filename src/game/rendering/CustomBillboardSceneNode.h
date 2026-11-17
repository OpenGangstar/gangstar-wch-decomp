#ifndef WCH_RENDERING_CUSTOM_BILLBOARD_SCENE_NODE_H
#define WCH_RENDERING_CUSTOM_BILLBOARD_SCENE_NODE_H

#include "../core/Collada.h"

class CustomBillboardSceneNode : public irr::collada::CRootSceneNode {
    irr::scene::ISceneNode* billboardParent;
    bool animationActive;
    bool animationLoops;
    unsigned char unknown510[6];
    unsigned int animationLength;
    unsigned char unknown520[4];
    int parentOffsetZ;
public:
    void activateAnimation() { animationActive = true; }
    void setParentOffsetZ(int offset) { parentOffsetZ = offset; }
    void setParent(irr::scene::ISceneNode* parent);
    void setLength(unsigned int length);
    void setChildrenMaterialType(irr::scene::ISceneNode* node, irr::video::E_MATERIAL_TYPE type);
    void setChildrenMaterialFlag(irr::scene::ISceneNode* node, irr::video::E_MATERIAL_FLAG flag, bool enabled);
    CustomBillboardSceneNode(const irr::collada::CColladaDatabase&, irr::collada::SNode*);
    virtual ~CustomBillboardSceneNode();
    virtual void render();
    virtual void OnAnimate(unsigned int);
};

#endif
