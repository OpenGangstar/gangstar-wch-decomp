sprintf = 0x001c46ac;
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
