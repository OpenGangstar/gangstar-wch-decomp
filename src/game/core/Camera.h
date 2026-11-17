#ifndef WCH_CORE_CAMERA_H
#define WCH_CORE_CAMERA_H
#include "Vector3.h"
// Observed 28-byte primary base. Remaining virtual interface is unrecovered.
class Camera {
public:
    Camera();
    virtual ~Camera();
protected:
    irr::core::vector3d<float> position;
private:
    unsigned char unknown16[12];
};
#endif
