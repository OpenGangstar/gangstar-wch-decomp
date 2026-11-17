OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/state-hooks-gsloading/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZN28retail_gsloading_transitions16civPassive_transE = 0x0041758c;
_ZN28retail_gsloading_transitions17scriptedNpc_transE = 0x004176b8;
_ZN28retail_gsloading_transitions19civAggressive_transE = 0x004176e8;
_ZN28retail_gsloading_transitions16gangMember_transE = 0x004177cc;
_ZN28retail_gsloading_transitions9cop_transE = 0x004177d8;
_ZN28retail_gsloading_transitions10swat_transE = 0x00417910;
_ZN28retail_gsloading_transitions17civ_vehicle_transE = 0x0041791c;
_ZN28retail_gsloading_transitions17cop_vehicle_transE = 0x004179ac;
_ZN28retail_gsloading_transitions11guard_transE = 0x00417a60;
_ZN28retail_gsloading_transitions22scripted_vehicle_transE = 0x00417b08;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .loading_get_loaded 0x002e2b18 : { *state-hooks-gsloading.o(.text._ZN9GSLoading12isGameLoadedEv) }
    .loading_set_loaded 0x002e2b2c : { *state-hooks-gsloading.o(.text._ZN9GSLoading13setGameLoadedEb) }
    .loading_loaded_flag 0x004b6eec (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN9GSLoading13s_bGameLoadedE) }
    .state_ctor 0x002e2dd0 : { *state-hooks-gsloading.o(.text._ZN9GSLoadingC1Ev) }
    .base_0 0x002dacc0 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase8isKindOfEi .text._ZN9StateBase8isKindOfEi .gnu.linkonce.d.rel.ro._ZN9StateBase8isKindOfEi .data.rel.ro._ZN9StateBase8isKindOfEi) }
    .base_1 0x002dacac : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase4drawEPK12StateMachine .text._ZN9StateBase4drawEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4drawEPK12StateMachine .data.rel.ro._ZN9StateBase4drawEPK12StateMachine) }
    .base_2 0x002db4ec : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBaseD0Ev .text._ZN9StateBaseD0Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD0Ev .data.rel.ro._ZN9StateBaseD0Ev) }
    .base_3 0x002daca4 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase6resumeEPK12StateMachine .text._ZN9StateBase6resumeEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6resumeEPK12StateMachine .data.rel.ro._ZN9StateBase6resumeEPK12StateMachine) }
    .base_4 0x002dacb8 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase6wakeupEPK12StateMachine .text._ZN9StateBase6wakeupEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6wakeupEPK12StateMachine .data.rel.ro._ZN9StateBase6wakeupEPK12StateMachine) }
    .base_5 0x002dacbc : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase10isDrawableEv .text._ZN9StateBase10isDrawableEv .gnu.linkonce.d.rel.ro._ZN9StateBase10isDrawableEv .data.rel.ro._ZN9StateBase10isDrawableEv) }
    .base_6 0x002dac9c : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase4dtorEPK12StateMachine .text._ZN9StateBase4dtorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4dtorEPK12StateMachine .data.rel.ro._ZN9StateBase4dtorEPK12StateMachine) }
    .base_7 0x002dacb4 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase5sleepEPK12StateMachine .text._ZN9StateBase5sleepEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5sleepEPK12StateMachine .data.rel.ro._ZN9StateBase5sleepEPK12StateMachine) }
    .base_8 0x002db50c : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBaseD1Ev .text._ZN9StateBaseD1Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD1Ev .data.rel.ro._ZN9StateBaseD1Ev) }
    .base_9 0x002dacb0 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase6draw2dEPK12StateMachine .text._ZN9StateBase6draw2dEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6draw2dEPK12StateMachine .data.rel.ro._ZN9StateBase6draw2dEPK12StateMachine) }
    .base_10 0x002dac98 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase4ctorEPK12StateMachine .text._ZN9StateBase4ctorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4ctorEPK12StateMachine .data.rel.ro._ZN9StateBase4ctorEPK12StateMachine) }
    .base_11 0x002daca0 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase5pauseEPK12StateMachine .text._ZN9StateBase5pauseEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5pauseEPK12StateMachine .data.rel.ro._ZN9StateBase5pauseEPK12StateMachine) }
    .base_12 0x002daca8 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9StateBase6updateEP12StateMachine .text._ZN9StateBase6updateEP12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6updateEP12StateMachine .data.rel.ro._ZN9StateBase6updateEP12StateMachine) }
    .base_13 0x004a8b60 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZTV9StateBase .text._ZTV9StateBase .gnu.linkonce.d.rel.ro._ZTV9StateBase .data.rel.ro._ZTV9StateBase) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .state_destructor 0x002e2f6c : { *state-hooks-gsloading.o(.text._ZN9GSLoadingD1Ev) }
    .state_delete 0x002e2f40 : { *state-hooks-gsloading.o(.text._ZN9GSLoadingD0Ev) }
    .state_vtable 0x004a8da0 : { *state-hooks-gsloading.o(.data.rel.ro._ZTV9GSLoading .gnu.linkonce.d.rel.ro._ZTV9GSLoading) }
    .state_kind 0x002e2b08 : { *state-hooks-gsloading.o(.gnu.linkonce.t._ZN9GSLoading8isKindOfEi .text._ZN9GSLoading8isKindOfEi) }
    .local_startup_function_0 0x002e2de8 : { *state-hooks-gsloading.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .local_startup_function_1 0x002e2f2c : { *state-hooks-gsloading.o(.text._GLOBAL__I_m_background) }
    .local_startup_function_2 0x002e2b40 : { *state-hooks-gsloading.o(.text.__tcf_4) }
    .local_startup_storage_0 0x004b6ef0 (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .local_startup_storage_1 0x004b6f10 (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN3irr2ps5vHalfE) }
    .local_startup_storage_2 0x004b6f1c (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .local_startup_storage_3 0x004b6f24 (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .local_startup_storage_4 0x004b6f2c (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .local_startup_storage_5 0x004b6f34 (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .local_startup_storage_6 0x004b6f3c (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai3copE) }
    .local_startup_storage_7 0x004b6f44 (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai4swatE) }
    .local_startup_storage_8 0x004b6f4c (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .local_startup_storage_9 0x004b6f54 (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .local_startup_storage_10 0x004b6f5c (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai5guardE) }
    .local_startup_storage_11 0x004b6f64 (NOLOAD) : { *state-hooks-gsloading.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

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

ASSERT(SIZEOF(.loading_loaded_flag) == 1, "GSLoading loaded flag extent");
