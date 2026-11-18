#ifndef WCH_HUD_CAR_BAR_H
#define WCH_HUD_CAR_BAR_H

#include "Gauge.h"

class CarBar : public Gauge {
public:
    CarBar(ASprite*, int, int, int);
    virtual ~CarBar();
    virtual void update(double);
    virtual void draw2d() const;
};

#endif
