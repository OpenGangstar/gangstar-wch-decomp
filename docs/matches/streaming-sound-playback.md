# Streaming sound playback

The data constructor allocates local stream buffers. Pool initialization
acquires shared buffers when configured. The playback methods decode
chunks into a rotating buffer, queue it, and release its resources.
The silence buffer in the lite path uses the native stack protector.
The comparison covers the remaining methods and generated vtable.

```text
OK  _ZN14StreamingSound4PlayEbfi  0x00353f29  78 bytes
OK  _ZN14StreamingSound6UnInitEv  0x00354095  112 bytes
OK  _ZN14StreamingSoundD0Ev  0x00354191  132 bytes
OK  _ZN14StreamingSoundD2Ev  0x00354215  124 bytes
OK  _ZN14StreamingSoundD1Ev  0x00354215  124 bytes
OK  _ZN14StreamingSound5FlushEi  0x00354291  50 bytes
OK  _ZN14StreamingSound14UpdateDecodingEv  0x003542c5  76 bytes
OK  _ZN14StreamingSound21_SaturateAndFlushLiteEv  0x00354311  168 bytes
OK  _ZN14StreamingSoundC1EP10CSoundDatai  0x003543b9  204 bytes
OK  _ZN14StreamingSoundC2EP10CSoundDatai  0x003543b9  204 bytes
OK  _ZN14StreamingSound4InitEP10CSoundData  0x00354485  184 bytes
OK SECTION .streaming_vtable  0x004ad898  48 bytes
```
