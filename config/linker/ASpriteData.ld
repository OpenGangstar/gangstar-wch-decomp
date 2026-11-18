OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/asprite-data/retail-symbols.ld
SECTIONS
{
    .asprite_data_ctor 0x0034a3b4 : { *asprite-data.o(.text._ZN11ASpriteDataC1Ev .text._ZN11ASpriteDataC2Ev) }
    .asprite_data_fmodule_swap 0x0034ac38 : { *asprite-data.o(.text._ZN11ASpriteData7FModule4SwapEv) }
    .asprite_data_aframe_swap 0x0034ad9c : { *asprite-data.o(.text._ZN11ASpriteData6AFrame4SwapEv) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
