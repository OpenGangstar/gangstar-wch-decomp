# CustomBillboardSceneNode::OnAnimate exact match

```text
OK  _ZN24CustomBillboardSceneNode9OnAnimateEj  0x002f800d  704 bytes
OK SECTION .billboard_on_animate  0x002f800c  704 bytes
```

Orients a visible billboard towards the camera: it builds the right/up/forward
basis from the billboard and camera positions, writes it into a rotation
matrix, sets the node's rotation from that matrix, then animates its
children (through the billboard parent or the base scene-node animation).
It records the animation time in every case.

The archived body (`nonmatching/rendering/_ZN24CustomBillboardSceneNode9OnAnimateEj.cpp`)
returned early when invisible, storing the time in that early-return path as
well. That extra store took the first reload register, so reload's round-robin
choice put the later 0.0f/1.0f constants in r3/r2 instead of retail's r2/r3
(13 differing bytes). Wrapping the body in `if (isVisible()) { ... }` with a
single trailing `unknown520 = time;` lets reload process that store last;
bb-reorder still duplicates the small return block, so the layout is
unchanged.

The thunk verification image now includes the matched canonical source only,
and the main unit also places the this-adjusting thunk. Camera-manager callees
are bound to retail Thumb addresses and the soft-float helpers and `memset` to
their PLT entries. No header change, hint, inline assembly or register
constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,535 function,
5,616 section and 181 region comparisons and no mismatch or skip.
