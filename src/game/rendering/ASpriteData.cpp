#include "../core/NativeStdio.h"
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


namespace { struct Palette { unsigned int colorCount, colors; }; }

void ASpriteData::Debug()
{
        printf("%d images, offset=%d \n", imageCount, 0);
        printf("%m_images offset=%d \n", 28);
    for (int i = 0; i < imageCount; ++i) {
        Image* img = reinterpret_cast<Image*>(reinterpret_cast<char*>(this) + images) + i;
        printf("%m_images=%x, img=%x \n", &images, img);
        printf(" img.width : %i, offset=%d \n", img->unknown0, 0);
        printf(" img.height : %i, offset=%d \n", img->unknown4, 4);
        printf(" img.palCount : %i, offset=%d \n", img->unknown8, 8);
        printf(" img.palettes : %i, offset=%d \n", img->unknown12, 12);
        printf(" img.data : %i, offset=%d \n", img->unknown16, 16);
        for (unsigned int j = 0; j < img->unknown8; ++j) {
            Palette* pal = reinterpret_cast<Palette*>(reinterpret_cast<char*>(this) + img->unknown12) + j;
        printf("  Pal.colorCount : %i, offset=%d \n", pal->colorCount, __builtin_offsetof(Palette, colorCount));
        printf("  Pal.colors : %i, offset=%d \n", pal->colors, __builtin_offsetof(Palette, colors));
        }
    }
        printf("%d modules, offset=%d \n", moduleCount, 4);
        printf("Size of Module =%d\n", sizeof(Module));
    for (int i = 0; i < moduleCount; ++i) {
        Module* mod = reinterpret_cast<Module*>(reinterpret_cast<char*>(this) + modules) + i;
        printf(" mod.type : %i\n", mod->kind);
        printf(" mod.image : %i\n", mod->unknown1);
        printf(" mod.x : %i\n", mod->unknown2);
        printf(" mod.y : %i\n", mod->unknown4);
        printf(" mod.width : %i\n", mod->width);
        printf(" mod.height : %i\n", mod->height);
        printf("mod=%x \n", mod);
        int j = 0;
        unsigned char* bytes = reinterpret_cast<unsigned char*>(mod);
        for (; j < sizeof(Module); ++j)
        printf("%x2 ", bytes[j]);
        printf("\n");
    }
        printf("%d frame rects, offset=%d \n", rectangleCount, 8);
    for (int i = 0; i < rectangleCount; ++i) {
        __rect* rc = reinterpret_cast<__rect*>(reinterpret_cast<char*>(this) + rectangles) + i;
        printf(" rc.left : %i\n", rc->left);
        printf(" rc.right : %i\n", rc->right);
        printf(" rc.top : %i\n", rc->top);
        printf(" rc.bottom : %i\n", rc->bottom);
    }
        printf("%d frames\n", frameCount);
    for (int i = 0; i < frameCount; ++i) {
        Frame* frame = reinterpret_cast<Frame*>(reinterpret_cast<char*>(this) + frames) + i;
        printf(" frame.numFModules : %i\n", frame->moduleCount);
        printf(" frame.numRects : %i\n", frame->unknown2);
        printf(" frame.rcBound.left : %i\n", frame->bounds.left);
        printf(" frame.rcBound.right : %i\n", frame->bounds.right);
        printf(" frame.rcBound.top : %i\n", frame->bounds.top);
        printf(" frame.rcBound.bottom : %i\n", frame->bounds.bottom);
        printf(" frame.startFModule : %i\n", frame->firstModule);
        printf(" frame.startRect : %i\n", frame->unknown22);
        printf(" frame desc : %s\n", reinterpret_cast<char*>(this) + frame->nameOffset);
    }
        printf("%d fmodules\n", frameModuleCount);
    for (int i = 0; i < frameModuleCount; ++i) {
        FModule* fmod = reinterpret_cast<FModule*>(reinterpret_cast<char*>(this) + frameModules) + i;
        printf(" fmod.moduleIndex : %i\n", fmod->module);
        printf(" fmod.ox : %i\n", fmod->x);
        printf(" fmod.oy : %i\n", fmod->y);
        printf(" fmod.palette : %i\n", fmod->unknown6);
        printf(" fmod.flags : %i\n", fmod->flags);
    }
        printf("%d anims\n", animationCount);
    for (int i = 0; i < animationCount; ++i) {
        Anim* anim = reinterpret_cast<Anim*>(reinterpret_cast<char*>(this) + animations) + i;
        printf(" anim.numFrames : %i\n", anim->count);
        printf(" anim.startFrame : %i\n", anim->firstFrame);
        printf(" anim.duration : %i\n", anim->unknown4);
        printf(" anim desc : %s\n", reinterpret_cast<char*>(this) + anim->nameOffset);
    }
        printf("%d aframes\n", animationFrameCount);
    // Native Debug uses nine bytes per animation-frame, unlike Swap (ten).
    for (int i = 0; i < animationFrameCount; ++i) {
        AFrame* aframe = reinterpret_cast<AFrame*>(reinterpret_cast<char*>(this) + animationFrames + i * 9);
        printf(" aframe.frame : %i\n", aframe->unknown0);
        printf(" aframe.time : %i\n", aframe->unknown2);
        printf(" aframe.ox : %i\n", static_cast<short>(aframe->unknown4));
        printf(" aframe.oy : %i\n", static_cast<short>(aframe->unknown6));
        printf(" aframe.flags : %i\n", aframe->flags);
    }
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
