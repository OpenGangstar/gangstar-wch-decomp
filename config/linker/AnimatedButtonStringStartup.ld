OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-animatedbutton/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .string_startup_function_0 0x00326e5c : { *string-startup-animatedbutton.o(.text.__tcf_0) }
    .string_startup_function_1 0x003271c4 : { *string-startup-animatedbutton.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0032721c : { *string-startup-animatedbutton.o(.text._GLOBAL__I__ZN14AnimatedButtonC2EP7ASpriteiN9EvVButton10ButtonType4TypeE) }
    .string_startup_storage_0 0x004b9284 (NOLOAD) : { *string-startup-animatedbutton.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .button_gray 0x00326e40 : { *string-startup-animatedbutton.o(.text._ZN14AnimatedButton7grayOutEb) }
    .button_set_anim 0x00327024 : { *string-startup-animatedbutton.o(.text._ZN14AnimatedButton7setAnimEi) }
    .button_update 0x00327034 : { *string-startup-animatedbutton.o(.text._ZN14AnimatedButton6updateEd) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
