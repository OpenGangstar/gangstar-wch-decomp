#ifndef WCH_CORE_GAME_EVENT_METHODS_H
#define WCH_CORE_GAME_EVENT_METHODS_H

#include "GameEvents.h"

inline int IEvent::getEventID() const
{
    return eventID;
}

inline IEvent::~IEvent()
{
}

#endif
