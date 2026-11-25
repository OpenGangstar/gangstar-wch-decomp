# Character::switchMoveAnimation exact match

`Character::switchMoveAnimation()` matches all 1236 retail bytes at Thumb
address `0x002f661d`, including relocations. Its 206-entry jump table at
`0x0041c22c` also matches.

```text
OK  _ZN9Character19switchMoveAnimationEv  0x002f661d  1236 bytes
```

## Source form

`switchMoveAnimation` chooses the next animation when a movement or vehicle
animation ends. It returns `false` for animations it does not handle.

- **Hijacks:** the hijack animations finish the hijack.
- **Getting in:** the get-in animations seat the character. They play the
  seated animation, hide the character, release an immobilised vehicle and
  hand control back to a player driver.
- **Becoming the driver:** a character who ends up driving gives the vehicle
  an AI state. A flagged NPC gets the flee state with a random direction and
  a pursuit target; any other driver gets the default state. In both cases
  an `EvNPCDespawn` event is raised.
- **Doors and exits:** these animations finish exiting, closing doors or
  throwing out a driver, depending on the movement flags.
- **Weapons and idle:** the remaining animations return to the matching weapon
  or idle animation.

Details that the retail bytes require:

- **Event constructor.** `EvNPCDespawn` passes its event ID to the `IEvent`
  base constructor (`IEvent(18)`), rather than assigning it in the body.
  Retail stores the base vtable, then the event ID, then the derived vtable.
  GameObjectManager, the other user of the event, compiles to identical bytes
  with the new constructor.
- **Get-in flag test.** In the 26/28 and 27/29 groups the bit test goes
  through an inline bool helper, which gives the natural then-likely
  probability. In 22 and 23 the flag is tested directly.
- **Pursuer local.** A separate `pursuer` local holds the vehicle for the
  pursuit block, so the vehicle pointer is not reloaded.
- **Shared case bodies.** Some case groups share bodies. They are distinct
  labels, and retail keeps separate blocks for them.
- **throwOutDriver binding.** `throwOutDriver` is defined later in the file
  and is not in `Character.h`, so it is forward-declared through its
  `extern "C"` mangled name.

No branch hint, inline assembly, register constraint or output edit is used.

## Linking

The function, its jump table, and the `EvNPCDespawn` linkonce destructors and
vtable are placed at their retail addresses in the shared
`CharacterRecoveredSections.ld`. The NPC and PlayerTest units also link the
character object, and the symbol is no longer bound externally there.

## Verification

`python -B tools/build.py` passes for ai-startup-character, ai-startup-npc,
ai-startup-playertest and game-object-manager. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,586 function, 5,672 section and
181 region comparisons and no mismatch or skip; the previous baseline was 5,585,
5,670 and 181.
