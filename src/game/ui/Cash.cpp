/*
 * Cash
 *
 * Original file: Cash.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Cash.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "Cash.h"
#include "../app/Application.h"
#include "../characters/PlayerTest.h"
#include "../core/ASprite.h"
#include "../core/NativeStdio.h"
#include "../persistence/StringManager.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_cash_transitions {
extern const unsigned int civPassive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scriptedNpc_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civAggressive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int gangMember_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_trans[] __attribute__((visibility("hidden")));
extern const unsigned int swat_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civ_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int guard_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scripted_vehicle_trans[] __attribute__((visibility("hidden")));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_3()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_cash_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_cash_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_cash_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_cash_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_cash_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_cash_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_cash_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_cash_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_cash_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_cash_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN4CashC2EP7ASpriteiiiii() __attribute__((used));
static void _GLOBAL__I__ZN4CashC2EP7ASpriteiiiii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}


void Cash::SetPosition(int x, int y)
{
    positionX = x;
    positionY = y;
}

void Cash::SetCash(int amount)
{
    cash = amount;
}

int Cash::GetCash()
{
    return cash;
}

inline void Cash::align(bool left)
{
    alignedLeft = left;
    int width, height;
    Application::GetInstance()->GetScreenDimensions(width, height);
    positionX = width - positionX;
}

void Cash::AlignRight()
{
    align(false);
}

void Cash::AlignLeft()
{
    align(true);
}

void Cash::update(double)
{
    PlayerTest* player = PlayerTest::GetPlayer();
    if (player)
        cash = player->cash;
}

Cash::~Cash()
{
}

void Cash::drawCash(int amount, const int*, int& x, int y) const
{
    const char* text = Application::GetInstance()->GetStringManager()->formatAmount(amount, false, true);
    int length = strlen(text);
    int frames[32];
    int extraWidth = 0;
    int frameCount = 0;

    for (int i = 0; i < length; ++i) {
        frames[frameCount] = -1;
        unsigned char character = text[i];
        if (static_cast<unsigned char>(character - '0') <= 9) {
            frames[frameCount++] = digitFrames[character - '0'];
        } else {
            switch (character) {
            case '$':
                frames[frameCount++] = dollarFrame;
                extraWidth += sprite->GetFrameWidth(dollarFrame);
                break;
            case ',':
                frames[frameCount++] = commaFrame;
                extraWidth += sprite->GetFrameWidth(commaFrame);
                break;
            case '.':
                frames[frameCount++] = periodFrame;
                extraWidth += sprite->GetFrameWidth(periodFrame);
                break;
            case ' ':
                frames[frameCount++] = -1;
                extraWidth += 8;
                break;
            }
        }
    }

    if (!alignedLeft)
        x -= extraWidth;
    for (int i = 0; i < frameCount; ++i) {
        int frame = frames[i];
        if (frame != -1) {
            sprite->PaintFrame(frame, x, y, 0);
            x += sprite->GetFrameWidth(frame);
        } else {
            x += 8;
        }
    }
}

Cash::Cash(ASprite* image, int baseFrame, int frame104, int frame108, int frame112, int frame116)
    : HudElement(image, baseFrame, false)
{
    firstFrame = baseFrame;
    digitFrames[1] = baseFrame;
    dollarFrame = frame104;
    commaFrame = frame108;
    periodFrame = frame112;
    unknown116 = frame116;
    positionX = 6;
    positionY = 97;
    alignedLeft = true;
    digitFrames[2] = baseFrame + 1;
    digitFrames[3] = baseFrame + 2;
    digitFrames[4] = baseFrame + 3;
    digitFrames[5] = baseFrame + 4;
    digitFrames[6] = baseFrame + 5;
    digitFrames[7] = baseFrame + 6;
    digitFrames[8] = baseFrame + 7;
    digitFrames[9] = baseFrame + 8;
    digitFrames[0] = baseFrame + 9;
}
