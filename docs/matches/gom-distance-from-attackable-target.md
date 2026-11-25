# GameObjectManager::getDistanceFromAttackableTarget exact match

`GameObjectManager::getDistanceFromAttackableTarget(Character*, int,
LevelObject*, bool)` matches all 416 retail bytes at Thumb address
`0x00315f39`, including relocations.

```text
OK  _ZN17GameObjectManager31getDistanceFromAttackableTargetEP9CharacteriP11LevelObjectb  0x00315f39  416 bytes
```

## Source form

The function returns -1 when the target cannot be attacked from this
character's point of view. Otherwise it returns the squared distance to the
target. The rules depend on whether the target is the player, an NPC or a
vehicle, and on faction hostility and health.

Details that the retail bytes require:

- **Faction helper.** In the NPC case, the opposed-faction test uses a
  file-local `static inline bool areFactionsHostile(unsigned int other, int
  faction)`, made of if-returns. It is called with the target's faction
  first. The join after the inlined helper survives DOM1 jump threading, so
  the hostile arm's faction load shares `myFaction`'s register `r2`, as in
  retail. Every plain if/return form threads the join away and leaves the
  load in `r3`.
- **Same helper as `NPC::isHostileTo`.** This is the same helper shape that
  matches `NPC::isHostileTo`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other GameObjectManager.cpp functions keep their
bytes.

## Verification

`python -B tools/build.py game-object-manager` passes. `__aeabi_f2iz` is
bound at its PLT address `0x001c44cc`. A fresh complete build, `python -B tools/build.py --all`,
exited 0 with 5,596 function, 5,700 section and 180 region comparisons and no
mismatch or skip; the previous baseline was 5,595, 5,699 and 180.
