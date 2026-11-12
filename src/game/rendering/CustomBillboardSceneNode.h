#ifndef WCH_RENDERING_CUSTOM_BILLBOARD_SCENE_NODE_H
#define WCH_RENDERING_CUSTOM_BILLBOARD_SCENE_NODE_H

#include "../core/Collada.h"

// Allocation extent and the observed CSceneNode conversion at +100 only.
// The complete billboard hierarchy and field layout remain unreconstructed.
struct CustomBillboardPrefix {
    virtual void unknown0();
    unsigned int unknown4[24];
};
class CustomBillboardSceneNode : public CustomBillboardPrefix, public irr::collada::CSceneNode {
    unsigned int unknown468[9];
    irr::scene::ISceneNode* billboardParent;
    bool animationActive;
    unsigned char unknown509[19];
public:
    void activateAnimation() { animationActive = true; }
    void setParent(irr::scene::ISceneNode* parent);
    CustomBillboardSceneNode(const irr::collada::CColladaDatabase&, irr::collada::SNode*);
};

#endif
