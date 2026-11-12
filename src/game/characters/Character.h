#ifndef WCH_CHARACTERS_CHARACTER_H
#define WCH_CHARACTERS_CHARACTER_H

#include "../world/LevelObject.h"

class Vehicle;
class b2Body;
class Weapon;

// Character's constructor calls LevelObject and initializes storage through
// offset 295. NPC's first additional field is at 296. Other fields and virtual
// overrides remain unrecovered; keep their storage opaque.
class Character : public LevelObject {
public:
    Character(int type);
    virtual ~Character();
    virtual void OnSpawn();
    virtual void OnDespawn();
    void initInVehicle(Vehicle* vehicle);
    void goToIdle();
    void switchWeapon();
    virtual void Stop();
    void onRocketLaunched();
    void walkToTarget();
    void startTurn(float speed);
    void closeVehicleDoorFromInside(bool left);
    void setTurnDirection(irr::core::vector3d<float> direction);
    void CheckDestination();
    bool isDown();
    bool isDying() __attribute__((weak));
    virtual bool isDead();
    virtual int getSpawnType();
    virtual void setSpawnType(int type);
    virtual void* getSkinMesh();
    virtual int getMaxHealth() const;
    virtual int getHealth() const;
    void resetAnimation();
    static void cleanTimelineController();
    static void freeBloodObjects();
    static void loadBloodObjects(const char* puddle, const char* splash);
    bool isAnimationLastFrame(float advance) const;
    bool isInFlinchAnimation();
    bool isInHitByCarAnimation();
    void setDestination(const irr::core::vector3d<float>& point, int limit);
    bool isPlayer() const;
    using LevelObject::sceneNode;
    using LevelObject::setAnimation;
    virtual void setAnimation(const char* name, int speed, bool a, bool b, bool c);
    virtual void setAnimationSpeedMultiplier(int speed);
    virtual void setNextAnimation(const char* name, int speed, bool a, bool b, bool c);
    virtual void setNextAnimation(int id, int speed, bool a, bool b, bool c);
    // Retail slots 40 through 55. The remaining slots are pending.
    virtual bool setAnimation(int id, float speed, bool loop, bool b, bool c);
    virtual void shoot(float time, bool pressed);
    virtual void die(bool flag);
    virtual void updatePhysic(int elapsed);
    virtual void updateSceneNode(int elapsed);
    virtual void render();
    virtual void init();
    virtual void enable();
    virtual void disable();
    virtual void clean();
    void block(int side);
    void nextPunch();
    void nextKick();
    virtual void setVehicle(Vehicle* vehicle);
    virtual Vehicle* getVehicle() const;
    virtual void setLockTarget(Character* target);
    virtual Character* getLockTarget() const;
    virtual void setCameraOffset(const irr::core::vector3d<float>& offset);
    virtual const irr::core::vector3d<float>& getCameraOffset() const;
    virtual void walkToLocation(const irr::core::vector3d<float>& point);
    virtual void runToLocation(const irr::core::vector3d<float>& point);
    virtual Weapon* getWeapon() const = 0;
    virtual void SetTarget(LevelObject* value);
private:
    friend class NPC;
    static irr::scene::ITimelineController* s_timelineController;
    static bool b_isBloodOn;
    static int s_bloodpuddle;
    static int s_bloodsplash;
    static irr::scene::ISceneNode* m_bloodSplash;
    bool isCurrentAnimation(int id);
    bool canAnimationBeInterrupted(int id);
    int getSpecificAnimation(int id);
    unsigned short collisionMask;
    short collisionGroup;
    unsigned char unknown56[24];
    irr::core::vector3d<float> cameraOffset;
    irr::core::vector3d<float> destination;
    irr::core::vector3d<float> adjustedDestination;
    bool destinationReachable;
    unsigned char unknown117[3];
    int destinationLimitSquared;
    int currentAnimation;
    unsigned char unknown128[8];
    int animationFrameCount;
    float animationFrame;
    unsigned char unknown144[4];
    bool animationLoops;
    unsigned char unknown149[3];
    int animationSpeedMultiplier;
    unsigned char unknown156[16];
    void* skinMesh;
    irr::scene::ISceneNode* shadowNode;
    b2Body* collisionBody;
    Character* lockTarget;
    Vehicle* vehicle;
    unsigned char unknown192[24];
    int maxHealth;
    int health;
    int punchIndex;
    unsigned char unknown228[4];
    int kickIndex;
    unsigned int movementFlags;
    unsigned char unknown240[4];
    int nextAnimation;
    unsigned char unknown248[12];
    LevelObject* target;
    int unknown264;
    int spawnType;
    irr::core::vector3d<float> turnDirection;
    float turnSpeed;
    bool turning;
    unsigned char unknown289[3];
    irr::scene::ISceneNode* bloodPuddle;
    void removeBloodPuddle();
    void cleanPhysic();
    void showBloodPuddle(irr::core::vector3d<float> position);
    void showBloodSplash(irr::core::vector3d<float> position, irr::core::vector3d<float> direction);

    void turnToward(const irr::core::vector3d<float>& point);
    bool turnToward(irr::core::vector3d<float> direction, float step);
    bool isFacingTarget(LevelObject* object);
    bool turnTowardTarget(LevelObject* object, float step);
    void turnTowardTarget(float step);
    bool isTargetInRange(float range, float degrees);
    void switchAnimation();
    bool switchMoveAnimation();
    void switchCombatAnimation();
    void goFromCombatToIdle();
    void ready(float speed);
    void checkForWeaponReload();
    void setReloadWeaponAnimation(int type);
    void resetCollisions();
};

#endif
