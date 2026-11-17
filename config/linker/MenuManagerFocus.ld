SECTIONS
{
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
    .menu_manager_clear_focus 0x002e44ec : { *menu-manager-helpers.o(.text._ZN11MenuManager10clearFocusEv) }
}
