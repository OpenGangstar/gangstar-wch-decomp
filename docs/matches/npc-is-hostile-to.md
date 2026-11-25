# NPC::isHostileTo exact match

`NPC::isHostileTo(LevelObject*)` matches all 128 retail bytes at Thumb address
`0x002fe0e9`, including relocations.

```text
OK  _ZN3NPC11isHostileToEP11LevelObject  0x002fe0e9  128 bytes
```

## Source form

`isHostileTo` checks the target's type. Another NPC is hostile when the two
factions are opposed (1 against 2). For the player and other targets, the
function asks the faction table.

Details that the retail bytes require:

- **Faction helper.** The opposed-faction test is a file-local
  `static inline bool areFactionsHostile(unsigned int other, int faction)`
  made of if-returns.
  - C++ gives the inlined helper an `int` result variable. Converting it back
    to `bool` is a plain truncation.
  - The two arms therefore merge into a separate byte value, which is
    zero-extended once and shared by cross-jumping, as in retail.
- **Parameter order.** The parameters come in (other, own) order. That gives
  retail's `r5`/`r6` assignment for the PIC base and `this`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other NPC.cpp functions are unchanged.

## Verification

`python -B tools/build.py ai-startup-npc` passes. `Factions::isFactionEnemy`
is bound as a Thumb callee. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,595 function, 5,699 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,594, 5,698 and 180.
