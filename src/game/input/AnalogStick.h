#ifndef WCH_INPUT_ANALOG_STICK_H
#define WCH_INPUT_ANALOG_STICK_H

#include "../hud/HudElement.h"

class AnalogStick : public HudElement {
public:
    enum Mode { Mode0, Mode1, Mode2, ModeForceWidth = 0x7fffffff };

    virtual ~AnalogStick();
    void switchMode(Mode value);
    virtual void reset();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    virtual void processTouch(long id);
    virtual void processTouchRelease();

private:
    unsigned char unknown56[8];
    float displacement;
    unsigned char unknown68[4];
    float displacementX;
    float displacementY;
    float magnitude;
    unsigned char unknown84[16];
    Mode mode;
    int stickFrame;
};

#endif
