#ifndef WCH_CORE_A_SPRITE_H
#define WCH_CORE_A_SPRITE_H

// Observed call interface only; allocation extent and internals are unrecovered.
namespace irr {
namespace video { class SColor; class ITexture; }
namespace core { template<class T> class CMatrix4; }
}
struct SpriteBounds { int left, right, top, bottom; };
struct SpriteFrame {
    short moduleCount;
    unsigned char unknown2[2];
    SpriteBounds bounds;
    short firstModule;
    unsigned char unknown22[6];
};
struct SpriteData;
struct SpriteFrameModule {
    unsigned short module;
    short x;
    short y;
    unsigned char unknown6;
    unsigned char flags;
};

struct SpriteModule {
    unsigned char kind;
    unsigned char unknown1[5];
    short width;
    short height;
};
class IFileStream;
class ASprite {
public:
    ASprite();
    ASprite(const ASprite& other);
    ASprite(unsigned char* bytes);
    ASprite(IFileStream* stream);
    ASprite(const char* name);
    virtual ~ASprite();
    void _trace(const char* text) const;
    void _setPtr(unsigned char* bytes);
    void _erasePtr();
    int GetModuleIdx(const char* name);
    void MakeImage(int image, unsigned int flags);
    static irr::video::SColor* s_global_color;
    static irr::core::CMatrix4<float> s_global_transform;
    static int GetTransformFromFlags(unsigned int flags);
    const SpriteModule* GetModule(int module) const;
    const SpriteFrameModule* GetFModule(int index) const;
    void GetFrameMarkers(int frame, int* output) const;
    int GetNumberOfFrameMarkers(int frame) const;
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
    void PaintFModule(int frame, int module, int x, int y, int flags) const;
    void PaintFrame(int frame, int x, int y, int flags) const;

private:
    friend class Gauge;
    void setClip(int left, int top, int right, int bottom)
    {
        unknown36 = left;
        unknown40 = top;
        unknown44 = right;
        unknown48 = bottom;
    }

    SpriteData* data;
    bool ownsData;
    unsigned char unknown9[3];
    irr::video::ITexture* texture;
    unsigned char unknown16[16];
    bool unknown32;
    bool unknown33;
    unsigned char unknown34[2];
    int unknown36;
    int unknown40;
    int unknown44;
    int unknown48;
};

#endif
