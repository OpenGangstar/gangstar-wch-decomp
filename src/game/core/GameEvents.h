#ifndef WCH_CORE_GAME_EVENTS_H
#define WCH_CORE_GAME_EVENTS_H

// Dispatch slots observed at the call sites; no complete event layout is claimed.
class IEvent {
public:
    virtual ~IEvent() __attribute__((used));
    virtual int getEventID() const __attribute__((used));

protected:
    int eventID;
};
class EventManager;
class IEventReceiver {
public:
    virtual ~IEventReceiver() {}
    virtual void onEvent(const IEvent*, const EventManager*) = 0;
};
#endif
