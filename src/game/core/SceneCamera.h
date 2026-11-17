#ifndef WCH_CORE_SCENE_CAMERA_H
#define WCH_CORE_SCENE_CAMERA_H
#include "Camera.h"
#include "../characters/Transformation.h"
namespace Structs { struct SceneCamera; }
// Constructor establishes Camera at 0 and Transformation at 28. The dispatcher
// allocates 128 bytes and performs nullable conversions through LevelObject.
class SceneCamera : public Camera, public Transformation {
public:
    SceneCamera(int type);
    virtual void init(LevelObject* target, int mode);
    virtual ~SceneCamera();
    virtual void update(float elapsed);
    virtual void debug(irr::video::IVideoDriver* driver);
    void Load(const Structs::SceneCamera&);
private:
    irr::core::vector3d<float> vector112;
    unsigned char unknown124[4];
};
#endif
