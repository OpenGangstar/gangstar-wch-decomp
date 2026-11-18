#ifndef WCH_INPUT_DIRECTIONAL_STICK_EVENTS_H
#define WCH_INPUT_DIRECTIONAL_STICK_EVENTS_H
#include "../core/GameEvents.h"

class EvUpDownStickMove : public IEvent {
public:
    EvUpDownStickMove() {}
    EvUpDownStickMove(bool positive, float distance)
        : IEvent(11), positive(positive), distance(distance) {}
    virtual ~EvUpDownStickMove() __attribute__((used)) {}

    bool positive;
    float distance;
};

class EvLeftRightStickMove : public IEvent {
public:
    EvLeftRightStickMove() {}
    EvLeftRightStickMove(bool positive, float distance)
        : IEvent(9), positive(positive), distance(distance) {}
    virtual ~EvLeftRightStickMove() __attribute__((used)) {}

    bool positive;
    float distance;
};
#endif
