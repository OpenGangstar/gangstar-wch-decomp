# NPC::_detect exact match

`NPC::_detect()` matches all 1104 retail bytes at Thumb address
`0x002ff181`, including relocations.

```text
OK  _ZN3NPC7_detectEv  0x002ff181  1104 bytes
```

## Source form

The function decides whether the NPC notices the player: it checks the
player's vehicle state, distance and view cone (via `acos` of the facing
dot product) or line of sight, then marks the NPC as detected.

Details that the retail bytes require:

- **Labels-as-values.** `void* const redirectLabel = &&vehicleRedirect;`
  (unused, so there is no computed jump) takes the address of the label at
  the `case 5: case 8:` body. The forced label stops cse path-following into
  the vehicle block, so the `0x104` offset is rematerialised there as in
  retail.
- **Bitfield union.** In the view-cone branch the flag update (set `0x200`,
  clear `0x8`) goes through a file-local `DetectFlags` union. The flag word
  is loaded before the `0x200` constant is formed, which gives retail's
  register assignment (constant in `r3`, flags in `r2`). The other branch
  keeps the plain `markDetected` helper.

Behaviour is unchanged. No branch hint, inline assembly, register
constraint, flag change, output edit or header change is used. The other
NPC.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-npc` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,640 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,638, 5,713 and 180.
