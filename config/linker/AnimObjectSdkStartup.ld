OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-animobject/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_f2iz = 0x001c44cc;
__aeabi_i2f = 0x001c41e4;
__aeabi_fmul = 0x001c4724;
__aeabi_fadd = 0x001c4154;
__aeabi_fsub = 0x001c4328;
__aeabi_fcmple = 0x001c43ac;
__aeabi_fcmplt = 0x001c479c;
__aeabi_fcmpge = 0x001c4364;
fmodf = 0x001c3fec;
memmove = 0x001c40ac;
SECTIONS
{
    .sdk_startup_function_0 0x00349414 : { *sdk-startup-animobject.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00349644 : { *sdk-startup-animobject.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x003496b0 : { *sdk-startup-animobject.o(.text._GLOBAL__I__Z7FSelectfff) }
    .sdk_startup_storage_0 0x004bb708 (NOLOAD) : { *sdk-startup-animobject.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bb728 (NOLOAD) : { *sdk-startup-animobject.o(.bss._ZN3irr2ps5vHalfE) }
    .anim_method_0 0x00349334 : { *sdk-startup-animobject.o(.text._Z18PlayPolicy_Onetimefff) }
    .anim_method_1 0x00349338 : { *sdk-startup-animobject.o(.text._ZN10AnimObject6UnloadEv) }
    .anim_method_2 0x00349340 : { *sdk-startup-animobject.o(.text._ZN10AnimObject4LoadEv) }
    .anim_method_4 0x00349374 : { *sdk-startup-animobject.o(.text._ZN10AnimObjectC2Ev .text._ZN10AnimObjectC1Ev) }
    .anim_method_5 0x003493a0 : { *sdk-startup-animobject.o(.text._ZN10AnimObjectD1Ev .text._ZN10AnimObjectD2Ev) }
    .anim_method_6 0x003493c0 : { *sdk-startup-animobject.o(.text._ZN10AnimObject11SetPositionEfff) }
    .anim_method_7 0x003493c8 : { *sdk-startup-animobject.o(.text._ZN10AnimObject10ChangeAnimEi) }
    .anim_method_8 0x003493cc : { *sdk-startup-animobject.o(.text._ZN10AnimObject7RestartEv) }
    .anim_method_9 0x003493d8 : { *sdk-startup-animobject.o(.text._ZN10AnimObject7SetAnimEi) }
    .anim_method_10 0x00349400 : { *sdk-startup-animobject.o(.text._ZN10AnimObject7SetAnimEii) }
    .anim_method_11 0x0034950c : { *sdk-startup-animobject.o(.text._ZN10AnimObject4DrawEv) }
    .anim_method_12 0x00349638 : { *sdk-startup-animobject.o(.text._ZN10AnimObject6UpdateEi) }
    .anim_timing_1 0x00349560 : { *sdk-startup-animobject.o(.text._Z15PlayPolicy_Loopfff) }
    .anim_timing_2 0x003495b0 : { *sdk-startup-animobject.o(.text._ZN10AnimObject11UpdateFrameEv) }
    .anim_bounds 0x003494b4 : { *sdk-startup-animobject.o(.text._ZN10AnimObject22GetCurrentBoundingRectEv) }
    .anim_empty_bounds 0x00435a60 : { *sdk-startup-animobject.o(.rodata.empty_anim_bounds) }
    .anim_vtable 0x004ad2a8 : { *sdk-startup-animobject.o(.data.rel.ro._ZTV10AnimObject .gnu.linkonce.d.rel.ro._ZTV10AnimObject) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
