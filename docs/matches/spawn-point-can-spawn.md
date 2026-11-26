# SpawnPoint::canSpawn exact match

`SpawnPoint::canSpawn() const` matches all 816 retail bytes at Thumb address
`0x00307451`, including relocations.

```text
OK  _ZNK10SpawnPoint8canSpawnEv  0x00307451  816 bytes
```

## Source form

The function decides whether the spawn point may spawn: the player must be
inside the spawn ring and facing away from it, and for spawn constants of
type 3 or 11 the point must have no close neighbours and, for type 3, a
clear traffic lane.

Details that the retail bytes require:

- **Type test order.** The type is copied into an `int` local once. A
  documented `__builtin_expect(type == 11, 0)` test comes first, and a
  one-case switch on 3 handles the rest. This gives retail's `cmp #11`
  then `cmp #3` order and block layout. A two-value switch always emits the
  smaller value first.
- **Block frequency and the frame.** local-alloc ranks quantities by an
  integer-truncated `refs * freq / life` priority. A nested-switch form
  raised the body's frequency enough to change the ties, which spilled two
  more values and grew the frame by 8 bytes; the form above keeps retail's
  frequency and its 92-byte frame.
- **Earlier forms kept.** An inline `spawnFacing` helper (vector
  temporary order), an `alignment` local for the final compare, `distance`
  as a one-member struct (retail's top spill slot), and a documented
  `__builtin_expect` on `hasCloseNeighbors()`.

Behaviour is unchanged. No inline assembly, register constraint, flag
change, output edit or header change is used.

## Verification

`python -B tools/build.py ai-startup-spawnpoint` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,652 function,
5,713 section and 180 region comparisons and no mismatch or skip; the
previous baseline was 5,651, 5,713 and 180.
