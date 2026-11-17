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
    unsigned char unknown56[16];
    int mode;
    float unknown76;
    float unknown80;
    float unknown84;
    unsigned char unknown88[8];
    bool releasedUp, releasedRight;
    unsigned char unknown98[2];
    int handleFrame;
};

#endif
