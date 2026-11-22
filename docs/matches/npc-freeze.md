# NPC::freeze

`NPC::freeze()` (`_ZN3NPC6freezeEv`, Thumb `0x002fe999`) matches all
224 retail bytes. Its complete linked section occupies `0x002fe998` through
`0x002fea77`, ending immediately before the next retail function.

The reconstruction preserves the dead-character guard, movement-state update,
optional turn toward the current target, animation, random voice selection and
SoundManager playback flag lifetime. The private `MovementFlags` view names the
previously unnamed frozen bit at position four. Storage remains four bytes;
all existing named bit positions and previously matched function bodies remain
unchanged. No shared header or native Windows port code changes are needed.

## Reusing independently matching source

Two archived source variants each matched a different voice-selection branch.
The older v2 implementation had an exact second branch but three differing
bytes in the first; v4/v5 had an exact first branch but three differing bytes in
the second. Combining their independently verified readable source expressions
produced the complete match:

```cpp
case 0: soundId = 88; if (!driverBehavior) soundId = 86; break;
case 1: soundId = 76; if (!driverBehavior) soundId = 73; break;
```

This was one bounded source-only experiment, using the unchanged established
compiler profile. No instruction bytes were combined or modified. The earlier
GNU branch hint remains rejected; the accepted function uses no hints, inline
assembly, register constraints, barriers, output edits or custom padding.

## Verification

The canonical primary build, `python tools/build.py ai-startup-npc`, prints:

```text
OK  _ZN3NPC6freezeEv  0x002fe999  224 bytes
OK SECTION .npc_freeze  0x002fe998  224 bytes
```

That run passes 224 function, 57 section and three region comparisons, including
all previously selected owner and dependency checks. The resolved 224-byte
function payload has SHA256
`b045bf9d703168fc5ef8b42a591b86a0ae3251321a6c817dc942e8c266459091`.

The shared NPC section fragment routes the actual compiled function in both
NPC and PlayerTest verification images. Each parent linker script asserts the
224-byte extent and exact next-function boundary. An initial attempt placed
these assertions in the included fragment; the legacy linker rejected that
syntax. Moving assertions into both parent scripts resolved the build failure.
No compiler flags, source behavior or native placement checks were relaxed.

A fresh `tools.build.build_units` run covering all 191 configured ARM profiles
passed 5,456 function, 5,477 section and 181 region comparisons: 11,114 total.
All 1,102 frozen inputs remained unchanged, with canonical build inputs identical
to the tested snapshot. Every old function/section selector and compiler profile
was retained. The eight existing GS loader routing and preservation guards also
passed. An independent coordinator audit checked the exact function and whole
section in both actual linked NPC-containing images, then confirmed direct
successful comparisons for all 4,286 previously matched catalogue entries.

The private source-control audit additionally retained all 71 old NPC raw
function payloads, 95 allocated sections except the intended target text and
60 semantic relocation sections. One generated anonymous `photographedFlag`
name hash differed between compiler runs; only that exact identity pair was
normalized in the read-only audit, with its four-byte contents, binding and
relocation meaning unchanged. Neither object nor linked image was altered.

After this proof, only this function's assembly marker was removed. Regenerated
tables retain all 17,703 original identities and change exactly one status from
pending to matched. Progress becomes 4,287/4,550 functions and
353,318/561,716 bytes (62.90%). NPC remains incomplete, so Fully Linked stays
114,548 bytes (20.39%, 126/203 units). Fuzzy Matched remains the independently
reported exact matched-code percentage, 62.90%; no approximate credit is added.

The historical nonmatching packet remains available as superseded evidence.
