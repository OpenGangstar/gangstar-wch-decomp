OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-menustate/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN28retail_menustate_transitions16civPassive_transE = 0x0041a084;
_ZN28retail_menustate_transitions17scriptedNpc_transE = 0x0041a1b0;
_ZN28retail_menustate_transitions19civAggressive_transE = 0x0041a1e0;
_ZN28retail_menustate_transitions16gangMember_transE = 0x0041a2c4;
_ZN28retail_menustate_transitions9cop_transE = 0x0041a2d0;
_ZN28retail_menustate_transitions10swat_transE = 0x0041a408;
_ZN28retail_menustate_transitions17civ_vehicle_transE = 0x0041a414;
_ZN28retail_menustate_transitions17cop_vehicle_transE = 0x0041a4a4;
_ZN28retail_menustate_transitions11guard_transE = 0x0041a558;
_ZN28retail_menustate_transitions22scripted_vehicle_transE = 0x0041a600;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
INCLUDE config/linker/MenuWidgetFunctions.ld
INCLUDE config/linker/RenderFXAnimationFunctions.ld
SECTIONS
{
    .state_create 0x002e7310 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State6CreateEv) }
    .state_show 0x002e7314 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State4ShowEv) }
    .state_hide 0x002e7318 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State4HideEv) }
    .state_got_focus 0x002e731c : { *ai-startup-menustate.o(.text._ZN6MenuFX5State8GotFocusEv) }
    .state_lost_focus 0x002e7320 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State9LostFocusEv) }
    .state_update 0x002e7324 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State6UpdateEv) }
    .state_update_elapsed 0x002e7328 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State6UpdateEi) }
    .state_on_event 0x002e7338 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State7OnEventERN8RenderFX5EventE) }
    .state_on_fs_command 0x002e733c : { *ai-startup-menustate.o(.text._ZN6MenuFX5State11OnFSCommandEPKcS2_) }
    .state_can_handle_event 0x002e7340 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State14CanHandleEventERN8RenderFX5EventE) }
    .menu_state_is_modal 0x002e7344 : { *ai-startup-menustate.o(.text._ZNK9MenuState7IsModalEv) }
    .confirm_is_modal 0x002e7348 : { *ai-startup-menustate.o(.text._ZNK5Menus7Confirm7IsModalEv) }
    .menu_state_notify 0x002e734c : { *ai-startup-menustate.o(.text._ZN9MenuState6NotifyEPK10MenuWidgeti) }
    .menu_state_get_depth 0x002e7350 : { *ai-startup-menustate.o(.text._ZNK9MenuState8GetDepthEv) }
    .menu_state_update 0x002e9510 : { *ai-startup-menustate.o(.text._ZN9MenuState6UpdateEv) }
    .menu_state_create 0x002e9514 : { *ai-startup-menustate.o(.text._ZN9MenuState6CreateEv) }
    .confirm_confirmed 0x002e7384 : { *ai-startup-menustate.o(.text._ZNK5Menus7Confirm9ConfirmedEv) }
    .confirm_payment_get_widget 0x002e7414 : { *ai-startup-menustate.o(.text._ZN5Menus14ConfirmPayment9GetWidgetEv) }
    .confirm_get_widget 0x002e7438 : { *ai-startup-menustate.o(.text._ZN5Menus7Confirm9GetWidgetEv) }
    .confirm_payment_set_price 0x002e8528 : { *ai-startup-menustate.o(.text._ZN5Menus14ConfirmPayment8SetPriceEi) }
    .menu_dialog_set_message 0x002e75dc : { *ai-startup-menustate.o(.text._ZN5Menus6Dialog10SetMessageEi) }
    .state_machine_singleton 0x002d44c4 : { *ai-startup-menustate.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x002e745c : { *ai-startup-menustate.o(.text.__tcf_1) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .wanted_singleton 0x002dba04 : { *ai-startup-menustate.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x002e761c : { *ai-startup-menustate.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .ai_startup_function_0 0x002e73b0 : { *ai-startup-menustate.o(.text.__tcf_6) }
    .ai_startup_function_1 0x002e9564 : { *ai-startup-menustate.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x002e96a8 : { *ai-startup-menustate.o(.text._GLOBAL__I__ZN9MenuStateC2EPKc) }
    .ai_startup_storage_0 0x004b7c70 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b7c90 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b7c9c (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b7ca4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b7cac (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b7cb4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b7cbc (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b7cc4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b7ccc (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b7cd4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b7cdc (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b7ce4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    /DISCARD/ : { *ai-startup-menuwidget.o(*) }
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
