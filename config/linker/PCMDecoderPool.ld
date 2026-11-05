OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/pcm-decoder-pool/retail-symbols.ld
__cxa_pure_virtual = 0;
_ZdlPv = 0x001c42b0;
_Znwj = 0x001c4814;
_Znaj = 0x001c3ff8;
_ZdaPv = 0x001c461c;
fread = 0x001c4598;
fseek = 0x001c43f4;
__aeabi_uidiv = 0x001c4604;
SECTIONS
{
    .pcm_method_0 0x00351cac : { *pcm-decoder-pool.o(.text._ZNK16CSoundDecoderPCM15GetSamplingRateEv) }
    .pcm_method_1 0x00351cb4 : { *pcm-decoder-pool.o(.text._ZNK16CSoundDecoderPCM10GetChannelEv) }
    .pcm_method_2 0x00351cbc : { *pcm-decoder-pool.o(.text._ZNK16CSoundDecoderPCM10GetPCMSizeEv) }
    .pcm_method_3 0x00351cc0 : { *pcm-decoder-pool.o(.text._ZNK16CSoundDecoderPCM21GetNbEffectiveSamplesEv) }
    .pcm_method_4 0x00351cd4 : { *pcm-decoder-pool.o(.text._ZNK16CSoundDecoderPCM15GetTotalSamplesEv) }
    .pcm_method_5 0x00351ce8 : { *pcm-decoder-pool.o(.text._ZNK16CSoundDecoderPCM11HasMoreDataEv) }
    .pcm_method_6 0x00351cfc : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCMC2Ev .text._ZN16CSoundDecoderPCMC1Ev) }
    .pcm_method_7 0x00351d28 : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCM6UnInitEv) }
    .pcm_method_8 0x00351d2c : { *pcm-decoder-pool.o(.text._ZN8CPcmPool17ReleasePCMDecoderEP16CSoundDecoderPCM) }
    .pcm_method_9 0x00351db8 : { *pcm-decoder-pool.o(.text._ZN8CPcmPoolD2Ev .text._ZN8CPcmPoolD1Ev) }
    .pcm_method_10 0x00351e04 : { *pcm-decoder-pool.o(.text._ZN8CPcmPoolC1Eii .text._ZN8CPcmPoolC2Eii) }
    .pcm_method_11 0x00351e8c : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCM4GoToEi) }
    .pcm_method_12 0x00351ea0 : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCM6DecodeEPsib) }
    .pcm_method_13 0x00351ef4 : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCM4InitEP7__sFILEP10RiffHeaderP12FormatHeader) }
    .pcm_method_14 0x00351f10 : { *pcm-decoder-pool.o(.text._ZN8CPcmPool13GetPCMDecoderEP7__sFILEP10RiffHeaderP12FormatHeader) }
    .pcm_method_15 0x00351fe8 : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCMD0Ev) }
    .pcm_method_16 0x00352014 : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCMD1Ev .text._ZN16CSoundDecoderPCMD2Ev) }
    .pcm_stream_constructor 0x00351fa8 : { *pcm-decoder-pool.o(.text._ZN16CSoundDecoderPCMC1EP7__sFILEP10RiffHeaderP12FormatHeader .text._ZN16CSoundDecoderPCMC2EP7__sFILEP10RiffHeaderP12FormatHeader) }
    .pcm_vtable 0x004ad818 : { *pcm-decoder-pool.o(.data.rel.ro._ZTV16CSoundDecoderPCM .gnu.linkonce.d.rel.ro._ZTV16CSoundDecoderPCM) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
