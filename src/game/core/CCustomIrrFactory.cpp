/*
 * CCustomIrrFactory
 *
 * Original file: CCustomIrrFactory.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CCustomIrrFactory.cpp here, in the order they appear in the library.
 */

#include "CCustomIrrFactory.h"
#include "PlacementNew.h"
#include "FactoryProducts.h"
#include "CCustomFileSystem.h"

inline irr::io::IFileSystem* CCustomIrrFactor::createFileSystem()
{
    return new CCustomFileSystem;
}

inline irr::scene::ISceneManager* CCustomIrrFactor::createSceneManager(
    irr::video::IVideoDriver* driver, irr::io::IFileSystem* fileSystem,
    irr::gui::ICursorControl* cursor, irr::gui::IGUIEnvironment* environment)
{
    return reinterpret_cast<irr::scene::ISceneManager*>(
        new CCustomSceneManager(driver, fileSystem, cursor, 0, environment));
}

extern void* __dso_handle;
extern "C" int __aeabi_atexit(void*, void (*)(void*), void*);
extern "C" {
static void __tcf_0() __attribute__((used));
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        new (&customFactory) CCustomIrrFactor();
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I_customFactory() __attribute__((used));
static void _GLOBAL__I_customFactory()
{
    __static_initialization_and_destruction_0(1, 65535);
}

static void __tcf_0()
{
    customFactory.~CCustomIrrFactor();
}
}
