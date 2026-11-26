# MiniMap::draw2d exact match

`MiniMap::draw2d() const` matches all 1380 retail bytes at Thumb address
`0x0032a0f9`, including relocations.

```text
OK  _ZNK7MiniMap6draw2dEv  0x0032a0f9  1380 bytes
```

## Source form

The function draws the minimap: it clips to the frame module, renders the
map around the player, then walks the tracked objects and draws each
visible marker (target markers and wanted-level indicators included).

Details that the retail bytes require:

- **Pixel position as one constructor.** `position2d<int> pixel(...)` ends
  the block, so tree-sink moves only the last conversion and the pixel
  arithmetic stays where retail has it.
- **Value-copy locals.** Map coordinates go through `vector2d<float>` locals
  declared above the early return, the frame inset is a `const int border`,
  sprite frame, target-marker fields and the point coordinates are read into
  locals once. These set retail's spill-slot order (which follows pseudo
  register order) and its register choices.
- **Declaration order.** The clip rectangle is built with zeros first, and
  the tracked-object link is declared before the end sentinel, which gives
  retail's store order and r2/r3 assignment.

Behaviour is unchanged: each member is read once as retail does, and call
order is the same. The function section is 1384 bytes, the 1380-byte body
plus a `c046c046` pad that retail also has before `Radio::show` at
`0x0032a660`; the linker assertion now checks that bound. No branch hint,
inline assembly, register constraint, flag change, output edit or header
change is used. The draw2d thunk keeps its bytes.

## Verification

`python -B tools/build.py minimap-draw-thunk` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,641 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,640, 5,713 and 180.
