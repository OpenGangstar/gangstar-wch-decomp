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
    virtual void die(bool flag);
    virtual Weapon* getWeapon() const;
    virtual void photographed();
    virtual void clearPhotographed();
    virtual bool isPhotographed() const;
    void Load(const Structs::NPC&);
    bool isCop();
    void notifyTargeted(bool targeted, Character* by);
    void attackTarget(LevelObject* object);
    virtual void SetTarget(LevelObject* object);
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
    Character* targetingCharacter;
    unsigned char unknown316[8];
    irr::scene::ISceneNode* leftHand;
    irr::scene::ISceneNode* rightHand;
    const Path* activePath;
    int activeWaypoint;
    unsigned char unknown340[16];
    unsigned int flags356;
    unsigned char unknown360[32];
    int weaponType;
    unsigned char unknown396[20];
    int cashDrop;
    unsigned char unknown420[8];
    unsigned int category428;
    unsigned char unknown432[8];
    const Path* pathToFollow;
    int currentWaypoint;
    unsigned char unknown448[4];
    bool attackState452;
    unsigned char unknown453[3];
    void acquireTarget();
    void equipWeapon(bool forceUnarmed, bool swapHands);
    void attachWeaponToHand(irr::scene::ISceneNode* hand, irr::scene::ISceneNode* model);
};
#endif
