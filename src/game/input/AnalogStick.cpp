/*
 * AnalogStick
 *
 * Original file: AnalogStick.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AnalogStick.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/GameEventMethods.h"
#include "../core/Point2D.h"
#include "../app/Application.h"
#include "../core/Rect.h"
#include "../core/ASprite.h"
#include "../core/Color.h"
#include "../hud/HudElement.h"
#include "TouchScreenBase.h"
#include "AnalogStick.h"
#include "StickReleaseEvents.h"
#include "StickMoveEvent.h"
#include "../hud/HudDrawColor.h"

inline AnalogStick::~AnalogStick()
{
}

void AnalogStick::switchMode(Mode value)
{
    mode = value;
}

void AnalogStick::reset()
{
    flags &= ~2u;
    displacement = 0.0f;
    displacementX = 0.0f;
    displacementY = 0.0f;
    magnitude = 0.0f;
}

void AnalogStick::update(double)
{
    if (flags & 1u) {
        TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
        const irr::core::rect<float>& region =
            reinterpret_cast<const irr::core::rect<float>&>(touchRegion);
        const long id = screen->getTouchIDInitiatedInRegion(region);
        if (id != -1)
            processTouch(id);
        else
            processTouchRelease();
    }
}

void AnalogStick::draw2d() const
{
    if (!(flags & 1)) return;
    irr::video::SColor colors[4];
    if ((flags & 16) && (unknown52 & 256)) {
        setHudColor(colors[0],191,51);
        setHudColor(colors[1],191,51);
        setHudColor(colors[2],191,51);
        setHudColor(colors[3],191,51);
        ASprite::s_global_color = colors;
    } else if (!(flags & 2)) {
        setHudColor(colors[0],128,255);
        setHudColor(colors[1],128,255);
        setHudColor(colors[2],128,255);
        setHudColor(colors[3],128,255);
        ASprite::s_global_color = colors;
    }
    sprite->PaintFrame(frame,0,0,0);
    sprite->PaintFrame(stickFrame,static_cast<int>(displacementY),static_cast<int>(magnitude),0);
    ASprite::s_global_color = 0;
}

// Event declarations for the recovered destructor and vtable layout.
inline __attribute__((used)) EvStickMove::~EvStickMove() {}

#include "DirectionalStickEvents.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

template Point2D<short>::~Point2D();

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11AnalogStickC2EP7ASpriteii() __attribute__((used));
static void _GLOBAL__I__ZN11AnalogStickC2EP7ASpriteii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" void _ZN11EvStickMoveD1Ev(void*) __attribute__((weak));
extern "C" void _ZN20EvLeftRightStickMoveD1Ev(void*) __attribute__((weak));
extern "C" void _ZN17EvUpDownStickMoveD1Ev(void*) __attribute__((weak));
extern "C" float sqrtf(float);
extern "C" float atan2f(float, float);
extern "C" int printf(const char* format, ...);

void AnalogStick::processTouch(long id)
{
    if (!(flags & 1u))
        return;

    TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
    const Point2D<short>* current = screen->getTouchPoint(id);
    if (!current) {
        printf("AnalogStick::processTouch: received invalid touchID: %i\n", static_cast<int>(id));
        return;
    }

    Point2D<short> delta = screen->getTouchDisplacement(id);
    if (!(flags & 2u)) {
        if ((delta.x < 0 ? -delta.x : delta.x) > 1 && (delta.y < 0 ? -delta.y : delta.y) > 1)
            return;
        if (delta.x == 0 && delta.y == 0)
            return;
    }

    const Point2D<short>* first = screen->getFirstTouchPoint(id);
    if (!first)
        first = current;
    const float positionY = static_cast<float>(current->y - first->x) + drawOriginY;
    drawPositionX = drawOriginX + static_cast<float>(current->x - first->x);
    drawPositionY = positionY;

    const int currentX = current->x;
    const int currentY = current->y;
    const int firstX = first->x;
    const int firstY = first->y;
    int dy;
    int dx = currentX - firstX;
    // Horizontal-arm locals, declared ahead of the other arms (their code is
    // placed after them below).
    int radiusX;
    float signX;
    float offsetH;
    float extentH;
    float fractionH;
    if (mode == Mode0)
        goto horizontalMode;
    if (mode == Mode1) {
        dx = 0;
    }
    dy = firstY - currentY;
    releasedHorizontal = dx > 0;
    releasedVertical = dy > 0;

    // No-code hint: the zero test reads dy through an aggregate copy so the
    // early range pass does not substitute zero into the horizontal join.
    if (({ struct P { int k; } u = { dy }; P t = u; t.k == 0; }))
        goto horizontalZeroTest;
    // No-code hint: the int-typed repeat of the zero test is false whenever
    // it is evaluated (predicted 21%, opcode positive) and is removed by DOM;
    // it only raises the horizontal arm's estimated frequency (block order).
    if (({ const bool moved = !(dy == 0); struct L { int k; } u = { moved }; L t = u; t.k <= 0; }))
        goto horizontalZeroTest;

    // No-code hint: the repeated test is true whenever it is evaluated
    // (predicted 71%, opcode nonequal) and is removed by DOM; it lowers the
    // vertical arm's estimated frequency (retail block order).
    if (dx != 0)
        goto bothAxesEntry;
    if (({ struct Z { unsigned k; } u = { dx == 0 }; Z t = u; t.k != 0u; })) {
    verticalArm:
        // No-code hint: this (unused) user label keeps the arm out of the
        // folded test's block, so the negation block gets the arm's own
        // frequency (it is then laid out after the negative-sign block).
        // Branch-profile hint (emits no Thumb code): balances the call
        // heuristic so the vertical and both-axes arms are equally likely.
        __builtin_prefetch(this);
        const int length = dy < 0 ? -dy : dy;
        const int radius = stickRadius;
        // No-code hint: repeated clamp test, true whenever evaluated
        // (predicted 29%), removed by DOM; lowers the clamp arm's frequency.
        if (length > radius && ({ struct Z { unsigned k; } u = { length > radius }; Z t = u; t.k == 1u; })) {
            const float sign = releasedVertical ? 1.0f : -1.0f;
            dy = static_cast<int>(sign * static_cast<float>(radius));
            displacementX = 1.0f;
        } else {
            const float offset = static_cast<float>(dy);
            const float extent = static_cast<float>(radius);
            const float fraction = offset / extent;
            displacementX = fraction > 0.0f ? fraction : -offset / extent;
        }
        displacement = dy > 0 ? 0.0f : 3.1415927f;
    } else {
        if (0) {
        bothAxesEntry:
            // No-code hint: an address-taken label keeps the nonzero edge
            // in its own block, so the both-axes arm keeps its position.
            ({ entry: void* const label = &&entry; (void)label; });
        }
        const float radius = static_cast<float>(stickRadius);
        const float offsetY = static_cast<float>(dy);
        // Reassigning squares blocks TER so the y term is computed first.
        float squares = offsetY * offsetY;
        const float offsetX = static_cast<float>(dx);
        const float squareX = offsetX * offsetX;
        squares += squareX;
        const float length = sqrtf(squares);
        if (radius < length) {
            const float scale = radius / length;
            displacementX = 1.0f;
            dy = static_cast<int>(offsetY * scale);
            dx = static_cast<int>(offsetX * scale);
        } else {
            displacementX = length / radius;
        }
        displacement = -atan2f(static_cast<float>(dx), static_cast<float>(dy));
    }
    goto events;

horizontalZeroTest:
    if (dx == 0) {
        return;
    }
    goto horizontalTest;
horizontalClamp:
    signX = releasedHorizontal ? 1.0f : -1.0f;
    dx = static_cast<int>(signX * static_cast<float>(radiusX));
    displacementX = 1.0f;
    goto horizontalTail;
horizontalInside:
    offsetH = static_cast<float>(dx);
    extentH = static_cast<float>(radiusX);
    fractionH = offsetH / extentH;
    displacementX = fractionH > 0.0f ? fractionH : -offsetH / extentH;
horizontalTail:
    displacement = dx > 0 ? -1.5707964f : 1.5707964f;
    goto events;
events:
    unsigned int horizontalStorage[sizeof(EvLeftRightStickMove) / sizeof(unsigned int)];
    unsigned int verticalStorage[sizeof(EvUpDownStickMove) / sizeof(unsigned int)];
    unsigned int stickStorage[sizeof(EvStickMove) / sizeof(unsigned int)];
    if (mode == Mode0) {
        EventManager* events = Application::GetInstance()->GetEventManager();
        EvLeftRightStickMove* event = new (horizontalStorage) EvLeftRightStickMove(releasedHorizontal, displacementX);
        events->raise(*event);
        _ZN20EvLeftRightStickMoveD1Ev(event);
    } else {
    if (mode == Mode1) {
        EventManager* events = Application::GetInstance()->GetEventManager();
        EvUpDownStickMove* event = new (verticalStorage) EvUpDownStickMove(releasedVertical, displacementX);
        events->raise(*event);
        _ZN17EvUpDownStickMoveD1Ev(event);
    } else {
        EventManager* events = Application::GetInstance()->GetEventManager();
        EvStickMove* event = new (stickStorage) EvStickMove(displacement, displacementX);
        events->raise(*event);
        _ZN11EvStickMoveD1Ev(event);
    }
    }
    displacementY = static_cast<float>(dx);
    magnitude = static_cast<float>(-dy);
    flags |= 2u;
    return;

    // Mode0 path and the magnitude test, placed after the event code (their
    // position in the insn stream decides the register copies CSE keeps).
horizontalMode:
    releasedHorizontal = dx > 0;
    releasedVertical = false;
    dy = 0;
    goto horizontalZeroTest;
    // The magnitude test comes last in the insn stream, after every other
    // use of dx, so CSE keeps the copy it compares (subs rD, rS, #0).
horizontalTest:
    {
        const int length = dx < 0 ? -dx : dx;
        radiusX = stickRadius;
        if (length > radiusX)
            goto horizontalClamp;
        goto horizontalInside;
    }
}

extern "C" void _ZN15EvStickReleasedD1Ev(void*) __attribute__((weak));
extern "C" void _ZN24EvLeftRightStickReleasedD1Ev(void*) __attribute__((weak));
extern "C" void _ZN21EvUpDownStickReleasedD1Ev(void*) __attribute__((weak));

void AnalogStick::processTouchRelease()
{
    if (!(flags & 1u))
        return;

    unsigned int horizontalStorage[sizeof(EvLeftRightStickReleased) / sizeof(unsigned int)];
    unsigned int verticalStorage[sizeof(EvUpDownStickReleased) / sizeof(unsigned int)];
    unsigned int stickStorage[sizeof(EvStickReleased) / sizeof(unsigned int)];
    if (flags & 2u) {
        if (mode == Mode0) {
            EventManager* events = Application::GetInstance()->GetEventManager();
            EvLeftRightStickReleased* event = new (horizontalStorage) EvLeftRightStickReleased(releasedHorizontal, displacementX);
            events->raise(*event);
            _ZN24EvLeftRightStickReleasedD1Ev(event);
        } else if (mode == Mode1) {
            EventManager* events = Application::GetInstance()->GetEventManager();
            EvUpDownStickReleased* event = new (verticalStorage) EvUpDownStickReleased(releasedVertical, displacementX);
            events->raise(*event);
            _ZN21EvUpDownStickReleasedD1Ev(event);
        } else {
            EventManager* events = Application::GetInstance()->GetEventManager();
            EvStickReleased* event = new (stickStorage) EvStickReleased(displacement, displacementX);
            events->raise(*event);
            _ZN15EvStickReleasedD1Ev(event);
        }
    }
    displacementY = 0.0f;
    magnitude = 0.0f;
    flags &= ~2u;
}

// Second access paths to the frame-module origin and module width. The
// constructor reads the base origin and width again for the right edge;
// through these views the reads are distinct memory expressions, so tree
// value numbering does not share them with the left edge and the stores
// keep retail order. RTL CSE later merges the duplicate loads.
namespace {
struct FrameModuleOrigin {
    unsigned short module;
    short x;
    short y;
};

struct ModuleExtent {
    unsigned char kind;
    unsigned char unknown1[5];
    short width;
    short height;
};
}

AnalogStick::AnalogStick(ASprite* image, int baseFrame, int handleFrame)
    : HudElement(image, baseFrame, true), displacement(0.0f), releasedHorizontal(false), releasedVertical(false),
      displacementX(0.0f), displacementY(0.0f), magnitude(0.0f), drawOriginX(0.0f), drawOriginY(0.0f),
      drawPositionX(0.0f), drawPositionY(0.0f), mode(Mode2), stickFrame(handleFrame)
{
    const SpriteFrame* base = sprite->GetFrame(frame);
    const SpriteFrameModule* basePart = sprite->GetFModule(base->firstModule);
    const float y = basePart->y;
    const float x = basePart->x;
    unknown32 = x;
    unknown36 = y;
    const SpriteModule* baseModule = sprite->GetModule(basePart->module);
    const float left = basePart->x - 70 + baseModule->width / 2;
    const float top = basePart->y - 70 + baseModule->height / 2;
    const float right = reinterpret_cast<const FrameModuleOrigin*>(basePart)->x - 70
        + reinterpret_cast<const ModuleExtent*>(baseModule)->width / 2 + 140.0f;
    touchRegion.coordinates[1] = top;
    touchRegion.coordinates[0] = left;
    touchRegion.coordinates[2] = right;
    touchRegion.coordinates[3] = top + 140.0f;

    const SpriteFrame* handle = sprite->GetFrame(stickFrame);
    const SpriteFrameModule* handlePart = sprite->GetFModule(handle->firstModule);
    displacementY = 0.0f;
    magnitude = 0.0f;
    const SpriteModule* handleModule = sprite->GetModule(handlePart->module);
    const float centerX = (handleModule->width >> 1) + handlePart->x;
    const float centerY = (handleModule->height >> 1) + handlePart->y;
    drawOriginX = centerX;
    drawOriginY = centerY;
    stickRadius = static_cast<int>(static_cast<float>((baseModule->width >> 1) - (handleModule->width >> 1)) + 30.0f);
}
