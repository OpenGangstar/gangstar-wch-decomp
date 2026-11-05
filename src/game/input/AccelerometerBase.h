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
    unsigned char unknown32[8];
    float maxX;
    unsigned char unknown44[8];
    float angleX;
    unsigned char unknown56[4];
    float angleY;
    unsigned char unknown64[4];
    float angleZ;
    unsigned char unknown72[4];
};

#endif
