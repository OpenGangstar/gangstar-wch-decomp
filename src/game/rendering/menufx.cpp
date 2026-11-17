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
#include "../core/NativeStdio.h"

extern "C" int vsprintf(char* buffer, const char* format, __builtin_va_list arguments);

void SwfFree(void* buffer);

namespace gameswf {
class matrix {
public:
    matrix();
    void concatenate_translation(float x, float y);
    float get_x_scale() const;
    float get_y_scale() const;
    float get_rotation() const;
    void set_scale_rotation(float xScale, float yScale, float rotation);

private:
    float elements[6];
};

class tu_string {
public:
    // The retail call resolves the constructor through the GOT.
    explicit tu_string(const char* text) __attribute__((long_call));
    ~tu_string()
    {
        if (storage[0] == 255)
            SwfFree(heap);
    }

    const char* c_str() const
    {
        return storage[0] == 255 ? static_cast<const char*>(heap)
                                 : reinterpret_cast<const char*>(storage + 1);
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
// Prefix of the gameswf character vtable through display callback registration.
struct CharacterAnimationMethods {
    void (*firstMethods[2])();
    bool (*is)(const gameswf::character*, int);
    void (*beforePlayState[31])();
    void (*setPlayState)(gameswf::character*, int);
    void (*getPlayState)();
    bool (*gotoLabeledFrame)(gameswf::character*, const char*);
    void (*beforeFrameQueries[38])();
    int (*getCurrentFrame)(gameswf::character*);
    int (*getFrameCount)(gameswf::character*);
    void (*beforeGotoFrame[2])();
    void (*gotoFrame)(gameswf::character*, int);
    void (*beforeDisplayCallback[3])();
    void (*registerDisplayCallback)(gameswf::character*, void (*)(gameswf::render_state&, void*), void*);
};

inline const CharacterAnimationMethods& animationMethods(const gameswf::character* character)
{
    return **reinterpret_cast<const CharacterAnimationMethods* const*>(character);
}

struct CharacterTransform {
    unsigned char prefix[0xb4];
    float alpha;
    unsigned char beforeMatrix[0x28];
    gameswf::matrix placement;
    bool hasPlacement;
};

struct ColorFilterEntry {
    int type;
    unsigned char color[4];
    unsigned char unknown8[36];
};

struct CharacterFilters {
    unsigned char prefix[0x11c];
    ColorFilterEntry* filters;
    int count;
};

struct EditTextStorage {
    unsigned char prefix[0x180];
    gameswf::tu_string text;
};

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

int RenderFX::GetFrameCount(gameswf::character* character)
{
    if (character && animationMethods(character).is(character, 2))
        return animationMethods(character).getFrameCount(character);
    return 0;
}

bool RenderFX::IsAnimOver(gameswf::character* character)
{
    if (!character || !animationMethods(character).is(character, 2))
        return false;

    // Retail queries both frames before repeating the calls for the comparison.
    animationMethods(character).getCurrentFrame(character);
    animationMethods(character).getFrameCount(character);
    const int current = animationMethods(character).getCurrentFrame(character);
    return current >= animationMethods(character).getFrameCount(character) - 1;
}

bool RenderFX::RegisterDisplayCallback(gameswf::character* character,
                                       void (*callback)(gameswf::render_state&, void*), void* context)
{
    if (!character)
        return false;
    animationMethods(character).registerDisplayCallback(character, callback, context);
    return true;
}

const char* RenderFX::GetText(gameswf::character* character)
{
    if (character && animationMethods(character).is(character, 30))
        return reinterpret_cast<const EditTextStorage*>(character)->text.c_str();
    return 0;
}

bool RenderFX::RegisterDisplayCallback(const char* characterName, void (*callback)(gameswf::render_state&, void*), void* context)
{
    return RegisterDisplayCallback(Find(characterName), callback, context);
}

bool RenderFX::IsAnimOver(const char* characterName)
{
    gameswf::character* character = Find(characterName);
    return character ? IsAnimOver(character) : 0;
}

int RenderFX::GetFrameCount(const char* characterName)
{
    gameswf::character* character = Find(characterName);
    return character ? GetFrameCount(character) : 0;
}

const char* RenderFX::GetText(const char* characterName)
{
    return GetText(Find(characterName));
}

float RenderFX::GetAlpha(gameswf::character* character) const
{
    return character ? reinterpret_cast<const CharacterTransform*>(character)->alpha : 0.0f;
}

void RenderFX::SetPosition(gameswf::character* character, int x, int y)
{
    if (!character)
        return;

    CharacterTransform* transform = reinterpret_cast<CharacterTransform*>(character);
    gameswf::matrix* original = &transform->placement;
    gameswf::matrix placement;
    placement.concatenate_translation(20.0f * x, 20.0f * y);
    placement.set_scale_rotation(original->get_x_scale(), original->get_y_scale(),
                                 original->get_rotation());
    memcpy(original, &placement, sizeof(placement));
    transform->hasPlacement = true;
}

void RenderFX::SetColorFilter(gameswf::character* character, int filter, unsigned int color)
{
    if (!character || filter < 0)
        return;

    CharacterFilters& filters = *reinterpret_cast<CharacterFilters*>(character);
    if (filter >= filters.count)
        return;

    ColorFilterEntry& entry = filters.filters[filter];
    if (entry.type == 0 || entry.type == 2) {
        entry.color[1] = color >> 8;
        entry.color[2] = color >> 16;
        entry.color[0] = color;
        entry.color[3] = color >> 24;
    }
}

void RenderFX::SetPosition(const char* characterName, int x, int y)
{
    SetPosition(Find(characterName), x, y);
}

void RenderFX::SetColorFilter(const char* characterName, int filter, unsigned int color)
{
    SetColorFilter(Find(characterName), filter, color);
}

void RenderFX::SetColorTransform(const char* characterName, unsigned int multiply, unsigned int add)
{
    SetColorTransform(Find(characterName), multiply, add);
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
