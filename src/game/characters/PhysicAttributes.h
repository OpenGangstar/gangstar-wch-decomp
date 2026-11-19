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
    // Local observed initialization view; adds no storage to the 20-byte array.
    struct PathArray : irr::core::array<AStarNode> {
        PathArray()
        {
            data = 0;
            allocated = 0;
            used = 0;
            free_when_destroyed = true;
            is_sorted = true;
            unknown16 = 1;
        }
    };
public:
    static void LoadArrays(char*);
    static int MATERIAL_TYPE_ROAD, MATERIAL_TYPE_PARK, MATERIAL_TYPE_BUILDING_BASE, MATERIAL_TYPE_INTERSECTION, MATERIAL_TYPE_CLIFF, MATERIAL_TYPE_WATER;
    static int MATERIAL_TYPE_DEATH_WATER;
    static unsigned short*** s_neighbors;
    static unsigned char** s_neighborsWrongWay;
    static unsigned short* s_neighborsCnt;
    static irr::core::array<unsigned short>** s_overlapping;
    // Cleanup-only POD views; original cliff-map element types remain unrecovered.
    // LoadArrays now confirms unsigned-short elements for both maps.
    static unsigned short* s_cliffVertexKeyMap;
    static unsigned short* s_cliffTriMap;
    static float** s_nodeCost;
    AStarNode FindLowerCostNode(irr::core::array<AStarNode>*, int*);
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
    static int MATERIAL_TYPE_SIDEWALK;
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
    union { unsigned char unknown4[4]; b2Body* body; };
    PhysicInfo* info;
    int infoCount;
    PathArray path;
    irr::core::vector3d<float> pathTarget;
    int pathLength;
    void SetCurrentJumpShape(b2Shape* shape);
    // Slots 0..3 are corners; slot 4 is their computed center.
    irr::core::vector3d<float> jumpVertices[5];
    bool hasJumpShape;
    unsigned char jumpFlags;
    unsigned char unknown114[2];
    int unknown116;
};
#endif
