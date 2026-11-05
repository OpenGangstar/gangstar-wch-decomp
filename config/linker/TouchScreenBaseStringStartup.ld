OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-touchscreenbase/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_i2f = 0x001c41e4;
__aeabi_fcmpge = 0x001c4364;
__aeabi_fcmple = 0x001c43ac;
__aeabi_dadd = 0x001c4394;
__aeabi_dcmplt = 0x001c4244;
__aeabi_atexit = 0x001c494c;
INCLUDE config/linker/TouchScreenBaseSections.ld
SECTIONS
{
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
