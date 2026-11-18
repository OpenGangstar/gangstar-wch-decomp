/*
 * TargetMarker
 *
 * Original file: TargetMarker.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of TargetMarker.cpp here, in the order they appear in the library.
 */

#include "TargetMarker.h"

TargetMarker::~TargetMarker()
{
}

void TargetMarker::init(ASprite* value, int marker, int target)
{
    sprite = value;
    markerFrame = marker;
    targetFrame = target;
}

TargetMarker::TargetMarker()
    : sprite(0), depth(0.0f), offsetX(0), offsetY(0), enabled(true)
{
}

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_3()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN12TargetMarkerC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN12TargetMarkerC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "../app/Application.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/ASprite.h"
#include "../core/Matrix4.h"
void TargetMarker::draw() const
{
    if (enabled) {
        Application::GetInstance()->GetDevice()->getVideoDriver();
        const SpriteFrame* targetSpriteFrame=sprite->GetFrame(targetFrame);
        const SpriteFrameModule* targetFrameModule=sprite->GetFModule(targetSpriteFrame->firstModule);
        const SpriteModule* targetModule=sprite->GetModule(targetFrameModule->module);
            int x=offsetX;
            int y=offsetY;
            irr::core::matrix4 transform;
            transform.setRotationRadians(irr::core::vector3d<float>(0,0,depth));
            irr::core::vector3d<float> translation(-x,-y,0);
            transform.rotateVect(translation);
            translation = translation + irr::core::vector3d<float>(x,y,0);
            transform.setTranslation(translation);
            ASprite::s_global_transform=transform;
        sprite->PaintFrame(targetFrame,offsetX+2-(targetModule->width>>1),offsetY+2-(targetModule->height>>1),0);
        const SpriteFrame* markerSpriteFrame=sprite->GetFrame(markerFrame);
        const SpriteFrameModule* markerFrameModule=sprite->GetFModule(markerSpriteFrame->firstModule);
        const SpriteModule* markerModule=sprite->GetModule(markerFrameModule->module);
            int y2;
            int x2;
            x2=offsetX;
            y2=offsetY;
            irr::core::matrix4 transform2;
            transform2.setRotationRadians(irr::core::vector3d<float>(0,0,depth));
            irr::core::vector3d<float> translation2(-x2,-y2,0);
            transform2.rotateVect(translation2);
            translation2 = translation2 + irr::core::vector3d<float>(x2,y2,0);
            transform2.setTranslation(translation2);
            ASprite::s_global_transform=transform2;
        sprite->PaintFrame(markerFrame,offsetX-(markerModule->width>>1),offsetY-(markerModule->height>>1),0);
        ASprite::s_global_transform=irr::core::matrix4();
    }
}
