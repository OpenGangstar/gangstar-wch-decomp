#ifndef WCH_UI_SLIDE_CONTROL_H
#define WCH_UI_SLIDE_CONTROL_H

#include "../hud/HudElement.h"

class SlideControl : public HudElement {
public:
    enum SlideControlMode { Horizontal, Vertical };
    SlideControl(ASprite*, int, int, SlideControlMode);
    virtual ~SlideControl();
    virtual void update(double elapsed);
    virtual void reset();
    virtual void processTouch(long touch);
    virtual void processTouchRelease();
    virtual void draw2d() const;

private:
    int minimumX, maximumX, minimumY, maximumY;
    int mode;
    float unknown76;
    float unknown80;
    float unknown84;
    float knobCenterX, knobCenterY;
    union { bool releasedUp; bool upward; };
    union { bool releasedRight; bool rightward; };
    bool horizontal;
    unsigned char unknown99;
    int handleFrame;
};

#endif
