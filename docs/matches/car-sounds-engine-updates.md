# CarSounds on/off engine sound updates exact match

`CarSounds::UpdateOnEngineSounds()` and `CarSounds::UpdateOffEngineSounds()`
match all retail bytes, including relocations.

```text
OK  _ZN9CarSounds20UpdateOnEngineSoundsEv  0x0034f785  544 bytes
OK  _ZN9CarSounds21UpdateOffEngineSoundsEv  0x0034f555  560 bytes
```

## Source form

The two functions share one body over their own fade, count, ID, channel,
gain and RPM-table members.

1. When a fade-out ends, every channel stops. When a cross-fade starts, the set
   becomes active.
2. The gain is computed, scaled by the fade volume while a fade runs.
3. For each engine sample, it is stopped outside its margin-widened RPM band.
   Otherwise its pitch and its piecewise-linear volume are updated, or it is
   started on a new channel.

`CarSoundCallbacks.h` names the members the bodies use. These were previously
opaque `unsigned char[4]` fields, and the layout is unchanged:

| Offset | Type | Name |
|---|---|---|
| +16 | `int` | `rpmMargin` |
| +84 | `float` | `onEngineGain` |
| +104 | `int` | `onEngineActive` |
| +120 | `float` | `offEngineGain` |
| +140 | `int` | `offEngineActive` |

### Comparison operand order

An earlier reconstruction differed in two bytes per function: the operand
order of the `rpm < upper` comparison. GCC 4.2.1 orders commutative and
comparison operands by SSA version. Jump threading in `dom1` creates the RPM
PHI using the most recently freed SSA name. When `dce` frees more dead copies
above `upper`, the PHI ends up after it.

The matching form avoids those dead copies:

- an `engineRpm` local assigned inside the band tests;
- an if/else for the next lower bound instead of a ternary;
- a `margin` local for the repeated margin load;
- a `lowers` pointer for the lower-bound table, which is indexed twice.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py car-sound-callbacks` passes every function and section
check of the unit. `UpdateTurboSounds` remains unmatched and is still bound
externally.

A fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,574
function, 5,657 section and 181 region comparisons and no mismatch or skip; the
previous baseline was 5,571, 5,654 and 181.
