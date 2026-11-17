#ifndef WCH_INPUT_TOUCH_SCREEN_IPHONE_H
#define WCH_INPUT_TOUCH_SCREEN_IPHONE_H

#include "TouchScreenBase.h"
#include "TouchScreenMouseEvent.h"

class TouchScreenIPhone : public TouchScreenBase, public irr::IEventReceiver {
public:
    TouchScreenIPhone(float left, float top, float right, float bottom);
    virtual ~TouchScreenIPhone();
    virtual bool OnEvent(const irr::SEvent& event);
    virtual short getLeftBound() const;
    virtual short getRightBound() const;
    virtual short getTopBound() const;
    virtual short getBottomBound() const;
    virtual long getTouchIDInRegion(const irr::core::rect<float>& region) const;
    virtual bool isRegionPressed(const irr::core::rect<float>& region) const;

private:
    short left, right, top, bottom;
};

#endif
