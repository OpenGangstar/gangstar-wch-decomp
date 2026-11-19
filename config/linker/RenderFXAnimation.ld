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
    .renderfx_collect_characters 0x003ed1bc : { *renderfx-animation.o(.text._ZN8RenderFX17CollectCharactersEPN7gameswf9characterEPKci) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}

INCLUDE config/linker/RenderFXUtilitySections.ld

SECTIONS { .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) } }

strstr = 0x001c446c;
ASSERT(SIZEOF(.renderfx_collect_characters) == 240, "native CollectCharacters strict span");
