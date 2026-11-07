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
    void Load(const Structs::NPC&);
    bool isCop();
    const Path* getPathToFollow() const;
    void setCurrentWaypoint(int waypoint);
    int getCurrentWaypoint() const;
    void loopPathToFollow(bool loop);
    void setPathToFollow(const Path* path);
    bool isLoopingOnPathToFollow() const;
private:
    friend class AchievementManager;
    unsigned char unknown296[60];
    unsigned int flags356;
    unsigned char unknown360[68];
    unsigned int category428;
    unsigned char unknown432[8];
    const Path* pathToFollow;
    int currentWaypoint;
    unsigned char unknown448[8];
};
#endif
