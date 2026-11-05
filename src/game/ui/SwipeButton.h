#ifndef WCH_UI_SWIPE_BUTTON_H
#define WCH_UI_SWIPE_BUTTON_H

#include "../hud/HudElement.h"

class SwipeButton : public HudElement {
public:
    SwipeButton(ASprite* sprite, int frame);
    virtual inline ~SwipeButton();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    virtual void processTouch(long touch);
    virtual void processTouchRelease();

protected:
    int swipeDirection;
};

inline SwipeButton::~SwipeButton() {}

#endif
