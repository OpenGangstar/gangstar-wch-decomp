#ifndef WCH_HUD_HUD_DRAW_COLOR_H
#define WCH_HUD_HUD_DRAW_COLOR_H

#include "../core/Color.h"

static inline void setHudColor(irr::video::SColor& color, unsigned int alpha, unsigned int red)
{
    color.b = 255;
    color.g = 255;
    color.a = alpha;
    color.r = red;
}

#endif
