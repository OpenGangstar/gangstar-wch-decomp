OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-soundmanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_fmul = 0x001c4724;
__aeabi_fcmpeq = 0x001c470c;
_Znwj = 0x001c4814;
_ZdaPv = 0x001c461c;
__cxa_pure_virtual = 0;
__aeabi_idivmod = 0x001c4934;
__aeabi_fcmplt = 0x001c479c;
__aeabi_fcmpgt = 0x001c419c;
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
    .sound_manager_radio_0 0x00352ba8 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager15playLowFpsMusicEib) }
    .sound_manager_radio_1 0x00352f20 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager9playRadioEi) }
    .sound_manager_radio_2 0x00353388 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager9stopRadioEv) }
    .sound_manager_radio_3 0x003539dc : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager18changeRadioStationEi) }
    .sound_manager_radio_4 0x00353a34 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager16lastRadioStationEv) }
    .sound_manager_radio_5 0x00353a54 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager16nextRadioStationEv) }
    .sound_manager_lowfps_0 0x003527a0 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager16pauseLowFpsMusicEv) }
    .sound_manager_lowfps_1 0x003527bc : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager19_cleanupLowFpsMusicEv) }
    .sound_manager_lowfps_2 0x003527e4 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager20setLowFpsMusicVolumeEf) }
    .sound_manager_lowfps_3 0x00352cfc : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager20isLowFpsMusicPlayingEv) }
    .sound_manager_lowfps_4 0x00352da4 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager17resumeLowFpsMusicEv) }
    .sound_manager_slots_0 0x00352844 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager26getNumberOfAllocatedSoundsEv) }
    .sound_manager_slots_1 0x00352c3c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager14isSoundPlayingEi) }
    .sound_manager_slots_2 0x00352c70 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager14isSoundPlayingEii) }
    .sound_manager_dispatch_0 0x00352920 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager8setPitchEiif) }
    .sound_manager_dispatch_1 0x0035294c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager12setSourcePosEiiRKN3irr4core8vector3dIfEE) }
    .sound_manager_dispatch_2 0x00352b68 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager6playExEiPKN3irr4core8vector3dIfEEbfibfPFvvE) }
    .sound_manager_dispatch_3 0x00352b40 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager24convertVisual3DToSound3DERKN3irr4core8vector3dIfEE) }
    .sound_manager_callback_0 0x0035384c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager16setPitchCallbackEiif) }
    .sound_manager_callback_1 0x0035387c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager17setVolumeCallbackEiif) }
    .sound_manager_callback_2 0x003538c8 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager17stopSoundCallbackEii) }
    .sound_manager_callback_3 0x0035397c : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager22isSoundPlayingCallbackEii) }
    .sound_manager_callback_4 0x00353820 : { *sdk-startup-soundmanager.o(.text._Z16soundEndCallbackv) }
    .sound_manager_callback_5 0x00353900 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager17playSoundCallbackEibff) }
    .sound_manager_playing 0x004bc1f0 (NOLOAD) : { *sdk-startup-soundmanager.o(.bss._ZN12SoundManager15s_soundsPlayingE) }
    .sound_manager_lifecycle_0 0x002d40cc : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager11getInstanceEv) }
    .sound_manager_lifecycle_1 0x00352750 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager5clearEv) }
    .sound_manager_lifecycle_2 0x00352788 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager11toggleSoundEv) }
    .sound_manager_instance 0x004bc1f4 (NOLOAD) : { *sdk-startup-soundmanager.o(.bss._ZN12SoundManager14s_soundManagerE) }
    .sound_manager_d0 0x00353a78 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManagerD0Ev) }
    .sound_manager_d1 0x00353ae8 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManagerD1Ev .text._ZN12SoundManagerD2Ev) }
    .sound_manager_vtable 0x004ad850 : { *sdk-startup-soundmanager.o(.data.rel.ro._ZTV12SoundManager .gnu.linkonce.d.rel.ro._ZTV12SoundManager) }
    .sound_updatable_vtable 0x004a6290 : { *sdk-startup-soundmanager.o(.gnu.linkonce.d.rel.ro._ZTV10IUpdatable .data.rel.ro._ZTV10IUpdatable) }
    .sound_updatable_d0 0x002d62b8 : { *sdk-startup-soundmanager.o(.gnu.linkonce.t._ZN10IUpdatableD0Ev) }
    .sound_updatable_d1 0x002d62d8 : { *sdk-startup-soundmanager.o(.gnu.linkonce.t._ZN10IUpdatableD1Ev .gnu.linkonce.t._ZN10IUpdatableD2Ev) }
    .sound_manager_frequencies 0x003528ac : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager17_resetFrequenciesEv) }
    .sound_manager_frequency_counts 0x00436390 : { *sdk-startup-soundmanager.o(.rodata._ZN12SoundManager11s_playFreqsE) }
    .sound_manager_radio_track 0x00352e60 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager14_getRadioTrackEi) }
    .sound_manager_setup_0 0x00352bbc : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager12setSfxVolumeEf) }
    .sound_manager_setup_1 0x00353050 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager12allocBuffersEv) }
    .sound_manager_setup_2 0x003537cc : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager17playPriorityAudioEib) }
    .sound_manager_setup_3 0x00352d28 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager14setMusicVolumeEf) }
    .sound_manager_cutscene_0 0x00352978 : { *sdk-startup-soundmanager.o(.text._ZNK12SoundManager15isRestrictedSfxEi) }
    .sound_manager_cutscene_1 0x003533b8 : { *sdk-startup-soundmanager.o(.text._ZN12SoundManager13beginCutsceneEv) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
