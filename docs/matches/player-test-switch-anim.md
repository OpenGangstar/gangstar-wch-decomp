# PlayerTest::switchAnim exact match

`PlayerTest::switchAnim()` matches all 1072 retail bytes at Thumb address
`0x00303bb9`, including relocations. Its 852-byte jump table at `0x0041dfa8`
also matches.

```text
OK  _ZN10PlayerTest10switchAnimEv  0x00303bb9  1072 bytes
```

## Source form

`switchAnim` chooses the player's next animation when the current one ends.

1. If an animation is queued, it plays that animation and clears the queue.
2. Otherwise, if the combat animation switch takes over, it stops there.
3. Otherwise it dispatches on the current animation:
   - **Vehicle entry (1–4):** completes the entry. When the driver-eject flag
     is set, it plays one of three random lines, opens the door, makes the
     current driver play the left eject animation and clears the flag.
     Otherwise it seats the player.
   - **Door animations (9–12):** close the door and play the close animation.
     Outside cinematics, they also close the opposite door.
   - **Landing and stand-up sets:** realign the character to the scene node's
     up axis and return to idle.
   - **Remaining groups:** update the player state, then either clear the
     animation, return to idle, or ready the weapon.
4. Finally it clears the transition flag.

Details that the retail bytes require:

- The driver-eject test reads bit 19 through an inline bool helper. Written
  inline, `(int)(flags << 12) < 0` gets GCC's "negative unlikely" prediction.
  Inside the helper it gets the natural then-likely probability, which
  reproduces retail's block layout without a branch hint.
- The two landing case groups (13/15 and 14/16) have equal bodies. They are
  separate case labels, and retail keeps two blocks with their own stack
  temporaries that share a cross-jumped tail. Case temporaries are given
  stack slots in reverse source order, so the 13/15, 14/16, then 7/8 order
  reproduces retail's frame.
- The up vector is bound to a `const vector3d&` before the transformation
  call.
- `Character::switchCombatAnimation` is declared locally with its bool result
  because the header's declaration is `void`. Retail tests the returned
  value.

`PlayerTest.h` declares `switchAnim` and `updateAnim`. No branch hint, inline
assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py ai-startup-playertest` passes every function and section
check, including the jump table. A fresh complete build, `python -B tools/build.py --all`,
exited 0 with 5,585 function, 5,670 section and 181 region comparisons and no
mismatch or skip; the previous baseline was 5,584, 5,668 and 181.
