# PhysicAttributes::GetJumpHeight exact match

`PhysicAttributes::GetJumpHeight(vector3d<float> const&, int)` matches all 596
retail bytes at Thumb address `0x0031a6fd`, including relocations.

```text
OK  _ZN16PhysicAttributes13GetJumpHeightERKN3irr4core8vector3dIfEEi  0x0031a6fd  596 bytes
```

## Source form

`GetJumpHeight` checks whether a point lies inside a jump shape's triangle,
using edge cross products. If it does, it interpolates the height at the
point from the triangle's vertices and counts the hit.

Details that the retail bytes require:

- **Loop cross products.** These use same-variable assignments, such as
  `ex *= dy;`, `dx = ey * dx;` and `float ey = b.Y; ey -= a.Y;`.
  - Out-of-SSA's temporary expression replacement (TER) does not substitute
    a value into a statement that defines the same root variable. These
    forms therefore keep the edge and point terms, and the `b.Y` load, in
    retail's order.
  - Writing `dx *= ey` instead gives the wrong multiply operand order.
- **Interpolation.** It reads the jump vertices through a file-local
  `JumpShapeView`, a second view of the public `jumpVertices` at `+52`.
  - The tree-level redundancy passes do not merge these reads, so vertices 1
    and 2 are reloaded after the divide, as in retail, while RTL CSE still
    shares vertex 0.
  - `v` is computed before `u`, and the hit counter is incremented after
    them.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other PhysicAttributes.cpp functions keep their
bytes.

## Verification

`python -B tools/build.py ai-startup-physicattributes` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,605 function, 5,709 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,602, 5,706 and 180.
