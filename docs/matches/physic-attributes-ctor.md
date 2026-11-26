# PhysicAttributes constructor exact match

`PhysicAttributes::PhysicAttributes(int, b2Body*)` matches all 260 retail
bytes at Thumb address `0x0031b29d`, including relocations. The
complete-object and base-object constructors share the same code.

```text
OK  _ZN16PhysicAttributesC1EiP6b2Body  0x0031b29d  260 bytes
```

## Source form

The constructor allocates the physic information array, clears the path
state, stores the body and claims the first free slot in the shared pool of
50 identifiers, creating the pool on first use.

Details that the retail bytes require:

- **Member store order.** The independent member stores are written in the
  order info, path length, path target, body, jump-shape flag, then
  `unknown116`. With the integer zero stored before the floating-point
  zero, their lifetimes overlap, so local allocation gives the integer zero
  r3 and the floating-point zero r2, as retail does. Reload and scheduling
  then give retail's order of the info and body copies. Of the 720 orders
  of these six stores, only this one gives retail's bytes.
- **Placement in the file.** The constructor is defined after the last
  function of `PhysicAttributes.cpp`, so it does not change the number of
  declarations seen before the already-matched functions.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other PhysicAttributes.cpp functions keep their
bytes.

## Verification

`python -B tools/build.py` passes for ai-startup-physicattributes,
ai-startup-character and ai-startup-playertest. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,610 function, 5,709 section
and 180 region comparisons and no mismatch or skip; the previous baseline was
5,609, 5,709 and 180.
