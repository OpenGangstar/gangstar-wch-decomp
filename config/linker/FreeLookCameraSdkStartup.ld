OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-freelookcamera/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_i2f = 0x001c41e4;
__aeabi_fdiv = 0x001c4520;
__aeabi_fmul = 0x001c4724;
__aeabi_fadd = 0x001c4154;
__aeabi_fsub = 0x001c4328;
__aeabi_fcmpge = 0x001c4364;
__aeabi_fcmple = 0x001c43ac;
acosf = 0x001c4694;
INCLUDE config/linker/CameraSections.ld
SECTIONS
{
    .free_look_init 0x00334638 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCamera4initEP11LevelObjecti) }
    .free_look_update 0x0033463c : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCamera6updateEf) }
    .free_look_debug 0x00334640 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCamera5debugEPN3irr5video12IVideoDriverE) }
    .free_look_horizontal 0x00334644 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCamera21updateHorizontalAngleEiif) }
    .free_look_vertical 0x00334694 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCamera19updateVerticalAngleEiif) }
    .free_look_destructor 0x00334710 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCameraD1Ev .text._ZN14FreeLookCameraD2Ev) }
    .free_look_constructor 0x00334730 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCameraC1Ev .text._ZN14FreeLookCameraC2Ev) }
    .free_look_vtable 0x004accd0 : { *sdk-startup-freelookcamera.o(.data.rel.ro._ZTV14FreeLookCamera) }
    .free_look_move 0x003347f8 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCamera14updatePositionEfRKN3irr4core8vector3dIfEEfRS3_S6_ff) }
    .free_look_set_position 0x00334760 : { *sdk-startup-freelookcamera.o(.text._ZN14FreeLookCamera11setPositionERKN3irr4core8vector3dIfEE) }
    .sdk_startup_function_0 0x003346e0 : { *sdk-startup-freelookcamera.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00334778 : { *sdk-startup-freelookcamera.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x003347e4 : { *sdk-startup-freelookcamera.o(.text._GLOBAL__I__ZN14FreeLookCameraC2Ev) }
    .sdk_startup_storage_0 0x004b9e38 (NOLOAD) : { *sdk-startup-freelookcamera.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9e58 (NOLOAD) : { *sdk-startup-freelookcamera.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
