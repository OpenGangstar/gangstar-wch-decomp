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
#include "../ui/MenuState.h"

// The Android libc exposes stdin, stdout, and stderr as adjacent entries.
struct AndroidStdioEntry {
    unsigned char storage[84];
};

extern "C" {
extern AndroidStdioEntry __sF[];
int fputs(const char* text, NativeFile* file);
int fflush(NativeFile* file);
}

extern "C" int strcmp(const char* left, const char* right);
extern "C" int vsprintf(char* buffer, const char* format, __builtin_va_list arguments);

namespace swf {
enum MemHint { DefaultMemHint = 0 };
}
void* operator new(unsigned int size, swf::MemHint hint);

void SwfFree(void* buffer);

extern "C" {
void _ZNK7gameswf11ref_counted7add_refEv(const gameswf::root* root);
void _ZN7gameswf11ref_counted8drop_refEv(gameswf::root* root);
void _ZN7gameswf4root18set_display_boundsEiiii(gameswf::root* root, int left, int top, int right, int bottom);
void _ZN7gameswf4root20set_display_viewportEiiii(gameswf::root* root, int x, int y, int width, int height);
void _ZN7gameswf4root13begin_displayEv(gameswf::root* root);
void _ZN7gameswf4root7displayEv(gameswf::root* root);
void _ZN7gameswf4root11end_displayEv(gameswf::root* root);
}

namespace gameswf {
class tu_file {
public:
    tu_file(const char* name, const char* mode);

private:
    unsigned char storage[40];
};
typedef irr::video::ITexture* (*TextureLoader)(const char*, int, int);
typedef void (*FSCommandCallback)(character*, const char*, const char*);

class render_handler {
public:
    virtual ~render_handler();
};
render_handler* get_render_handler();
void set_render_handler(render_handler* handler);
void clears_tag_loaders();
void clear_shared_libs();
void clear_standard_fnames();
void clear_standard_method_map();
void clear_standard_property_map();
void clear_disasm();
void register_file_opener_callback(tu_file* (*callback)(const char*));
void register_fscommand_callback(FSCommandCallback callback);
void register_log_callback(void (*callback)(bool, const char*));
void register_texture_loader_callback(TextureLoader callback);
bool get_verbose_parse();
render_handler* create_render_handler_irrlicht(void* driver);
void standard_method_map_init();
void log_msg(const char* format, ...);

class texture_cache {
public:
    void reset();
};

class tu_string;
class font_entity;

struct glyph_provider {
    glyph_provider(int width, int height, bool option);
    unsigned char prefix[20];
    texture_cache* cache;
};

struct bitmap_glyph_provider {
    bitmap_glyph_provider(int width, int height, bool option) __attribute__((long_call));
    virtual ~bitmap_glyph_provider();
    virtual font_entity* get_font_entity_impl(const tu_string& name);
    unsigned char prefix[8];
    texture_cache* cache;
};

struct default_bitmap_glyph_provider : bitmap_glyph_provider {
    default_bitmap_glyph_provider(int width, int height, bool option)
        : bitmap_glyph_provider(width, height, option)
    {
    }

    virtual ~default_bitmap_glyph_provider();
    virtual font_entity* get_font_entity_impl(const tu_string& name);
};

class player_context {
public:
    player_context();
    virtual ~player_context();

    unsigned char unknown4[8];
    glyph_provider* outlineGlyphs;
    bitmap_glyph_provider* bitmapGlyphs;
    unsigned char unknown20[16];
};

class filter_engine {
public:
    static filter_engine* s_instance;
    void run(root* movie);
};

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

template<class T> struct string_hash_functor;

template<class Key, class Value, class Hash>
class hash {
public:
    ~hash() { clear(); }
    void clear() __attribute__((weak));

private:
    void* table;
};

class edit_text_character {
public:
    void set_text_value(const tu_string& value, bool option);
};
}

gameswf::tu_file* file_opener(const char*) __attribute__((visibility("hidden")));
void fs_callback(gameswf::character*, const char*, const char*) __attribute__((visibility("hidden")));
void fscommand_callback_handler(gameswf::character*, const char*, const char*) __attribute__((visibility("hidden")));
void log_callback(bool, const char*) __attribute__((visibility("hidden")));

