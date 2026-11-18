PROVIDE(_Znwj = 0x001c4814);
__cxa_pure_virtual = 0;
SECTIONS
{
    .hud_toggle_touch 0x0032c234 : { *hud-manager-helpers.o(.gnu.linkonce.t._ZN12ToggleButton12processTouchEl) }
    .hud_manager_ctor 0x00324c84 : { *hud-manager-helpers.o(.text._ZN11CHudManagerC1Ev .text._ZN11CHudManagerC2Ev) }
    .hud_manager_d1 0x00324978 : { *hud-manager-helpers.o(.text._ZN11CHudManagerD1Ev .text._ZN11CHudManagerD2Ev) }
    .hud_manager_d0 0x00324668 : { *hud-manager-helpers.o(.text._ZN11CHudManagerD0Ev) }
    .hud_ctor_high 0x004223f8 : { *hud-manager-helpers.o(.rodata.hudSpriteHigh) }
    .hud_ctor_low 0x00422408 : { *hud-manager-helpers.o(.rodata.hudSpriteLow) }
    .hud_manager_vtable 0x004abdb0 : { *hud-manager-helpers.o(.data.rel.ro._ZTV11CHudManager) }
    .hud_updatable_d0 0x002d62b8 : { *hud-manager-helpers.o(.gnu.linkonce.t._ZN10IUpdatableD0Ev) }
    .hud_updatable_d1 0x002d62d8 : { *hud-manager-helpers.o(.gnu.linkonce.t._ZN10IUpdatableD1Ev) }
    .hud_updatable_vtable 0x004a6290 : { *hud-manager-helpers.o(.gnu.linkonce.d.rel.ro._ZTV10IUpdatable) }

    .recovered_hud_manager_helpers_3238f4 0x003238f4 : { *hud-manager-helpers.o(.text._ZN11CHudManager24unregUpdatableComponentsEv .gnu.linkonce.t._ZN11CHudManager24unregUpdatableComponentsEv) }
    .recovered_hud_manager_helpers_32399c 0x0032399c : { *hud-manager-helpers.o(.text._ZN11CHudManager22regUpdatableComponentsEv .gnu.linkonce.t._ZN11CHudManager22regUpdatableComponentsEv) }
    .recovered_hud_manager_helpers_323be8 0x00323be8 : { *hud-manager-helpers.o(.text._ZN11CHudManager21regDrawableComponentsEv .gnu.linkonce.t._ZN11CHudManager21regDrawableComponentsEv) }
    .recovered_hud_manager_helpers_323da8 0x00323da8 : { *hud-manager-helpers.o(.text._ZN11CHudManager23unregDrawableComponentsEv .gnu.linkonce.t._ZN11CHudManager23unregDrawableComponentsEv) }
    .recovered_hud_manager_helpers_323704 0x00323704 : { *hud-manager-helpers.o(.text._ZN11CHudManager5blinkEi .gnu.linkonce.t._ZN11CHudManager5blinkEi) }
    .recovered_hud_manager_helpers_2ebc9c 0x002ebc9c : { *hud-manager-helpers.o(.text._ZN11CHudManager15setThrottleModeENS_12ThrottleModeE .gnu.linkonce.t._ZN11CHudManager15setThrottleModeENS_12ThrottleModeE) }
    .recovered_hud_manager_helpers_2ebd28 0x002ebd28 : { *hud-manager-helpers.o(.text._ZN11CHudManager15setSteeringModeENS_12SteeringModeE .gnu.linkonce.t._ZN11CHudManager15setSteeringModeENS_12SteeringModeE) }
    .hud_blink_table 0x00421dc8 : { *hud-manager-helpers.o(.rodata._ZN11CHudManager5blinkEi) }
}
