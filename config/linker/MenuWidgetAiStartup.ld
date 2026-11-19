strlen = 0x001c48bc;
strrchr = 0x001c4340;
strstr = 0x001c446c;
strchr = 0x001c48e0;
__aeabi_ui2f = 0x001c4574;
__aeabi_fdiv = 0x001c4520;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-menuwidget/retail-symbols.ld
_ZdlPv = 0x001c42b0;
sprintf = 0x001c46ac;
memset = 0x001c45d4;
__aeabi_idivmod = 0x001c4934;
__stack_chk_fail = 0x001c42e0;
__aeabi_atexit = 0x001c494c;
_ZN29retail_menuwidget_transitions16civPassive_transE = 0x0041b6c8;
_ZN29retail_menuwidget_transitions17scriptedNpc_transE = 0x0041b7f4;
_ZN29retail_menuwidget_transitions19civAggressive_transE = 0x0041b824;
_ZN29retail_menuwidget_transitions16gangMember_transE = 0x0041b908;
_ZN29retail_menuwidget_transitions9cop_transE = 0x0041b914;
_ZN29retail_menuwidget_transitions10swat_transE = 0x0041ba4c;
_ZN29retail_menuwidget_transitions17civ_vehicle_transE = 0x0041ba58;
_ZN29retail_menuwidget_transitions17cop_vehicle_transE = 0x0041bae8;
_ZN29retail_menuwidget_transitions11guard_transE = 0x0041bb9c;
_ZN29retail_menuwidget_transitions22scripted_vehicle_transE = 0x0041bc44;
INCLUDE config/linker/MenuWidgetFunctions.ld
INCLUDE config/linker/RenderFXAnimationFunctions.ld
INCLUDE config/linker/MenuWidgetMissionSections.ld
SECTIONS
{
    .renderfx_trace_context 0x003ed2f4 : { *renderfx-animation.o(.text._ZN8RenderFX27DBG_TraceContextInformationEPN7gameswf9characterE) }
    .renderfx_found_child 0x0044ddf8 : { *renderfx-animation.o(.rodata.renderfx_found_child) }
    .renderfx_child_sprite 0x0044de10 : { *renderfx-animation.o(.rodata.renderfx_child_sprite) }

    .renderfx_collect_characters 0x003ed1bc : { *renderfx-animation.o(.text._ZN8RenderFX17CollectCharactersEPN7gameswf9characterEPKci) }

    .ai_startup_function_0 0x002ec014 : { *ai-startup-menuwidget.o(.text.__tcf_3) }
    .ai_startup_function_1 0x002ef2bc : { *ai-startup-menuwidget.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x002ef400 : { *ai-startup-menuwidget.o(.text._GLOBAL__I__ZN10MenuWidgetC2EPKc) }
    .ai_startup_storage_0 0x004b7cf0 (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b7d10 (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b7d1c (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b7d24 (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b7d2c (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b7d34 (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b7d3c (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b7d44 (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b7d4c (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b7d54 (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b7d5c (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b7d64 (NOLOAD) : { *ai-startup-menuwidget.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");

INCLUDE config/linker/RenderFXUtilitySections.ld

ASSERT(SIZEOF(.renderfx_collect_characters) == 240, "native CollectCharacters dependency span");

printf = 0x001c4058;
puts = 0x001c41b4;
ASSERT(SIZEOF(.renderfx_trace_context) == 124, "native TraceContext strict span");
ASSERT(SIZEOF(.renderfx_found_child) == 24, "native found-child format extent");
ASSERT(SIZEOF(.renderfx_child_sprite) == 24, "native child-sprite text extent");
