OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-checkpoint/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN29retail_checkpoint_transitions16civPassive_transE = 0x0041cc10;
_ZN29retail_checkpoint_transitions17scriptedNpc_transE = 0x0041cd3c;
_ZN29retail_checkpoint_transitions19civAggressive_transE = 0x0041cd6c;
_ZN29retail_checkpoint_transitions16gangMember_transE = 0x0041ce50;
_ZN29retail_checkpoint_transitions9cop_transE = 0x0041ce5c;
_ZN29retail_checkpoint_transitions10swat_transE = 0x0041cf94;
_ZN29retail_checkpoint_transitions17civ_vehicle_transE = 0x0041cfa0;
_ZN29retail_checkpoint_transitions17cop_vehicle_transE = 0x0041d030;
_ZN29retail_checkpoint_transitions11guard_transE = 0x0041d0e4;
_ZN29retail_checkpoint_transitions22scripted_vehicle_transE = 0x0041d18c;
SECTIONS
{
    .checkpoint_base_spawn_type 0x002f74d0 : { *(.gnu.linkonce.t._ZN11LevelObject12getSpawnTypeEv) }
    .ai-startup-checkpoint_fn_0 0x002f7674 : { *(.text._ZN10CheckpointD0Ev) }
    .ai-startup-checkpoint_fn_1 0x002f769c : { *(.text._ZN10CheckpointD1Ev .text._ZN10CheckpointD2Ev) }
    .ai-startup-checkpoint_fn_2 0x002f76bc : { *(.text._ZN10CheckpointC1Ei .text._ZN10CheckpointC2Ei) }
    .ai-startup-checkpoint_fn_3 0x002f7600 : { *(.text._ZN10Checkpoint4LoadERKN7Structs10CheckpointE) }
    .ai-startup-checkpoint_fn_4 0x002f763c : { *(.text._ZN10Checkpoint13grabSceneNodeEiPPPv) }
    .ai-startup-checkpoint_fn_5 0x002f7538 : { *(.text._ZN10Checkpoint11SetPositionERKN3irr4core8vector3dIfEE) }
    .checkpoint_vtable 0x004aa178 : { *(.data.rel.ro._ZTV10Checkpoint) }
    .ai_startup_function_0 0x002f79b4 : { *ai-startup-checkpoint.o(.text.__tcf_3) }
    .ai_startup_function_1 0x002f785c : { *ai-startup-checkpoint.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x002f79a0 : { *ai-startup-checkpoint.o(.text._GLOBAL__I__ZN10Checkpoint18s_bTutoCallContactE) }
    .ai_startup_storage_0 0x004b7e58 (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b7e78 (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b7e84 (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b7e8c (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b7e94 (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b7e9c (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b7ea4 (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b7eac (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b7eb4 (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b7ebc (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b7ec4 (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b7ecc (NOLOAD) : { *ai-startup-checkpoint.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
