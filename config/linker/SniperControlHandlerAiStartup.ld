OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-snipercontrolhandler/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN39retail_snipercontrolhandler_transitions16civPassive_transE = 0x00426bfc;
_ZN39retail_snipercontrolhandler_transitions17scriptedNpc_transE = 0x00426d28;
_ZN39retail_snipercontrolhandler_transitions19civAggressive_transE = 0x00426d58;
_ZN39retail_snipercontrolhandler_transitions16gangMember_transE = 0x00426e3c;
_ZN39retail_snipercontrolhandler_transitions9cop_transE = 0x00426e48;
_ZN39retail_snipercontrolhandler_transitions10swat_transE = 0x00426f80;
_ZN39retail_snipercontrolhandler_transitions17civ_vehicle_transE = 0x00426f8c;
_ZN39retail_snipercontrolhandler_transitions17cop_vehicle_transE = 0x0042701c;
_ZN39retail_snipercontrolhandler_transitions11guard_transE = 0x004270d0;
_ZN39retail_snipercontrolhandler_transitions22scripted_vehicle_transE = 0x00427178;
__cxa_pure_virtual = 0;
SECTIONS
{
    .handler_deactivate 0x0032f120 : { *(.text._ZN20SniperControlHandler10deactivateEv) }
    .handler_delete 0x0032f5a8 : { *(.text._ZN20SniperControlHandlerD0Ev) }
    .handler_destructor 0x0032f5e0 : { *(.text._ZN20SniperControlHandlerD1Ev .text._ZN20SniperControlHandlerD2Ev) }
    .handler_vtable 0x004acad8 : { *(.data.rel.ro._ZTV20SniperControlHandler) }
    .control_handler_delete 0x0032e468 : { *(.gnu.linkonce.t._ZN15IControlHandlerD0Ev) }
    .control_handler_destructor 0x0032e494 : { *(.gnu.linkonce.t._ZN15IControlHandlerD1Ev) }
    .control_handler_vtable 0x004aca98 : { *(.gnu.linkonce.d.rel.ro._ZTV15IControlHandler) }
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_destructor 0x002db4d4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD1Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .ai_startup_function_0 0x0032f578 : { *ai-startup-snipercontrolhandler.o(.text.__tcf_5) }
    .ai_startup_function_1 0x0032f420 : { *ai-startup-snipercontrolhandler.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0032f564 : { *ai-startup-snipercontrolhandler.o(.text._GLOBAL__I__ZN20SniperControlHandlerC2EP15CControlManager) }
    .ai_startup_storage_0 0x004b9a2c (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9a4c (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9a58 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9a60 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9a68 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9a70 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9a78 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9a80 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9a88 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9a90 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9a98 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9aa0 (NOLOAD) : { *ai-startup-snipercontrolhandler.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
