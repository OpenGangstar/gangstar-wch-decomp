#ifndef WCH_UI_VIRTUAL_BUTTON_H
#define WCH_UI_VIRTUAL_BUTTON_H

#include "../hud/HudElement.h"

struct EvVButton {
    struct ButtonType {
        enum Type { ForceWidth = 0x7fffffff };
    };
};

class VirtualButton : public HudElement {
public:
    VirtualButton(ASprite*, int, EvVButton::ButtonType::Type, bool);
    virtual ~VirtualButton() {}
    virtual void update(double);
    virtual void processTouch(long);
    virtual void processTouchRelease();

private:
    EvVButton::ButtonType::Type buttonType;
};

#endif
