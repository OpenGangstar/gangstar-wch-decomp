__cxa_pure_virtual = 0;
_ZdlPv = 0x001c42b0;
__stack_chk_fail = 0x001c42e0;
memcpy = 0x001c4190;
__aeabi_i2f = 0x001c41e4;
__aeabi_fmul = 0x001c4724;
__aeabi_fcmpge = 0x001c4364;
__aeabi_fcmple = 0x001c43ac;
fputs = 0x001c4904;
fflush = 0x001c425c;
strcmp = 0x001c4658;
vsprintf = 0x001c4070;
SECTIONS
{
    .renderfx_named_registerdisplaycallback 0x003ee14c : { *renderfx-animation.o(.text._ZN8RenderFX23RegisterDisplayCallbackEPKcPFvRN7gameswf12render_stateEPvES5_) }
    .renderfx_named_isanimover 0x003ee168 : { *renderfx-animation.o(.text._ZN8RenderFX10IsAnimOverEPKc) }
    .renderfx_named_getframecount 0x003ee184 : { *renderfx-animation.o(.text._ZN8RenderFX13GetFrameCountEPKc) }
    .renderfx_named_gettext 0x003ee260 : { *renderfx-animation.o(.text._ZN8RenderFX7GetTextEPKc) }
    .renderfx_named_setposition 0x003ee290 : { *renderfx-animation.o(.text._ZN8RenderFX11SetPositionEPKcii) }
    .renderfx_named_setcolorfilter 0x003ee2c8 : { *renderfx-animation.o(.text._ZN8RenderFX14SetColorFilterEPKcij) }
    .renderfx_named_setcolortransform 0x003ee2e4 : { *renderfx-animation.o(.text._ZN8RenderFX17SetColorTransformEPKcjj) }
    .renderfx_character_frame_count 0x003ec31c : { *renderfx-animation.o(.text._ZN8RenderFX13GetFrameCountEPN7gameswf9characterE) }
    .renderfx_character_animation_over 0x003ec344 : { *renderfx-animation.o(.text._ZN8RenderFX10IsAnimOverEPN7gameswf9characterE) }
    .renderfx_character_display_callback 0x003ec3b0 : { *renderfx-animation.o(.text._ZN8RenderFX23RegisterDisplayCallbackEPN7gameswf9characterEPFvRNS0_12render_stateEPvES5_) }
    .renderfx_character_get_text 0x003ec9d4 : { *renderfx-animation.o(.text._ZN8RenderFX7GetTextEPN7gameswf9characterE) }
    .renderfx_character_alpha 0x003ecaf4 : { *renderfx-animation.o(.text._ZNK8RenderFX8GetAlphaEPN7gameswf9characterE) }
    .renderfx_character_position 0x003ec6ec : { *renderfx-animation.o(.text._ZN8RenderFX11SetPositionEPN7gameswf9characterEii) }
    .renderfx_character_color_filter 0x003ecdc4 : { *renderfx-animation.o(.text._ZN8RenderFX14SetColorFilterEPN7gameswf9characterEij) }
    .renderfx_named_alpha 0x003ee300 : { *renderfx-animation.o(.text._ZN8RenderFX8SetAlphaEPKcf) }
    .renderfx_event_listener 0x003ec1f8 : { *renderfx-animation.o(.text._ZN8RenderFX16SetEventListenerEPNS_13EventListenerE) }
    .renderfx_unload 0x003ed370 : { *renderfx-animation.o(.text._ZN8RenderFX6UnloadEv) }
    .renderfx_find_named 0x003edf1c : { *renderfx-animation.o(.text._ZN8RenderFX4FindEPKc) }
    .renderfx_get_search_index 0x003f04ac : { *renderfx-animation.o(.text._ZN8RenderFX14GetSearchIndexEv) }
    .renderfx_search_index_destructor 0x003ee7d4 : { *renderfx-animation.o(.text._ZN8RenderFX11SearchIndexD1Ev .text._ZN8RenderFX11SearchIndexD2Ev) }
    .menufx_vtable 0x004afc18 : { *renderfx-animation.o(.data.rel.ro._ZTV6MenuFX) }
    .menufx_deleting_destructor 0x003ee904 : { *renderfx-animation.o(.text._ZN6MenuFXD0Ev) }
    .menufx_destructor 0x003ee94c : { *renderfx-animation.o(.text._ZN6MenuFXD1Ev .text._ZN6MenuFXD2Ev) }
    .menufx_constructor 0x003ed158 : { *renderfx-animation.o(.text._ZN6MenuFXC1Ev .text._ZN6MenuFXC2Ev) }
    .renderfx_constructor 0x003ed0cc : { *renderfx-animation.o(.text._ZN8RenderFXC1Ev .text._ZN8RenderFXC2Ev) }
    .renderfx_controller_reset 0x003ec600 : { *renderfx-animation.o(.text._ZN8RenderFX10Controller5ResetEv) }
    .renderfx_controller_destructor 0x003ed6a8 : { *renderfx-animation.o(.text._ZN8RenderFX10ControllerD1Ev) }
    .renderfx_controller_enabled 0x003ec200 : { *renderfx-animation.o(.text._ZN8RenderFX20SetControllerEnabledEib) }
    .renderfx_input_behavior 0x003ec210 : { *renderfx-animation.o(.text._ZN8RenderFX16SetInputBehaviorEi) }
    .renderfx_set_context 0x003ec3cc : { *renderfx-animation.o(.text._ZN8RenderFX10SetContextEPN7gameswf9characterE) }
    .renderfx_get_root 0x003ec3d0 : { *renderfx-animation.o(.text._ZNK8RenderFX7GetRootEv) }
    .renderfx_set_text_buffering 0x003ec9c4 : { *renderfx-animation.o(.text._ZN8RenderFX23SetTextBufferingEnabledEb) }
    .renderfx_get_flash_root 0x003ec9cc : { *renderfx-animation.o(.text._ZNK8RenderFX12GetFlashRootEv) }
    .renderfx_prerender 0x003ed884 : { *renderfx-animation.o(.text._ZN8RenderFX9PreRenderEv) }
    .renderfx_setbounds 0x003ed8c8 : { *renderfx-animation.o(.text._ZN8RenderFX9SetBoundsEiiii) }
    .renderfx_setviewport 0x003ed910 : { *renderfx-animation.o(.text._ZN8RenderFX11SetViewportEiiii) }
    .renderfx_begindisplay 0x003ed680 : { *renderfx-animation.o(.text._ZN8RenderFX12BeginDisplayEv) }
    .renderfx_render 0x003ed958 : { *renderfx-animation.o(.text._ZN8RenderFX6RenderEv) }
    .renderfx_enddisplay 0x003ed980 : { *renderfx-animation.o(.text._ZN8RenderFX10EndDisplayEv) }
    .renderfx_orientation 0x003ec6a8 : { *renderfx-animation.o(.text._ZN8RenderFX14SetOrientationEN7gameswf16orientation_modeE) }
    .renderfx_wireframe 0x003ec6bc : { *renderfx-animation.o(.text._ZN8RenderFX12SetWireFrameEb) }
    .renderfx_initialize_glyph_cache 0x003ec6d0 : { *renderfx-animation.o(.text._ZN8RenderFX27InitializeGlyphTextureCacheEii) }
    .renderfx_glyph_cache_warning 0x0044dc5c : { *renderfx-animation.o(.rodata.deprecatedGlyphCache) }
    .renderfx_destroy_context 0x003ec1e4 : { *renderfx-animation.o(.text._ZN8RenderFX14DestroyContextEPN7gameswf14player_contextE) }
    .renderfx_clear_glyph_caches 0x003ecd48 : { *renderfx-animation.o(.text._ZN8RenderFX23ClearGlyphTextureCachesEPN7gameswf14player_contextE) }
    .renderfx_create_context 0x003ec818 : { *renderfx-animation.o(.text._ZN8RenderFX13CreateContextERNS_24InitializationParametersE) }
    .renderfx_initialize 0x003ec8d0 : { *renderfx-animation.o(.text._ZN8RenderFX10InitializeERNS_24InitializationParametersE) }
    .renderfx_finalize 0x003ec884 : { *renderfx-animation.o(.text._ZN8RenderFX8FinalizeEv) }
    .renderfx_file_opener 0x003ec998 : { *renderfx-animation.o(.text._Z11file_openerPKc) }
    .renderfx_empty_fs_callback 0x003ec1e0 : { *renderfx-animation.o(.text._Z11fs_callbackPN7gameswf9characterEPKcS3_) }
    .renderfx_can_handle_event 0x003ec1dc : { *renderfx-animation.o(.text._ZN8RenderFX13EventListener14CanHandleEventERNS_5EventE) }
    .renderfx_event_listener_vtable 0x004afc88 : { *renderfx-animation.o(.data.rel.ro._ZTVN8RenderFX13EventListenerE) }
    .renderfx_set_cursor 0x003ee378 : { *renderfx-animation.o(.text._ZN8RenderFX9SetCursorEPKci) }
    .renderfx_named_as_callback 0x003ef11c : { *renderfx-animation.o(.text._ZN8RenderFX16InvokeASCallbackEPKcS1_) }
    .renderfx_menu_update 0x003f0138 : { *renderfx-animation.o(.text._ZN6MenuFX6UpdateEib) }
    .renderfx_menu_event_filter_thunk 0x003f0260 : { *renderfx-animation.o(.text._ZThn204_N6MenuFX14CanHandleEventERN8RenderFX5EventE) }
    .renderfx_menu_event_filter 0x003f0274 : { *renderfx-animation.o(.text._ZN6MenuFX14CanHandleEventERN8RenderFX5EventE) }
    .renderfx_menu_on_event_thunk 0x003f0294 : { *renderfx-animation.o(.text._ZThn204_N6MenuFX7OnEventERN8RenderFX5EventE) }
    .renderfx_menu_on_event 0x003f02a8 : { *renderfx-animation.o(.text._ZN6MenuFX7OnEventERN8RenderFX5EventE) }
    .renderfx_menu_get_state 0x003ecd88 : { *renderfx-animation.o(.text._ZN6MenuFX8GetStateEPKc) }
    .widget_button_prefix 0x00419f00 : { *renderfx-animation.o(.rodata.widgetButtonPrefix) }
    .renderfx_missing_menu_format 0x0044de28 : { *renderfx-animation.o(.rodata.missingMenuFormat) }
    .renderfx_menu_register_states 0x003ee020 : { *renderfx-animation.o(.text._ZN6MenuFX14RegisterStatesEPPNS_5StateEi) }
    .renderfx_menu_register_state 0x003edfb8 : { *renderfx-animation.o(.text._ZN6MenuFX13RegisterStateEPNS_5StateEPKc) }
    .renderfx_pop_menu 0x003ef374 : { *renderfx-animation.o(.text._ZN6MenuFX7PopMenuEv) }
    .renderfx_focus_in_animation 0x0044de7c : { *renderfx-animation.o(.rodata.focusInAnimation) }
    .renderfx_menu_default_focus 0x003ef4b8 : { *renderfx-animation.o(.text._ZN6MenuFX15SetFocusDefaultEv) }
    .renderfx_reset_focus 0x003ef364 : { *renderfx-animation.o(.text._ZN8RenderFX10ResetFocusEi) }
    .widget_hide_animation 0x0041aa74 : { *renderfx-animation.o(.rodata.widgetHideAnimation) }
    .widget_show_animation 0x0041aa7c : { *renderfx-animation.o(.rodata.widgetShowAnimation) }
    .renderfx_set_menu 0x003ed3e0 : { *renderfx-animation.o(.text._ZN6MenuFX7SetMenuEPKcb) }
    .renderfx_menu_switch 0x003ed4f0 : { *renderfx-animation.o(.text._ZN6MenuFX10SwitchMenuEPKc) }
    .renderfx_menu_push 0x003ed500 : { *renderfx-animation.o(.text._ZN6MenuFX8PushMenuEPKc) }
    .renderfx_menu_unload 0x003ed510 : { *renderfx-animation.o(.text._ZN6MenuFX6UnloadEv) }
    .renderfx_menu_pop_all 0x003ed60c : { *renderfx-animation.o(.text._ZN6MenuFX6PopAllEv) }
    .renderfx_menu_fs_command 0x003eca88 : { *renderfx-animation.o(.text._ZN6MenuFX11OnFSCommandEPKcS1_) }
    .renderfx_menu_fs_command_thunk 0x003eca74 : { *renderfx-animation.o(.text._ZThn204_N6MenuFX11OnFSCommandEPKcS1_) }
    .renderfx_menu_current_state 0x003ecaa8 : { *renderfx-animation.o(.text._ZN6MenuFX15GetCurrentStateEv) }
    .renderfx_menu_state_in_stack 0x003ecac4 : { *renderfx-animation.o(.text._ZN6MenuFX14IsStateInStackEPNS_5StateE) }
    .renderfx_fs_command 0x003ec398 : { *renderfx-animation.o(.text._ZN8RenderFX9FSCommandEPKcS1_) }
    .renderfx_file_read_mode 0x004014f0 : { *renderfx-animation.o(.rodata.swfReadMode) }
    .renderfx_fs_command_callback 0x003ed9a8 : { *renderfx-animation.o(.text._Z26fscommand_callback_handlerPN7gameswf9characterEPKcS3_) }
    .renderfx_message_log 0x003ec640 : { *renderfx-animation.o(.text._Z11message_logPKc) }
    .renderfx_log_callback 0x003ec670 : { *renderfx-animation.o(.text._Z12log_callbackbPKc) }
    .set_character_text 0x003eebd0 : { *renderfx-animation.o(.text._ZN8RenderFX7SetTextEPN7gameswf9characterEPKcb) }
    .set_named_text 0x003eec4c : { *renderfx-animation.o(.text._ZN8RenderFX7SetTextEPKcS1_b) }
    .format_named_html 0x003eec68 : { *renderfx-animation.o(.text._ZN8RenderFX10FormatHTMLEPKcS1_z) }
    .format_named_text 0x003eeca8 : { *renderfx-animation.o(.text._ZN8RenderFX10FormatTextEPKcS1_z) }
    .format_character_html 0x003eece8 : { *renderfx-animation.o(.text._ZN8RenderFX10FormatHTMLEPN7gameswf9characterEPKcz) }
    .format_character_text 0x003eed28 : { *renderfx-animation.o(.text._ZN8RenderFX10FormatTextEPN7gameswf9characterEPKcz) }
    .renderfx_string_buffer 0x004bd500 (NOLOAD) : { *renderfx-animation.o(.bss.s_stringBuffer) }
    .set_named_focus 0x003ef4f4 : { *renderfx-animation.o(.text._ZN8RenderFX8SetFocusEPKci) }
    .find_characters 0x003ed2ac : { *renderfx-animation.o(.text._ZN8RenderFX14FindCharactersEPN7gameswf9characterEPKci) }
    .enable_character 0x003ec270 : { *renderfx-animation.o(.text._ZN8RenderFX10SetEnabledEPN7gameswf9characterEb) }
    .enable_named_character 0x003ee274 : { *renderfx-animation.o(.text._ZN8RenderFX10SetEnabledEPKcb) }
    .set_named_character_visibility 0x003ee2ac : { *renderfx-animation.o(.text._ZN8RenderFX10SetVisibleEPKcb) }
    .activate_animation 0x0041aa40 : { *renderfx-animation.o(.rodata.activateAnimation) }
    .focus_out_animation 0x0044dc50 : { *renderfx-animation.o(.rodata.focusOutAnimation) }
    .disabled_animation 0x0041aa4c : { *renderfx-animation.o(.rodata.disabledAnimation) }
    .goto_character_label 0x003ec218 : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPN7gameswf9characterEPKcb) }
    .play_character_animation 0x003ec260 : { *renderfx-animation.o(.text._ZN8RenderFX8PlayAnimEPN7gameswf9characterEPKci) }
    .goto_character_frame 0x003ec2dc : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPN7gameswf9characterEib) }
    .goto_named_frame 0x003ee1a0 : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPKcib) }
    .goto_named_label 0x003ee1c0 : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPKcS1_b) }
    .play_named_animation 0x003ee1dc : { *renderfx-animation.o(.text._ZN8RenderFX8PlayAnimEPKcS1_i) }
}
