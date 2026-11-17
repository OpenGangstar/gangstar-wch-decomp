#ifndef WCH_RENDERING_RENDER_FX_H
#define WCH_RENDERING_RENDER_FX_H

namespace irr { namespace video { class IVideoDriver; class ITexture; } }

namespace gameswf {
class character;
class render_state;
// Enumerator names are still unknown.
enum orientation_mode {};
class player_context;
class player;
class root;

class ref_counted {
public:
    void drop_ref();
};

template <typename T>
class smart_ptr {
public:
    smart_ptr() : value(0) {}
    ~smart_ptr()
    {
        if (value)
            reinterpret_cast<ref_counted*>(value)->drop_ref();
    }
    T* get() const { return value; }
    T* operator->() const { return value; }
    void set_ref(T* value) __attribute__((weak));

private:
    T* value;
};

template <typename T>
class array {
public:
    array() : elements(0), size(0), capacity(0) {}
    void resize(int size) __attribute__((weak));
    void append(const T* values, int count) __attribute__((weak));
    void remove(int index) __attribute__((weak));
    void release_buffer() __attribute__((weak));
    T* elements;
    int size;
    int capacity;
};
}

class RenderFX {
public:
    class Controller {
    public:
        Controller();
        ~Controller();
        void Reset() __attribute__((long_call));

        float unknown0;
        float unknown4;
        float unknown8;
        int unknown12;
        gameswf::smart_ptr<gameswf::character> first;
        gameswf::smart_ptr<gameswf::character> second;
        gameswf::smart_ptr<gameswf::character> third;
        gameswf::smart_ptr<gameswf::character> fourth;
        gameswf::smart_ptr<gameswf::character> fifth;
        bool enabled;
    };

    RenderFX();
    virtual ~RenderFX();
    virtual void Load(const char* name, gameswf::player_context* context);
    virtual void Unload();
    virtual void Update(int elapsed, bool render);
    class Event;
    class EventListener;
    void FSCommand(const char* command, const char* args);
    void SetEventListener(EventListener* listener);
    void SetInputBehavior(int behavior);
    void SetOrientation(gameswf::orientation_mode orientation);
    static void SetWireFrame(bool enabled);
    void InitializeGlyphTextureCache(int width, int height);
    struct InitializationParameters;
    static gameswf::player_context* CreateContext(InitializationParameters& parameters);
    static void Initialize(InitializationParameters& parameters);
    static void Finalize();
    static void DestroyContext(gameswf::player_context* context);
    static void ClearGlyphTextureCaches(gameswf::player_context* context);

    void SetBounds(int left, int top, int right, int bottom);
    void SetViewport(int x, int y, int width, int height);
    void PreRender();
    void BeginDisplay();
    void Render();
    void EndDisplay();
    void SetControllerEnabled(int index, bool enabled);
    void SetContext(gameswf::character* character);
    gameswf::root* GetRoot() const;
    gameswf::root* GetFlashRoot() const;
    void SetTextBufferingEnabled(bool enabled);
    gameswf::character* Find(const char* name);
    const gameswf::array<gameswf::character*>& FindCharacters(
        gameswf::character* parent, const char* name, int flags);
    bool PlayAnim(gameswf::character* character, const char* label, int flags);
    bool PlayAnim(const char* characterName, const char* label, int flags);
    bool GotoFrame(gameswf::character* character, const char* label, bool play);
    void GotoFrame(gameswf::character* character, int frame, bool play);
    bool GotoFrame(const char* characterName, const char* label, bool play);
    void GotoFrame(const char* characterName, int frame, bool play);
    void SetEnabled(gameswf::character* character, bool enabled);
    void SetEnabled(const char* characterName, bool enabled);
    void SetVisible(const char* characterName, bool visible);
    bool RegisterDisplayCallback(const char* characterName, void (*callback)(gameswf::render_state&, void*), void* context);
    bool RegisterDisplayCallback(gameswf::character* character, void (*callback)(gameswf::render_state&, void*), void* context);
    bool IsAnimOver(const char* characterName);
    bool IsAnimOver(gameswf::character* character);
    int GetFrameCount(const char* characterName);
    int GetFrameCount(gameswf::character* character);
    const char* GetText(const char* characterName);
    const char* GetText(gameswf::character* character);
    void SetAlpha(const char* characterName, float alpha);
    float GetAlpha(gameswf::character* character) const;
    void SetPosition(const char* characterName, int x, int y);
    void SetPosition(gameswf::character* character, int x, int y);
    void SetColorFilter(const char* characterName, int filter, unsigned int color);
    void SetColorFilter(gameswf::character* character, int filter, unsigned int color);
    void SetColorTransform(const char* characterName, unsigned int multiply, unsigned int add);
    void SetColorTransform(gameswf::character* character, unsigned int multiply, unsigned int add);
    void SetText(const char* characterName, const char* text, bool option);
    void SetText(gameswf::character* character, const char* text, bool option);
    void FormatText(const char* characterName, const char* format, ...);
    void FormatText(gameswf::character* character, const char* format, ...);
    void SetFocus(gameswf::character* character, int flags);
    void SetFocus(const char* characterName, int flags);

private:
    gameswf::array<gameswf::character*> matches;
    bool unknown16;
    void* unknown20;
    gameswf::smart_ptr<gameswf::player> player;
    gameswf::smart_ptr<gameswf::root> root;
    gameswf::character* context;
    Controller controllers[4];
    int inputBehavior;
    EventListener* listener;

    static gameswf::player_context* s_default_context;
    void CollectCharacters(gameswf::character* parent, const char* name, int flags);
};

#endif
