# SoundManager low-FPS playback

The recovered CSound and CSoundData interfaces provide the virtual calls
and deleting destructors. Cleanup clears the sound pointer after deleting
both objects. The status check preserves the retail calls to GetStatus,
including the discarded call on the true path.

```text
OK  _ZN12SoundManager16pauseLowFpsMusicEv  0x003527a1  26 bytes
OK  _ZN12SoundManager19_cleanupLowFpsMusicEv  0x003527bd  40 bytes
OK  _ZN12SoundManager20setLowFpsMusicVolumeEf  0x003527e5  26 bytes
OK  _ZNK12SoundManager20isLowFpsMusicPlayingEv  0x00352cfd  42 bytes
OK  _ZN12SoundManager17resumeLowFpsMusicEv  0x00352da5  36 bytes
```
