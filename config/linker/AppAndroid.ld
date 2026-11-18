OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/app-android/retail-symbols.ld
SECTIONS {
    .app_android_native_key_down 0x002d135c : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyDown) }
    .app_android_native_key_up 0x002d134c : { *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyUp) }
    .app_android_native_done 0x002d1414 : {
        *app-android.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeDone)
    }
    /DISCARD/ : { *(.comment) *(.note*) *(.ARM.attributes) }
}
