OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-mission/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN26retail_mission_transitions16civPassive_transE = 0x0042a72c;
_ZN26retail_mission_transitions17scriptedNpc_transE = 0x0042a858;
_ZN26retail_mission_transitions19civAggressive_transE = 0x0042a888;
_ZN26retail_mission_transitions16gangMember_transE = 0x0042a96c;
_ZN26retail_mission_transitions9cop_transE = 0x0042a978;
_ZN26retail_mission_transitions10swat_transE = 0x0042aab0;
_ZN26retail_mission_transitions17civ_vehicle_transE = 0x0042aabc;
_ZN26retail_mission_transitions17cop_vehicle_transE = 0x0042ab4c;
_ZN26retail_mission_transitions11guard_transE = 0x0042ac00;
_ZN26retail_mission_transitions22scripted_vehicle_transE = 0x0042aca8;
SECTIONS
{
    .ai_startup_function_0 0x00335d24 : { *ai-startup-mission.o(.text.__tcf_4) }
    .ai_startup_function_1 0x00336808 : { *ai-startup-mission.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0033694c : { *ai-startup-mission.o(.text._GLOBAL__I__Z18getFrameModuleRectP7ASpriteiii) }
    .mission_rct_1 0x00335d54 : { *ai-startup-mission.o(.text._ZN3RctIiED0Ev .gnu.linkonce.t._ZN3RctIiED0Ev) }
    .mission_rct_2 0x00335d74 : { *ai-startup-mission.o(.text._ZN3RctIiED1Ev .gnu.linkonce.t._ZN3RctIiED1Ev) }
    .mission_rct_vtable 0x004ace10 : { *ai-startup-mission.o(.data.rel.ro._ZTV3RctIiE .gnu.linkonce.d._ZTV3RctIiE .gnu.linkonce.d.rel.ro._ZTV3RctIiE .rodata._ZTV3RctIiE .gnu.linkonce.r._ZTV3RctIiE) }
    .ai_startup_storage_0 0x004b9f88 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9fa8 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9fb4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9fbc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9fc4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9fcc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9fd4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9fdc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9fe4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9fec (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9ff4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9ffc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
