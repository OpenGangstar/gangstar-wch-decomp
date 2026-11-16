#ifndef WCH_UI_MESSAGE_H
#define WCH_UI_MESSAGE_H

#include "../hud/HudElement.h"

class AnimObject;

// Partial layout recovered from the message timer and animation methods.
class Message : public HudElement {
public:
    bool isDisplayed();
    void setTimer(int duration);
    void setAnim(int animation);

private:
    AnimObject* animationObject;
    unsigned char unknown60[12];
    int timer;
    int animationId;
    unsigned char unknown80[36];
    bool timedDisplay;
    bool untimed;
};

#endif
