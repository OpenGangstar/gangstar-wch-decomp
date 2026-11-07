#ifndef WCH_CHARACTERS_CHARACTER_H
#define WCH_CHARACTERS_CHARACTER_H

#include "../world/LevelObject.h"

class Vehicle;

// Character's constructor calls LevelObject and initializes storage through
// offset 295. NPC's first additional field is at 296. Other fields and virtual
// overrides remain unrecovered; keep their storage opaque.
class Character : public LevelObject {
public:
    Character(int type);
    void initInVehicle(Vehicle* vehicle);
    void goToIdle();
    void setDestination(const irr::core::vector3d<float>& point, int duration);
    bool isPlayer() const;
    using LevelObject::sceneNode;
    using LevelObject::setAnimation;
    // Retail slots 40 through 53. The remaining slots are pending.
    virtual void setAnimation(int id, float speed, bool a, bool b, bool c);
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
private:
    unsigned char unknown52[244];
};

#endif
