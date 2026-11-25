# PlayerTest::updateAnim exact match

`PlayerTest::updateAnim(float)` matches all 132 retail bytes at Thumb address
`0x00303fe9`, including relocations.

```text
OK  _ZN10PlayerTest10updateAnimEf  0x00303fe9  132 bytes
```

## Source form

`updateAnim` updates the base character animation. When the player stands on
a cliff, it then pushes the collision body away by five times the cliff
vector.

Details that the retail bytes require:

- **Velocity reads.** The body velocity is read into named `velocityY` and
  `velocityX` locals, Y first. They then build a `b2Vec2`. The inlined
  constructor splits the tree block, so TER does not fold the loads into the
  add. Reading Y first gives retail's local-alloc register choice.
- **Base call.** `Character::updateAnimation` is called through an
  `extern "C"` declaration of its mangled name. Declaring it in `Character.h`
  changes `ServiceCarRental::Notify` in ai-startup-menustate.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. `PlayerTest::Update` and `PlayerTest::switchContext`
remain exact.

## Verification

`python -B tools/build.py ai-startup-playertest` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,609 function, 5,700 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,607, 5,698 and 181.
