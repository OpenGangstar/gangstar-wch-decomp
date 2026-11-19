# Physics constructor prerequisites

These changes preserve existing matches and make the PhysicAttributes
constructor reproducible with genuine current types. The constructor remains
unmatched; its assembly files remain in the queue. No progress credit is added.

## PhysicInfo linkage

The existing 96-byte PhysicInfo constructor is moved unchanged into its class
definition. Ordinary C++ inline emission supplies the native weak binding;
`used` retains the definition for complete comparison. The previous manually
weak out-of-line declaration caused GCC 4.2.1 to emit the invalid directive
`.weak _ZN10PhysicInfoC1Ev *INTERNAL*` when the pending array construction
used it. No compiler output is edited to bypass that failure.

The owning and Character verification images place the actual emitted
`.gnu.linkonce.t` constructor section at native Thumb `0x00319dd1`, with a
strict 96-byte section assertion and complete byte checks. These are compiled
definitions, not absolute retail substitutes. Native C1 is weak; native C2 is
absent from both symbol tables, so generated C2 receives no separate credit.

## Observed storage

PhysicAttributes remains 120 bytes, aligned to four bytes on the target ABI.
Its path remains a 20-byte array. A local initialization view supplies the six
observed defaults without adding a constructor to the shared generic array:
null data, zero allocated/used counts, both flags true, and strategy word one.
The body pointer view occupies offset 4; the zeroed tail word occupies 116.

The five contiguous 12-byte vectors occupy offsets 52 through 111. Slots 0
through 3 hold corners, and slot 4 holds their computed center at offset 100.
This models the native constructor's five-element initialization loop. The
former four-element array followed by a separate center generated three extra
stores, six instruction bytes and two alignment bytes. Existing
SetCurrentJumpShape changes only its final destination spelling to slot 4;
its arithmetic, calls and full 644-byte implementation remain native-exact.

## Integrated verification

The final integrated `python tools/build.py --all` passed all 190 profiles:
5,305 function checks, 5,204 section checks and 181 region checks, or 10,690
comparisons. No profile failed or was skipped. The three additional checks
cover real constructor emission in the existing graphs; they are not three
newly decompiled functions. Compiler flags remain unchanged.

```text
OK  _ZN10PhysicInfoC1Ev  0x00319dd1  96 bytes
OK  _ZN16PhysicAttributes19SetCurrentJumpShapeEP7b2Shape  0x0031ccf1  644 bytes
```

Independent executable extraction confirms the constructor in both images has
SHA256 `23b0631ac9bdcfd80637003bdfaa3f7c85b63c68abd410e8891afb1c17862f64`.
SetCurrentJumpShape has SHA256
`4cd65eae54251e905a9f372ce829ade66f1606271c9198e1fb0193ac5916f311`.

## Remaining mismatch

One private replay of the original constructor algorithm now compiles and
links at native Thumb `0x0031b29d` with the exact 260-byte extent. Its output is
byte-identical to the historical standalone candidate; six bytes still differ
at offsets `0x7f`, `0x80`, `0x84`, `0x86`, `0x88` and `0x8a`. The difference
concerns scratch-register allocation and store scheduling after allocation.
All 47 existing owning checks pass in that private trial. This does not accept
the constructor or authorize further store-order searches.

The candidate SHA256 is
`9f94beba336ee71c1d4b54ec0ad07b576d7d6868b5a9c8b5cf8201fa67e5b39c`;
native is `466dca64bb80d6f1a2340e096e5ffd2e2e381d9823ad9371ee393f7127642aa9`.
Matched, fuzzy and fully linked totals remain unchanged.
