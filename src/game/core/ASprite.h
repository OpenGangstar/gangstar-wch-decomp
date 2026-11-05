#ifndef WCH_CORE_A_SPRITE_H
#define WCH_CORE_A_SPRITE_H

// Observed call interface only; allocation extent and internals are unrecovered.
namespace irr { namespace video { class SColor; } }
class ASprite {
public:
    static irr::video::SColor* s_global_color;
    int GetFrameWidth(int frame) __attribute__((weak));
    int GetAnimDuration(int animation);
    int GetAFrame(int animation, int frame);
    void PaintAFrame(int animation, int frame, int x, int y, int flags) const;
    void PaintFrame(int frame, int x, int y, int flags) const;
};

#endif
