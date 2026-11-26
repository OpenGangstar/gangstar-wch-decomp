# Vehicle::shoot exact match

`Vehicle::shoot()` matches all 1140 retail bytes at Thumb address
`0x00310909`, including relocations.

```text
OK  _ZN7Vehicle5shootEv  0x00310909  1140 bytes
```

## Source form

The function fires the vehicle's weapon: it checks the weapon and ammunition,
finds an attackable target, aims with a random deviation and fires either a
projectile or a gun ray, raising a player event for the shot.

Details that the retail bytes require, each commented in the source:

- **No-op write-backs in the aim block.** `source.Y` and `source.X` are
  stored back right after they are loaded. Each write-back adds a use that
  survives until local allocation, so the source Y value ranks above the
  aim sums and gets retail's register, while the sums are spilled to
  retail's stack slots. Postreload removes the stores, so they emit no code.
- **Early source X load.** Loading `source.X` before the deviation
  arithmetic lengthens its live range, which allocates the Z difference
  first, as retail does.

## Integration

The weapon, weapon-manager, player and ray-cast callees are bound as
external Thumb functions. The `EvPlayer` destructors and vtable that this
object now emits are placed at their retail addresses.
