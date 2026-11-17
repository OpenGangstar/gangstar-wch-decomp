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
    void handleStickMove(EvStickMove*);
    void handleStickReleased(bool);
    void handleExitSightReleased();
    void handleAttackReleased();
    void handleAttackHeld();

private:
    inline __attribute__((always_inline)) void resetInput();
    unsigned char unknown4[4];
    CControlManager* controlManager;
    int unknown12;
};

#endif
