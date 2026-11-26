# ContactFilter::ShouldCollide exact match

`ContactFilter::ShouldCollide(b2Shape*, b2Shape*)` matches all 1100 retail
bytes at Thumb address `0x0031dc7d`, including relocations. Its vtable
`_ZTV13ContactFilter` is placed at `0x004abd00`.

```text
OK  _ZN13ContactFilter13ShouldCollideEP7b2ShapeS1_  0x0031dc7d  1100 bytes
```

## Source form

The filter first applies Box2D's category/mask/group test, then compares the
vertical extents of the two bodies: a character or the player uses its
position and height offset, a scene node uses its transformed bounding box,
and a static body uses its stored heights.

Details that the retail bytes require:

- **Definition order.** The function is appended to the end of
  `PhysicAttributes.cpp`, which leaves the declaration UIDs of every earlier
  function unchanged.
- **Empty-filter helper.** One inline helper tests both filters for "all
  zero", so retail's shared early return is kept.
- **Hints.** Three documented no-code `__builtin_prefetch` calls set the
  branch probabilities (PRED_CALL) on the second mask test and on the two
  user-data guards, which gives retail's block order.
- **Owner reload.** `data1->owner` and `data2->owner` are read again after
  the `GetPlayer()` call, as retail does.
- **Static-body minimum.** The second body's lowest height is computed as
  `const float& lowest = min_(upperHeight, lowerHeight)` followed by two
  if-assignments. Reassigning `low2` in place makes the compare operand a
  low-version PHI, so fold keeps retail's operand order.

## Integration

`ContactFilter`'s destructor is already linked from this unit, and its
vtable now comes from this object. The units that discard the rest of
`ai-startup-physicattributes.o` (Character, NPC and PlayerTest) place the
vtable, `ShouldCollide` and `SetCurrentJumpShape` at their retail addresses.

The `SlideControl` and `WantedMeter` C2 constructors are aliases of the
already-matched C1 constructors at the same addresses; their stale pending
assembly files are removed.
