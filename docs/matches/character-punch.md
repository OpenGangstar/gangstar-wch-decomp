# Character::punch exact match

`Character::punch()` matches all 776 retail bytes at Thumb address `0x002f710d`,
and its strict section ends at the retail extent.

```text
OK  _ZN9Character5punchEv  0x002f710d  776 bytes
OK SECTION .character_punch  0x002f710c  776 bytes
```

## Source form

The body was rebuilt from the retail instructions. Every call, constant and
vtable slot follows the retail code:

- the fists combo sequence and the combo index reset
- the 0x10000000/0x1c000000/0x20000000 movement-flag updates
- three random punch sounds, each played with SoundManager's `unknown140`
  guard
- the target type gates (8 = player vehicle check, 5 = character, 3 = damageable
  object)
- the range and cone test
- the blood splash, `punched` and `nextPunch`

Three source details decide the bytes:

- **One type-8 test.** The type-8 test is written once:
  `if (type == 8) { if (!player->unknown372) goto hit; } else if (!(unknown4 & 4)) goto skip;`.
  That gives retail's register assignment (r4/r5/r7) and block layout. Combined
  `||` forms move the GetPlayer block and the type-3 path.
- **The unused victim position.** Retail calls `victim->GetPosition()` through
  vtable slot +0x30 and discards the result. Calling the existing inline
  `Character::position()` wrapper allocates that temporary last (sp+24), as
  retail does. A named local or a const reference takes the highest slot
  instead, which shifts every splash temporary by 12 bytes.
- **The GOT calls.** `isDying` and `isDown` remain weak declarations, so their
  calls go through the GOT as in retail.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,539 function, 5,621 section
and 181 region comparisons and no mismatch or skip. The previous baseline was
5,538, 5,620 and 181. Unit tests, repository checks and progress checks pass.
