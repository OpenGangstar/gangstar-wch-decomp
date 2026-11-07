OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-vehiclecontroller/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN36retail_vehiclecontroller_transitions16civPassive_transE = 0x00432410;
_ZN36retail_vehiclecontroller_transitions17scriptedNpc_transE = 0x0043253c;
_ZN36retail_vehiclecontroller_transitions19civAggressive_transE = 0x0043256c;
_ZN36retail_vehiclecontroller_transitions16gangMember_transE = 0x00432650;
_ZN36retail_vehiclecontroller_transitions9cop_transE = 0x0043265c;
_ZN36retail_vehiclecontroller_transitions10swat_transE = 0x00432794;
_ZN36retail_vehiclecontroller_transitions17civ_vehicle_transE = 0x004327a0;
_ZN36retail_vehiclecontroller_transitions17cop_vehicle_transE = 0x00432830;
_ZN36retail_vehiclecontroller_transitions11guard_transE = 0x004328e4;
_ZN36retail_vehiclecontroller_transitions22scripted_vehicle_transE = 0x0043298c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
__cxa_pure_virtual = 0;
__aeabi_idivmod = 0x001c4934;
SECTIONS
{
    .vehicle_controller_next_point 0x0034264c : { *(.text._ZN17VehicleController12getNextPointEv) }
    .vehicle_controller_waypoint 0x00342514 : { *(.text._ZN17VehicleController15getNextWaypointEv) }
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .vehicle_controller_construct 0x00342818 : { *(.text._ZN17VehicleControllerC1EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE .text._ZN17VehicleControllerC2EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE) }
    .vehicle_controller_delete 0x003429c4 : { *(.text._ZN17VehicleControllerD0Ev) }
    .vehicle_controller_destroy 0x00342a14 : { *(.text._ZN17VehicleControllerD1Ev .text._ZN17VehicleControllerD2Ev) }
    .vehicle_controller_vtable 0x004ad030 : { *(.data.rel.ro._ZTV17VehicleController) }
    .ai_manager_singleton 0x002dbae8 : { *ai-startup-vehiclecontroller.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x00342568 : { *ai-startup-vehiclecontroller.o(.text.__tcf_0) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .ai_startup_function_0 0x003424e4 : { *ai-startup-vehiclecontroller.o(.text.__tcf_4) }
    .ai_startup_function_1 0x0034286c : { *ai-startup-vehiclecontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003429b0 : { *ai-startup-vehiclecontroller.o(.text._GLOBAL__I__ZN17VehicleControllerC2EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE) }
    .ai_startup_storage_0 0x004baa40 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba9f0 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_2 0x004ba9f8 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_3 0x004baa00 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_4 0x004baa08 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_5 0x004baa10 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_6 0x004baa18 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_7 0x004baa20 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_8 0x004baa28 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_9 0x004baa30 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_10 0x004baa38 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_11 0x004baa60 (NOLOAD) : { *ai-startup-vehiclecontroller.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 12, "_ZN3irr2ps5vHalfE extent");
