#ifndef WCH_WORLD_LEVEL_OBJECT_H
#define WCH_WORLD_LEVEL_OBJECT_H

#include "../core/SceneNode.h"

namespace irr { namespace core {
template<class T> class vector3d;
class quaternion;
} }
namespace irr { namespace collada { class CColladaFactory; } }
namespace Structs { struct GameObjectBasic; }
class GameObjectList;
class PhysicAttributes;

// Observed primary virtual slots and 52-byte base prefix. Several field and
// return types remain provisional; complete hierarchy and runtime use await
// recovery of the remaining methods. The constructor is the recovered standalone
// function; the inline type accessor represents the observed byte load.
class LevelObject {
    friend class GameObjectList;
    friend class GameObjectManager;
    friend class GS3DStuff;
    friend class SpawnPoint;
    friend class ScriptManager;
    friend class MiniMap;
public:
    LevelObject(int id);
    unsigned char getObjectType() const { return objectType; }
    const char* getName() const { return unknown28; }
    PhysicAttributes* getPhysicAttributes() const { return unknown24; }
    unsigned char GetMetatype();
    void SetName(const char* name);
    void debug(irr::video::IVideoDriver* driver);
    static void setup();
    static void freeHighlights();
    static void loadHighlights(const char* filename);
    static int s_type[256];
    static unsigned char s_nodePoolID[256];
    static unsigned char s_nodePoolMinimumSize[256];
    static int* s_highlights;
    static int* s_highlightsIcons;
    void Load(const Structs::GameObjectBasic& data, irr::collada::CColladaFactory* factory);
    void showHighlight(int id);
    bool isEnabled() const;
    bool isVisibleOnScreen();
    bool isWithinRange(float range);
    bool canSeeLevelObject(LevelObject* other, irr::core::vector3d<float>& point);
    bool CastRay(const irr::core::vector3d<float>& start, const irr::core::vector3d<float>& direction,
        irr::core::vector3d<float>& point, irr::core::vector3d<float>& normal,
        LevelObject*& object, bool detailed);
    // Pending body: nonmatching/world/level-object-movement.cpp.
    bool canGoToPoint(const irr::core::vector3d<float>& target,
        irr::core::vector3d<float>& point, irr::core::vector3d<float>& adjusted);
    // Observed byte predicate, inlined without claiming a standalone retail symbol.
    bool hasHighlightPool() const { return unknown48 != 0xff; }
    // Observed pool-table predicate; used inline without claiming a standalone symbol.
    bool hasSceneNodePool() const { return s_nodePoolID[objectType] != 0xff; }
    virtual irr::scene::ISceneNode* grabSceneNode(int id, void*** parameters);
    virtual void dropSceneNode();
    virtual void setupSceneNode(int id, irr::scene::ISceneNode* node, int count, void** parameters);
    virtual ~LevelObject();
    virtual void WarmUp();
    virtual void OnSpawn();
    virtual void OnDespawn();
    virtual void setSpawnType(int type);
    // Header-emitted weak base implementation, also used through qualified calls.
    virtual int getSpawnType() { return s_type[objectType]; }
    virtual unsigned short GetMatID() const;
    virtual unsigned short GetTriID() const;
    virtual irr::core::vector3d<float> GetPosition() const;
    virtual const irr::core::quaternion& GetRotation() const;
    virtual irr::core::vector3d<float> GetRight() const;
    virtual irr::core::vector3d<float> GetFront() const;
    virtual void SetPosition(const irr::core::vector3d<float>& value);
    virtual void SetRotation(const irr::core::vector3d<float>& value);
    virtual void SetRotation(const irr::core::quaternion& value);
    virtual int getMaxHealth() const;
    virtual int getHealth() const;
    virtual bool isDead();
    virtual float GetSpeed() const;
    virtual void* getSkinMesh();
    virtual void photographed();
    virtual void clearPhotographed();
    virtual bool isPhotographed() const;
    virtual void Update(int elapsed);
    virtual void Stop();
    virtual void enable();
    virtual void disable();
    virtual void init();
    virtual void clean();
    virtual void applyDamage(int amount, LevelObject* source, bool flag);
    virtual void setAnimationSpeedMultiplier(int speed);
    virtual void setAnimation(const char* name, int speed, bool a, bool b, bool c);
    virtual void setAnimation(int id, int speed, bool a, bool b, bool c);
    virtual void setNextAnimation(const char* name, int speed, bool a, bool b, bool c);
    virtual void setNextAnimation(int id, int speed, bool a, bool b, bool c);
    virtual void shooted(int amount, LevelObject* source);

protected:
    unsigned int unknown4;
    LevelObject* previous;
public:
    LevelObject* next;
protected:
    irr::scene::ISceneNode* sceneNode;
    irr::scene::ISceneNode* unknown20;
    PhysicAttributes* unknown24;
    char* unknown28;
    GameObjectList* objectList;
    unsigned char objectType;
    unsigned char unknown37;
    unsigned char unknown38[2];
    int unknown40;
    int unknown44;
    unsigned char unknown48;
    unsigned char unknown49[3];
};

#endif
