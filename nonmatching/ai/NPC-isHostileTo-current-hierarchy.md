# NPC hostility: current hierarchy replay

This unapplied patch reconstructs `NPC::isHostileTo(LevelObject*)`, native
Thumb address `0x002fe0e9`, in the existing `ai-startup-npc` verification
profile. It remains unmatched: 120 compiled bytes versus 128 native bytes.
The assembly marker remains present and no progress is credited.

The earlier six-form pass used an obsolete interface cast when comparing
against `PlayerTest::GetPlayer()`. The current production inheritance tree
supplies concrete evidence for an ordinary `static_cast<LevelObject*>`.
One bounded replay with that correction produces exactly the earlier best
120-byte function. Its complete linked SHA-256 is
`309b9a6e522660faa17314e9f433e6634dcb977156b18afd76d4d73ebc1e7778`.

The canonical build exits 1. Exact function comparison output:

```text
MISMATCH  _ZN3NPC11isHostileToEP11LevelObject  0x002fe0e9
  expected : 70 b5 b2 23 5b 00 1c 4d c3 58 06 1c 7d 44
  actual   : 70 b5 b2 23 5b 00 1a 4d c3 58 06 1c 7d 44
  differs at 0x6
```

The complete new section also fails. All 71 existing owning-profile
functions and 15 existing sections/regions pass, including its global GOT;
dependency profiles pass. The 884 private input files remained stable.
The coordinator independently loaded the actual image, checked its complete
function hash and repeated the native function comparison.

There are 39 differing positions in the overlapping bytes and eight missing
bytes. The native final faction comparisons explicitly zero-extend a byte
temporary; this candidate canonicalizes Boolean returns differently. The
ordinary inheritance conversion reproduces the native null-preserving
pointer adjustment but does not resolve that tail. No padding, return-type
guess, or additional exhausted source grid is accepted.

For reproduction, apply the adjacent patch in an isolated checkout, then run
the normal `python tools/build.py ai-startup-npc --baselib <retail-library>`
command with the original configured toolchain available. The patch includes
the source declaration, native placement, manifest selection and required
external Thumb bindings. The adjacent JSON records exact result offsets and
the failed comparison. This is a retained candidate, not production code.
