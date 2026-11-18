SECTIONS
{
    .text 0x0039c750 : { *(.text) }
    /DISCARD/ : { *(.comment) *(.note*) *(.ARM.attributes) }
}
