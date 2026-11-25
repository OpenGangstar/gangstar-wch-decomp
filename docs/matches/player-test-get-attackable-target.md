# PlayerTest::getAttackableTarget exact match

`PlayerTest::getAttackableTarget(LevelObject*, Weapon*, LevelObject*)` matches
all 700 retail bytes at Thumb address `0x00303315`, including relocations.

```text
OK  _ZN10PlayerTest19getAttackableTargetEP11LevelObjectP6WeaponS1_  0x00303315  700 bytes
```

## Source form

The function gathers the hostile, targetable NPCs in weapon range. It scores
each one by distance and by how far it is from the player's facing, and
returns the best-scoring target.

Details that the retail bytes require:

- **Candidate list.** The candidates live in a file-local explicit
  specialisation of `irr::core::array<NPC*>`, written in the style of
  `core/UnsignedShortArray.h`.
  - Its destructor resets the fields before deleting the buffer pointer.
  - `clear()` only deletes.
  - This reproduces retail's tail stores.
- **Weak calls.** `push_back` and `NPC::isTargetable` are declared weak and
  are called through the GOT, as in retail. Both are `STB_WEAK` in the retail
  symbol table.
- **Loop index.** The index is a signed `int` compared as
  `(unsigned int)i < candidates.size()`. The cast keeps a short-lived
  register copy of the index, which gives retail's loop-top register and
  reload rotation.
- **Slots and operand order.** `best` is declared first and the range is
  squared in place, which gives retail's stack slots. The facing factor is
  assigned rather than computed in a ternary, which gives retail's multiply
  operand order. The normal and facing vectors are copied by value.

No branch hint, inline assembly, register constraint or output edit is used,
and no shared-header change. The other PlayerTest.cpp functions keep their
bytes. `NPC::isHostileTo`'s placement moved into the shared
`NPCFunctionSections.ld`, so the PlayerTest link places it.

## Verification

`python -B tools/build.py` passes for ai-startup-playertest and
ai-startup-npc. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,598 function, 5,702 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,596, 5,700 and 180.
