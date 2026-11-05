# Sound data loading

SoundManager creates ADPCM stream metadata or acquires a WAV decoder.
For a static WAV it decodes the samples before obtaining a sound-data
slot. The retail path assumes the entry selects ADPCM or WAV and
leaves the return value unspecified when both codec flags are absent.

```text
OK  _ZN12SoundManager13_getSoundDataEi  0x00352f4d  260 bytes
OK SECTION .sound_manager_data_load  0x00352f4c  260 bytes
```
