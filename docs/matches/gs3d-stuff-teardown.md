# GS3DStuff::tearDown exact match

`GS3DStuff::tearDown()` matches all 492 retail bytes at Thumb address
`0x002df419`, including relocations.

```text
OK  _ZN9GS3DStuff8tearDownEv  0x002df419  492 bytes
```

## Source form

`tearDown` shuts down the managers in this order:

1. The AI, game-object, scene-node, script and menu managers.
2. The light nodes, then game data from the scene root.
3. The sun node, the camera, physics, timelines and locks.
4. The octree, spawn instances, the player, the physics world and the trail
   manager.
5. Highlights, the map, car sounds and sounds.

It then frees the five visibility arrays.

Details that the retail bytes require:

- **Array helpers.** Each visibility array is freed through one of two file-local
  `always_inline` helpers. Both free `data` only when `free_when_destroyed`
  is set, and then free the array.
  - `deletePointerArray` tests the flag and deletes the array once.
  - `deletePointerArraySplit` tests `!free_when_destroyed` first and calls
    `operator delete` in each arm. The arms are not identical: the second
    one frees `data` first.
- **Which arrays use the split helper.** `VisibleNodes`,
  `LastVisibleSceneNodes` and `VisibleSpawnPoint` use it.
- **Why the split matters.** Both arms of the split helper call
  `operator delete`, so the call heuristic gives each arm 50% and raises the
  cold-block frequency of those three arrays. Cross-jumping merges the
  duplicated delete back into one shape before basic-block reordering. That
  reproduces retail's cold-block order 5, 4, 1, 3, 2.
- **Evidence.** The per-array helper choice follows from the retail block
  order and frequencies, as modelled from `-fdump-rtl-bbro`. The original
  source is not available to confirm the exact spelling.

No branch hint, inline assembly, register constraint, flag change or output
edit is used, and no header change.

## Verification

`python -B tools/build.py gs3d-stuff` passes. `MenuManager::tearDown`,
`ScriptManager::tearDown` and `CarSounds::Clean` are bound as Thumb callees. The section is placed in the shared
`GS3DSceneTraversal.ld`, so every unit that links gs3d-stuff.o places it. A
fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,596
function, 5,684 section and 181 region comparisons and no mismatch or skip;
the previous baseline was 5,595, 5,683 and 181.
