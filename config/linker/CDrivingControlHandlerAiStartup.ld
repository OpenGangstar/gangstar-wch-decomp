OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-cdrivingcontrolhandler/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN41retail_cdrivingcontrolhandler_transitions16civPassive_transE = 0x00425c58;
_ZN41retail_cdrivingcontrolhandler_transitions17scriptedNpc_transE = 0x00425d84;
_ZN41retail_cdrivingcontrolhandler_transitions19civAggressive_transE = 0x00425db4;
_ZN41retail_cdrivingcontrolhandler_transitions16gangMember_transE = 0x00425e98;
_ZN41retail_cdrivingcontrolhandler_transitions9cop_transE = 0x00425ea4;
_ZN41retail_cdrivingcontrolhandler_transitions10swat_transE = 0x00425fdc;
_ZN41retail_cdrivingcontrolhandler_transitions17civ_vehicle_transE = 0x00425fe8;
_ZN41retail_cdrivingcontrolhandler_transitions17cop_vehicle_transE = 0x00426078;
_ZN41retail_cdrivingcontrolhandler_transitions11guard_transE = 0x0042612c;
_ZN41retail_cdrivingcontrolhandler_transitions22scripted_vehicle_transE = 0x004261d4;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
__cxa_pure_virtual = 0;
SECTIONS
{
    .driving_disable_accelerometer 0x0032d944 : { *ai-startup-cdrivingcontrolhandler.o(.text._ZN22CDrivingControlHandler20disableAccelerometerEv) }
    .driving_held 0x0032d924 : { *ai-startup-cdrivingcontrolhandler.o(.text._ZN22CDrivingControlHandler16handleAttackHeldEv) }
    .driving_pressed 0x0032d934 : { *ai-startup-cdrivingcontrolhandler.o(.text._ZN22CDrivingControlHandler19handleAttackPressedEv) }
    .driving_weapon_switched 0x0032d910 : { *ai-startup-cdrivingcontrolhandler.o(.text._ZN22CDrivingControlHandler20handleWeaponSwitchedEv) }
    .handler_attack_released 0x0032d8dc : { *ai-startup-cdrivingcontrolhandler.o(.text._ZN22CDrivingControlHandler20handleAttackReleasedEv) }
    .handler_constructor 0x0032da54 : { *(.text._ZN22CDrivingControlHandlerC1EP15CControlManager .text._ZN22CDrivingControlHandlerC2EP15CControlManager) }
    .handler_init 0x0032da30 : { *(.text._ZN22CDrivingControlHandler4initEv) }
    .handler_release_keys 0x0032d8bc : { *(.text._ZN22CDrivingControlHandler19releaseKeyboardKeysEv) }
    .handler_activate 0x0032d98c : { *(.text._ZN22CDrivingControlHandler8activateEv) }
    .handler_deactivate 0x0032d9e4 : { *(.text._ZN22CDrivingControlHandler10deactivateEv) }
    .driving_handler_delete 0x0032e4b8 : { *(.text._ZN22CDrivingControlHandlerD0Ev) }
    .driving_handler_destructor 0x0032e4f0 : { *(.text._ZN22CDrivingControlHandlerD1Ev .text._ZN22CDrivingControlHandlerD2Ev) }
    .driving_handler_vtable 0x004aca78 : { *(.data.rel.ro._ZTV22CDrivingControlHandler) }
    .control_handler_delete 0x0032e468 : { *(.gnu.linkonce.t._ZN15IControlHandlerD0Ev) }
    .control_handler_destructor 0x0032e494 : { *(.gnu.linkonce.t._ZN15IControlHandlerD1Ev) }
    .control_handler_vtable 0x004aca98 : { *(.gnu.linkonce.d.rel.ro._ZTV15IControlHandler) }
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_destructor 0x002db4d4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD1Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .state_machine_singleton 0x002d44c4 : { *ai-startup-cdrivingcontrolhandler.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x0032d970 : { *ai-startup-cdrivingcontrolhandler.o(.text.__tcf_0) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .ai_startup_function_0 0x0032d8e0 : { *ai-startup-cdrivingcontrolhandler.o(.text.__tcf_4) }
    .ai_startup_function_1 0x0032e310 : { *ai-startup-cdrivingcontrolhandler.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0032e454 : { *ai-startup-cdrivingcontrolhandler.o(.text._GLOBAL__I__ZN22CDrivingControlHandlerC2EP15CControlManager) }
    .ai_startup_storage_0 0x004b9904 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9924 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9930 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9938 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9940 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9948 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9950 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9958 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9960 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9968 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9970 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9978 (NOLOAD) : { *ai-startup-cdrivingcontrolhandler.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
