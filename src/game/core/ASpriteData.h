#ifndef WCH_CORE_ASPRITE_DATA_H
#define WCH_CORE_ASPRITE_DATA_H
#include "ASprite.h"
class ASpriteData {
    friend class ASprite;
public:
    ASpriteData();
    void Debug();
    void Swap();
    struct __rect {
        int left, right, top, bottom;
        bool isIntersecting(int, int) __attribute__((weak));
    };
    struct Frame {
        short moduleCount, unknown2;
        SpriteBounds bounds;
        short firstModule, unknown22;
        unsigned int nameOffset;
        void Swap();
    };
    // Twelve-byte animation record; final word is the relative name offset.
    struct Anim {
        short count, firstFrame;
        unsigned int unknown4, nameOffset;
        void Swap();
    };
    // Twenty-byte image record; the final word is untouched by Swap.
    struct Image {
        unsigned int unknown0, unknown4, unknown8, unknown12, unknown16;
        void Swap();
    };
    struct Module {
        unsigned char kind, unknown1;
        short unknown2, unknown4, width, height;
        void Swap();
    };
    // Same eight-byte module record read by ASprite::GetFModule.
    struct FModule {
        unsigned short module;
        short x, y;
        unsigned char unknown6, flags;
        void Swap();
    };
    // Four 16-bit values visited by the retail AFrame endian conversion.
    struct AFrame {
        unsigned short unknown0, unknown2, unknown4, unknown6;
        unsigned char flags;
        void Swap();
    };
private:
    int imageCount, moduleCount, rectangleCount, frameCount;
    int frameModuleCount, animationCount, animationFrameCount;
    unsigned int images;
    unsigned int modules;
    unsigned int rectangles;
    unsigned int frames;
    unsigned int frameModules;
    unsigned int animations;
    unsigned int animationFrames;
};
#endif
