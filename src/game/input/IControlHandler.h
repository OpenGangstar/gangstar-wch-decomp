#ifndef WCH_INPUT_ICONTROLHANDLER_H
#define WCH_INPUT_ICONTROLHANDLER_H

#include "../core/GameEvents.h"

class IControlHandler : public IEventReceiver {
public:
    virtual ~IControlHandler() __attribute__((used)) {}
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void releaseKeyboardKeys() = 0;
};

#endif
