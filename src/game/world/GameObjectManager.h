#ifndef WCH_WORLD_GAME_OBJECT_MANAGER_H
#define WCH_WORLD_GAME_OBJECT_MANAGER_H

#include "GameObjectList.h"
#include "../core/Vector3.h"

class LevelObject;
class DataStream;
class NPC;
class Vehicle;

// Observed 1088-byte layout. The leading storage and several field meanings
// remain provisional pending the loading and spawning methods.
class GameObjectManager {
public:
    GameObjectManager();
    virtual ~GameObjectManager();
    virtual LevelObject* Remove(LevelObject* object);
    virtual LevelObject* RemoveAndDestroy(LevelObject* object);
    LevelObject* GetFirst(int type);
    LevelObject* CreateGameObjectFromMetatype(int type);
    LevelObject* LoadGameObject(DataStream& stream);
    LevelObject* SpawnGameObject(int type);
    int GetMetatypeFromName(const char* name);
    void AddGameObjectOfType(int type);
    void RemoveGameObjectOfType(int type);
    void Add(LevelObject* object, int list);
    GameObjectList* getObjectList(int list);
    void Clear();
    static void Setup();
    void LoadMetatypes();
    void LoadSpawnPoints(const char* filename);
    void Load(char* filename);
    LevelObject* despawn(LevelObject* object);
    NPC* spawnNPC(int metatype, int behavior, int option);
    NPC* spawnNPCInVehicle(Vehicle* vehicle, int metatype, int behavior);
    NPC* spawnNPC(int metatype, int behavior, irr::core::vector3d<float> position,
        unsigned short region, unsigned short surface);
    LevelObject* GetGameObjectByName(const char* name, bool respawnDead) const;
    static GameObjectManager* s_gom;
private:
    unsigned char unknown4[1028];
    int unknown1032;
    int metatypeCount;
    unsigned char** metatypeData;
    int* metatypeSizes;
    int* typeCounts;
    GameObjectList list0;
    GameObjectList list2;
    GameObjectList list1;
};

#endif
