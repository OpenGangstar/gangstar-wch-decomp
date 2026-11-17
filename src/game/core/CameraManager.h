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
    AnimatableType() : interpolationMode(0), interpolate(true) {}
    void Update(float elapsed) __attribute__((weak));

    T start;
    T end;
    T current;
    float progress;
    int interpolationMode;
    bool interpolate;
    unsigned char unknown45[7];
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

    void* touch;
    irr::scene::ICameraSceneNode* cameraNode;
    LevelObject* target;
    int mode;
    Camera* currentCamera;
    FollowCamera* followCamera;
    LockCamera* lockCamera;
    VehicleCamera* vehicleCamera;
    LevelObject* touchTarget;
    FPSCamera* fpsCamera;
    unsigned char unknown44[4];
    AnimatableType<irr::core::vector3d<float> > positionTransition;
    AnimatableType<irr::core::vector3d<float> > targetTransition;
    bool touchScreenInputs;
    bool used;
    bool flag154;
    bool flag155;
    int touchX;
    int touchY;
    int value164;
    int value168;
    SceneCamera* sceneCamera;
};

#endif
