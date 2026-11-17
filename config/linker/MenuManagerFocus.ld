SECTIONS
{
    .menu_fx_clear_focus 0x002e44dc : { *menu-manager-helpers.o(.text._ZN8MyMenuFX10ClearFocusEv) }
    .menu_manager_clear_focus 0x002e44ec : { *menu-manager-helpers.o(.text._ZN11MenuManager10clearFocusEv) }
}
