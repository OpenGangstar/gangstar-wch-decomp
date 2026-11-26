# NPC::attackTarget exact match

`NPC::attackTarget()` matches all 2108 retail bytes at Thumb address
`0x002ff5d1`, including relocations.

```text
OK  _ZN3NPC12attackTargetEv  0x002ff5d1  2108 bytes
```

## Source form

The function drives an NPC's attack: it checks the target and weapon,
approaches or faces the target, and fires when ready. The body is an
`extern "C"` definition over the existing NPC layout, appended to `NPC.cpp`.

The structure, registers and reload order come from earlier rounds: a split
movement-flag test, a single-statement type lookup, a nested vehicle test and
a joined facing flag. The last difference was where the attack-call block is
placed, which needs its guard predicted at 15-18%. Two contrived
prediction forms, both commented in the source, do this without changing
code:

- **Attack guard.** The guard is compared against a non-zero constant
  through a one-field struct (`guard.k == 2u`). The struct keeps forward
  propagation from folding the test before branch prediction, so the
  opcode heuristic (29%) combines with the call heuristic (30%) to 14.9%.
  Later passes fold it back to the original test.
- **Facing test.** The facing result is compared the same way, and a no-code
  `__builtin_prefetch(self)` marks the continue edge as guarded. This raises
  the guard block's incoming frequency just enough for the attack block to
  reach retail's frequency, without disturbing the neighbouring blocks.

## Integration

`WeaponManager::getWeaponInList` is bound as an external Thumb function, and
`Character::runToTarget` is placed at its retail address in the NPC linker
script.
