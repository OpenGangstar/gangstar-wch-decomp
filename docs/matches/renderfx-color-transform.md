# RenderFX color transform

The third bounded source form matches all 456 native bytes:

```text
OK  _ZN8RenderFX17SetColorTransformEPN7gameswf9characterEjj  0x003ecf05  456 bytes
```

It preserves the null check, native cxform construction, unsigned-byte RGBA
extraction, float conversion, multiplication-channel division by 255.0f,
addition channels and all eight existing finiteColor calls. The 32-byte value
is copied to the existing character layout and its color flag is set.

An ordinary TU-local inline helper expresses that final game-object copy.
It emits no standalone function; object inspection confirms no hidden support
body. The real engine cxform constructor remains an undefined native import.
Only its genuine declaration is added to the existing layout. No new fields,
engine implementation, hints, register constraints or output edits are used.
The first two exact-size candidates had different store scheduling and receive
no credit. Complete comparison proves the final source, not partial similarity.

All three images retain and compare the compiled target at its original address.
Stale imports of that now-compiled target are removed; real constructor Thumb
metadata and unsigned-float/divide PLTs preserve native calls. The named color
overload and existing SetAlpha remain exact. Previously accepted string setter,
coordinate helper and mouse callback are included in this coherent root build.

Coordinator graph: 4 profiles, 851 passing function/section/GOT comparisons,
exit zero. Proof: _scratch/renderfx-color-root.log and .exit. No existing function
body, shared header or Windows source changes.
