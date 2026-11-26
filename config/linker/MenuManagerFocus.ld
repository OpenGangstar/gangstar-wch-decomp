PROVIDE(__aeabi_f2d = 0x1c48f8);
PROVIDE(sqrt = 0x1c401c);
PROVIDE(__aeabi_d2f = 0x1c4310);
PROVIDE(acosf = 0x1c4694);
PROVIDE(_Znwj = 0x001c4814);
PROVIDE(_Znaj = 0x001c3ff8);
PROVIDE(__aeabi_i2d = 0x1c452c);
PROVIDE(__aeabi_dadd = 0x1c4394);
PROVIDE(__aeabi_d2iz = 0x1c4844);
PROVIDE(__aeabi_i2f = 0x001c41e4);
PROVIDE(__aeabi_fmul = 0x001c4724);
PROVIDE(__aeabi_fadd = 0x001c4154);
PROVIDE(__aeabi_fsub = 0x001c4328);
PROVIDE(__aeabi_fdiv = 0x001c4520);
PROVIDE(__aeabi_f2iz = 0x001c44cc);
PROVIDE(__aeabi_fcmplt = 0x001c479c);
PROVIDE(__aeabi_fcmpgt = 0x001c419c);
PROVIDE(__aeabi_fcmpge = 0x001c4364);
PROVIDE(__aeabi_fcmple = 0x001c43ac);
PROVIDE(__aeabi_fcmpeq = 0x001c470c);
PROVIDE(sqrtf = 0x001c4184);
PROVIDE(__aeabi_fsub = 0x001c4328);
PROVIDE(__aeabi_fdiv = 0x001c4520);
PROVIDE(__aeabi_i2f = 0x001c41e4);
PROVIDE(__aeabi_fmul = 0x001c4724);
PROVIDE(__aeabi_fadd = 0x001c4154);
PROVIDE(__aeabi_f2iz = 0x001c44cc);
PROVIDE(sqrtf = 0x001c4184);
sprintf = 0x001c46ac;
memset = 0x001c45d4;
strcmp = 0x001c4658;
strstr = 0x001c446c;
fclose = 0x001c4628;
feof = 0x001c41c0;
ftell = 0x001c45f8;
fseek = 0x001c43f4;
fwrite = 0x001c47e4;
fread = 0x001c4598;
fopen = 0x001c45bc;
strcpy = 0x001c3fd4;
__stack_chk_fail = 0x001c42e0;
strlen = 0x001c48bc;
strcat = 0x001c43a0;
memcpy = 0x001c4190;
/* The suffix is pooled inside the complete Asian font format string. */
asianFontEnd = ADDR(.menu_manager_asian_font_format) + 20;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
__aeabi_atexit = 0x001c494c;
menuMapStateName = 0x0040b608;
glFlush = 0x001c4160;
SECTIONS
{
    .menu_manager_set_text_names 0x00418db4 : { *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc11textCarNameE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc13textCopyrightE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc18textCutsceneDialogE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc9textYNameE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc22textCutsceneSkipButtonE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc16textFailureEventE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc16textFailureCauseE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc22textFailureTouchScreenE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc16textLoadingTitleE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc15textLoadingPercE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc20textMissionObjectiveE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc20textMissionCompletedE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc16textMissionTitleE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc13textRaceTimerE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc21textSplashTouchScreenE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc19textSplashMoreGamesE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc9textTimerE) *menu-manager-helpers.o(.rodata._ZN27_GLOBAL__N__Z10StrToLowerPc11textWarningE) }
    ASSERT(SIZEOF(.menu_manager_set_text_names) == 0x19c, "setText name pool extent")
    .menu_manager_set_text 0x002e51fc : { *menu-manager-helpers.o(.text._ZN11MenuManager7setTextENS_5eTextEPKcPi) }
    .menu_manager_set_text_table 0x004191e4 : { *menu-manager-helpers.o(.rodata._ZN11MenuManager7setTextENS_5eTextEPKcPi) }
    .menu_manager_init_map 0x002e7164 : { *menu-manager-helpers.o(.text._ZN11MenuManager7initMapEv) }
    .menu_manager_position_map_on_point 0x002e6730 : { *menu-manager-helpers.o(.text._ZN11MenuManager19_positionMapOnPointERN3irr4core8vector2dIfEE) }
    .menu_manager_setup 0x002e574c : { *menu-manager-helpers.o(.text._ZN11MenuManager5setupEb) }
    .menu_manager_update 0x002e4e7c : { *menu-manager-helpers.o(.text._ZN11MenuManager6updateEP12StateMachine) }
    .menu_update_markers 0x002e6948 : { *menu-manager-helpers.o(.text._ZN11MenuManager13updateMarkersEv) }
    ASSERT(SIZEOF(.menu_update_markers) == 360, "native updateMarkers extent")
    .menu_draw_map 0x002e6ab0 : { *menu-manager-helpers.o(.text._ZNK11MenuManager8_drawMapEv) }
    ASSERT(SIZEOF(.menu_draw_map) == 424, "native _drawMap extent")
    .menu_update_map 0x002e6fe0 : { *menu-manager-helpers.o(.text._ZN11MenuManager9updateMapEv) }
    .menu_manager_scroll_map 0x002e6864 : { *menu-manager-helpers.o(.text._ZN11MenuManager10_scrollMapERKSt4listIP7Point2DIsESaIS3_EE) }
    .menu_manager_zoom_map 0x002e6db0 : { *menu-manager-helpers.o(.text._ZN11MenuManager8_zoomMapERKSt4listIP7Point2DIsESaIS3_EE) }
    ASSERT(SIZEOF(.menu_update_map) == 388, "native updateMap extent")
    .preload_format 0x00419004 : { *menu-manager-helpers.o(.rodata.preloadFormat) }
    .preload_error 0x00419014 : { *menu-manager-helpers.o(.rodata.preloadError) }
    .menu_preload_glyphs 0x002e5e4c : { *menu-manager-helpers.o(.text._ZN11MenuManager13preloadGlyphsEb) }
    ASSERT(SIZEOF(.menu_preload_glyphs) == 460, "native preloadGlyphs extent")
    .menu_update_localization 0x002e56b0 : { *menu-manager-helpers.o(.text._ZN11MenuManager18updateLocalizationEv) }
    .menu_manager_draw 0x002e4694 : { *menu-manager-helpers.o(.text._ZN11MenuManager4drawEPK12StateMachine) }
    .menu_manager_get_tutorial 0x002e3e94 : { *menu-manager-helpers.o(.text._ZNK11MenuManager14getTutorialIdsERiS0_) }
    .menu_manager_allow_cheats 0x002e3ec4 : { *menu-manager-helpers.o(.text._ZN11MenuManager17allowCheatsUnlockEb) }
    .menu_manager_get_playlist 0x002e3ef0 : { *menu-manager-helpers.o(.text._ZNK11MenuManager11getPlaylistEv) }
    .menu_manager_sequence 0x004b7190 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN11MenuManager19s_currentSequenceIdE) }
    .menu_manager_set_localized_text 0x002e564c : { *menu-manager-helpers.o(.text._ZN11MenuManager7setTextENS_5eTextEiPi) }
    .menu_manager_get_text_id 0x002e3f30 : { *menu-manager-helpers.o(.text._ZNK11MenuManager9getTextIdENS_5eTextE) }
    .menu_manager_get_text 0x002e3f48 : { *menu-manager-helpers.o(.text._ZNK11MenuManager7getTextENS_5eTextE) }
    .menu_manager_instance 0x002e4894 : { *menu-manager-helpers.o(.text._ZN11MenuManager11getInstanceEv) }
    .menu_manager_instance_cleanup 0x002e62b0 : { *menu-manager-helpers.o(.text.__tcf_1) }
    .menu_manager_instance_guard 0x004b7a1c (NOLOAD) : { *menu-manager-helpers.o(.bss._ZGVZN11MenuManager11getInstanceEvE3mgr) }
    .menu_manager_instance_storage 0x004b7a20 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZZN11MenuManager11getInstanceEvE3mgr) }
    .menu_manager_widget_visibility 0x002e49ac : { *menu-manager-helpers.o(.text._ZN11MenuManager22updateWidgetVisibilityEv) }
    .menu_manager_constructor 0x002e477c : { *menu-manager-helpers.o(.text._ZN11MenuManagerC1Ev .text._ZN11MenuManagerC2Ev) }
    .menu_manager_destructor 0x002e6274 : { *menu-manager-helpers.o(.text._ZN11MenuManagerD1Ev .text._ZN11MenuManagerD2Ev) }
    .menu_manager_deleting_destructor 0x002e4c84 : { *menu-manager-helpers.o(.text._ZN11MenuManagerD0Ev) }
    .menu_manager_vtable 0x004a8f60 : { *menu-manager-helpers.o(.data.rel.ro._ZTV11MenuManager) }
    .menu_swf_texture_loader 0x002e60e8 : { *menu-manager-helpers.o(.text._Z16SwfTextureLoaderPKcii) }
    .menu_manager_free_texture 0x002e4a14 : { *menu-manager-helpers.o(.text._ZN11MenuManager11freeTextureEPKc) }
    .menu_font_file 0x002e48e8 : { *menu-manager-helpers.o(.text._Z12get_fontfilePKcbbPci) }
    .menu_requested_font_format 0x00418d74 : { *menu-manager-helpers.o(.rodata.requestedFontFormat) }
    .menu_asian_font_file_format 0x00418d80 : { *menu-manager-helpers.o(.rodata.asianFontFileFormat) }
    .menu_standard_font_file_format 0x00418d90 : { *menu-manager-helpers.o(.rodata.standardFontFileFormat) }
    .menu_lowercase 0x002e4040 : { *menu-manager-helpers.o(.text._Z10StrToLowerPc) }
    .menu_fs_close 0x002e4074 : { *menu-manager-helpers.o(.text._Z13fs_close_funcPv) }
    .menu_fs_eof 0x002e408c : { *menu-manager-helpers.o(.text._Z15fs_get_eof_funcPv) }
    .menu_fs_tell 0x002e40a0 : { *menu-manager-helpers.o(.text._Z12fs_tell_funcPKv) }
    .menu_fs_seek_end 0x002e40ac : { *menu-manager-helpers.o(.text._Z19fs_seek_to_end_funcPv) }
    .menu_fs_seek 0x002e40c8 : { *menu-manager-helpers.o(.text._Z12fs_seek_funciPv) }
    .menu_fs_write 0x002e40ec : { *menu-manager-helpers.o(.text._Z13fs_write_funcPKviPv) }
    .menu_fs_read 0x002e40fc : { *menu-manager-helpers.o(.text._Z12fs_read_funcPviS_) }
    .menu_fs_open 0x002e410c : { *menu-manager-helpers.o(.text._Z12fs_open_funcPKcS0_) }
    .menu_fs_open_error 0x00418d04 : { *menu-manager-helpers.o(.rodata.menuFileOpenError) }
    .menu_manager_show_texts 0x002e4160 : { *menu-manager-helpers.o(.text._ZN11MenuManager9showTextsEv) }
    .menu_manager_hide_texts 0x002e4184 : { *menu-manager-helpers.o(.text._ZN11MenuManager9hideTextsEv) }
    .menu_manager_hide_arrow 0x002e41a8 : { *menu-manager-helpers.o(.text._ZN11MenuManager15hideDialogArrowEv) }
    .menu_manager_show_arrow 0x002e41cc : { *menu-manager-helpers.o(.text._ZN11MenuManager15showDialogArrowEv) }
    .menu_manager_texts_name 0x00418d30 : { *menu-manager-helpers.o(.rodata.menuTexts) }
    .menu_manager_arrow_name 0x00418d38 : { *menu-manager-helpers.o(.rodata.dialogArrow) }
    .menu_manager_get_state 0x002e4228 : { *menu-manager-helpers.o(.text._ZNK11MenuManager8getStateEPKc) }
    .menu_manager_is_current_state 0x002e4238 : { *menu-manager-helpers.o(.text._ZNK11MenuManager14isCurrentStateEPKc) }
    .my_menu_fx_clear_states 0x002e4388 : { *menu-manager-helpers.o(.text._ZN8MyMenuFX11ClearStatesEv) }
    .menu_car_rental_read 0x002e4458 : { *menu-manager-helpers.o(.text._ZN7Structs9CarRental4ReadER10DataStream) }
    .my_menu_fx_deleting_destructor 0x002e4484 : { *menu-manager-helpers.o(.text._ZN8MyMenuFXD0Ev) }
    .my_menu_fx_destructor 0x002e44b4 : { *menu-manager-helpers.o(.text._ZN8MyMenuFXD1Ev .text._ZN8MyMenuFXD2Ev) }
    .my_menu_fx_vtable 0x004a8f70 : { *menu-manager-helpers.o(.data.rel.ro._ZTV8MyMenuFX) }
    .menu_fx_clear_focus 0x002e44dc : { *menu-manager-helpers.o(.text._ZN8MyMenuFX10ClearFocusEv) }
    .menu_manager_enable_asian_font 0x002e3f60 : { *menu-manager-helpers.o(.text._ZN11MenuManager15enableAsianFontEb) }
    .menu_manager_format_character 0x002e4508 : { *menu-manager-helpers.o(.text._ZN11MenuManager16formatMenuFXTextEPN7gameswf9characterEPKcz) }
    .menu_manager_format_named 0x002e4594 : { *menu-manager-helpers.o(.text._ZN11MenuManager16formatMenuFXTextEPKcS1_z) }
    .menu_manager_asian_font_start 0x00418d44 : { *menu-manager-helpers.o(.rodata.asianFontStart) }
    .menu_manager_format_buffer 0x004b721c (NOLOAD) : { *menu-manager-helpers.o(.bss.menuTextFormatBuffer) }
    .menu_manager_character_text 0x002e45c4 : { *menu-manager-helpers.o(.text._ZN11MenuManager13setMenuFXTextEPN7gameswf9characterEPKcbb) }
    .menu_manager_named_text 0x002e462c : { *menu-manager-helpers.o(.text._ZN11MenuManager13setMenuFXTextEPKcS1_bb) }
    .menu_manager_asian_font_format 0x00418d58 : { *menu-manager-helpers.o(.rodata.asianFontFormat) }
    .menu_manager_text_buffer 0x004b761c (NOLOAD) : { *menu-manager-helpers.o(.bss.asianFontTextBuffer) }
    .menu_manager_top_visibility 0x002e4668 : { *menu-manager-helpers.o(.text._ZN11MenuManager13topSetVisibleEb) }
    .menu_manager_push 0x002e64bc : { *menu-manager-helpers.o(.text._ZN11MenuManager4pushEPKcb) }
    .menu_manager_switch 0x002e62cc : { *menu-manager-helpers.o(.text._ZN11MenuManager8switchToEPKcb) }
    .menu_manager_pop 0x002e6370 : { *menu-manager-helpers.o(.text._ZN11MenuManager3popEb) }
    .menu_manager_pop_to 0x002e6418 : { *menu-manager-helpers.o(.text._ZN11MenuManager5popToEPKcbb) }
    .menu_manager_pop_all 0x002e6460 : { *menu-manager-helpers.o(.text._ZN11MenuManager6popAllEb) }
    .menu_manager_clear_focus 0x002e44ec : { *menu-manager-helpers.o(.text._ZN11MenuManager10clearFocusEv) }
}
