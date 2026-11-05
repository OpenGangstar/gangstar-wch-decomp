OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-streamingsound/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_Znwj = 0x001c4814;
_Znaj = 0x001c3ff8;
_ZdaPv = 0x001c461c;
__aeabi_idivmod = 0x001c4934;
memset = 0x001c45d4;
__stack_chk_fail = 0x001c42e0;
__aeabi_idiv = 0x001c43dc;
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
    .streaming_playback_0 0x00353f28 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound4PlayEbfi) }
    .streaming_playback_1 0x00354094 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound6UnInitEv) }
    .streaming_playback_2 0x00354190 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSoundD0Ev) }
    .streaming_playback_3 0x00354214 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSoundD2Ev .text._ZN14StreamingSoundD1Ev) }
    .streaming_playback_4 0x00354290 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound5FlushEi) }
    .streaming_playback_5 0x003542c4 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound14UpdateDecodingEv) }
    .streaming_playback_6 0x00354310 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound21_SaturateAndFlushLiteEv) }
    .streaming_open_0 0x003543b8 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSoundC1EP10CSoundDatai .text._ZN14StreamingSoundC2EP10CSoundDatai) }
    .streaming_open_1 0x00354484 : { *sdk-startup-streamingsound.o(.text._ZN14StreamingSound4InitEP10CSoundData) }
    .streaming_vtable 0x004ad898 : { *sdk-startup-streamingsound.o(.data.rel.ro._ZTV14StreamingSound .gnu.linkonce.d.rel.ro._ZTV14StreamingSound) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
