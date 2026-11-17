OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-accelerometerwin32/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__cxa_pure_virtual = 0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .accelerometer_win32_set_wide 0x0034d940 : { *sdk-startup-accelerometerwin32.o(.text._ZN18AccelerometerWin327setWideEb) }
    .accelerometer_win32_dtor 0x0034dad8 : { *sdk-startup-accelerometerwin32.o(.text._ZN18AccelerometerWin32D1Ev .text._ZN18AccelerometerWin32D2Ev) }
    .accelerometer_win32_delete 0x0034da8c : { *sdk-startup-accelerometerwin32.o(.text._ZN18AccelerometerWin32D0Ev) }
    .accelerometer_win32_dtor_thunk 0x0034dac4 : { *sdk-startup-accelerometerwin32.o(.text._ZThn76_N18AccelerometerWin32D1Ev) }
    .accelerometer_win32_delete_thunk 0x0034da78 : { *sdk-startup-accelerometerwin32.o(.text._ZThn76_N18AccelerometerWin32D0Ev) }
    .accelerometer_win32_vtable 0x004ad490 : { *sdk-startup-accelerometerwin32.o(.data.rel.ro._ZTV18AccelerometerWin32) }
    .win32_receiver_d0 0x002537d8 : { *sdk-startup-accelerometerwin32.o(.gnu.linkonce.t._ZN3irr14IEventReceiverD0Ev) }
    .win32_receiver_d1 0x002537f8 : { *sdk-startup-accelerometerwin32.o(.gnu.linkonce.t._ZN3irr14IEventReceiverD1Ev) }
    .win32_receiver_vtable 0x00488968 : { *sdk-startup-accelerometerwin32.o(.gnu.linkonce.d.rel.ro._ZTVN3irr14IEventReceiverE) }
    .accelerometer_win32_constructor 0x0034d9bc : { *sdk-startup-accelerometerwin32.o(.text._ZN18AccelerometerWin32C1Ev .text._ZN18AccelerometerWin32C2Ev) }
    .sdk_startup_function_0 0x0034d98c : { *sdk-startup-accelerometerwin32.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0034d9f8 : { *sdk-startup-accelerometerwin32.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0034da64 : { *sdk-startup-accelerometerwin32.o(.text._GLOBAL__I__ZN18AccelerometerWin32C2Ev) }
    .sdk_startup_storage_0 0x004bc12c (NOLOAD) : { *sdk-startup-accelerometerwin32.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc14c (NOLOAD) : { *sdk-startup-accelerometerwin32.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
