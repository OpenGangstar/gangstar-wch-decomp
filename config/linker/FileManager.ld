__aeabi_fmul = 0x001c4724;
__aeabi_dmul = 0x001c4298;
__aeabi_d2iz = 0x001c4844;
__aeabi_i2d = 0x001c452c;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_ZN11FileManagerC1Eb)
INCLUDE build/matches/file-manager/retail-symbols.ld
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
_ZdaPv = 0x001c461c;
memcpy = 0x001c4190;
strcmp = 0x001c4658;
strcasecmp = 0x001c44e4;
strncmp = 0x001c44b4;
strncasecmp = 0x001c42c8;
strchr = 0x001c48e0;
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
    .fronttext 0x002d3500 : {
        *file-manager.o(.text._ZN11FileManager15_GetNumMappingsEv .gnu.linkonce.t._ZN11FileManager15_GetNumMappingsEv)
        *file-manager.o(.text._ZN11FileManager11_GetMappingEi .gnu.linkonce.t._ZN11FileManager11_GetMappingEi)
        *file-manager.o(.text._ZN11FileManager12_GetFileSizeEi .gnu.linkonce.t._ZN11FileManager12_GetFileSizeEi)
        *file-manager.o(.text._ZN11FileManager11_GetDvdNameEi .gnu.linkonce.t._ZN11FileManager11_GetDvdNameEi)
        *file-manager.o(.text._ZN11FileManager8_GetNameEi .gnu.linkonce.t._ZN11FileManager8_GetNameEi)
        *file-manager.o(.text._ZN11FileManager17StringToShortNameEPci .gnu.linkonce.t._ZN11FileManager17StringToShortNameEPci)
        *file-manager.o(.text._ZN11FileManager16StringToBaseNameEPci .gnu.linkonce.t._ZN11FileManager16StringToBaseNameEPci)
        *file-manager.o(.text._ZN11FileManager28_Debug_ClearLoadedRessourcesEv .gnu.linkonce.t._ZN11FileManager28_Debug_ClearLoadedRessourcesEv)
        *file-manager.o(.text._ZN11FileManager31_Debug_GetLoadedRessourcesCountEv .gnu.linkonce.t._ZN11FileManager31_Debug_GetLoadedRessourcesCountEv)
        *file-manager.o(.text._ZN11FileManager26_Debug_GetLoadedRessourcesEPi .gnu.linkonce.t._ZN11FileManager26_Debug_GetLoadedRessourcesEPi)
        *file-manager.o(.text._ZN11FileManager22_Debug_GetMaxFileCountEv .gnu.linkonce.t._ZN11FileManager22_Debug_GetMaxFileCountEv)
    }
    .text 0x002d3678 : {
        *file-manager.o(.text._ZN11FileManager16StringToBaseNameEPc .gnu.linkonce.t._ZN11FileManager16StringToBaseNameEPc)
        *file-manager.o(.text._ZN11FileManager17StringToShortNameEPc .gnu.linkonce.t._ZN11FileManager17StringToShortNameEPc)
        *file-manager.o(.text._ZN11FileManager17_GetIdFromDvdNameEPKc .gnu.linkonce.t._ZN11FileManager17_GetIdFromDvdNameEPKc)
        *file-manager.o(.text._ZN11FileManager23_GetResIdsFromDvdFolderEPKcPii .gnu.linkonce.t._ZN11FileManager23_GetResIdsFromDvdFolderEPKcPii)
        *file-manager.o(.text._ZN11FileManager19_GetNamesFromPrefixEPKcPA256_c .gnu.linkonce.t._ZN11FileManager19_GetNamesFromPrefixEPKcPA256_c)
        *file-manager.o(.text._ZN11FileManager5_LoadEiPi .gnu.linkonce.t._ZN11FileManager5_LoadEiPi)
        *file-manager.o(.text._ZN11FileManager7_UnloadEPv .gnu.linkonce.t._ZN11FileManager7_UnloadEPv)
        *file-manager.o(.text._ZN11FileManager7_UnloadEi .gnu.linkonce.t._ZN11FileManager7_UnloadEi)
        *file-manager.o(.text._ZN11FileManager21_GetFirstIdFromPrefixEPKc .gnu.linkonce.t._ZN11FileManager21_GetFirstIdFromPrefixEPKc)
        *file-manager.o(.text._ZN11FileManager6_GetIdEPKc .gnu.linkonce.t._ZN11FileManager6_GetIdEPKc)
        *file-manager.o(.text._ZN11FileManagerD1Ev .gnu.linkonce.t._ZN11FileManagerD1Ev .text._ZN11FileManagerD2Ev .gnu.linkonce.t._ZN11FileManagerD2Ev)
        *file-manager.o(.text._ZN11FileManager7DestroyEv .gnu.linkonce.t._ZN11FileManager7DestroyEv)
        *file-manager.o(.text._ZN7Structs9FileEntry4ReadER10DataStream .gnu.linkonce.t._ZN7Structs9FileEntry4ReadER10DataStream)
        *file-manager.o(.text._ZN11FileManagerC1Eb .gnu.linkonce.t._ZN11FileManagerC1Eb .text._ZN11FileManagerC2Eb .gnu.linkonce.t._ZN11FileManagerC2Eb)
        *file-manager.o(.text._ZN11FileManager14InitArgMappingEv .gnu.linkonce.t._ZN11FileManager14InitArgMappingEv)
        *file-manager.o(.text._ZN11FileManager4InitEv .gnu.linkonce.t._ZN11FileManager4InitEv)
    }
    .dvdtext 0x00353f78 : {
        *file-manager.o(.text._ZN11FileManager10GetDvdNameEPKc .gnu.linkonce.t._ZN11FileManager10GetDvdNameEPKc)
    }
    .names 0x00413aec : { *file-manager.o(.rodata.str1.4) }
    .mgr 0x004b677c : { *file-manager.o(.bss._ZN11FileManager5s_mgrE) }
    .filestream_text 0x0034eb7c : {
        *file-stream.o(.text._ZNK10FileStream7IsValidEv .gnu.linkonce.t._ZNK10FileStream7IsValidEv)
        *file-stream.o(.text._ZN10FileStream4SizeEv)
        *file-stream.o(.text._ZN10FileStream6UnloadEPv)
        *file-stream.o(.text._ZN10FileStream6DeleteEPKc)
        *file-stream.o(.text._ZNK10FileStream4TellEv)
        *file-stream.o(.text._ZN10FileStream4SeekEii)
        *file-stream.o(.text._ZN10FileStream5WriteEPKvi)
        *file-stream.o(.text._ZN10FileStream4ReadEPvi)
        *file-stream.o(.text._ZN10FileStream5CloseEv)
        *file-stream.o(.text._ZN10FileStreamD1Ev .text._ZN10FileStreamD2Ev)
        *file-stream.o(.text._ZN10FileStream4OpenEPKci)
        *file-stream.o(.text._ZN10FileStream6CreateEPKc)
        *file-stream.o(.text._ZN10FileStreamC2Ev .text._ZN10FileStreamC1Ev)
        *file-stream.o(.text._ZN10FileStream5ExistEPKc)
        *file-stream.o(.text._ZN10FileStreamC2EPKci .text._ZN10FileStreamC1EPKci)
        *file-stream.o(.text._ZN10FileStream4LoadEPKcPi)
        *file-stream.o(.text._ZN10FileStreamD0Ev)
    }
    .modes 0x004014f0 : { *file-stream.o(.rodata.readMode .rodata.appendMode) }
    .filestream_rodata 0x004361d4 : {
        *file-stream.o(.rodata.deleteFormat .rodata.updateMode .rodata.createMode .rodata.errorOpen)
    }
    .filestream_vtable 0x004ad668 : { *file-stream.o(.data.rel.ro._ZTV10FileStream) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .streamtext 0x0034efe4 : {
        *stream.o(.text._ZN6StreamC1Ev .text._ZN6StreamC2Ev)
        *stream.o(.text._ZN6Stream5CloseEv)
        *stream.o(.text._ZN6Stream4ReadEv)
        *stream.o(.text._ZN6Stream5WriteEc)
        *stream.o(.text._ZN6Stream5WriteERS_i)
        *stream.o(.text._ZN6Stream4PeekEPvi)
        *stream.o(.text._ZN6StreamD0Ev .gnu.linkonce.t._ZN6StreamD0Ev)
        *stream.o(.text._ZN6StreamD1Ev .text._ZN6StreamD2Ev .gnu.linkonce.t._ZN6StreamD1Ev .gnu.linkonce.t._ZN6StreamD2Ev)
    }
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
    .verification 0x00600000 : { *retail-got.o(.text) }
    .bufferstream_text 0x0034e2dc : {
        *buffer-stream.o(.text._ZNK12BufferStream4TellEv)
        *buffer-stream.o(.text._ZNK12BufferStream6GetPtrEv)
        *buffer-stream.o(.text._ZN12BufferStream8GetBytesEi)
        *buffer-stream.o(.text._ZN12BufferStream4ReadEPvi)
        *buffer-stream.o(.text._ZN12BufferStream10ReadStringEPPc)
        *buffer-stream.o(.text._ZN12BufferStream5CloseEv)
        *buffer-stream.o(.text._ZN12BufferStream13ReserveBufferEi)
        *buffer-stream.o(.text._ZN12BufferStream5WriteER6Streami)
        *buffer-stream.o(.text._ZN12BufferStream4SeekEii)
        *buffer-stream.o(.text._ZN12BufferStream5WriteEPKvi)
        *buffer-stream.o(.text._ZN12BufferStream4OpenEiiPv)
        *buffer-stream.o(.text._ZN12BufferStream4OpenEiiPvb)
        *buffer-stream.o(.text._ZN12BufferStreamD1Ev .text._ZN12BufferStreamD2Ev)
        *buffer-stream.o(.text._ZN12BufferStreamC1EiiPv .text._ZN12BufferStreamC2EiiPv)
        *buffer-stream.o(.text._ZN12BufferStreamC1EiiPvb .text._ZN12BufferStreamC2EiiPvb)
        *buffer-stream.o(.text._ZN12BufferStreamC2Ev .text._ZN12BufferStreamC1Ev)
        *buffer-stream.o(.text._ZN12BufferStreamD0Ev)
    }
    .bufferstream_vtable 0x004ad608 : { *buffer-stream.o(.data.rel.ro) }
    .destructor 0x002d3654 : { *data-stream.o(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .datastream_text 0x0034e7b0 : {
        *data-stream.o(.text._Z11IsBigEndianv)
        *data-stream.o(.text._ZN10DataStream4ReadEPvi)
        *data-stream.o(.text._ZN10DataStream5WriteEPKvi)
        *data-stream.o(.text._ZN10DataStream4SeekEii)
        *data-stream.o(.text._ZNK10DataStream4TellEv)
        *data-stream.o(.text._ZN10DataStream4SkipEi)
        *data-stream.o(.text._ZN10DataStream17ReadUnsignedShortEv)
        *data-stream.o(.text._ZN10DataStream9ReadShortEv)
        *data-stream.o(.text._ZN10DataStream9ReadFloatEv)
        *data-stream.o(.text._ZN10DataStream7ReadUTFEPci)
        *data-stream.o(.text._ZN10DataStream5Peek1Ev)
        *data-stream.o(.text._ZN10DataStreamD0Ev .gnu.linkonce.t._ZN10DataStreamD0Ev)
        *data-stream.o(.text._ZN10DataStream9WriteByteEi)
        *data-stream.o(.text._ZN10DataStream12WriteBooleanEb)
        *data-stream.o(.text._ZN10DataStream16ReadUnsignedByteEv)
        *data-stream.o(.text._ZN10DataStream8ReadByteEv)
        *data-stream.o(.text._ZN10DataStream11ReadBooleanEv)
        *data-stream.o(.text._ZN10DataStream7ReadIntEv)
        *data-stream.o(.text._ZN10DataStream21ReadAndAllocateStringEv)
        *data-stream.o(.text._ZN10DataStream10ReadStringEPci)
        *data-stream.o(.text._ZN10DataStream5Peek4Ev)
        *data-stream.o(.text._ZN10DataStream10WriteFloatEf)
        *data-stream.o(.text._ZN10DataStream8WriteIntEi)
        *data-stream.o(.text._ZN10DataStream5Peek2Ev)
        *data-stream.o(.text._ZN10DataStream10WriteShortEi)
        *data-stream.o(.text._ZN10DataStream8WriteUTFEPKc)
        *data-stream.o(.text._ZN10DataStreamC1ER6StreamNS_6endianE .text._ZN10DataStreamC2ER6StreamNS_6endianE)
    }
    .datastream_vtable 0x004ad638 : { *data-stream.o(.data.rel.ro) }
    .streamvtable 0x004ad6c8 : { *stream.o(.data.rel.ro) }
    .module_startup_file_manager_function_0 0x002d3624 : { *file-manager.o(.text.__tcf_2) }
    .module_startup_file_manager_function_1 0x002d3b60 : { *file-manager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .module_startup_file_manager_function_2 0x002d3bcc : { *file-manager.o(.text._GLOBAL__I__ZN11FileManager5s_mgrE) }
    .module_startup_file_manager_storage_0 0x004b6780 (NOLOAD) : { *file-manager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .module_startup_file_manager_storage_1 0x004b67a0 (NOLOAD) : { *file-manager.o(.bss._ZN3irr2ps5vHalfE) }

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
ASSERT(SIZEOF(.module_startup_file_manager_storage_0) == 32, "file-manager _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.module_startup_file_manager_storage_1) == 12, "file-manager _ZN3irr2ps5vHalfE extent");
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
