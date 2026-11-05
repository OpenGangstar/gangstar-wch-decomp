OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/mswav-decoder-interface/retail-symbols.ld
__cxa_pure_virtual = 0;
_ZdlPv = 0x001c42b0;
fclose = 0x001c4628;
SECTIONS
{
    .mswav_method_0 0x003517d4 : { *mswav-decoder-interface.o(.text._ZNK18CSoundDecoderMSWAV15GetSamplingRateEv) }
    .mswav_method_1 0x003517e4 : { *mswav-decoder-interface.o(.text._ZNK18CSoundDecoderMSWAV10GetChannelEv) }
    .mswav_method_2 0x003517f4 : { *mswav-decoder-interface.o(.text._ZNK18CSoundDecoderMSWAV10GetPCMSizeEv) }
    .mswav_method_3 0x00351804 : { *mswav-decoder-interface.o(.text._ZNK18CSoundDecoderMSWAV21GetNbEffectiveSamplesEv) }
    .mswav_method_4 0x00351814 : { *mswav-decoder-interface.o(.text._ZNK18CSoundDecoderMSWAV15GetTotalSamplesEv) }
    .mswav_method_5 0x00351824 : { *mswav-decoder-interface.o(.text._ZNK18CSoundDecoderMSWAV11HasMoreDataEv) }
    .mswav_method_6 0x00351898 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAV6DecodeEPsib) }
    .mswav_method_7 0x003518a4 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAV4GoToEi) }
    .mswav_method_8 0x003518b4 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAV22GetNumSamplesPerDecodeEi) }
    .mswav_lifecycle_0 0x00351834 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAVC1Ev .text._ZN18CSoundDecoderMSWAVC2Ev) }
    .mswav_lifecycle_1 0x00351878 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAV20InitStaticParametersEP8CPcmPoolP12CMSAdpcmPool) }
    .mswav_lifecycle_2 0x00351c38 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAVD0Ev) }
    .mswav_lifecycle_3 0x00351c74 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAVD1Ev .text._ZN18CSoundDecoderMSWAVD2Ev) }
    .mswav_vtable 0x004ad7e0 : { *mswav-decoder-interface.o(.data.rel.ro._ZTV18CSoundDecoderMSWAV .gnu.linkonce.d.rel.ro._ZTV18CSoundDecoderMSWAV) }
    .mswav_pcm_pool 0x004bc1cc (NOLOAD) : { *mswav-decoder-interface.o(.bss._ZN18CSoundDecoderMSWAV11s_msPcmPoolE) }
    .mswav_adpcm_pool 0x004bc1c8 (NOLOAD) : { *mswav-decoder-interface.o(.bss._ZN18CSoundDecoderMSWAV13s_msAdpcmPoolE) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
