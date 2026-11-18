#ifndef WCH_CORE_MESH_SCENE_INTERFACES_H
#define WCH_CORE_MESH_SCENE_INTERFACES_H
#include "SceneNode.h"
#include "Geometry.h"
// Partial virtual call interfaces only. Do not instantiate engine objects.
namespace irr { namespace scene {
class IMesh;
class IAnimatedMesh {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual void unknown6(); virtual void unknown7(); virtual void unknown8();
    virtual void unknown9();
    virtual IMesh* getMesh(int frame, int detail, int first, int last);
};
class IMeshSceneNode : public ISceneNode {
public:
    virtual void setMesh(IMesh*) = 0;
    virtual IMesh* getMesh() = 0;
    virtual void setReadOnlyMaterials(bool) = 0;
    virtual bool isReadOnlyMaterials() const = 0;
};
class IAnimatedMeshSceneNode : public ISceneNode {
public:
    virtual void unknown66(); virtual void unknown67(); virtual void unknown68();
    virtual void unknown69(); virtual void unknown70(); virtual void unknown71();
    virtual void unknown72(); virtual void unknown73(); virtual void unknown74();
    virtual void unknown75(); virtual void unknown76();
    virtual float getFrameNr() const;
    virtual void unknown78(); virtual void unknown79(); virtual void unknown80();
    virtual void unknown81(); virtual void unknown82(); virtual void unknown83();
    virtual void unknown84();
    virtual IAnimatedMesh* getMesh();
};
} }
// Observed Collada node/source prefixes for the collision override flag only.
struct CollisionColladaSourceView {
    unsigned char unknown0[37];
    bool collisionFlag;
};
struct CollisionColladaNodeView {
    unsigned char unknown0[332];
    CollisionColladaSourceView* source;
};
#endif
