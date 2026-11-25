#ifndef WCH_INPUT_ACCELEROMETER_BASE_H
#define WCH_INPUT_ACCELEROMETER_BASE_H

#include "../core/FrameInterfaces.h"

class AccelerometerBase : public IUpdatable {
public:
    AccelerometerBase();
    virtual ~AccelerometerBase();
    virtual void update(double elapsed);
    virtual void moved(float x, float y, float z);
    void clear();

private:
    void _calcAngles();
    void _trace(const char* message) const;

    float x;
    float y;
    float z;
    float baselineX;
    float baselineY;
    float baselineZ;
    float minX;
    float minY;
    float minZ;
    float maxX;
    float maxY;
    float maxZ;
    float angleX;
    float curX;
    float angleY;
    float curY;
    float angleZ;
    float curZ;
};

#endif
