/* Existing retail ARM PLT entries; only these four wrappers are rebuilt. */
memset = 0x001c45d4;
memcpy = 0x001c4190;
memcmp = 0x001c4544;
strlen = 0x001c48bc;

SECTIONS
{
    .text 0x003935bc : { *(.text) }
    /DISCARD/ : { *(.comment) *(.note*) *(.ARM.attributes) }
}
