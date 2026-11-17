#ifndef WCH_MISSIONS_WANTED_LEVEL_EVENTS_H
#define WCH_MISSIONS_WANTED_LEVEL_EVENTS_H

#include "../core/EventManager.h"

class EvWantedLevelChanged : public IEvent {
public:
    EvWantedLevelChanged() { eventID = 23; }
    virtual ~EvWantedLevelChanged() __attribute__((used)) {}
};

#endif
