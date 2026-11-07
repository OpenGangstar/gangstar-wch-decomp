#ifndef WCH_WORLD_WORLD_H
#define WCH_WORLD_WORLD_H

class GameObject;
class WorldDescriptor;

class World {
public:
    World();
    virtual ~World();
    // Retail returns zero; the source return type is provisional.
    bool GetGameObjectByName(GameObject** objects, int& count, const char* name);
    static World* GetInstance();
    void AddFromDescriptor(const WorldDescriptor& descriptor, bool spawnPointsOnly);
    void Init(const WorldDescriptor& descriptor);
private:
    int unknown4;
    int unknown8;
    int unknown12;
    int flags;
};

#endif
