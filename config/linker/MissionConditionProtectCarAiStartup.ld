OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditionprotectcar/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN45retail_missionconditionprotectcar_transitions16civPassive_transE = 0x0042bf70;
_ZN45retail_missionconditionprotectcar_transitions17scriptedNpc_transE = 0x0042c09c;
_ZN45retail_missionconditionprotectcar_transitions19civAggressive_transE = 0x0042c0cc;
_ZN45retail_missionconditionprotectcar_transitions16gangMember_transE = 0x0042c1b0;
_ZN45retail_missionconditionprotectcar_transitions9cop_transE = 0x0042c1bc;
_ZN45retail_missionconditionprotectcar_transitions10swat_transE = 0x0042c2f4;
_ZN45retail_missionconditionprotectcar_transitions17civ_vehicle_transE = 0x0042c300;
_ZN45retail_missionconditionprotectcar_transitions17cop_vehicle_transE = 0x0042c390;
_ZN45retail_missionconditionprotectcar_transitions11guard_transE = 0x0042c444;
_ZN45retail_missionconditionprotectcar_transitions22scripted_vehicle_transE = 0x0042c4ec;
SECTIONS
{
    .mission_protect_003376b8 0x003376b8 : { *ai-startup-missionconditionprotectcar.o(.text._ZN26MissionConditionProtectCar8evaluateEi) }
    .mission_protect_003376e0 0x003376e0 : { *ai-startup-missionconditionprotectcar.o(.text._ZN26MissionConditionProtectCar4drawEv) }
    .mission_protect_003376e4 0x003376e4 : { *ai-startup-missionconditionprotectcar.o(.text._ZNK26MissionConditionProtectCar5causeEv) }
    .mission_protect_00337718 0x00337718 : { *ai-startup-missionconditionprotectcar.o(.text._ZN26MissionConditionProtectCarC2EP7Vehiclei .text._ZN26MissionConditionProtectCarC1EP7Vehiclei) }
    .mission_protect_003378a0 0x003378a0 : { *ai-startup-missionconditionprotectcar.o(.text._ZN26MissionConditionProtectCarD0Ev) }
    .mission_protect_003378dc 0x003378dc : { *ai-startup-missionconditionprotectcar.o(.text._ZN26MissionConditionProtectCarD2Ev .text._ZN26MissionConditionProtectCarD1Ev) }
    .mission_protect_vtable 0x004acea0 : { *ai-startup-missionconditionprotectcar.o(.data.rel.ro._ZTV26MissionConditionProtectCar) }
    .ai_startup_function_0 0x003376e8 : { *ai-startup-missionconditionprotectcar.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00337748 : { *ai-startup-missionconditionprotectcar.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0033788c : { *ai-startup-missionconditionprotectcar.o(.text._GLOBAL__I__ZN26MissionConditionProtectCarC2EP7Vehiclei) }
    .ai_startup_storage_0 0x004ba178 (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba198 (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba1a4 (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba1ac (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba1b4 (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba1bc (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba1c4 (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba1cc (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba1d4 (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba1dc (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba1e4 (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba1ec (NOLOAD) : { *ai-startup-missionconditionprotectcar.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
