# Character::die and PlayerTest::isFacingTarget exact matches

```text
OK  _ZN9Character3dieEb  0x002f2d95  324 bytes
OK  _ZN10PlayerTest14isFacingTargetEv  0x003025cd  184 bytes
```

`PlayerTest::isFacingTarget` reuses the matched `Character::isFacingTarget`
form: planar direction to `_GetTarget()`, planar front, both normalized, and a
dot product above 0.9.

`Character::die` writes the animation guard as a positive `&&` chain, which
avoids the `iftmp` temporary that let DOM jump threading duplicate the flag
test and lose CSE of the zero argument. The two death animations then test
`!(movementFlags & 0x08000000)` first. One permitted branch-likelihood hint,
`__builtin_expect(..., 0)` on that test, places the animation-175 arm after
the animation-86 arm as retail does; without it the arms' layout is swapped
(three differing bytes). Every call and memory access is unchanged. Character
dependents no longer bind `Character::die` externally.

## Verification

Both owning units and their dependents pass every function and section check.
python -B tools/build.py --all exited 0 with 5,476 function, 5,509 section and 181 region comparisons and no mismatch or skip.
