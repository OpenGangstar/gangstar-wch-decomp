/*
 * CIrrDevicePS3
 *
 * Original file: CIrrDevicePS3.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CIrrDevicePS3.cpp here, in the order they appear in the library.
 */

#include "../app/NativeJNI.h"
extern "C" {
extern JNIEnv* mEnv;
void Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeGetJNIEnv(
    JNIEnv* environment, jclass unusedClass)
{
    mEnv=environment;
}
}
