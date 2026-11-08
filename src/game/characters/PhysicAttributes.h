#ifndef WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#define WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#include "../core/Vector3.h"
class b2World;
class b2Body;
namespace irr { namespace scene { class ISceneNode; } }
struct PhysicInfo;
// Observed 120-byte allocation extent, index and info pointer. Other fields
// remain opaque; constructor and methods are retail call interfaces.
class PhysicAttributes {
public:
    irr::core::vector3d<float> GetNextRandomPos(int, int, irr::core::vector3d<float>);
    PhysicAttributes(int type, b2Body* body);
    ~PhysicAttributes();
    void Init(unsigned short region, unsigned short surface, const irr::core::vector3d<float>& position);
    void SetPhysicInfo(const PhysicInfo& info, int flag);
    void ResetPhysicInfo();
    void SetIsOnGround(int slot, bool value);
    irr::scene::ISceneNode* GetSceneNodeFromID(irr::scene::ISceneNode* node, int id);
    void UpdateEdgesCollisions(int slot);
    float GetHeight(const irr::core::vector3d<float>& position, int flag, bool detailed);
    float GetHeightFrom(int source, const irr::core::vector3d<float>& position, int slot);
    static b2World* s_world;
    float IntersectSegmentWithHeightMap(const irr::core::vector3d<float>&,
        const irr::core::vector3d<float>&, irr::core::vector3d<float>&,
        irr::core::vector3d<float>&);
    // Observed slot index at offset zero; no standalone accessor is credited.
    int getIndex() const { return index; }
    int index;
    unsigned char unknown4[4];
    PhysicInfo* info;
    int infoCount;
    unsigned char unknown16[104];
};
#endif
