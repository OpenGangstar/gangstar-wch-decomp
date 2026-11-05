OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/msadpcm-decoder-pool/retail-symbols.ld
__cxa_pure_virtual = 0;
_ZdlPv = 0x001c42b0;
_Znwj = 0x001c4814;
_Znaj = 0x001c3ff8;
_ZdaPv = 0x001c461c;
fread = 0x001c4598;
fseek = 0x001c43f4;
__aeabi_uidiv = 0x001c4604;
__aeabi_uidivmod = 0x001c47c0;
SECTIONS
{
    .msadpcm_method_0 0x00351070 : { *msadpcm-decoder-pool.o(.text._ZNK20CSoundDecoderMSADPCM15GetSamplingRateEv) }
    .msadpcm_method_1 0x00351078 : { *msadpcm-decoder-pool.o(.text._ZNK20CSoundDecoderMSADPCM10GetChannelEv) }
    .msadpcm_method_2 0x00351080 : { *msadpcm-decoder-pool.o(.text._ZNK20CSoundDecoderMSADPCM10GetPCMSizeEv) }
    .msadpcm_method_3 0x00351084 : { *msadpcm-decoder-pool.o(.text._ZNK20CSoundDecoderMSADPCM11HasMoreDataEv) }
    .msadpcm_method_4 0x00351094 : { *msadpcm-decoder-pool.o(.text._ZNK20CSoundDecoderMSADPCM21GetNbEffectiveSamplesEv) }
    .msadpcm_method_5 0x00351098 : { *msadpcm-decoder-pool.o(.text._ZNK20CSoundDecoderMSADPCM15GetTotalSamplesEv) }
    .msadpcm_method_6 0x0035109c : { *msadpcm-decoder-pool.o(.text._ZN20CSoundDecoderMSADPCM6UnInitEv) }
    .msadpcm_method_7 0x003510a0 : { *msadpcm-decoder-pool.o(.text._ZN20CSoundDecoderMSADPCM22GetNumSamplesPerDecodeEi) }
    .msadpcm_method_8 0x003510c0 : { *msadpcm-decoder-pool.o(.text._ZN12CMSAdpcmPool21ReleaseMSADPCMDecoderEP20CSoundDecoderMSADPCM) }
    .msadpcm_method_9 0x0035114c : { *msadpcm-decoder-pool.o(.text._ZN12CMSAdpcmPoolD2Ev .text._ZN12CMSAdpcmPoolD1Ev) }
    .msadpcm_method_10 0x00351198 : { *msadpcm-decoder-pool.o(.text._ZN20CSoundDecoderMSADPCM4GoToEi) }
    .msadpcm_method_12 0x00351240 : { *msadpcm-decoder-pool.o(.text._ZN20CSoundDecoderMSADPCMC1Ev .text._ZN20CSoundDecoderMSADPCMC2Ev) }
    .msadpcm_method_13 0x003512b8 : { *msadpcm-decoder-pool.o(.text._ZN12CMSAdpcmPool17GetMSADPCMDecoderEP7__sFILEP10RiffHeaderP12FormatHeader) }
    .msadpcm_method_14 0x00351350 : { *msadpcm-decoder-pool.o(.text._ZN12CMSAdpcmPoolC1Eii .text._ZN12CMSAdpcmPoolC2Eii) }
    .msadpcm_method_15 0x00351744 : { *msadpcm-decoder-pool.o(.text._ZN20CSoundDecoderMSADPCMD0Ev) }
    .msadpcm_method_16 0x00351790 : { *msadpcm-decoder-pool.o(.text._ZN20CSoundDecoderMSADPCMD2Ev .text._ZN20CSoundDecoderMSADPCMD1Ev) }
    .msadpcm_vtable 0x004ad7a8 : { *msadpcm-decoder-pool.o(.data.rel.ro._ZTV20CSoundDecoderMSADPCM .gnu.linkonce.d.rel.ro._ZTV20CSoundDecoderMSADPCM) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
