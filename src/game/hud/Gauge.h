#ifndef WCH_HUD_GAUGE_H
#define WCH_HUD_GAUGE_H

#include "HudElement.h"

class Gauge : public HudElement {
public:
    Gauge(ASprite* sprite, int frame, int fillFrame, int overlayFrame);
    virtual ~Gauge();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    void setPercentage(float percentage);

protected:
    int fillWidth;
    int fillLeft;
    int fillRight;
    unsigned char unknown68[4];
    double blinkElapsed;
    bool hideFill;
    int fillFrame;
    int overlayFrame;
};

#endif
