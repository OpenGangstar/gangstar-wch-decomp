PROVIDE(puts = 0x001c41b4);
PROVIDE(printf = 0x001c4058);
PROVIDE(__aeabi_idiv = 0x001c43dc);
PROVIDE(__aeabi_uidiv = 0x001c4604);
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-scenenodemanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
strlen = 0x001c48bc;
strcpy = 0x001c3fd4;
_Znaj = 0x001c3ff8;
_Znwj = 0x001c4814;
_ZdaPv = 0x001c461c;
memset = 0x001c45d4;
__stack_chk_fail = 0x001c42e0;
SECTIONS
{
    .scene_node_reclaim_garbage 0x003218d8 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager14reclaimGarbageEv) }
    .scene_node_drop 0x003219cc : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4dropEiPKN3irr5scene10ISceneNodeE) }
    .scene_node_report 0x00321720 : { *sdk-startup-scenenodemanager.o(.text._ZNK16SceneNodeManager6reportEv) }
    .scene_node_report_strings 0x00421074 : { *sdk-startup-scenenodemanager.o(.rodata.str1.4) }
 .scene_pool_id 0x00321444 : { *sdk-startup-scenenodemanager.o(.text._ZNK16SceneNodeManager9getPoolIDEi) }

    .scene_node_manage 0x00321698 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager6manageEiP11LevelObjecti .gnu.linkonce.t._ZN16SceneNodeManager6manageEiP11LevelObjecti) }

    .scene_crc_reflect 0x003213f0 : { *sdk-startup-scenenodemanager.o(.text._Z10crcReflectjc) }
    .scene_manager_setup 0x0032141c : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager5setupEv) }
    .scene_manager_update 0x00321420 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager6updateEi) }
    .scene_manager_crc 0x003215b4 : { *sdk-startup-scenenodemanager.o(.text._ZNK16SceneNodeManager3crcEPKc) }
    .scene_node_destructor 0x003215f0 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4NodeD1Ev .text._ZN16SceneNodeManager4NodeD2Ev) }
    .scene_node_setup_unmanaged 0x00321630 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4Node14setupUnmanagedEi) }
    .scene_node_constructor 0x00321658 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4NodeC1EPN3irr5scene10ISceneNodeE .text._ZN16SceneNodeManager4NodeC2EPN3irr5scene10ISceneNodeE) }
    .scene_pool_constructor 0x003218a0 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4PoolC1EPKcPN3irr7collada15CColladaFactoryEi .text._ZN16SceneNodeManager4PoolC2EPKcPN3irr7collada15CColladaFactoryEi) }
    .scene_pool_destructor 0x00322154 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4PoolD1Ev .text._ZN16SceneNodeManager4PoolD2Ev) }
    .scene_manager_teardown 0x003221ac : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager8tearDownEv) }
    .scene_manager_destructor 0x00322208 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManagerD1Ev .text._ZN16SceneNodeManagerD2Ev) }
    .scene_pool_extend 0x003225bc : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4Pool6extendEi) }
    .scene_pool_grab 0x00322388 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager4grabEiP11LevelObjectiPPPv) }
    .scene_pool_find_or_create 0x0032268c : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager16findOrCreatePoolEPKciPN3irr7collada15CColladaFactoryE) }
    .scene_manager_constructor 0x00321aa0 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManagerC1Ev .text._ZN16SceneNodeManagerC2Ev) }
    .scene_manager_instance 0x00321b20 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager11getInstanceEv) }
    .scene_manager_instance_cleanup 0x0032224c : { *sdk-startup-scenenodemanager.o(.text.__tcf_0) }
    .scene_manager_instance_guard 0x004b8b9c (NOLOAD) : { *sdk-startup-scenenodemanager.o(.bss._ZGVZN16SceneNodeManager11getInstanceEvE16sceneNodeManager) }
    .scene_manager_instance_storage 0x004b8ba0 (NOLOAD) : { *sdk-startup-scenenodemanager.o(.bss._ZZN16SceneNodeManager11getInstanceEvE16sceneNodeManager) }
    .sdk_startup_function_0 0x00322068 : { *sdk-startup-scenenodemanager.o(.text.__tcf_3) }
    .scene_manager_get_pool_path 0x00322098 : { *sdk-startup-scenenodemanager.o(.text._ZNK16SceneNodeManager9getPoolIDEPKc) }
    .sdk_startup_function_1 0x00321b9c : { *sdk-startup-scenenodemanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00321c08 : { *sdk-startup-scenenodemanager.o(.text._GLOBAL__I__Z10crcReflectjc) }
    .sdk_startup_storage_0 0x004b8b70 (NOLOAD) : { *sdk-startup-scenenodemanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b8b90 (NOLOAD) : { *sdk-startup-scenenodemanager.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.scene_manager_instance_guard) == 4, "SceneNodeManager singleton guard extent");
ASSERT(SIZEOF(.scene_manager_instance_storage) == 0x42c, "SceneNodeManager singleton storage extent");

ASSERT(SIZEOF(.scene_pool_id)<=68,"native getPoolID span");
