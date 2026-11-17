sprintf = 0x001c46ac;
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
SECTIONS
{
    .menu_manager_get_tutorial 0x002e3e94 : { *menu-manager-helpers.o(.text._ZNK11MenuManager14getTutorialIdsERiS0_) }
    .menu_manager_allow_cheats 0x002e3ec4 : { *menu-manager-helpers.o(.text._ZN11MenuManager17allowCheatsUnlockEb) }
    .menu_manager_get_playlist 0x002e3ef0 : { *menu-manager-helpers.o(.text._ZNK11MenuManager11getPlaylistEv) }
    .menu_manager_sequence 0x004b7190 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN11MenuManager19s_currentSequenceIdE) }
    .menu_manager_set_localized_text 0x002e564c : { *menu-manager-helpers.o(.text._ZN11MenuManager7setTextENS_5eTextEiPi) }
    .menu_manager_get_text_id 0x002e3f30 : { *menu-manager-helpers.o(.text._ZNK11MenuManager9getTextIdENS_5eTextE) }
    .menu_manager_get_text 0x002e3f48 : { *menu-manager-helpers.o(.text._ZNK11MenuManager7getTextENS_5eTextE) }
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
    .menu_manager_clear_focus 0x002e44ec : { *menu-manager-helpers.o(.text._ZN11MenuManager10clearFocusEv) }
}
