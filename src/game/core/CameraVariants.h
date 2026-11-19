#ifndef WCH_CORE_CAMERA_VARIANTS_H
#define WCH_CORE_CAMERA_VARIANTS_H

#include "Camera.h"

template<class T> struct Point2D;
namespace std {
template<class T> class allocator;
template<class T, class Alloc> class list;
}

class PhysicAttributes;
class Character;
typedef Character SavePositionInterface;
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
    void goBehind(LevelObject* object);
    ~FollowCamera();
    void updateAngles(int horizontal, int vertical);
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    void updatePosition(float elapsed, const irr::core::vector3d<float>& pivot,
        float distance, irr::core::vector3d<float>& yawAxis,
        irr::core::vector3d<float>& pitchAxis, float maximumPitch, float minimumPitch);
    irr::core::vector3d<float> getFacing() const;
    Character* owner;
    bool flag32;
    unsigned char unknown33[3];
    PhysicAttributes* physics;
    float previousHeight;
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
    void goToSide(bool left);
    ~VehicleCamera();
    void updateAngles(int horizontal, int vertical);
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void enter();
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    void updatePosition(float elapsed, const irr::core::vector3d<float>& pivot,
        float distance, irr::core::vector3d<float>& yawAxis,
        irr::core::vector3d<float>&, float, float);
    Vehicle* vehicle;
    float distance;
    float previousSpeed;
    irr::core::vector3d<float> vector40;
    irr::core::vector3d<float> vector52;
    float previousHeight;
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
    void zoom(const std::list<Point2D<short>*, std::allocator<Point2D<short>*> >& points);
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void enter();
    virtual void exit();
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    void updateTouchInputs();
    SavePositionInterface* owner;
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
