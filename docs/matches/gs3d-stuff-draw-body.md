# GS3DStuff::DrawBody exact match

`GS3DStuff::DrawBody(b2Body*, irr::video::SColor)` matches all 936 retail
bytes at Thumb address `0x002dc959`, including relocations.

```text
OK  _ZN9GS3DStuff8DrawBodyEP6b2BodyN3irr5video6SColorE  0x002dc959  936 bytes
```

## Source form

The debug routine draws each polygon shape of a Box2D body as 3D lines at the
player's height. Details that the retail bytes require, each commented in
the source:

- **Pointer start and loop shape.** The store pointer starts at
  `reinterpret_cast<float*>(points) + 1` and the loop is written so that the
  destination pointer is the induction variable with retail's exit test.
- **User labels.** Labels before the x and y stores split the loop body
  without emitting code, so the loop optimiser meets the y store first and
  picks retail's y-based pointer. `int j = i++;` followed by a label leaves
  only the increment in the loop header, which gives retail's preheader
  initialisation order.
- **Rotation values and stack slots.** `c3`, `c0` and `c1` are declared at
  function scope and first hold earlier values (the heights). Leaving SSA
  form then keeps those earlier values in the original variables and turns
  the rotation values into temporaries created after the spilled virtual
  call pointer, which is the slot order retail uses (c2 #48, call pointer
  #52, c3 #56, c0 #60, c1 #64).
- **Assignment order.** The preheader loads are assigned in retail's order,
  `py` before `px`.

## Integration

The units that link the GS3DStuff object place the function at its retail
address.
