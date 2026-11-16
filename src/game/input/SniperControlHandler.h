#ifndef WCH_INPUT_SNIPERCONTROLHANDLER_H
#define WCH_INPUT_SNIPERCONTROLHANDLER_H

#include "IControlHandler.h"

// Recovered virtual interface. The member layout is still incomplete.
class SniperControlHandler : public IControlHandler {
public:
    void init();
    virtual ~SniperControlHandler();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void activate();
    virtual void deactivate() __attribute__((noinline));
    virtual void releaseKeyboardKeys();

private:
    unsigned char unknown4[8];
    int unknown12;
};

#endif
