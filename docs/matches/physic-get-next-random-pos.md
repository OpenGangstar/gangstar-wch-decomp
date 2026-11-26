# PhysicAttributes::GetNextRandomPos exact match

`PhysicAttributes::GetNextRandomPos(int, int, irr::core::vector3d<float>)`
matches all 1748 retail bytes at Thumb address `0x0031cf75`, including
relocations.

```text
OK  _ZN16PhysicAttributes16GetNextRandomPosEiiN3irr4core8vector3dIfEE  0x0031cf75  1748 bytes
```

## Source form

The function picks the next road or sidewalk position for an AI walker: it
finds the nearest edge of the current triangle, walks the neighbour tables
with a random start, skips wrong-way edges, and falls back to a random
sidewalk destination when nothing is found.

Details that the retail bytes require, each commented in the source:

- **Byte-offset load.** In the side branch, `side * 4` is computed first and
  used as a byte offset into the neighbour row, which gives retail's address
  operand order.
- **Declaration orders.** The loop variables (`i`, `wrapped`, `chosen`, the
  first-loop `i` before `best`, and the j-loop `oldTri`/`oldBuffer`) are
  declared in the orders that give retail's SSA numbering.
- **Wrong-way helper.** The random loop's wrong-way test goes through a small
  inline that compares `side + 1` with the table entry before loading it.
- **Dead scoped temporaries.** Four dead `int` scopes at the top and two dead
  vector copies in the random loop change only SSA naming. They give
  retail's loop merge order and compare operand order and emit no code. An
  unused inline helper must also stay, because removing it changes the
  numbering.
- **Fallback first.** The sidewalk fallback is tested before the mode-1
  default edge. That block order sets the reload pass's register rotation to
  retail's.

## Integration

The NPC and PlayerTest units place the function, `GetRandomDestination` and
`GetTriCenter` at their retail addresses and provide the run-time helper
addresses they now reference.
