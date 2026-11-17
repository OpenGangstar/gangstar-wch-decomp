#ifndef WCH_INPUT_CDRIVINGCONTROLHANDLER_H
#define WCH_INPUT_CDRIVINGCONTROLHANDLER_H

#include "IControlHandler.h"

class Vehicle;

// Recovered virtual interface. The member layout is still incomplete.
class CControlManager;

class CDrivingControlHandler : public IControlHandler {
public:
    explicit CDrivingControlHandler(CControlManager* manager);
    void init();
    virtual ~CDrivingControlHandler();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void activate();
    virtual void deactivate() __attribute__((noinline));
    virtual void releaseKeyboardKeys();

private:
    void handleAttackReleased();
    void handleAttackHeld();
    void handleAttackPressed();
    void handleWeaponSwitched();
    void disableAccelerometer();
    template<bool (EventManager::*operation)(int, IEventReceiver*)>
    inline __attribute__((always_inline)) void updateDrivingEvents();
    unsigned char unknown4[4];
    Vehicle* vehicle;
    CControlManager* controlManager;
    bool unknown16;
    bool unknown17;
    int unknown20;
    float unknown24[6];
};

#endif
