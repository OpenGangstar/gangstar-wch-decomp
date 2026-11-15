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
    template<bool (EventManager::*operation)(int, IEventReceiver*)>
    inline __attribute__((always_inline)) void updateOnFootEvents()
    {
        EventManager* events = Application::GetInstance()->GetEventManager();
        (events->*operation)(7, this);
        (events->*operation)(8, this);
        (events->*operation)(13, this);
        (events->*operation)(0, this);
    }
};

#endif
