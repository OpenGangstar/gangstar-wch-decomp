#ifndef WCH_CORE_PHYSICS_BODY_DEF_H
#define WCH_CORE_PHYSICS_BODY_DEF_H

#include "Physics.h"

struct b2MassData { float mass; b2Vec2 center; float I; };
struct b2BodyDef {
    b2BodyDef()
    {
        massData.center.x = 0.0f;
        massData.center.y = 0.0f;
        massData.mass = 0.0f;
        massData.I = 0.0f;
        userData = 0;
        linearDamping = 0.0f;
        angularDamping = 0.0f;
        position.x = 0.0f;
        position.y = 0.0f;
        angle = 0.0f;
        allowSleep = true;
        isSleeping = false;
        fixedRotation = false;
        isBullet = false;
    }

    b2MassData massData;
    void* userData;
    b2Vec2 position;
    float angle, linearDamping, angularDamping;
    bool allowSleep, isSleeping, fixedRotation, isBullet;
};

#endif
