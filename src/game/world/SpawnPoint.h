#ifndef WCH_WORLD_SPAWN_POINT_H
#define WCH_WORLD_SPAWN_POINT_H
namespace Structs { struct SpawnPoint; }
struct SpawnPointList;
// Separate polymorphic type: the dispatcher does not return a LevelObject.
// The constructor and dispatcher establish a 40-byte allocation extent.
class SpawnPoint {
public:
    SpawnPoint(int type);
    virtual ~SpawnPoint();
    void Load(const Structs::SpawnPoint&);
    static void UpdateSpawnCenters();

    struct Center { float x, y, z; };
    static Center s_innerCenterCiv;
    static Center s_outterCenterCiv;
    static Center s_innerCenterCar;
    static Center s_outterCenterCar;
    static Center s_innerCenterParkedCar;
    static Center s_outterCenterParkedCar;
    static SpawnPointList s_spawnPoints;
private:
    unsigned char unknown4[36];
};
#endif
