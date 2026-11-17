SECTIONS
{
    .my_menu_fx_clear_states 0x002e4388 : { *menu-manager-helpers.o(.text._ZN8MyMenuFX11ClearStatesEv) }
    .my_menu_fx_deleting_destructor 0x002e4484 : { *menu-manager-helpers.o(.text._ZN8MyMenuFXD0Ev) }
    .my_menu_fx_destructor 0x002e44b4 : { *menu-manager-helpers.o(.text._ZN8MyMenuFXD1Ev .text._ZN8MyMenuFXD2Ev) }
    .my_menu_fx_vtable 0x004a8f70 : { *menu-manager-helpers.o(.data.rel.ro._ZTV8MyMenuFX) }
    .menu_fx_clear_focus 0x002e44dc : { *menu-manager-helpers.o(.text._ZN8MyMenuFX10ClearFocusEv) }
    .menu_manager_clear_focus 0x002e44ec : { *menu-manager-helpers.o(.text._ZN11MenuManager10clearFocusEv) }
}
