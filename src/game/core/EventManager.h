#ifndef WCH_CORE_EVENT_MANAGER_H
#define WCH_CORE_EVENT_MANAGER_H

#include "GameEvents.h"
#include "FrameInterfaces.h"

class EventManager : public IUpdatable {
public:
    EventManager();
    virtual ~EventManager();
    virtual void update(double);
    void raise(const IEvent& event);
    void raise(const IEvent* event);
    void raiseAsync(const IEvent* event) const;
    bool detach(int eventID, IEventReceiver* receiver);
    bool attach(int eventID, IEventReceiver* receiver);

private:
    enum { Capacity = 200 };

    struct ListenerGroup {
        IEventReceiver* receivers[Capacity];
        int count;
        int eventID;
    };

    struct Registration {
        int eventID;
        IEventReceiver* receiver;
    };

    void _trace(const char*) const;
    bool _attach(int eventID, IEventReceiver* receiver);
    bool _detach(int eventID, IEventReceiver* receiver);
    void refresh();

    int dispatchDepth;
    ListenerGroup groups[Capacity];
    int groupCount;
    mutable const IEvent* queuedEvents[Capacity];
    mutable int queuedCount;
    Registration pendingAttaches[Capacity];
    int pendingAttachCount;
    Registration pendingDetaches[Capacity];
    int pendingDetachCount;
};

#endif
