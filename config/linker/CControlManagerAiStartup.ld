OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-ccontrolmanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN34retail_ccontrolmanager_transitions16civPassive_transE = 0x004253a8;
_ZN34retail_ccontrolmanager_transitions17scriptedNpc_transE = 0x004254d4;
_ZN34retail_ccontrolmanager_transitions19civAggressive_transE = 0x00425504;
_ZN34retail_ccontrolmanager_transitions16gangMember_transE = 0x004255e8;
_ZN34retail_ccontrolmanager_transitions9cop_transE = 0x004255f4;
_ZN34retail_ccontrolmanager_transitions10swat_transE = 0x0042572c;
_ZN34retail_ccontrolmanager_transitions17civ_vehicle_transE = 0x00425738;
_ZN34retail_ccontrolmanager_transitions17cop_vehicle_transE = 0x004257c8;
_ZN34retail_ccontrolmanager_transitions11guard_transE = 0x0042587c;
_ZN34retail_ccontrolmanager_transitions22scripted_vehicle_transE = 0x00425924;
__cxa_pure_virtual = 0;
SECTIONS
{
    .control_manager_camera_proxy 0x0032d1b8 : { *(.text._ZN15CControlManager14setCameraProxyEP9GS3DStuff) }
    .control_manager_lock 0x0032d1bc : { *(.text._ZN15CControlManager4lockEv) }
    .control_manager_is_locked 0x0032d1e8 : { *(.text._ZNK15CControlManager8isLockedEv) }
    .control_handler_delete 0x0032e468 : { *(.gnu.linkonce.t._ZN15IControlHandlerD0Ev) }
    .control_handler_destructor 0x0032e494 : { *(.gnu.linkonce.t._ZN15IControlHandlerD1Ev) }
    .control_handler_vtable 0x004aca98 : { *(.gnu.linkonce.d.rel.ro._ZTV15IControlHandler) }
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_destructor 0x002db4d4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD1Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .control_manager_destructor 0x0032d6f4 : { *ai-startup-ccontrolmanager.o(.text._ZN15CControlManagerD1Ev) }
    .ai_startup_function_0 0x0032d6c4 : { *ai-startup-ccontrolmanager.o(.text.__tcf_3) }
    .ai_startup_function_1 0x0032d56c : { *ai-startup-ccontrolmanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0032d6b0 : { *ai-startup-ccontrolmanager.o(.text._GLOBAL__I__ZN15CControlManager16s_sniperTutorialE) }
    .ai_startup_storage_0 0x004b9888 (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b98a8 (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b98b4 (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b98bc (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b98c4 (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b98cc (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b98d4 (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b98dc (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b98e4 (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b98ec (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b98f4 (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b98fc (NOLOAD) : { *ai-startup-ccontrolmanager.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
