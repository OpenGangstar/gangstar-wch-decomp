#ifndef WCH_WORLD_SPAWN_POINT_H
#define WCH_WORLD_SPAWN_POINT_H
#include "../core/Vector3.h"
#include "../core/Quaternion.h"
namespace Structs { struct SpawnPoint; }
class SpawnPoint;
class LevelObject;
struct SpawnPointList {
    struct Node { Node* next; Node* previous; SpawnPoint* value; };
    Node* head;
    Node* tail;
    unsigned int count;
};
// Separate polymorphic type: the dispatcher does not return a LevelObject.
// The constructor and dispatcher establish a 40-byte allocation extent.
class SpawnPoint {
public:
    SpawnPoint(int type);
    virtual ~SpawnPoint();
    static void add(SpawnPoint* point);
    void SetRotation(const irr::core::vector3d<float>& degrees);
    void Load(const Structs::SpawnPoint&);
    static void UpdateSpawnCenters();
    static void releaseSpawnObject(LevelObject* object);
    static LevelObject* getSpawnObject(int metatype);
    static void ClearAllSpawnInstances();
    void Update(int elapsed);
    const irr::core::vector3d<float>& getPosition() const { return position; }

    struct Center { float x, y, z; };
    const Center& GetInnerSpawnCenter() const;
    const Center& GetOutterSpawnCenter() const;
    static Center s_innerCenterCiv;
    static Center s_outterCenterCiv;
    static Center s_innerCenterCar;
    static Center s_outterCenterCar;
    static Center s_innerCenterParkedCar;
    static Center s_outterCenterParkedCar;
    static SpawnPointList s_spawnPoints;
private:
    struct SpawnConstants {
        int type;
        int unknown4;
        int retryMin;
        int retryMax;
        int respawnMin;
        int respawnMax;
        int unknown24;
        int unknown28;
        int unknown32;
        int unknown36;
    };
    void resetSpawnTime(int minimum, int maximum);
    bool canSpawn() const;
    void spawn();
    enum { SpawnPoolSize = 256 };
    static LevelObject* s_spawnPool[SpawnPoolSize];
    static unsigned char s_spawnedCops;
    static unsigned char** s_spawnMetatypes;
    static unsigned char* s_metatypesCount;
    static const SpawnConstants** s_metatypesSpawnCst;
    static SpawnConstants s_carSpawnCst;
    static SpawnConstants s_civSpawnCst;
    static SpawnConstants s_prisonerSpawnCst;
    static SpawnConstants s_parkedCarSpawnCst;
    irr::core::vector3d<float> position;
    irr::core::quaternion rotation;
    short unknown32;
    unsigned char unknown34[2];
    short spawnTime;
    unsigned char spawnGroup;
    unsigned char unknown39;
};
#endif
