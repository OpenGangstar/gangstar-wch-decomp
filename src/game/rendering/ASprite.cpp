/*
 * ASprite
 *
 * Original file: ASprite.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ASprite.cpp here, in the order they appear in the library.
 */

#include "../core/ASprite.h"
#include "../core/ASpriteData.h"
#include "../core/Matrix4.h"
#include "../core/Rct.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/VideoDriver.h"
#include "../app/Application.h"
#include "../persistence/IFileStream.h"
#include "../persistence/FileSystemBase.h"

struct SpriteAnimation {
    short count;
    short firstFrame;
    unsigned char unknown4[8];
};

struct SpriteData {
    unsigned char unknown0[12];
    int frameCount;
    unsigned char unknown16[16];
    unsigned int modules;
    unsigned char unknown36[4];
    unsigned int frames;
    unsigned int frameModules;
    unsigned int animations;
    unsigned int animationFrames;
};

template<class T>
bool Rct<T>::isIntersecting(T x, T y) const
{
    return left <= x && x <= right && top <= y && y <= bottom;
}

template bool Rct<int>::isIntersecting(int, int) const;

int ASprite::GetTransformFromFlags(unsigned int flags)
{
    if (flags & 16) {
        if (flags & 32)
            return 2;
        return 1;
    }
    if (flags & 32)
        return 3;
    return 0;
}

ASprite::ASprite()
    : data(0), ownsData(false), texture(0), unknown32(false), unknown33(true),
      unknown36(0), unknown40(0), unknown44(-1), unknown48(-1)
{
}

ASprite::ASprite(const ASprite& other)
    : data(0), ownsData(false), texture(0), unknown32(false), unknown33(true),
      unknown36(0), unknown40(0), unknown44(-1), unknown48(-1)
{
    data = other.data;
}

void ASprite::_trace(const char*) const {}
void ASprite::_setPtr(unsigned char* bytes) { data = reinterpret_cast<SpriteData*>(bytes); }

ASprite::ASprite(unsigned char* bytes)
    : data(0), ownsData(false), texture(0), unknown32(false), unknown33(true),
      unknown36(0), unknown40(0), unknown44(-1), unknown48(-1)
{
    _setPtr(bytes);
}

int ASprite::GetModuleIdx(const char*) { return -1; }
void ASprite::MakeImage(int, unsigned int) {}

void ASprite::_erasePtr()
{
    if (ownsData) {
        delete[] reinterpret_cast<unsigned char*>(data);
        data = 0;
        ownsData = false;
    }
    data = 0;
}

ASprite::ASprite(IFileStream* stream)
    : data(0), ownsData(true), texture(0), unknown32(false), unknown33(true),
      unknown36(0), unknown40(0), unknown44(-1), unknown48(-1)
{
    unsigned long long savedPosition = stream->tell();
    stream->seek(0);
    unsigned char* bytes = new unsigned char[stream->size()];
    stream->read(bytes, stream->size());
    stream->seek(savedPosition);
    _setPtr(bytes);
}

extern "C" unsigned int strcspn(const char* text, const char* delimiters);
static const char textureExtensionDelimiter[] __attribute__((section(".rodata.sprite_extension"))) = ".";

