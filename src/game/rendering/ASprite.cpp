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
#include "../core/Matrix4.h"
#include "../core/SceneNode.h"
#include "../core/VideoDriver.h"
#include "../app/Application.h"
#include "../persistence/IFileStream.h"

struct SpriteAnimation {
    short count;
    short firstFrame;
    unsigned char unknown4[8];
};

struct SpriteData {
    unsigned char unknown0[32];
    unsigned int modules;
    unsigned char unknown36[4];
    unsigned int frames;
    unsigned int frameModules;
    unsigned int animations;
    unsigned int animationFrames;
};

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
