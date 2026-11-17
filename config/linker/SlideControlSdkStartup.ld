OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-slidecontrol/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .slidecontrol_destructor_complete 0x0032b1b0 : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControlD1Ev .text._ZN12SlideControlD2Ev) }
    .slidecontrol_destructor_deleting 0x0032b16c : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControlD0Ev) }
    .slidecontrol_destructor_complete_thunk 0x0032b19c : { *sdk-startup-slidecontrol.o(.text._ZThn4_N12SlideControlD1Ev) }
    .slidecontrol_destructor_deleting_thunk 0x0032b158 : { *sdk-startup-slidecontrol.o(.text._ZThn4_N12SlideControlD0Ev) }
    .slidecontrol_reset 0x0032b1dc : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControl5resetEv) }
    .slidecontrol_update 0x0032b3e0 : { *sdk-startup-slidecontrol.o(.text._ZN12SlideControl6updateEd) }
    .slidecontrol_vtable 0x004ac6b0 : { *sdk-startup-slidecontrol.o(.data.rel.ro._ZTV12SlideControl .gnu.linkonce.d.rel.ro._ZTV12SlideControl) }
    .sdk_startup_function_0 0x0032b128 : { *sdk-startup-slidecontrol.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0032b518 : { *sdk-startup-slidecontrol.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0032b584 : { *sdk-startup-slidecontrol.o(.text._GLOBAL__I__ZN12SlideControlC2EP7ASpriteiiNS_16SlideControlModeE) }
    .sdk_startup_storage_0 0x004b96e0 (NOLOAD) : { *sdk-startup-slidecontrol.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9700 (NOLOAD) : { *sdk-startup-slidecontrol.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
