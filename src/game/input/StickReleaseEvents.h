#ifndef WCH_INPUT_STICK_RELEASE_EVENTS_H
#define WCH_INPUT_STICK_RELEASE_EVENTS_H

#include "../core/EventManager.h"

class EvStickReleased : public IEvent {
    float first, second;
public:
    EvStickReleased(float x, float y) : first(x), second(y) { eventID = 8; }
    virtual ~EvStickReleased() __attribute__((used)) {}
};

class EvLeftRightStickReleased : public IEvent {
    bool first; float second;
public:
    EvLeftRightStickReleased(bool active, float value) : first(active), second(value) { eventID = 10; }
    virtual ~EvLeftRightStickReleased() __attribute__((used)) {}
};

class EvUpDownStickReleased : public IEvent {
    bool first; float second;
public:
    EvUpDownStickReleased(bool active, float value) : first(active), second(value) { eventID = 12; }
    virtual ~EvUpDownStickReleased() __attribute__((used)) {}
};

#endif
