#ifndef WCH_AI_NPC_H
#define WCH_AI_NPC_H
#include "../characters/Character.h"
namespace Structs { struct NPC; }
class Path;
// Constructor calls Character; the dispatcher allocates 456 bytes.
// Remaining fields and virtual overrides are unrecovered.
class NPC : public Character {
public:
    NPC(int type);
    virtual ~NPC();
    virtual Weapon* getWeapon() const;
    virtual void photographed();
    virtual void clearPhotographed();
    virtual bool isPhotographed() const;
    void Load(const Structs::NPC&);
    bool isCop();
    const Path* getPathToFollow() const;
    void setCurrentWaypoint(int waypoint);
    int getCurrentWaypoint() const;
    void loopPathToFollow(bool loop);
    void setPathToFollow(const Path* path);
    bool isLoopingOnPathToFollow() const;
    irr::core::vector3d<float> getNextWaypoint();
    bool getNextPoint(irr::core::vector3d<float>& point);
    void goToNextPoint(bool repeat);
    void goToLocation(const irr::core::vector3d<float>& point);
    virtual void walkToLocation(const irr::core::vector3d<float>& point);
    virtual void runToLocation(const irr::core::vector3d<float>& point);
private:
    friend class AchievementManager;
    friend class Character;
    unsigned char unknown296[12];
    Weapon* weapon;
    unsigned char unknown312[20];
    const Path* activePath;
    int activeWaypoint;
    unsigned char unknown340[16];
    unsigned int flags356;
    unsigned char unknown360[68];
    unsigned int category428;
    unsigned char unknown432[8];
    const Path* pathToFollow;
    int currentWaypoint;
    unsigned char unknown448[8];
};
#endif
