#ifndef WCH_WORLD_TRAIL_H
#define WCH_WORLD_TRAIL_H

#include "../core/Vector3.h"

struct TrailPoint {
    unsigned char unknown0[24];
    int remainingLife;
};

class Trail {
public:
    Trail();
    virtual ~Trail();
    bool Init(int pointCount, int mode, int lifetime, float width, float scale);
    void Update();
    void SetSegmentWidth(float width);
    void SetLastAddedPoint(irr::core::vector3d<float> point);

    unsigned char unknown4[32];
    TrailPoint* points;

private:
    unsigned char unknown40[8];
    irr::core::vector3d<float> lastAddedPoint;
    unsigned char unknown60[20];
};

#endif
