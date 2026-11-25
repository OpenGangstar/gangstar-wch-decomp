# MenuManager::_drawMap exact match

```text
OK  _ZNK11MenuManager8_drawMapEv  0x002e6ab1  424 bytes
OK SECTION .menu_draw_map  0x002e6ab0  424 bytes
```

Draws every MiniMap-tracked object visible in the map viewport (skipping locked
shops and wanted-only items) and then the target marker.

- `while (link != &trackedObjects)` with `link = link->next` on each skip
  path leaves an empty latch, so GCC 4.2's loop-header copying does not rotate
  the loop (retail's unrotated entry).
- Building the marker point as `position2d<int>(int(X), int(Y))` ends the
  inlined constructor block on the Y conversion, so only that conversion sinks,
  reproducing retail's call order.
- **One permitted branch-likelihood hint,** `__builtin_expect(clip test, 1)`,
  keeps the marker draw on the fall-through path; without it GCC's call
  heuristic moves it after the epilogue. The project already uses this idiom
  (MiniMap::registerForMapTracking).
- The function is defined under its retail mangled name as a free function, the
  form this file already uses to call it, and reads private `Map`, `MiniMap`,
  `Item` and `MenuManager` fields through offset views. Adding a member
  declaration to `MenuManager.h` (or splitting its offset-28 field) changes the
  generated code of the matched `Menus::ServiceCarRental::Notify` in
  MenuState.cpp, whose allocation depends on declaration identifiers, so no
  shared header is changed.

Retail-only callees and the soft-float helpers are bound to retail addresses.

Full gate: `python -B tools/build.py --all` exited 0 with 5,494 function,
5,571 section and 181 region comparisons and no mismatch or skip.
