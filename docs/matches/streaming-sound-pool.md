# Streaming sound pool

The streaming pool reuses the slot management pattern from the WAV
decoder pools. Its slots allocate five local buffers when there is no
shared buffer pool. The profile binds the base constructor and the
pending streaming Init and UnInit methods to their retail Thumb
addresses.

```text
OK  _ZN14StreamingSound20InitStaticParametersEP13CSoundBuffersP10CMSWavPool  0x00353e85  32 bytes
OK  _ZN14StreamingSound23SaturateBuffersAndFlushEv  0x00353ea5  2 bytes
OK  _ZN14StreamingSound6UpdateEi  0x00353ea9  2 bytes
OK  _ZN14CStreamingPoolD2Ev  0x00353edd  74 bytes
OK  _ZN14CStreamingPoolD1Ev  0x00353edd  74 bytes
OK  _ZN14StreamingSoundC1Ei  0x00353fa1  88 bytes
OK  _ZN14StreamingSoundC2Ei  0x00353fa1  88 bytes
OK  _ZN14CStreamingPoolC2Eii  0x00353ff9  156 bytes
OK  _ZN14CStreamingPoolC1Eii  0x00353ff9  156 bytes
OK  _ZN14CStreamingPool21ReleaseStreamingSoundEP14StreamingSound  0x00354105  138 bytes
OK  _ZN14CStreamingPool17GetStreamingSoundEP10CSoundData  0x0035453d  136 bytes
```
