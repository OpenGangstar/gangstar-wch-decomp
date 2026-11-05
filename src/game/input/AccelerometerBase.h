#ifndef WCH_INPUT_ACCELEROMETER_BASE_H
#define WCH_INPUT_ACCELEROMETER_BASE_H

#include "../core/FrameInterfaces.h"

class AccelerometerBase : public IUpdatable {
public:
    virtual ~AccelerometerBase();
    virtual void update(double elapsed);
    virtual void moved(float x, float y, float z);
    void clear();

private:
    float x;
    float y;
    float z;
    float baselineX;
    float baselineY;
    float baselineZ;
    float minX;
    unsigned char unknown32[8];
    float maxX;
    unsigned char unknown44[32];
};

#endif
