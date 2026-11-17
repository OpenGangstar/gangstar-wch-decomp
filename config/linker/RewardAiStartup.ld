OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-reward/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_Znwj = 0x001c4814;
__aeabi_dsub = 0x001c4454;
__aeabi_d2iz = 0x001c4844;
__aeabi_i2d = 0x1c452c;
__aeabi_atexit = 0x001c494c;
_ZN25retail_reward_transitions16civPassive_transE = 0x00424798;
_ZN25retail_reward_transitions17scriptedNpc_transE = 0x004248c4;
_ZN25retail_reward_transitions19civAggressive_transE = 0x004248f4;
_ZN25retail_reward_transitions16gangMember_transE = 0x004249d8;
_ZN25retail_reward_transitions9cop_transE = 0x004249e4;
_ZN25retail_reward_transitions10swat_transE = 0x00424b1c;
_ZN25retail_reward_transitions17civ_vehicle_transE = 0x00424b28;
_ZN25retail_reward_transitions17cop_vehicle_transE = 0x00424bb8;
_ZN25retail_reward_transitions11guard_transE = 0x00424c6c;
_ZN25retail_reward_transitions22scripted_vehicle_transE = 0x00424d14;
SECTIONS
{
    .reward_set_anim 0x0032ad64 : { *ai-startup-reward.o(.text._ZN6Reward7setAnimEi) }
    .reward_set_message 0x0032ad74 : { *ai-startup-reward.o(.text._ZN6Reward10setMessageEii) }
    .reward_draw_thunk 0x0032ad9c : { *ai-startup-reward.o(.text._ZThn4_NK6Reward6draw2dEv) }
    .reward_draw 0x0032adb0 : { *ai-startup-reward.o(.text._ZNK6Reward6draw2dEv) }
    .reward_update 0x0032addc : { *ai-startup-reward.o(.text._ZN6Reward6updateEd) }
    .reward_constructor 0x0032ae68 : { *ai-startup-reward.o(.text._ZN6RewardC2EP7ASpritei .text._ZN6RewardC1EP7ASpritei) }
    .reward_delete_thunk 0x0032b068 : { *ai-startup-reward.o(.text._ZThn4_N6RewardD0Ev) }
    .reward_delete 0x0032b07c : { *ai-startup-reward.o(.text._ZN6RewardD0Ev) }
    .reward_destructor_thunk 0x0032b0cc : { *ai-startup-reward.o(.text._ZThn4_N6RewardD1Ev) }
    .reward_destructor 0x0032b0e0 : { *ai-startup-reward.o(.text._ZN6RewardD2Ev .text._ZN6RewardD1Ev) }
    .reward_vtable 0x004ac630 : { *ai-startup-reward.o(.data.rel.ro._ZTV6Reward .gnu.linkonce.d.rel.ro._ZTV6Reward) }
    .ai_startup_function_0 0x0032ad34 : { *ai-startup-reward.o(.text.__tcf_3) }
    .ai_startup_function_1 0x0032af10 : { *ai-startup-reward.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0032b054 : { *ai-startup-reward.o(.text._GLOBAL__I__ZN6RewardC2EP7ASpritei) }
    .ai_startup_storage_0 0x004b9664 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9684 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9690 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9698 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b96a0 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b96a8 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b96b0 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b96b8 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b96c0 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b96c8 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b96d0 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b96d8 (NOLOAD) : { *ai-startup-reward.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
