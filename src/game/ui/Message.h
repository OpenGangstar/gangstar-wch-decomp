#ifndef WCH_UI_MESSAGE_H
#define WCH_UI_MESSAGE_H

#include "../hud/HudElement.h"

class AnimObject;

// Partial layout recovered from the message timer and animation methods.
class Message : public HudElement {
public:
    virtual ~Message();
    virtual void draw2d() const;
    bool isDisplayed();
    void clearMessage(bool clearAnimation);
    void setTimer(int duration);
    void setAnim(int animation);

private:
    AnimObject* animationObject;
    unsigned char unknown60[4];
    int defaultAnimation;
    unsigned char unknown68[4];
    int timer;
    int animationId;
    int unknown80;
    unsigned char unknown84[32];
    bool timedDisplay;
    bool untimed;
};

#endif
