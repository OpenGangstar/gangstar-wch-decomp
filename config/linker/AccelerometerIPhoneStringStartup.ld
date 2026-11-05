OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-accelerometeriphone/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .accelerometer_moved 0x0034d854 : { *string-startup-accelerometeriphone.o(.text._ZN19AccelerometerIPhone5movedEfff) }
    .string_startup_function_0 0x0034d824 : { *string-startup-accelerometeriphone.o(.text.__tcf_0) }
    .string_startup_function_1 0x0034d8d4 : { *string-startup-accelerometeriphone.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0034d92c : { *string-startup-accelerometeriphone.o(.text._GLOBAL__I__ZN19AccelerometerIPhoneC2Ev) }
    .string_startup_storage_0 0x004bc10c (NOLOAD) : { *string-startup-accelerometeriphone.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
