/*
 * CCustomMaterialRenderer_VERTEX_COLOR_ALPHA
 *
 * Original file: CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_0()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE() __attribute__((used));
static void _GLOBAL__I__ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}


// The remaining renderer virtual methods and vtable are retail imports.
class CCustomMaterialRenderer_VERTEX_COLOR_ALPHA {
public:
    virtual ~CCustomMaterialRenderer_VERTEX_COLOR_ALPHA();
    virtual bool isTransparent() const;
    virtual unsigned int getVertexAttributeMask() const;
};

bool CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::isTransparent() const
{
    return false;
}

unsigned int CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::getVertexAttributeMask() const
{
    return 0x15u;
}
