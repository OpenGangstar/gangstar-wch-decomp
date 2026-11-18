#ifndef WCH_VEHICLES_WHEEL_H
#define WCH_VEHICLES_WHEEL_H

#include "../hud/HudElement.h"

class Wheel : public HudElement {
public:
    Wheel(ASprite*, int);
    virtual ~Wheel();
    virtual void update(double);
    virtual void setHand(bool);
    virtual void processTouch(long);
    virtual void processTouchRelease();
    virtual void draw2d() const;
private:
    bool positiveDirection;
    float displacement;
    // Constructor allocation proves an 84-byte extent; remaining tail is opaque.
    unsigned char unknown64[20];
};

#endif
