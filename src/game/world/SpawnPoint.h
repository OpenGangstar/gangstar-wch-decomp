#ifndef WCH_WORLD_SPAWN_POINT_H
#define WCH_WORLD_SPAWN_POINT_H
#include "../core/Vector3.h"
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
    void Load(const Structs::SpawnPoint&);
    static void UpdateSpawnCenters();
    static void releaseSpawnObject(LevelObject* object);
    static LevelObject* getSpawnObject(int metatype);
    static void ClearAllSpawnInstances();
    const irr::core::vector3d<float>& getPosition() const { return position; }

    struct Center { float x, y, z; };
    static Center s_innerCenterCiv;
    static Center s_outterCenterCiv;
    static Center s_innerCenterCar;
    static Center s_outterCenterCar;
    static Center s_innerCenterParkedCar;
    static Center s_outterCenterParkedCar;
    static SpawnPointList s_spawnPoints;
private:
    enum { SpawnPoolSize = 256 };
    static LevelObject* s_spawnPool[SpawnPoolSize];
    static unsigned char s_spawnedCops;
    static unsigned char** s_spawnMetatypes;
    static unsigned char* s_metatypesCount;
    static unsigned char* s_metatypesSpawnCst;
    irr::core::vector3d<float> position;
    unsigned char unknown16[24];
};
#endif
