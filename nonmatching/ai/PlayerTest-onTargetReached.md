# PlayerTest::onTargetReached: reproducible nine-byte near miss

This candidate is **not matched** and must not be credited. The patch is kept
outside production source, and the original assembly remains in the queue.

The baseline is `10d56a0b0a8405b0152523e531534ac728ec14c8` (PR #726).
The subsequent documentation-only commits do not change its source or build
configuration. Apply this patch only in an isolated checkout:

```powershell
git apply --check nonmatching/ai/PlayerTest-onTargetReached.patch
git apply nonmatching/ai/PlayerTest-onTargetReached.patch
$env:WCH_BASE_LIB = 'C:/path/to/your/libsanangeles.so'
python tools/build.py ai-startup-playertest
```

## Included changes

The patch reconstructs the 60-byte callback with the canonical `LevelObject*`
field, a genuine downcast to `Vehicle*`, the existing `unknown372` state field,
and the actual compiled `justStoleCar` implementation. It adds the missing
ordinary, nonvirtual callback declaration. No class size or virtual slot changes.

That declaration changed two independent null-initialization instructions in
the existing `NPC::equipWeapon` match. The coordinator's separate compatibility
edit reverses only the two pointer declarations, preserving behavior and
restoring all 208 native bytes in this context. Do not apply that edit alone
to the baseline: its original declaration order is already matched there.

The profile also adds authentic Thumb metadata for `Weapon::hide`, which is not
compiled in this profile's dependency closure. Its compiled definition in the
separate Weapon profile is not overridden. Without this metadata the candidate
incorrectly emitted BLX to the Thumb callee; the corrected BL matches native.
Native function and section selectors and a strict 60-byte assertion are added.
Compiler flags and generated tables remain unchanged; existing matching
selectors are retained.

## Verified result

The final private run passed all **342 existing function checks and 112 existing
section, region and GOT checks**, including the restored NPC match, with no
skips. Only the new callback and its section fail:

```text
MISMATCH  _ZN10PlayerTest15onTargetReachedEv  0x003017b1
  expected : 26 5b 00 c6 54 03 68 b8 24 05 1c 1b 6a 98 47 64
  actual   : 26 5b 00 c6 54 03 68 b8 25 04 1c 1b 6a 98 47 6d
  differs at 0xd
MISMATCH SECTION .player_on_target_reached
```

The candidate is exactly 60 bytes, with nine differences from native at offsets
`0x0d`, `0x0e`, `0x14`, `0x1a`, `0x1c`, `0x2a`, `0x2c`, `0x30`, and `0x34`.
These express the same register-role permutation: candidate `this` in r4 and
offset in r5, versus native `this` in r5 and offset in r4.

| Bytes | SHA-256 |
| --- | --- |
| Native | `9ff60c90e49855ff8d43d2d62b95a6521259aed1c1ee4819081111739f4ed27f` |
| Candidate | `0478bba3fe62e9e9dc38da4d792ff5a3a03c22b9384aa498997132e46fd7f2b0` |

The complete candidate reproduces the historical nine-byte near miss despite
the canonical types and real compiled caller boundary. Unchanged diagnostic
dumps first expose the physical allocation at `138r.greg`; they do not establish
the original local-allocation priority or justify register pins, barriers,
source-order permutations or optimization-flag sweeps.

Preserve this candidate until a concrete new hypothesis or separately bounded
escalation is assigned. A full affected-header gate was not run: the target
already fails, and no production header or function is being integrated.
