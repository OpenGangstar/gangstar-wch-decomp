OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/jni-cache-environment/retail-symbols.ld
SECTIONS {
 .jni_cache_environment 0x002d1334 : { *jni-cache-environment.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeGetJNIEnv) }
 .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
 .verification 0x00600000 : { *retail-got.o(.text) }
 /DISCARD/ : { *(.comment) *(.note*) *(.ARM.attributes) }
}
