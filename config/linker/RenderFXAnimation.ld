OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/renderfx-animation/retail-symbols.ld
INCLUDE config/linker/RenderFXAnimationFunctions.ld
SECTIONS
{
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
