OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-accelerometerbase/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .accelerometer_update 0x0034d420 : { *sdk-startup-accelerometerbase.o(.text._ZN17AccelerometerBase6updateEd) }
    .accelerometer_clear 0x0034d40c : { *sdk-startup-accelerometerbase.o(.text._ZN17AccelerometerBase5clearEv) }
    .sdk_startup_function_0 0x0034d42c : { *sdk-startup-accelerometerbase.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0034d5b8 : { *sdk-startup-accelerometerbase.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0034d624 : { *sdk-startup-accelerometerbase.o(.text._GLOBAL__I__ZN17AccelerometerBaseC2Ev) }
    .sdk_startup_storage_0 0x004bc0e0 (NOLOAD) : { *sdk-startup-accelerometerbase.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc100 (NOLOAD) : { *sdk-startup-accelerometerbase.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
