PROVIDE(__aeabi_f2iz = 0x001c44cc);
PROVIDE(__aeabi_fadd = 0x001c4154);
PROVIDE(__aeabi_fcmpgt = 0x001c419c);
PROVIDE(__aeabi_fcmplt = 0x001c479c);
PROVIDE(__aeabi_fmul = 0x001c4724);
PROVIDE(__aeabi_fsub = 0x001c4328);
PROVIDE(__aeabi_i2f = 0x001c41e4);
PROVIDE(__stack_chk_fail = 0x001c42e0);
PROVIDE(strcat = 0x001c43a0);
strlen = 0x001c48bc;
strrchr = 0x001c4340;
strstr = 0x001c446c;
strchr = 0x001c48e0;
__aeabi_ui2f = 0x001c4574;
__aeabi_fdiv = 0x001c4520;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/renderfx-animation/retail-symbols.ld
INCLUDE config/linker/RenderFXAnimationFunctions.ld
_ZdlPv = 0x001c42b0;
sprintf = 0x001c46ac;
SECTIONS
{
    .renderfx_invoke_as_callback 0x003eefac : { *renderfx-animation.o(.text._ZN8RenderFX16InvokeASCallbackEPN7gameswf9characterEPKc) }
    .renderfx_update_input 0x003efcec : { *renderfx-animation.o(.text._ZN8RenderFX11UpdateInputEii) }
    .renderfx_input_clicked 0x0044de94 : { *renderfx-animation.o(.rodata.inputClickedAnimation) }
    .renderfx_search_index_init 0x003f02c4 : { *renderfx-animation.o(.text._ZN8RenderFX11SearchIndex4InitERS_) }
    .renderfx_search_index_clear 0x003ee720 : { *renderfx-animation.o(.text._ZN8RenderFX11SearchIndex5ClearEv) }
    .renderfx_trace_context 0x003ed2f4 : { *renderfx-animation.o(.text._ZN8RenderFX27DBG_TraceContextInformationEPN7gameswf9characterE) }
    .renderfx_found_child 0x0044ddf8 : { *renderfx-animation.o(.rodata.renderfx_found_child) }
    .renderfx_child_sprite 0x0044de10 : { *renderfx-animation.o(.rodata.renderfx_child_sprite) }

    .renderfx_collect_characters 0x003ed1bc : { *renderfx-animation.o(.text._ZN8RenderFX17CollectCharactersEPN7gameswf9characterEPKci) }
    .renderfx_update 0x003f0040 : { *renderfx-animation.o(.text._ZN8RenderFX6UpdateEib) }
    .renderfx_find 0x003ed6e4 : { *renderfx-animation.o(.text._ZN8RenderFX4FindEPKcPN7gameswf9characterE) }
    .renderfx_load 0x003edde4 : { *renderfx-animation.o(.text._ZN8RenderFX4LoadEPKcPN7gameswf14player_contextE) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}

INCLUDE config/linker/RenderFXUtilitySections.ld

SECTIONS { .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) } }

strstr = 0x001c446c;
ASSERT(SIZEOF(.renderfx_collect_characters) == 240, "native CollectCharacters strict span");

printf = 0x001c4058;
puts = 0x001c41b4;
ASSERT(SIZEOF(.renderfx_trace_context) == 124, "native TraceContext strict span");
ASSERT(SIZEOF(.renderfx_found_child) == 24, "native found-child format extent");
ASSERT(SIZEOF(.renderfx_child_sprite) == 24, "native child-sprite text extent");

ASSERT(SIZEOF(.set_character_focus) == 356, "SetFocus native356 exact extent");

INCLUDE config/linker/RenderFXSetMemberValue.ld

ASSERT(SIZEOF(.can_handle_mouse) == 92, "CanHandleMouse native92 exact extent");
