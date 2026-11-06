#ifndef WCH_UI_CASH_H
#define WCH_UI_CASH_H

#include "../hud/HudElement.h"

class Cash : public HudElement {
public:
    Cash(ASprite*, int, int, int, int, int);
    virtual ~Cash();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    void SetCash(int amount);
    void AlignLeft();
    void SetPosition(int x, int y);

private:
    unsigned char unknown56[80];
};

#endif
