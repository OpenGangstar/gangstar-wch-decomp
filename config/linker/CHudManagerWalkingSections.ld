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
}
