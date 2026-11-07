OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-npc/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_idivmod = 0x001c4934;
__aeabi_atexit = 0x001c494c;
_ZN22retail_npc_transitions16civPassive_transE = 0x0041d918;
_ZN22retail_npc_transitions17scriptedNpc_transE = 0x0041da44;
_ZN22retail_npc_transitions19civAggressive_transE = 0x0041da74;
_ZN22retail_npc_transitions16gangMember_transE = 0x0041db58;
_ZN22retail_npc_transitions9cop_transE = 0x0041db64;
_ZN22retail_npc_transitions10swat_transE = 0x0041dc9c;
_ZN22retail_npc_transitions17civ_vehicle_transE = 0x0041dca8;
_ZN22retail_npc_transitions17cop_vehicle_transE = 0x0041dd38;
_ZN22retail_npc_transitions11guard_transE = 0x0041ddec;
_ZN22retail_npc_transitions22scripted_vehicle_transE = 0x0041de94;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .npc_photographed 0x002fd448 : { *ai-startup-npc.o(.text._ZN3NPC12photographedEv) }
    .npc_clear_photographed 0x002fd458 : { *ai-startup-npc.o(.text._ZN3NPC17clearPhotographedEv) }
    .npc_is_photographed 0x002fd46c : { *ai-startup-npc.o(.text._ZNK3NPC14isPhotographedEv) }
    .npc_go_to_location 0x002fd478 : { *ai-startup-npc.o(.text._ZN3NPC12goToLocationERKN3irr4core8vector3dIfEE) }
    .npc_run_to_location 0x002fd788 : { *ai-startup-npc.o(.text._ZN3NPC13runToLocationERKN3irr4core8vector3dIfEE) }
    .npc_walk_to_location 0x002fd7c4 : { *ai-startup-npc.o(.text._ZN3NPC14walkToLocationERKN3irr4core8vector3dIfEE) }
    .npc_next_waypoint 0x002fdde8 : { *ai-startup-npc.o(.text._ZN3NPC15getNextWaypointEv) }
    .npc_next_point 0x002fdff0 : { *ai-startup-npc.o(.text._ZN3NPC12getNextPointERN3irr4core8vector3dIfEE) }
    .npc_go_next_point 0x002fe084 : { *ai-startup-npc.o(.text._ZN3NPC13goToNextPointEb) }
    .npc_get_path 0x002fd4f8 : { *ai-startup-npc.o(.text._ZNK3NPC15getPathToFollowEv) }
    .npc_set_waypoint 0x002fd500 : { *ai-startup-npc.o(.text._ZN3NPC18setCurrentWaypointEi) }
    .npc_get_waypoint 0x002fd508 : { *ai-startup-npc.o(.text._ZNK3NPC18getCurrentWaypointEv) }
    .npc_set_loop 0x002fd510 : { *ai-startup-npc.o(.text._ZN3NPC16loopPathToFollowEb) }
    .npc_set_path 0x002fd538 : { *ai-startup-npc.o(.text._ZN3NPC15setPathToFollowEPK4Path) }
    .npc_get_loop 0x002fd558 : { *ai-startup-npc.o(.text._ZNK3NPC23isLoopingOnPathToFollowEv) }
    .ai_manager_singleton 0x002dbae8 : { *ai-startup-npc.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x002fd6f0 : { *ai-startup-npc.o(.text.__tcf_0) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *ai-startup-npc.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *ai-startup-npc.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .ai_startup_function_0 0x002fe968 : { *ai-startup-npc.o(.text.__tcf_4) }
    .ai_startup_function_1 0x002fe4bc : { *ai-startup-npc.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x002fe600 : { *ai-startup-npc.o(.text._GLOBAL__I__ZN3NPC16s_combatSXFTimerE) }
    .ai_startup_storage_0 0x004b8040 (NOLOAD) : { *ai-startup-npc.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b8060 (NOLOAD) : { *ai-startup-npc.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b806c (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b8074 (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b807c (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b8084 (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b808c (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b8094 (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b809c (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b80a4 (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b80ac (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b80b4 (NOLOAD) : { *ai-startup-npc.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
