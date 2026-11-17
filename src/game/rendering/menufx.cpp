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
#include "CharacterVisibility.h"

extern "C" int vsprintf(char* buffer, const char* format, __builtin_va_list arguments);

void SwfFree(void* buffer);

namespace gameswf {
class tu_string {
public:
    // The retail call resolves the constructor through the GOT.
    explicit tu_string(const char* text) __attribute__((long_call));
    ~tu_string()
    {
        if (storage[0] == 255)
            SwfFree(heap);
    }

private:
    unsigned char storage[12];
    void* heap;
};

class edit_text_character {
public:
    void set_text_value(const tu_string& value, bool option);
};
}

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

struct SpriteEnabledState {
    unsigned char prefix[0x2a4];
    bool enabled;
};

}

extern const char activateAnimation[] __attribute__((visibility("hidden"))) = "activated";
static const char focusOutAnimation[] = "focus_out";
extern const char disabledAnimation[] __attribute__((visibility("hidden"))) = "disabled";

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

void RenderFX::SetEnabled(gameswf::character* character, bool enabled)
{
    if (!character || !animationMethods(character).is(character, 2))
        return;

    SpriteEnabledState& sprite = *reinterpret_cast<SpriteEnabledState*>(character);
    if (sprite.enabled != enabled) {
        if (enabled) {
            if (!PlayAnim(character, activateAnimation, 0))
                PlayAnim(character, focusOutAnimation, 0);
        } else {
            PlayAnim(character, disabledAnimation, 0);
        }
    }
    sprite.enabled = enabled;
}

void RenderFX::GotoFrame(gameswf::character* character, int frame, bool play)
{
    if (character && animationMethods(character).is(character, 2)) {
        animationMethods(character).gotoFrame(character, frame);
        animationMethods(character).setPlayState(character, !play);
    }
}

const gameswf::array<gameswf::character*>& RenderFX::FindCharacters(
    gameswf::character* parent, const char* name, int flags)
{
    gameswf::array<gameswf::character*>& matches =
        *reinterpret_cast<gameswf::array<gameswf::character*>*>(reinterpret_cast<char*>(this) + 4);
    matches.resize(0);
    CollectCharacters(parent, name, flags);
    return matches;
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

void RenderFX::SetEnabled(const char* characterName, bool enabled)
{
    SetEnabled(Find(characterName), enabled);
}

void RenderFX::SetVisible(const char* characterName, bool visible)
{
    gameswf::character* character = Find(characterName);
    if (character)
        setCharacterVisible(character, visible);
}

void RenderFX::SetText(gameswf::character* character, const char* text, bool option)
{
    if (character && animationMethods(character).is(character, 30)) {
        gameswf::tu_string value(text);
        reinterpret_cast<gameswf::edit_text_character*>(character)->set_text_value(value, option);
    }
}

void RenderFX::SetText(const char* characterName, const char* text, bool option)
{
    SetText(Find(characterName), text, option);
}

static char s_stringBuffer[8192];

void RenderFX::FormatText(const char* characterName, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    vsprintf(s_stringBuffer, format, arguments);
    __builtin_va_end(arguments);
    SetText(characterName, s_stringBuffer, false);
}

void RenderFX::FormatText(gameswf::character* character, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    vsprintf(s_stringBuffer, format, arguments);
    __builtin_va_end(arguments);
    SetText(character, s_stringBuffer, false);
}

void RenderFX::SetFocus(const char* characterName, int flags)
{
    SetFocus(Find(characterName), flags);
}
