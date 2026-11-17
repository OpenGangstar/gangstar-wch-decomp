#ifndef WCH_UI_VIRTUAL_BUTTON_EVENT_H
#define WCH_UI_VIRTUAL_BUTTON_EVENT_H

#include "../core/GameEvents.h"
#include "VirtualButton.h"
class EvVirtualButton : public IEvent {
public:
    enum Action { Pressed, Held, Released, Canceled, ForceWidth = 0x7fffffff };

    EvVirtualButton(Action action, EvVButton::ButtonType::Type type)
        : action(action), buttonType(type)
    {
        eventID = 13;
    }

    virtual ~EvVirtualButton() {}

    Action getAction() const { return action; }
    EvVButton::ButtonType::Type getButtonType() const { return buttonType; }
private:
    Action action;
    EvVButton::ButtonType::Type buttonType;
};

#endif
