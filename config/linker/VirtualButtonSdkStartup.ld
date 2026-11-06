OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-virtualbutton/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_i2f = 0x001c41e4;
__aeabi_fadd = 0x001c4154;
SECTIONS
{
    .sdk_startup_function_0 0x0032c5f8 : { *sdk-startup-virtualbutton.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0032c578 : { *sdk-startup-virtualbutton.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0032c5e4 : { *sdk-startup-virtualbutton.o(.text._GLOBAL__I__ZN13VirtualButtonC2EP7ASpriteiN9EvVButton10ButtonType4TypeEb) }
    .sdk_startup_storage_0 0x004b9800 (NOLOAD) : { *sdk-startup-virtualbutton.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9820 (NOLOAD) : { *sdk-startup-virtualbutton.o(.bss._ZN3irr2ps5vHalfE) }
    .button_update 0x0032c474 : { *sdk-startup-virtualbutton.o(.text._ZN13VirtualButton6updateEd) }
    .button_ctor 0x0032c4d0 : { *sdk-startup-virtualbutton.o(.text._ZN13VirtualButtonC1EP7ASpriteiN9EvVButton10ButtonType4TypeEb) }
    .button_base_thunk 0x00326eac : { *sdk-startup-virtualbutton.o(.gnu.linkonce.t._ZN13VirtualButtonD1Ev) }
    .button_delete_thunk 0x0032c430 : { *sdk-startup-virtualbutton.o(.gnu.linkonce.t._ZN13VirtualButtonD0Ev) }
    .button_vtable 0x004ac8b0 : { *sdk-startup-virtualbutton.o(.data.rel.ro._ZTV13VirtualButton .gnu.linkonce.d.rel.ro._ZTV13VirtualButton) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
