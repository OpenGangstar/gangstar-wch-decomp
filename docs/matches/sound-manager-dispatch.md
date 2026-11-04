# SoundManager playback dispatch

The pitch and position setters use the existing resource ID conversion and
dispatch through the matched CSound vtable. The native playback wrapper
chooses a gain from the sound type flag and the manager's volume fields.
The coordinate conversion scales the vector by 0.01 through the retail
weak Irrlicht operator.

```text
OK  _ZN12SoundManager8setPitchEiif  0x00352921  44 bytes
OK  _ZN12SoundManager12setSourcePosEiiRKN3irr4core8vector3dIfEE  0x0035294d  44 bytes
OK  _ZN12SoundManager6playExEiPKN3irr4core8vector3dIfEEbfibfPFvvE  0x00352b69  62 bytes
OK  _ZN12SoundManager24convertVisual3DToSound3DERKN3irr4core8vector3dIfEE  0x00352b41  40 bytes
```
