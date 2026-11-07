OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-copvehiclecontroller/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN39retail_copvehiclecontroller_transitions16civPassive_transE = 0x00431244;
_ZN39retail_copvehiclecontroller_transitions17scriptedNpc_transE = 0x00431370;
_ZN39retail_copvehiclecontroller_transitions19civAggressive_transE = 0x004313a0;
_ZN39retail_copvehiclecontroller_transitions16gangMember_transE = 0x00431484;
_ZN39retail_copvehiclecontroller_transitions9cop_transE = 0x00431490;
_ZN39retail_copvehiclecontroller_transitions10swat_transE = 0x004315c8;
_ZN39retail_copvehiclecontroller_transitions17civ_vehicle_transE = 0x004315d4;
_ZN39retail_copvehiclecontroller_transitions17cop_vehicle_transE = 0x00431664;
_ZN39retail_copvehiclecontroller_transitions11guard_transE = 0x00431718;
_ZN39retail_copvehiclecontroller_transitions22scripted_vehicle_transE = 0x004317c0;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .cop_vehicle_construct 0x0034185c : { *(.text._ZN20CopVehicleControllerC1EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE .text._ZN20CopVehicleControllerC2EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE) }
    .cop_vehicle_delete 0x003417ac : { *(.text._ZN20CopVehicleControllerD0Ev) }
    .cop_vehicle_destroy 0x00341808 : { *(.text._ZN20CopVehicleControllerD1Ev .text._ZN20CopVehicleControllerD2Ev) }
    .cop_vehicle_vtable 0x004acfe0 : { *(.data.rel.ro._ZTV20CopVehicleController) }
    .wanted_singleton 0x002dba04 : { *ai-startup-copvehiclecontroller.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x00341700 : { *ai-startup-copvehiclecontroller.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .ai_startup_function_0 0x00341a0c : { *ai-startup-copvehiclecontroller.o(.text.__tcf_5) }
    .ai_startup_function_1 0x003418b4 : { *ai-startup-copvehiclecontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003419f8 : { *ai-startup-copvehiclecontroller.o(.text._GLOBAL__I__ZN20CopVehicleControllerC2EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE) }
    .ai_startup_storage_0 0x004ba87c (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_1 0x004ba884 (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_2 0x004ba8cc (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_3 0x004ba88c (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_4 0x004ba894 (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_5 0x004ba89c (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_6 0x004ba8a4 (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_7 0x004ba8ac (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_8 0x004ba8b4 (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_9 0x004ba8bc (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_10 0x004ba8c4 (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_11 0x004ba8ec (NOLOAD) : { *ai-startup-copvehiclecontroller.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 12, "_ZN3irr2ps5vHalfE extent");
