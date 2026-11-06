/* Walking HUD dispatch wrappers at their retail addresses. */
SECTIONS
{
    .walking_nearCar 0x00323aa4 : { *hud-manager-helpers.o(.text._ZN11CHudManager7nearCarEv) }
    .walking_notNearCar 0x00323a8c : { *hud-manager-helpers.o(.text._ZN11CHudManager10notNearCarEv) }
    .walking_nearShop 0x00323a74 : { *hud-manager-helpers.o(.text._ZN11CHudManager8nearShopEv) }
    .walking_isNearShop 0x00323a44 : { *hud-manager-helpers.o(.text._ZNK11CHudManager10isNearShopEv) }
    .walking_notNearShop 0x00323a5c : { *hud-manager-helpers.o(.text._ZN11CHudManager11notNearShopEv) }
    .hud_showCash 0x003237e0 : { *hud-manager-helpers.o(.text._ZN11CHudManager8showCashEb) }
    .hud_showSpyGauge 0x00323840 : { *hud-manager-helpers.o(.text._ZN11CHudManager12showSpyGaugeEb) }
    .hud_weapon_selector 0x003236e8 : { *hud-manager-helpers.o(.text._ZN11CHudManager20toggleWeaponSelectorEb) }
    .hud_show 0x003235b0 : { *hud-manager-helpers.o(.text._ZN11CHudManager4showEv) }
    .hud_visible 0x003235d4 : { *hud-manager-helpers.o(.text._ZNK11CHudManager9isVisibleEv) }
    .hud_minimap_visible 0x00323620 : { *hud-manager-helpers.o(.text._ZN11CHudManager16isMinimapVisibleEv) }
    .hud_weapon_visible 0x00323634 : { *hud-manager-helpers.o(.text._ZNK11CHudManager15isWeaponVisibleEv) }
    .hud_hide 0x00323d68 : { *hud-manager-helpers.o(.text._ZN11CHudManager4hideEv) }
    .hud_mode_walking 0x00323b00 : { *hud-manager-helpers.o(.text._ZN11CHudManager7walkingEv) }
    .hud_mode_driving 0x00323b34 : { *hud-manager-helpers.o(.text._ZN11CHudManager7drivingEv) }
    .hud_mode_sniping 0x00323abc : { *hud-manager-helpers.o(.text._ZN11CHudManager7snipingEv) }
}
