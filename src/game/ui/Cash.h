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
    int GetCash();
    void AlignLeft();
    void SetPosition(int x, int y);

private:
    int cash;
    unsigned char unknown60[64];
    int positionX;
    int positionY;
    unsigned char unknown132[4];
};

#endif
