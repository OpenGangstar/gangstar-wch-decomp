OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-message/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN26retail_message_transitions16civPassive_transE = 0x004241b8;
_ZN26retail_message_transitions17scriptedNpc_transE = 0x004242e4;
_ZN26retail_message_transitions19civAggressive_transE = 0x00424314;
_ZN26retail_message_transitions16gangMember_transE = 0x004243f8;
_ZN26retail_message_transitions9cop_transE = 0x00424404;
_ZN26retail_message_transitions10swat_transE = 0x0042453c;
_ZN26retail_message_transitions17civ_vehicle_transE = 0x00424548;
_ZN26retail_message_transitions17cop_vehicle_transE = 0x004245d8;
_ZN26retail_message_transitions11guard_transE = 0x0042468c;
_ZN26retail_message_transitions22scripted_vehicle_transE = 0x00424734;
SECTIONS
{
    .message_clear 0x00328e7c : { *(.text._ZN7Message12clearMessageEb) }
    .message_draw 0x00328ef8 : { *(.text._ZNK7Message6draw2dEv) }
    .message_draw_thunk 0x00328ee4 : { *(.text._ZThn4_NK7Message6draw2dEv) }
    .message_328e24 0x00328e24 : { *ai-startup-message.o(.text._ZN7Message8setTimerEi) }
    .message_328e6c 0x00328e6c : { *ai-startup-message.o(.text._ZN7Message7setAnimEi) }
    .ai_startup_function_0 0x00328e3c : { *ai-startup-message.o(.text.__tcf_3) }
    .ai_startup_function_1 0x003291e4 : { *ai-startup-message.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00329328 : { *ai-startup-message.o(.text._GLOBAL__I__ZN7MessageC2EP7ASpriteN11MenuManager5eTextEii) }
    .ai_startup_storage_0 0x004b9570 (NOLOAD) : { *ai-startup-message.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9590 (NOLOAD) : { *ai-startup-message.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b959c (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b95a4 (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b95ac (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b95b4 (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b95bc (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b95c4 (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b95cc (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b95d4 (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b95dc (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b95e4 (NOLOAD) : { *ai-startup-message.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
