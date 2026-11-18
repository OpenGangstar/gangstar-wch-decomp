glViewport = 0x001c42ec;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/app-android/retail-symbols.ld
SECTIONS {
    .jni_gangstar_nativeaccelerometer 0x002d136c : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeAccelerometer) }
    .jni_gameglsurfaceview_nativeontouch 0x002d13a0 : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeOnTouch) }
    .jni_gamerenderer_nativerender 0x002d13b4 : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeRender) }
    .jni_gameglsurfaceview_nativeresume 0x002d13d8 : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeResume) }
    .jni_gameglsurfaceview_nativepause 0x002d13f4 : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativePause) }
    .jni_gamerenderer_nativeresize 0x002d1420 : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeResize) }
    .jni_gamerenderer_nativeinit 0x002d144c : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeInit) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .app_android_native_key_down 0x002d135c : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyDown) }
    .app_android_native_key_up 0x002d134c : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyUp) }
    .app_android_native_done 0x002d1414 : {
        *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeDone)
    }
    /DISCARD/ : { *(.comment) *(.note*) *(.ARM.attributes) }
}
