# MenuManager::updateMarkers exact match

```text
OK  _ZN11MenuManager13updateMarkersEv  0x002e6949  360 bytes
OK SECTION .menu_update_markers  0x002e6948  360 bytes
```

Projects the player (or their vehicle) onto the scaled map, enables the target
marker with a screen offset when the point is inside the map viewport, and
advances the animation of every flagged MiniMap tracking marker.

- As with `updateMap` and `_drawMap`, private `MenuManager`, `Map`,
  `TargetMarker` and `MiniMap` fields are read through local offset views
  instead of new `MenuManager.h` declarations, because header changes perturb
  the matched `Menus::ServiceCarRental::Notify`.
- The tracking list is walked with a minimal iterator type (copyable iterator,
  pre-increment, `!=`), which yields retail's loop shape.
- The marker X offset is written in two steps (`offsetX = offset` then
  `offsetX += pos.X`), matching retail's split store.

`AnimObject::UpdateFrame` and `PlayerTest::GetPlayer` are bound to retail
Thumb addresses.

Full gate: `python -B tools/build.py --all` exited 0 with 5,499 function,
5,574 section and 181 region comparisons and no mismatch or skip.
