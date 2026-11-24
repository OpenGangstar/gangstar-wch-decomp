#ifndef WCH_CHARACTERS_NPC_VEHICLE_EVENT_H
#define WCH_CHARACTERS_NPC_VEHICLE_EVENT_H

#include "../core/GameEvents.h"

class Vehicle;

class EvNPCVehicle : public IEvent {
public:
    EvNPCVehicle(int type, Vehicle* vehicle) : IEvent(19), type(type), vehicle(vehicle) {}
    virtual ~EvNPCVehicle() __attribute__((used, long_call));

private:
    int type;
    Vehicle* vehicle;
};

#endif
