# MenuManager::updateMap exact match

```text
OK  _ZN11MenuManager9updateMapEv  0x002e6fe1  388 bytes
OK SECTION .menu_update_map  0x002e6fe0  388 bytes
```

The map gathers touch points that start inside the map viewport into a
`std::list<Point2D<short>*>`, then remembers the first point (one finger) or the
pinch distance (two fingers) when the touch count changes, or scrolls/zooms
when it stays the same.

- The point list is modelled as an STLport list specialization whose nodes
  derive from `stlp_priv::_List_node_base`, the same node base as the touch-ID
  list. With `-fno-strict-aliasing`, distinct fields of the same record type let
  GCC schedule the touch-list `++i` load across the new node's link stores, as
  retail does. Both `size()` traversals, the GOT-called allocator and the two
  weak `clear()` imports are kept.
- If/else chains (not switches) for both count branches reproduce retail block
  order; `static_cast<int>(points.size()) != fields.mapMode` reproduces the
  compare canonicalization; storing x before y in source gives retail's
  load/store schedule.
- Map state is accessed through a field view (`MenuManagerMapFields`);
  `_scrollMap`/`_zoomMap` are still retail-only and called by mangled name.
  Soft-float helpers and `sqrtf` are bound to their retail PLT entries.

No hint, inline assembly or output edit is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,493 function and
5,570 section comparisons and no mismatch or skip.
