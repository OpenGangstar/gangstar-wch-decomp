# MenuManager::_zoomMap exact match

`MenuManager::_zoomMap(std::list<Point2D<short>*> const&)` matches all 560
retail bytes at Thumb address `0x002e6db1`, and its strict section ends at the
retail extent.

```text
OK  _ZN11MenuManager8_zoomMapERKSt4listIP7Point2DIsESaIS3_EE  0x002e6db1  560 bytes
```

## Source form

The function converts the change in pinch distance into a clamped zoom step.
When the zoom changes, it keeps the window centre fixed while rescaling, clamps
the window to the scaled texture and copies it into the Map clip. It then
always publishes the zoom as the Map scale.

Like `_scrollMap`, it is an `extern "C"` definition of the retail mangled name
that uses file-local field views (`ZoomFields`, `ZoomMapFields`), so no shared
header declaration is needed. Four details decide the bytes:

- **Inline `m.height / 2`.** It is written inside the centre expressions, not as
  a named local, so the height load is scheduled after the `i2f` libcall as in
  retail.
- **Store order in the right clamp.** The right-clamp branch stores `left`
  before `right`, which gives retail's allocation, as in `_scrollMap`.
- **The right-clamp test.** The test recomputes the scaled width from
  `textureWidth`, which RTL CSE merges back into the existing value.
  - This keeps the `textureWidth` user variable live across a CSE path, so it
    keeps its low pseudo number.
  - Spill slots are handed out in pseudo order, so that number yields retail's
    slots.
  - Nothing between the two computations writes `m.zoom`, so the behaviour is
    unchanged.
- **Operand order of that test.** It is written
  `scaledWidthExpression <= m.right`, which gives retail's `cmp r9, r1; ble`
  operand order.

No header change, branch hint, inline assembly, register constraint or output
edit is used. The shared `MenuManagerFocus.ld` provides the retail float
helper PLT addresses.

## Verification

`python -B tools/build.py --all` exited 0 with 5,550 function, 5,632 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
