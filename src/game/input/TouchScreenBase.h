#ifndef WCH_INPUT_TOUCH_SCREEN_BASE_H
#define WCH_INPUT_TOUCH_SCREEN_BASE_H

#include "../core/FrameInterfaces.h"
#include "../core/Point2D.h"

namespace irr { namespace core { template<class T> class rect; } }
template<class T> struct Rct;
struct TouchIDList;

// Virtual call interface and recovered touch-slot layout.
class TouchScreenBase : public IUpdatable {
public:
    TouchScreenBase();
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
    virtual Point2D<short>* getTouchPoint(long id);
    virtual Point2D<short>* getFirstTouchPoint(long id);
    virtual int getNumPoints(long id) const;
    virtual Point2D<short> getTouchDisplacement(long id) const;
    virtual int getSwipeDirection(long id) const;
    virtual TouchIDList getTouchIDList() const;

    static void ConvertCoord(Point2D<short>& point);
    void clear();
    void clearTouchPoint(long id);
    void enable();
    void disable();
    bool isEnabled() const;

protected:
    long getID(long externalId);

private:
    void _trace(const char* message) const;

    struct _TouchPointInfo {
        _TouchPointInfo() : hasPoints(false), active(false) {}
        ~_TouchPointInfo() __attribute__((used));

        Point2D<short> first;
        Point2D<short> current;
        Point2D<short> previous;
        double lastTouchTime;
        bool hasPoints;
        int numPoints;
        int swipeDirection;
        bool active;
        long externalId;
        unsigned char unknown52[4];
    };

    unsigned char unknown4[4];
    _TouchPointInfo points[8];
    double currentTime;
    bool enabled;
    int slotCount;
};

#endif
