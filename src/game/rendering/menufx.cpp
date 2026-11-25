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
#include "FlashMatrix.h"
#include "../core/NativeStdio.h"
#include "../core/LocalStartupText.h"
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

namespace { struct MovieRenderFX; }

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
    void clear() __attribute__((weak, long_call));
    glyph_provider(int width, int height, bool option);
    unsigned char prefix[20];
    texture_cache* cache;
};

struct bitmap_glyph_provider {
    void clear() __attribute__((weak, long_call));
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
    array<MovieRenderFX*> movies;
    unsigned char unknown32[4];
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
    cxform();
    static cxform identity;

    float channels[4][2];
};

} // namespace gameswf

#include "RetailSwfString.h"
#include "RetailSwfValue.h"

namespace gameswf {

class as_object {
public:
    as_object* find_target(const as_value& name);
};

class root {
public:
    as_object* get_root_movie();
    void advance(float delta, bool render);
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

RenderFX::SearchIndex::~SearchIndex()
{
    Clear();
}

namespace {
// Prefix of the gameswf character vtable through display callback registration.
struct CharacterAnimationMethods {
    void (*firstMethods[2])();
    bool (*is)(const gameswf::character*, int);
    void (*beforeSetMember[4])();
    bool (*setMember)(gameswf::character*, const gameswf::tu_stringi&, const gameswf::as_value&);
    void (*beforePlayState[26])();
    void (*setPlayState)(gameswf::character*, int);
    void (*beforeGotoLabeledFrame)();
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
        // Use the field address so GCC retains the separate reference guard.
        const unsigned int aliveAddress = reinterpret_cast<unsigned int>(reference) +
            __builtin_offsetof(MovieWeakReference, alive);
        if (!*reinterpret_cast<const bool*>(aliveAddress)) {
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

gameswf::character* RenderFX::Find(const char* name)
{
    gameswf::character* result = Find(name, context);
    if (result)
        return result;

    result = Find(name, reinterpret_cast<gameswf::character*>(
        reinterpret_cast<FlashCharacterRoot*>(root.get())->flashRoot));
    if (result)
        return result;

    gameswf::as_object* target =
        root.get()->get_root_movie()->find_target(gameswf::as_value(name));
    gameswf::character* character = reinterpret_cast<gameswf::character*>(target);
    if (character && animationMethods(character).is(character, 1))
        result = character;
    return result;
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

extern const char widgetHideAnimation[] __attribute__((visibility("hidden"))) = "hide";
extern const char widgetShowAnimation[] __attribute__((visibility("hidden"))) = "show";

void MenuFX::SetMenu(const char* name, bool push)
{
    State* next = GetState(name);
    if (!next)
        return;

    int count = stateStack.size;
    if (count > 0) {
        --count;
        State* current = stateStack.elements[count];
        current->LostFocus();
        if (push && PlayAnim(current->firstCharacter.get(), focusOutAnimation, 0)) {
            current->unknown80 = 4;
        } else {
            if (!push)
                current->Hide();
            if (PlayAnim(current->firstCharacter.get(), widgetHideAnimation, 0))
                current->unknown80 = 2;
        }
        current->secondCharacter.set_ref(controllers[0].first.get());
    }

    if (!push)
        stateStack.resize(stateStack.size - 1);
    stateStack.append(&next, 1);
    setCharacterVisible(next->firstCharacter.get(), true);
    SetContext(next->firstCharacter.get());
    PlayAnim(next->firstCharacter.get(), widgetShowAnimation, 0);
    if (inputBehavior & 1)
        SetFocusDefault();
    next->Show();
    next->GotFocus();
    next->unknown80 = 1;
}

static const char focusInAnimation[] = "focus_in";

void MenuFX::PopMenu()
{
    topState()->LostFocus();
    topState()->Hide();
    PlayAnim(topState()->firstCharacter.get(), widgetHideAnimation, 0);
    topState()->unknown80 = 2;

    SetContext(reinterpret_cast<gameswf::character*>(
        reinterpret_cast<FlashCharacterRoot*>(root.get())->flashRoot));
    stateStack.resize(stateStack.size - 1);
    if (stateStack.size > 0) {
        setCharacterVisible(topState()->firstCharacter.get(), true);
        SetContext(topState()->firstCharacter.get());
        if (!PlayAnim(topState()->firstCharacter.get(), focusInAnimation, 0))
            PlayAnim(topState()->firstCharacter.get(), widgetShowAnimation, 0);
        if ((inputBehavior & 1) && topState()->secondCharacter.get()) {
            ResetFocus(0);
            SetFocus(topState()->secondCharacter.get(), 0);
        }
        topState()->GotFocus();
        topState()->unknown80 = 3;
    }
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

void MenuFX::Update(int elapsed, bool render)
{
    RenderFX::Update(elapsed, render);
    if (stateStack.size > 0)
        topState()->Update(elapsed);

    for (int index = 0; index < registeredStates.size; ++index) {
        State* state = registeredStates.elements[index];
        if (state->unknown80 != 2 ||
            getCharacterPlayState(state->firstCharacter.get()) != 1 ||
            !isCharacterVisible(registeredStates.elements[index]->firstCharacter.get()))
            continue;

        for (int controller = 0; controller < 4; ++controller) {
            if (controllers[controller].fourth.get())
                goto nextState;
        }
        setCharacterVisible(registeredStates.elements[index]->firstCharacter.get(), false);
    nextState:
        ;
    }
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
    : unknown16(false), context(0),
      inputBehavior(0), listener(0)
{
}

MenuFX::MenuFX() : unknown220(false), unknown236(false)
{
    SetEventListener(this);
}

MenuFX::~MenuFX()
{
}

RenderFX::~RenderFX()
{
    Unload();
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

void RenderFX::FormatHTML(const char* characterName, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    vsprintf(s_stringBuffer, format, arguments);
    __builtin_va_end(arguments);
    SetText(characterName, s_stringBuffer, true);
}

void RenderFX::FormatText(const char* characterName, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    vsprintf(s_stringBuffer, format, arguments);
    __builtin_va_end(arguments);
    SetText(characterName, s_stringBuffer, false);
}

void RenderFX::FormatHTML(gameswf::character* character, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    vsprintf(s_stringBuffer, format, arguments);
    __builtin_va_end(arguments);
    SetText(character, s_stringBuffer, true);
}

void RenderFX::FormatText(gameswf::character* character, const char* format, ...)
{
    __builtin_va_list arguments;
    __builtin_va_start(arguments, format);
    vsprintf(s_stringBuffer, format, arguments);
    __builtin_va_end(arguments);
    SetText(character, s_stringBuffer, false);
}

void RenderFX::SetCursor(const char* characterName, int index)
{
    gameswf::character* character = Find(characterName);
    controllers[index].third.set_ref(character);
}

bool RenderFX::InvokeASCallback(const char* characterName, const char* callback)
{
    return InvokeASCallback(Find(characterName), callback);
}

void RenderFX::SetFocus(const char* characterName, int flags)
{
    SetFocus(Find(characterName), flags);
}

RenderFX::SearchIndex* RenderFX::GetSearchIndex()
{
    searchIndex.Init(*this);
    return &searchIndex;
}

static const char deprecatedInitialize[] =
    "RenderFX::Initialize(irr::video::IVideoDriver* videoDriver) deprecated. "
    "Use RenderFX::Initialize(InitializationParameters& parameters) instead.\n";

void RenderFX::Initialize(irr::video::IVideoDriver* driver)
{
    gameswf::log_msg(deprecatedInitialize);
    InitializationParameters parameters;
    parameters.textureLoader = 0;
    parameters.glyphOption = true;
    parameters.outlineWidth = 0;
    parameters.bitmapWidth = 0;
    parameters.driver = driver;
    parameters.bitmapHeight = 0;
    parameters.outlineHeight = 0;
    Initialize(parameters);
}

namespace gameswf {
int decode_next_unicode_character(const char** text);

template <>
class array<unsigned short> {
public:
    array() : elements(0), size(0), capacity(0), unknown12(false) {}
    ~array() { release_buffer(); }
    void resize(int size) __attribute__((weak));
    void release_buffer() __attribute__((weak));

    unsigned short* elements;
    int size;
    int capacity;
    bool unknown12;
};
}

int RenderFX::PreloadGlyphs(const char* text, const char* fontName, int size,
                            bool bold, bool italic, gameswf::filter* filter)
{
    gameswf::array<unsigned short> glyphs;
    while (int codePoint = gameswf::decode_next_unicode_character(&text)) {
        const int index = glyphs.size;
        glyphs.resize(index + 1);
        glyphs.elements[index] = codePoint;
    }
    if (glyphs.size > 0)
        return PreloadGlyphs(glyphs.elements, glyphs.size, fontName, size, bold, italic, filter);
    return 0;
}

namespace gameswf {

class bitmap_info;

namespace render {
bitmap_info* create_bitmap_info_texture(irr::video::ITexture* texture);
}

class character_def {
    unsigned char storage[32];
};

class bitmap_character : public character_def {
public:
    bitmap_character(player* owner, bitmap_info* bitmap) __attribute__((long_call));

private:
    bitmap_info* bitmap;
};

struct player_weak_ptr {
    struct proxy_ptr {
        MovieWeakReference* value;

        void clear()
        {
            if (value) {
                MovieWeakReference* previous = value;
                if (--previous->references == 0)
                    delete previous;
                value = 0;
            }
        }
    };

    mutable proxy_ptr proxy;
    mutable player* owner;

    void check_proxy() const
    {
        if (!owner)
            return;
        const unsigned int aliveAddress = reinterpret_cast<unsigned int>(proxy.value) +
            __builtin_offsetof(MovieWeakReference, alive);
        if (!*reinterpret_cast<const bool*>(aliveAddress)) {
            proxy.clear();
            owner = 0;
        }
    }

    player* get() const
    {
        check_proxy();
        return owner;
    }
};

struct character_texture_fields {
    struct VTable {
        void (*beforeReplaceMe[40])();
        void (*replaceMe)(character*, character_def*);
    };

    const VTable* methods;
    unsigned char unknown4[108];
    player_weak_ptr playerReference;
};

} // namespace gameswf

void RenderFX::SetTexture(const char* name, irr::video::ITexture* texture)
{
    gameswf::character* character = Find(name);
    if (!character)
        return;
    gameswf::bitmap_info* bitmap = gameswf::render::create_bitmap_info_texture(texture);
    gameswf::character_texture_fields& fields =
        *reinterpret_cast<gameswf::character_texture_fields*>(character);
    gameswf::player* owner = fields.playerReference.get();
    gameswf::bitmap_character* replacement = new (swf::DefaultMemHint) gameswf::bitmap_character(owner, bitmap);
    fields.methods->replaceMe(character, replacement);
}

void RenderFX::SetMember(const char* characterName, const char* member, int value)
{
    gameswf::as_value memberValue(value);
    SetMember(characterName, member, memberValue);
}

namespace gameswf {
class as_environment {
public:
    void set_local(const tu_string& name, const as_value& value);
};
}

void RenderFX::SetLocalVariable(const char* characterName, const char* variable, gameswf::as_value& value)
{
    gameswf::tu_string variableName(variable);
    gameswf::character* found = Find(characterName);
    gameswf::as_object* object = reinterpret_cast<gameswf::as_object*>(found);
    if (!found)
        object = root.get()->get_root_movie()->find_target(gameswf::as_value(characterName));

    gameswf::character* character = reinterpret_cast<gameswf::character*>(object);
    if (character && animationMethods(character).is(character, 2)) {
        gameswf::as_environment* environment = reinterpret_cast<gameswf::as_environment*>(
            reinterpret_cast<unsigned char*>(character) + 0x1c0);
        environment->set_local(variableName, value);
    }
}


void RenderFX::SetMember(const char* characterName, const char* member, const char* value)
{
    gameswf::as_value memberValue(value);
    SetMember(characterName, member, memberValue);
}


extern "C" {
const gameswf::matrix& _ZN7gameswf9character16get_world_matrixEv(gameswf::character* character);
}
gameswf::point GetLocalPosition(gameswf::character* character, float x, float y)
{
    gameswf::point input(x * 20.0f, y * 20.0f);
    gameswf::point result;
    gameswf::matrix world = _ZN7gameswf9character16get_world_matrixEv(character);
    gameswf::matrix inverse;
    inverse.set_inverse(world);
    inverse.transform(&result, input);
    return result;
}

bool CanHandleMouseEvent(gameswf::character* character);
bool sprite_can_handle_mouse_event_callback(gameswf::character* character)
{
    return CanHandleMouseEvent(character);
}

namespace {
inline void applyCharacterColor(gameswf::character* character, const gameswf::cxform& color)
{
    CharacterTransform& target = *reinterpret_cast<CharacterTransform*>(character);
    target.color = color;
    target.hasColor = true;
}
}

void RenderFX::SetColorTransform(gameswf::character* character, unsigned int multiply, unsigned int add)
{
    if (!character)
        return;
    gameswf::cxform color;
    color.channels[0][0] = finiteColor(static_cast<float>((multiply >> 16) & 255u) / 255.0f);
    color.channels[1][0] = finiteColor(static_cast<float>((multiply >> 8) & 255u) / 255.0f);
    color.channels[2][0] = finiteColor(static_cast<float>(multiply & 255u) / 255.0f);
    color.channels[3][0] = finiteColor(static_cast<float>(multiply >> 24) / 255.0f);
    color.channels[0][1] = finiteColor(static_cast<float>((add >> 16) & 255u));
    color.channels[1][1] = finiteColor(static_cast<float>((add >> 8) & 255u));
    color.channels[2][1] = finiteColor(static_cast<float>(add & 255u));
    color.channels[3][1] = finiteColor(static_cast<float>(add >> 24));
    applyCharacterColor(character, color);
}


class RenderFX::SearchIndex::Entry {
public:
    gameswf::character* character;
    char path[256];
};

extern "C" char* strrchr(const char*, int);

gameswf::character* RenderFX::SearchIndex::Find(const char* name)
{
    char component[128];
    const int nameLength = strlen(name);
    const char* suffix = strrchr(name, '.');
    suffix = suffix ? suffix + 1 : name;
    gameswf::tu_string key(suffix, name + nameLength - suffix);
    const int index = entries.find_index(key);
    if (index < 0)
        return 0;
    typedef gameswf::hash<gameswf::tu_string, gameswf::array<Entry>*,
        gameswf::string_hash_functor<gameswf::tu_string> > IndexHash;
    gameswf::array<Entry>* candidates =
        (reinterpret_cast<IndexHash::entry*>(entries.m_table + 1) + index)->second;
    for (int i = 0; i < candidates->size; ++i) {
        const Entry& entry = candidates->elements[i];
        const char* remainingPath = entry.path;
        const char* part = name;
        for (;;) {
            const char* end = strchr(part, '.');
            if (!end)
                end = part + nameLength;
            const int length = end - part;
            memcpy(component, part, length);
            component[length] = 0;
            const char* match = strstr(remainingPath, component);
            if (__builtin_expect(match != 0, 1)) {
                remainingPath = match + length;
                if (*remainingPath == 0)
                    return entry.character;
                part += length + 1;
            } else {
                break;
            }
        }
    }
    return 0;
}

static const char sendEventFocusIn[] __attribute__((section(".rodata.renderfx_send_0"))) = "on_focus_in";
static const char sendEventFocusOut[] __attribute__((section(".rodata.renderfx_send_1"))) = "on_focus_out";
static const char sendEventClicked[] __attribute__((section(".rodata.renderfx_send_2"))) = "on_clicked";
static const char sendEventPress[] __attribute__((section(".rodata.renderfx_send_4"))) = "onPress";
static const char sendEventRelease[] __attribute__((section(".rodata.renderfx_send_6"))) = "onRelease";
static const char sendEventReleaseOutside[] __attribute__((section(".rodata.renderfx_send_7"))) = "onReleaseOutside";
static const char sendEventRollOver[] __attribute__((section(".rodata.renderfx_send_8"))) = "onRollOver";
static const char sendEventRollOut[] __attribute__((section(".rodata.renderfx_send_9"))) = "onRollOut";

void RenderFX::SendEvent(Event& event)
{
    listener->OnEvent(event);
    if (event.consumed)
        return;
    switch (event.type) {
    case 0:
        InvokeASCallback(event.character, sendEventFocusIn);
        break;
    case 1:
        InvokeASCallback(event.character, sendEventFocusOut);
        break;
    case 2:
        InvokeASCallback(event.character, sendEventClicked);
        break;
    case 4:
        InvokeASCallback(event.character, sendEventPress);
        break;
    case 6:
        InvokeASCallback(event.character, sendEventRelease);
        break;
    case 7:
        InvokeASCallback(event.character, sendEventReleaseOutside);
        break;
    case 8:
        InvokeASCallback(event.character, sendEventRollOver);
        break;
    case 9:
        InvokeASCallback(event.character, sendEventRollOut);
        break;
    }
}

namespace {
// Only the observed root-movie pointer at +16 is exposed; no full root size.
struct ClearFontsRootFields {
    unsigned char prefix[16];
    gameswf::character* rootCharacter;
};
}

void RenderFX::ClearFonts(gameswf::player_context* context)
{
    if (!context)
        context = s_default_context;
    if (context->outlineGlyphs)
        context->outlineGlyphs->clear();
    if (context->bitmapGlyphs)
        context->bitmapGlyphs->clear();
    for (int i = 0; i < context->movies.size; ++i) {
        RenderFX* movie = context->movies.elements[i]->renderFX;
        const gameswf::array<gameswf::character*>& characters = movie->FindCharacters(
            reinterpret_cast<ClearFontsRootFields*>(movie->root.get())->rootCharacter, 0, 0);
        for (int j = 0; j < characters.size; ++j) {
            if (animationMethods(characters.elements[j]).is(characters.elements[j], 30)) {
                gameswf::character* character = characters.elements[j];
                gameswf::tu_string empty(localStartupEmptyText);
                reinterpret_cast<gameswf::edit_text_character*>(character)->set_text_value(empty, false);
            }
        }
    }
}

namespace {

struct CharacterCollectionFields {
    unsigned char unknown0[136];
    gameswf::tu_string name;
    // Authentic get_name const-reference API, adapted to observed +136 view.
    const gameswf::tu_string& get_name() const { return name; }
    unsigned char unknown152[154];
    bool visible;
};

struct SpriteCollectionFields {
    unsigned char unknown0[324];
    gameswf::array<gameswf::character*> children;
};

} // namespace

void RenderFX::CollectCharacters(gameswf::character* character, const char* name, int flags)
{
    const CharacterCollectionFields& fields = *reinterpret_cast<const CharacterCollectionFields*>(character);
    bool visible = !(flags & 1) || fields.visible;
    if (animationMethods(character).is(character, 2) && (flags & 2) &&
        !reinterpret_cast<const SpriteEnabledState*>(character)->enabled)
        visible = false;
    if (!visible)
        return;

    if ((!name || strstr(fields.get_name().c_str(), name)) &&
        (!(flags & 4) || fields.get_name().size() != 0)) {
        int index = matches.size;
        matches.resize(index + 1);
        matches.elements[index] = character;
    }

    if (animationMethods(character).is(character, 2)) {
        const gameswf::array<gameswf::character*>& children =
            reinterpret_cast<const SpriteCollectionFields*>(character)->children;
        for (int i = 0; i < children.size; ++i)
            CollectCharacters(children.elements[i], name, flags);
    }
}

namespace {

static const char foundChildFormat[] __attribute__((section(".rodata.renderfx_found_child"))) =
    "Found child named %s\n";
static const char childSpriteMessage[] __attribute__((section(".rodata.renderfx_child_sprite"))) =
    "child is a sprite ...";

} // namespace

void RenderFX::DBG_TraceContextInformation(gameswf::character* character)
{
    const gameswf::array<gameswf::character*>& children = FindCharacters(character, 0, 0);
    for (int i = 0; i < children.size; ++i) {
        const CharacterCollectionFields* child = reinterpret_cast<const CharacterCollectionFields*>(children.elements[i]);
        printf(foundChildFormat, child->get_name().c_str());
        gameswf::character* current = children.elements[i];
        if (animationMethods(current).is(current, 2))
            puts(childSpriteMessage);
    }
}

extern "C" const gameswf::cxform& _ZN7gameswf9character16get_world_cxformEv(gameswf::character*);

namespace {

static const char hierarchyStart[] __attribute__((section(".rodata.renderfx_hierarchy_start"))) = "Hierarchy:\n";
static const char hierarchyIndent[] __attribute__((section(".rodata.renderfx_hierarchy_indent"))) = "   ";
static const char hierarchyEdit[] __attribute__((section(".rodata.renderfx_hierarchy_edit"))) = "%s edit: '%s' text='%s' @ 0x%x\n";
static const char hierarchyPlay[] __attribute__((section(".rodata.renderfx_hierarchy_play"))) = "PLAY";
static const char hierarchyStop[] __attribute__((section(".rodata.renderfx_hierarchy_stop"))) = "STOP";
static const char hierarchySprite[] __attribute__((section(".rodata.renderfx_hierarchy_sprite"))) = "%s sprite: '%s' f=%d %s @ 0x%x\n";
static const char hierarchyCharacter[] __attribute__((section(".rodata.renderfx_hierarchy_character"))) = "%s ch: '%s' @ 0x%x\n";

} // namespace

void RenderFX::TraceHierarchy(gameswf::character* character, int flags, int depth)
{
    if (!character)
        character = reinterpret_cast<gameswf::character*>(
            reinterpret_cast<const FlashCharacterRoot*>(root.get())->flashRoot);
    if (depth == 0)
        gameswf::log_msg(hierarchyStart);
    const CharacterCollectionFields& fields = *reinterpret_cast<const CharacterCollectionFields*>(character);
    if ((flags & 1) && (!fields.visible || _ZN7gameswf9character16get_world_cxformEv(character).channels[3][0] == 0.0f))
        return;

    char indent[256] = {};
    for (int i = 0; i < depth; ++i)
        memcpy(indent + strlen(indent), hierarchyIndent, sizeof(hierarchyIndent));

    if (animationMethods(character).is(character, 30)) {
        const char* name = fields.get_name().c_str();
        const char* text = reinterpret_cast<const EditTextStorage*>(character)->text.c_str();
        gameswf::log_msg(hierarchyEdit, indent, name, text, character);
    } else if (animationMethods(character).is(character, 2)) {
        const char* name = fields.get_name().c_str();
        int frame = animationMethods(character).getCurrentFrame(character);
        int state = getCharacterPlayState(character);
        gameswf::log_msg(hierarchySprite, indent, name, frame,
                         state ? hierarchyPlay : hierarchyStop, character);
        const gameswf::array<gameswf::character*>& children =
            reinterpret_cast<const SpriteCollectionFields*>(character)->children;
        for (int i = 0; i < children.size; ++i)
            TraceHierarchy(children.elements[i], flags, depth + 1);
    } else {
        gameswf::log_msg(hierarchyCharacter, indent, fields.get_name().c_str(), character);
    }
}

template <class T>
static inline bool hasCharacter(const gameswf::smart_ptr<T>& pointer)
{
    return pointer.get() != 0;
}

void RenderFX::Update(int elapsed, bool render)
{
    DisplayRoot root(player->get_root());
    root.get()->advance(elapsed / 1000.0f, render);
    for (int index = 0; index < 4; ++index) {
        if (hasCharacter(controllers[index].fourth) && getCharacterPlayState(controllers[index].fourth.get()) == 1) {
            Event event;
            event.character = controllers[index].fourth.get();
            event.payload.y = 0.0f;
            event.payload.x = 0.0f;
            event.payload.z = 0.0f;
            event.payload.unknown24 = 0;
            event.type = 2;
            event.characterName = reinterpret_cast<const CharacterCollectionFields*>(event.character)->get_name().c_str();
            event.characterPath[0] = 0;
            event.consumed = false;
            event.payload.controller = index;
            SendEvent(event);
            controllers[index].fourth.set_ref(0);
        }
    }
}

void RenderFX::SetFocus(gameswf::character* character, int index)
{
    Event event;
    gameswf::character* previous = controllers[index].first.get();
    if (previous == character)
        return;
    if (previous && animationMethods(previous).is(previous, 2) &&
        reinterpret_cast<SpriteEnabledState*>(previous)->enabled) {
        PlayAnim(previous, focusOutAnimation, 0);
        event.character = previous;
        event.payload.y = 0.0f;
        event.payload.x = 0.0f;
        event.payload.z = 0.0f;
        event.payload.unknown24 = 0;
        event.type = 1;
        event.characterName = reinterpret_cast<const CharacterCollectionFields*>(previous)->get_name().c_str();
        event.characterPath[0] = 0;
        event.consumed = false;
        event.payload.controller = index;
        SendEvent(event);
    }
    controllers[index].first.set_ref(character);
    if (character) {
        event.character = character;
        event.payload.y = 0.0f;
        event.payload.x = 0.0f;
        event.payload.z = 0.0f;
        event.payload.unknown24 = 0;
        event.type = 0;
        event.characterName = reinterpret_cast<const CharacterCollectionFields*>(character)->get_name().c_str();
        event.characterPath[0] = 0;
        event.consumed = false;
        event.payload.controller = index;
        if (listener->CanHandleEvent(event)) {
            PlayAnim(character, focusInAnimation, 0);
            SendEvent(event);
        } else {
            controllers[index].first.set_ref(0);
        }
    }
}

void RenderFX::SetMember(const char* characterName, const char* member, gameswf::as_value& value)
{
    gameswf::tu_string memberName(member);
    gameswf::character* found = Find(characterName);
    gameswf::as_object* object = reinterpret_cast<gameswf::as_object*>(found);
    if (!found)
        object = root.get()->get_root_movie()->find_target(gameswf::as_value(characterName));
    gameswf::character* character = reinterpret_cast<gameswf::character*>(object);

    if (character)
        animationMethods(character).setMember(character, gameswf::tu_stringi(memberName), value);
}

extern "C" char* strstr(const char* text, const char* part);
namespace {
struct CharacterMouseState {
    unsigned char prefix[0x88];
    gameswf::tu_string name;
    unsigned char beforeUnknown133[0x9b];
    bool unknown133;
};
}

bool CanHandleMouseEvent(gameswf::character* character)
{
    CharacterMouseState* fields = reinterpret_cast<CharacterMouseState*>(character);
    if (!strstr(reinterpret_cast<const CharacterCollectionFields*>(character)->get_name().c_str(), widgetButtonPrefix))
        return fields->unknown133;
    if (!animationMethods(character).is(character, 2))
        return true;
    return reinterpret_cast<SpriteEnabledState*>(character)->enabled;
}
