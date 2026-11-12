/*
 * Transformation
 *
 * Original file: Transformation.cpp
 * Area:          characters
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Transformation.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "Transformation.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
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
    }
}

extern "C" {
static void _GLOBAL__I__ZN14TransformationC2Ei() __attribute__((used));
static void _GLOBAL__I__ZN14TransformationC2Ei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

unsigned short Transformation::GetMatID() const
{
    return materialID;
}

unsigned short Transformation::GetTriID() const
{
    return triangleID;
}

void Transformation::SetRotation(const irr::core::quaternion& value)
{
    rotation = value;
}

const irr::core::quaternion& Transformation::GetRotation() const
{
    return rotation;
}

irr::core::vector3d<float> Transformation::GetPosition() const
{
    return position;
}

void Transformation::SetPosition(const irr::core::vector3d<float>& value)
{
    position = value;
}

irr::core::vector3d<float> Transformation::GetRight() const
{
    return rotation * irr::core::vector3d<float>(-1.0f, 0.0f, 0.0f);
}

irr::core::vector3d<float> Transformation::GetFront() const
{
    return rotation * irr::core::vector3d<float>(0.0f, -1.0f, 0.0f);
}

void Transformation::SetRotation(const irr::core::vector3d<float>& value)
{
    rotation = irr::core::quaternion(value * 0.017453292f);
}

void Transformation::dropSceneNode()
{
    LevelObject::dropSceneNode();
}

Transformation::Transformation(int type) : LevelObject(type)
{
}

Transformation::~Transformation()
{
}

irr::scene::ISceneNode* Transformation::grabSceneNode(int id, void*** parameters)
{
    LevelObject::grabSceneNode(id, parameters);
    irr::scene::ISceneNode* node = sceneNode;
    node->setPosition(GetPosition());
    node->setRotation(GetRotation());
    node->updateAbsolutePosition(false);
    return node;
}
