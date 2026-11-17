#ifndef WCH_INPUT_STICK_MOVE_EVENT_H
#define WCH_INPUT_STICK_MOVE_EVENT_H
#include "../core/GameEvents.h"

class EvStickMove : public IEvent {
public:
    virtual inline ~EvStickMove() __attribute__((used));

    float direction;
    float magnitude;
};

#endif
