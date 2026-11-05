OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-touchscreenwin32/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_i2f = 0x001c41e4;
__aeabi_fcmpge = 0x001c4364;
__aeabi_fcmple = 0x001c43ac;
__aeabi_dadd = 0x001c4394;
__aeabi_dcmplt = 0x001c4244;
__aeabi_f2iz = 0x001c44cc;
INCLUDE config/linker/TouchScreenBaseSections.ld
SECTIONS
{
    .win32_touchCancelled 0x0034d1dc : { *sdk-startup-touchscreenwin32.o(.text._ZN16TouchScreenWin3214touchCancelledEffi) }
    .win32_touchEnded 0x0034d238 : { *sdk-startup-touchscreenwin32.o(.text._ZN16TouchScreenWin3210touchEndedEffi) }
    .win32_touchMoved 0x0034d294 : { *sdk-startup-touchscreenwin32.o(.text._ZN16TouchScreenWin3210touchMovedEffi) }
    .win32_touchBegan 0x0034d2f0 : { *sdk-startup-touchscreenwin32.o(.text._ZN16TouchScreenWin3210touchBeganEffi) }
    .sdk_startup_function_0 0x0034d03c : { *sdk-startup-touchscreenwin32.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0034d0c0 : { *sdk-startup-touchscreenwin32.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0034d12c : { *sdk-startup-touchscreenwin32.o(.text._GLOBAL__I__ZN16TouchScreenWin32C2Ev) }
    .sdk_startup_storage_0 0x004bc0b0 (NOLOAD) : { *sdk-startup-touchscreenwin32.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc0d0 (NOLOAD) : { *sdk-startup-touchscreenwin32.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
