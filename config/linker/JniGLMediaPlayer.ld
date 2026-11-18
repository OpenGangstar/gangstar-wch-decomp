OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/jni-glmedia-player/retail-symbols.ld
__aeabi_f2d = 0x001c48f8;
SECTIONS {
 .jni_stop_on_music 0x002d1de0 : { *jni-glmedia-player.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeSetStopOnMusic) }
 .jni_total_same_instance 0x002d1ddc : { *jni-glmedia-player.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeGetTotalSoundsOfSameInstance) }

 .jni_native_total_sounds 0x002d1dd4 : { *jni-glmedia-player.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeGetTotalSounds) }

 .nativeLoadMovie 0x002d2430 : { *jni-glmedia-player.o(.text.nativeLoadMovie) }
 .nativeIsMediaPlaying 0x002d248c : { *jni-glmedia-player.o(.text.nativeIsMediaPlaying) }
 .nativeIsVideoPlayDone 0x002d24c0 : { *jni-glmedia-player.o(.text.nativeIsVideoPlayDone) }
 .nativePlaySoundBig 0x002d1ec4 : { *jni-glmedia-player.o(.text.nativePlaySoundBig) }
 .nativePlaySound 0x002d1e5c : { *jni-glmedia-player.o(.text.nativePlaySound) }
 .nativeSetVolume 0x002d2194 : { *jni-glmedia-player.o(.text.nativeSetVolume) }
 .nativeSetPitch 0x002d2290 : { *jni-glmedia-player.o(.text.nativeSetPitch) }

 .nativeInitSoundPoolArray 0x002d23fc : { *jni-glmedia-player.o(.text.nativeInitSoundPoolArray) }

 .nativeDestroySoundPool 0x002d23c8 : { *jni-glmedia-player.o(.text.nativeDestroySoundPool) }

 .nativeStopAllBigSound 0x002d2394 : { *jni-glmedia-player.o(.text.nativeStopAllBigSound) }

 .nativeStopAllSoundPool 0x002d2360 : { *jni-glmedia-player.o(.text.nativeStopAllSoundPool) }

 .nativeUnloadAllSounds 0x002d232c : { *jni-glmedia-player.o(.text.nativeUnloadAllSounds) }

 .nativeStopAllSounds 0x002d22f8 : { *jni-glmedia-player.o(.text.nativeStopAllSounds) }

 .jni_media_init 0x002d19c8 : { *jni-glmedia-player.o(.text.Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeInit) }
 .jni_id_playSoundID 0x004b6634 (NOLOAD) : { *jni-glmedia-player.o(.bss.playSoundID) }
 .jni_id_playSoundBigID 0x004b6638 (NOLOAD) : { *jni-glmedia-player.o(.bss.playSoundBigID) }
 .jni_id_setVolID 0x004b6658 (NOLOAD) : { *jni-glmedia-player.o(.bss.setVolID) }
 .jni_id_setPitchID 0x004b6664 (NOLOAD) : { *jni-glmedia-player.o(.bss.setPitchID) }
 .jni_id_stopAllID 0x004b6668 (NOLOAD) : { *jni-glmedia-player.o(.bss.stopAllID) }
 .jni_id_unloadAllID 0x004b666c (NOLOAD) : { *jni-glmedia-player.o(.bss.unloadAllID) }
 .jni_id_stopAllPoolID 0x004b6670 (NOLOAD) : { *jni-glmedia-player.o(.bss.stopAllPoolID) }
 .jni_id_stopAllBigID 0x004b6674 (NOLOAD) : { *jni-glmedia-player.o(.bss.stopAllBigID) }
 .jni_id_destroySoundPoolID 0x004b6678 (NOLOAD) : { *jni-glmedia-player.o(.bss.destroySoundPoolID) }
 .jni_id_initSoundPoolArrayID 0x004b667c (NOLOAD) : { *jni-glmedia-player.o(.bss.initSoundPoolArrayID) }
 .jni_id_loadMovie 0x004b6680 (NOLOAD) : { *jni-glmedia-player.o(.bss.loadMovie) }
 .jni_id_isMediaPlaying 0x004b6684 (NOLOAD) : { *jni-glmedia-player.o(.bss.isMediaPlaying) }
 .jni_id_IsVideoPlayDone 0x004b6688 (NOLOAD) : { *jni-glmedia-player.o(.bss.IsVideoPlayDone) }
 .jni_text_4132b8 0x004132b8 : { *jni-glmedia-player.o(.rodata.jni_text_4132b8) }
 .jni_text_4132c8 0x004132c8 : { *jni-glmedia-player.o(.rodata.jni_text_4132c8) }
 .jni_text_4132d0 0x004132d0 : { *jni-glmedia-player.o(.rodata.jni_text_4132d0) }
 .jni_text_4132e4 0x004132e4 : { *jni-glmedia-player.o(.rodata.jni_text_4132e4) }
 .jni_text_4132ec 0x004132ec : { *jni-glmedia-player.o(.rodata.jni_text_4132ec) }
 .jni_text_4132f8 0x004132f8 : { *jni-glmedia-player.o(.rodata.jni_text_4132f8) }
 .jni_text_413300 0x00413300 : { *jni-glmedia-player.o(.rodata.jni_text_413300) }
 .jni_text_413310 0x00413310 : { *jni-glmedia-player.o(.rodata.jni_text_413310) }
 .jni_text_413318 0x00413318 : { *jni-glmedia-player.o(.rodata.jni_text_413318) }
 .jni_text_413324 0x00413324 : { *jni-glmedia-player.o(.rodata.jni_text_413324) }
 .jni_text_413334 0x00413334 : { *jni-glmedia-player.o(.rodata.jni_text_413334) }
 .jni_text_413340 0x00413340 : { *jni-glmedia-player.o(.rodata.jni_text_413340) }
 .jni_text_413348 0x00413348 : { *jni-glmedia-player.o(.rodata.jni_text_413348) }
 .jni_text_413358 0x00413358 : { *jni-glmedia-player.o(.rodata.jni_text_413358) }
 .jni_text_413360 0x00413360 : { *jni-glmedia-player.o(.rodata.jni_text_413360) }
 .jni_text_41336c 0x0041336c : { *jni-glmedia-player.o(.rodata.jni_text_41336c) }
 .jni_text_41337c 0x0041337c : { *jni-glmedia-player.o(.rodata.jni_text_41337c) }
 .jni_text_413248 0x00413248 : { *jni-glmedia-player.o(.rodata.jni_text_413248) }
 .jni_text_41338c 0x0041338c : { *jni-glmedia-player.o(.rodata.jni_text_41338c) }
 .jni_text_413398 0x00413398 : { *jni-glmedia-player.o(.rodata.jni_text_413398) }
 .jni_text_4133a8 0x004133a8 : { *jni-glmedia-player.o(.rodata.jni_text_4133a8) }
 .jni_text_4133b4 0x004133b4 : { *jni-glmedia-player.o(.rodata.jni_text_4133b4) }
 .jni_text_4133c4 0x004133c4 : { *jni-glmedia-player.o(.rodata.jni_text_4133c4) }
 .jni_text_4133d0 0x004133d0 : { *jni-glmedia-player.o(.rodata.jni_text_4133d0) }
 .jni_text_4133e0 0x004133e0 : { *jni-glmedia-player.o(.rodata.jni_text_4133e0) }
 .jni_text_4133e8 0x004133e8 : { *jni-glmedia-player.o(.rodata.jni_text_4133e8) }
 .jni_text_4133f4 0x004133f4 : { *jni-glmedia-player.o(.rodata.jni_text_4133f4) }
 .jni_text_413400 0x00413400 : { *jni-glmedia-player.o(.rodata.jni_text_413400) }
 .jni_text_413410 0x00413410 : { *jni-glmedia-player.o(.rodata.jni_text_413410) }
 .jni_text_413420 0x00413420 : { *jni-glmedia-player.o(.rodata.jni_text_413420) }
 .jni_text_41342c 0x0041342c : { *jni-glmedia-player.o(.rodata.jni_text_41342c) }
 .jni_text_413438 0x00413438 : { *jni-glmedia-player.o(.rodata.jni_text_413438) }
 .jni_text_41344c 0x0041344c : { *jni-glmedia-player.o(.rodata.jni_text_41344c) }
 .jni_text_413460 0x00413460 : { *jni-glmedia-player.o(.rodata.jni_text_413460) }
 .jni_text_413258 0x00413258 : { *jni-glmedia-player.o(.rodata.jni_text_413258) }
 .jni_text_41346c 0x0041346c : { *jni-glmedia-player.o(.rodata.jni_text_41346c) }
 .jni_text_41347c 0x0041347c : { *jni-glmedia-player.o(.rodata.jni_text_41347c) }
 .jni_text_413484 0x00413484 : { *jni-glmedia-player.o(.rodata.jni_text_413484) }
 .jni_text_413494 0x00413494 : { *jni-glmedia-player.o(.rodata.jni_text_413494) }

 .nativeSetVolumeBig 0x002d21fc : { *jni-glmedia-player.o(.text.nativeSetVolumeBig) }
 .setVolumeBigID 0x004b665c (NOLOAD) : { *jni-glmedia-player.o(.bss.setVolumeBigID) }
 .nativeResetSound 0x002d225c : { *jni-glmedia-player.o(.text.nativeResetSound) }
 .resetSoundID 0x004b6660 (NOLOAD) : { *jni-glmedia-player.o(.bss.resetSoundID) }

 .nativeLoadSoundBig 0x002d1e28 : { *jni-glmedia-player.o(.text.nativeLoadSoundBig) }
 .loadSoundBigID 0x004b6630 (NOLOAD) : { *jni-glmedia-player.o(.bss.loadSoundBigID) }

 .nativeIsSoundLoadedBig 0x002d2160 : { *jni-glmedia-player.o(.text.nativeIsSoundLoadedBig) }
 .isSoundLoadedBigID 0x004b6620 (NOLOAD) : { *jni-glmedia-player.o(.bss.isSoundLoadedBigID) }

 .nativeUnloadSoundBig 0x002d20f0 : { *jni-glmedia-player.o(.text.nativeUnloadSoundBig) }
 .unloadSoundBigID 0x004b6628 (NOLOAD) : { *jni-glmedia-player.o(.bss.unloadSoundBigID) }

 .nativeResumeSoundBig 0x002d2010 : { *jni-glmedia-player.o(.text.nativeResumeSoundBig) }
 .resumeSoundBigID 0x004b664c (NOLOAD) : { *jni-glmedia-player.o(.bss.resumeSoundBigID) }
 .nativeStopSoundBig 0x002d2080 : { *jni-glmedia-player.o(.text.nativeStopSoundBig) }
 .stopSoundBigID 0x004b6654 (NOLOAD) : { *jni-glmedia-player.o(.bss.stopSoundBigID) }

 .nativeLoadSound 0x002d1dec : { *jni-glmedia-player.o(.text.nativeLoadSound) }
 .loadSoundID 0x004b662c (NOLOAD) : { *jni-glmedia-player.o(.bss.loadSoundID) }
 .nativePauseSoundBig 0x002d1f6c : { *jni-glmedia-player.o(.text.nativePauseSoundBig) }
 .pauseSoundBigID 0x004b6640 (NOLOAD) : { *jni-glmedia-player.o(.bss.pauseSoundBigID) }
 .nativePauseAllSounds 0x002d1fa0 : { *jni-glmedia-player.o(.text.nativePauseAllSounds) }
 .pauseAllID 0x004b6644 (NOLOAD) : { *jni-glmedia-player.o(.bss.pauseAllID) }

 .nativeStopSound 0x002d2044 : { *jni-glmedia-player.o(.text.nativeStopSound) }
 .stopSoundID 0x004b6650 (NOLOAD) : { *jni-glmedia-player.o(.bss.stopSoundID) }
 .nativeUnloadSound 0x002d20b4 : { *jni-glmedia-player.o(.text.nativeUnloadSound) }
 .unloadSoundID 0x004b6624 (NOLOAD) : { *jni-glmedia-player.o(.bss.unloadSoundID) }
 .nativeIsSoundLoaded 0x002d2124 : { *jni-glmedia-player.o(.text.nativeIsSoundLoaded) }
 .isSoundLoadedID 0x004b661c (NOLOAD) : { *jni-glmedia-player.o(.bss.isSoundLoadedID) }

 .native_resume 0x002d1fd4 : { *jni-glmedia-player.o(.text.nativeResumeSound) }
 .resume_method 0x004b6648 (NOLOAD) : { *jni-glmedia-player.o(.bss.resumeSoundID) }
 .native_pause 0x002d1f30 : { *jni-glmedia-player.o(.text.nativePauseSound) }
 .jni_class 0x004b6618 (NOLOAD) : { *jni-glmedia-player.o(.bss.mClassGLMediaPlayer) }
 .pause_method 0x004b663c (NOLOAD) : { *jni-glmedia-player.o(.bss.pauseSoundID) }
 .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
 .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.jni_class) == 4,"JNI class reference extent");
