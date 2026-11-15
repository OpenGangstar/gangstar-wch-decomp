#ifndef WCH_INPUT_ICONTROLHANDLER_H
#define WCH_INPUT_ICONTROLHANDLER_H

#include "../core/EventManager.h"
#include "../app/Application.h"

class IControlHandler : public IEventReceiver {
public:
    virtual ~IControlHandler() __attribute__((used, noinline)) {}
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void releaseKeyboardKeys() = 0;

protected:
    inline __attribute__((always_inline)) void detachOnFootEvents()
    {
        EventManager* events = Application::GetInstance()->GetEventManager();
        events->detach(7, this);
        events->detach(8, this);
        events->detach(13, this);
        events->detach(0, this);
    }
};

#endif
