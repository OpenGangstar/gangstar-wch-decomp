# Vehicle::ResetBodyPosition exact match

`Vehicle::ResetBodyPosition()` matches all 792 retail bytes at Thumb address
`0x0030b68d`, including relocations.

```text
OK  _ZN7Vehicle17ResetBodyPositionEv  0x0030b68d  792 bytes
```

## Source form

The function places the vehicle body and its four wheel bodies from the
vehicle's position and rotation, using a `b2Vec2`-returning rotation helper
for the wheel offsets.

Details that the retail bytes require, each commented in the source:

- **No-op write-backs.** `rear.X` and two wheel-offset X values are stored
  back right after they are loaded. The extra uses break local-allocation
  priority ties and set the reload order retail uses; postreload and flow
  remove the stores, so no code is emitted for them.
- **Alias views.** `bodyOffset` is written as a `Vehicle` member and the
  offsets at 604-616 through the wheel view. These spellings give the
  scheduler the alias information that produces retail's load and store
  order.
