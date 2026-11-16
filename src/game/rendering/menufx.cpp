/*
 * menufx
 *
 * Original file: menufx.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of menufx.cpp here, in the order they appear in the library.
 */

#include "RenderFX.h"

namespace {
// Prefix of the gameswf character vtable through the numeric frame method.
struct CharacterAnimationMethods {
    void (*firstMethods[2])();
    bool (*is)(const gameswf::character*, int);
    void (*beforePlayState[31])();
    void (*setPlayState)(gameswf::character*, int);
    void (*getPlayState)();
    bool (*gotoLabeledFrame)(gameswf::character*, const char*);
    void (*beforeGotoFrame[42])();
    void (*gotoFrame)(gameswf::character*, int);
};

inline const CharacterAnimationMethods& animationMethods(const gameswf::character* character)
{
    return **reinterpret_cast<const CharacterAnimationMethods* const*>(character);
}
}

bool RenderFX::GotoFrame(gameswf::character* character, const char* label, bool play)
{
    if (!character || !animationMethods(character).is(character, 2))
        return false;
    if (!animationMethods(character).gotoLabeledFrame(character, label))
        return false;
    animationMethods(character).setPlayState(character, !play);
    return true;
}

bool RenderFX::PlayAnim(gameswf::character* character, const char* label, int)
{
    return GotoFrame(character, label, true);
}

void RenderFX::GotoFrame(gameswf::character* character, int frame, bool play)
{
    if (character && animationMethods(character).is(character, 2)) {
        animationMethods(character).gotoFrame(character, frame);
        animationMethods(character).setPlayState(character, !play);
    }
}

void RenderFX::GotoFrame(const char* characterName, int frame, bool play)
{
    gameswf::character* character = Find(characterName);
    if (character)
        GotoFrame(character, frame, play);
}

bool RenderFX::GotoFrame(const char* characterName, const char* label, bool play)
{
    return GotoFrame(Find(characterName), label, play);
}

bool RenderFX::PlayAnim(const char* characterName, const char* label, int)
{
    return GotoFrame(characterName, label, true);
}
