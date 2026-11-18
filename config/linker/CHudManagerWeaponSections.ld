INCLUDE config/linker/CHudManagerRecoveredSections.ld
SECTIONS
{
    .message_2e7638 0x002e7638 : { *hud-manager-helpers.o(.text._ZN11CHudManager21isAnyMessageDisplayedEv) }
    .hud_switch_weapon 0x003238ac : { *hud-manager-helpers.o(.text._ZN11CHudManager12switchWeaponEv) }
    .hud_switch_weapon_by_id 0x00323d18 : { *hud-manager-helpers.o(.text._ZN11CHudManager12switchWeaponEi) }
}
