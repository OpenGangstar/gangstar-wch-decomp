#include "../../src/game/ui/SlideControl.h"
#include "../../src/game/app/Application.h"
#include "../../src/game/input/TouchScreenBase.h"
#include "../../src/game/core/EventManager.h"
#include "../../src/game/core/GameEventMethods.h"
#include "../../src/game/input/DirectionalStickEvents.h"
#include "../../src/game/core/NativeStdio.h"
static const char invalidSlideTouch[] __attribute__((section(".rodata.slide_invalid_touch"))) =
    "SlideControl::processTouch: received invalid touchID: %i\n";

void SlideControl::processTouch(long touch)
{
    if (!(flags & 1))
        return;

    TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
    const Point2D<short>* current = screen->getTouchPoint(touch);
    if (!current) {
        printf(invalidSlideTouch, static_cast<int>(touch));
        return;
    }

    const Point2D<short>* first = screen->getFirstTouchPoint(touch);
    int x, y;
    if (horizontal) {
        x = current->x - first->x;
        y = current->y - first->y;
    } else {
        x = static_cast<int>(current->x - knobCenterX);
        y = static_cast<int>(current->y - knobCenterY);
    }

    const int mode = this->mode;
    if (mode == Horizontal)
        y = 0;
    else if (mode == Vertical)
        x = 0;
    if (!x && !y)
        return;

    float xOffset, yOffset;
    if (mode == Horizontal) {
        if (x >= 0) {
            const int limit = maximumX;
            rightward = true;
            if (limit < x) {
                unknown76 = 1.0f;
                xOffset = static_cast<float>(limit);
                yOffset = static_cast<float>(y);
            } else {
                const float offset = static_cast<float>(x);
                const float extent = static_cast<float>(maximumX);
                const float fraction = offset / extent;
                unknown76 = fraction > 0.0f ? fraction : -offset / extent;
                xOffset = offset;
                yOffset = static_cast<float>(y);
            }
        } else {
            const int limit = minimumX;
            rightward = false;
            if (-x > limit) {
                unknown76 = 1.0f;
                xOffset = static_cast<float>(-limit);
                yOffset = static_cast<float>(y);
            } else {
                xOffset = static_cast<float>(x);
                const float extent = static_cast<float>(limit);
                const float fraction = xOffset / extent;
                unknown76 = fraction > 0.0f ? fraction : -xOffset / extent;
                yOffset = static_cast<float>(y);
            }
        }
    } else if (y >= 0) {
        const int limit = maximumY;
        upward = false;
        if (y > limit) {
            unknown76 = 1.0f;
            xOffset = static_cast<float>(x);
            yOffset = static_cast<float>(limit);
        } else {
            yOffset = static_cast<float>(y);
            unknown76 = yOffset / static_cast<float>(limit);
            xOffset = static_cast<float>(x);
        }
    } else {
        upward = true;
        const int limit = minimumY;
        if (-y > limit) {
            unknown76 = 1.0f;
            xOffset = static_cast<float>(x);
            yOffset = static_cast<float>(-limit);
        } else {
            unknown76 = static_cast<float>(-y) / static_cast<float>(limit);
            xOffset = static_cast<float>(x);
            yOffset = static_cast<float>(y);
        }
    }

    if (this->mode == Horizontal)
        Application::GetInstance()->GetEventManager()->raise(EvLeftRightStickMove(rightward, unknown76));
    else
        Application::GetInstance()->GetEventManager()->raise(EvUpDownStickMove(upward, unknown76));

    unknown80 = xOffset;
    unknown84 = yOffset;
    flags |= 2;
}
