#ifndef WCH_CORE_A_SPRITE_H
#define WCH_CORE_A_SPRITE_H

// Observed call interface only; allocation extent and internals are unrecovered.
namespace irr {
namespace video { class SColor; }
namespace core { template<class T> class CMatrix4; }
}
struct SpriteBounds { int left, right, top, bottom; };
struct SpriteFrame {
    unsigned char unknown0[4];
    SpriteBounds bounds;
    short firstModule;
    unsigned char unknown22[6];
};
struct SpriteData;
class ASprite {
public:
    static irr::video::SColor* s_global_color;
    static irr::core::CMatrix4<float> s_global_transform;
    const SpriteFrame* GetFrame(int frame) const;
    int GetFrameFromAFrame(int animation, int frame) const;
    const SpriteBounds& GetFrameBoundingRect(int frame) const;
    const unsigned char* GetAFrame(int index) const;
    int GetModuleFromAFrame(int frame, int module) const;
    int GetFrameHeight(int frame) __attribute__((weak));
    int GetFrameWidth(int frame) __attribute__((weak));
    int GetAnimDuration(int animation);
    const SpriteBounds& GetAnimFrameBoundingRect(int animation, int frame) const;
    int GetAFrame(int animation, int frame);
    void PaintAFrame(int animation, int frame, int x, int y, int flags) const;
    void PaintFrame(int frame, int x, int y, int flags) const;

private:
    unsigned char unknown0[4];
    SpriteData* data;
};

#endif
