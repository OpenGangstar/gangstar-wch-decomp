SECTIONS
{
    .hud_switch_weapon 0x003238ac : { *hud-manager-helpers.o(.text._ZN11CHudManager12switchWeaponEv) }
    .hud_switch_weapon_by_id 0x00323d18 : { *hud-manager-helpers.o(.text._ZN11CHudManager12switchWeaponEi) }
}
