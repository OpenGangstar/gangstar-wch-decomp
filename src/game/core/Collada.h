#ifndef WCH_CORE_COLLADA_H
#define WCH_CORE_COLLADA_H

#include "SceneNode.h"
#include "Geometry.h"

// Observed engine call/vtable interfaces. Unused return types remain provisional.
namespace irr {
namespace res { class String; template<class T> class vector; }
namespace scene { class IColladaMesh; }
namespace scene {
class CEmptySceneNode : public ISceneNode {
public:
    virtual void render(void*);
    virtual const core::aabbox3d<float>& getBoundingBox() const;
private:
    core::aabbox3d<float> box;
};
}
namespace collada {
class CColladaDatabase;
struct SLibraryAnimationClips; struct SLight; struct SMaterial;
struct SGeometry; struct SController; struct SCamera;
struct SInstanceModularSkin; struct SEmitter; struct SForce;
class IRootSceneNode;
struct SNode { unsigned int unknown0[18]; const void* properties; };

// Observed scene interface prefix, 380-byte allocation extent and constructor ABI.
// Remaining storage is opaque; this is not the complete engine class.
class CSceneNode : public scene::CEmptySceneNode {
    unsigned int unknown352[4];
public:
    CSceneNode(const CColladaDatabase&, SNode*);
};

typedef char ColladaSceneExtent[sizeof(CSceneNode) == 380 ? 1 : -1];

class CColladaFactory {
public:
    virtual ~CColladaFactory() {}
    virtual void* createAnimation();
    virtual void* createAnimator(const CColladaDatabase&, SLibraryAnimationClips*);
    virtual void* createLight(const CColladaDatabase&, SLight*);
    virtual void* createMaterial(const CColladaDatabase&, SMaterial*, IRootSceneNode*);
    virtual void* createGeometry(const CColladaDatabase&, SGeometry*);
    virtual void* createMorph(const CColladaDatabase&, SController*);
    virtual CSceneNode* createNode(const CColladaDatabase&, SNode*);
    virtual void* createBillboard(const CColladaDatabase&, SNode*);
    virtual void* createCameraNode(const CColladaDatabase&, SCamera*);
    virtual void* createMeshNode(const CColladaDatabase&, scene::IColladaMesh*, IRootSceneNode*, void*);
    virtual void* createSkinNode(const CColladaDatabase&, scene::IColladaMesh*, IRootSceneNode*, void*);
    virtual void* createModularSkinNode(const CColladaDatabase&, scene::IColladaMesh*, IRootSceneNode*, void*);
    virtual void* createScene(const CColladaDatabase&);
    virtual void* createSkin(const CColladaDatabase&, SController*, res::vector<res::String>*, IRootSceneNode*);
    virtual void* createModularSkin(const CColladaDatabase&, SInstanceModularSkin*, IRootSceneNode*);
    virtual void* createParticleSystem(const CColladaDatabase&, SEmitter*, res::vector<res::String>*, IRootSceneNode*);
    virtual void* createParticleSystemGravityForce(const CColladaDatabase&, SForce*);
    virtual void* createParticleSystemWindForce(const CColladaDatabase&, SForce*);
    virtual void* createParticleSystemDeflectorForce(const CColladaDatabase&, SForce*);
};
class CColladaDatabase {
public:
    static CColladaFactory DefaultFactory;
    static scene::ISceneNodeAnimator* constructAnimator(const char* name, CColladaFactory* factory);
    static scene::ISceneNode* constructNode(const char* scene, const char* node, CColladaFactory* factory);
    static scene::ISceneNode* constructScene(const char* name, bool flag, CColladaFactory* factory);
    static scene::ISceneNode* constructScene(const char* name, CColladaFactory* factory);
};
} }

#endif
