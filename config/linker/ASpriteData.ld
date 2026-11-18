printf = 0x001c4058;
putchar = 0x001c3f98;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/asprite-data/retail-symbols.ld
_ZdlPv = 0x001c42b0;
SECTIONS
{
 .asprite_debug_literals 0x435a70 : { *asprite-data.o(.rodata.str1.4) }
 .asprite_data_debug 0x34a728 : { *asprite-data.o(.text._ZN11ASpriteData5DebugEv) }

    .asprite_data_rect_validate 0x00335cc4 : { *asprite-data.o(.gnu.linkonce.t._ZN3RctIiE9_validateEv) }
    .asprite_data_rect_delete 0x00335d54 : { *asprite-data.o(.gnu.linkonce.t._ZN3RctIiED0Ev) }
    .asprite_data_rect_destructor 0x00335d74 : { *asprite-data.o(.gnu.linkonce.t._ZN3RctIiED1Ev) }
    .asprite_data_rect_vtable 0x004ace10 : { *asprite-data.o(.gnu.linkonce.d.rel.ro._ZTV3RctIiE) }
    .asprite_data_rect_intersection 0x0034a230 : { *asprite-data.o(.text._ZN11ASpriteData6__rect14isIntersectingEii) }
    .asprite_data_swap 0x0034ae60 : { *asprite-data.o(.text._ZN11ASpriteData4SwapEv) }
    .asprite_data_frame_swap 0x0034a490 : { *asprite-data.o(.text._ZN11ASpriteData5Frame4SwapEv) }
    .asprite_data_ctor 0x0034a3b4 : { *asprite-data.o(.text._ZN11ASpriteDataC1Ev .text._ZN11ASpriteDataC2Ev) }
    .asprite_data_anim_swap 0x0034a3c8 : { *asprite-data.o(.text._ZN11ASpriteData4Anim4SwapEv) }
    .asprite_data_image_swap 0x0034acd0 : { *asprite-data.o(.text._ZN11ASpriteData5Image4SwapEv) }
    .asprite_data_module_swap 0x0034a654 : { *asprite-data.o(.text._ZN11ASpriteData6Module4SwapEv) }
    .asprite_data_fmodule_swap 0x0034ac38 : { *asprite-data.o(.text._ZN11ASpriteData7FModule4SwapEv) }
    .asprite_data_aframe_swap 0x0034ad9c : { *asprite-data.o(.text._ZN11ASpriteData6AFrame4SwapEv) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
