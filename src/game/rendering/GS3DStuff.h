#ifndef WCH_RENDERING_GS3D_STUFF_H
#define WCH_RENDERING_GS3D_STUFF_H

#include "../core/SceneNode.h"
#include "../core/Color.h"
#include "../core/Material.h"
#include "../core/StateBase.h"
#include "../core/GameEvents.h"
#include "../core/PointerVector.h"
#include "../core/Array.h"

class BulletTraceManager;
class TrailMgr;
class OctTreeAABB;
class DataStream;
class Vehicle;
class Item;
class LevelObject;
class PlayerTest;
class GameObjectManager;
class WorldDescriptor;
namespace irr { namespace video { class ITexture; } }
namespace Structs {
struct PhonePerformanceProfile {
    int unknown0;
    int unknown4;
    char* textureNameSuffix;
    void Read(DataStream&);
};
}

// Observed 28-byte prefix, two bases and their virtual slots only.
// Do not instantiate or infer complete scene-state layout from this prefix.
struct GS3DLightNodes;

class GS3DStuff : public StateBase, public IEventReceiver {
public:
    static GS3DLightNodes lightsNodes;
    static int s_orientation;

    GS3DStuff();
    virtual ~GS3DStuff();
    virtual void ctor(const StateMachine*);
    virtual void dtor(const StateMachine*);
    virtual void resume(const StateMachine*);
    virtual void update(StateMachine*);
    virtual void draw(const StateMachine*);
    virtual void draw2d(const StateMachine*);
    virtual void wakeup(const StateMachine*);
    virtual bool isDrawable() { return drawable; }
    virtual bool isKindOf(int kind) {
        if (kind == 1) return true;
        return StateBase::isKindOf(kind);
    }
    virtual void onEvent(const IEvent*, const EventManager*);

    static bool getProperty(const void* properties, const char* name, char* output);
    static BulletTraceManager* GetBulletManager();
    static TrailMgr* GetTrailMgr();
    // Retail returns zero; the source-level return type remains provisional.
    static irr::scene::ISceneNode* OptimizeHierarchy(irr::scene::ISceneNode*);
    static irr::scene::ISceneNode* getSkyBox();
    static irr::video::ITexture* getSkyBoxTexture();
    static char* getTextureNameSuffix();
    static OctTreeAABB* getSceneOctTree();
    enum eColorType { Color0, Color1, Color2, Color3 };
    static void SetColor(irr::scene::ISceneNode* node, irr::video::SColor color, eColorType type);
    static void SetMaterialType(irr::scene::ISceneNode* node, irr::video::E_MATERIAL_TYPE type);
    static void SetMaterial(irr::scene::ISceneNode* node, irr::video::SMaterial* material);
    static void SetMaterialFiltering(irr::scene::ISceneNode* node, bool enabled, bool force);
    static void SetMaterialTypeCondition(irr::scene::ISceneNode* node,
        irr::video::E_MATERIAL_TYPE type, irr::video::ITexture* texture);
    static void SetMaterialFlag(irr::scene::ISceneNode* node, irr::video::E_MATERIAL_FLAG flag, bool enabled);
    static void SetVisibility(irr::scene::ISceneNode* node, bool visible);
    static void SetCulling(irr::scene::ISceneNode* node, irr::scene::E_CULLING_TYPE type);
    static void SetMaterialTexture(irr::scene::ISceneNode* node, irr::video::ITexture* texture);
    static irr::scene::ISceneNode* FindAMesh(irr::scene::ISceneNode* node);
    static void CleanNode(irr::scene::ISceneNode* node);
    static void AddRenderables(irr::scene::ISceneNode* node,
        irr::core::array<irr::scene::ISceneNode*>& renderables, irr::scene::ESCENE_NODE_TYPE type);
    static void freeGameData(irr::scene::ISceneNode* node);
    static void setSkyColor(bool enabled);
    static void AddXRef(irr::scene::ISceneNode* node);
    static void loadCityGameObjects(const WorldDescriptor& descriptor, bool spawnPointsOnly);
    static void loadCityVisual(const WorldDescriptor& descriptor);
    static void loadCityPart(const WorldDescriptor& descriptor, irr::scene::ISceneNode*& parent);
    static irr::scene::ISceneNode* loadCityPart(const char* path);

    static BulletTraceManager* s_bulletManager;
    static TrailMgr* s_TrailMgr;
    static irr::scene::ISceneNode* skyBox;
    static irr::scene::ISceneNode* city;
    static irr::video::ITexture* skyBoxTexture;
    static OctTreeAABB* sceneOcttree;
    static Structs::PhonePerformanceProfile s_phonePerformanceProfile;
    static unsigned int lastTime;
    static Vehicle* s_vehicle;
    static PlayerTest* playerTest;
    static GameObjectManager* gom;
    LevelObject* checkForDespawn(LevelObject*);
    void checkVehicleProximity(std::vector<Vehicle*>&);
    void checkPickableProximity(std::vector<Item*>&);
    void updateVisibility(unsigned int);
private:
    unsigned char unknown8[12];
    bool unknownFlag20;
    bool drawable;
    unsigned char unknown22[2];
    int unknown24;
};

#endif
