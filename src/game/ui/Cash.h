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
    void AlignRight();
    void SetPosition(int x, int y);

private:
    void align(bool left) __attribute__((always_inline));

    int cash;
    unsigned char unknown60[64];
    int positionX;
    int positionY;
    bool alignedLeft;
};

#endif
