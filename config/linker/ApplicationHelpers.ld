__stack_chk_fail = 0x001c42e0;
sprintf = 0x001c46ac;
__aeabi_fdiv = 0x001c4520;
__aeabi_fcmpge = 0x001c4364;
__aeabi_fadd = 0x001c4154;
__aeabi_ui2f = 0x001c4574;
__android_log_print = 0x001c4238;
__aeabi_idiv = 0x001c43dc;
_Znwj = 0x001c4814;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/application-helpers/retail-symbols.ld
_ZN30retail_application_transitions16civPassive_transE = 0x00413df8;
_ZN30retail_application_transitions17scriptedNpc_transE = 0x00413f24;
_ZN30retail_application_transitions19civAggressive_transE = 0x00413f54;
_ZN30retail_application_transitions16gangMember_transE = 0x00414038;
_ZN30retail_application_transitions9cop_transE = 0x00414044;
_ZN30retail_application_transitions10swat_transE = 0x0041417c;
_ZN30retail_application_transitions17civ_vehicle_transE = 0x00414188;
_ZN30retail_application_transitions17cop_vehicle_transE = 0x00414218;
_ZN30retail_application_transitions11guard_transE = 0x004142cc;
_ZN30retail_application_transitions22scripted_vehicle_transE = 0x00414374;
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
INCLUDE config/linker/ApplicationEventSections.ld
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
INCLUDE config/linker/ApplicationRuntimeSections.ld
SECTIONS
{
    .application_key_pressed 0x002d4708 : { *(.text._ZN11Application13appKeyPressedEi) }
    .application_key_released 0x002d45ac : { *(.text._ZN11Application14appKeyReleasedEi) }
    .application_process_key 0x002d40fc : { *(.text._ZN11Application15ProcessKeyEventEbi) }
    .application_key_tag 0x00413b3c : { *(.rodata.application_key_tag) }
    .application_key_back 0x00413b44 : { *(.rodata.application_key_back) }
    .application_key_igm 0x00413b80 : { *(.rodata.application_key_igm) }
    .application_key_mm 0x00413bbc : { *(.rodata.application_key_mm) }
    .application_key_device 0x00413bf4 : { *(.rodata.application_key_device) }
    .application_key_post 0x00413c30 : { *(.rodata.application_key_post) }
    .application_key_main 0x00413c7c : { *(.rodata.application_key_main) }


    .application_delete_control 0x002d458c : { *(.gnu.linkonce.t._Z10SafeDeleteI15CControlManagerEvRPT_) }
    .application_logo_sprite 0x00413d30 : { *(.rodata.application_logo_sprite) }
    .application_resume_sprite 0x00413c88 : { *(.rodata.application_resume_sprite) }
    .application_stop_sound 0x002d4440 : { *(.text._ZN11Application15stopSoundThreadEv) }
    .application_material_renderer 0x002d3c48 : { *(.text._ZN11Application19GetMaterialRendererEv) }
    .application_default_language 0x002d3c5c : { *(.text._ZN11Application18SetDefaultLanguageEi) }
    .application_reinit_win32 0x002d3c6c : { *(.text._ZN11Application11ReInitWin32EPN3irr14IrrlichtDeviceE) }
    .application_helper_0 0x002d3c38 : { *(.text._ZN11Application16SetIsDemoVersionEb) }
    .application_helper_1 0x002d3c40 : { *(.text._ZN11Application16GetIsDemoVersionEv) }
    .application_helper_2 0x002d3c68 : { *(.text._ZN11Application6ReInitEPN3irr14IrrlichtDeviceE) }
    .application_helper_3 0x002d3c78 : { *(.text._ZN11Application20InitIPhoneFileSystemEv) }
    .application_helper_4 0x002d3c90 : { *(.text._ZN11Application21dumpMonitoredPointersEv) }
    .application_helper_5 0x002d3c94 : { *(.text._ZN11Application10SetDrawAllEb) }
    .state_machine_singleton 0x002d44c4 : { *application-helpers.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x002d4518 : { *application-helpers.o(.text.__tcf_0) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *application-helpers.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *application-helpers.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .screen_dimensions 0x002d483c : { *application-helpers.o(.text._ZNK11Application19GetScreenDimensionsERiS0_) }
    .module_startup_application_helpers_function_0 0x002d4044 : { *application-helpers.o(.text.__tcf_5) }
    .module_startup_application_helpers_function_1 0x002d5400 : { *application-helpers.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .module_startup_application_helpers_function_2 0x002d5544 : { *application-helpers.o(.text._GLOBAL__I_iAdditionMenuDepth) }
    .module_startup_application_helpers_storage_0 0x004b67c0 (NOLOAD) : { *application-helpers.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .module_startup_application_helpers_storage_1 0x004b67e0 (NOLOAD) : { *application-helpers.o(.bss._ZN3irr2ps5vHalfE) }
    .module_startup_application_helpers_storage_2 0x004b67ec (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .module_startup_application_helpers_storage_3 0x004b67f4 (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .module_startup_application_helpers_storage_4 0x004b67fc (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .module_startup_application_helpers_storage_5 0x004b6804 (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .module_startup_application_helpers_storage_6 0x004b680c (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai3copE) }
    .module_startup_application_helpers_storage_7 0x004b6814 (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai4swatE) }
    .module_startup_application_helpers_storage_8 0x004b681c (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .module_startup_application_helpers_storage_9 0x004b6824 (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .module_startup_application_helpers_storage_10 0x004b682c (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai5guardE) }
    .module_startup_application_helpers_storage_11 0x004b6834 (NOLOAD) : { *application-helpers.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

.got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
}
ASSERT(SIZEOF(.module_startup_application_helpers_storage_0) == 32, "application-helpers _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_1) == 12, "application-helpers _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_2) == 8, "application-helpers _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_3) == 8, "application-helpers _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_4) == 8, "application-helpers _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_5) == 8, "application-helpers _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_6) == 8, "application-helpers _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_7) == 8, "application-helpers _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_8) == 8, "application-helpers _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_9) == 8, "application-helpers _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_10) == 8, "application-helpers _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.module_startup_application_helpers_storage_11) == 8, "application-helpers _ZN8gameloft2ai16scripted_vehicleE extent");

INCLUDE config/linker/ApplicationFrameSections.ld

ASSERT(SIZEOF(.app_s_frameUpdateStart) == 4, "s_frameUpdateStart extent");
ASSERT(SIZEOF(.app_s_frameTotalUpdateTime) == 4, "s_frameTotalUpdateTime extent");
ASSERT(SIZEOF(.app_s_frameUpdateCount) == 4, "s_frameUpdateCount extent");
ASSERT(SIZEOF(.app_s_frameUpdateTime) == 4, "s_frameUpdateTime extent");

INCLUDE config/linker/ApplicationNumberSections.ld

INCLUDE config/linker/ApplicationResumeSections.ld

INCLUDE config/linker/ApplicationSingletonSections.ld
ASSERT(SIZEOF(.application_singleton_guard)==4,"Application singleton guard extent");
ASSERT(SIZEOF(.application_singleton_storage)==180,"Application singleton native extent");

INCLUDE config/linker/JNIGangstarBrowserSections.ld
ASSERT(SIZEOF(.gangstar_class)==4,"JNI Gangstar class cache extent");
ASSERT(SIZEOF(.gangstar_browser_method)==4,"JNI browser method cache extent");

ASSERT(SIZEOF(.gangstar_notify_method)==4,"JNI notify method cache extent");

ASSERT(SIZEOF(.gangstar_exit_method)==4,"JNI exit method cache extent");

ASSERT(SIZEOF(.gangstar_phone_method)==4,"JNI phone method cache extent");

ASSERT(SIZEOF(.gangstar_unlock_method)==4,"JNI unlock method cache extent");

ASSERT(SIZEOF(.gangstar_version_method)==4,"JNI version method cache extent");

ASSERT(SIZEOF(.gangstar_launch_method)==4,"JNI launch method cache extent");

INCLUDE config/linker/ApplicationDestructorSections.ld

INCLUDE config/linker/ApplicationInitWin32Sections.ld
