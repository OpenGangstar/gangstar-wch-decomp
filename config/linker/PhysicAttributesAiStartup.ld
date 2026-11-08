OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-physicattributes/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_Znwj = 0x001c4814;
__aeabi_atexit = 0x001c494c;
_ZN35retail_physicattributes_transitions16civPassive_transE = 0x00420aa4;
_ZN35retail_physicattributes_transitions17scriptedNpc_transE = 0x00420bd0;
_ZN35retail_physicattributes_transitions19civAggressive_transE = 0x00420c00;
_ZN35retail_physicattributes_transitions16gangMember_transE = 0x00420ce4;
_ZN35retail_physicattributes_transitions9cop_transE = 0x00420cf0;
_ZN35retail_physicattributes_transitions10swat_transE = 0x00420e28;
_ZN35retail_physicattributes_transitions17civ_vehicle_transE = 0x00420e34;
_ZN35retail_physicattributes_transitions17cop_vehicle_transE = 0x00420ec4;
_ZN35retail_physicattributes_transitions11guard_transE = 0x00420f78;
_ZN35retail_physicattributes_transitions22scripted_vehicle_transE = 0x00421020;
INCLUDE config/linker/PhysicAttributesResetSections.ld
SECTIONS
{
    .physic_init_world 0x0031a950 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes9InitWorldEv) }
    .physic_attributes_find_scene_node 0x0031b3a0 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes18GetSceneNodeFromIDEPN3irr5scene10ISceneNodeEi) }
    .physic_attributes_set_info 0x0031eb14 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes13SetPhysicInfoERK10PhysicInfoi) }
    .physic_attributes_get_height_from 0x00320040 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes13GetHeightFromEiRKN3irr4core8vector3dIfEEi) }
    .physic_attributes_on_ground 0x00319888 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes13SetIsOnGroundEib) }
    .ai_startup_function_0 0x003199f0 : { *ai-startup-physicattributes.o(.text.__tcf_3) }
    .ai_startup_function_1 0x0031d648 : { *ai-startup-physicattributes.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0031d78c : { *ai-startup-physicattributes.o(.text._GLOBAL__I__ZN16PhysicAttributes11s_neighborsE) }
    .ai_startup_storage_0 0x004b8af4 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b8b14 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b8b20 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b8b28 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b8b30 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b8b38 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b8b40 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b8b48 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b8b50 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b8b58 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b8b60 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b8b68 (NOLOAD) : { *ai-startup-physicattributes.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
