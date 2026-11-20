# SoundManager playing-count reconstruction: unmatched

The unapplied patch reconstructs `SoundManager::getNumberOfPlayingSounds()` at
Thumb `0x00352cad`, native 80 bytes. It has no branch hints, assembly, register
constraints, output edits or progress credit. Preserve the assembly marker.

The coordinator independently applied the final public patch to a fresh copy
of current source/configuration/tools and ran the ordinary owning build. It
exits **1**, honestly comparing both the complete function and its strict 80-byte
section. Only byte offsets `0x20` and `0x21` differ. Linked SHA-256 is
`112648002dbd6db60de290af5e082d9d65449dd076811ca53311628c54762de1`.

```text
MISMATCH  _ZN12SoundManager24getNumberOfPlayingSoundsEv  0x00352cad
  expected : 00 27 be 00 00 24 6b 6a 9b 59 18 59 00 28 05 d0
  actual   : 00 27 be 00 00 24 6b 6a f3 58 18 59 00 28 05 d0
  differs at 0x20
MISMATCH SECTION .sound_playing_count
  expected : 00 27 be 00 00 24 6b 6a 9b 59 18 59 00 28 05 d0
  actual   : 00 27 be 00 00 24 6b 6a f3 58 18 59 00 28 05 d0
  differs at 0x20
```

All 73 existing owner function checks and 80 region checks pass with the target
present. Independently rebuilt affected-header coverage requests 26 profiles,
builds 35 including dependencies, and passes 2,274 existing function checks and
2,210 region checks. The target alone is excluded from that preservation gate
and compared separately above; it is not counted as passing. All 890 frozen
source/configuration/tool inputs remain stable during the gate. The first log
counter incorrectly expected four spaces after OK; correcting that parser to
the actual two-space format recovered 2,274 without another build.

## Translation-unit and interface context

The patch retains all 70 accepted definition texts, including the matched
680-byte constructor and SDK/free callbacks, while placing definitions in native
address order. Include, declaration, global-data and static-initializer order
remain intact. The ordinary forward declaration of `soundEndCallback` is needed
when its actual definition follows its caller. An earlier private dispatch
failed at the frontend without it; no stale object was treated as a result.

The nonvirtual class-end count declaration adds no storage or vtable slot.
Adding that declaration exposed a four-byte instruction-order regression in
existing `MenuManager::updateWidgetVisibility()`. The coordinator corrected only
the ordering of its independent local initializations: initialize the loop index
before `allHidden`, then use that existing index in the unchanged loop. The
104-byte existing function and every affected check are exact again. This
existing-body compatibility change is part of the **unapplied patch only**;
canonical game sources and the Windows port are unchanged. Do not adopt these
prerequisites alone on the strength of an unmatched target.

## Compiler evidence and limits

One dump-only compilation of the exact unhinted input produced an identical
whole object (SHA-256
`23392e877801932b52d20885643158abbfe87e1a9f19e82e12b19faf9c9426b7`),
including all 74 emitted function payloads and 89 allocated sections. No relink
was needed for that diagnostic. In current GCC dumps, pass `089t.vrp2` propagates
copied index SSA67 to original index SSA1 and changes table SSA15 plus index to
index plus table. RTL expansion, combination, allocation and scheduling preserve
that operand order. The matched `isSoundPlaying` relative retains table SSA11
plus index SSA53.

[GCC 4.2.1 fold-const.c](https://github.com/gcc-mirror/gcc/blob/releases/gcc-4.2.1/gcc/fold-const.c#L6148-L6192)
contains an SSA-version canonicalization rule consistent with these observations.
The exact Android compiler internal call path was not instrumented; that causal
explanation remains an inference. Late register allocation is not the first
observed divergence. Three separately bounded branch-hint controls also failed:
80 bytes with the same mismatch, 82 bytes with a strict-link failure, and 78 bytes
with a mismatching full 80-byte section. None is included in this patch.

Apply only in a private checkout:

```sh
git apply --unidiff-zero nonmatching/audio/SoundManager-playing-count.patch
python tools/build.py sdk-startup-soundmanager
```

Configure the documented retail library and matching toolchain first. Expected
build exit is 1, not success. This patch deliberately preserves strict native
start/extent/successor assertions and includes target comparisons in the normal
profile. No compilation unit becomes fully linked, and no matching percentage
changes. Further source trials require new evidence or an explicitly bounded
escalation; the recorded negative is not a fresh six-attempt budget.
