#ifndef WCH_INPUT_STICK_MOVE_EVENT_H
#define WCH_INPUT_STICK_MOVE_EVENT_H
#include "../core/GameEvents.h"

class EvStickMove : public IEvent {
public:
    EvStickMove() {}
    EvStickMove(float direction, float magnitude)
        : IEvent(7), direction(direction), magnitude(magnitude) {}
    virtual inline ~EvStickMove() __attribute__((used));

    float direction;
    float magnitude;
};

#endif
