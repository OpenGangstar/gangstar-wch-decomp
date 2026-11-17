OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-ambulancesidemission/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN39retail_ambulancesidemission_transitions16civPassive_transE = 0x004342ac;
_ZN39retail_ambulancesidemission_transitions17scriptedNpc_transE = 0x004343d8;
_ZN39retail_ambulancesidemission_transitions19civAggressive_transE = 0x00434408;
_ZN39retail_ambulancesidemission_transitions16gangMember_transE = 0x004344ec;
_ZN39retail_ambulancesidemission_transitions9cop_transE = 0x004344f8;
_ZN39retail_ambulancesidemission_transitions10swat_transE = 0x00434630;
_ZN39retail_ambulancesidemission_transitions17civ_vehicle_transE = 0x0043463c;
_ZN39retail_ambulancesidemission_transitions17cop_vehicle_transE = 0x004346cc;
_ZN39retail_ambulancesidemission_transitions11guard_transE = 0x00434780;
_ZN39retail_ambulancesidemission_transitions22scripted_vehicle_transE = 0x00434828;
__cxa_pure_virtual = 0x00000000;
__stack_chk_fail = 0x001c42e0;
__aeabi_fsub = 0x001c4328;
__aeabi_fmul = 0x001c4724;
__aeabi_fadd = 0x001c4154;
__aeabi_f2d = 0x001c48f8;
__aeabi_idiv = 0x001c43dc;
__aeabi_idivmod = 0x001c4934;
sqrt = 0x001c401c;
sprintf = 0x001c46ac;
ambulanceMissionTimerFormat = 0x0042ad20;
SECTIONS
{
    .side_entry_346570 0x00346570 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMissionD1Ev .text._ZN20AmbulanceSideMissionD2Ev) }
    .ambulance_pickup 0x00346394 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission6pickUpEN3irr4core8vector3dIfEERiRfi) }
    .side_entry_345f94 0x00345f94 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission5cleanEv) }
    .side_entry_345fa8 0x00345fa8 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission7dropOffEN3irr4core8vector3dIfEE) }
    .side_entry_345fd4 0x00345fd4 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission5beginEN3irr4core8vector3dIfEEiRiRf) }
    .side_entry_3461f8 0x003461f8 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMissionC1Ev .text._ZN20AmbulanceSideMissionC2Ev) }
    .side_mission_base_vtable 0x004ad1e0 : { *(.gnu.linkonce.d.rel.ro._ZTV11SideMission .data.rel.ro._ZTV11SideMission) }
    .derived_side_mission_vtable 0x004ad1a8 : { *(.data.rel.ro._ZTV20AmbulanceSideMission) }
    .side_mission_obj2_message 0x00345f5c : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission14getObj2MessageEv) }
    .side_mission_obj1_message 0x00345f54 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission14getObj1MessageEv) }
    .side_mission_end_message 0x00345f4c : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission13getEndMessageEv) }
    .side_mission_start_message 0x00345f44 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission15getStartMessageEv) }
    .side_mission_end 0x00345f30 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission3endEv) }
    .side_mission_reward 0x00345f34 : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission14getMoneyRewardEv) }
    .side_mission_goal_message 0x00345f3c : { *ai-startup-ambulancesidemission.o(.text._ZN20AmbulanceSideMission14getGoalMessageEv) }
    .ai_startup_function_0 0x00345f64 : { *ai-startup-ambulancesidemission.o(.text.__tcf_3) }
    .ai_startup_function_1 0x0034623c : { *ai-startup-ambulancesidemission.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00346380 : { *ai-startup-ambulancesidemission.o(.text._GLOBAL__I__ZN20AmbulanceSideMissionC2Ev) }
    .ai_startup_storage_0 0x004bb488 (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004bb4a8 (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004bb4b4 (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004bb4bc (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004bb4c4 (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004bb4cc (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004bb4d4 (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004bb4dc (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004bb4e4 (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004bb4ec (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004bb4f4 (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004bb4fc (NOLOAD) : { *ai-startup-ambulancesidemission.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
