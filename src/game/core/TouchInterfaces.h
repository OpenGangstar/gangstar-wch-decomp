#ifndef WCH_CORE_TOUCH_INTERFACES_H
#define WCH_CORE_TOUCH_INTERFACES_H

class ITouchable {
public:
    virtual void processTouch(long) = 0;
    virtual void processTouchRelease() = 0;
    virtual bool isUsed() const = 0;
};

#endif
