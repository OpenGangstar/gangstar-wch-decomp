# Rocket::launch exact match

```text
OK  _ZN6Rocket6launchEN3irr4core8vector3dIfEE  0x00330015  744 bytes
OK SECTION .rocket_launch  0x00330014  744 bytes
```

Launches a rocket: copies its owner's physics info, records the start
position, reparents the scene node to the scene root keeping its transform,
orients it along the launch direction (or uses the node's left axis when the
direction is zero), creates a sensor circle body (radius from the rocket's
size, category 2, group from its pool index), links the body back to the
rocket, registers it with the object manager, sets its velocity and wakes it.

This continues the archived reconstruction (`nonmatching/combat/`), which
differed in its body and shape set-up:

- The body and circle definitions are the licensed Box2D 2.0.1 types now in
  `vehicles/VehicleBodyShapes.h` (also used by `Character::initPhysic`).
  As there, the zero damping and `isBullet` fields are written explicitly
  after construction, so dead-store elimination drops the constructor's copies
  and retail's store order results; `filter.maskBits` is also written
  explicitly, which gives retail's registers for the shape block.
- The velocity is built component-wise and the body's user data is stored
  through a fresh `body` read, both as in retail.
- `b2Body::SetLinearVelocity` and `WakeUp` are inline in Box2D; they are
  written as the field assignments they expand to, through the file's existing
  body views.

The Box2D definitions' weak destructors and vtables emitted by the unit are
placed at their retail addresses. Retail-only callees are bound to retail
Thumb addresses and `__aeabi_fcmpeq` to its PLT entry. No header change,
hint, inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,537 function,
5,619 section and 181 region comparisons and no mismatch or skip.
