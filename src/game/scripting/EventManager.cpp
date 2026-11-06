/*
 * EventManager
 *
 * Original file: EventManager.cpp
 * Area:          scripting
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of EventManager.cpp here, in the order they appear in the library.
 */

#include "../core/EventManager.h"

EventManager::EventManager() : dispatchDepth(0) {}

void EventManager::_trace(const char*) const {}

bool EventManager::attach(int eventID, IEventReceiver* receiver)
{
    Registration& entry = pendingAttaches[pendingAttachCount];
    entry.receiver = receiver;
    entry.eventID = eventID;
    ++pendingAttachCount;
    return true;
}

bool EventManager::detach(int eventID, IEventReceiver* receiver)
{
    Registration& entry = pendingDetaches[pendingDetachCount];
    entry.receiver = receiver;
    entry.eventID = eventID;
    ++pendingDetachCount;
    return true;
}

void EventManager::raiseAsync(const IEvent* event) const
{
    queuedEvents[queuedCount++] = event;
}

void EventManager::refresh()
{
    if (dispatchDepth > 0)
        return;

    for (int i = 0; i < pendingDetachCount; ++i)
        _detach(pendingDetaches[i].eventID, pendingDetaches[i].receiver);
    pendingDetachCount = 0;

    for (int i = 0; i < pendingAttachCount; ++i)
        _attach(pendingAttaches[i].eventID, pendingAttaches[i].receiver);
    pendingAttachCount = 0;
}

void EventManager::raise(const IEvent& event)
{
    refresh();
    ++dispatchDepth;
    for (int i = 0; i < groupCount; ++i) {
        if (groups[i].eventID == event.getEventID()) {
            for (int j = 0; j < groups[i].count; ++j)
                groups[i].receivers[j]->onEvent(&event, this);
            break;
        }
    }
    --dispatchDepth;
}

void EventManager::raise(const IEvent* event)
{
    raise(*event);
}

void EventManager::update(double)
{
    // Retail rereads the first slot and count after dispatch.
    while (queuedCount > 0) {
        const IEvent* event = queuedEvents[0];
        raise(event);
        delete event;
    }
}

EventManager::~EventManager()
{
    queuedCount = 0;
}
