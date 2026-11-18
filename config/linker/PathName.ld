__aeabi_dmul = 0x001c4298;
__aeabi_d2iz = 0x001c4844;
__aeabi_i2d = 0x001c452c;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/path-name/retail-symbols.ld
ENTRY(_Z21ekd_makestringfile255PKcPc)
strcpy = 0x001c3fd4;
_ZN26retail_wrapper_transitions16civPassive_transE = 0x00413508;
_ZN26retail_wrapper_transitions17scriptedNpc_transE = 0x00413634;
_ZN26retail_wrapper_transitions19civAggressive_transE = 0x00413664;
_ZN26retail_wrapper_transitions16gangMember_transE = 0x00413748;
_ZN26retail_wrapper_transitions9cop_transE = 0x00413754;
_ZN26retail_wrapper_transitions10swat_transE = 0x0041388c;
_ZN26retail_wrapper_transitions17civ_vehicle_transE = 0x00413898;
_ZN26retail_wrapper_transitions17cop_vehicle_transE = 0x00413928;
_ZN26retail_wrapper_transitions11guard_transE = 0x004139dc;
_ZN26retail_wrapper_transitions22scripted_vehicle_transE = 0x00413a84;
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS {
    .text 0x002d2818 : { *path-name.o(.text._Z21ekd_makestringfile255PKcPc) }
    .module_startup_path_name_function_0 0x002d2624 : { *path-name.o(.text.__tcf_4) }
    .module_startup_path_name_function_1 0x002d2840 : { *path-name.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .module_startup_path_name_function_2 0x002d2984 : { *path-name.o(.text._GLOBAL__I_mouseLButtHeld) }
    .module_startup_path_name_storage_0 0x004b66a0 (NOLOAD) : { *path-name.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .module_startup_path_name_storage_1 0x004b66c0 (NOLOAD) : { *path-name.o(.bss._ZN3irr2ps5vHalfE) }
    .module_startup_path_name_storage_2 0x004b66cc (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .module_startup_path_name_storage_3 0x004b66d4 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .module_startup_path_name_storage_4 0x004b66dc (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .module_startup_path_name_storage_5 0x004b66e4 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .module_startup_path_name_storage_6 0x004b66ec (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai3copE) }
    .module_startup_path_name_storage_7 0x004b66f4 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai4swatE) }
    .module_startup_path_name_storage_8 0x004b66fc (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .module_startup_path_name_storage_9 0x004b6704 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .module_startup_path_name_storage_10 0x004b670c (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai5guardE) }
    .module_startup_path_name_storage_11 0x004b6714 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

.got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
}
ASSERT(SIZEOF(.module_startup_path_name_storage_0) == 32, "path-name _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_1) == 12, "path-name _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_2) == 8, "path-name _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_3) == 8, "path-name _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_4) == 8, "path-name _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_5) == 8, "path-name _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_6) == 8, "path-name _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_7) == 8, "path-name _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_8) == 8, "path-name _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_9) == 8, "path-name _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_10) == 8, "path-name _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_11) == 8, "path-name _ZN8gameloft2ai16scripted_vehicleE extent");

INCLUDE config/linker/WrapperRuntimeSections.ld

ASSERT(SIZEOF(.wrapper_application) == 4, "native wrapper app pointer extent");

ASSERT(SIZEOF(.wrapper_device) == 4, "native wrapper device pointer extent");
