OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/mswav-decoder-interface/retail-symbols.ld
__cxa_pure_virtual = 0;
_ZdlPv = 0x001c42b0;
fclose = 0x001c4628;
_Znwj = 0x001c4814;
_Znaj = 0x001c3ff8;
_ZdaPv = 0x001c461c;
fopen = 0x001c45bc;
fread = 0x001c4598;
printf = 0x001c4058;
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
    .mswav_pool_0 0x003518c4 : { *mswav-decoder-interface.o(.text._ZN10CMSWavPoolD1Ev .text._ZN10CMSWavPoolD2Ev) }
    .mswav_pool_1 0x00351910 : { *mswav-decoder-interface.o(.text._ZN10CMSWavPoolC1Eii .text._ZN10CMSWavPoolC2Eii) }
    .mswav_pool_2 0x003519e0 : { *mswav-decoder-interface.o(.text._ZN10CMSWavPool19ReleaseMSWAVDecoderEP18CSoundDecoderMSWAV) }
    .mswav_pool_3 0x00351af4 : { *mswav-decoder-interface.o(.text._ZN10CMSWavPool15GetMSWAVDecoderEPKc) }
    .mswav_stream_0 0x00351998 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAV6UnInitEv) }
    .mswav_stream_1 0x00351a6c : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAV4InitEPKc) }
    .mswav_stream_2 0x00351b78 : { *mswav-decoder-interface.o(.text._ZN18CSoundDecoderMSWAVC1EPKc .text._ZN18CSoundDecoderMSWAVC2EPKc) }
    .mswav_read_mode 0x004014f0 : { *mswav-decoder-interface.o(.rodata.wav_read_mode) }
    .mswav_unknown_format 0x004362d8 : { *mswav-decoder-interface.o(.rodata.wav_unknown_format) }
    .mswav_vtable 0x004ad7e0 : { *mswav-decoder-interface.o(.data.rel.ro._ZTV18CSoundDecoderMSWAV .gnu.linkonce.d.rel.ro._ZTV18CSoundDecoderMSWAV) }
    .mswav_pcm_pool 0x004bc1cc (NOLOAD) : { *mswav-decoder-interface.o(.bss._ZN18CSoundDecoderMSWAV11s_msPcmPoolE) }
    .mswav_adpcm_pool 0x004bc1c8 (NOLOAD) : { *mswav-decoder-interface.o(.bss._ZN18CSoundDecoderMSWAV13s_msAdpcmPoolE) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
