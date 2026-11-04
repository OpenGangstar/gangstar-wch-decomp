# SoundManager helpers

The Android build leaves the iPod and listener hooks empty or returns a
constant. The other helpers recover the manager flags, resource ID base,
sound table stride and radio station count. The native audio wrappers check
the initialized flag before dispatching. The separate playLowFpsMusic
candidate still differs in register allocation and remains pending.

```text
OK  _ZN12SoundManager4initEv  0x00352775  16 bytes
OK  _ZN12SoundManager6unInitEv  0x00352785  2 bytes
OK  _ZN12SoundManager12useIPodRadioEv  0x00352801  2 bytes
OK  _ZN12SoundManager15useBuiltInRadioEv  0x00352805  10 bytes
OK  _ZNK12SoundManager10canUseIPodEv  0x00352811  4 bytes
OK  _ZN12SoundManager8initIPodEv  0x00352815  2 bytes
OK  _ZN12SoundManager11cleanupIPodEv  0x00352819  2 bytes
OK  _ZNK12SoundManager17iPodIsInitializedEv  0x0035281d  4 bytes
OK  _ZNK12SoundManager16getPlaylistCountEv  0x00352821  6 bytes
OK  _ZNK12SoundManager15getPlaylistNameEiPc  0x00352829  2 bytes
OK  _ZNK12SoundManager26getPlaylistIndexFromStringEPKc  0x0035282d  6 bytes
OK  _ZNK12SoundManager14getCurPlaylistEv  0x00352835  6 bytes
OK  _ZN12SoundManager11setPlaylistEi  0x0035283d  2 bytes
OK  _ZN12SoundManager14setListenerPosERKN3irr4core8vector3dIfEES5_S5_  0x00352841  2 bytes
OK  _ZN12SoundManager11_getSoundIdEi  0x00352875  8 bytes
OK  _ZN12SoundManager9_getResIdEi  0x0035287d  8 bytes
OK  _ZN12SoundManager13_getSoundTypeEi  0x00352885  12 bytes
OK  _ZN12SoundManager12disableMusicEv  0x00352891  12 bytes
OK  _ZN12SoundManager11enableMusicEv  0x0035289d  16 bytes
OK  _ZNK12SoundManager19getNumRadioStationsEv  0x0035349d  6 bytes
OK  _ZN12SoundManager9setVolumeEiif  0x00352c25  24 bytes
OK  _ZN12SoundManager12stopAllMusicEv  0x00353321  18 bytes
OK  _ZN12SoundManager13stopAllSoundsEv  0x00353335  18 bytes
OK  _ZN12SoundManager14pauseAllSoundsEv  0x00353349  24 bytes
OK  _ZN12SoundManager15stopLowFpsMusicEv  0x00353361  18 bytes
OK  _ZN12SoundManager4stopEiii  0x00353375  20 bytes
OK  _ZN12SoundManager6resumeEi  0x00353475  20 bytes
OK  _ZN12SoundManager5pauseEi  0x00353489  20 bytes
```
