/*
 * ASpriteData
 *
 * Original file: ASpriteData.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ASpriteData.cpp here, in the order they appear in the library.
 */

#include "../core/ASprite.h"

// Header prefix and offset-table words observed by ASprite readers.
#include "../core/ASpriteData.h"

ASpriteData::ASpriteData()
    : images(0), modules(0), rectangles(0), frames(0), frameModules(0), animations(0), animationFrames(0)
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

void ASpriteData::Module::Swap()
{
    if (kind == 0) {
        swapOnBigEndian(unknown2);
        swapOnBigEndian(unknown4);
    }
    swapOnBigEndian(width);
    swapOnBigEndian(height);
}


void ASpriteData::Anim::Swap()
{
    swapOnBigEndian(count);
    swapOnBigEndian(firstFrame);
    swapOnBigEndian(unknown4);
    swapOnBigEndian(nameOffset);
}

void ASpriteData::Image::Swap()
{
    swapOnBigEndian(unknown0);
    swapOnBigEndian(unknown4);
    swapOnBigEndian(unknown8);
    swapOnBigEndian(unknown12);
}

void ASpriteData::Frame::Swap()
{
    swapOnBigEndian(moduleCount);
    swapOnBigEndian(unknown2);
    swapOnBigEndian(bounds.left);
    swapOnBigEndian(bounds.right);
    swapOnBigEndian(bounds.top);
    swapOnBigEndian(bounds.bottom);
    swapOnBigEndian(firstModule);
    swapOnBigEndian(unknown22);
    swapOnBigEndian(nameOffset);
}


#include "../core/Rct.h"
template<> bool Rct<int>::isIntersecting(int,int) const __attribute__((weak));
bool ASpriteData::__rect::isIntersecting(int x,int y)
{
    return Rct<int>(left,top,right,bottom).isIntersecting(x,y);
}


void ASpriteData::Swap()
{
    if (imageCount > 65534) {
        swapOnBigEndian(imageCount);
        swapOnBigEndian(moduleCount);
        swapOnBigEndian(rectangleCount);
        swapOnBigEndian(frameCount);
        swapOnBigEndian(frameModuleCount);
        swapOnBigEndian(animationCount);
        swapOnBigEndian(animationFrameCount);
        swapOnBigEndian(images);
        swapOnBigEndian(modules);
        swapOnBigEndian(rectangles);
        swapOnBigEndian(frames);
        swapOnBigEndian(frameModules);
        swapOnBigEndian(animations);
        swapOnBigEndian(animationFrames);
        for (int i = 0; i < imageCount; ++i)
            reinterpret_cast<Image*>(reinterpret_cast<char*>(this) + images)[i].Swap();
        for (int i = 0; i < moduleCount; ++i)
            reinterpret_cast<Module*>(reinterpret_cast<char*>(this) + modules)[i].Swap();
        for (int i = 0; i < rectangleCount; ++i) {
            __rect& rectangle = reinterpret_cast<__rect*>(reinterpret_cast<char*>(this) + rectangles)[i];
            swapOnBigEndian(rectangle.left);
            swapOnBigEndian(rectangle.right);
            swapOnBigEndian(rectangle.top);
            swapOnBigEndian(rectangle.bottom);
        }
        for (int i = 0; i < frameCount; ++i)
            reinterpret_cast<Frame*>(reinterpret_cast<char*>(this) + frames)[i].Swap();
        for (int i = 0; i < frameModuleCount; ++i)
            reinterpret_cast<FModule*>(reinterpret_cast<char*>(this) + frameModules)[i].Swap();
        for (int i = 0; i < animationCount; ++i)
            reinterpret_cast<Anim*>(reinterpret_cast<char*>(this) + animations)[i].Swap();
        for (int i = 0; i < animationFrameCount; ++i)
            reinterpret_cast<AFrame*>(reinterpret_cast<char*>(this) + animationFrames)[i].Swap();
    }
}
