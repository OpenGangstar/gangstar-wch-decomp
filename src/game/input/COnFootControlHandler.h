#ifndef WCH_INPUT_CONFOOTCONTROLHANDLER_H
#define WCH_INPUT_CONFOOTCONTROLHANDLER_H

#include "IControlHandler.h"

class CControlManager;

// Recovered virtual interface. The member layout is still incomplete.
class EvStickMove;

class COnFootControlHandler : public IControlHandler {
public:
    explicit COnFootControlHandler(CControlManager* manager);
    void init();
    virtual ~COnFootControlHandler();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void activate();
    virtual void deactivate() __attribute__((noinline));
    virtual void releaseKeyboardKeys();

private:
    void onKeyboardEvent(const IEvent* event);
    void handleEnterCarPressed() __attribute__((noinline));
    void handleEnterShopPressed() __attribute__((noinline));
    void handleLockPressed() __attribute__((noinline));
    void handleStickReleased(bool fast) __attribute__((noinline));
    void handleStickMove(EvStickMove* event) __attribute__((noinline));
    void handleAttackReleased() __attribute__((noinline));
    void handleAttackHeld() __attribute__((noinline));
    void handleAttackPressed() __attribute__((noinline));
    void handleWeaponSwitched() __attribute__((noinline));
    inline __attribute__((always_inline)) void resetInput();
    friend class CControlManager;
    unsigned char unknown4[4];
    CControlManager* controlManager;
    bool unknown12;
    bool unknown13;
    int unknown16;
};

#endif
