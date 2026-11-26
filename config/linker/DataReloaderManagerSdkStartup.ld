OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-datareloadermanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .reloader_reloaded_message 0x00435fd4 : { *sdk-startup-datareloadermanager.o(.rodata.reloaderReloadedMessage) }
    .reloader_open_error 0x00435fe4 : { *sdk-startup-datareloadermanager.o(.rodata.reloaderOpenError) }
    .reloader_check_files 0x0034c118 : { *sdk-startup-datareloadermanager.o(.text._ZNK19DataReloaderManager10checkFilesEv) }
    .datareloader_nested_destructor 0x0034c0a0 : { *sdk-startup-datareloadermanager.o(.gnu.linkonce.t._ZN19DataReloaderManager15_MonitoredFilesD1Ev .gnu.linkonce.t._ZN19DataReloaderManager15_MonitoredFilesD2Ev) }
    .datareloader_vtable 0x004ad2d8 : { *sdk-startup-datareloadermanager.o(.data.rel.ro._ZTV19DataReloaderManager) }
    .reloader_dtor 0x0034c0c4 : { *sdk-startup-datareloadermanager.o(.text._ZN19DataReloaderManagerD1Ev .text._ZN19DataReloaderManagerD2Ev) }
    .reloader_delete 0x0034c2e0 : { *sdk-startup-datareloadermanager.o(.text._ZN19DataReloaderManagerD0Ev) }
    .reloader_trace 0x0034c084 : { *sdk-startup-datareloadermanager.o(.text._ZNK19DataReloaderManager6_traceEPKc) }
    .reloader_monitor 0x0034c088 : { *sdk-startup-datareloadermanager.o(.text._ZN19DataReloaderManager12monitorFilesEPKcS1_P13IDataReloader) }
    .reloader_ctor 0x0034c210 : { *sdk-startup-datareloadermanager.o(.text._ZN19DataReloaderManagerC1Ev .text._ZN19DataReloaderManagerC2Ev) }
    .sdk_startup_function_0 0x0034c2b0 : { *sdk-startup-datareloadermanager.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0034c230 : { *sdk-startup-datareloadermanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0034c29c : { *sdk-startup-datareloadermanager.o(.text._GLOBAL__I__ZN19DataReloaderManagerC2Ev) }
    .sdk_startup_storage_0 0x004bc034 (NOLOAD) : { *sdk-startup-datareloadermanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc054 (NOLOAD) : { *sdk-startup-datareloadermanager.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
