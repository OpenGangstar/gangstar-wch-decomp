OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-analogstick/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .sdk_startup_function_0 0x00326344 : { *sdk-startup-analogstick.o(.text.__tcf_2) }
    .point2d_d0 0x00326374 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN7Point2DIsED0Ev) }
    .point2d_d1 0x00326394 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN7Point2DIsED1Ev) }
    .point2d_vtable 0x004abf88 : { *sdk-startup-analogstick.o(.gnu.linkonce.d.rel.ro._ZTV7Point2DIsE) }
    .sdk_startup_function_1 0x003266e8 : { *sdk-startup-analogstick.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00326754 : { *sdk-startup-analogstick.o(.text._GLOBAL__I__ZN11AnalogStickC2EP7ASpriteii) }
    .sdk_startup_storage_0 0x004b9258 (NOLOAD) : { *sdk-startup-analogstick.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9278 (NOLOAD) : { *sdk-startup-analogstick.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
