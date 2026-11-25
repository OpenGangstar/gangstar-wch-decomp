# SpawnPoint::CreateAllSpawnInstances exact match

`SpawnPoint::CreateAllSpawnInstances()` matches all 336 retail bytes at Thumb
address `0x003065e5`, including relocations.

```text
OK  _ZN10SpawnPoint23CreateAllSpawnInstancesEv  0x003065e5  336 bytes
```

## Source form

The function counts the spawn instances needed per metatype across every
spawn point's group. It then creates that many game objects for each
metatype.

Details that the retail bytes require:

- **Counts array.** The per-metatype counts array is zero-initialised with
  `= {0}` instead of a separate `memset`. The initialiser still expands to
  retail's `memset(sp + 8, 0, 1024)` call. Because the array does not
  escape, the loop-invariant pass can hoist the row-table load past the
  stores to `counts[]` into the loop entry block, where retail has it.
- **Inner loop guard.** The loop over a group's metatypes uses only its loop
  guard, `i < count`, with no separate `if (count != 0)`. The loop guard is
  predicted taken, so the count and row values tie in global-alloc
  priority. The lower register then goes to the row value, as in retail.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other functions in SpawnPoint.cpp are unchanged.

## Verification

`python -B tools/build.py ai-startup-spawnpoint` passes. `memset` is bound at
its PLT address, and `GameObjectManager::CreateGameObjectFromMetatype` is
bound as a Thumb callee. A fresh complete build, `python -B tools/build.py --all`,
exited 0 with 5,605 function, 5,696 section and 181 region comparisons and no
mismatch or skip; the previous baseline was 5,604, 5,695 and 181.
