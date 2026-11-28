# Vehicle::step exact match

`Vehicle::step()` matches all 4372 retail bytes at Thumb address `0x0030c035`,
including relocations. The other sections of `Vehicle.cpp` are unchanged.

## Source form

The function advances the vehicle's physics each frame. It updates the wheels,
velocity, ground contact and orientation, then positions the exterior node.
Details that the retail bytes require, each commented in the source:

- **Exterior rotation.** The pitch argument is written as
  `(pitch = -rotationX, basisY.X = basisY.X, pitch)`.
  - **Separate registers.** Because the negation's operand is a memory
    reference, GCC's bit-negation expansion turns the load into an integer
    word load into a subreg of `pitch`. local-alloc only ties registers of
    compatible mode classes, so it never ties that load with `-pitch`. The
    loaded value then gets `r3` and the negated pitch `r1`, as in retail.
  - **No-op write-back.** `basisY.X = basisY.X` keeps `-rotationX` in the
    `pitch` variable instead of being substituted into the call argument, so
    pseudo numbering is unchanged. Expansion drops the write-back, so it emits
    no code.
- **Other hints.** The wheel blocks, ground reads and other `basisY.X`
  write-backs carry over from earlier candidates (`w3zdh`, `w3zed`).
