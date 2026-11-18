OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/jni-gangstar/retail-symbols.ld
SECTIONS {
 .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
 .verification 0x00600000 : { *retail-got.o(.text) }
}

INCLUDE config/linker/JNIGangstarBrowserSections.ld
ASSERT(SIZEOF(.gangstar_class)==4,"JNI Gangstar class cache extent");
ASSERT(SIZEOF(.gangstar_browser_method)==4,"JNI browser method cache extent");

ASSERT(SIZEOF(.gangstar_notify_method)==4,"JNI notify method cache extent");

ASSERT(SIZEOF(.gangstar_exit_method)==4,"JNI exit method cache extent");

ASSERT(SIZEOF(.gangstar_phone_method)==4,"JNI phone method cache extent");

ASSERT(SIZEOF(.gangstar_unlock_method)==4,"JNI unlock method cache extent");

ASSERT(SIZEOF(.gangstar_version_method)==4,"JNI version method cache extent");

ASSERT(SIZEOF(.gangstar_launch_method)==4,"JNI launch method cache extent");
