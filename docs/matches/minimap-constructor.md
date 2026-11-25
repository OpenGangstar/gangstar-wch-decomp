# MiniMap constructor exact match

```text
OK  _ZN7MiniMapC1EP7ASpriteiiii  0x003295a5  212 bytes
OK  _ZN7MiniMapC2EP7ASpriteiiii  0x003295a5  212 bytes
OK SECTION .minimap_constructor  0x003295a4  212 bytes
```

The complete-object and base-object constructors share one retail body. It
builds the `VirtualButton` base with button type 7, clears the tracking state,
initialises the `TargetMarker` singleton and insets the touch region by
`inset` (18) on every side.

- The inset is applied as `left = amount + left` / `right -= amount` with every
  edge loaded into its own local first. Reassigning the same variable keeps
  each load a separate statement (GCC 4.2.1 TER), which reproduces retail's
  load-then-store schedule.
- `TrackingLink` gains its self-linking default constructor so the embedded
  list head is initialised as retail does; no layout changes.

Retail-only callees (`VirtualButton` C1, `TargetMarker::init`) and the
soft-float helpers are bound to retail addresses. The placement is also
recorded in `MiniMapDrawThunk.ld` so that verification image links.

Full gate: `python -B tools/build.py --all` exited 0 with 5,499 function,
5,574 section and 181 region comparisons and no mismatch or skip.
