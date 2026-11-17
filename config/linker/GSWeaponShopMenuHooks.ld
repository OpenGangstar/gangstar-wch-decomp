OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/state-hooks-gsweaponshopmenu/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZN35retail_gsweaponshopmenu_transitions16civPassive_transE = 0x00418734;
_ZN35retail_gsweaponshopmenu_transitions17scriptedNpc_transE = 0x00418860;
_ZN35retail_gsweaponshopmenu_transitions19civAggressive_transE = 0x00418890;
_ZN35retail_gsweaponshopmenu_transitions16gangMember_transE = 0x00418974;
_ZN35retail_gsweaponshopmenu_transitions9cop_transE = 0x00418980;
_ZN35retail_gsweaponshopmenu_transitions10swat_transE = 0x00418ab8;
_ZN35retail_gsweaponshopmenu_transitions17civ_vehicle_transE = 0x00418ac4;
_ZN35retail_gsweaponshopmenu_transitions17cop_vehicle_transE = 0x00418b54;
_ZN35retail_gsweaponshopmenu_transitions11guard_transE = 0x00418c08;
_ZN35retail_gsweaponshopmenu_transitions22scripted_vehicle_transE = 0x00418cb0;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .hook_0 0x002e3c14 : { *state-hooks-gsweaponshopmenu.o(.text._ZN16GSWeaponShopMenu6updateEP12StateMachine .gnu.linkonce.t._ZN16GSWeaponShopMenu6updateEP12StateMachine) }
    .hook_1 0x002e3c18 : { *state-hooks-gsweaponshopmenu.o(.text._ZN16GSWeaponShopMenu4drawEPK12StateMachine .gnu.linkonce.t._ZN16GSWeaponShopMenu4drawEPK12StateMachine) }
    .state_ctor 0x002e3bfc : { *state-hooks-gsweaponshopmenu.o(.text._ZN16GSWeaponShopMenuC1Ev) }
    .menu_exit 0x002e3c1c : { *state-hooks-gsweaponshopmenu.o(.text._ZN16GSWeaponShopMenu4dtorEPK12StateMachine) }
    .menu_enter 0x002e3c48 : { *state-hooks-gsweaponshopmenu.o(.text._ZN16GSWeaponShopMenu4ctorEPK12StateMachine) }
    .entry_text 0x00418720 : { *state-hooks-gsweaponshopmenu.o(.rodata.str1.4 .rodata.str1.1) }
    .base_0 0x002dacc0 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase8isKindOfEi .text._ZN9StateBase8isKindOfEi .gnu.linkonce.d.rel.ro._ZN9StateBase8isKindOfEi .data.rel.ro._ZN9StateBase8isKindOfEi) }
    .base_1 0x002dacac : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase4drawEPK12StateMachine .text._ZN9StateBase4drawEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4drawEPK12StateMachine .data.rel.ro._ZN9StateBase4drawEPK12StateMachine) }
    .base_2 0x002db4ec : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBaseD0Ev .text._ZN9StateBaseD0Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD0Ev .data.rel.ro._ZN9StateBaseD0Ev) }
    .base_3 0x002daca4 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase6resumeEPK12StateMachine .text._ZN9StateBase6resumeEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6resumeEPK12StateMachine .data.rel.ro._ZN9StateBase6resumeEPK12StateMachine) }
    .base_4 0x002dacb8 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase6wakeupEPK12StateMachine .text._ZN9StateBase6wakeupEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6wakeupEPK12StateMachine .data.rel.ro._ZN9StateBase6wakeupEPK12StateMachine) }
    .base_5 0x002dacbc : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase10isDrawableEv .text._ZN9StateBase10isDrawableEv .gnu.linkonce.d.rel.ro._ZN9StateBase10isDrawableEv .data.rel.ro._ZN9StateBase10isDrawableEv) }
    .base_6 0x002dac9c : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase4dtorEPK12StateMachine .text._ZN9StateBase4dtorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4dtorEPK12StateMachine .data.rel.ro._ZN9StateBase4dtorEPK12StateMachine) }
    .base_7 0x002dacb4 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase5sleepEPK12StateMachine .text._ZN9StateBase5sleepEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5sleepEPK12StateMachine .data.rel.ro._ZN9StateBase5sleepEPK12StateMachine) }
    .base_8 0x002db50c : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBaseD1Ev .text._ZN9StateBaseD1Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD1Ev .data.rel.ro._ZN9StateBaseD1Ev) }
    .base_9 0x002dacb0 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase6draw2dEPK12StateMachine .text._ZN9StateBase6draw2dEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6draw2dEPK12StateMachine .data.rel.ro._ZN9StateBase6draw2dEPK12StateMachine) }
    .base_10 0x002dac98 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase4ctorEPK12StateMachine .text._ZN9StateBase4ctorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4ctorEPK12StateMachine .data.rel.ro._ZN9StateBase4ctorEPK12StateMachine) }
    .base_11 0x002daca0 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase5pauseEPK12StateMachine .text._ZN9StateBase5pauseEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5pauseEPK12StateMachine .data.rel.ro._ZN9StateBase5pauseEPK12StateMachine) }
    .base_12 0x002daca8 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN9StateBase6updateEP12StateMachine .text._ZN9StateBase6updateEP12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6updateEP12StateMachine .data.rel.ro._ZN9StateBase6updateEP12StateMachine) }
    .base_13 0x004a8b60 : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZTV9StateBase .text._ZTV9StateBase .gnu.linkonce.d.rel.ro._ZTV9StateBase .data.rel.ro._ZTV9StateBase) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .state_destructor 0x002e3e58 : { *state-hooks-gsweaponshopmenu.o(.text._ZN16GSWeaponShopMenuD1Ev) }
    .state_delete 0x002e3e2c : { *state-hooks-gsweaponshopmenu.o(.text._ZN16GSWeaponShopMenuD0Ev) }
    .state_vtable 0x004a8f20 : { *state-hooks-gsweaponshopmenu.o(.data.rel.ro._ZTV16GSWeaponShopMenu .gnu.linkonce.d.rel.ro._ZTV16GSWeaponShopMenu) }
    .state_kind 0x002e3bec : { *state-hooks-gsweaponshopmenu.o(.gnu.linkonce.t._ZN16GSWeaponShopMenu8isKindOfEi .text._ZN16GSWeaponShopMenu8isKindOfEi) }
    .local_startup_function_0 0x002e3ca4 : { *state-hooks-gsweaponshopmenu.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .local_startup_function_1 0x002e3de8 : { *state-hooks-gsweaponshopmenu.o(.text._GLOBAL__I__ZN16GSWeaponShopMenuC2Ev) }
    .local_startup_function_2 0x002e3dfc : { *state-hooks-gsweaponshopmenu.o(.text.__tcf_4) }
    .local_startup_storage_0 0x004b70ec (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .local_startup_storage_1 0x004b710c (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN3irr2ps5vHalfE) }
    .local_startup_storage_2 0x004b7118 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .local_startup_storage_3 0x004b7120 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .local_startup_storage_4 0x004b7128 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .local_startup_storage_5 0x004b7130 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .local_startup_storage_6 0x004b7138 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai3copE) }
    .local_startup_storage_7 0x004b7140 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai4swatE) }
    .local_startup_storage_8 0x004b7148 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .local_startup_storage_9 0x004b7150 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .local_startup_storage_10 0x004b7158 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai5guardE) }
    .local_startup_storage_11 0x004b7160 (NOLOAD) : { *state-hooks-gsweaponshopmenu.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
}
ASSERT(SIZEOF(.local_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.local_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.local_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.local_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.local_startup_storage_4) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.local_startup_storage_5) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.local_startup_storage_6) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.local_startup_storage_7) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.local_startup_storage_8) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.local_startup_storage_9) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.local_startup_storage_10) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.local_startup_storage_11) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
