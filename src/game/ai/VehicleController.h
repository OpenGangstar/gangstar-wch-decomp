#ifndef WCH_AI_VEHICLE_CONTROLLER_H
#define WCH_AI_VEHICLE_CONTROLLER_H

#include "AIManager.h"

class Path;
namespace irr { namespace core { template<class T> class vector3d; } }

namespace gameloft { namespace ai { struct Transition; } }

class VehicleController : public IEventReceiver {
public:
    VehicleController(Vehicle* vehicle, const gameloft::ai::Transition& transition,
        gameloft::ai::StateID state);
    virtual ~VehicleController();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void switchState(gameloft::ai::StateID);
    virtual irr::core::vector3d<float> getNextPoint();
    virtual irr::core::vector3d<float> getNextWaypoint();

private:
    unsigned int state;
    Vehicle* vehicle;
    const Path* path;
    const gameloft::ai::Transition& transition;
    unsigned int unknown20;
    int waypoint;
};

#endif
