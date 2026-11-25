#ifndef WCH_UI_TOGGLE_BUTTON_H
#define WCH_UI_TOGGLE_BUTTON_H

#include "VirtualButton.h"

class ToggleButton : public VirtualButton {
public:
    ToggleButton(ASprite* sprite, int frame, int inactiveFrame);
    virtual ~ToggleButton() {}
    virtual void processTouch(long) __attribute__((used)) { flags |= 2; }
    virtual void processTouchRelease();
    virtual void draw2d() const;

private:
    friend class CControlManager;
    friend class CHudManager;
    int inactiveFrame;
    bool toggled;
};

#endif
