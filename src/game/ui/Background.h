#ifndef WCH_UI_BACKGROUND_H
#define WCH_UI_BACKGROUND_H

#include "../hud/HudElement.h"

class Background : public HudElement {
public:
    Background(ASprite* image, int frame);
    virtual ~Background();
    virtual void update(double elapsed);
    virtual void draw2d() const;

private:
    bool blackoutActive;
    int blackoutElapsed;
};

#endif
