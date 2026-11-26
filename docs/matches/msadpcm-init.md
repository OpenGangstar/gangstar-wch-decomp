# CSoundDecoderMSADPCM::Init exact match

`CSoundDecoderMSADPCM::Init(__sFILE*, RiffHeader*, FormatHeader*)` matches
all 134 retail bytes at Thumb address `0x003511b9`, including relocations.

```text
OK  _ZN20CSoundDecoderMSADPCM4InitEP7__sFILEP10RiffHeaderP12FormatHeader  0x003511b9  134 bytes
```

## Source form

`Init` stores the stream and headers, resets the decoder state, skips any
extra format bytes, reads the fact and data chunk headers, and computes the
block header size, samples per block and decoded size.

Details that the retail bytes require:

- **Format reads.** The extra format size is held in a local for the
  compare and the seek, and the fields read after the chunk headers go
  through the stored `formatHeader`. That gives retail's copy of the format
  pointer into r1.
- **Store order.** `channelIndex` is reset before `flags` is set. The longer
  lifetime of the zero constant lets the constant 84 take r3 in local
  register allocation, as retail does; scheduling keeps retail's store
  order.

No branch hint, inline assembly, register constraint, output edit or header
change is used. `Decode` and the other functions in the file keep their
bytes.

## Verification

`python -B tools/build.py msadpcm-decoder-pool` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,619 function, 5,709 section
and 180 region comparisons and no mismatch or skip; the previous baseline
was 5,618, 5,709 and 180.
