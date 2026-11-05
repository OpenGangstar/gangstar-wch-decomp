OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
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
}
