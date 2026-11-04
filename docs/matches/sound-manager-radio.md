# SoundManager radio controls

The native playback call takes a sound ID, a float volume, and a loop flag.
The retail callee converts the second argument to double and forwards the
third. Recovering that signature closes the register allocation difference
in playLowFpsMusic from the previous batch.

The radio controls recover the track and station fields and reuse the
existing stop wrapper. The station controls wrap at the first and last
station. All six functions matched on the first compile of this batch.

```text
OK  _ZN12SoundManager15playLowFpsMusicEib  0x00352ba9  20 bytes
OK  _ZN12SoundManager9playRadioEi  0x00352f21  44 bytes
OK  _ZN12SoundManager9stopRadioEv  0x00353389  46 bytes
OK  _ZN12SoundManager18changeRadioStationEi  0x003539dd  88 bytes
OK  _ZN12SoundManager16lastRadioStationEv  0x00353a35  32 bytes
OK  _ZN12SoundManager16nextRadioStationEv  0x00353a55  34 bytes
```
