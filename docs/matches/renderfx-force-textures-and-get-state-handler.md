# RenderFX::ForceTexturesToVRAM and MenuFX::GetStateHandler exact matches

`RenderFX::ForceTexturesToVRAM(bool, gameswf::player_context*)` matches all
256 retail bytes at Thumb address `0x003ece05`, and
`MenuFX::GetStateHandler(gameswf::character*)` matches all 142 retail bytes
at `0x003f01d1`, both including relocations.

```text
OK  _ZN6MenuFX15GetStateHandlerEPN7gameswf9characterE  0x003f01d1  142 bytes
OK  _ZN8RenderFX19ForceTexturesToVRAMEbPN7gameswf14player_contextE  0x003ece05  256 bytes
```

## Source form

`ForceTexturesToVRAM` walks every movie of a player context and lays out
each bitmap of its definition, optionally drawing it so that the texture is
uploaded. `GetStateHandler` walks from a character up its parents until it
finds one that is a registered state handler, clearing dead parent links on
the way.

Details that the retail bytes require:

- **Bitmap table view.** Both bitmap reads go through a file-local view of
  the bitmap table that uses array indexing. An array reference is expanded
  with the scaled index first, which gives retail's `ldr r0,[r4,r3]`; plain
  pointer arithmetic orders the table first.
- **Mangled names for the RenderFX method and static.** `RenderFX.h` does
  not declare `ForceTexturesToVRAM`, and `s_default_context` is private, so
  the function and the static are named by their mangled names.
- **Two views of the parent link.** In `GetStateHandler`, the parent null
  check and the read-back go through one view of the character fields, and
  a dead link is cleared through a second view. Because the clear is spelled
  differently, jump threading cannot forward the stored zero to the
  read-back, so the per-iteration state reloads stay in the loop as in
  retail.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other menufx.cpp functions keep their bytes.

## Verification

`python -B tools/build.py` passes for renderfx-animation,
ai-startup-menuwidget and ai-startup-menustate. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,618 function, 5,709 section
and 180 region comparisons and no mismatch or skip; the previous baseline was
5,616, 5,709 and 180.
