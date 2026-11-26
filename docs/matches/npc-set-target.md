# NPC::SetTarget exact match

`NPC::SetTarget(LevelObject*)` matches all 320 retail bytes at Thumb address
`0x003009d1`, including relocations.

```text
OK  _ZN3NPC9SetTargetEP11LevelObject  0x003009d1  320 bytes
```

## Source form

The function sets the NPC's target, clears or sets the related flags and
plays the reaction sound for the new target type.

Details that the retail bytes require:

- **Sound cases.** The sound block's case labels follow the return in the
  order 4, 0, 2.
- **Two views for the store and the flags.** The target is stored through
  a Character-layout view and the flags are read through an NPC-layout
  view, so the scheduler keeps retail's store-before-load order.
- **Constant before the store.** The target store address is written as
  `self` plus the offset of `flags356` in a view of the object, minus 356.
  The value is `self`; the form materialises the 356 constant before the
  store, which lengthens the offset pseudo's live range so global
  allocation gives the flags pseudo r2 and the offset r1, as retail does.
  It forms an address from a possibly null object without dereferencing
  it. This form was accepted by the maintainer as byte-exact.
- **Definition without a header change.** The method is defined through
  its mangled name.

No branch hint, inline assembly, register constraint or output edit is used.
The other NPC.cpp functions keep their bytes.

## Verification

`python -B tools/build.py` passes for ai-startup-npc and
ai-startup-playertest. A fresh complete build, `python -B tools/build.py
--all`, exited 0 with 5,632 function, 5,713 section and 180 region
comparisons and no mismatch or skip; the previous baseline was 5,630, 5,713
and 180.
