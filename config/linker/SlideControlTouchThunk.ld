__aeabi_i2f = 0x1c41e4; __aeabi_fsub = 0x1c4328; __aeabi_fdiv = 0x1c4520; __aeabi_fcmpgt = 0x1c419c; printf = 0x1c4058;
PROVIDE(__aeabi_fadd = 0x001c4154);
INCLUDE config/linker/ApplicationEventSections.ld
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/slidecontrol-touch-thunk/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_f2iz = 0x001c44cc;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
 .slidecontrol_process_thunk 0x0032b650 : { *sdk-startup-slidecontrol.o(.text._ZThn8_N12SlideControl12processTouchEl) }
 .slidecontrol_nonmatching_process 0x0032b664 : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControl12processTouchEl) }
 .slidecontrol_invalid_touch 0x00424d68 : { *sdk-startup-slidecontrol.o(.rodata.slide_invalid_touch) }
 .move_up_D0 0x003267dc : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN17EvUpDownStickMoveD0Ev) }
 .move_up_D1 0x00326808 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN17EvUpDownStickMoveD1Ev) }
 .move_up_vtable 0x004abf58 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.d.rel.ro._ZTV17EvUpDownStickMove) }
 .move_right_D0 0x0032687c : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN20EvLeftRightStickMoveD0Ev) }
 .move_right_D1 0x003268a8 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN20EvLeftRightStickMoveD1Ev) }
 .move_right_vtable 0x004abf40 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.d.rel.ro._ZTV20EvLeftRightStickMove) }

    .stick_release_0 0x0032b5ac : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControl19processTouchReleaseEv) }
    .stick_release_1 0x0032b598 : { *sdk-startup-slidecontrol.o(.text._ZThn8_N12SlideControl19processTouchReleaseEv) }
    .input_EvStickReleased_D0 0x00326cd8 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN15EvStickReleasedD0Ev) }
    .input_EvStickReleased_D1 0x00326d04 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN15EvStickReleasedD1Ev) }
    .input_EvStickReleased_vtable 0x004abf28 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.d.rel.ro._ZTV15EvStickReleased) }
    .input_EvUpDownStickReleased_D0 0x00326768 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN21EvUpDownStickReleasedD0Ev) }
    .input_EvUpDownStickReleased_D1 0x003267b8 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN21EvUpDownStickReleasedD1Ev) }
    .input_EvUpDownStickReleased_vtable 0x004abf10 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.d.rel.ro._ZTV21EvUpDownStickReleased) }
    .input_EvLeftRightStickReleased_D0 0x0032682c : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN24EvLeftRightStickReleasedD0Ev) }
    .input_EvLeftRightStickReleased_D1 0x00326858 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.t._ZN24EvLeftRightStickReleasedD1Ev) }
    .input_EvLeftRightStickReleased_vtable 0x004abef8 : { *sdk-startup-slidecontrol.o(.gnu.linkonce.d.rel.ro._ZTV24EvLeftRightStickReleased) }
    .slidecontrol_draw 0x0032b42c : { *sdk-startup-slidecontrol.o(.text._ZNK12SlideControl6draw2dEv) }
    .slidecontrol_draw_thunk 0x0032b418 : { *sdk-startup-slidecontrol.o(.text._ZThn4_NK12SlideControl6draw2dEv) }
    .slidecontrol_destructor_complete 0x0032b1b0 : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControlD1Ev .text._ZN12SlideControlD2Ev) }
    .slidecontrol_destructor_deleting 0x0032b16c : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControlD0Ev) }
    .slidecontrol_destructor_complete_thunk 0x0032b19c : { *sdk-startup-slidecontrol.o(.text._ZThn4_N12SlideControlD1Ev) }
    .slidecontrol_destructor_deleting_thunk 0x0032b158 : { *sdk-startup-slidecontrol.o(.text._ZThn4_N12SlideControlD0Ev) }
    .slidecontrol_reset 0x0032b1dc : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControl5resetEv) }
    .slidecontrol_update 0x0032b3e0 : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControl6updateEd) }
    .slidecontrol_vtable 0x004ac6b0 : { *sdk-startup-slidecontrol.o(.data.rel.ro._ZTV12SlideControl .gnu.linkonce.d.rel.ro._ZTV12SlideControl) }
    .sdk_startup_function_0 0x0032b128 : { *sdk-startup-slidecontrol.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0032b518 : { *sdk-startup-slidecontrol.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .slide_control_ctor 0x0032b1f4 : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControlC1EP7ASpriteiiNS_16SlideControlModeE .text._ZN12SlideControlC2EP7ASpriteiiNS_16SlideControlModeE) }
    .sdk_startup_function_2 0x0032b584 : { *sdk-startup-slidecontrol.o(.text._GLOBAL__I__ZN12SlideControlC2EP7ASpriteiiNS_16SlideControlModeE) }
    .sdk_startup_storage_0 0x004b96e0 (NOLOAD) : { *sdk-startup-slidecontrol.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9700 (NOLOAD) : { *sdk-startup-slidecontrol.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");

ASSERT(SIZEOF(.slidecontrol_nonmatching_process) <= 668, "uncredited parent must fit retail span");
