# MSWAV stream initialization

The filename constructor allocates a decoder for PCM or MSADPCM. Pool
initialization acquires that decoder from the corresponding pool, and
cleanup releases it before closing the stream. Both initialization paths
use a switch to reproduce the retail order of the format branches. The
profile also compares the file mode and diagnostic string.

```text
OK  _ZN18CSoundDecoderMSWAV6UnInitEv  0x00351999  72 bytes
OK  _ZN18CSoundDecoderMSWAV4InitEPKc  0x00351a6d  136 bytes
OK  _ZN18CSoundDecoderMSWAVC1EPKc  0x00351b79  192 bytes
OK  _ZN18CSoundDecoderMSWAVC2EPKc  0x00351b79  192 bytes
OK SECTION .mswav_read_mode  0x004014f0  4 bytes
OK SECTION .mswav_unknown_format  0x004362d8  80 bytes
```
