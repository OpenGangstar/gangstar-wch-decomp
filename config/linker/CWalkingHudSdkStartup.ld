OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-cwalkinghud/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .sdk_startup_function_0 0x00325a2c : { *sdk-startup-cwalkinghud.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00325a5c : { *sdk-startup-cwalkinghud.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00325ac8 : { *sdk-startup-cwalkinghud.o(.text._GLOBAL__I__ZN11CWalkingHudC2EP11CHudManager) }
    .sdk_startup_storage_0 0x004b9184 (NOLOAD) : { *sdk-startup-cwalkinghud.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b91a4 (NOLOAD) : { *sdk-startup-cwalkinghud.o(.bss._ZN3irr2ps5vHalfE) }
    .hud_entry_0 0x00325690 : { *sdk-startup-cwalkinghud.o(.gnu.linkonce.t._ZNK11CWalkingHud12isWalkingHudEv) }
    .hud_entry_1 0x00325694 : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHudC1EP11CHudManager) }
    .hud_entry_2 0x003256c4 : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHudD1Ev) }
    .walking_nearCar 0x003258c0 : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHud7nearCarEv) }
    .walking_notNearCar 0x003258e4 : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHud10notNearCarEv) }
    .walking_nearShop 0x003258fc : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHud8nearShopEv) }
    .walking_isNearShop 0x00325920 : { *sdk-startup-cwalkinghud.o(.text._ZNK11CWalkingHud10isNearShopEv) }
    .walking_notNearShop 0x00325934 : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHud11notNearShopEv) }
    .hud_showSpyGauge 0x00325950 : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHud12showSpyGaugeEb) }
    .hud_showCash 0x0032598c : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHud8showCashEb) }
    .hud_weapon_selector 0x003259ac : { *sdk-startup-cwalkinghud.o(.text._ZN11CWalkingHud20toggleWeaponSelectorEb) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
