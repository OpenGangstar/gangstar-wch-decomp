// Unmatched parent remains pending; verifies genuine compiler-generated ARM thunk.
#include "../../src/game/vehicles/Wheel.cpp"
#include "../../src/game/core/NativeStdio.h"
extern "C" void _ZN11EvWheelTurnD1Ev(void*) __attribute__((weak));
extern "C" const char wheelInvalidTouchFormat[] __attribute__((visibility("hidden")));

void Wheel::processTouch(long id)
{
    if (!(flags & 1u))
        return;
    Application* application = Application::GetInstance();
    TouchScreenBase* screen = application->GetTouchScreen();
    Point2D<short>* touch = screen->getTouchPoint(id);
    if (!touch) {
        printf(wheelInvalidTouchFormat, id);
        return;
    }
    const Point2D<short> movement = screen->getTouchDisplacement(id);
    if (!(flags & 2u)) {
        if (__builtin_abs(movement.x) > 1 && __builtin_abs(movement.y) > 1)
            return;
        if (!*reinterpret_cast<const unsigned int*>(&movement.x))
            return;
    }

    Point2D<short>* firstTouch = screen->getFirstTouchPoint(id);
    if (!firstTouch)
        return;
    int distance = touch->x - firstTouch->x;
    if (!distance)
        return;
    if (distance > 0) {
        positiveDirection = true;
    } else {
        positiveDirection = false;
        distance = -distance;
    }
    displacement = static_cast<float>(distance) / static_cast<float>(maximumDisplacement);
    if (displacement > 1.0f)
        displacement = 1.0f;

    EventManager* events = application->GetEventManager();
    unsigned int storage[sizeof(EvWheelTurn) / sizeof(unsigned int)];
    EvWheelTurn* event = new (storage) EvWheelTurn(positiveDirection, displacement);
    events->raise(*event);
    _ZN11EvWheelTurnD1Ev(event);
    flags |= 2u;
}

