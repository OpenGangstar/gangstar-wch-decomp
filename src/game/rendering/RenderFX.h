#ifndef WCH_RENDERING_RENDER_FX_H
#define WCH_RENDERING_RENDER_FX_H

namespace gameswf {
class character;

template <typename T>
class array {
public:
    void resize(int size) __attribute__((weak));
    T* elements;
    int size;
    int capacity;
};
}

class RenderFX {
public:
    class Event;
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

private:
    void CollectCharacters(gameswf::character* parent, const char* name, int flags);
};

#endif
