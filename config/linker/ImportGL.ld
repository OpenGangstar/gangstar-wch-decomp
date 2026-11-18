OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
SECTIONS
{
    .importgl_text 0x002d16ec : { *importgl.o(.text) }
}
