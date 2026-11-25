#ifndef WCH_CHARACTERS_PHYSIC_INFO_H
#define WCH_CHARACTERS_PHYSIC_INFO_H

#include "../core/Vector3.h"

class b2Body;
class b2World;
namespace irr { namespace scene { class ISceneNode; } }

struct PhysicInfo {
    PhysicInfo() __attribute__((used))
    {
        unknown64.Z = 999999.0f;
        for (int i = 0; i < 12; ++i)
            bodies[i] = 0;
        Reset(0);
    }
    // The retail array allocation has an ARM EABI cookie.
    ~PhysicInfo() {}
    void Reset(b2World* world) __attribute__((weak));

    unsigned short unknown0;
    unsigned char unknown2[2];
    union { unsigned int unknown4; irr::scene::ISceneNode* heightmap; };
    unsigned short unknown8;
    unsigned char unknown10[2];
    irr::core::vector3d<float> vector12, vector24, vector36, vector48;
    bool unknown60;
    unsigned char unknown61[3];
    irr::core::vector3d<float> unknown64;
    unsigned short unknown76, unknown78, unknown80;
    unsigned short unknown82;
    bool unknown84;
    unsigned char unknown85[3];
    b2Body* bodies[12];
    bool onGround;
    bool wasOnGround;
    unsigned char unknown138[2];
};

#endif
