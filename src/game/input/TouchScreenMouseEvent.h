#ifndef WCH_INPUT_TOUCH_SCREEN_MOUSE_EVENT_H
#define WCH_INPUT_TOUCH_SCREEN_MOUSE_EVENT_H

namespace irr {

// Mouse-event prefix used by the retail receiver.
struct SEvent {
    enum EventType { MouseInputEvent = 1 };
    enum MouseEvent { LeftPressed = 0, LeftReleased = 3, MouseMoved = 6 };

    int type;
    unsigned char unknown4[4];
    struct {
        int x;
        int y;
        float wheel;
        int event;
    } mouse;
};

class IEventReceiver {
public:
    virtual ~IEventReceiver() {}
    virtual bool OnEvent(const SEvent& event) = 0;
};

} // namespace irr

#endif
