# Vertex-color material renderer

The custom renderer uses the existing SMaterial, IVideoDriver, E_VERTEX_TYPE,
and IReferenceCounted declarations. Its actual inheritance is
CCommonGLMaterialRenderer, IMaterialRenderer, then virtual IReferenceCounted.
The driver pointer is at offset 4 and the reference-counted virtual base at 8.
The custom destructor is empty and inline. Its weak complete/deleting variants
and two virtual-base adjustment thunks match retail; no custom D2 is emitted.
This preserves the original weak destructor versus strong onSetMaterial key
function relationship, rather than discarding an unexplained extra function.

The two inline base destructors are required SDK support. All ten emitted base
variants/thunks and seven complete vtable, VTT, and construction-table sections
compare byte for byte. They receive no game-code progress credit. Existing
transparency, vertex-mask, SDK startup callbacks, and GOT bytes remain exact.

onSetMaterial binds layer-zero texture, calls the driver's original basic
render-state method, and updates the texture-environment cache to GL_REPLACE
only when needed. onUnsetMaterial similarly restores GL_MODULATE. The observed
driver view preserves activeTexture at offset 432 and four 68-byte cache
entries starting at 1556. Read-only constructor analysis proves four entries:
the shadow-state constructor initializes 272 bytes with a 68-byte stride.
The driver and its constructors are not reconstructed or credited here.
The base driver interface reuses IVideoDriver and identifies the original
setBasicRenderStates virtual slot 143, without claiming a complete driver size.

The integrated verification command exited 0:

    python tools/build.py string-startup-ccustommaterialrenderer_vertex_color_alpha

Exact output, including all supporting comparisons:

```text
OK  _ZNK42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13isTransparentEv  0x002d6ab9  4 bytes
OK  _ZNK42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA22getVertexAttributeMaskEv  0x002d6abd  4 bytes
OK  __tcf_0  0x002d6ac1  48 bytes
OK  _Z41__static_initialization_and_destruction_0ii  0x002d6b61  88 bytes
OK  _GLOBAL__I__ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE  0x002d6bb9  20 bytes
OK  _ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA13onSetMaterialERKN3irr5video9SMaterialES4_bPNS1_25IMaterialRendererServicesE  0x002d6af1  112 bytes
OK  _ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHA15onUnsetMaterialEv  0x002d6bcd  68 bytes
OK  _ZN3irr5video17IMaterialRendererD2Ev  0x002b8d35  14 bytes
OK  _ZTv0_n12_N3irr5video17IMaterialRendererD1Ev  0x002b8e49  20 bytes
OK  _ZN3irr5video17IMaterialRendererD1Ev  0x002b8e5d  40 bytes
OK  _ZTv0_n12_N3irr5video17IMaterialRendererD0Ev  0x002b8e01  20 bytes
OK  _ZN3irr5video17IMaterialRendererD0Ev  0x002b8e15  52 bytes
OK  _ZN3irr5video25CCommonGLMaterialRendererD2Ev  0x002cb379  44 bytes
OK  _ZTv0_n12_N3irr5video25CCommonGLMaterialRendererD1Ev  0x002cb31d  20 bytes
OK  _ZN3irr5video25CCommonGLMaterialRendererD1Ev  0x002cb331  72 bytes
OK  _ZTv0_n12_N3irr5video25CCommonGLMaterialRendererD0Ev  0x002cb2bd  20 bytes
OK  _ZN3irr5video25CCommonGLMaterialRendererD0Ev  0x002cb2d1  76 bytes
OK  _ZTv0_n12_N42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD1Ev  0x002d6c71  20 bytes
OK  _ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD1Ev  0x002d6c85  72 bytes
OK  _ZTv0_n12_N42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD0Ev  0x002d6c11  20 bytes
OK  _ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD0Ev  0x002d6c25  76 bytes
OK SECTION .string_startup_function_0  0x002d6ac0  48 bytes
OK SECTION .string_startup_function_1  0x002d6b60  88 bytes
OK SECTION .string_startup_function_2  0x002d6bb8  20 bytes
OK SECTION .shared_startup_empty_text  0x0044d91c  4 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK SECTION .material_dtor_0  0x002d6c70  92 bytes
OK SECTION .material_dtor_1  0x002d6c10  96 bytes
OK SECTION .material_support_0  0x002b8d34  16 bytes
OK SECTION .material_support_1  0x002b8e48  60 bytes
OK SECTION .material_support_2  0x002b8e00  72 bytes
OK SECTION .material_support_3  0x002cb378  44 bytes
OK SECTION .material_support_4  0x002cb31c  92 bytes
OK SECTION .material_support_5  0x002cb2bc  96 bytes
OK SECTION .material_table_0  0x004a6478  72 bytes
OK SECTION .material_table_1  0x004a64c0  24 bytes
OK SECTION .material_table_2  0x004a64d8  72 bytes
OK SECTION .material_table_3  0x004a6520  72 bytes
OK SECTION .material_table_4  0x004a5108  72 bytes
OK SECTION .material_table_5  0x004a5150  16 bytes
OK SECTION .material_table_6  0x004a5160  72 bytes
```

The final `python tools/build.py --all` run exited 0 with 9,662 retail comparisons.
