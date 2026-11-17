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
    void debug(irr::video::IVideoDriver* driver);
    virtual void Stop();
    virtual void OnDespawn();
    virtual void Update(int elapsed);
    virtual void disable();
    virtual void init();
    virtual void goToVehicle(Vehicle*, bool, bool, bool, bool);
    void switchAnim();
    void tagForKill(bool tagged);
    void clearOnAlert();
    void setHitByCar(bool hit);
    void clearGoToVehicle();
    void UpdateSceneNode();
    virtual void enable();
    virtual irr::core::vector3d<float> GetPosition() const;
    void _arrest();
    virtual void applyDamage(int, LevelObject*, bool);
    virtual void clean();
    virtual void dropSceneNode();
    void wait(int duration);
    virtual void WarmUp();
    void flee();
    void flee(const irr::core::vector3d<float>&) __attribute__((noinline));
    virtual irr::scene::ISceneNode* grabSceneNode(int, void***);
    virtual void setupSceneNode(int, irr::scene::ISceneNode*, int, void**);
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
    bool isTargetable();
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
    void SetWeapon(int type) __attribute__((noinline));
    void notifyAttacked(LevelObject*) __attribute__((noinline));
    friend class AchievementManager;
    friend class Character;
    friend class PlayerTest;
    irr::core::vector3d<float> unknown296;
    Weapon* weapon;
    Character* targetingCharacter;
    unsigned int unknown316;
    unsigned int unknown320;
    irr::scene::ISceneNode* leftHand;
    irr::scene::ISceneNode* rightHand;
    const Path* activePath;
    int activeWaypoint;
    int unknown340;
    int unknown344;
    int waitDuration;
    int waitElapsed;
    unsigned int flags356;
    irr::core::vector3d<float> searchOrigin;
    irr::core::vector3d<float> unknown372;
    float searchRadiusScale;
    float searchRadiusSquared;
    int weaponType;
    int unknown396;
    int unknown400;
    int unknown404;
    int unknown408;
    int unknown412;
    int cashDrop;
    int cleanTimer;
    int faction;
    unsigned int category428;
    float unknown432;
    bool unknown436;
    unsigned char unknown437[3];
    const Path* pathToFollow;
    int currentWaypoint;
    int unknown448;
    bool attackState452;
    unsigned char unknown453[3];
    void acquireTarget();
    void equipWeapon(bool forceUnarmed, bool swapHands);
    void attachWeaponToHand(irr::scene::ISceneNode* hand, irr::scene::ISceneNode* model);
};
#endif
