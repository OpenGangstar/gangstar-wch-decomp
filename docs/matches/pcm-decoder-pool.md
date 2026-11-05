# PCM decoder and pool

The PCM pool reuses the MSWAV pool's slot management. PCM decoding reads
whole sample blocks from the data chunk and resets the stream to the data
offset when looping. The comparison covers the complete translation unit
and the generated PCM vtable.

```text
OK  _ZNK16CSoundDecoderPCM15GetSamplingRateEv  0x00351cad  6 bytes
OK  _ZNK16CSoundDecoderPCM10GetChannelEv  0x00351cb5  6 bytes
OK  _ZNK16CSoundDecoderPCM10GetPCMSizeEv  0x00351cbd  4 bytes
OK  _ZNK16CSoundDecoderPCM21GetNbEffectiveSamplesEv  0x00351cc1  18 bytes
OK  _ZNK16CSoundDecoderPCM15GetTotalSamplesEv  0x00351cd5  18 bytes
OK  _ZNK16CSoundDecoderPCM11HasMoreDataEv  0x00351ce9  18 bytes
OK  _ZN16CSoundDecoderPCMC2Ev  0x00351cfd  44 bytes
OK  _ZN16CSoundDecoderPCMC1Ev  0x00351cfd  44 bytes
OK  _ZN16CSoundDecoderPCM6UnInitEv  0x00351d29  2 bytes
OK  _ZN8CPcmPool17ReleasePCMDecoderEP16CSoundDecoderPCM  0x00351d2d  138 bytes
OK  _ZN8CPcmPoolD2Ev  0x00351db9  74 bytes
OK  _ZN8CPcmPoolD1Ev  0x00351db9  74 bytes
OK  _ZN8CPcmPoolC1Eii  0x00351e05  136 bytes
OK  _ZN8CPcmPoolC2Eii  0x00351e05  136 bytes
OK  _ZN16CSoundDecoderPCM4GoToEi  0x00351e8d  20 bytes
OK  _ZN16CSoundDecoderPCM6DecodeEPsib  0x00351ea1  84 bytes
OK  _ZN16CSoundDecoderPCM4InitEP7__sFILEP10RiffHeaderP12FormatHeader  0x00351ef5  28 bytes
OK  _ZN8CPcmPool13GetPCMDecoderEP7__sFILEP10RiffHeaderP12FormatHeader  0x00351f11  150 bytes
OK  _ZN16CSoundDecoderPCMD0Ev  0x00351fe9  44 bytes
OK  _ZN16CSoundDecoderPCMD1Ev  0x00352015  36 bytes
OK  _ZN16CSoundDecoderPCMD2Ev  0x00352015  36 bytes
OK  _ZN16CSoundDecoderPCMC1EP7__sFILEP10RiffHeaderP12FormatHeader  0x00351fa9  64 bytes
OK  _ZN16CSoundDecoderPCMC2EP7__sFILEP10RiffHeaderP12FormatHeader  0x00351fa9  64 bytes
OK SECTION .pcm_vtable  0x004ad818  56 bytes
```
