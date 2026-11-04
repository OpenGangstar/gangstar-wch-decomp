# SoundManager playback setup

The priority wrapper begins cutscene audio and passes the completion
callback to the matched playback method. Buffer allocation fills entries
flagged for preloading. The volume setters clamp their input and update
the appropriate native sounds, including the low-FPS music path.

```text
OK  _ZN12SoundManager12setSfxVolumeEf  0x00352bbd  104 bytes
OK  _ZN12SoundManager12allocBuffersEv  0x00353051  68 bytes
OK  _ZN12SoundManager17playPriorityAudioEib  0x003537cd  84 bytes
OK  _ZN12SoundManager14setMusicVolumeEf  0x00352d29  124 bytes
```
