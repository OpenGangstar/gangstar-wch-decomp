# MSADPCM decoder and pool

The MSADPCM pool reuses the PCM pool's slot management. Both decoders
share the WAV format header. The profile resolves MSADPCM initialization
and decoding to retail Thumb addresses pending their own matches.
The first initialization candidate produced a 140-byte section for a
136-byte retail slot, including alignment padding.

```text
OK  _ZNK20CSoundDecoderMSADPCM15GetSamplingRateEv  0x00351071  6 bytes
OK  _ZNK20CSoundDecoderMSADPCM10GetChannelEv  0x00351079  6 bytes
OK  _ZNK20CSoundDecoderMSADPCM10GetPCMSizeEv  0x00351081  4 bytes
OK  _ZNK20CSoundDecoderMSADPCM11HasMoreDataEv  0x00351085  14 bytes
OK  _ZNK20CSoundDecoderMSADPCM21GetNbEffectiveSamplesEv  0x00351095  4 bytes
OK  _ZNK20CSoundDecoderMSADPCM15GetTotalSamplesEv  0x00351099  4 bytes
OK  _ZN20CSoundDecoderMSADPCM6UnInitEv  0x0035109d  2 bytes
OK  _ZN20CSoundDecoderMSADPCM22GetNumSamplesPerDecodeEi  0x003510a1  30 bytes
OK  _ZN12CMSAdpcmPool21ReleaseMSADPCMDecoderEP20CSoundDecoderMSADPCM  0x003510c1  138 bytes
OK  _ZN12CMSAdpcmPoolD2Ev  0x0035114d  74 bytes
OK  _ZN12CMSAdpcmPoolD1Ev  0x0035114d  74 bytes
OK  _ZN20CSoundDecoderMSADPCM4GoToEi  0x00351199  32 bytes
OK  _ZN20CSoundDecoderMSADPCMC1Ev  0x00351241  120 bytes
OK  _ZN20CSoundDecoderMSADPCMC2Ev  0x00351241  120 bytes
OK  _ZN12CMSAdpcmPool17GetMSADPCMDecoderEP7__sFILEP10RiffHeaderP12FormatHeader  0x003512b9  150 bytes
OK  _ZN12CMSAdpcmPoolC1Eii  0x00351351  136 bytes
OK  _ZN12CMSAdpcmPoolC2Eii  0x00351351  136 bytes
OK  _ZN20CSoundDecoderMSADPCMD0Ev  0x00351745  76 bytes
OK  _ZN20CSoundDecoderMSADPCMD2Ev  0x00351791  68 bytes
OK  _ZN20CSoundDecoderMSADPCMD1Ev  0x00351791  68 bytes
OK SECTION .msadpcm_vtable  0x004ad7a8  56 bytes
```
