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

class AnalogStick : public HudElement {
public:
    enum Mode { Mode0, Mode1, Mode2, ModeForceWidth = 0x7fffffff };

    virtual ~AnalogStick();
    void switchMode(Mode value);
    virtual void reset();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    virtual void processTouch(long id);
    virtual void processTouchRelease();

private:
    unsigned char unknown56[8];
    float displacement;
    unsigned char unknown68[4];
    float displacementX;
    float displacementY;
    float magnitude;
    unsigned char unknown84[16];
    Mode mode;
    int stickFrame;
};

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

static inline void setStickColor(irr::video::SColor& color, unsigned int alpha, unsigned int red)
{
    color.b = 255; color.g = 255; color.a = alpha; color.r = red;
}

void AnalogStick::draw2d() const
{
    if (!(flags & 1)) return;
    irr::video::SColor colors[4];
    if ((flags & 16) && (unknown52 & 256)) {
        setStickColor(colors[0],191,51);
        setStickColor(colors[1],191,51);
        setStickColor(colors[2],191,51);
        setStickColor(colors[3],191,51);
        ASprite::s_global_color = colors;
    } else if (!(flags & 2)) {
        setStickColor(colors[0],128,255);
        setStickColor(colors[1],128,255);
        setStickColor(colors[2],128,255);
        setStickColor(colors[3],128,255);
        ASprite::s_global_color = colors;
    }
    sprite->PaintFrame(frame,0,0,0);
    sprite->PaintFrame(stickFrame,static_cast<int>(displacementY),static_cast<int>(magnitude),0);
    ASprite::s_global_color = 0;
}

// Event declarations for the recovered destructor and vtable layout.
class EvStickMove : public IEvent {
public:
    virtual ~EvStickMove() __attribute__((used)) {}
};

class EvStickReleased : public IEvent {
public:
    virtual ~EvStickReleased() __attribute__((used)) {}
};

class EvUpDownStickMove : public IEvent {
public:
    virtual ~EvUpDownStickMove() __attribute__((used)) {}
};

class EvUpDownStickReleased : public IEvent {
public:
    virtual ~EvUpDownStickReleased() __attribute__((used)) {}
};

class EvLeftRightStickMove : public IEvent {
public:
    virtual ~EvLeftRightStickMove() __attribute__((used)) {}
};

class EvLeftRightStickReleased : public IEvent {
public:
    virtual ~EvLeftRightStickReleased() __attribute__((used)) {}
};

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
