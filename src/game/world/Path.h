#ifndef WCH_WORLD_PATH_H
#define WCH_WORLD_PATH_H
#include "../characters/Transformation.h"
namespace Structs { struct Path; }
class Path : public Transformation {
public:
    Path(int type);
    virtual ~Path();
    void Load(const Structs::Path&, irr::collada::CColladaFactory*);
    int getSize() const;
    bool getWaypoint(int index, irr::core::vector3d<float>& position) const;
private:
    irr::core::vector3d<float> pathPosition;
    irr::core::quaternion pathRotation;
    int waypointCount;
    irr::core::vector3d<float>* waypoints;
};
#endif
