OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-deliverysidemission/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .side_mission_obj2_message 0x003465dc : { *sdk-startup-deliverysidemission.o(.text._ZN19DeliverySideMission14getObj2MessageEv) }
    .side_mission_obj1_message 0x003465d4 : { *sdk-startup-deliverysidemission.o(.text._ZN19DeliverySideMission14getObj1MessageEv) }
    .side_mission_end_message 0x003465cc : { *sdk-startup-deliverysidemission.o(.text._ZN19DeliverySideMission13getEndMessageEv) }
    .side_mission_start_message 0x003465c4 : { *sdk-startup-deliverysidemission.o(.text._ZN19DeliverySideMission15getStartMessageEv) }
    .side_mission_end 0x003465b0 : { *sdk-startup-deliverysidemission.o(.text._ZN19DeliverySideMission3endEv) }
    .side_mission_reward 0x003465b4 : { *sdk-startup-deliverysidemission.o(.text._ZN19DeliverySideMission14getMoneyRewardEv) }
    .side_mission_goal_message 0x003465bc : { *sdk-startup-deliverysidemission.o(.text._ZN19DeliverySideMission14getGoalMessageEv) }
    .sdk_startup_function_0 0x003465e4 : { *sdk-startup-deliverysidemission.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00346848 : { *sdk-startup-deliverysidemission.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x003468b4 : { *sdk-startup-deliverysidemission.o(.text._GLOBAL__I__ZN19DeliverySideMissionC2Ev) }
    .sdk_startup_storage_0 0x004bb504 (NOLOAD) : { *sdk-startup-deliverysidemission.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bb524 (NOLOAD) : { *sdk-startup-deliverysidemission.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
