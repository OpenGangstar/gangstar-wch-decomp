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
