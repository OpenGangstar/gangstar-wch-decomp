# PlayerTest::move exact match

`PlayerTest::move(float, float)` matches all 2496 retail bytes at Thumb
address `0x003026b9`, including relocations. The other sections of
`PlayerTest.cpp` are unchanged.

## Source form

The function steers the test player from the analog direction and magnitude.
It picks the walk, run or stop animation, turns the character relative to the
camera side vector, and updates the scene node rotation. Details that the
retail bytes require, each commented in the source:

- **Turn region.** The three turn arms (`dot > 0.1`, `dot < -0.1`, middle)
  are reached through labels.
  - `greater == 0` compares an int flag against zero, which makes the second
    comparison the then-edge of the first test. The code is the same.
  - The `dot < -0.1f` test is a flag copied through a local struct inside a
    statement expression. This places both remaining turn arms after the
    `-0.1` arm, as in retail.
- **Frequency hints.** Each turn arm ends with tests of `canInterrupt` that
  jump to `turnLess`, `turnMid`, `walkEntry` or `runEntry`. `canInterrupt` is
  known to be true at that point, so dominator optimisation folds the tests
  and they emit no code. They only adjust block frequencies for the block
  reorder pass.
- **Other hints.** The struct-copied flag tests in the animation selection
  and the walk/run entry labels carry over from the earlier `w3zgf` G10
  candidate.

## Linking

The unit places `.text._ZN10PlayerTest4moveEff` at `0x003026b8` and provides
the libm PLT entries `atan2f`, `sinf`, `cosf` and `sqrt`. The Thumb callee
`LevelObject::GetFront` is bound in `external_thumb_functions` so the call is
emitted as `bl`.
