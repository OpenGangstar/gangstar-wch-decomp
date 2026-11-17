#ifndef WCH_CORE_CAMERA_VARIANTS_H
#define WCH_CORE_CAMERA_VARIANTS_H

#include "Camera.h"

class PhysicAttributes;

// Derived storage is partial. FollowCamera owns the physics pointer at byte 36.
class FollowCamera : public Camera {
public:
    ~FollowCamera();
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void debug(irr::video::IVideoDriver* driver);
private:
    unsigned char unknown28[8];
    PhysicAttributes* physics;
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
    virtual void init(LevelObject* owner, int mode);
    virtual void update(float elapsed);
    virtual void enter();
    virtual void debug(irr::video::IVideoDriver* driver);
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
