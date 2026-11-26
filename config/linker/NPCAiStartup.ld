PROVIDE(__aeabi_fadd = 0x001c4154);
PROVIDE(__aeabi_fcmpeq = 0x001c470c);
PROVIDE(__aeabi_fcmplt = 0x001c479c);
PROVIDE(__aeabi_fmul = 0x001c4724);
PROVIDE(__aeabi_fsub = 0x001c4328);
PROVIDE(__aeabi_i2f = 0x001c41e4);
PROVIDE(__aeabi_idiv = 0x001c43dc);
PROVIDE(__aeabi_idivmod = 0x001c4934);
PROVIDE(__aeabi_uidiv = 0x001c4604);
PROVIDE(lrand48 = 0x001c4664);
PROVIDE(__aeabi_fcmpgt = 0x001c419c);
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-npc/retail-symbols.ld
_ZdlPv = 0x001c42b0;
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
memset = 0x001c45d4;
memcpy = 0x001c4190;
__aeabi_fdiv = 0x001c4520;
INCLUDE config/linker/CharacterStateSections.ld
INCLUDE config/linker/NPCTargetEventSections.ld
INCLUDE config/linker/NPCFunctionSections.ld
SECTIONS
{
    .physic_get_height 0x0031ff48 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes9GetHeightERKN3irr4core8vector3dIfEEib) }
    .npc_update 0x002ffe0c : { *ai-startup-npc.o(.text._ZN3NPC6UpdateEi) }
    .physic_get_tri_center 0x0031a4cc : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes12GetTriCenterEtt) }
    .physic_get_random_destination 0x0031aa5c : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes20GetRandomDestinationEtRtRKN3irr4core8vector3dIfEEff) }
    .physic_next_random_pos 0x0031cf74 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes16GetNextRandomPosEiiN3irr4core8vector3dIfEE) }
    .character_run_to_target 0x002f39e0 : { *ai-startup-character.o(.text._ZN9Character11runToTargetEi) }
    .npc_attack_target 0x002ff5d0 : { *ai-startup-npc.o(.text._ZN3NPC12attackTargetEv) }
    .contact_filter_should_collide 0x0031dc7c : { *ai-startup-physicattributes.o(.text._ZN13ContactFilter13ShouldCollideEP7b2ShapeS1_) }
    .physic_jump_shape 0x0031ccf0 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes19SetCurrentJumpShapeEP7b2Shape) }
    .contact_filter_vtable 0x004abd00 : { *ai-startup-physicattributes.o(.data.rel.ro._ZTV13ContactFilter) }
    .character_shoot 0x002f55d0 : { *ai-startup-character.o(.text._ZN9Character5shootEfb) }
    .character_shoot_tables 0x0041bfd0 : { *ai-startup-character.o(.rodata._ZN9Character5shootEfb) }
    .npc_car_under_wheel 0x002fe784 : { *ai-startup-npc.o(.text._ZN3NPC24UpdateCarPosIfUnderWheelEv) }
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
    /* Character startup is verified in its own image. Keep only the state methods here. */
    /DISCARD/ : { *ai-startup-character.o(*) *ai-startup-physicattributes.o(*) }
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
ASSERT(SIZEOF(.npc_freeze) == 224, "NPC freeze native extent");
ASSERT(ADDR(.npc_freeze) + SIZEOF(.npc_freeze) == 0x002fea78, "NPC freeze next boundary");

ASSERT(SIZEOF(.npc_combat_sfx) == 368, "NPC combat SFX native extent");
ASSERT(ADDR(.npc_combat_sfx) + SIZEOF(.npc_combat_sfx) == 0x002fe784, "NPC combat SFX next function");
ASSERT(SIZEOF(.npc_combat_sfx_table) == 28, "NPC combat SFX switch table extent");
ASSERT(SIZEOF(.npc_combat_sfx_timer) == 4, "NPC combat SFX timer extent");
ASSERT(SIZEOF(.npc_outside_search_radius) == 172, "Native NPC isOutsideSearchRadius extent");
ASSERT(SIZEOF(.npc_is_under_car) == 416, "Native NPC isUnderCar extent");
