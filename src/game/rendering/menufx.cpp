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

extern "C" {
void _ZNK7gameswf11ref_counted7add_refEv(const gameswf::root* root);
void _ZN7gameswf11ref_counted8drop_refEv(gameswf::root* root);
void _ZN7gameswf4root13begin_displayEv(gameswf::root* root);
void _ZN7gameswf4root7displayEv(gameswf::root* root);
void _ZN7gameswf4root11end_displayEv(gameswf::root* root);
}

namespace gameswf {
class render_handler;
render_handler* get_render_handler();
void log_msg(const char* format, ...);

class player {
public:
    root* get_root();
};

class cxform {
public:
    static cxform identity;

    float channels[4][2];
};

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

struct RenderHandlerMethods {
    void (*beforeWireFrame[16])();
    void (*setWireFrame)(gameswf::render_handler*, bool);
    void (*beforeOrientation[23])();
    void (*setOrientation)(gameswf::render_handler*, gameswf::orientation_mode);
};

inline const RenderHandlerMethods& renderHandlerMethods(const gameswf::render_handler* handler)
{
    return **reinterpret_cast<const RenderHandlerMethods* const*>(handler);
}

struct FlashCharacterRoot {
    unsigned char prefix[0x10];
    gameswf::root* flashRoot;
    unsigned char beforeTextBuffering[0x5d];
    bool textBufferingEnabled;
};

struct ControllerState {
    unsigned char prefix[0x24];
    bool enabled;
    unsigned char padding[3];
};

struct RenderFXState {
    unsigned char prefix[4];
    gameswf::array<gameswf::character*> matches;
    unsigned char beforePlayer[8];
    gameswf::player* player;
    gameswf::character* root;
    gameswf::character* context;
    ControllerState controllers[4];
    int inputBehavior;
    RenderFX::EventListener* listener;
};

class DisplayRoot {
public:
    explicit DisplayRoot(gameswf::root* root) : root(root)
    {
        if (root)
            _ZNK7gameswf11ref_counted7add_refEv(root);
    }

    ~DisplayRoot()
    {
        if (root)
            _ZN7gameswf11ref_counted8drop_refEv(root);
    }

    gameswf::root* get() const { return root; }

private:
    gameswf::root* root;
};

struct CharacterTransform {
    unsigned char prefix[0x9c];
    gameswf::cxform color;
    bool hasColor;
    unsigned char beforeMatrix[0x23];
    gameswf::matrix placement;
    bool hasPlacement;
};

inline float finiteColor(float value)
{
    return value >= -__FLT_MAX__ && value <= __FLT_MAX__ ? value : 0.0f;
}

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

void RenderFX::SetOrientation(gameswf::orientation_mode orientation)
{
    gameswf::render_handler* handler = gameswf::get_render_handler();
    renderHandlerMethods(handler).setOrientation(handler, orientation);
}

void RenderFX::SetWireFrame(bool enabled)
{
    gameswf::render_handler* handler = gameswf::get_render_handler();
    renderHandlerMethods(handler).setWireFrame(handler, enabled);
}

static const char deprecatedGlyphCache[] =
    "RenderFX::InitializeGlyphTextureCache(int width, int height) deprecated. "
    "Use RenderFX::Initialize(InitializationParameters& parameters) instead.\n";

void RenderFX::InitializeGlyphTextureCache(int, int)
{
    gameswf::log_msg(deprecatedGlyphCache);
}

void RenderFX::BeginDisplay()
{
    DisplayRoot root(reinterpret_cast<RenderFXState*>(this)->player->get_root());
    _ZN7gameswf4root13begin_displayEv(root.get());
}

void RenderFX::Render()
{
    DisplayRoot root(reinterpret_cast<RenderFXState*>(this)->player->get_root());
    _ZN7gameswf4root7displayEv(root.get());
}

void RenderFX::EndDisplay()
{
    DisplayRoot root(reinterpret_cast<RenderFXState*>(this)->player->get_root());
    _ZN7gameswf4root11end_displayEv(root.get());
}

void RenderFX::SetEventListener(EventListener* listener)
{
    reinterpret_cast<RenderFXState*>(this)->listener = listener;
}

void RenderFX::SetControllerEnabled(int index, bool enabled)
{
    reinterpret_cast<RenderFXState*>(this)->controllers[index].enabled = enabled;
}

void RenderFX::SetInputBehavior(int behavior)
{
    reinterpret_cast<RenderFXState*>(this)->inputBehavior = behavior;
}

void RenderFX::SetContext(gameswf::character* character)
{
    reinterpret_cast<RenderFXState*>(this)->context = character;
}

gameswf::character* RenderFX::GetRoot() const
{
    return reinterpret_cast<const RenderFXState*>(this)->root;
}

gameswf::root* RenderFX::GetFlashRoot() const
{
    return reinterpret_cast<const FlashCharacterRoot*>(reinterpret_cast<const RenderFXState*>(this)->root)->flashRoot;
}

void RenderFX::SetTextBufferingEnabled(bool enabled)
{
    reinterpret_cast<FlashCharacterRoot*>(reinterpret_cast<RenderFXState*>(this)->root)->textBufferingEnabled = enabled;
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
        reinterpret_cast<RenderFXState*>(this)->matches;
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
    return character ? reinterpret_cast<const CharacterTransform*>(character)->color.channels[3][0] : 0.0f;
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

void RenderFX::SetAlpha(const char* characterName, float alpha)
{
    gameswf::character* character = Find(characterName);
    if (character) {
        gameswf::cxform color = gameswf::cxform::identity;
        color.channels[3][0] = finiteColor(alpha);
        CharacterTransform& transform = *reinterpret_cast<CharacterTransform*>(character);
        transform.color = color;
        transform.hasColor = true;
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
