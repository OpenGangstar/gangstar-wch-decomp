# SoundManager callbacks

The callbacks reuse the recovered pitch, volume, playback, stop and status
methods. The volume and playback callbacks preserve the retail pair of
singleton lookups and the percent-to-gain conversion. The completion
callback dispatches cutscene cleanup when the playing counter is positive.

```text
OK  _ZN12SoundManager16setPitchCallbackEiif  0x0035384d  48 bytes
OK  _ZN12SoundManager17setVolumeCallbackEiif  0x0035387d  76 bytes
OK  _ZN12SoundManager17stopSoundCallbackEii  0x003538c9  56 bytes
OK  _ZN12SoundManager22isSoundPlayingCallbackEii  0x0035397d  48 bytes
OK  _Z16soundEndCallbackv  0x00353821  44 bytes
OK  _ZN12SoundManager17playSoundCallbackEibff  0x00353901  124 bytes
```
