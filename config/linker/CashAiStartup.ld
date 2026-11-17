OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-cash/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN23retail_cash_transitions16civPassive_transE = 0x004235f0;
_ZN23retail_cash_transitions17scriptedNpc_transE = 0x0042371c;
_ZN23retail_cash_transitions19civAggressive_transE = 0x0042374c;
_ZN23retail_cash_transitions16gangMember_transE = 0x00423830;
_ZN23retail_cash_transitions9cop_transE = 0x0042383c;
_ZN23retail_cash_transitions10swat_transE = 0x00423974;
_ZN23retail_cash_transitions17civ_vehicle_transE = 0x00423980;
_ZN23retail_cash_transitions17cop_vehicle_transE = 0x00423a10;
_ZN23retail_cash_transitions11guard_transE = 0x00423ac4;
_ZN23retail_cash_transitions22scripted_vehicle_transE = 0x00423b6c;
SECTIONS
{
    .cash_set_position 0x003279e8 : { *ai-startup-cash.o(.text._ZN4Cash11SetPositionEii) }
    .cash_set_cash 0x003279f0 : { *ai-startup-cash.o(.text._ZN4Cash7SetCashEi) }
    .cash_get_cash 0x003279f4 : { *ai-startup-cash.o(.text._ZN4Cash7GetCashEv) }
    .ai_startup_function_0 0x003279f8 : { *ai-startup-cash.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00327e34 : { *ai-startup-cash.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00327f78 : { *ai-startup-cash.o(.text._GLOBAL__I__ZN4CashC2EP7ASpriteiiiii) }
    .ai_startup_storage_0 0x004b93c8 (NOLOAD) : { *ai-startup-cash.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b93e8 (NOLOAD) : { *ai-startup-cash.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b93f4 (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b93fc (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9404 (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b940c (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9414 (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b941c (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9424 (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b942c (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9434 (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b943c (NOLOAD) : { *ai-startup-cash.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
