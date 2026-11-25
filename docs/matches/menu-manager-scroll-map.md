# MenuManager::_scrollMap exact match

`MenuManager::_scrollMap(std::list<Point2D<short>*> const&)` matches all 228
retail bytes at Thumb address `0x002e6865`, and its strict section ends at the
retail extent.

```text
OK  _ZN11MenuManager10_scrollMapERKSt4listIP7Point2DIsESaIS3_EE  0x002e6865  228 bytes
```

## Source form

The function moves the visible map window by the drag delta from the previous
touch point, then clamps it:

- to the left/top at 0;
- to the right/bottom at the scaled map size from `Map::getScaledSize`.

It then copies the window into the Map's clip rect and stores the touch point.

`MenuManager` does not declare `_scrollMap`, and the Map clip rect is private.
To avoid shared header declarations, which perturb other matched units through
declaration UIDs, the function is defined as an `extern "C"` definition of the
retail mangled name. It uses file-local field views (`ScrollMapFields`,
`ScrollMapClip`) taken from the retail offsets.

Two choices decide allocation:

- **Clamp store order.** In the width clamp, storing `left` before `right`
  lengthens the scaled width's live range. That lowers its allocation priority,
  which removes the earlier GOT spill (232 bytes) and gives retail's callee-saved
  set.
- **Declaration order of x and y.** x and y tie exactly in global-allocation
  priority, so the lower allocno number wins. Declaring `int y, x;` before
  loading x then y assigns them retail's `sl`/`r9`.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,549 function, 5,631 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
