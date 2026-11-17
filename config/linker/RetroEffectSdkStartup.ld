OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-retroeffect/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .retroeffect_constructor 0x0032aa98 : { *sdk-startup-retroeffect.o(.text._ZN11RetroEffectC1Ev .text._ZN11RetroEffectC2Ev) }
    .retro_effect_texture_name 0x00424788 : { *sdk-startup-retroeffect.o(.rodata.retroEffectTexture) }
    .sdk_material_ctor 0x0020e7ec : { *sdk-startup-retroeffect.o(.text._ZN3irr5video9SMaterialC1Ev .gnu.linkonce.t._ZN3irr5video9SMaterialC1Ev) }
    .retroeffect_destructor_complete 0x0032ab68 : { *sdk-startup-retroeffect.o(.text._ZN11RetroEffectD2Ev .text._ZN11RetroEffectD1Ev) }
    .retroeffect_destructor_deleting 0x0032a9a4 : { *sdk-startup-retroeffect.o(.text._ZN11RetroEffectD0Ev) }
    .retroeffect_destructor_complete_thunk 0x0032ab54 : { *sdk-startup-retroeffect.o(.text._ZThn4_N11RetroEffectD1Ev) }
    .retroeffect_destructor_deleting_thunk 0x0032a990 : { *sdk-startup-retroeffect.o(.text._ZThn4_N11RetroEffectD0Ev) }
    .retroeffect_vtable 0x004ac5b0 : { *sdk-startup-retroeffect.o(.data.rel.ro._ZTV11RetroEffect .gnu.linkonce.d.rel.ro._ZTV11RetroEffect) }
    .sdk_layer 0x0020f09c : { *sdk-startup-retroeffect.o(.text._ZN3irr5video14SMaterialLayerD1Ev .gnu.linkonce.t._ZN3irr5video14SMaterialLayerD1Ev) }
    .sdk_startup_function_0 0x0032a960 : { *sdk-startup-retroeffect.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0032aa18 : { *sdk-startup-retroeffect.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0032aa84 : { *sdk-startup-retroeffect.o(.text._GLOBAL__I__ZN11RetroEffectC2Ev) }
    .sdk_startup_storage_0 0x004b9638 (NOLOAD) : { *sdk-startup-retroeffect.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9658 (NOLOAD) : { *sdk-startup-retroeffect.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
