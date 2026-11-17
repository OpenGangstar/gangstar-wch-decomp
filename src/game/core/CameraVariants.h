#ifndef WCH_CORE_CAMERA_VARIANTS_H
#define WCH_CORE_CAMERA_VARIANTS_H

#include "Camera.h"

// FollowCamera, VehicleCamera and FPSCamera expose the destructor interfaces
// used by the manager. Their derived storage and overrides remain pending.
class FollowCamera : public Camera {
public:
    ~FollowCamera();
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
};

class FPSCamera : public Camera {
public:
    ~FPSCamera();
};

#endif
