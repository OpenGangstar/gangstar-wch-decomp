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
