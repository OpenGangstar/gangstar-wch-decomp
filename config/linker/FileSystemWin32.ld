__aeabi_ddiv = 0x001c4274;
__aeabi_fmul = 0x001c4724;
__aeabi_dmul = 0x001c4298;
__aeabi_d2iz = 0x001c4844;
__aeabi_i2d = 0x001c452c;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_ZN15FileSystemWin32C1Ev)
INCLUDE build/matches/file-system-win32/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_Znwj = 0x001c4814;
_Znaj = 0x001c3ff8;
fopen = 0x001c45bc;
fclose = 0x001c4628;
printf = 0x001c4058;
fprintf = 0x001c4388;
strcpy = 0x001c3fd4;
strlen = 0x001c48bc;
vprintf = 0x001c43c4;
__aeabi_f2d = 0x001c48f8;
__stack_chk_fail = 0x001c42e0;
sprintf = 0x001c46ac;
remove = 0x001c41d8;
ftell = 0x001c45f8;
fseek = 0x001c43f4;
fwrite = 0x001c47e4;
fread = 0x001c4598;
__cxa_pure_virtual = 0;
"_Znwj" = 0x001c4814;
memset = 0x001c45d4;
memcpy = 0x001c4190;
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
__aeabi_atexit = 0x001c494c;
SECTIONS {
    .text 0x0034df2c : {
        *file-system-win32.o(.text._ZNK15FileSystemWin3211_FileHandle7canReadEv .gnu.linkonce.t._ZNK15FileSystemWin3211_FileHandle7canReadEv)
        *file-system-win32.o(.text._ZNK15FileSystemWin3211_FileHandle8canWriteEv .gnu.linkonce.t._ZNK15FileSystemWin3211_FileHandle8canWriteEv)
        *file-system-win32.o(.text._ZNK15FileSystemWin3211getRootPathEv .gnu.linkonce.t._ZNK15FileSystemWin3211getRootPathEv)
        *file-system-win32.o(.text._ZNK15FileSystemWin3216getResourcesPathEv .gnu.linkonce.t._ZNK15FileSystemWin3216getResourcesPathEv)
        *file-system-win32.o(.text._ZNK15FileSystemWin3216getSaveFilesPathEv .gnu.linkonce.t._ZNK15FileSystemWin3216getSaveFilesPathEv)
        *file-system-win32.o(.text._ZN15FileSystemWin329closeFileERP11IFileStream .gnu.linkonce.t._ZN15FileSystemWin329closeFileERP11IFileStream)
        *file-system-win32.o(.text._ZNK15FileSystemWin3211_FileHandle4tellEv .gnu.linkonce.t._ZNK15FileSystemWin3211_FileHandle4tellEv)
        *file-system-win32.o(.text._ZN15FileSystemWin3211_FileHandle4seekEy .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandle4seekEy)
        *file-system-win32.o(.text._ZNK15FileSystemWin3211_FileHandle4sizeEv .gnu.linkonce.t._ZNK15FileSystemWin3211_FileHandle4sizeEv)
        *file-system-win32.o(.text._ZN15FileSystemWin3211_FileHandle5writeEPKhy .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandle5writeEPKhy)
        *file-system-win32.o(.text._ZN15FileSystemWin3211_FileHandle4readEPhy .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandle4readEPhy)
        *file-system-win32.o(.text._ZN15FileSystemWin3211_FileHandleC2EPKcS2_b .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandleC2EPKcS2_b .text._ZN15FileSystemWin3211_FileHandleC1EPKcS2_b .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandleC1EPKcS2_b)
        *file-system-win32.o(.text._ZN15FileSystemWin3213_createHandleEPKcS1_b .gnu.linkonce.t._ZN15FileSystemWin3213_createHandleEPKcS1_b)
        *file-system-win32.o(.text._ZN15FileSystemWin3212openSavefileEPKc .gnu.linkonce.t._ZN15FileSystemWin3212openSavefileEPKc)
        *file-system-win32.o(.text._ZN15FileSystemWin3212openResourceEPKc .gnu.linkonce.t._ZN15FileSystemWin3212openResourceEPKc)
        *file-system-win32.o(.text._ZN15FileSystemWin328openFileEPKc .gnu.linkonce.t._ZN15FileSystemWin328openFileEPKc)
        *file-system-win32.o(.text._ZN15FileSystemWin329_getPathsEv .gnu.linkonce.t._ZN15FileSystemWin329_getPathsEv)
        *file-system-win32.o(.text._ZN15FileSystemWin32D0Ev .gnu.linkonce.t._ZN15FileSystemWin32D0Ev)
        *file-system-win32.o(.text._ZN15FileSystemWin32D2Ev .gnu.linkonce.t._ZN15FileSystemWin32D2Ev .text._ZN15FileSystemWin32D1Ev .gnu.linkonce.t._ZN15FileSystemWin32D1Ev)
        *file-system-win32.o(.text._ZN15FileSystemWin32C1Ev .gnu.linkonce.t._ZN15FileSystemWin32C1Ev .text._ZN15FileSystemWin32C2Ev .gnu.linkonce.t._ZN15FileSystemWin32C2Ev)
        *file-system-win32.o(.text._ZN15FileSystemWin3211_FileHandleD0Ev .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandleD0Ev)
        *file-system-win32.o(.text._ZN15FileSystemWin3211_FileHandleD1Ev .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandleD1Ev .text._ZN15FileSystemWin3211_FileHandleD2Ev .gnu.linkonce.t._ZN15FileSystemWin3211_FileHandleD2Ev)
    }
    .vtable 0x004ad5a8 : { *file-system-win32.o(.data.rel.ro._ZTV15FileSystemWin32) }
    .handle_vtable 0x004ad5d8 : { *file-system-win32.o(.data.rel.ro._ZTVN15FileSystemWin3211_FileHandleE) }
    .write_error 0x00436128 : { *file-system-win32.o(.rodata.write_error) }
    .read_error 0x00436178 : { *file-system-win32.o(.rodata.read_error) }
    .paths 0x004361c4 : { *file-system-win32.o(.rodata.str1.4) }

    .shared0 0x0034dc6c : { *file-system-win32.o(.gnu.linkonce.t._ZN11IStreamBaseD0Ev) }
    .shared1 0x0034dc8c : { *file-system-win32.o(.gnu.linkonce.t._ZN11IStreamBaseD1Ev) }
    .shared2 0x0034de68 : { *file-system-win32.o(.gnu.linkonce.t._ZN11IFileStreamD0Ev) }
    .shared3 0x0034de94 : { *file-system-win32.o(.gnu.linkonce.t._ZN11IFileStreamD1Ev) }
    .file_vtable 0x004ad550 : { *file-system-win32.o(.data.rel.ro._ZTV11IFileStream .gnu.linkonce.d.rel.ro._ZTV11IFileStream) }
    .stream_vtable 0x004ad580 : { *file-system-win32.o(.data.rel.ro._ZTV11IStreamBase .gnu.linkonce.d.rel.ro._ZTV11IStreamBase) }
    .write_mode 0x00436084 : { *file-system-win32.o(.rodata.write_mode) }
    .read_mode 0x004014f0 : { *file-system-win32.o(.rodata.read_mode) }
    .basetext 0x0034db0c : {
        *file-system-base.o(.text._ZN14FileSystemBaseC1Ev .text._ZN14FileSystemBaseC2Ev)
        *file-system-base.o(.text._ZNK14FileSystemBase6_traceEPKc)
        *file-system-base.o(.text._ZN14FileSystemBaseD0Ev .gnu.linkonce.t._ZN14FileSystemBaseD0Ev)
        *file-system-base.o(.text._ZN14FileSystemBaseD1Ev .text._ZN14FileSystemBaseD2Ev .gnu.linkonce.t._ZN14FileSystemBaseD1Ev .gnu.linkonce.t._ZN14FileSystemBaseD2Ev)
    }
    .basevtable 0x004ad4c0 : { *file-system-base.o(.data.rel.ro) }

    .pathtext 0x002d2818 : { *path-name.o(.text._Z21ekd_makestringfile255PKcPc) }
    .debugtext 0x002d1494 : {
        *debug-log.o(.text._Z14ekd_debug_initv)
        *debug-log.o(.text._Z13ekd_debug_outPKcf)
        *debug-log.o(.text._Z13ekd_debug_outPKci)
        *debug-log.o(.text._Z13ekd_debug_outPKcPc)
        *debug-log.o(.text._Z13ekd_debug_outPKc)
        *debug-log.o(.text._Z7dbg_outPcz)
    }
    .debugrodata 0x004130ec : {
        . = 0x0; *debug-log.o(.rodata.logName)
        . = 0x10; *debug-log.o(.rodata.writeMode)
        . = 0x14; *debug-log.o(.rodata.errorInit)
        . = 0x40; *debug-log.o(.rodata.appendMode)
        . = 0x44; *debug-log.o(.rodata.errorFloat)
        . = 0x88; *debug-log.o(.rodata.errorInt)
        . = 0xcc; *debug-log.o(.rodata.errorString)
        . = 0x110; *debug-log.o(.rodata.errorText)
    }
    .debugbss 0x004b65f4 : { *debug-log.o(.bss.ekd_isHasInit) }

    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
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

INCLUDE config/linker/JNIGangstarBrowserSections.ld
ASSERT(SIZEOF(.gangstar_class)==4,"JNI Gangstar class cache extent");
ASSERT(SIZEOF(.gangstar_browser_method)==4,"JNI browser method cache extent");

ASSERT(SIZEOF(.gangstar_notify_method)==4,"JNI notify method cache extent");

ASSERT(SIZEOF(.gangstar_exit_method)==4,"JNI exit method cache extent");

ASSERT(SIZEOF(.gangstar_phone_method)==4,"JNI phone method cache extent");

ASSERT(SIZEOF(.gangstar_unlock_method)==4,"JNI unlock method cache extent");

ASSERT(SIZEOF(.gangstar_version_method)==4,"JNI version method cache extent");

ASSERT(SIZEOF(.gangstar_launch_method)==4,"JNI launch method cache extent");
