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
