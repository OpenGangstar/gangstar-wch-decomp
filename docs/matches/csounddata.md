# CSoundData and its pool

CSoundData uses the same constructor and destructor patterns as CSound.
The pool tracks unallocated, free and occupied slots separately. Acquisition
allocates a sample object when needed and advances the free-slot index.
Release clears the slot state and walks back the last occupied index.

The first pool constructor exceeded its retail section by four bytes.
Starting the second loop at the requested preallocation count matched
both constructor aliases. The final build matched every pending symbol
in this translation unit and the generated vtable.

```text
OK  _ZN10CSoundDataC1Ev  0x00350a65  28 bytes
OK  _ZN10CSoundDataC2Ev  0x00350a65  28 bytes
OK  _ZN10CSoundDataC1EiiiiPcib  0x00350a81  44 bytes
OK  _ZN10CSoundDataC2EiiiiPcib  0x00350a81  44 bytes
OK  _ZN10CSoundData4InitEiiiiPci  0x00350aad  2 bytes
OK  _ZN10CSoundData6UnInitEv  0x00350ab1  2 bytes
OK  _ZN10CSoundDataD0Ev  0x00350b71  32 bytes
OK  _ZN10CSoundDataD2Ev  0x00350b91  24 bytes
OK  _ZN10CSoundDataD1Ev  0x00350b91  24 bytes
OK  _ZN14CSoundDataPool16ReleaseSoundDataEP10CSoundData  0x00350ab5  138 bytes
OK  _ZN14CSoundDataPool12GetSoundDataEiiiiPci  0x00350ba9  162 bytes
OK  _ZN14CSoundDataPoolD1Ev  0x00350c4d  74 bytes
OK  _ZN14CSoundDataPoolD2Ev  0x00350c4d  74 bytes
OK  _ZN14CSoundDataPoolC1Eii  0x00350c99  136 bytes
OK  _ZN14CSoundDataPoolC2Eii  0x00350c99  136 bytes
OK SECTION .csounddata_vtable  0x004ad728  16 bytes
```
