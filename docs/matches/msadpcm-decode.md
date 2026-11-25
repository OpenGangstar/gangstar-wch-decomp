# CSoundDecoderMSADPCM::Decode exact match

`CSoundDecoderMSADPCM::Decode(short*, int, bool)` matches all 652 retail bytes
at Thumb address `0x003514b9`, including relocations.

```text
OK  _ZN20CSoundDecoderMSADPCM6DecodeEPsib  0x003514b9  652 bytes
```

## Source form

`Decode` does the following:

1. It reads whole ADPCM blocks from the stream in buffer-sized chunks.
2. It decodes each block's nibbles into mono or interleaved stereo samples,
   reloading the block headers when a block ends.
3. It returns the number of decoded samples. When the stream ends it returns
   any leftover sample count, and optionally rewinds for looping.

Details that the retail bytes require:

- **Chunk loop.** The remaining-bytes and decoded-sample counters are updated
  right after the samples are computed, before the mono/stereo split. That
  leaves the chunk loop's latch empty, so tree-ch skips copying the loop
  header. Tree-sink then places both updates ahead of the chunk counter
  test, as retail does.
- **Stereo arms.** Both stereo arms store each nibble's sample and then
  advance the pointer, in two steps. This keeps retail's mid and right
  pointers in `r9` and `fp`. It also rematerialises the `& 15` mask before
  each decode call.
- **Sample count.** The stereo sample count is written inline as
  `samplesPerBlock * nb`. It stays a late compiler temporary, which gives
  retail's six spill slots.
- **The one documented hint.** The leftover-samples return keeps
  `__builtin_expect(rest != 0, 0)`.
  - Every path that returns `decoded` enters the return block directly, so
    GCC's early-return heuristic predicts both edges of the `rest` test.
    That gives 67% for `rest != 0` and the opposite branch direction to
    retail.
  - Without the hint the function differs in 3 bytes, the branch sense and
    the order of the two jump-only blocks after it. No hint-free spelling
    gives retail's edge prediction.
- **ADPCM decoder.** `AdpcmDecoder::DecodeAdpcm` is declared weak, as it is
  in retail (`STB_WEAK`), so it is called through the GOT.

No inline assembly, register constraint, flag change or output edit is used,
and no header change. The other 17 decoder-pool functions are unchanged.

## Verification

`python -B tools/build.py msadpcm-decoder-pool` passes. `__aeabi_idiv` is
bound at its PLT address. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,606 function, 5,697 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,605, 5,696 and 181.
