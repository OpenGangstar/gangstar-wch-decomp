OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-lockcamera/retail-symbols.ld
__aeabi_fadd = 0x001c4154;
__aeabi_fsub = 0x001c4328;
__aeabi_fmul = 0x001c4724;
INCLUDE config/linker/CameraSections.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN29retail_lockcamera_transitions16civPassive_transE = 0x00429b74;
_ZN29retail_lockcamera_transitions17scriptedNpc_transE = 0x00429ca0;
_ZN29retail_lockcamera_transitions19civAggressive_transE = 0x00429cd0;
_ZN29retail_lockcamera_transitions16gangMember_transE = 0x00429db4;
_ZN29retail_lockcamera_transitions9cop_transE = 0x00429dc0;
_ZN29retail_lockcamera_transitions10swat_transE = 0x00429ef8;
_ZN29retail_lockcamera_transitions17civ_vehicle_transE = 0x00429f04;
_ZN29retail_lockcamera_transitions17cop_vehicle_transE = 0x00429f94;
_ZN29retail_lockcamera_transitions11guard_transE = 0x0042a048;
_ZN29retail_lockcamera_transitions22scripted_vehicle_transE = 0x0042a0f0;
SECTIONS
{
    .lock_camera_vtable 0x004accf0 : { *ai-startup-lockcamera.o(.data.rel.ro._ZTV10LockCamera) }
    .lock_camera_debug 0x00334a2c : { *ai-startup-lockcamera.o(.text._ZN10LockCamera5debugEPN3irr5video12IVideoDriverE) }
    .lock_camera_destructor 0x00334a60 : { *ai-startup-lockcamera.o(.text._ZN10LockCameraD1Ev .text._ZN10LockCameraD2Ev) }
    .lock_camera_init 0x00334a80 : { *ai-startup-lockcamera.o(.text._ZN10LockCamera4initEP11LevelObjecti) }
    ASSERT(SIZEOF(.lock_camera_init) == 376, "Native LockCamera init extent")
    .lock_camera_constructor 0x00334bf8 : { *ai-startup-lockcamera.o(.text._ZN10LockCameraC1EP11LevelObject .text._ZN10LockCameraC2EP11LevelObject) }
    .lock_camera_update 0x00334c24 : { *ai-startup-lockcamera.o(.text._ZN10LockCamera6updateEf) }
    ASSERT(SIZEOF(.lock_camera_update) == 360, "Native LockCamera update extent")
    .ai_startup_function_0 0x00334a30 : { *ai-startup-lockcamera.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00334d8c : { *ai-startup-lockcamera.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00334ed0 : { *ai-startup-lockcamera.o(.text._GLOBAL__I__ZN10LockCameraC2EP11LevelObject) }
    .ai_startup_storage_0 0x004b9e64 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9e84 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9e90 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9e98 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9ea0 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9ea8 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9eb0 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9eb8 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9ec0 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9ec8 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9ed0 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9ed8 (NOLOAD) : { *ai-startup-lockcamera.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
