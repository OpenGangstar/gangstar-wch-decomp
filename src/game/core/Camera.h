#ifndef WCH_CORE_CAMERA_H
#define WCH_CORE_CAMERA_H
#include "Vector3.h"
class LevelObject;
namespace irr { namespace video { class IVideoDriver; } }

// Observed 28-byte primary base and five virtual slots.
class Camera {
public:
    Camera();
    ~Camera();
    virtual void init(LevelObject* target, int mode) = 0;
    virtual void update(float elapsed) = 0;
    virtual void enter();
    virtual void exit();
    virtual void debug(irr::video::IVideoDriver* driver) = 0;
    const irr::core::vector3d<float>& getPosition() const;
    const irr::core::vector3d<float>& getLookAt() const;
    void setPosition(const irr::core::vector3d<float>& value);
    void setLookAt(const irr::core::vector3d<float>& value);
protected:
    irr::core::vector3d<float> position;
    irr::core::vector3d<float> lookAt;
};
#endif
