#ifndef WCH_INPUT_SNIPERCONTROLHANDLER_H
#define WCH_INPUT_SNIPERCONTROLHANDLER_H

#include "IControlHandler.h"

// Recovered virtual interface. The member layout is still incomplete.
class CControlManager;
class EvStickMove;

class SniperControlHandler : public IControlHandler {
public:
    explicit SniperControlHandler(CControlManager* manager);
    void init();
    virtual ~SniperControlHandler();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void activate();
    virtual void deactivate() __attribute__((noinline));
    virtual void releaseKeyboardKeys();
    void handleStickMove(EvStickMove*) __attribute__((noinline));
    void handleStickReleased(bool) __attribute__((noinline));
    void handleExitSightReleased() __attribute__((noinline));
    void handleAttackReleased() __attribute__((noinline));
    void handleAttackHeld() __attribute__((noinline));
    void handleAttackPressed() __attribute__((noinline));

private:
    void onKeyboardEvent(const IEvent* event);
    inline __attribute__((always_inline)) void resetInput();
    unsigned char unknown4[4];
    CControlManager* controlManager;
    int unknown12;
};

#endif
