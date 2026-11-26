# CControlManager::update exact match

`CControlManager::update()` matches all 400 retail bytes at Thumb address
`0x0032d72d`, including relocations.

```text
OK  _ZN15CControlManager6updateEv  0x0032d72d  400 bytes
```

## Source form

Each frame the function leaves combat or sniping when the active weapon or
a cinematic requires it, raises virtual-button events and updates the
on-foot handler's state from the player's input timestamps.

Details that the retail bytes require:

- **Call predictor on the store edge.** When `unknown28[3]` is clear, the
  on-foot handler's flag is set through a one-byte
  `__builtin_memset(&handler->unknown12, true, 1)`. The target is a field
  behind a pointer, so the builtin is not folded before branch prediction,
  and the call heuristic gives that edge retail's 30% probability. This
  sets retail's block order and its r5/r6 assignment. At expansion the
  builtin becomes the same single `strb` as a plain assignment; no call or
  relocation is emitted.
- **Other interfaces.** `Character::isDown` is reached through a weak
  `extern "C"` declaration of its mangled name, giving retail's GOT call;
  the combat test is the bit-13 mask of the player flags. `update()` is
  declared in `CControlManager.h` as a non-virtual member, which changes no
  layout.
- **Linker.** The unit now emits the `EvVirtualButton` vtable and
  destructors as link-once sections, so the linker script places them at
  their retail addresses.

Behaviour is unchanged. No branch hint, inline assembly, register
constraint, flag change or output edit is used.

## Verification

`python -B tools/build.py ai-startup-ccontrolmanager` passes. A fresh
complete build, `python -B tools/build.py --all`, exited 0 with 5,643
function, 5,713 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,642, 5,713 and 180.
