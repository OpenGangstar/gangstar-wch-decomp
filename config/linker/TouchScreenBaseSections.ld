/* Retail section placement shared with the platform input verifier. */
SECTIONS
{
    .touchscreen_convert_coord 0x0034c33c : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase12ConvertCoordER7Point2DIsE) }
    .touchscreen_trace 0x0034c394 : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase6_traceEPKc) }
    .touchscreen_touch_ended 0x0034c3c8 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase10touchEndedERK7Point2DIsEl) }
    .touchscreen_touch_cancelled 0x0034c400 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase14touchCancelledERK7Point2DIsEl) }
    .touchscreen_release_message 0x0043600c : { *string-startup-touchscreenbase.o(.rodata.releaseMessage) }
    .touchscreen_cancel_message 0x00436024 : { *string-startup-touchscreenbase.o(.rodata.cancelMessage) }
    .touchscreen_update 0x0034c4f8 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase6updateEd) }
    .touchscreen_moved 0x0034c78c : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase10touchMovedERK7Point2DIsEl) }
    .touchscreen_move_message 0x00436030 : { *string-startup-touchscreenbase.o(.rodata.moveMessage) }
    .touchscreen_clear 0x0034c398 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase5clearEv) }
    .touchscreen_clear_point 0x0034c3b8 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase15clearTouchPointEl) }
    .touchscreen_point 0x0034c44c : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase13getTouchPointEl) }
    .touchscreen_first_point 0x0034c478 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase18getFirstTouchPointEl) }
    .touchscreen_num_points 0x0034c4a4 : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase12getNumPointsEl) }
    .touchscreen_swipe_direction 0x0034c4cc : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase17getSwipeDirectionEl) }
    .touchscreen_get_id 0x0034c598 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase5getIDEl) }
    .touchscreen_enable 0x0034c5dc : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase6enableEv) }
    .touchscreen_disable 0x0034c5e8 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBase7disableEv) }
    .touchscreen_is_enabled 0x0034c5f4 : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase9isEnabledEv) }
    .touchscreen_point2d_d0 0x00326374 : { *string-startup-touchscreenbase.o(.gnu.linkonce.t._ZN7Point2DIsED0Ev) }
    .touchscreen_point2d_d1 0x00326394 : { *string-startup-touchscreenbase.o(.gnu.linkonce.t._ZN7Point2DIsED1Ev) }
    .touchscreen_point2d_vtable 0x004abf88 : { *string-startup-touchscreenbase.o(.gnu.linkonce.d.rel.ro._ZTV7Point2DIsE) }
    .touchscreen_dimension_out 0x0034c5fc : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase12getDimensionER3RctIsE) }
    .touchscreen_rct_validate 0x0034c64c : { *string-startup-touchscreenbase.o(.text._ZN3RctIsE9_validateEv .gnu.linkonce.t._ZN3RctIsE9_validateEv) }
    .touchscreen_dimension_value 0x0034c6a4 : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase12getDimensionEv) }
    .string_startup_function_0 0x0034c724 : { *string-startup-touchscreenbase.o(.text.__tcf_0) }
    .string_startup_function_1 0x0034cb10 : { *string-startup-touchscreenbase.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0034cb68 : { *string-startup-touchscreenbase.o(.text._GLOBAL__I__ZN15TouchScreenBase14CLEAN_UP_DELAYE) }
    .touchscreen_rct_d0 0x0034c754 : { *string-startup-touchscreenbase.o(.text._ZN3RctIsED0Ev .gnu.linkonce.t._ZN3RctIsED0Ev) }
    .touchscreen_rct_d1 0x0034c774 : { *string-startup-touchscreenbase.o(.text._ZN3RctIsED1Ev .gnu.linkonce.t._ZN3RctIsED1Ev) }
    .touchscreen_rct_vtable 0x004ad348 : { *string-startup-touchscreenbase.o(.gnu.linkonce.d.rel.ro._ZTV3RctIsE) }
    .touchscreen_initiated_in_region 0x0034c830 : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase27getTouchIDInitiatedInRegionERKN3irr4core4rectIfEE) }
    .touchscreen_region_pressed 0x0034c968 : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase15isRegionPressedERKN3irr4core4rectIfEE) }
    .touchscreen_id_in_region 0x0034c9fc : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase18getTouchIDInRegionERKN3irr4core4rectIfEE) }
    .touchscreen_slot_destructor 0x0034cc18 : { *string-startup-touchscreenbase.o(.gnu.linkonce.t._ZN15TouchScreenBase15_TouchPointInfoD1Ev .gnu.linkonce.t._ZN15TouchScreenBase15_TouchPointInfoD2Ev) }
    .string_startup_storage_0 0x004bc060 (NOLOAD) : { *string-startup-touchscreenbase.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .touchscreen_base_constructor 0x0034ca90 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBaseC1Ev .text._ZN15TouchScreenBaseC2Ev) }
    .touchscreen_base_deleting_destructor 0x0034cc34 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBaseD0Ev) }
    .touchscreen_base_destructor 0x0034cc98 : { *string-startup-touchscreenbase.o(.text._ZN15TouchScreenBaseD1Ev .text._ZN15TouchScreenBaseD2Ev) }
    .touchscreen_base_vtable 0x004ad2e8 : { *string-startup-touchscreenbase.o(.data.rel.ro._ZTV15TouchScreenBase) }
    .touchscreen_base_updatable_vtable 0x004a6290 : { *string-startup-touchscreenbase.o(.gnu.linkonce.d.rel.ro._ZTV10IUpdatable) }
    .touchscreen_base_updatable_delete 0x002d62b8 : { *string-startup-touchscreenbase.o(.gnu.linkonce.t._ZN10IUpdatableD0Ev) }
    .touchscreen_base_updatable_destructor 0x002d62d8 : { *string-startup-touchscreenbase.o(.gnu.linkonce.t._ZN10IUpdatableD1Ev) }
}
