OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-streamingsound/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_Znwj = 0x001c4814;
_Znaj = 0x001c3ff8;
_ZdaPv = 0x001c461c;
SECTIONS
{
    .sdk_startup_function_0 0x00353eac : { *sdk-startup-streamingsound.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x003545c4 : { *sdk-startup-streamingsound.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00354630 : { *sdk-startup-streamingsound.o(.text._GLOBAL__I__ZN14StreamingSound14s_pBuffersPoolE) }
    .sdk_startup_storage_0 0x004bc24c (NOLOAD) : { *sdk-startup-streamingsound.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc26c (NOLOAD) : { *sdk-startup-streamingsound.o(.bss._ZN3irr2ps5vHalfE) }
    .streaming_method_0 0x00353e84 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound20InitStaticParametersEP13CSoundBuffersP10CMSWavPool) }
    .streaming_method_1 0x00353ea4 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound23SaturateBuffersAndFlushEv) }
    .streaming_method_2 0x00353ea8 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound6UpdateEi) }
    .streaming_method_3 0x00353edc : { *sdk-startup-streamingsound.o(.text._ZN14CStreamingPoolD2Ev .text._ZN14CStreamingPoolD1Ev) }
    .streaming_method_4 0x00353fa0 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSoundC1Ei .text._ZN14StreamingSoundC2Ei) }
    .streaming_method_5 0x00353ff8 : { *sdk-startup-streamingsound.o(.text._ZN14CStreamingPoolC2Eii .text._ZN14CStreamingPoolC1Eii) }
    .streaming_method_6 0x00354104 : { *sdk-startup-streamingsound.o(.text._ZN14CStreamingPool21ReleaseStreamingSoundEP14StreamingSound) }
    .streaming_method_7 0x0035453c : { *sdk-startup-streamingsound.o(.text._ZN14CStreamingPool17GetStreamingSoundEP10CSoundData) }
    .streaming_buffers_pool 0x004bc244 (NOLOAD) : { *sdk-startup-streamingsound.o(.bss._ZN14StreamingSound14s_pBuffersPoolE) }
    .streaming_mswav_pool 0x004bc248 (NOLOAD) : { *sdk-startup-streamingsound.o(.bss._ZN14StreamingSound12s_pMsWavPoolE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
