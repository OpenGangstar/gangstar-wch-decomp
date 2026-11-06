OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditionphotographquickly/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN52retail_missionconditionphotographquickly_transitions16civPassive_transE = 0x0042b9a0;
_ZN52retail_missionconditionphotographquickly_transitions17scriptedNpc_transE = 0x0042bacc;
_ZN52retail_missionconditionphotographquickly_transitions19civAggressive_transE = 0x0042bafc;
_ZN52retail_missionconditionphotographquickly_transitions16gangMember_transE = 0x0042bbe0;
_ZN52retail_missionconditionphotographquickly_transitions9cop_transE = 0x0042bbec;
_ZN52retail_missionconditionphotographquickly_transitions10swat_transE = 0x0042bd24;
_ZN52retail_missionconditionphotographquickly_transitions17civ_vehicle_transE = 0x0042bd30;
_ZN52retail_missionconditionphotographquickly_transitions17cop_vehicle_transE = 0x0042bdc0;
_ZN52retail_missionconditionphotographquickly_transitions11guard_transE = 0x0042be74;
_ZN52retail_missionconditionphotographquickly_transitions22scripted_vehicle_transE = 0x0042bf1c;
sprintf = 0x001c46ac;
__stack_chk_fail = 0x001c42e0;
__aeabi_idiv = 0x001c43dc;
__aeabi_idivmod = 0x001c4934;
SECTIONS
{
    .mission_photo_0033739c 0x0033739c : { *ai-startup-missionconditionphotographquickly.o(.text._ZN33MissionConditionPhotographQuickly4drawEv) }
    .mission_photo_003373d0 0x003373d0 : { *ai-startup-missionconditionphotographquickly.o(.text._ZN33MissionConditionPhotographQuickly8evaluateEi) }
    .mission_photo_003374b4 0x003374b4 : { *ai-startup-missionconditionphotographquickly.o(.text._ZN33MissionConditionPhotographQuicklyC2EP11LevelObjecti .text._ZN33MissionConditionPhotographQuicklyC1EP11LevelObjecti) }
    .mission_photo_0033763c 0x0033763c : { *ai-startup-missionconditionphotographquickly.o(.text._ZN33MissionConditionPhotographQuicklyD0Ev) }
    .mission_photo_0033767c 0x0033767c : { *ai-startup-missionconditionphotographquickly.o(.text._ZN33MissionConditionPhotographQuicklyD2Ev .text._ZN33MissionConditionPhotographQuicklyD1Ev) }
    .mission_photo_vtable 0x004ace80 : { *ai-startup-missionconditionphotographquickly.o(.data.rel.ro._ZTV33MissionConditionPhotographQuickly) }
    .mission_photo_format 0x0042ad20 : { *ai-startup-missionconditionphotographquickly.o(.rodata.str1.4 .rodata.str1.1) }
    .ai_startup_function_0 0x003373a0 : { *ai-startup-missionconditionphotographquickly.o(.text.__tcf_3) }
    .ai_startup_function_1 0x003374e4 : { *ai-startup-missionconditionphotographquickly.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00337628 : { *ai-startup-missionconditionphotographquickly.o(.text._GLOBAL__I__ZN33MissionConditionPhotographQuicklyC2EP11LevelObjecti) }
    .ai_startup_storage_0 0x004ba0fc (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba11c (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba128 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba130 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba138 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba140 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba148 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba150 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba158 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba160 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba168 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba170 (NOLOAD) : { *ai-startup-missionconditionphotographquickly.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
