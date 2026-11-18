OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-ccustommaterialrenderer_vertex_color_alpha/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
glTexEnvi = 0x001c488c;
__cxa_pure_virtual = 0;
SECTIONS
{
 .material_dtor_0 0x2d6c70 : { *(.gnu.linkonce.t._ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD1Ev) }
 .material_dtor_1 0x2d6c10 : { *(.gnu.linkonce.t._ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD0Ev) }
 .material_support_0 0x2b8d34 : { *(.gnu.linkonce.t._ZN3irr5video17IMaterialRendererD2Ev) }
 .material_support_1 0x2b8e48 : { *(.gnu.linkonce.t._ZN3irr5video17IMaterialRendererD1Ev) }
 .material_support_2 0x2b8e00 : { *(.gnu.linkonce.t._ZN3irr5video17IMaterialRendererD0Ev) }
 .material_support_3 0x2cb378 : { *(.gnu.linkonce.t._ZN3irr5video25CCommonGLMaterialRendererD2Ev) }
 .material_support_4 0x2cb31c : { *(.gnu.linkonce.t._ZN3irr5video25CCommonGLMaterialRendererD1Ev) }
 .material_support_5 0x2cb2bc : { *(.gnu.linkonce.t._ZN3irr5video25CCommonGLMaterialRendererD0Ev) }
 .material_table_0 0x4a6478 : { *(.data.rel.ro._ZTV42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA .gnu.linkonce.d.rel.ro._ZTV42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA .gnu.linkonce.d._ZTV42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA .rodata._ZTV42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA) }
 .material_table_1 0x4a64c0 : { *(.data.rel.ro._ZTT42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA .gnu.linkonce.d.rel.ro._ZTT42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA .gnu.linkonce.d._ZTT42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA .rodata._ZTT42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA) }
 .material_table_2 0x4a64d8 : { *(.data.rel.ro._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video25CCommonGLMaterialRendererE .gnu.linkonce.d.rel.ro._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video25CCommonGLMaterialRendererE .gnu.linkonce.d._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video25CCommonGLMaterialRendererE .rodata._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video25CCommonGLMaterialRendererE) }
 .material_table_3 0x4a6520 : { *(.data.rel.ro._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video17IMaterialRendererE .gnu.linkonce.d.rel.ro._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video17IMaterialRendererE .gnu.linkonce.d._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video17IMaterialRendererE .rodata._ZTC42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA0_N3irr5video17IMaterialRendererE) }
 .material_table_4 0x4a5108 : { *(.data.rel.ro._ZTVN3irr5video25CCommonGLMaterialRendererE .gnu.linkonce.d.rel.ro._ZTVN3irr5video25CCommonGLMaterialRendererE .gnu.linkonce.d._ZTVN3irr5video25CCommonGLMaterialRendererE .rodata._ZTVN3irr5video25CCommonGLMaterialRendererE) }
 .material_table_5 0x4a5150 : { *(.data.rel.ro._ZTTN3irr5video25CCommonGLMaterialRendererE .gnu.linkonce.d.rel.ro._ZTTN3irr5video25CCommonGLMaterialRendererE .gnu.linkonce.d._ZTTN3irr5video25CCommonGLMaterialRendererE .rodata._ZTTN3irr5video25CCommonGLMaterialRendererE) }
 .material_table_6 0x4a5160 : { *(.data.rel.ro._ZTCN3irr5video25CCommonGLMaterialRendererE0_NS0_17IMaterialRendererE .gnu.linkonce.d.rel.ro._ZTCN3irr5video25CCommonGLMaterialRendererE0_NS0_17IMaterialRendererE .gnu.linkonce.d._ZTCN3irr5video25CCommonGLMaterialRendererE0_NS0_17IMaterialRendererE .rodata._ZTCN3irr5video25CCommonGLMaterialRendererE0_NS0_17IMaterialRendererE) }

    .material_on_set 0x002d6af0 : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.text._ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE) }
    .material_on_unset 0x002d6bcc : { *string-startup-ccustommaterialrenderer_vertex_color_alpha.o(.text._ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA15onUnsetMaterialEv) }
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
