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
SECTIONS
{
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
