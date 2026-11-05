/*
 * Radio
 *
 * Original file: Radio.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Radio.cpp here, in the order they appear in the library.
 */

#include "SoundManager.h"
#include "../core/ASprite.h"
#include "../ui/SwipeButton.h"

class AnimObject {
public:
    AnimObject();
    ~AnimObject();
    virtual void Update(int elapsed);
    void SetAnim(int animation);
    void Draw();

    unsigned char animationState[36];
    ASprite* sprite;
};

class Radio : public SwipeButton {
public:
    Radio(ASprite* sprite, int frame, int stationAnimation, int value1,
          int value2, int disabledFrame, int mutedAnimation);
    virtual inline ~Radio();
    virtual inline void show();
    virtual void draw2d() const;
    virtual void processTouch(long touch);

private:
    AnimObject* animation;
    int stationAnimation;
    int unknown68;
    int unknown72;
    int disabledFrame;
    int mutedAnimation;
    unsigned int radioFlags;
};

void Radio::show()
{
    flags |= 1;
    if (SoundManager::getInstance()->flags & 0x20)
        animation->SetAnim(mutedAnimation);
    else
        animation->SetAnim(stationAnimation + SoundManager::getInstance()->radioStation);
}

Radio::~Radio() { delete animation; }

void Radio::draw2d() const
{
    if (flags & 1) {
        if (radioFlags & 1) {
            sprite->PaintFrame(disabledFrame, 0, 0, 0);
        } else {
            SwipeButton::draw2d();
            animation->Draw();
        }
    }
}

Radio::Radio(ASprite* sprite, int frame, int firstStation, int value1,
             int value2, int disabled, int muted)
    : SwipeButton(sprite, frame), animation(new AnimObject), stationAnimation(firstStation),
      unknown68(value1), unknown72(value2), disabledFrame(disabled),
      mutedAnimation(muted), radioFlags(0)
{
    animation->sprite = sprite;
}

void Radio::processTouch(long touch)
{
    if (!(flags & 1) || (radioFlags & 1))
        return;
    SwipeButton::processTouch(touch);
    if (swipeDirection == 1)
        SoundManager::getInstance()->lastRadioStation();
    else if (swipeDirection == 2)
        SoundManager::getInstance()->nextRadioStation();
    if (!(SoundManager::getInstance()->flags & 0x20))
        animation->SetAnim(stationAnimation + SoundManager::getInstance()->radioStation);
}

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_0()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN5RadioC2EP7ASpriteiiiiii() __attribute__((used));
static void _GLOBAL__I__ZN5RadioC2EP7ASpriteiiiiii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
