#ifndef WCH_INPUT_ANALOG_STICK_H
#define WCH_INPUT_ANALOG_STICK_H

#include "../hud/HudElement.h"

class AnalogStick : public HudElement {
public:
    enum Mode { Mode0, Mode1, Mode2, ModeForceWidth = 0x7fffffff };

    AnalogStick(ASprite*, int, int);
    virtual ~AnalogStick();
    void switchMode(Mode value);
    virtual void reset();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    virtual void processTouch(long id);
    virtual void processTouchRelease();

private:
    unsigned char unknown56[4];
    int stickRadius;
    float displacement;
    bool releasedHorizontal, releasedVertical;
    unsigned char unknown70[2];
    float displacementX;
    float displacementY;
    float magnitude;
    float drawOriginX, drawOriginY, drawPositionX, drawPositionY;
    Mode mode;
    int stickFrame;
};

#endif
