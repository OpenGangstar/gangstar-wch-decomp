OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-gauge/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_i2f = 0x001c41e4;
__aeabi_fmul = 0x001c4724;
__aeabi_fsub = 0x001c4328;
__aeabi_f2iz = 0x001c44cc;
__cxa_pure_virtual = 0;
INCLUDE config/linker/HudElement-sections.ld
SECTIONS
{
    .sdk_startup_function_0 0x00327fb4 : { *sdk-startup-gauge.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00328148 : { *sdk-startup-gauge.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x003281b4 : { *sdk-startup-gauge.o(.text._GLOBAL__I__ZN5GaugeC2EP7ASpriteiii) }
    .sdk_startup_storage_0 0x004b9444 (NOLOAD) : { *sdk-startup-gauge.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9464 (NOLOAD) : { *sdk-startup-gauge.o(.bss._ZN3irr2ps5vHalfE) }
    .gauge_update 0x00327f8c : { *sdk-startup-gauge.o(.text._ZN5Gauge6updateEd) }
    .gauge_percentage 0x00327f90 : { *sdk-startup-gauge.o(.text._ZN5Gauge13setPercentageEf) }
    .gauge_draw_thunk 0x00327fe4 : { *sdk-startup-gauge.o(.text._ZThn4_NK5Gauge6draw2dEv) }
    .gauge_draw 0x00327ff8 : { *sdk-startup-gauge.o(.text._ZNK5Gauge6draw2dEv) }
    .gauge_delete_thunk 0x00328048 : { *sdk-startup-gauge.o(.text._ZThn4_N5GaugeD0Ev) }
    .gauge_delete 0x0032805c : { *sdk-startup-gauge.o(.text._ZN5GaugeD0Ev) }
    .gauge_destructor_thunk 0x0032808c : { *sdk-startup-gauge.o(.text._ZThn4_N5GaugeD1Ev) }
    .gauge_destructor 0x003280a0 : { *sdk-startup-gauge.o(.text._ZN5GaugeD1Ev) }
    .gauge_constructor 0x003280d0 : { *sdk-startup-gauge.o(.text._ZN5GaugeC1EP7ASpriteiii) }
    .gauge_vtable 0x004ac218 : { *sdk-startup-gauge.o(.data.rel.ro._ZTV5Gauge) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
