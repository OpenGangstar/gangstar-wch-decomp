# Static sound and pool

StaticSound forwards its lifecycle and stop operations to CSound.
CStaticSoundsPool reuses the slot tracking pattern from the streaming
sound pool. The native profile compares the entire translation unit and
the generated vtable at their retail addresses.

```text
OK  _ZN17CStaticSoundsPoolD1Ev  0x00353b81  74 bytes
OK  _ZN17CStaticSoundsPoolD2Ev  0x00353b81  74 bytes
OK  _ZN11StaticSound4StopEi  0x00353bcd  12 bytes
OK  _ZN11StaticSound6UnInitEv  0x00353bd9  12 bytes
OK  _ZN17CStaticSoundsPool18ReleaseStaticSoundEP11StaticSound  0x00353be5  138 bytes
OK  _ZN11StaticSound4InitEP10CSoundData  0x00353c71  12 bytes
OK  _ZN11StaticSoundD0Ev  0x00353c7d  40 bytes
OK  _ZN11StaticSoundD2Ev  0x00353ca5  32 bytes
OK  _ZN11StaticSoundD1Ev  0x00353ca5  32 bytes
OK  _ZN11StaticSoundC2EP10CSoundData  0x00353cc5  36 bytes
OK  _ZN11StaticSoundC1EP10CSoundData  0x00353cc5  36 bytes
OK  _ZN11StaticSoundC2Ev  0x00353ce9  36 bytes
OK  _ZN11StaticSoundC1Ev  0x00353ce9  36 bytes
OK  _ZN17CStaticSoundsPool14GetStaticSoundEP10CSoundData  0x00353d0d  130 bytes
OK  _ZN17CStaticSoundsPoolC2Eii  0x00353d91  136 bytes
OK  _ZN17CStaticSoundsPoolC1Eii  0x00353d91  136 bytes
OK SECTION .static_sound_vtable  0x004ad868  48 bytes
```
