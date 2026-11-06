OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-shop/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN23retail_shop_transitions16civPassive_transE = 0x0041e910;
_ZN23retail_shop_transitions17scriptedNpc_transE = 0x0041ea3c;
_ZN23retail_shop_transitions19civAggressive_transE = 0x0041ea6c;
_ZN23retail_shop_transitions16gangMember_transE = 0x0041eb50;
_ZN23retail_shop_transitions9cop_transE = 0x0041eb5c;
_ZN23retail_shop_transitions10swat_transE = 0x0041ec94;
_ZN23retail_shop_transitions17civ_vehicle_transE = 0x0041eca0;
_ZN23retail_shop_transitions17cop_vehicle_transE = 0x0041ed30;
_ZN23retail_shop_transitions11guard_transE = 0x0041ede4;
_ZN23retail_shop_transitions22scripted_vehicle_transE = 0x0041ee8c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .state_machine_singleton 0x002d44c4 : { *ai-startup-shop.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x00305d18 : { *ai-startup-shop.o(.text.__tcf_0) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-shop.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-shop.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .ai_startup_function_0 0x00306310 : { *ai-startup-shop.o(.text.__tcf_4) }
    .ai_startup_function_1 0x003061b8 : { *ai-startup-shop.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003062fc : { *ai-startup-shop.o(.text._GLOBAL__I__ZN4Shop15s_numShopWeaponE) }
    .ai_startup_storage_0 0x004b819c (NOLOAD) : { *ai-startup-shop.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b81bc (NOLOAD) : { *ai-startup-shop.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b81c8 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b81d0 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b81d8 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b81e0 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b81e8 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b81f0 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b81f8 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b8200 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b8208 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b8210 (NOLOAD) : { *ai-startup-shop.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
