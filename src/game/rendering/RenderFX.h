#ifndef WCH_RENDERING_RENDER_FX_H
#define WCH_RENDERING_RENDER_FX_H

namespace gameswf { class character; }

class RenderFX {
public:
    class Event;
    gameswf::character* Find(const char* name);
    bool PlayAnim(gameswf::character* character, const char* label, int flags);
    bool PlayAnim(const char* characterName, const char* label, int flags);
    bool GotoFrame(gameswf::character* character, const char* label, bool play);
    void GotoFrame(gameswf::character* character, int frame, bool play);
    bool GotoFrame(const char* characterName, const char* label, bool play);
    void GotoFrame(const char* characterName, int frame, bool play);
};

#endif
