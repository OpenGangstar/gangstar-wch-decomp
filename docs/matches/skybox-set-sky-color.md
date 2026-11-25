# CustomSkyBoxSceneNode::setSkyColor exact match

`CustomSkyBoxSceneNode::setSkyColor(bool)` matches all 4120 retail bytes at
Thumb address `0x002f84c9`. The function has no relocations.

```text
OK  _ZN21CustomSkyBoxSceneNode11setSkyColorEb  0x002f84c9  4120 bytes
```

## Source form

The flag chooses one of two four-colour palettes:

| Palette | Colours (A, R, G, B) |
|---|---|
| Day | (255,255,255,255), (255,150,210,220), (255,115,153,177), (255,55,82,95) |
| Night | (255,255,255,255), (255,255,255,255), (255,255,242,160), (150,255,235,50) |

The colours are stored in index order 3, 2, 1, 0. The function then rewrites
vertices 0 to 43 of the sky box with literal positions, the up normal, a
palette colour and texture coordinates. Each vertex takes its colour by band:

| Vertices | Colour |
|---|---|
| 0–7 | 3 |
| 8–15 | 2 |
| 16–31 | 1 |
| 32–39 | 0 |
| 40–43 | 3 |

Details that the retail bytes require:

- **Colour view.** The palette, which sits at `this + 0x880`, is reached
  through a file-local view that declares four distinct `SColor` members,
  `c0` to `c3`. With an array view, RTL alias analysis cannot separate the
  stores to the same byte field of different elements. That gives each colour
  store extra output dependences, and sched2 then orders the store ahead of a
  reload-generated constant load, the reverse of retail. Distinct members let
  `nonoverlapping_component_refs` separate the stores, which reproduces
  retail's schedule.
- **Vertex helper.** A file-local `setVertex` helper takes the colour by value.
  A `const SColor&` parameter produces block copies instead of the colour
  bytes hoisted into registers.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py sdk-startup-customskyboxscenenode` passes every function
and section check. A fresh complete build, `python -B tools/build.py --all`, exited
0 with 5,589 function, 5,676 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,588, 5,675 and 181.
