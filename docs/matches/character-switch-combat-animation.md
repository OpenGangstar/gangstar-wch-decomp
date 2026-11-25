# Character::switchCombatAnimation exact match

`Character::switchCombatAnimation()` matches all 1108 retail bytes at Thumb
address `0x002f517d`, including relocations. Its 125-entry jump table also
matches all 500 retail bytes at `0x0041bddc`.

```text
OK  _ZN9Character21switchCombatAnimationEv  0x002f517d  1108 bytes
OK SECTION .character_switch_combat_animation        0x002f517c  1108 bytes
OK SECTION .character_switch_combat_animation_table  0x0041bddc  500 bytes
```

## Source form

The function switches on the current animation, picks the matching combat
animation or shoot action, and returns `true` when it handled the switch.
`PlayerTest` already calls it as a `bool` function, so `Character.h` now
declares it `bool`.

Details that the retail bytes require:

- **Case order.** The case bodies are written in the order 86, 87, 83, 67,
  51, 164, 81, 78, 77, 70, 69, 146, 145, 138, 143, 142, 141, 140, 66, 64, 54,
  90, 61, 57, 52, then default.
  - The block layout and the cross-jump hosts come from bb-reorder, not
    from source order. So source order is free to set the order in which
    the return value is reloaded.
  - The spilled return value is reloaded through `r2` or `r3`, alternating
    round-robin unless one of them is live. This source order puts every
    reload in retail's register. It was found by modelling that rotation
    from the reload dump.
- **Shoot cases.** Cases 146, 145, 142, 141, 140 and 64 compute the new
  movement flags into a local `f`, store them, and test bit 21 first:
  `shoot` when it is set, otherwise `setAnimation`.
- **Case 164.** Case 164 handles the non-player path first, then the player
  path.
- **The one documented hint.** Case 145 carries
  `__builtin_expect(static_cast<int>(f << 10) < 0, 1)`. Both arms of that
  case end in jumps out of the body, so bb-reorder points the conditional
  branch at the more probable side. GCC's opcode heuristic rates `x < 0` as
  unlikely and emits `bpl` to the animation path. Retail emits `bmi` to
  `shoot`. Without the hint the function differs from retail in 3 bytes, at
  `0x216`–`0x218`. Every hint-free spelling folds back to the same compare.

No inline assembly, register constraint, flag change or output edit is used.

## Verification

`python -B tools/build.py` passes for ai-startup-character,
ai-startup-playertest and ai-startup-npc. The function and its table are
placed in the shared `CharacterStateSections.ld`. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,602 function, 5,691 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,601, 5,689 and 181.
