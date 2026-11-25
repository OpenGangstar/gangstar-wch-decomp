PROVIDE(__aeabi_d2iz = 0x001c4844);
PROVIDE(__aeabi_dsub = 0x001c4454);
PROVIDE(__aeabi_i2d = 0x001c452c);
PROVIDE(_Znwj = 0x001c4814);
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/state-hooks-gsfailure/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZN28retail_gsfailure_transitions16civPassive_transE = 0x004169d0;
_ZN28retail_gsfailure_transitions17scriptedNpc_transE = 0x00416afc;
_ZN28retail_gsfailure_transitions19civAggressive_transE = 0x00416b2c;
_ZN28retail_gsfailure_transitions16gangMember_transE = 0x00416c10;
_ZN28retail_gsfailure_transitions9cop_transE = 0x00416c1c;
_ZN28retail_gsfailure_transitions10swat_transE = 0x00416d54;
_ZN28retail_gsfailure_transitions17civ_vehicle_transE = 0x00416d60;
_ZN28retail_gsfailure_transitions17cop_vehicle_transE = 0x00416df0;
_ZN28retail_gsfailure_transitions11guard_transE = 0x00416ea4;
_ZN28retail_gsfailure_transitions22scripted_vehicle_transE = 0x00416f4c;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
PROVIDE(__aeabi_idiv = 0x001c43dc);
SECTIONS
{
    .gsfailure_draw2d 0x002e1e14 : { *state-hooks-gsfailure.o(.text._ZN9GSFailure6draw2dEPK12StateMachine) }
    .gsfailure_dtor 0x002e1f64 : { *state-hooks-gsfailure.o(.text._ZN9GSFailure4dtorEPK12StateMachine .gnu.linkonce.t._ZN9GSFailure4dtorEPK12StateMachine) }
    .gsfailure_state_ctor 0x002e1fd4 : { *state-hooks-gsfailure.o(.text._ZN9GSFailure4ctorEPK12StateMachine .gnu.linkonce.t._ZN9GSFailure4ctorEPK12StateMachine) }
    .gsfailure_update 0x002e20dc : { *state-hooks-gsfailure.o(.text._ZN9GSFailure6updateEP12StateMachine .gnu.linkonce.t._ZN9GSFailure6updateEP12StateMachine) }

    .state_ctor 0x002e233c : { *state-hooks-gsfailure.o(.text._ZN9GSFailureC1Ev) }
    .base_0 0x002dacc0 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase8isKindOfEi .text._ZN9StateBase8isKindOfEi .gnu.linkonce.d.rel.ro._ZN9StateBase8isKindOfEi .data.rel.ro._ZN9StateBase8isKindOfEi) }
    .base_1 0x002dacac : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase4drawEPK12StateMachine .text._ZN9StateBase4drawEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4drawEPK12StateMachine .data.rel.ro._ZN9StateBase4drawEPK12StateMachine) }
    .base_2 0x002db4ec : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBaseD0Ev .text._ZN9StateBaseD0Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD0Ev .data.rel.ro._ZN9StateBaseD0Ev) }
    .base_3 0x002daca4 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase6resumeEPK12StateMachine .text._ZN9StateBase6resumeEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6resumeEPK12StateMachine .data.rel.ro._ZN9StateBase6resumeEPK12StateMachine) }
    .base_4 0x002dacb8 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase6wakeupEPK12StateMachine .text._ZN9StateBase6wakeupEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6wakeupEPK12StateMachine .data.rel.ro._ZN9StateBase6wakeupEPK12StateMachine) }
    .base_5 0x002dacbc : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase10isDrawableEv .text._ZN9StateBase10isDrawableEv .gnu.linkonce.d.rel.ro._ZN9StateBase10isDrawableEv .data.rel.ro._ZN9StateBase10isDrawableEv) }
    .base_6 0x002dac9c : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase4dtorEPK12StateMachine .text._ZN9StateBase4dtorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4dtorEPK12StateMachine .data.rel.ro._ZN9StateBase4dtorEPK12StateMachine) }
    .base_7 0x002dacb4 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase5sleepEPK12StateMachine .text._ZN9StateBase5sleepEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5sleepEPK12StateMachine .data.rel.ro._ZN9StateBase5sleepEPK12StateMachine) }
    .base_8 0x002db50c : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBaseD1Ev .text._ZN9StateBaseD1Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD1Ev .data.rel.ro._ZN9StateBaseD1Ev) }
    .base_9 0x002dacb0 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase6draw2dEPK12StateMachine .text._ZN9StateBase6draw2dEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6draw2dEPK12StateMachine .data.rel.ro._ZN9StateBase6draw2dEPK12StateMachine) }
    .base_10 0x002dac98 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase4ctorEPK12StateMachine .text._ZN9StateBase4ctorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4ctorEPK12StateMachine .data.rel.ro._ZN9StateBase4ctorEPK12StateMachine) }
    .base_11 0x002daca0 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase5pauseEPK12StateMachine .text._ZN9StateBase5pauseEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5pauseEPK12StateMachine .data.rel.ro._ZN9StateBase5pauseEPK12StateMachine) }
    .base_12 0x002daca8 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9StateBase6updateEP12StateMachine .text._ZN9StateBase6updateEP12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6updateEP12StateMachine .data.rel.ro._ZN9StateBase6updateEP12StateMachine) }
    .base_13 0x004a8b60 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZTV9StateBase .text._ZTV9StateBase .gnu.linkonce.d.rel.ro._ZTV9StateBase .data.rel.ro._ZTV9StateBase) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .state_destructor 0x002e24dc : { *state-hooks-gsfailure.o(.text._ZN9GSFailureD1Ev) }
    .state_delete 0x002e24b0 : { *state-hooks-gsfailure.o(.text._ZN9GSFailureD0Ev) }
    .state_vtable 0x004a8ce0 : { *state-hooks-gsfailure.o(.data.rel.ro._ZTV9GSFailure .gnu.linkonce.d.rel.ro._ZTV9GSFailure) }
    .state_kind 0x002e1dd4 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN9GSFailure8isKindOfEi .text._ZN9GSFailure8isKindOfEi) }
    .local_startup_function_0 0x002e2358 : { *state-hooks-gsfailure.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .local_startup_function_1 0x002e249c : { *state-hooks-gsfailure.o(.text._GLOBAL__I__ZN9GSFailure14s_bCutsceneDieE) }
    .local_startup_function_2 0x002e1de4 : { *state-hooks-gsfailure.o(.text.__tcf_4) }
    .local_startup_function_3 0x002e1f48 : { *state-hooks-gsfailure.o(.text.__tcf_3) }
    .local_startup_storage_0 0x004b6dc0 (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .local_startup_storage_1 0x004b6de0 (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN3irr2ps5vHalfE) }
    .local_startup_storage_2 0x004b6dec (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .local_startup_storage_3 0x004b6df4 (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .local_startup_storage_4 0x004b6dfc (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .local_startup_storage_5 0x004b6e04 (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .local_startup_storage_6 0x004b6e0c (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai3copE) }
    .local_startup_storage_7 0x004b6e14 (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai4swatE) }
    .local_startup_storage_8 0x004b6e1c (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .local_startup_storage_9 0x004b6e24 (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .local_startup_storage_10 0x004b6e2c (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai5guardE) }
    .local_startup_storage_11 0x004b6e34 (NOLOAD) : { *state-hooks-gsfailure.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

.state_instance 0x002d44c4 : { *state-hooks-gsfailure.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv .text._ZN12StateMachine11getInstanceEv) }
    .state_instance_cleanup 0x002d4518 : { *state-hooks-gsfailure.o(.text.__tcf_0) }
    .state_instance_guard 0x004b6904 (NOLOAD) : { *state-hooks-gsfailure.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm .bss._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_instance_storage 0x004b6908 (NOLOAD) : { *state-hooks-gsfailure.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm .bss._ZZN12StateMachine11getInstanceEvE2sm) }
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
ASSERT(SIZEOF(.state_instance_guard) == 4, "StateMachine guard extent");
ASSERT(SIZEOF(.state_instance_storage) == 40, "StateMachine storage extent");
ASSERT(SIZEOF(.gsfailure_draw2d) == 308, "Native _ZN9GSFailure6draw2dEPK12StateMachine extent");
