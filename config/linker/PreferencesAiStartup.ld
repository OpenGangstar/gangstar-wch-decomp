__aeabi_fmul = 0x001c4724;
__aeabi_f2iz = 0x001c44cc;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-preferences/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN30retail_preferences_transitions16civPassive_transE = 0x00433084;
_ZN30retail_preferences_transitions17scriptedNpc_transE = 0x004331b0;
_ZN30retail_preferences_transitions19civAggressive_transE = 0x004331e0;
_ZN30retail_preferences_transitions16gangMember_transE = 0x004332c4;
_ZN30retail_preferences_transitions9cop_transE = 0x004332d0;
_ZN30retail_preferences_transitions10swat_transE = 0x00433408;
_ZN30retail_preferences_transitions17civ_vehicle_transE = 0x00433414;
_ZN30retail_preferences_transitions17cop_vehicle_transE = 0x004334a4;
_ZN30retail_preferences_transitions11guard_transE = 0x00433558;
_ZN30retail_preferences_transitions22scripted_vehicle_transE = 0x00433600;
sprintf = 0x001c46ac;
SECTIONS
{
    .preferences_get_orientation 0x00343834 : { *ai-startup-preferences.o(.text._ZN11Preferences14GetOrientationEPKc) }
    .orientation_datastream_d1 0x002d3654 : { *ai-startup-preferences.o(.gnu.linkonce.t._ZN10DataStreamD1Ev .text._ZN10DataStreamD1Ev) }
    .orientation_blockint_d1 0x003435e8 : { *ai-startup-preferences.o(.gnu.linkonce.t._ZN11Persistence8BlockIntD1Ev .text._ZN11Persistence8BlockIntD1Ev) }

 .preferences_sample_save 0x3438e4 : { *ai-startup-preferences.o(.text._ZN11Preferences13SampleAndSaveEPKc) }
    .preferences_vtable 0x004ad128 : { *ai-startup-preferences.o(.data.rel.ro._ZTV11Preferences) }
    .preferences_dtor 0x003437f0 : { *ai-startup-preferences.o(.text._ZN11PreferencesD1Ev .text._ZN11PreferencesD2Ev) }
    .preferences_delete 0x003437c8 : { *ai-startup-preferences.o(.text._ZN11PreferencesD0Ev) }
    .preferences_filename_format 0x00419e70 : { *ai-startup-preferences.o(.rodata.preferenceFilenameFormat) }
    .preferences_filename 0x0043304c : { *ai-startup-preferences.o(.rodata.preferenceFilename) }
    .preferences_filename_storage 0x004bab68 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZZN11Preferences18GetDefaultFilenameEvE14preferenceFile) }
    .preferences_default_filename 0x00343784 : { *ai-startup-preferences.o(.text._ZN11Preferences18GetDefaultFilenameEv) }
    .preferences_ctor 0x00343810 : { *ai-startup-preferences.o(.text._ZN11PreferencesC1Ev .text._ZN11PreferencesC2Ev) }
    .preferences_exist 0x00343760 : { *ai-startup-preferences.o(.text._ZN11Preferences5ExistEPKc) }
    .ai_startup_function_0 0x00343730 : { *ai-startup-preferences.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00343c98 : { *ai-startup-preferences.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00343ddc : { *ai-startup-preferences.o(.text._GLOBAL__I__ZN11PreferencesC2Ev) }
    .ai_startup_storage_0 0x004baaec (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004bab0c (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004bab18 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004bab20 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004bab28 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004bab30 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004bab38 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004bab40 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004bab48 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004bab50 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004bab58 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004bab60 (NOLOAD) : { *ai-startup-preferences.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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

ASSERT(SIZEOF(.preferences_filename_storage) == 256, "preferences filename extent");

ASSERT(SIZEOF(.preferences_get_orientation) == 176, "native GetOrientation extent");
