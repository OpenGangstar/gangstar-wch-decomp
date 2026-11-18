printf = 0x001c4058; __aeabi_ui2f = 0x001c4574; __aeabi_fdiv = 0x001c4520; __aeabi_fcmpgt = 0x001c419c;
wheelInvalidTouchFormat = 0x00425374;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/wheel-touch-thunk/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_i2f = 0x001c41e4;
__aeabi_fmul = 0x001c4724;
__aeabi_fadd = 0x001c4154;
memcpy = 0x001c4190;
memset = 0x001c45d4;
SECTIONS
{
    .point2d_delete 0x00326374 : { *wheel-touch-thunk.o(.gnu.linkonce.t._ZN7Point2DIsED0Ev) }
    .point2d_destroy 0x00326394 : { *wheel-touch-thunk.o(.gnu.linkonce.t._ZN7Point2DIsED1Ev) }
    .point2d_table 0x004abf88 : { *wheel-touch-thunk.o(.gnu.linkonce.d.rel.ro._ZTV7Point2DIsE) }
    .wheel_touch_thunk 0x0032cfb8 : { *wheel-touch-thunk.o(.text._ZThn8_N5Wheel12processTouchEl) }
    .wheel_nonmatching_touch 0x0032cfcc : { *wheel-touch-thunk.o(.text._ZN5Wheel12processTouchEl) }
    .base_getid 0x002d3c34 : { *(.gnu.linkonce.t._ZNK6IEvent10getEventIDEv) }
    .base_delete 0x002d4074 : { *(.gnu.linkonce.t._ZN6IEventD0Ev) }
    .base_destructor 0x002d4094 : { *(.gnu.linkonce.t._ZN6IEventD1Ev) }
    .base_table 0x004a6198 : { *(.gnu.linkonce.d.rel.ro._ZTV6IEvent) }
    .wheel_event_release_delete 0x0032cf68 : { *(.gnu.linkonce.t._ZN15EvWheelReleasedD0Ev) }
    .wheel_event_release_destructor 0x0032d0f8 : { *(.gnu.linkonce.t._ZN15EvWheelReleasedD1Ev) }
    .wheel_event_release_vtable 0x004aca48 : { *(.gnu.linkonce.d.rel.ro._ZTV15EvWheelReleased) }
    .wheel_event_turn_delete 0x0032d18c : { *(.gnu.linkonce.t._ZN11EvWheelTurnD0Ev) }
    .wheel_event_turn_destructor 0x0032cf94 : { *(.gnu.linkonce.t._ZN11EvWheelTurnD1Ev) }
    .wheel_event_turn_vtable 0x004aca60 : { *(.gnu.linkonce.d.rel.ro._ZTV11EvWheelTurn) }
    .wheel_release_thunk 0x0032d11c : { *(.text._ZThn8_N5Wheel19processTouchReleaseEv) }
    .wheel_touch_release 0x0032d130 : { *(.text._ZN5Wheel19processTouchReleaseEv) }
    .wheel_set_hand 0x0032caf0 : { *(.text._ZN5Wheel7setHandEb) }
    .wheel_delete_thunk 0x0032cb24 : { *(.text._ZThn4_N5WheelD0Ev) }
    .wheel_delete 0x0032cb38 : { *(.text._ZN5WheelD0Ev) }
    .wheel_destructor_thunk 0x0032cb68 : { *(.text._ZThn4_N5WheelD1Ev) }
    .wheel_destructor 0x0032cb7c : { *(.text._ZN5WheelD1Ev) }
    .wheel_draw 0x0032ccf4 : { *(.text._ZNK5Wheel6draw2dEv) }
    .wheel_draw_thunk 0x0032cce0 : { *(.text._ZThn4_NK5Wheel6draw2dEv) }
    .wheel_update 0x0032cba8 : { *(.text._ZN5Wheel6updateEd) }
    .wheel_vtable 0x004ac9c8 : { *(.data.rel.ro._ZTV5Wheel) }
    .sdk_startup_function_0 0x0032caf4 : { *wheel-touch-thunk.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0032cee8 : { *wheel-touch-thunk.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0032cf54 : { *wheel-touch-thunk.o(.text._GLOBAL__I__ZN5WheelC2EP7ASpritei) }
    .sdk_startup_storage_0 0x004b9858 (NOLOAD) : { *wheel-touch-thunk.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9878 (NOLOAD) : { *wheel-touch-thunk.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
