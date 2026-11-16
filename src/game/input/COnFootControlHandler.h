#ifndef WCH_INPUT_CONFOOTCONTROLHANDLER_H
#define WCH_INPUT_CONFOOTCONTROLHANDLER_H

#include "IControlHandler.h"

class CControlManager;

// Recovered virtual interface. The member layout is still incomplete.
class COnFootControlHandler : public IControlHandler {
public:
    void init();
    virtual ~COnFootControlHandler();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void activate();
    virtual void deactivate() __attribute__((noinline));
    virtual void releaseKeyboardKeys();

private:
    friend class CControlManager;
    unsigned char unknown4[4];
    CControlManager* controlManager;
    bool unknown12;
    bool unknown13;
    int unknown16;
};

#endif
