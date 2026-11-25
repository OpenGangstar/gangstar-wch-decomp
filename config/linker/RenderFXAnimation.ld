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
    .renderfx_trace_context 0x003ed2f4 : { *renderfx-animation.o(.text._ZN8RenderFX27DBG_TraceContextInformationEPN7gameswf9characterE) }
    .renderfx_found_child 0x0044ddf8 : { *renderfx-animation.o(.rodata.renderfx_found_child) }
    .renderfx_child_sprite 0x0044de10 : { *renderfx-animation.o(.rodata.renderfx_child_sprite) }

    .renderfx_collect_characters 0x003ed1bc : { *renderfx-animation.o(.text._ZN8RenderFX17CollectCharactersEPN7gameswf9characterEPKci) }
    .renderfx_update 0x003f0040 : { *renderfx-animation.o(.text._ZN8RenderFX6UpdateEib) }
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
