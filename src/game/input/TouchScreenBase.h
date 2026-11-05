#ifndef WCH_INPUT_TOUCH_SCREEN_BASE_H
#define WCH_INPUT_TOUCH_SCREEN_BASE_H

namespace irr { namespace core { template<class T> class rect; } }
template<class T> struct Rct;
template<class T> struct Point2D;
struct TouchPoint;
struct TouchIDList;

// Virtual call interface and recovered touch-slot layout.
class TouchScreenBase {
public:
    virtual ~TouchScreenBase();
    virtual void update(double elapsed);
    virtual short getLeftBound() const = 0;
    virtual short getRightBound() const = 0;
    virtual short getTopBound() const = 0;
    virtual short getBottomBound() const = 0;
    virtual Rct<short> getDimension() const;
    virtual void getDimension(Rct<short>& result) const;
    virtual void touchBegan(const Point2D<short>& point, long id);
    virtual void touchMoved(const Point2D<short>& point, long id);
    virtual void touchEnded(const Point2D<short>& point, long id);
    virtual void touchCancelled(const Point2D<short>& point, long id);
    virtual bool isRegionPressed(const irr::core::rect<float>& region) const;
    virtual long getTouchIDInitiatedInRegion(const irr::core::rect<float>& region) const;
    virtual long getTouchIDInRegion(const irr::core::rect<float>& region) const;
    virtual TouchPoint* getTouchPoint(long id);
    virtual TouchPoint* getFirstTouchPoint(long id);
    virtual int getNumPoints(long id) const;
    virtual Point2D<short> getTouchDisplacement(long id) const;
    virtual int getSwipeDirection(long id) const;
    virtual TouchIDList getTouchIDList() const;

    void clear();
    void clearTouchPoint(long id);
    void enable();
    void disable();
    bool isEnabled() const;

private:
    struct _TouchPointInfo {
        unsigned char first[8];
        unsigned char current[8];
        unsigned char unknown16[16];
        bool hasPoints;
        int numPoints;
        int swipeDirection;
        bool active;
        unsigned char unknown45[11];
    };

    unsigned char unknown4[4];
    _TouchPointInfo points[8];
    unsigned char unknown456[8];
    bool enabled;
};

#endif