ASSERT(SIZEOF(.pause_method) == 4,"JNI pause method reference extent");
ASSERT(SIZEOF(.resume_method) == 4,"JNI resume method reference extent");
ASSERT(SIZEOF(.stopSoundID) == 4,"JNI stopSoundID extent");
ASSERT(SIZEOF(.unloadSoundID) == 4,"JNI unloadSoundID extent");
ASSERT(SIZEOF(.isSoundLoadedID) == 4,"JNI isSoundLoadedID extent");
ASSERT(SIZEOF(.loadSoundID) == 4,"JNI loadSoundID extent");
ASSERT(SIZEOF(.pauseSoundBigID) == 4,"JNI pauseSoundBigID extent");
ASSERT(SIZEOF(.pauseAllID) == 4,"JNI pauseAllID extent");
ASSERT(SIZEOF(.resumeSoundBigID) == 4,"JNI resumeSoundBigID extent");
ASSERT(SIZEOF(.stopSoundBigID) == 4,"JNI stopSoundBigID extent");
ASSERT(SIZEOF(.unloadSoundBigID) == 4,"JNI unloadSoundBigID extent");
ASSERT(SIZEOF(.isSoundLoadedBigID) == 4,"JNI isSoundLoadedBigID extent");
ASSERT(SIZEOF(.loadSoundBigID) == 4,"JNI loadSoundBigID extent");
ASSERT(SIZEOF(.resetSoundID) == 4,"JNI resetSoundID extent");
ASSERT(SIZEOF(.setVolumeBigID) == 4,"JNI volume method extent");
ASSERT(SIZEOF(.jni_id_playSoundID) == 4,"JNI playSoundID extent");
ASSERT(SIZEOF(.jni_id_playSoundBigID) == 4,"JNI playSoundBigID extent");
ASSERT(SIZEOF(.jni_id_setVolID) == 4,"JNI setVolID extent");
ASSERT(SIZEOF(.jni_id_setPitchID) == 4,"JNI setPitchID extent");
ASSERT(SIZEOF(.jni_id_stopAllID) == 4,"JNI stopAllID extent");
ASSERT(SIZEOF(.jni_id_unloadAllID) == 4,"JNI unloadAllID extent");
ASSERT(SIZEOF(.jni_id_stopAllPoolID) == 4,"JNI stopAllPoolID extent");
ASSERT(SIZEOF(.jni_id_stopAllBigID) == 4,"JNI stopAllBigID extent");
ASSERT(SIZEOF(.jni_id_destroySoundPoolID) == 4,"JNI destroySoundPoolID extent");
ASSERT(SIZEOF(.jni_id_initSoundPoolArrayID) == 4,"JNI initSoundPoolArrayID extent");
ASSERT(SIZEOF(.jni_id_loadMovie) == 4,"JNI loadMovie extent");
ASSERT(SIZEOF(.jni_id_isMediaPlaying) == 4,"JNI isMediaPlaying extent");
ASSERT(SIZEOF(.jni_id_IsVideoPlayDone) == 4,"JNI IsVideoPlayDone extent");
