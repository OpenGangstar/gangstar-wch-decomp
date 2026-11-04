OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/adpcm-stream/retail-symbols.ld
__cxa_pure_virtual = 0;
_ZdlPv = 0x001c42b0;
_Znaj = 0x001c3ff8;
_Znwj = 0x001c4814;
fopen = 0x001c45bc;
fread = 0x001c4598;
fclose = 0x001c4628;
fseek = 0x001c43f4;
SECTIONS
{
    .adpcm_stream_0 0x00350d8c : { *adpcm-stream.o(.text._ZN13ISoundDecoder22GetNumSamplesPerDecodeEi .gnu.linkonce.t._ZN13ISoundDecoder22GetNumSamplesPerDecodeEi) }
    .adpcm_stream_1 0x00350d90 : { *adpcm-stream.o(.text._ZNK13ISoundDecoder15GetSamplingRateEv .gnu.linkonce.t._ZNK13ISoundDecoder15GetSamplingRateEv) }
    .adpcm_stream_2 0x00350d98 : { *adpcm-stream.o(.text._ZNK13ISoundDecoder10GetChannelEv .gnu.linkonce.t._ZNK13ISoundDecoder10GetChannelEv) }
    .adpcm_stream_3 0x00350da0 : { *adpcm-stream.o(.text._ZNK13ISoundDecoder10GetPCMSizeEv .gnu.linkonce.t._ZNK13ISoundDecoder10GetPCMSizeEv) }
    .adpcm_stream_4 0x00350da8 : { *adpcm-stream.o(.text._ZNK13ISoundDecoder21GetNbEffectiveSamplesEv .gnu.linkonce.t._ZNK13ISoundDecoder21GetNbEffectiveSamplesEv) }
    .adpcm_stream_5 0x00350db0 : { *adpcm-stream.o(.text._ZNK13ISoundDecoder15GetTotalSamplesEv .gnu.linkonce.t._ZNK13ISoundDecoder15GetTotalSamplesEv) }
    .adpcm_stream_6 0x00350db8 : { *adpcm-stream.o(.text._ZNK13ISoundDecoder11HasMoreDataEv .gnu.linkonce.t._ZNK13ISoundDecoder11HasMoreDataEv) }
    .adpcm_stream_7 0x00350e34 : { *adpcm-stream.o(.text._ZN18CSoundDecoderADPCM4GoToEi) }
    .adpcm_stream_8 0x00350e60 : { *adpcm-stream.o(.text._ZN13ISoundDecoderD0Ev .gnu.linkonce.t._ZN13ISoundDecoderD0Ev) }
    .adpcm_stream_9 0x00350e80 : { *adpcm-stream.o(.text._ZN13ISoundDecoderD1Ev .gnu.linkonce.t._ZN13ISoundDecoderD1Ev .gnu.linkonce.t._ZN13ISoundDecoderD2Ev) }
    .adpcm_stream_10 0x00350e98 : { *adpcm-stream.o(.text._ZN18CSoundDecoderADPCM6DecodeEPsib) }
    .adpcm_stream_11 0x00350f70 : { *adpcm-stream.o(.text._ZN18CSoundDecoderADPCMC1EPKc .text._ZN18CSoundDecoderADPCMC2EPKc) }
    .adpcm_stream_12 0x00350fdc : { *adpcm-stream.o(.text._ZN18CSoundDecoderADPCMD0Ev) }
    .adpcm_stream_13 0x00351028 : { *adpcm-stream.o(.text._ZN18CSoundDecoderADPCMD1Ev .text._ZN18CSoundDecoderADPCMD2Ev) }
    .adpcm_base_vtable 0x004ad770 : { *adpcm-stream.o(.gnu.linkonce.d.rel.ro._ZTV13ISoundDecoder .data.rel.ro._ZTV13ISoundDecoder) }
    .adpcm_stream_vtable 0x004ad738 : { *adpcm-stream.o(.gnu.linkonce.d.rel.ro._ZTV18CSoundDecoderADPCM .data.rel.ro._ZTV18CSoundDecoderADPCM) }
    .adpcm_mode 0x004014f0 : { *adpcm-stream.o(.rodata.adpcm_read_mode) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
