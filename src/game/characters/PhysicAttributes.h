#ifndef WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#define WCH_CHARACTERS_PHYSIC_ATTRIBUTES_H
#include "../core/Array.h"
#include "../core/Vector3.h"
class b2World;
class b2Body;
class b2Shape;
class b2ContactFilter;
class b2ContactListener;
namespace irr { namespace scene { class ISceneNode; } }
struct PhysicInfo;
struct AStarNode;
// Partial layout of the observed 120-byte allocation.
class PhysicAttributes {
public:
    static int MATERIAL_TYPE_DEATH_WATER;
    static unsigned short*** s_neighbors;
    static unsigned char** s_neighborsWrongWay;
    static unsigned short* s_neighborsCnt;
    static irr::core::array<unsigned short>** s_overlapping;
    // Cleanup-only POD views; original cliff-map element types remain unrecovered.
    static unsigned int* s_cliffVertexKeyMap;
    static unsigned int* s_cliffTriMap;
    static float** s_nodeCost;
    void AddCollisionShapes(int slot, unsigned short vertex);
    static bool SegmentsIntersect(const irr::core::vector3d<float>& a,
        const irr::core::vector3d<float>& b, const irr::core::vector3d<float>& c,
        const irr::core::vector3d<float>& d);
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
    static void Clean();
    static void CleanWorld();
    static unsigned short MATERIAL_TYPE_SIDEWALK;
    static irr::core::vector3d<float> GetRandomDestination(unsigned short material, unsigned short& surface,
        const irr::core::vector3d<float>& origin, float minimum, float maximum);
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
    void SetCurrentJumpShape(b2Shape* shape);
    irr::core::vector3d<float> jumpVertices[4];
    irr::core::vector3d<float> jumpCenter;
    bool hasJumpShape;
    unsigned char jumpFlags;
    unsigned char unknown114[6];
};
#endif
