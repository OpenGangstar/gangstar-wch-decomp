# SpawnPoint::Load exact match

`SpawnPoint::Load(Structs::SpawnPoint const&)` matches all 540 retail bytes at
Thumb address `0x00306b11`, and its strict section ends at the retail extent.

```text
OK  _ZN10SpawnPoint4LoadERKN7Structs10SpawnPointE  0x00306b11  540 bytes
OK SECTION .spawn_point_load  0x00306b10  540 bytes
```

## Source form

The function does the following, in order:

- copies the position and rotation;
- reads the material and triangle IDs, resetting both when the material is
  above 59999;
- allocates and zero-fills the shared 256-entry metatype tables on first use;
- selects the spawn constants by spawn type (11 parked car, 16 prisoner,
  3 car, otherwise civilian);
- records the metatype's count, values and constants on first sight;
- resets the spawn timer;
- frees the source record's strings and values, and registers the spawn point.

Earlier forms matched everything except one `strb` in the zero-fill loop at
`0x1da`, where the address operands were reversed. The tree dumps show the
cause:

- ivopts gives the loop index a recycled SSA name from the free list.
- When that name is lower than the base load's, VRP canonicalises the address to
  `index + base`.

Two genuine spellings shift the free-list state:

- the chained reset `triangleId = materialId = 0;`, whose forwarded store
  releases one extra name;
- an `unsigned` zero-fill index, which drops a conversion.

With both, the index receives version 97, above the base's 71, which gives
retail's `[base, index]` order. The behaviour is identical, and the store order
(material first) is unchanged.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,551 function, 5,633 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
