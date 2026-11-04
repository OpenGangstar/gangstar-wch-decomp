# ADPCM stream decoder

The stream decoder reads the initial ADPCM state and decodes the low and
high nibbles of each byte using the recovered ADPCM routine. It writes
each decoded sample to both stereo channels. A short read with looping
enabled rewinds the stream to the end of the 40-byte header.

The explicit output pointer increments reproduced the retail loop with
the existing short return type. The derived destructors matched after
inlining the base destructor and placing its weak linkonce sections at
the retail addresses. The symbol audit identified seven weak interface methods;
inline definitions reproduced their linkage. Both generated vtables also
compare exactly.

```text
OK  _ZN13ISoundDecoder22GetNumSamplesPerDecodeEi  0x00350d8d  4 bytes
OK  _ZNK13ISoundDecoder15GetSamplingRateEv  0x00350d91  6 bytes
OK  _ZNK13ISoundDecoder10GetChannelEv  0x00350d99  6 bytes
OK  _ZNK13ISoundDecoder10GetPCMSizeEv  0x00350da1  6 bytes
OK  _ZNK13ISoundDecoder21GetNbEffectiveSamplesEv  0x00350da9  6 bytes
OK  _ZNK13ISoundDecoder15GetTotalSamplesEv  0x00350db1  6 bytes
OK  _ZNK13ISoundDecoder11HasMoreDataEv  0x00350db9  4 bytes
OK  _ZN18CSoundDecoderADPCM4GoToEi  0x00350e35  42 bytes
OK  _ZN13ISoundDecoderD0Ev  0x00350e61  32 bytes
OK  _ZN13ISoundDecoderD1Ev  0x00350e81  24 bytes
OK  _ZN18CSoundDecoderADPCM6DecodeEPsib  0x00350e99  216 bytes
OK  _ZN18CSoundDecoderADPCMC1EPKc  0x00350f71  108 bytes
OK  _ZN18CSoundDecoderADPCMC2EPKc  0x00350f71  108 bytes
OK  _ZN18CSoundDecoderADPCMD0Ev  0x00350fdd  76 bytes
OK  _ZN18CSoundDecoderADPCMD1Ev  0x00351029  72 bytes
OK  _ZN18CSoundDecoderADPCMD2Ev  0x00351029  72 bytes
OK SECTION .adpcm_base_vtable  0x004ad770  56 bytes
OK SECTION .adpcm_stream_vtable  0x004ad738  56 bytes
```
