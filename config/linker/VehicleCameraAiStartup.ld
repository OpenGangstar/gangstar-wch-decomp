OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-vehiclecamera/retail-symbols.ld
INCLUDE config/linker/CameraSections.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN32retail_vehiclecamera_transitions16civPassive_transE = 0x0042a144;
_ZN32retail_vehiclecamera_transitions17scriptedNpc_transE = 0x0042a270;
_ZN32retail_vehiclecamera_transitions19civAggressive_transE = 0x0042a2a0;
_ZN32retail_vehiclecamera_transitions16gangMember_transE = 0x0042a384;
_ZN32retail_vehiclecamera_transitions9cop_transE = 0x0042a390;
_ZN32retail_vehiclecamera_transitions10swat_transE = 0x0042a4c8;
_ZN32retail_vehiclecamera_transitions17civ_vehicle_transE = 0x0042a4d4;
_ZN32retail_vehiclecamera_transitions17cop_vehicle_transE = 0x0042a564;
_ZN32retail_vehiclecamera_transitions11guard_transE = 0x0042a618;
_ZN32retail_vehiclecamera_transitions22scripted_vehicle_transE = 0x0042a6c0;
SECTIONS
{
    .camera_variant_debug 0x003350f8 : { *ai-startup-vehiclecamera.o(.text._ZN13VehicleCamera5debugEPN3irr5video12IVideoDriverE) }
    .camera_variant_dtor 0x003351bc : { *ai-startup-vehiclecamera.o(.text._ZN13VehicleCameraD1Ev .text._ZN13VehicleCameraD2Ev) }
    .ai_startup_function_0 0x00335170 : { *ai-startup-vehiclecamera.o(.text.__tcf_3) }
    .ai_startup_function_1 0x003354b4 : { *ai-startup-vehiclecamera.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003355f8 : { *ai-startup-vehiclecamera.o(.text._GLOBAL__I__ZN13VehicleCameraC2EP11LevelObject) }
    .ai_startup_storage_0 0x004b9f0c (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9f2c (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9f38 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9f40 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9f48 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9f50 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9f58 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9f60 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9f68 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9f70 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9f78 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9f80 (NOLOAD) : { *ai-startup-vehiclecamera.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
