# Sound buffer pool

The pool preallocates byte buffers and allocates additional buffers as
slots are acquired. Releasing a buffer marks its slot available again.
The destructor releases the buffers and both slot arrays.
StreamingSound uses the shared pool declaration.

```text
OK  _ZN13CSoundBuffers18ReleaseSoundBufferEPc  0x00352591  132 bytes
OK  _ZN13CSoundBuffers14GetSoundBufferEv  0x00352615  110 bytes
OK  _ZN13CSoundBuffersC2Eiii  0x00352685  130 bytes
OK  _ZN13CSoundBuffersC1Eiii  0x00352685  130 bytes
OK  _ZN13CSoundBuffersD1Ev  0x00352709  72 bytes
OK  _ZN13CSoundBuffersD2Ev  0x00352709  72 bytes
```
