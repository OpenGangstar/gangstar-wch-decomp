#ifndef WCH_UI_TOGGLE_BUTTON_H
#define WCH_UI_TOGGLE_BUTTON_H

#include "VirtualButton.h"

class ToggleButton : public VirtualButton {
private:
    friend class CControlManager;
    unsigned char unknown60[4];
    bool toggled;
};

#endif
