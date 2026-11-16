OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE config/linker/RenderFXAnimationFunctions.ld
SECTIONS
{
    .got 0x004b0048 : { *(.got.plt) *(.got) }
}
