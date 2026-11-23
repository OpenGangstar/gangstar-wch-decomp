#ifndef WCH_VEHICLES_VEHICLE_EVENTS_H
#define WCH_VEHICLES_VEHICLE_EVENTS_H

#include "../core/GameEventMethods.h"

class Vehicle;

class EvVehicleDeactivated : public IEvent {
public:
    explicit EvVehicleDeactivated(Vehicle* vehicle) : vehicle(vehicle) { eventID = 21; }
    Vehicle* vehicle;
    Vehicle* getTarget() const { return vehicle; }
    virtual ~EvVehicleDeactivated() __attribute__((used));
};

class EvVehicleDestroyed : public IEvent {
public:
    EvVehicleDestroyed() {}
    explicit EvVehicleDestroyed(Vehicle* value) : IEvent(20), vehicle(value) {}
    virtual ~EvVehicleDestroyed() __attribute__((used));
    Vehicle* getTarget() const { return vehicle; }
private:
    Vehicle* vehicle;
};

#endif
