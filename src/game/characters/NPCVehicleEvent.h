#ifndef WCH_CHARACTERS_NPC_VEHICLE_EVENT_H
#define WCH_CHARACTERS_NPC_VEHICLE_EVENT_H

#include "../core/GameEvents.h"

class Vehicle;

class EvNPCVehicle : public IEvent {
public:
    EvNPCVehicle(int type, Vehicle* vehicle) : type(type), vehicle(vehicle) { eventID = 19; }
    virtual ~EvNPCVehicle() __attribute__((used));

private:
    int type;
    Vehicle* vehicle;
};

#endif
