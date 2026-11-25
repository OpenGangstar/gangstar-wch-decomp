# GameObjectManager::getAttackableTarget exact match

`GameObjectManager::getAttackableTarget(Character*)` matches all 316 retail
bytes at Thumb address `0x003160d9`, and its strict section ends at the retail
extent.

```text
OK  _ZN17GameObjectManager19getAttackableTargetEP9Character  0x003160d9  316 bytes
OK SECTION .gom_get_attackable_target  0x003160d8  316 bytes
```

## Source form

The function scans the object list for enabled characters, or characters with
flag `0x80`. For each it asks `getDistanceFromAttackableTarget`, using the
weapon's range and a non-camera flag, and keeps the nearest valid target. A
faction-2 NPC also considers the player.

The earlier form differed in 10 bytes, in argument-move registers and reload
scratch registers.

- **Cause.** It skipped disabled objects with a negated `&&` and `continue`.
  That placed the call block at the end of the RTL insn chain, so reload's
  round-robin spill-register choice shifted by one.
- **Fix.** Writing the test as a positive nested block,
  `if (isEnabled() || (unknown4 & 0x80)) { ... }`, keeps the call block in
  natural order. Reload and sched2 then reproduce retail.

Supporting source changes:

- `GameObjectManager.h` declares
  `getDistanceFromAttackableTarget(Character*, int, LevelObject*, bool)`, the
  existing retail member.
- `NPC.h` gains `friend class GameObjectManager;`, which the private `faction`
  read needs.
- `GameObjectManager.cpp` includes `PlayerTest.h`.

The DECL_UID-sensitive `GameObjectManager::GetMetatypeFromName` remains exact,
and so does every other unit.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,556 function, 5,639 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
