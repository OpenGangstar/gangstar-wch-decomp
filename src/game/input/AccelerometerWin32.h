#ifndef WCH_INPUT_ACCELEROMETERWIN32_H
#define WCH_INPUT_ACCELEROMETERWIN32_H
#include "AccelerometerBase.h"
#include "TouchScreenMouseEvent.h"

class AccelerometerWin32 : public AccelerometerBase, public irr::IEventReceiver {
public:
    AccelerometerWin32();
    virtual ~AccelerometerWin32();
    virtual bool OnEvent(const irr::SEvent& event);
    void setWide(bool value);

private:
    bool wide;
};

#endif
