#ifndef WCH_HUD_SPY_GAUGE_H
#define WCH_HUD_SPY_GAUGE_H

#include "Gauge.h"

class SpyGauge : public Gauge {
public:
    SpyGauge(ASprite*, int, int, int, int, int);
    virtual ~SpyGauge();
    virtual void update(double);
    virtual void draw2d() const;
    void useDriveWellBG();
    void useDriveBadBG();
    void useSpyBG();

private:
    int driveWellFrame;
    int driveBadFrame;
    int spyFrame;
};

#endif
