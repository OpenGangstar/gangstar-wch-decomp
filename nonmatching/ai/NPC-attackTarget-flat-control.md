# NPC::attackTarget: native extent, unmatched bytes

The accompanying method fragment preserves the reviewed flat control-flow
composition for Thumb `0x002ff5d1`, `_ZN3NPC12attackTargetEv`. It remains
**unmatched**. The assembly marker and matching statistics are unchanged.
The JSON records actual source/object/image hashes and the complete object and
linked verification summaries. This fragment was extracted from the tested
historical full translation unit; it has not been compiled independently or
accepted against the current canonical source tree.

## Reconstruction and measured result

The composition preserves acquisition, incapacitation and empty-driver event
full-expression boundaries in their source order, the corrected target-animation
receiver and retarget `else if`, and previously established scalar calculations.
One original GCC 4.2.1 frontend/assembler pair produced a 2108-byte function and
2108-byte input section, matching the retail extent. The frame is 84 bytes.
The three event homes match retail: incapacitation SP24, acquisition failure
SP40, and empty driver SP8. These facts do not establish byte identity.

All 71 other NPC functions, 94 off-target allocated payloads, definition/import
metadata and 359 off-target semantic relocations were preserved. One strict
native-address link then succeeded. The actual target still differs in **1935
bytes**; the first difference is at `+0x18`. Exact checker output:

```text
MISMATCH  _ZN3NPC12attackTargetEv  0x002ff5d1
  expected : d5 f7 54 fe 82 24 64 00 b5 4d 80 46 86 6b 38 59
  actual   : d5 f7 54 fe 82 24 64 00 a4 4d 3b 59 80 46 7d 44
  differs at 0x18
MISMATCH SECTION .owned_attack_target
  expected : d5 f7 54 fe 82 24 64 00 b5 4d 80 46 86 6b 38 59
  actual   : d5 f7 54 fe 82 24 64 00 a4 4d 3b 59 80 46 7d 44
  differs at 0x18
```

The two mismatch blocks above were separated by successful region checks in
the original log. All old NPC 71 functions/15 regions, saved Physics 38/11 and
saved Character 114/33 checks pass. Dependency objects were authenticated saved
objects, not freshly rebuilt. EvNPC D1/D0, its vtable, IEvent D1 and its vtable
are genuine allocated definitions and compare exactly; none is replaced by a
retail-address import. No primary emitted definition was overridden or discarded.
The established linker recipe still discards unused dependency remnants; it
does not place every dependency definition in this image.

The entire 18,836-byte GOT was also compared: **642 differing bytes**, all
within the existing reserved prefix. The global policy region after `+0x360`
passes exactly. A passing region is not a claim of complete GOT equality:

```text
OK REGION .got+0x360  0x004b03a8  17972 bytes
```

## Provenance and next investigation

Private evidence is retained under
`_scratch/worker-npc-attack-flat-control/`: `REPORT.md`, `LINKED-REPORT.md`,
`freeze.json`, actual compiler/assembler/link commands, `OBJECT-PROOF.json`,
`LINKED-PROOF.json`, `TARGET-DIFF.json`, complete GOT differences and checker log.
The fixture pins 1063 historical source/config/tool inputs. Use those paired
inputs and original flags to reproduce this result; transplanting this fragment
into another header context does not reproduce the recorded object by itself.
No game data, compiled objects or proprietary tools accompany the publication.

The first difference concerns PIC/load scheduling. Separately, early false
returns use R5 and a common R5-to-R0 transfer where retail writes R0 directly.
Two distinct user variables named `attacked` exist; register reuse alone does
not prove either merged with a compiler return temporary. The coordinator has
ran one unchanged-source, identity-gated tree/RTL diagnostic to locate the actual
declaration/coalescing decisions. It preserves all function/data payloads,
symbol/import metadata and 476 semantic relocation tuples. Only 14 object bytes
differ, in two anonymous metadata-name occurrences; an explicit correspondence
makes the complete objects equal in memory. No output was modified, and raw
whole-object identity is not claimed.

The diagnostic **refutes the direct FSelect analogy**. Original/gimple declares
`bool NPC::attackTarget()` and two bool user variables, but lowers their return
conversions through integer `D.14158`. The first two copyrename stages keep both
user variables separate. Pass 067 PRE creates an integer return-conversion PHI;
097 copyrename3 first merges the generated return carrier into that generated
PRE root:

```text
Try : D.14158_16(P16) & prephitmp.3181_589(P589) --> P589 prephitmp.3181
Coalesced D.14158_16 to prephitmp.3181_589
```

RTL expand retains generated root 110, rocket user 120 and ordinary user 122.
CSE removes the rocket intermediary copy; register allocation maps the generated
root to R5 and the ordinary user to R9. This explains the measured R5 return
carrier without claiming a tree merge into either bool user variable.

The known original NPC::Update caller ignores returned R0; it does not uniquely
establish bool versus int, and ordinary mangling omits return type. Observed
integer lowering does not justify changing the source signature. Neither this
trace nor the local register observation attributes all 1935 byte differences
to return handling. No source rewrite or matching credit follows.

Detailed original dump line evidence is retained in
`_scratch/worker-npc-attack-return-origin/RETURN-TRACE-REPORT.md` and
`RETURN-TRACE-EVIDENCE.json`; all 117 diagnostic dumps remain unchanged.
