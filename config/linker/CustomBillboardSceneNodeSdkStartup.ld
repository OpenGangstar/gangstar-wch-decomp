OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-custombillboardscenenode/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .billboard_set_parent 0x002f79e4 : { *(.text._ZN24CustomBillboardSceneNode9setParentEPN3irr5scene10ISceneNodeE) }
    .sdk_startup_function_0 0x002f7a24 : { *sdk-startup-custombillboardscenenode.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x002f7dd0 : { *sdk-startup-custombillboardscenenode.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x002f7e3c : { *sdk-startup-custombillboardscenenode.o(.text._GLOBAL__I__ZN24CustomBillboardSceneNodeC2ERKN3irr7collada16CColladaDatabaseEPNS1_5SNodeE) }
    .sdk_startup_storage_0 0x004b7ed4 (NOLOAD) : { *sdk-startup-custombillboardscenenode.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b7ef4 (NOLOAD) : { *sdk-startup-custombillboardscenenode.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
