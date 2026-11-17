#ifndef WCH_CORE_CAMERA_MANAGER_H
#define WCH_CORE_CAMERA_MANAGER_H

#include "SceneNode.h"

// Recovered call interface; complete manager layout remains unknown.
class LevelObject;
class Camera;
class SceneCamera;

class CameraManager {
public:
    static CameraManager* getInstance();
    void setFOV(int degrees);
    int getFOV();
    irr::scene::ICameraSceneNode* getCamera() const;
    void debug(irr::video::IVideoDriver*);
    void setSceneCamera(SceneCamera* scene);
    void update(float);
    void enterMode(int mode, LevelObject* target, float transition, int flags);
    void setTouchScreenInputs(bool);
    bool isUsed() const;
    const irr::core::vector3d<float>& getPosition() const;
    const irr::core::vector3d<float>& getLookAt() const;

private:
    CameraManager(float nearDistance, float farDistance, float fov, LevelObject* target);
    static CameraManager* s_cm;

    unsigned char unknown0[8];
    irr::scene::ICameraSceneNode* cameraNode;
    unsigned char unknown12[8];
    Camera* currentCamera;
    unsigned char unknown24[128];
    bool touchScreenInputs;
    bool used;
    unsigned char unknown154[18];
    SceneCamera* sceneCamera;
};

#endif
