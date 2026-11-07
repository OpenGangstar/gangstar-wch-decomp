#ifndef WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#define WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#include "../core/Vector3.h"
class b2World;
class b2Body;
struct PhysicInfo;
// Observed 120-byte allocation extent, index and info pointer. Other fields
// remain opaque; constructor and methods are retail call interfaces.
class PhysicAttributes {
public:
    irr::core::vector3d<float> GetNextRandomPos(int, int, irr::core::vector3d<float>);
    PhysicAttributes(int type, b2Body* body);
    ~PhysicAttributes();
    void SetPhysicInfo(const PhysicInfo& info, int flag);
    float GetHeight(const irr::core::vector3d<float>& position, int flag, bool detailed);
    static b2World* s_world;
    float IntersectSegmentWithHeightMap(const irr::core::vector3d<float>&,
        const irr::core::vector3d<float>&, irr::core::vector3d<float>&,
        irr::core::vector3d<float>&);
    // Observed slot index at offset zero; no standalone accessor is credited.
    int getIndex() const { return index; }
    int index;
    unsigned char unknown4[4];
    PhysicInfo* info;
    unsigned char unknown12[108];
};
#endif
