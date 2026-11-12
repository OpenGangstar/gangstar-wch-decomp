#ifndef WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#define WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#include "../core/Array.h"
#include "../core/Vector3.h"
class b2World;
class b2Body;
class b2ContactFilter;
class b2ContactListener;
namespace irr { namespace scene { class ISceneNode; } }
struct PhysicInfo;
struct AStarNode;
// Partial layout of the observed 120-byte allocation.
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
    static bool* s_PoolID;
    static b2Body* s_groundBody;
    static b2ContactFilter* s_contactFilter;
    static b2ContactListener* s_contactListener;
    static void InitWorld();
    static void CleanWorld();
    static void CreateNeighborTris(irr::scene::ISceneNode* node, int id);
    static irr::scene::ISceneNode* s_heightmap;
    irr::core::vector3d<float> GetPathPos(int index);
    static irr::core::vector3d<float> GetTriCenter(unsigned short bufferIndex, unsigned short triangleOffset);
    float IntersectSegmentWithHeightMap(const irr::core::vector3d<float>&,
        const irr::core::vector3d<float>&, irr::core::vector3d<float>&,
        irr::core::vector3d<float>&);
    // Observed slot index at offset zero; no standalone accessor is credited.
    int getIndex() const { return index; }
    int index;
    unsigned char unknown4[4];
    PhysicInfo* info;
    int infoCount;
    irr::core::array<AStarNode> path;
    irr::core::vector3d<float> pathTarget;
    int pathLength;
    unsigned char unknown52[68];
};
#endif
