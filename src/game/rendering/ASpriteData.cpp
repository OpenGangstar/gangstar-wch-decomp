/*
 * ASpriteData
 *
 * Original file: ASpriteData.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ASpriteData.cpp here, in the order they appear in the library.
 */

// Header prefix and offset-table words observed by ASprite readers.
class ASpriteData {
public:
    ASpriteData();
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
        void Swap();
    };
private:
    unsigned char unknown0[28];
    unsigned int unknown28;
    unsigned int modules;
    unsigned int unknown36;
    unsigned int frames;
    unsigned int frameModules;
    unsigned int animations;
    unsigned int animationFrames;
};
ASpriteData::ASpriteData()
    : unknown28(0), modules(0), unknown36(0), frames(0), frameModules(0), animations(0), animationFrames(0)
{
}

template<class T> inline void swapOnBigEndian(T& value)
{
    int endian = 1;
    if (*reinterpret_cast<char*>(&endian) == 0) {
        char* first = reinterpret_cast<char*>(&value);
        char* last = first + sizeof(T) - 1;
        while (first < last) {
            *first = *last ^ *first;
            *last ^= *first;
            *first ^= *last;
            ++first;
            --last;
        }
    }
}

void ASpriteData::AFrame::Swap()
{
    swapOnBigEndian(unknown0);
    swapOnBigEndian(unknown2);
    swapOnBigEndian(unknown4);
    swapOnBigEndian(unknown6);
}

void ASpriteData::FModule::Swap()
{
    swapOnBigEndian(module);
    swapOnBigEndian(x);
    swapOnBigEndian(y);
}
