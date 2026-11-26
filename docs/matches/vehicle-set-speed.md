# Vehicle::setSpeed exact match

`Vehicle::setSpeed()` matches all 872 retail bytes at Thumb address
`0x0030bccd`, including relocations.

```text
OK  _ZN7Vehicle8setSpeedEv  0x0030bccd  872 bytes
```

## Source form

The function sets the vehicle's speed from the lane count of its current
road triangle, applies the velocity to the three collision bodies, then
recomputes the lane index along the road edge and clamps it to the lane
count.

The structure matches without hints, but the result is 880 bytes because
`this` and the mesh buffer get each other's registers. Two documented
branch-likelihood hints fix this:

- **`if (__builtin_expect(unknown240 == 6, 0))`.** The speed-computing arm
  uses `this` once more than the other arm. Weighting it raises `this`
  above the mesh buffer in global allocation, so `this` takes r7 as in
  retail. The later `unknown24` test keeps its natural prediction, so the
  heightmap GOT pseudo still ranks ahead of the PIC base.
- **`setSpeedFloor`.** A local copy of `irr::core::max_` with the
  "below the floor" branch hinted unlikely. With only the first hint, the
  floor block's frequency is higher than the `unknown240 == 6` block's and
  is placed before it (872 bytes, 28 bytes differing). This hint restores
  retail's block order.

Comparison output for the hint forms (probe builds; the final form is also exact in the vehicle-cleanup unit):

| Form | Size | Result |
|---|---|---|
| No hints | 880 | `this`/mesh buffer registers swapped |
| First hint only | 872 | 28 bytes differ (block order) |
| Floor hint only | 880 | registers swapped |
| Both hints | 872 | exact |
