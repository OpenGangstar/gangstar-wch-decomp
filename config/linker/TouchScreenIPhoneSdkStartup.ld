OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-touchscreeniphone/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__cxa_pure_virtual = 0;
__aeabi_f2iz = 0x001c44cc;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .iphone_constructor 0x0034cde4 : { *sdk-startup-touchscreeniphone.o(.text._ZN17TouchScreenIPhoneC1Effff .text._ZN17TouchScreenIPhoneC2Effff) }
    .iphone_on_event 0x0034cedc : { *sdk-startup-touchscreeniphone.o(.text._ZThn472_N17TouchScreenIPhone7OnEventERKN3irr6SEventE .text._ZN17TouchScreenIPhone7OnEventERKN3irr6SEventE) }
    .iphone_mouse_down 0x004bc0ac (NOLOAD) : { *sdk-startup-touchscreeniphone.o(.bss._ZZN17TouchScreenIPhone7OnEventERKN3irr6SEventEE6isDown) }
    .iphone_point2d_d0 0x00326374 : { *sdk-startup-touchscreeniphone.o(.gnu.linkonce.t._ZN7Point2DIsED0Ev) }
    .iphone_point2d_d1 0x00326394 : { *sdk-startup-touchscreeniphone.o(.gnu.linkonce.t._ZN7Point2DIsED1Ev) }
    .iphone_point2d_vtable 0x004abf88 : { *sdk-startup-touchscreeniphone.o(.gnu.linkonce.d.rel.ro._ZTV7Point2DIsE) }
    .iphone_destructor_complete 0x0034cff4 : { *sdk-startup-touchscreeniphone.o(.text._ZN17TouchScreenIPhoneD1Ev .text._ZN17TouchScreenIPhoneD2Ev) }
    .iphone_destructor_deleting 0x0034cfa4 : { *sdk-startup-touchscreeniphone.o(.text._ZN17TouchScreenIPhoneD0Ev) }
    .iphone_destructor_complete_thunk 0x0034cfe0 : { *sdk-startup-touchscreeniphone.o(.text._ZThn472_N17TouchScreenIPhoneD1Ev) }
    .iphone_destructor_deleting_thunk 0x0034cf90 : { *sdk-startup-touchscreeniphone.o(.text._ZThn472_N17TouchScreenIPhoneD0Ev) }
    .iphone_vtable 0x004ad358 : { *sdk-startup-touchscreeniphone.o(.data.rel.ro._ZTV17TouchScreenIPhone .gnu.linkonce.d.rel.ro._ZTV17TouchScreenIPhone) }
    .iphone_receiver_d0 0x002537d8 : { *sdk-startup-touchscreeniphone.o(.gnu.linkonce.t._ZN3irr14IEventReceiverD0Ev) }
    .iphone_receiver_d1 0x002537f8 : { *sdk-startup-touchscreeniphone.o(.gnu.linkonce.t._ZN3irr14IEventReceiverD1Ev) }
    .iphone_receiver_vtable 0x00488968 : { *sdk-startup-touchscreeniphone.o(.gnu.linkonce.d.rel.ro._ZTVN3irr14IEventReceiverE) }
    .iphone_accessor_0 0x0034cd7c : { *sdk-startup-touchscreeniphone.o(.text._ZNK17TouchScreenIPhone12getLeftBoundEv) }
    .iphone_accessor_1 0x0034cd84 : { *sdk-startup-touchscreeniphone.o(.text._ZNK17TouchScreenIPhone13getRightBoundEv) }
    .iphone_accessor_2 0x0034cd8c : { *sdk-startup-touchscreeniphone.o(.text._ZNK17TouchScreenIPhone11getTopBoundEv) }
    .iphone_accessor_3 0x0034cd94 : { *sdk-startup-touchscreeniphone.o(.text._ZNK17TouchScreenIPhone14getBottomBoundEv) }
    .iphone_accessor_4 0x0034cdcc : { *sdk-startup-touchscreeniphone.o(.text._ZNK17TouchScreenIPhone18getTouchIDInRegionERKN3irr4core4rectIfEE) }
    .iphone_accessor_5 0x0034cdd8 : { *sdk-startup-touchscreeniphone.o(.text._ZNK17TouchScreenIPhone15isRegionPressedERKN3irr4core4rectIfEE) }
    .sdk_startup_function_0 0x0034cd9c : { *sdk-startup-touchscreeniphone.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0034ce5c : { *sdk-startup-touchscreeniphone.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0034cec8 : { *sdk-startup-touchscreeniphone.o(.text._GLOBAL__I__ZN17TouchScreenIPhoneC2Effff) }
    .sdk_startup_storage_0 0x004bc080 (NOLOAD) : { *sdk-startup-touchscreeniphone.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc0a0 (NOLOAD) : { *sdk-startup-touchscreeniphone.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
