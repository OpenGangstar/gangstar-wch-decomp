/*
 * Message
 *
 * Original file: Message.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Message.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "Message.h"
#include "../scripting/ScriptManager.h"
#include "../core/SafeDelete.h"
#include "../characters/AnimObject.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_message_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_message_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_message_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_message_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_message_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_message_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_message_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_message_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_message_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_message_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_message_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN7MessageC2EP7ASpriteN11MenuManager5eTextEii() __attribute__((used));
static void _GLOBAL__I__ZN7MessageC2EP7ASpriteN11MenuManager5eTextEii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void Message::setTimer(int duration)
{
    if (duration == -1) {
        untimed = true;
    } else {
        timer = duration;
        untimed = false;
    }
}

void Message::setAnim(int animation)
{
    animationId = animation;
    animationObject->SetAnim(animation);
}

void Message::clearMessage(bool clearAnimation)
{
    setAnim(clearAnimation ? -1 : defaultAnimation);
    timedDisplay = false;
}

void Message::draw2d() const
{
    if (animationId != -1 && unknown80 != -1)
        animationObject->Draw();
}

extern "C" char* strcpy(char* destination, const char* source);

void Message::setMessage(const char* text, int duration)
{
    strcpy(messageText, text);
    unknown80 = -2;
    setTimer(duration);
    if (timedDisplay) {
        clearMessage(false);
        pendingMessage = true;
    } else if (unknown80 != -1) {
        setAnim(messageAnimation);
    }
}

template<> void SafeDelete<AnimObject>(AnimObject*& object) __attribute__((weak));

Message::~Message()
{
    SafeDelete(animationObject);
}

Message::Message(ASprite* sprite, MenuManager::eText text, int message, int fallback)
    : HudElement(sprite, -1, true),
      messageAnimation(message), defaultAnimation(fallback), textSlot(text),
      timer(-1), animationId(-1), unknown80(-1),
      timedDisplay(false), untimed(false), pendingMessage(false)
{
    animationObject = new AnimObject;
    animationObject->sprite = sprite;
    animationObject->SetAnim(animationId);
}

void Message::update(double elapsed)
{
    if (ScriptManager::getInstance()->isInCinematic())
        clearMessage(true);

    if (timedDisplay) {
        if (!untimed) {
            timer = static_cast<int>(timer - elapsed);
            if (timer <= 0) {
                setAnim(defaultAnimation);
                timedDisplay = false;
            }
        }
    } else if (animationId == -1) {
        MenuManager::getInstance()->setText(textSlot, -1, 0);
    } else {
        animationObject->Update(static_cast<int>(elapsed));
        if (animationId == messageAnimation) {
            if (animationObject->IsAnimOver() || animationId == -2) {
                if (unknown80 == -2)
                    MenuManager::getInstance()->setText(textSlot, messageText, 0);
                else if (unknown80 != -1)
                    MenuManager::getInstance()->setText(textSlot, unknown80, 0);
                timedDisplay = true;
            }
        } else if (defaultAnimation != 0) {
            if (unknown80 == -2) {
                MenuManager::getInstance()->setText(textSlot, static_cast<const char*>(0), 0);
                unknown80 = -1;
            } else if (unknown80 != -1) {
                MenuManager::getInstance()->setText(textSlot, -1, 0);
            }
            if (animationObject->IsAnimOver() || animationId == -3)
                setAnim(-1);
            if (pendingMessage) {
                pendingMessage = false;
                if (unknown80 != -1)
                    setAnim(messageAnimation);
                else
                    setAnim(-1);
            }
        }
    }
}

void Message::setMessage(int textId, int duration, MenuManager::eText slot)
{
    if (timedDisplay && unknown80 != textId) {
        unknown80 = textId;
        setTimer(duration);
        textSlot = slot;
        clearMessage(false);
        pendingMessage = true;
    } else {
        unknown80 = textId;
        setTimer(duration);
        textSlot = slot;
        if (unknown80 != -1)
            setAnim(messageAnimation);
        else
            setAnim(-1);
    }
}
