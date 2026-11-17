#ifndef WCH_CORE_CAMERA_VARIANTS_H
#define WCH_CORE_CAMERA_VARIANTS_H

#include "Camera.h"

class PhysicAttributes;

inline __attribute__((always_inline))
void updateCameraInputRates(int horizontal, int vertical, float& yawRate, float& pitchRate)
{
    yawRate = (horizontal / 480.0f) * 100.0f * 600.0f / 1000.0f;
    pitchRate = (vertical / 320.0f) * 100.0f * -600.0f / 1000.0f;
}

// Derived storage is partial. FollowCamera owns the physics pointer at byte 36.
class FollowCamera : public Camera {
public:
    ~FollowCamera();
    void updateAngles(int horizontal, int vertical);
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    unsigned char unknown28[8];
    PhysicAttributes* physics;
    unsigned char unknown40[4];
    float yawRate;
    float pitchRate;
};

class LockCamera : public Camera {
public:
    explicit LockCamera(LevelObject* owner);
    ~LockCamera();
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    LevelObject* owner;
};

class VehicleCamera : public Camera {
public:
    ~VehicleCamera();
    void updateAngles(int horizontal, int vertical);
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void enter();
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    unsigned char unknown28[40];
    float yawRate;
    float pitchRate;
};

class FPSCamera : public Camera {
public:
    ~FPSCamera();
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void enter();
    virtual void exit();
    virtual void debug(irr::video::IVideoDriver* driver);
};

#endif
