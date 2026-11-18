OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
SECTIONS
{
    .adpcm_state_text 0x0034f140 : { *adpcm-state.o(.text) }
}
