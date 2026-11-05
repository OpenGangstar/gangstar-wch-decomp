OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
_Znaj = 0x001c3ff8;
_ZdaPv = 0x001c461c;
SECTIONS
{
    .sound_buffers_release 0x00352590 : { *sound-buffer-pool.o(.text._ZN13CSoundBuffers18ReleaseSoundBufferEPc) }
    .sound_buffers_acquire 0x00352614 : { *sound-buffer-pool.o(.text._ZN13CSoundBuffers14GetSoundBufferEv) }
    .sound_buffers_constructor 0x00352684 : { *sound-buffer-pool.o(.text._ZN13CSoundBuffersC2Eiii .text._ZN13CSoundBuffersC1Eiii) }
    .sound_buffers_destructor 0x00352708 : { *sound-buffer-pool.o(.text._ZN13CSoundBuffersD1Ev .text._ZN13CSoundBuffersD2Ev) }
}
