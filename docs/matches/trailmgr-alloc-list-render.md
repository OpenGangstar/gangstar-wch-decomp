# TrailMgr::AllocTrailList and TrailMgr::Render exact matches

```text
OK  _ZN8TrailMgr14AllocTrailListEPP5Traili  0x00348fb5  154 bytes
OK SECTION .trail_alloc_list  0x00348fb4  156 bytes
OK  _ZN8TrailMgr6RenderEv  0x00349271  56 bytes
OK SECTION .trail_render  0x00349270  56 bytes
```

`AllocTrailList` claims `count` unallocated dead trails into `list`; if it
cannot find enough it releases the ones it claimed and fails. `Render` draws
every live trail. The 156-byte section includes retail's two-byte alignment
`nop` after `AllocTrailList`.

Both test whether a trail is dead (`points[0].remainingLife <= 0`). Written
as a plain comparison, GCC's "comparison with zero" branch guess predicts the
wrong direction: `AllocTrailList` moved its store block out of line (160 bytes)
and `Render` merged its two loop latches (48 bytes). A bool-returning static
inline helper, `IsTrailDead`, turns the test into a bool compare that GCC
guesses the other way, which puts the store block inline and lets bb-reorder
duplicate `Render`'s small latch as retail does.

`AllocTrailList` additionally declares `found` and the loop index before the
`trails` null check, reuses that index for the rollback loop, and writes the
failure path as `if (found != count) { rollback; return false; }`. Its register
choice depends on GCC's numbering, so it sits directly after the constructor,
which is also its retail position.

`TrailMgr.h` gains the two method declarations (non-virtual; no layout
change). `Trail::Render` is bound to its retail Thumb address. No hint, inline
assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,514 function,
5,591 section and 181 region comparisons and no mismatch or skip.
