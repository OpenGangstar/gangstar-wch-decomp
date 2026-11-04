OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-soundmanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .sdk_startup_function_0 0x003539ac : { *sdk-startup-soundmanager.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x003534a4 : { *sdk-startup-soundmanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00353510 : { *sdk-startup-soundmanager.o(.text._GLOBAL__I__ZN12SoundManager15s_soundsPlayingE) }
    .sdk_startup_storage_0 0x004bc1f8 (NOLOAD) : { *sdk-startup-soundmanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc218 (NOLOAD) : { *sdk-startup-soundmanager.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .sound_manager_helper_0 0x00352774 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager4initEv) }
    .sound_manager_helper_1 0x00352784 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager6unInitEv) }
    .sound_manager_helper_2 0x00352800 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager12useIPodRadioEv) }
    .sound_manager_helper_3 0x00352804 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager15useBuiltInRadioEv) }
    .sound_manager_helper_4 0x00352810 : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager10canUseIPodEv) }
    .sound_manager_helper_5 0x00352814 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager8initIPodEv) }
    .sound_manager_helper_6 0x00352818 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager11cleanupIPodEv) }
    .sound_manager_helper_7 0x0035281c : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager17iPodIsInitializedEv) }
    .sound_manager_helper_8 0x00352820 : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager16getPlaylistCountEv) }
    .sound_manager_helper_9 0x00352828 : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager15getPlaylistNameEiPc) }
    .sound_manager_helper_10 0x0035282c : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager26getPlaylistIndexFromStringEPKc) }
    .sound_manager_helper_11 0x00352834 : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager14getCurPlaylistEv) }
    .sound_manager_helper_12 0x0035283c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager11setPlaylistEi) }
    .sound_manager_helper_13 0x00352840 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager14setListenerPosERKN3irr4core8vector3dIfEES5_S5_) }
    .sound_manager_helper_14 0x00352874 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager11_getSoundIdEi) }
    .sound_manager_helper_15 0x0035287c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager9_getResIdEi) }
    .sound_manager_helper_16 0x00352884 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager13_getSoundTypeEi) }
    .sound_manager_helper_17 0x00352890 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager12disableMusicEv) }
    .sound_manager_helper_18 0x0035289c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager11enableMusicEv) }
    .sound_manager_helper_19 0x0035349c : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager19getNumRadioStationsEv) }
    .sound_manager_helper_20 0x00352c24 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager9setVolumeEiif) }
    .sound_manager_helper_21 0x00353320 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager12stopAllMusicEv) }
    .sound_manager_helper_22 0x00353334 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager13stopAllSoundsEv) }
    .sound_manager_helper_23 0x00353348 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager14pauseAllSoundsEv) }
    .sound_manager_helper_24 0x00353360 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager15stopLowFpsMusicEv) }
    .sound_manager_helper_25 0x00353374 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager4stopEiii) }
    .sound_manager_helper_26 0x00353474 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager6resumeEi) }
    .sound_manager_helper_27 0x00353488 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager5pauseEi) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