ASprite::ASprite(const char* name)
    : data(0), ownsData(true), texture(0), unknown32(false), unknown33(true),
      unknown36(0), unknown40(0), unknown44(-1), unknown48(-1)
{
    Application* app = Application::GetInstance();
    IFileStream* stream = app->GetFileSystem()->openResource(name);
    if (!stream)
        return;

    unsigned char* bytes = new unsigned char[stream->size()];
    stream->read(bytes, stream->size());
    app->GetFileSystem()->closeFile(stream);
    _setPtr(bytes);

    if (texture) {
        app->GetDevice()->getVideoDriver()->removeTexture(texture);
        texture = 0;
    }

    char textureName[80];
    int length = strcspn(name + 1, textureExtensionDelimiter);
    int extension = length + 1;
    if (extension >= 0) {
        int i = 0;
        do {
            textureName[i] = name[i];
            ++i;
        } while (i != length + 2);
    }

    textureName[extension + 1] = 'b';
    textureName[extension + 2] = 'm';
    textureName[extension + 3] = 'p';
    textureName[extension + 4] = 0;
    texture = app->GetDevice()->getVideoDriver()->getTexture(textureName);
    if (!texture) {
        textureName[extension + 1] = 'p';
        textureName[extension + 2] = 'n';
        textureName[extension + 3] = 'g';
        textureName[extension + 4] = 0;
        texture = app->GetDevice()->getVideoDriver()->getTexture(textureName);
        if (!texture) {
            textureName[extension + 1] = 't';
            textureName[extension + 2] = 'g';
            textureName[extension + 3] = 'a';
            textureName[extension + 4] = 0;
            texture = app->GetDevice()->getVideoDriver()->getTexture(textureName);
            if (!texture) {
                textureName[extension + 1] = 'p';
                textureName[extension + 2] = 's';
                textureName[extension + 3] = 'd';
                textureName[extension + 4] = 0;
                texture = app->GetDevice()->getVideoDriver()->getTexture(textureName);
            }
        }
    }
}

ASprite::~ASprite()
{
    if (texture) {
        Application::GetInstance()->GetDevice()->getVideoDriver()->removeTexture(texture);
        texture = 0;
    }
    _erasePtr();
}

const unsigned char* ASprite::GetAFrame(int index) const
{
    return reinterpret_cast<const unsigned char*>(data) + data->animationFrames + index * 9;
}

int ASprite::GetFrameHeight(int frame)
{
    return GetFrameBoundingRect(frame).bottom - GetFrameBoundingRect(frame).top;
}

int ASprite::GetFrameWidth(int frame)
{
    return GetFrameBoundingRect(frame).right - GetFrameBoundingRect(frame).left;
}

int ASprite::GetModuleFromAFrame(int frame, int module) const
{
    const char* bytes = reinterpret_cast<const char*>(data);
    const SpriteFrame* entry = reinterpret_cast<const SpriteFrame*>(bytes + (data->frames + frame * 28));
    int index = entry->firstModule + module;
    return *reinterpret_cast<const unsigned short*>(bytes + (data->frameModules + index * 8));
}

const SpriteBounds& ASprite::GetFrameBoundingRect(int frame) const
{
    return GetFrame(frame)->bounds;
}

int ASprite::GetFrameFromAFrame(int animation, int frame) const
{
    const char* bytes = reinterpret_cast<const char*>(data);
    const SpriteAnimation* entry = reinterpret_cast<const SpriteAnimation*>(bytes + (data->animations + animation * 12));
    int index = entry->firstFrame + frame;
    return *reinterpret_cast<const unsigned short*>(bytes + (data->animationFrames + index * 9));
}

const SpriteBounds& ASprite::GetAnimFrameBoundingRect(int animation, int frame) const
{
    return GetFrameBoundingRect(GetFrameFromAFrame(animation, frame));
}

void ASprite::GetFrameMarkers(int frame, int* output) const
{
    const SpriteFrame* entry = GetFrame(frame);
    if (entry->moduleCount <= 0)
        return;
    int* cursor = output;
    for (int i = 0; i < entry->moduleCount; ++i) {
        const SpriteFrameModule* record = GetFModule(entry->firstModule + i);
        if (!(record->flags & 8) && GetModule(record->module)->kind == 5) {
            *cursor++ = record->x;
            *cursor++ = record->y;
        }
    }
}

int ASprite::GetNumberOfFrameMarkers(int frame) const
{
    const SpriteFrame* entry = GetFrame(frame);
    int count = 0;
    for (int i = 0; i < entry->moduleCount; ++i) {
        const SpriteFrameModule* record = GetFModule(entry->firstModule + i);
        if (!(record->flags & 8) && GetModule(record->module)->kind == 5)
            ++count;
    }
    return count;
}

