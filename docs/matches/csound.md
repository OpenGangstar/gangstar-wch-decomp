# CSound

The retail constructors establish the data pointer, status and fade fields.
The Android build leaves the OpenAL playback hooks empty. The absolute
volume method multiplies the sound volume by the manager's SFX volume
and scales it by the remaining fade time when a fade is active.

All pending symbols in CSound.cpp matched on the first compile, including
the constructor and destructor aliases and the ALSourcesPool stubs. The
generated vtable matched separately.

```text
OK  _ZN6CSoundC2Ev  0x00350885  24 bytes
OK  _ZN6CSoundC1Ev  0x00350885  24 bytes
OK  _ZN6CSoundC2EP10CSoundData  0x0035089d  52 bytes
OK  _ZN6CSoundC1EP10CSoundData  0x0035089d  52 bytes
OK  _ZN6CSound4InitEP10CSoundData  0x003508d1  2 bytes
OK  _ZN6CSound12InitALSourceEv  0x003508d5  2 bytes
OK  _ZN6CSound20InitStaticParametersEP13ALSourcesPool  0x003508d9  20 bytes
OK  _ZN6CSound6UnInitEv  0x003508ed  2 bytes
OK  _ZNK6CSound9GetStatusEv  0x003508f1  4 bytes
OK  _ZN6CSound4PlayEbfi  0x003508f5  2 bytes
OK  _ZN6CSound4StopEi  0x003508f9  2 bytes
OK  _ZN6CSound5PauseEv  0x003508fd  2 bytes
OK  _ZN6CSound6ResumeEv  0x00350901  2 bytes
OK  _ZN6CSound11SetPositionERKN3irr4core8vector3dIfEE  0x00350905  2 bytes
OK  _ZN6CSound6UpdateEi  0x00350909  2 bytes
OK  _ZN6CSound12_performFadeEi  0x0035090d  2 bytes
OK  _ZN6CSound17QueueStreamBufferEPcii  0x00350911  2 bytes
OK  _ZN6CSound18GetProcessedBufferEv  0x00350915  4 bytes
OK  _ZN6CSound9SetVolumeEf  0x00350919  2 bytes
OK  _ZN6CSound8SetPitchEf  0x0035091d  2 bytes
OK  _ZN6CSound12GetSoundDataEv  0x00350921  4 bytes
OK  _ZN13ALSourcesPoolC1Eii  0x00350925  2 bytes
OK  _ZN13ALSourcesPoolC2Eii  0x00350925  2 bytes
OK  _ZN13ALSourcesPoolD2Ev  0x00350929  2 bytes
OK  _ZN13ALSourcesPoolD1Ev  0x00350929  2 bytes
OK  _ZN6CSoundD0Ev  0x0035095d  32 bytes
OK  _ZN6CSoundD2Ev  0x0035097d  24 bytes
OK  _ZN6CSoundD1Ev  0x0035097d  24 bytes
OK  _ZNK6CSound17GetAbsoluteVolumeEv  0x00350995  80 bytes
OK SECTION .csound_vtable  0x004ad6f8  48 bytes
```
