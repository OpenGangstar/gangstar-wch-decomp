#ifndef WCH_WORLD_WORLD_H
#define WCH_WORLD_WORLD_H

class WorldDescriptor;

class World {
public:
    static World* GetInstance();
    void AddFromDescriptor(const WorldDescriptor& descriptor, bool spawnPointsOnly);
};

#endif
