OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/bullet-trace-manager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
_ZdaPv = 0x001c461c;
__cxa_pure_virtual = 0;
_Znaj = 0x001c3ff8;
__aeabi_idivmod = 0x001c4934;
__aeabi_fsub = 0x001c4328;
__aeabi_fmul = 0x001c4724;
__aeabi_fadd = 0x001c4154;
__aeabi_f2d = 0x001c48f8;
sqrt = 0x001c401c;
__aeabi_d2f = 0x001c4310;
__aeabi_fdiv = 0x001c4520;
lrand48 = 0x001c4664;
__aeabi_i2f = 0x001c41e4;
__aeabi_fcmpgt = 0x001c419c;
memset = 0x001c45d4;
SECTIONS
{
    .bullet_trace_on_animate 0x002f064c : { *bullet-trace-manager.o(.text._ZN18BulletTraceManager9OnAnimateEj) }
    .bullet_trace_startup 0x002f0c6c : { *bullet-trace-manager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .bullet_trace_startup_wrapper 0x002f0cd8 : { *bullet-trace-manager.o(.text._GLOBAL__I__ZN18BulletTraceManagerC2Ev) }
    .bullet_trace_string_cleanup 0x002f0cec : { *bullet-trace-manager.o(.text.__tcf_2) }
    .bullet_trace_empty_string 0x0044d91c : { *bullet-trace-manager.o(.rodata.str1.4) }
    .bullet_trace_string 0x004b7d6c (NOLOAD) : { *bullet-trace-manager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .bullet_trace_half 0x004b7d8c (NOLOAD) : { *bullet-trace-manager.o(.bss._ZN3irr2ps5vHalfE) }
    .bullet_trace_bounds 0x002f0600 : { *bullet-trace-manager.o(.text._ZNK18BulletTraceManager14getBoundingBoxEv) }
    .bullet_trace_bounds_guard 0x004b7d98 (NOLOAD) : { *bullet-trace-manager.o(.bss._ZGVZNK18BulletTraceManager14getBoundingBoxEvE8EmptyBox) }
    .bullet_trace_bounds_storage 0x004b7d9c (NOLOAD) : { *bullet-trace-manager.o(.bss._ZZNK18BulletTraceManager14getBoundingBoxEvE8EmptyBox) }
    .bullet_trace_impacts 0x002f0354 : { *bullet-trace-manager.o(.text._ZN18BulletTraceManager10getImpactsEv) }
    .bullet_trace_register 0x002f035c : { *bullet-trace-manager.o(.text._ZN18BulletTraceManager19OnRegisterSceneNodeEv) }
    .bullet_full_d1 0x002f12d8 : { *bullet-trace-manager.o(.text._ZN18BulletTraceManagerD1Ev) }
    .bullet_full_d2 0x002f1398 : { *bullet-trace-manager.o(.text._ZN18BulletTraceManagerD2Ev) }
    .bullet_full_d0 0x002f11ec : { *bullet-trace-manager.o(.text._ZN18BulletTraceManagerD0Ev) }
    .bullet_full_d0_v12 0x002f11c4 : { *bullet-trace-manager.o(.text._ZTv0_n12_N18BulletTraceManagerD0Ev) }
    .bullet_full_d0_v24 0x002f11d8 : { *bullet-trace-manager.o(.text._ZTv0_n24_N18BulletTraceManagerD0Ev) }
    .bullet_full_d1_v12 0x002f12b0 : { *bullet-trace-manager.o(.text._ZTv0_n12_N18BulletTraceManagerD1Ev) }
    .bullet_full_d1_v24 0x002f12c4 : { *bullet-trace-manager.o(.text._ZTv0_n24_N18BulletTraceManagerD1Ev) }
    .bullet_full_vtable 0x004a9d48 : { *bullet-trace-manager.o(.data.rel.ro._ZTV18BulletTraceManager .gnu.linkonce.d.rel.ro._ZTV18BulletTraceManager) }
    .bullet_full_vtt 0x004a9e88 : { *bullet-trace-manager.o(.data.rel.ro._ZTT18BulletTraceManager .gnu.linkonce.d.rel.ro._ZTT18BulletTraceManager) }
    .bullet_full_base_scene_vtable 0x004a9ea8 : { *bullet-trace-manager.o(.data.rel.ro._ZTC18BulletTraceManager0_N3irr5scene10ISceneNodeE .gnu.linkonce.d.rel.ro._ZTC18BulletTraceManager0_N3irr5scene10ISceneNodeE) }
    .bullet_full_base_attributes_vtable 0x004a9fe8 : { *bullet-trace-manager.o(.data.rel.ro._ZTC18BulletTraceManager0_N3irr2io26IAttributeExchangingObjectE .gnu.linkonce.d.rel.ro._ZTC18BulletTraceManager0_N3irr2io26IAttributeExchangingObjectE) }
    .sdk_attribute_0 0x0021a8d4 : { *bullet-trace-manager.o(.text._ZN3irr2io26IAttributeExchangingObjectD0Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD0Ev) }
    .sdk_attribute_1 0x0021a91c : { *bullet-trace-manager.o(.text._ZN3irr2io26IAttributeExchangingObjectD1Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD1Ev) }
    .sdk_attribute_2 0x0021a958 : { *bullet-trace-manager.o(.text._ZN3irr2io26IAttributeExchangingObjectD2Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD2Ev) }
    .sdk_attribute_3 0x0021a8d4 : { *bullet-trace-manager.o(.text._ZTv0_n12_N3irr2io26IAttributeExchangingObjectD0Ev .gnu.linkonce.t._ZTv0_n12_N3irr2io26IAttributeExchangingObjectD0Ev) }
    .sdk_attribute_4 0x0021a91c : { *bullet-trace-manager.o(.text._ZTv0_n12_N3irr2io26IAttributeExchangingObjectD1Ev .gnu.linkonce.t._ZTv0_n12_N3irr2io26IAttributeExchangingObjectD1Ev) }
    .sdk_layer 0x0020f09c : { *bullet-trace-manager.o(.text._ZN3irr5video14SMaterialLayerD1Ev .gnu.linkonce.t._ZN3irr5video14SMaterialLayerD1Ev) }
    .bullet_constructor_c1 0x002f0d1c : { *bullet-trace-manager.o(.text._ZN18BulletTraceManagerC1Ev) }
    .bullet_constructor_c2 0x002f0f88 : { *bullet-trace-manager.o(.text._ZN18BulletTraceManagerC2Ev) }
    .bullet_impact_asset 0x0041bc98 : { *bullet-trace-manager.o(.rodata.bullet_impact_asset) }
    /* SDK constructor copy is not matched; this image checks game constructors. */
    .sdk_material_ctor 0x0020e7ec : { *bullet-trace-manager.o(.text._ZN3irr5video9SMaterialC1Ev .gnu.linkonce.t._ZN3irr5video9SMaterialC1Ev) }
    .bullet_play 0x002f083c : { *bullet-trace-manager.o(.text._ZN18BulletTraceManager15PlayBulletTraceERKN3irr4core8vector3dIfEES5_bS5_) }
    .bullet_render 0x002f09c4 : { *bullet-trace-manager.o(.text._ZN18BulletTraceManager6renderEPv) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.bullet_trace_string) == 32, "BulletTraceManager string extent");
ASSERT(SIZEOF(.bullet_trace_half) == 12, "BulletTraceManager half-vector extent");
ASSERT(SIZEOF(.bullet_trace_bounds_guard) == 4, "BulletTraceManager box guard extent");
ASSERT(SIZEOF(.bullet_trace_bounds_storage) == 24, "BulletTraceManager box extent");
ASSERT(SIZEOF(.bullet_trace_on_animate) == 496, "Native BulletTraceManager OnAnimate extent");
