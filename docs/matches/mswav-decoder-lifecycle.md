# MSWAV decoder lifecycle

The default constructor initializes the file pointer and WAV header fields.
The destructor closes an open file before the shared decoder base is
destroyed. Pool initialization stores both static pool pointers.

The initial profile used the default toolchain, which differed in Thumb
padding and GOT order. Selecting the ADPCM profile's toolchain matched
the complete functions and generated vtable.

```text
OK  _ZN18CSoundDecoderMSWAVC1Ev  0x00351835  68 bytes
OK  _ZN18CSoundDecoderMSWAVC2Ev  0x00351835  68 bytes
OK  _ZN18CSoundDecoderMSWAV20InitStaticParametersEP8CPcmPoolP12CMSAdpcmPool  0x00351879  32 bytes
OK  _ZN18CSoundDecoderMSWAVD0Ev  0x00351c39  60 bytes
OK  _ZN18CSoundDecoderMSWAVD1Ev  0x00351c75  56 bytes
OK  _ZN18CSoundDecoderMSWAVD2Ev  0x00351c75  56 bytes
OK SECTION .mswav_vtable  0x004ad7e0  56 bytes
```
