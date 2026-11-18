# ASprite canonical table getters

Four accessors reuse ASpriteData's recovered Anim, Frame, FModule and Module
records. Ordinary typed pointer arithmetic produces the original ARM Thumb
instructions without compiler hints, flag changes or output modification.

SpriteBounds retains its identical four-int layout in a shared header.
ASpriteData no longer includes ASprite, allowing ASprite to expose the actual
ASpriteData::Anim return type without a circular include. Existing observer
types and runtime record layouts remain unchanged.

The existing matched Cash::drawCash body was changed: its first loop counter
now has loop scope. The counter is not used after that loop. With the canonical
sprite header, the previous declaration emitted 328 rather than 332 bytes;
the scoped declaration restores the complete original function. This change
adds no matching credit. Private baseline, header-extraction and compatibility
checks preceded integration; the integrated full gate then passed.

`python tools/build.py --all` exited 0: 183 profiles, 10,274 successful
function, section and region comparisons, including every existing comparison.
Relevant output, copied verbatim:

```text
OK  _ZNK4Cash8drawCashEiPKiRii  0x00327a71  332 bytes
OK  _ZNK7ASprite7GetAnimEi  0x003497e5  16 bytes
OK  _ZNK7ASprite8GetFrameEi  0x003497f5  16 bytes
OK  _ZNK7ASprite10GetFModuleEi  0x00349c85  14 bytes
OK  _ZNK7ASprite9GetModuleEi  0x00349815  16 bytes
```

All four definitions occupy their retail executable addresses. Native Thumb
imports for the three formerly imported getters were removed when their C++
definitions became available. This family adds four matched functions and
62 bytes; incomplete ASprite compilation-unit completion remains uncredited.

PaintFModule and PixelInfo candidates remain uncredited: respectively 220
bytes with differing instructions and 300 bytes against the native 296.
No candidate bodies or diagnostic compiler flags from those investigations
are integrated.
