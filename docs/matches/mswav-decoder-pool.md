# MSWAV decoder pool

The pool reuses the allocation and slot tracking pattern from CSoundDataPool.
The match profile resolves the decoder initialization and cleanup calls to
their retail Thumb addresses while those methods await C++ matches.

```text
OK  _ZN10CMSWavPoolD1Ev  0x003518c5  74 bytes
OK  _ZN10CMSWavPoolD2Ev  0x003518c5  74 bytes
OK  _ZN10CMSWavPoolC1Eii  0x00351911  136 bytes
OK  _ZN10CMSWavPoolC2Eii  0x00351911  136 bytes
OK  _ZN10CMSWavPool19ReleaseMSWAVDecoderEP18CSoundDecoderMSWAV  0x003519e1  138 bytes
OK  _ZN10CMSWavPool15GetMSWAVDecoderEPKc  0x00351af5  130 bytes
```