void ASprite::PaintFrame(int frame, int x, int y, int flags) const
{
    const char* bytes = reinterpret_cast<const char*>(data);
    const SpriteFrame* entry = reinterpret_cast<const SpriteFrame*>(bytes + (data->frames + frame * 28));
    short count = entry->moduleCount;
    for (int i = 0; i < count; ++i)
        PaintFModule(frame, i, x, y, flags);
}

void ASprite::PaintAFrame(int animation, int frame, int x, int y, int flags) const
{
    const SpriteData* blob = data;
    unsigned int animations = blob->animations;
    unsigned int frames = blob->animationFrames;
    const char* bytes = reinterpret_cast<const char*>(blob);
    const SpriteAnimation* entry = reinterpret_cast<const SpriteAnimation*>(bytes + (animations + animation * 12));
    const char* record = bytes + frames + (entry->firstFrame + frame) * 9;
    int frameFlags = static_cast<unsigned char>(record[8]) & 15;
    PaintFrame(*reinterpret_cast<const unsigned short*>(record), x, y, flags ^ (frameFlags << 4));
}

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (&ASprite::s_global_transform) irr::core::matrix4;
    }
}

extern "C" {
static void _GLOBAL__I__ZN7ASprite18s_global_transformE() __attribute__((used));
static void _GLOBAL__I__ZN7ASprite18s_global_transformE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

int ASprite::GetAFrameTime(int animation, int frame) const
{
    const char* bytes = reinterpret_cast<const char*>(data);
    const SpriteAnimation* entry = reinterpret_cast<const SpriteAnimation*>(bytes + (data->animations + animation * 12));
    int index = entry->firstFrame + frame;
    return reinterpret_cast<const unsigned short*>(bytes + data->animationFrames + index * 9)[1];
}

extern "C" int strcmp(const char*,const char*);
int ASprite::GetFrameIdx(const char* name)
{
    SpriteData* bytes=data;
    int count=bytes->frameCount;
    for (int index=0;index<count;++index) {
        const SpriteFrame* frames=reinterpret_cast<const SpriteFrame*>(reinterpret_cast<const unsigned char*>(bytes)+bytes->frames);
        const char* frameName=reinterpret_cast<const char*>(bytes)+frames[index].nameOffset;
        if (strcmp(name,frameName)==0)
            return index;
    }
    return -1;
}


const ASpriteData::Anim* ASprite::GetAnim(int index) const
{
    const ASpriteData* spriteData = reinterpret_cast<const ASpriteData*>(data);
    const ASpriteData::Anim* animations = reinterpret_cast<const ASpriteData::Anim*>(
        reinterpret_cast<const unsigned char*>(spriteData) + spriteData->animations);
    return animations + index;
}

const SpriteFrame* ASprite::GetFrame(int index) const
{
    const ASpriteData* blob = reinterpret_cast<const ASpriteData*>(data);
    const ASpriteData::Frame* frames = reinterpret_cast<const ASpriteData::Frame*>(
        reinterpret_cast<const char*>(blob) + blob->frames);
    return reinterpret_cast<const SpriteFrame*>(frames + index);
}


const SpriteFrameModule* ASprite::GetFModule(int index) const
{
    const ASpriteData* blob = reinterpret_cast<const ASpriteData*>(data);
    const ASpriteData::FModule* modules = reinterpret_cast<const ASpriteData::FModule*>(
        reinterpret_cast<const unsigned char*>(blob) + blob->frameModules);
    return reinterpret_cast<const SpriteFrameModule*>(modules + index);
}


const SpriteModule* ASprite::GetModule(int index) const
{
    const ASpriteData* spriteData = reinterpret_cast<const ASpriteData*>(data);
    const ASpriteData::Module* modules = reinterpret_cast<const ASpriteData::Module*>(
        reinterpret_cast<const unsigned char*>(spriteData) + spriteData->modules);
    return reinterpret_cast<const SpriteModule*>(modules + index);
}

const SpriteBounds* ASprite::GetFrameRect(int frameIndex, int rectangle) const
{
    const ASpriteData::Frame* frame = reinterpret_cast<const ASpriteData::Frame*>(GetFrame(frameIndex));
    int index = frame->unknown22 + rectangle;
    const ASpriteData* spriteData = reinterpret_cast<const ASpriteData*>(data);
    const ASpriteData::__rect* rectangles = reinterpret_cast<const ASpriteData::__rect*>(
        reinterpret_cast<const unsigned char*>(spriteData) + spriteData->rectangles);
    return reinterpret_cast<const SpriteBounds*>(rectangles + index);
}

int ASprite::GetAFrame(int animation, int time)
{
    const ASpriteData* blob = reinterpret_cast<const ASpriteData*>(data);
    const ASpriteData::Anim* animations = reinterpret_cast<const ASpriteData::Anim*>(
        reinterpret_cast<const unsigned char*>(blob) + blob->animations);
    const ASpriteData::Anim* entry = animations + animation;
    Application::GetInstance();
    short count = entry->count;
    if (count > 0) {
        const ASpriteData* frameBlob = reinterpret_cast<const ASpriteData*>(data);
        const char* frames = reinterpret_cast<const char*>(frameBlob) + frameBlob->animationFrames;
        int total = 0;
        for (int i = 0; i < count; ++i) {
            total += *reinterpret_cast<const unsigned short*>(frames + (entry->firstFrame + i) * 9 + 2);
            if (__builtin_expect(time < total, 0))
                return i;
        }
    }
    return count - 1;
}


int ASprite::GetAnimDuration(int animation)
{
    const ASpriteData* blob = reinterpret_cast<const ASpriteData*>(data);
    const ASpriteData::Anim* animations = reinterpret_cast<const ASpriteData::Anim*>(
        reinterpret_cast<const unsigned char*>(blob) + blob->animations);
    const ASpriteData::Anim* entry = animations + animation;
    Application::GetInstance();
    int total = 0;
    for (int i = 0; i < entry->count; ++i) {
        const ASpriteData* frameBlob = reinterpret_cast<const ASpriteData*>(data);
        const char* frames = reinterpret_cast<const char*>(frameBlob);
        frames += frameBlob->animationFrames;
        total += *reinterpret_cast<const unsigned short*>(frames + (entry->firstFrame + i) * 9 + 2);
    }
    return total;
}

int ASprite::GetAnimIdx(const char* name)
{
    ASpriteData* bytes=reinterpret_cast<ASpriteData*>(data);
    int count=bytes->animationCount;
    for (int index=0;index<count;++index) {
        const ASpriteData::Anim* animations=reinterpret_cast<const ASpriteData::Anim*>(reinterpret_cast<const unsigned char*>(bytes)+bytes->animations);
        const char* animationName=reinterpret_cast<const char*>(bytes)+animations[index].nameOffset;
        if (strcmp(name,animationName)==0)
            return index;
    }
    return -1;
}

// Native const-member ABI import: receiver followed by four integer arguments.
extern "C" void _ZNK7ASprite11PaintModuleEiiii(const ASprite*, int, int, int, int);

#include "../core/Geometry.h"
namespace irr { namespace core { extern matrix4 IdentityMatrix; } }
namespace {
// File-local views of the private ASprite and ASpriteData fields read by PaintModule.
struct PaintSpriteView {
    void* vtable;
    const char* data;
    bool ownsData;
    unsigned char unknown9[3];
    irr::video::ITexture* texture;
    SpriteBounds bounds;
    bool unknown32;
    bool unknown33;
    unsigned char unknown34[2];
    int unknown36;
    int unknown40;
    int unknown44;
    int unknown48;
};
struct PaintBlobView {
    int counts[7];
    unsigned int images;
    unsigned int modules;
};
// Video driver view naming vtable slot 49, the source-rectangle draw2DImage overload.
class PaintDriverView {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48();
    virtual void draw2DImage(const irr::video::ITexture* texture, const irr::core::rect<int>& destRect,
        const irr::core::rect<int>& sourceRect, const irr::core::rect<int>* clipRect,
        irr::video::SColor* colors, bool useAlphaChannelOfTexture);
};
inline bool spriteHasTexture(const irr::video::ITexture* t) { return t != 0; }
inline int spriteAbsolute(const int& value) { return value < 0 ? -value : value; }
// Irrlicht 1.4.2 rect(position, dimension) constructor body.
inline irr::core::rect<int> spriteDestRect(const irr::core::position2d<int>& pos, const irr::core::dimension2d<int>& size)
{
    return irr::core::rect<int>(pos.X, pos.Y, pos.X + size.Width, pos.Y + size.Height);
}
}

extern "C" void _ZNK7ASprite11PaintModuleEiiii(const ASprite* sprite, int module, int x, int y, int flags)
{
    PaintSpriteView* self = reinterpret_cast<PaintSpriteView*>(const_cast<ASprite*>(sprite));
    if (spriteHasTexture(self->texture)) {
    Application* app = Application::GetInstance();
    const char* bytes = self->data;
    const PaintBlobView* blob = reinterpret_cast<const PaintBlobView*>(bytes);
    const ASpriteData::Module* modules = reinterpret_cast<const ASpriteData::Module*>(bytes + blob->modules);
    const ASpriteData::Module* record = modules + module;
    const SpriteModule* entry = reinterpret_cast<const SpriteModule*>(record);
    int sourceX = record->unknown2;
    int sourceY = record->unknown4;
    int width = entry->width;
    int height = entry->height;
    if (self->unknown32) {
        self->bounds.left = irr::core::min_(x, self->bounds.left);
        self->bounds.top = irr::core::min_(y, self->bounds.top);
        self->bounds.right = irr::core::max_(self->bounds.right, x + width);
        self->bounds.bottom = irr::core::max_(self->bounds.bottom, y + height);
    } else if (entry->kind != 5) {
    if (self->unknown33) { x += 165; y -= 80; }
    int clipWidth = self->unknown44;
    if (clipWidth < 0) clipWidth = width;
    int clipHeight = self->unknown48;
    if (clipHeight < 0) clipHeight = height;
    irr::core::rect<int> clip(x + self->unknown36, y + self->unknown40, x + clipWidth, y + clipHeight);
    irr::core::rect<int> source(sourceX, sourceY, sourceX + width, sourceY + height);
    if (flags & 16) {
        int value = source.LowerRightCorner.X;
        source.LowerRightCorner.X = source.UpperLeftCorner.X;
        source.UpperLeftCorner.X = value;
    }
    if (flags & 32) {
        int value = source.LowerRightCorner.Y;
        source.LowerRightCorner.Y = source.UpperLeftCorner.Y;
        source.UpperLeftCorner.Y = value;
    }
    app->GetDevice()->getVideoDriver()->setTransform(irr::video::ETS_WORLD, ASprite::s_global_transform);
    reinterpret_cast<PaintDriverView*>(app->GetDevice()->getVideoDriver())->draw2DImage(self->texture,
        spriteDestRect(irr::core::position2d<int>(x, y),
            irr::core::dimension2d<int>(spriteAbsolute(source.LowerRightCorner.X - source.UpperLeftCorner.X),
                                        spriteAbsolute(source.LowerRightCorner.Y - source.UpperLeftCorner.Y))),
        source, &clip, ASprite::s_global_color, true);
    app->GetDevice()->getVideoDriver()->setTransform(irr::video::ETS_VIEW, irr::core::IdentityMatrix);
    }
    }
}

void ASprite::PaintFModule(int frame, int module, int x, int y, int flags) const
{
    const ASpriteData* blob = reinterpret_cast<const ASpriteData*>(data);
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(blob);
    const ASpriteData::Frame* entry = reinterpret_cast<const ASpriteData::Frame*>(
        bytes + (blob->frames + static_cast<unsigned int>(frame) * sizeof(ASpriteData::Frame)));
    int index = entry->firstModule + module;
    const ASpriteData::FModule* frameModules = reinterpret_cast<const ASpriteData::FModule*>(bytes + blob->frameModules);
    const ASpriteData::FModule* record = frameModules + index;
    unsigned int moduleFlags = record->flags;
    unsigned int moduleIndex = record->module;
    if (moduleFlags & 8) {
        PaintFrame(moduleIndex, x + record->x, y + record->y, flags ^ ((moduleFlags & 15) << 4));
    } else {
        int flipX = flags & 16;
        int px = flipX ? x - record->x : x + record->x;
        int flipY = flags & 32;
        int py = flipY ? y - record->y : y + record->y;
        if (flipX) {
            const ASpriteData::Module* shape = reinterpret_cast<const ASpriteData::Module*>(
                bytes + (blob->modules + moduleIndex * sizeof(ASpriteData::Module)));
            px -= shape->width;
        }
        if (flipY) {
            const ASpriteData::Module* shape = reinterpret_cast<const ASpriteData::Module*>(
                bytes + (blob->modules + moduleIndex * sizeof(ASpriteData::Module)));
            py -= shape->height;
        }
        _ZNK7ASprite11PaintModuleEiiii(this, moduleIndex, px, py, flags ^ ((moduleFlags & 15) << 4));
    }
}

namespace {
// File-local view of the private ASpriteData section offsets read by GetPixelInfoInFrame.
struct PixelBlobView {
    int counts[7];
    unsigned int images;
    unsigned int modules;
    unsigned int rectangles;
    unsigned int frames;
    unsigned int frameModules;
};
}

extern "C" bool _ZN7ASprite19GetPixelInfoInFrameEiiiRiS0_(ASprite* sprite, int frame, int x, int y, int& moduleIndex, int& color)
{
    PaintSpriteView* self = reinterpret_cast<PaintSpriteView*>(sprite);
    const PixelBlobView* blob = reinterpret_cast<const PixelBlobView*>(self->data);
    const char* frames = reinterpret_cast<const char*>(blob);
    frames += blob->frames;
    const ASpriteData::Frame* entry = reinterpret_cast<const ASpriteData::Frame*>(frames) + frame;
    for (int i = 0; i < entry->moduleCount; ++i) {
        const PixelBlobView* recordBlob = reinterpret_cast<const PixelBlobView*>(self->data);
        const char* records = reinterpret_cast<const char*>(recordBlob);
        records += recordBlob->frameModules;
        const int index = entry->firstModule + i;
        const ASpriteData::FModule* record = reinterpret_cast<const ASpriteData::FModule*>(records) + index;
        const char* modules = reinterpret_cast<const char*>(recordBlob);
        modules += recordBlob->modules;
        const ASpriteData::Module* module = reinterpret_cast<const ASpriteData::Module*>(modules) + record->module;
        if (module->kind == 0) {
            ASpriteData::__rect rect; rect.left = 0; rect.right = 0; rect.top = 0; rect.bottom = 0;
            rect.left = record->x; rect.right = record->x + module->width;
            rect.top = record->y; rect.bottom = record->y + module->height;
            if (rect.isIntersecting(x, y)) {
                int imageIndex = module->unknown1;
                const PixelBlobView* imageBlob = reinterpret_cast<const PixelBlobView*>(self->data);
                const char* images = reinterpret_cast<const char*>(imageBlob);
                images += imageBlob->images;
                const ASpriteData::Image* image = reinterpret_cast<const ASpriteData::Image*>(images) + imageIndex;
                int row = image->unknown0 * (module->unknown4 - record->y + y);
                int column = module->unknown2 - record->x;
                const unsigned char pixel = (reinterpret_cast<const unsigned char*>(imageBlob) + image->unknown16 + (x + row))[column];
                moduleIndex = index;
                const char* bytes = self->data;
                const char* palette = bytes;
                palette += image->unknown12;
                unsigned int paletteOffset = reinterpret_cast<const unsigned int*>(palette)[1];
                color = reinterpret_cast<const unsigned int*>(bytes + paletteOffset)[pixel] & 0x00ffffffu;
                return true;
            }
        }
    }
    return false;
}
