# MSWAV decoder interface

The MSWAV methods forward through the underlying decoder's virtual interface.
The ADPCM decoder and the MSWAV wrapper share the recovered ISoundDecoder
declaration.

```text
OK  _ZNK18CSoundDecoderMSWAV15GetSamplingRateEv  0x003517d5  16 bytes
OK  _ZNK18CSoundDecoderMSWAV10GetChannelEv  0x003517e5  16 bytes
OK  _ZNK18CSoundDecoderMSWAV10GetPCMSizeEv  0x003517f5  16 bytes
OK  _ZNK18CSoundDecoderMSWAV21GetNbEffectiveSamplesEv  0x00351805  16 bytes
OK  _ZNK18CSoundDecoderMSWAV15GetTotalSamplesEv  0x00351815  16 bytes
OK  _ZNK18CSoundDecoderMSWAV11HasMoreDataEv  0x00351825  16 bytes
OK  _ZN18CSoundDecoderMSWAV6DecodeEPsib  0x00351899  12 bytes
OK  _ZN18CSoundDecoderMSWAV4GoToEi  0x003518a5  16 bytes
OK  _ZN18CSoundDecoderMSWAV22GetNumSamplesPerDecodeEi  0x003518b5  16 bytes
```