void message_log(const char* text)
{
    if (gameswf::get_verbose_parse()) {
        NativeFile* output = reinterpret_cast<NativeFile*>(&__sF[1]);
        fputs(text, output);
        fflush(output);
    }
}

void log_callback(bool error, const char* text)
{
    if (error) {
        message_log(text);
        NativeFile* output = reinterpret_cast<NativeFile*>(&__sF[2]);
        fputs(text, output);
        fflush(output);
    } else {
        message_log(text);
    }
}

class RenderFX::SearchIndex {
public:
    ~SearchIndex();
    void Clear() __attribute__((long_call));
    class Entry;

private:
    gameswf::hash<gameswf::tu_string, gameswf::array<Entry>*,
                  gameswf::string_hash_functor<gameswf::tu_string> > entries;
};

RenderFX::SearchIndex::~SearchIndex()
{
    Clear();
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

struct MovieRenderFX {
    unsigned char prefix[0x5c];
    RenderFX* renderFX;
};

struct MovieWeakReference {
    int references;
    bool alive;
};

struct CharacterMovie {
    unsigned char prefix[0x70];
    MovieWeakReference* reference;
    MovieRenderFX* movie;
};

struct RenderHandlerMethods {
    void (*beforeWireFrame[16])();
    void (*setWireFrame)(gameswf::render_handler*, bool);
    void (*beforeAntialiasing[14])();
    void (*setAntialiased)(gameswf::render_handler*, bool);
    void (*beforeOpen[6])();
    void (*open)(gameswf::render_handler*);
    void (*reset)(gameswf::render_handler*);
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

struct RenderFX::InitializationParameters {
    irr::video::IVideoDriver* driver;
    gameswf::TextureLoader textureLoader;
    int outlineWidth;
    int outlineHeight;
    int bitmapWidth;
    int bitmapHeight;
    bool glyphOption;
};

gameswf::player_context* RenderFX::CreateContext(InitializationParameters& parameters)
{
    gameswf::player_context* context = new (swf::DefaultMemHint) gameswf::player_context;
    context->outlineGlyphs = new (swf::DefaultMemHint) gameswf::glyph_provider(
        parameters.outlineWidth, parameters.outlineHeight, parameters.glyphOption);
    context->bitmapGlyphs = new (swf::DefaultMemHint) gameswf::default_bitmap_glyph_provider(
        parameters.bitmapWidth, parameters.bitmapHeight, parameters.glyphOption);
    return context;
}

void RenderFX::Initialize(InitializationParameters& parameters)
{
    if (s_default_context)
        return;

    gameswf::register_file_opener_callback(file_opener);
    gameswf::register_fscommand_callback(fs_callback);
    if (gameswf::get_verbose_parse())
        gameswf::register_log_callback(log_callback);
    gameswf::register_fscommand_callback(fscommand_callback_handler);

    gameswf::render_handler* handler = gameswf::create_render_handler_irrlicht(parameters.driver);
    gameswf::set_render_handler(handler);
    renderHandlerMethods(handler).open(handler);
    renderHandlerMethods(handler).setAntialiased(handler, true);

    if (parameters.textureLoader)
        gameswf::register_texture_loader_callback(parameters.textureLoader);
    gameswf::standard_method_map_init();
    s_default_context = CreateContext(parameters);
}

void RenderFX::Finalize()
{
    DestroyContext(s_default_context);
    s_default_context = 0;

    gameswf::render_handler* handler = gameswf::get_render_handler();
    if (handler) {
        delete handler;
        gameswf::set_render_handler(0);
    }
    gameswf::clears_tag_loaders();
    gameswf::clear_shared_libs();
    gameswf::clear_standard_fnames();
    gameswf::clear_standard_method_map();
    gameswf::clear_standard_property_map();
    gameswf::clear_disasm();
}

void RenderFX::DestroyContext(gameswf::player_context* context)
{
    delete context;
}

void RenderFX::ClearGlyphTextureCaches(gameswf::player_context* context)
{
    if (!context)
        context = s_default_context;

    if (context->outlineGlyphs && context->outlineGlyphs->cache)
        context->outlineGlyphs->cache->reset();
    if (context->bitmapGlyphs && context->bitmapGlyphs->cache)
        context->bitmapGlyphs->cache->reset();
}

void RenderFX::PreRender()
{
    DisplayRoot root(player->get_root());
    gameswf::filter_engine* engine = gameswf::filter_engine::s_instance;
    if (!engine)
        return;
    engine->run(root.get());
}

void RenderFX::SetBounds(int left, int top, int right, int bottom)
{
    DisplayRoot root(player->get_root());
    _ZN7gameswf4root18set_display_boundsEiiii(root.get(), left, top, right, bottom);
}

void RenderFX::SetViewport(int x, int y, int width, int height)
{
    DisplayRoot root(player->get_root());
    _ZN7gameswf4root20set_display_viewportEiiii(root.get(), x, y, width, height);
}

void RenderFX::BeginDisplay()
{
    DisplayRoot root(player->get_root());
    _ZN7gameswf4root13begin_displayEv(root.get());
}

void RenderFX::Render()
{
    DisplayRoot root(player->get_root());
    _ZN7gameswf4root7displayEv(root.get());
}

void RenderFX::EndDisplay()
{
    DisplayRoot root(player->get_root());
    _ZN7gameswf4root11end_displayEv(root.get());
}

static const char swfReadMode[] = "rb";

gameswf::tu_file* file_opener(const char* name)
{
    return new (swf::DefaultMemHint) gameswf::tu_file(name, swfReadMode);
}

void fs_callback(gameswf::character*, const char*, const char*)
{
}

void fscommand_callback_handler(gameswf::character* character, const char* command, const char* args)
{
    CharacterMovie& state = *reinterpret_cast<CharacterMovie*>(character);
    MovieRenderFX* movie = state.movie;
    if (movie) {
        MovieWeakReference* reference = state.reference;
        if (!reference->alive) {
            if (reference) {
                if (--reference->references == 0)
                    delete reference;
                state.reference = 0;
            }
            state.movie = 0;
            movie = 0;
        }
    }
    movie->renderFX->FSCommand(command, args);
}

bool RenderFX::EventListener::CanHandleEvent(Event&)
{
    return true;
}

void RenderFX::FSCommand(const char* command, const char* args)
{
    EventListener* listener = this->listener;
    if (listener)
        listener->OnFSCommand(command, args);
}

void RenderFX::Unload()
{
    gameswf::render_handler* handler = gameswf::get_render_handler();
    if (handler)
        renderHandlerMethods(handler).reset(handler);

    root.set_ref(0);
    player.set_ref(0);
    SetContext(0);
    for (int index = 0; index < 4; ++index)
        controllers[index].Reset();
}

class RenderFX::Event {
public:
    gameswf::character* character;
};

bool MenuFX::CanHandleEvent(RenderFX::Event& event)
{
    if (stateStack.size > 0)
        return GetStateHandler(event.character)->CanHandleEvent(event);
    return true;
}

void MenuFX::OnEvent(RenderFX::Event& event)
{
    if (stateStack.size > 0)
        GetStateHandler(event.character)->OnEvent(event);
}

MenuFX::State* MenuFX::GetState(const char* name)
{
    for (int index = 0; index < registeredStates.size; ++index) {
        State* state = registeredStates.elements[index];
        if (strcmp(state->name, name) == 0)
            return state;
    }
    return 0;
}

void MenuFX::RegisterState(State* state, const char* characterName)
{
    state->menu = this;
    registeredStates.append(&state, 1);
    if (!characterName)
        characterName = state->name;
    gameswf::character* character = Find(characterName);
    state->firstCharacter.set_ref(character);
    setCharacterVisible(character, false);
    state->Create();
}

extern const char widgetButtonPrefix[] __attribute__((visibility("hidden"))) = "btn";
static const char missingMenuFormat[] = "menu %s not found";

void MenuFX::RegisterStates(State** states, int count)
{
    for (int index = 0; index < count; ++index) {
        states[index]->menu = this;
        registeredStates.append(states + index, 1);
    }
    for (int index = 0; index < count; ++index) {
        const char* name = states[index]->name;
        gameswf::character* character = Find(name);
        if (character) {
            states[index]->firstCharacter.set_ref(character);
            setCharacterVisible(character, false);
            states[index]->Create();
        } else {
            char message[32];
            sprintf(message, missingMenuFormat, name);
            message_log(message);
        }
    }

    const gameswf::array<gameswf::character*>& buttons = FindCharacters(context, widgetButtonPrefix, 0);
    for (int index = 0; index < buttons.size; ++index) {
        if (animationMethods(buttons.elements[index]).is(buttons.elements[index], 2))
            reinterpret_cast<SpriteEnabledState*>(buttons.elements[index])->enabled = true;
    }
}

void MenuFX::SetFocusDefault()
{
    const gameswf::array<gameswf::character*>& buttons = FindCharacters(context, widgetButtonPrefix, 3);
    if (buttons.size > 0)
        SetFocus(buttons.elements[0], 0);
    else
        ResetFocus(0);
}

void RenderFX::ResetFocus(int flags)
{
    SetFocus(static_cast<gameswf::character*>(0), flags);
}

void MenuFX::SwitchMenu(const char* name)
{
    SetMenu(name, false);
}

void MenuFX::PushMenu(const char* name)
{
    SetMenu(name, true);
}

void MenuFX::Unload()
{
    RenderFX::Unload();
    registeredStates.resize(0);
    stateStack.resize(0);
}

void MenuFX::PopAll()
{
    if (stateStack.size > 0) {
        do {
            int index = stateStack.size;
            --index;
            stateStack.elements[index]->Hide();
            index = stateStack.size;
            --index;
            stateStack.elements[index]->unknown80 = 2;
            stateStack.resize(stateStack.size - 1);
        } while (stateStack.size > 0);
    }
    SetContext(reinterpret_cast<gameswf::character*>(
        reinterpret_cast<FlashCharacterRoot*>(root.get())->flashRoot));
}

void MenuFX::OnFSCommand(const char* command, const char* args)
{
    int count = stateStack.size;
    if (count > 0) {
        --count;
        stateStack.elements[count]->OnFSCommand(command, args);
    }
}

MenuFX::State* MenuFX::GetCurrentState()
{
    int count = stateStack.size;
    if (count <= 0)
        return 0;
    --count;
    return stateStack.elements[count];
}

bool MenuFX::IsStateInStack(State* state)
{
    for (int index = 0; index < stateStack.size; ++index) {
        if (stateStack.elements[index] == state)
            return true;
    }
    return false;
}

void RenderFX::SetEventListener(EventListener* listener)
{
    this->listener = listener;
}

inline RenderFX::Controller::Controller()
    : unknown12(0)
{
    unknown4 = 0.0f;
    unknown0 = 0.0f;
    unknown8 = 0.0f;
    enabled = true;
    Reset();
}

RenderFX::RenderFX()
    : unknown16(false), unknown20(0), context(0),
      inputBehavior(0), listener(0)
{
}

void RenderFX::Controller::Reset()
{
    first.set_ref(0);
    second.set_ref(0);
    third.set_ref(0);
    fourth.set_ref(0);
    fifth.set_ref(0);
}

RenderFX::Controller::~Controller()
{
}

void RenderFX::SetControllerEnabled(int index, bool enabled)
{
    controllers[index].enabled = enabled;
}

void RenderFX::SetInputBehavior(int behavior)
{
    inputBehavior = behavior;
}

void RenderFX::SetContext(gameswf::character* character)
{
    context = character;
}

gameswf::root* RenderFX::GetRoot() const
{
    return root.get();
}

gameswf::root* RenderFX::GetFlashRoot() const
{
    return reinterpret_cast<const FlashCharacterRoot*>(root.get())->flashRoot;
}

void RenderFX::SetTextBufferingEnabled(bool enabled)
{
    reinterpret_cast<FlashCharacterRoot*>(root.get())->textBufferingEnabled = enabled;
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
        this->matches;
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
