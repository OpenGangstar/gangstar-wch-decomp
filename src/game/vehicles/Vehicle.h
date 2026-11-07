#ifndef WCH_VEHICLES_VEHICLE_H
#define WCH_VEHICLES_VEHICLE_H
#include "../world/LevelObject.h"
namespace Structs { struct Car; }
class Character;
class Path;
// Primary base and 1012-byte allocation extent; secondary interfaces and fields
// remain opaque pending recovery of the constructor and vehicle methods.
class Vehicle : public LevelObject {
public:
    void explode();
    bool hasExplosionFlag() const { return explosionFlag != 0; }
    Vehicle(int type);
    void Load(const Structs::Car&);
    void initializeDriver();
    void UpdatePhysic(float);
    void stepPhysic();
    void step();
    void immobilize();
    void mobilize();
    void UpdateCarSounds();
    void repair();
    void setPathToFollow(const Path* path);
    const Path* getPathToFollow() const;
    int getCurrentWaypoint() const;
    void setCurrentWaypoint(int waypoint);
    bool isLoopingOnPathToFollow() const;
    void setSpeed();
    // Observed driver pointer at 696; inline accessor claims no separate symbol.
    Character* getDriver() const { return driver; }
private:
    friend class Race;
    unsigned char unknown52[292];
    unsigned int flags344;
    unsigned char unknown348[73];
    unsigned char explosionFlag;
    unsigned char unknown422[274];
    Character* driver;
    unsigned char unknown700[76];
    float unknown776;
    unsigned char unknown780[232];
};
#endif
