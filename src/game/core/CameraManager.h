#ifndef WCH_CORE_CAMERA_MANAGER_H
#define WCH_CORE_CAMERA_MANAGER_H

#include "SceneNode.h"
#include "Vector3.h"

// Recovered call interface; complete manager layout remains unknown.
class LevelObject;
class Camera;
class SceneCamera;
class FollowCamera;
class LockCamera;
class VehicleCamera;
class FPSCamera;

template<class T>
class AnimatableType {
public:
    void Update(float elapsed) __attribute__((weak));

    unsigned char unknown0[24];
    T current;
    float progress;
    unsigned char unknown40[12];
};

class CameraManager {
public:
    static CameraManager* getInstance();
    ~CameraManager();
    void clean();
    virtual void processTouch(long touch);
    virtual void processTouchRelease();
    void setFOV(int degrees);
    int getFOV();
    irr::scene::ICameraSceneNode* getCamera() const;
    void debug(irr::video::IVideoDriver*);
    void setSceneCamera(SceneCamera* scene);
    void update(float);
    void enterMode(int mode, LevelObject* target, float transition, int flags);
    void setTouchScreenInputs(bool);
    virtual bool isUsed() const;
    const irr::core::vector3d<float>& getPosition() const;
    const irr::core::vector3d<float>& getLookAt() const;

private:
    CameraManager(float nearDistance, float farDistance, float fov, LevelObject* target);
    bool updateTransition(float elapsed);
    static CameraManager* s_cm;

    unsigned char unknown4[4];
    irr::scene::ICameraSceneNode* cameraNode;
    unsigned char unknown12[8];
    Camera* currentCamera;
    FollowCamera* followCamera;
    LockCamera* lockCamera;
    VehicleCamera* vehicleCamera;
    unsigned char unknown36[4];
    FPSCamera* fpsCamera;
    unsigned char unknown44[4];
    AnimatableType<irr::core::vector3d<float> > positionTransition;
    AnimatableType<irr::core::vector3d<float> > targetTransition;
    bool touchScreenInputs;
    bool used;
    unsigned char unknown154[18];
    SceneCamera* sceneCamera;
};

#endif
