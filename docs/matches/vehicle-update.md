# Vehicle::Update exact match

`Vehicle::Update(int)` matches all 4,020 retail bytes at Thumb address
`0x00313b01`, including relocations. The four bytes of padding after it are
two `nop` halfwords in both builds.

```text
OK  _ZN7Vehicle6UpdateEi  0x00313b01  4020 bytes
```

## Source form

`Update` runs a vehicle's per-frame logic: fading and destruction after an
explosion, water and destroyed states, wheel and skid sounds, the repair
light, distance and speed bookkeeping, AI flags and the occupants.

Details that the retail bytes require:

- **Finished path in an else branch.** The explosion-finished handling is
  the `else` of an `if (!isSet(finished))` test, where `isSet` is an inline
  helper that returns the flag through a `const bool&`. Returning the flag
  directly avoids a join of constant values that jump threading would
  duplicate. With this layout, the finished path's GOT reload comes where
  retail has it in instruction order, so reload hands out the same spill
  registers.
- **Distance accumulators written in full.** Both distance accumulators add
  the full squared-length expression of the velocity, and the second
  subtracts the initial squared length. Temporary-expression replacement
  then keeps the expression in the first statement, which gives retail's
  local register allocation in that block.
- **Arm order.** In the third ternary of the `init980` update, the `-1.0`
  arm is written first, which gives retail's instruction order.
- **Alpha test.** The `alpha == 0` early return follows the `alpha < 255`
  block. This lowers the predicted frequency of the finished path, so block
  reordering places its trace after the other one, as retail does.
- **Branch hints.** Three documented `__builtin_expect` hints are needed for
  retail's block layout: the repair-light test, the `unknown506` to
  `unknown509` chain and the test for the player's vehicle.

No inline assembly, register constraint, output edit or header change is
used. The other Vehicle.cpp functions keep their bytes.

## Verification

`python -B tools/build.py vehicle-cleanup` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,611 function, 5,709 section
and 180 region comparisons and no mismatch or skip; the previous baseline
was 5,610, 5,709 and 180.
