OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/asprite-startup/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
memset = 0x001c45d4;
_ZdaPv = 0x001c461c;
SECTIONS
{
    .asprite_function_0 0x00349848 : { *asprite-startup.o(.text.__tcf_2) }
    .asprite_function_1 0x0034a184 : { *asprite-startup.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .asprite_function_2 0x0034a21c : { *asprite-startup.o(.text._GLOBAL__I__ZN7ASprite18s_global_transformE) }
    .asprite_storage_0 0x004bb77c (NOLOAD) : { *asprite-startup.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .asprite_storage_1 0x004bb79c (NOLOAD) : { *asprite-startup.o(.bss._ZN3irr2ps5vHalfE) }
    .asprite_lookup_1 0x00349804 : { *asprite-startup.o(.text._ZNK7ASprite20GetFrameBoundingRectEi) }
    .asprite_lookup_3 0x00349a48 : { *asprite-startup.o(.text._ZNK7ASprite18GetFrameFromAFrameEii) }
    .asprite_lookup_4 0x00349a6c : { *asprite-startup.o(.text._ZNK7ASprite24GetAnimFrameBoundingRectEii) }
    .asprite_animation_0 0x002d4534 : { *asprite-startup.o(.text._ZN7ASprite14GetFrameHeightEi) }
    .asprite_animation_1 0x002d4550 : { *asprite-startup.o(.text._ZN7ASprite13GetFrameWidthEi) }
    .asprite_animation_2 0x0034979c : { *asprite-startup.o(.text._ZNK7ASprite9GetAFrameEi) }
    .asprite_animation_5 0x00349d60 : { *asprite-startup.o(.text._ZNK7ASprite19GetModuleFromAFrameEii) }
    .asprite_paint_frame 0x0034a0f0 : { *asprite-startup.o(.text._ZNK7ASprite10PaintFrameEiiii) }
    .asprite_paint_animation 0x0034a144 : { *asprite-startup.o(.text._ZNK7ASprite11PaintAFrameEiiiii) }
    .asprite_storage_method_0 0x003496e4 : { *asprite-startup.o(.text._ZN7ASpriteC1Ev .text._ZN7ASpriteC2Ev) }
    .asprite_storage_method_1 0x00349718 : { *asprite-startup.o(.text._ZN7ASpriteC1ERKS_ .text._ZN7ASpriteC2ERKS_) }
    .asprite_storage_method_2 0x00349754 : { *asprite-startup.o(.text._ZNK7ASprite6_traceEPKc) }
    .asprite_storage_method_3 0x00349758 : { *asprite-startup.o(.text._ZN7ASprite7_setPtrEPh) }
    .asprite_storage_method_4 0x0034975c : { *asprite-startup.o(.text._ZN7ASpriteC2EPh .text._ZN7ASpriteC1EPh) }
    .asprite_storage_method_5 0x003497ac : { *asprite-startup.o(.text._ZN7ASprite12GetModuleIdxEPKc) }
    .asprite_storage_method_6 0x003497b4 : { *asprite-startup.o(.text._ZN7ASprite9MakeImageEij) }
    .asprite_storage_method_7 0x00349878 : { *asprite-startup.o(.text._ZN7ASprite9_erasePtrEv) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.asprite_storage_0) == 32, "local string extent");
ASSERT(SIZEOF(.asprite_storage_1) == 12, "half-vector extent");
