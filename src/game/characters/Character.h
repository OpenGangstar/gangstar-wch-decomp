#ifndef WCH_CHARACTERS_CHARACTER_H
#define WCH_CHARACTERS_CHARACTER_H

#include "../world/LevelObject.h"

class Vehicle;
class Weapon;

// Character's constructor calls LevelObject and initializes storage through
// offset 295. NPC's first additional field is at 296. Other fields and virtual
// overrides remain unrecovered; keep their storage opaque.
class Character : public LevelObject {
public:
    Character(int type);
    virtual ~Character();
    void initInVehicle(Vehicle* vehicle);
    void goToIdle();
    bool isDown();
    bool isDying();
    virtual bool isDead();
    virtual int getSpawnType();
    virtual void setSpawnType(int type);
    virtual void* getSkinMesh();
    virtual int getMaxHealth() const;
    virtual int getHealth() const;
    void resetAnimation();
    static void cleanTimelineController();
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
    static irr::scene::ITimelineController* s_timelineController;
    bool isCurrentAnimation(int id);
    bool canAnimationBeInterrupted(int id);
    int getSpecificAnimation(int id);
    unsigned char unknown52[28];
    irr::core::vector3d<float> cameraOffset;
    irr::core::vector3d<float> destination;
    unsigned char unknown104[16];
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
    unsigned char unknown176[8];
    Character* lockTarget;
    Vehicle* vehicle;
    unsigned char unknown192[24];
    int maxHealth;
    int health;
    unsigned char unknown224[12];
    unsigned int movementFlags;
    unsigned char unknown240[4];
    int nextAnimation;
    unsigned char unknown248[12];
    LevelObject* target;
    unsigned char unknown264[4];
    int spawnType;
    unsigned char unknown272[24];

    void turnToward(const irr::core::vector3d<float>& point);
    bool isFacingTarget(LevelObject* object);
    bool turnTowardTarget(LevelObject* object, float step);
    void turnTowardTarget(float step);
    bool isTargetInRange(float range, float degrees);
};

#endif
