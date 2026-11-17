#ifndef WCH_RENDERING_RENDER_FX_H
#define WCH_RENDERING_RENDER_FX_H

namespace gameswf {
class character;
class render_state;
class root;

template <typename T>
class array {
public:
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
    class Event;
    class EventListener;
    void SetEventListener(EventListener* listener);
    void SetInputBehavior(int behavior);
    void SetControllerEnabled(int index, bool enabled);
    void SetContext(gameswf::character* character);
    gameswf::character* GetRoot() const;
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
    void CollectCharacters(gameswf::character* parent, const char* name, int flags);
};

#endif
