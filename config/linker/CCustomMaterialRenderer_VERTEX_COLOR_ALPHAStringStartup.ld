OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-ccustommaterialrenderer_vertex_color_alpha/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .material_is_transparent 0x002d6ab8 : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.text._ZNK42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13isTransparentEv) }
    .material_vertex_attribute_mask 0x002d6abc : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.text._ZNK42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA22getVertexAttributeMaskEv) }
    .string_startup_function_0 0x002d6ac0 : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.text.__tcf_0) }
    .string_startup_function_1 0x002d6b60 : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x002d6bb8 : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.text._GLOBAL__I__ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE) }
    .string_startup_storage_0 0x004b6958 (NOLOAD) : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
