# PlayerTest::updateCarInteraction exact match

`PlayerTest::updateCarInteraction()` matches all 1,684 retail bytes at
Thumb address `0x0030406d`, including relocations. Its 17-entry jump table
at `0x0041e2fc` also matches.

```text
OK  _ZN10PlayerTest20updateCarInteractionEv  0x0030406d  1684 bytes
```

## Source form

`updateCarInteraction` runs the player's car-entry and car-exit state
machine. A switch over the interaction state opens doors, plays the entry,
exit and door animations, seats or ejects the player, and returns control
to on-foot handling when the sequence finishes.

Details that the retail bytes require:

- **Case source order.** The cases are written in the order 1, 2 (empty),
  3, 7, 12, 5, 6, 8, 9, 10, 16, 11, 13 (empty), 14, 15. GCC 4.2.1's block
  reordering breaks ties between equally likely switch arms by basic-block
  order, so this order gives retail's layout. The stack slots of the case
  locals are also assigned in source order. Cases 7, 11 and 16 each make
  their own `finishedStopDriving` call.
- **Layout views for scheduling.** The build uses `-fno-strict-aliasing`,
  so the memory expression of each access decides which loads may be
  scheduled past which stores. The animation speed is stored through a
  view based on the PlayerTest object. Facing is assigned as a whole
  `vector3d` through a view that also holds the vehicle pointer, and case
  14 reloads the vehicle through that view. Retail's load and store order
  follows from this.
- **Case 9.** `SetPosition` is called before the `character` local is
  declared, so the pointer is materialised after the virtual-function load,
  as retail does.
- **Definition without a header change.** The function is defined through
  its mangled name. Private Character methods are called through `extern
  "C"` declarations, and Vehicle's private door and immobilisation fields
  are read through a file-local view.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other PlayerTest.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-playertest` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,606 function, 5,709
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,605, 5,709 and 180.
