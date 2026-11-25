# FPSCamera::updateTouchInputs exact match

`FPSCamera::updateTouchInputs()` matches all 364 retail bytes at Thumb address
`0x00334389`, and its strict section ends at the retail extent.

```text
OK  _ZN9FPSCamera17updateTouchInputsEv  0x00334389  364 bytes
OK SECTION .fps_update_touch_inputs  0x00334388  364 bytes
```

## Source form

The function has the same shape as the matched `MenuManager::updateMap`, without
the region filter.

1. Unless the menu has consumed the cursors, it collects the current touch
   points into a `std::list` of `Point2D<short>*`.
2. If the touch count changed, it records the new count and either the single
   touch position or the initial two-finger distance (`sqrtf`).
3. Otherwise it scrolls for one touch or zooms for two.

The earlier 316-byte mismatch was structural. `std::list<Point2D<short>*>` was
incomplete in this unit, so the STLport list code that retail inlines was never
generated: the constructor, `push_back`, `size` and the `clear` destructor.

The complete list specialization from `MenuManager.cpp` is repeated file-locally
in `FPSCamera.cpp`. The retail allocator and `_List_base::clear` calls bind
through the GOT, as in retail. No header is changed.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,562 function, 5,645 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
