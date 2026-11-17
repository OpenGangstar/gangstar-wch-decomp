#ifndef WCH_WORLD_TRAIL_H
#define WCH_WORLD_TRAIL_H

#include "../core/Vector3.h"

namespace irr { namespace scene { class ISceneNode; } }

struct TrailPoint {
    irr::core::vector3d<float> left;
    irr::core::vector3d<float> right;
    int remainingLife;
    TrailPoint() : remainingLife(0) {}
};

class Trail {
public:
    Trail();
    virtual ~Trail();
    bool Init(int pointCount, int mode, int lifetime, float width, float scale);
    void Update();
    void Render();
    void ModifyLife(float scale);
    void SetSegmentWidth(float width);
    void SetLastAddedPoint(irr::core::vector3d<float> point);

private:
    void CreateMeshSceneNode();
    void CleanUp();
    int trailLifetime;
    float segmentWidth;
    int trailMode;
    int trailPointCount;
    int segmentCount;
    int triangleCount;
    int vertexCount;
    int indexCount;
public:
    TrailPoint* points;

private:
    int unknown40;
    int activePointCount;
    irr::core::vector3d<float> lastAddedPoint;
    float trailScaleSquared;
    unsigned char unknown64[4];
    irr::scene::ISceneNode* meshSceneNode;
    unsigned short* indices;
    bool unknown76;
    unsigned char unknown77[3];
};

#endif
