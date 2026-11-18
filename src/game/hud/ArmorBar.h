#ifndef WCH_HUD_ARMOR_BAR_H
#define WCH_HUD_ARMOR_BAR_H

#include "Gauge.h"

class ArmorBar : public Gauge {
public:
    ArmorBar(ASprite*, int, int, int);
    virtual ~ArmorBar();
    virtual void update(double);
    virtual void draw2d() const;
    virtual void show();
};

#endif
