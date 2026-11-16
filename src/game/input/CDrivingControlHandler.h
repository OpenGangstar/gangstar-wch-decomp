#ifndef WCH_INPUT_CDRIVINGCONTROLHANDLER_H
#define WCH_INPUT_CDRIVINGCONTROLHANDLER_H

#include "IControlHandler.h"

class Vehicle;

// Recovered virtual interface. The member layout is still incomplete.
class CControlManager;

class CDrivingControlHandler : public IControlHandler {
public:
    void init();
    virtual ~CDrivingControlHandler();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void activate();
    virtual void deactivate() __attribute__((noinline));
    virtual void releaseKeyboardKeys();

private:
    template<bool (EventManager::*operation)(int, IEventReceiver*)>
    inline __attribute__((always_inline)) void updateDrivingEvents();
    CControlManager* controlManager;
    Vehicle* vehicle;
    unsigned char unknown12[4];
    bool unknown16;
    bool unknown17;
    int unknown20;
    float unknown24[6];
};

#endif
