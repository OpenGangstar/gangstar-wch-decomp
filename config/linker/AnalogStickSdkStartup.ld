OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-analogstick/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
INCLUDE config/linker/ApplicationEventSections.ld
SECTIONS
{
    .input_EvStickMove_D0 0x00326e14 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN11EvStickMoveD0Ev) }
    .input_EvStickMove_D1 0x00326794 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN11EvStickMoveD1Ev) }
    .input_EvStickMove_vtable 0x004abf70 : { *sdk-startup-analogstick.o(.gnu.linkonce.d.rel.ro._ZTV11EvStickMove) }
    .input_EvStickReleased_D0 0x00326cd8 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN15EvStickReleasedD0Ev) }
    .input_EvStickReleased_D1 0x00326d04 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN15EvStickReleasedD1Ev) }
    .input_EvStickReleased_vtable 0x004abf28 : { *sdk-startup-analogstick.o(.gnu.linkonce.d.rel.ro._ZTV15EvStickReleased) }
    .input_EvUpDownStickMove_D0 0x003267dc : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN17EvUpDownStickMoveD0Ev) }
    .input_EvUpDownStickMove_D1 0x00326808 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN17EvUpDownStickMoveD1Ev) }
    .input_EvUpDownStickMove_vtable 0x004abf58 : { *sdk-startup-analogstick.o(.gnu.linkonce.d.rel.ro._ZTV17EvUpDownStickMove) }
    .input_EvUpDownStickReleased_D0 0x00326768 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN21EvUpDownStickReleasedD0Ev) }
    .input_EvUpDownStickReleased_D1 0x003267b8 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN21EvUpDownStickReleasedD1Ev) }
    .input_EvUpDownStickReleased_vtable 0x004abf10 : { *sdk-startup-analogstick.o(.gnu.linkonce.d.rel.ro._ZTV21EvUpDownStickReleased) }
    .input_EvLeftRightStickMove_D0 0x0032687c : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN20EvLeftRightStickMoveD0Ev) }
    .input_EvLeftRightStickMove_D1 0x003268a8 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN20EvLeftRightStickMoveD1Ev) }
    .input_EvLeftRightStickMove_vtable 0x004abf40 : { *sdk-startup-analogstick.o(.gnu.linkonce.d.rel.ro._ZTV20EvLeftRightStickMove) }
    .input_EvLeftRightStickReleased_D0 0x0032682c : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN24EvLeftRightStickReleasedD0Ev) }
    .input_EvLeftRightStickReleased_D1 0x00326858 : { *sdk-startup-analogstick.o(.gnu.linkonce.t._ZN24EvLeftRightStickReleasedD1Ev) }
    .input_EvLeftRightStickReleased_vtable 0x004abef8 : { *sdk-startup-analogstick.o(.gnu.linkonce.d.rel.ro._ZTV24EvLeftRightStickReleased) }
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
