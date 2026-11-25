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
    void setAnchor(float x, float y) { unknown32 = x; unknown36 = y; }
    bool positiveDirection;
    float displacement;
    float centerX;
    float centerY;
    unsigned int maximumDisplacement;
    float previousTouchX;
    float previousTouchY;
};

#endif
