#ifndef WCH_INPUT_TOUCHSCREENWIN32_H
#define WCH_INPUT_TOUCHSCREENWIN32_H
#include "TouchScreenBase.h"
#include "TouchScreenMouseEvent.h"

class TouchScreenWin32 : public TouchScreenBase, public irr::IEventReceiver {
public:
    TouchScreenWin32();
    virtual ~TouchScreenWin32();
    virtual bool OnEvent(const irr::SEvent& event);
    virtual short getLeftBound() const __attribute__((used)) { return 0; }
    virtual short getRightBound() const __attribute__((used)) { return 0; }
    virtual short getTopBound() const __attribute__((used)) { return 0; }
    virtual short getBottomBound() const __attribute__((used)) { return 0; }
    virtual long getTouchIDInRegion(const irr::core::rect<float>& region) const;
    virtual bool isRegionPressed(const irr::core::rect<float>& region) const;

    void touchCancelled(float x, float y, int externalId);
    void touchEnded(float x, float y, int externalId);
    void touchMoved(float x, float y, int externalId);
    void touchBegan(float x, float y, int externalId);
};

#endif
