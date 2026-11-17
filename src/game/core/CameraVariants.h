#ifndef WCH_CORE_CAMERA_VARIANTS_H
#define WCH_CORE_CAMERA_VARIANTS_H

#include "Camera.h"

class PhysicAttributes;
class Character;
class Vehicle;

inline __attribute__((always_inline))
void updateCameraInputRates(int horizontal, int vertical, float& yawRate, float& pitchRate)
{
    yawRate = (horizontal / 480.0f) * 100.0f * 600.0f / 1000.0f;
    pitchRate = (vertical / 320.0f) * 100.0f * -600.0f / 1000.0f;
}

// Derived storage is partial. FollowCamera owns the physics pointer at byte 36.
class FollowCamera : public Camera {
public:
    explicit FollowCamera(Character* owner);
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
    explicit VehicleCamera(LevelObject* owner);
    ~VehicleCamera();
    void updateAngles(int horizontal, int vertical);
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void enter();
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    Vehicle* vehicle;
    unsigned char unknown32[8];
    irr::core::vector3d<float> vector40;
    irr::core::vector3d<float> vector52;
    unsigned char unknown64[4];
    float yawRate;
    float pitchRate;
    bool entered;
};

class FPSCamera : public Camera {
public:
    FPSCamera();
    ~FPSCamera();
    void incVerticalAngle(float delta);
    void zoom(int degrees);
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void enter();
    virtual void exit();
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    unsigned char unknown28[4];
    float verticalAngle;
    int value36;
    int value40;
    int value44;
    int value48;
    float value52;
    float value56;
    bool flag60;
};

#endif
