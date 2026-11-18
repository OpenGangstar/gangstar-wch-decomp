#ifndef WCH_HUD_HEALTH_BAR_H
#define WCH_HUD_HEALTH_BAR_H

#include "Gauge.h"

class HealthBar : public Gauge {
public:
    HealthBar(ASprite*, int, int, int);
    virtual ~HealthBar();
    virtual void update(double);
    virtual void draw2d() const;
};

#endif
