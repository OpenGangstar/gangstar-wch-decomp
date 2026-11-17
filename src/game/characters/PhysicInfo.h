#ifndef WCH_CHARACTERS_PHYSIC_INFO_H
#define WCH_CHARACTERS_PHYSIC_INFO_H

#include "../core/Vector3.h"

class b2Body;
class b2World;

struct PhysicInfo {
    PhysicInfo() __attribute__((weak));
    // The retail array allocation has an ARM EABI cookie.
    ~PhysicInfo() {}
    void Reset(b2World* world) __attribute__((weak));

    unsigned short unknown0;
    unsigned char unknown2[2];
    unsigned int unknown4;
    unsigned short unknown8;
    unsigned char unknown10[2];
    irr::core::vector3d<float> vector12, vector24, vector36, vector48;
    bool unknown60;
    unsigned char unknown61[3];
    irr::core::vector3d<float> unknown64;
    unsigned short unknown76, unknown78, unknown80;
    unsigned char unknown82[6];
    b2Body* bodies[12];
    bool onGround;
    bool wasOnGround;
    unsigned char unknown138[2];
};

#endif
