#ifndef WCH_RENDERING_RENDER_FX_H
#define WCH_RENDERING_RENDER_FX_H

namespace irr { namespace video { class IVideoDriver; class ITexture; } }

class RenderFX;

namespace gameswf {
class filter;
class as_value;
class character;
class render_state;
// Enumerator names are still unknown.
enum orientation_mode {};
class player_context;
class player;
class tu_string;
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
    ~array() {}
    void resize(int size) __attribute__((weak));
    void append(const T* values, int count) __attribute__((weak));
    void remove(int index) __attribute__((weak));
    void release_buffer() __attribute__((weak));
    T* elements;
    int size;
    int capacity;
};

template <>
inline array<character*>::~array()
{
    release_buffer();
}

template<class T> struct string_hash_functor;

template<class Key, class Value, class Hash>
class hash {
public:
    hash() : m_table(0) {}
    ~hash() { clear(); }
    void clear() __attribute__((weak));
    // Authentic tu-testbed container.h record declarations; algorithms remain native.
    struct entry {
        int m_next_in_chain;
        unsigned int m_hash_value;
        Key first;
        Value second;
    };

private:
    // Decompilation access view only, with no additional storage or engine code.
    friend class ::RenderFX;
    int find_index(const Key& key) const __attribute__((weak));
    struct table {
        int m_entry_count;
        int m_size_mask;
        // The variable-length entry payload follows this header.
    };
    table* m_table;
};
}

class RenderFX {
public:
    class Controller {
    public:
        Controller();
        ~Controller() __attribute__((long_call));
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
    class SearchIndex {
    public:
        inline ~SearchIndex() __attribute__((noinline, long_call));
        void Init(RenderFX& owner);
        gameswf::character* Find(const char* name);
        void Clear() __attribute__((long_call));
        class Entry;

    private:
        gameswf::hash<gameswf::tu_string, gameswf::array<Entry>*,
                      gameswf::string_hash_functor<gameswf::tu_string> > entries;
    };
    SearchIndex* GetSearchIndex();
    class Event {
    public:
        gameswf::character* character;
        const char* characterName;
        int type;
        unsigned char unknown12[24];
        bool consumed;
    };
    class EventListener {
    public:
        virtual void OnEvent(Event& event) = 0;
        virtual void OnFSCommand(const char* command, const char* args) = 0;
        virtual bool CanHandleEvent(Event& event);
    };
    void FSCommand(const char* command, const char* args);
    void SetEventListener(EventListener* listener);
    void SetInputBehavior(int behavior);
    void SetOrientation(gameswf::orientation_mode orientation);
    static void SetWireFrame(bool enabled);
    int PreloadGlyphs(const char* text, const char* fontName, int size, bool bold, bool italic, gameswf::filter* filter);
    int PreloadGlyphs(unsigned short* glyphs, int count, const char* fontName, int size, bool bold, bool italic, gameswf::filter* filter);
    void InitializeGlyphTextureCache(int width, int height);
    struct InitializationParameters;
    static gameswf::player_context* CreateContext(InitializationParameters& parameters);
    static void Initialize(InitializationParameters& parameters);
    static void Initialize(irr::video::IVideoDriver* driver);
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
    void SetCursor(const char* characterName, int index);
    bool InvokeASCallback(gameswf::character* character, const char* callback);
    bool InvokeASCallback(const char* characterName, const char* callback);
    gameswf::root* GetRoot() const;
    gameswf::root* GetFlashRoot() const;
    void SetTextBufferingEnabled(bool enabled);
    gameswf::character* Find(const char* name);
    gameswf::character* Find(const char* name, gameswf::character* parent);
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
    void SetTexture(const char* name, irr::video::ITexture* texture);
    void SetLocalVariable(const char* characterName, const char* variable, gameswf::as_value& value);
    void SetMember(const char* characterName, const char* member, int value);
    void SetMember(const char* characterName, const char* member, const char* value);
    void SetMember(const char* characterName, const char* member, gameswf::as_value& value);
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
    void FormatHTML(const char* characterName, const char* format, ...);
    void FormatText(const char* characterName, const char* format, ...);
    void FormatHTML(gameswf::character* character, const char* format, ...);
    void FormatText(gameswf::character* character, const char* format, ...);
    void ResetFocus(int flags);
    void SetFocus(gameswf::character* character, int flags);
    void SetFocus(const char* characterName, int flags);

private:
    friend class MenuFX;
    gameswf::array<gameswf::character*> matches;
    bool unknown16;
    SearchIndex searchIndex;
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
