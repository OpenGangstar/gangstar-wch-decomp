__aeabi_ui2f = 0x001c4574;
__aeabi_fdiv = 0x001c4520;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/renderfx-animation/retail-symbols.ld
INCLUDE config/linker/RenderFXAnimationFunctions.ld
_ZdlPv = 0x001c42b0;
sprintf = 0x001c46ac;
SECTIONS
{
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}

INCLUDE config/linker/RenderFXUtilitySections.ld
