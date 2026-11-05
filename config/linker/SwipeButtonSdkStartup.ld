OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-swipebutton/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .sdk_startup_function_0 0x0032bbe0 : { *sdk-startup-swipebutton.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0032bda0 : { *sdk-startup-swipebutton.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0032be0c : { *sdk-startup-swipebutton.o(.text._GLOBAL__I__ZN11SwipeButtonC2EP7ASpritei) }
    .sdk_startup_storage_0 0x004b9788 (NOLOAD) : { *sdk-startup-swipebutton.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b97a8 (NOLOAD) : { *sdk-startup-swipebutton.o(.bss._ZN3irr2ps5vHalfE) }
    .swipe_method_0 0x0032bbc8 : { *sdk-startup-swipebutton.o(.text._ZThn8_N11SwipeButton19processTouchReleaseEv) }
    .swipe_method_1 0x0032bbdc : { *sdk-startup-swipebutton.o(.text._ZN11SwipeButton19processTouchReleaseEv) }
    .swipe_method_2 0x0032bc10 : { *sdk-startup-swipebutton.o(.text._ZThn4_N11SwipeButtonD0Ev .gnu.linkonce.t._ZN11SwipeButtonD0Ev) }
    .swipe_method_4 0x0032bc54 : { *sdk-startup-swipebutton.o(.text._ZThn4_NK11SwipeButton6draw2dEv) }
    .swipe_method_5 0x0032bc68 : { *sdk-startup-swipebutton.o(.text._ZNK11SwipeButton6draw2dEv) }
    .swipe_method_6 0x0032bc88 : { *sdk-startup-swipebutton.o(.text._ZThn8_N11SwipeButton12processTouchEl) }
    .swipe_method_7 0x0032bc9c : { *sdk-startup-swipebutton.o(.text._ZN11SwipeButton12processTouchEl) }
    .swipe_method_8 0x0032bcd0 : { *sdk-startup-swipebutton.o(.text._ZN11SwipeButton6updateEd) }
    .swipe_base_destructor 0x0032a6d4 : { *sdk-startup-swipebutton.o(.gnu.linkonce.t._ZN11SwipeButtonD1Ev) }
    .swipe_vtable 0x004ac7b0 : { *sdk-startup-swipebutton.o(.data.rel.ro._ZTV11SwipeButton .gnu.linkonce.d.rel.ro._ZTV11SwipeButton) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
