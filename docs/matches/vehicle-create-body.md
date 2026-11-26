# Vehicle::CreateBody exact match

`Vehicle::CreateBody()` matches all 1044 retail bytes at Thumb address
`0x0030fac9`, including relocations.

```text
OK  _ZN7Vehicle10CreateBodyEv  0x0030fac9  1044 bytes
```

## Source form

The function creates the vehicle's Box2D body: a polygon hull, two circle
caps and a sensor, then sets the transform and mass and creates the wheels.

Details that the retail bytes require, each commented in the source:

- **Repeated restitution stores.** `frontCap.restitution = 0.0f;` and
  `rearCap.restitution = 0.0f;` repeat the constructor's stores. The extra
  uses give the float-zero value retail's allocation priority; postreload
  removes the stores.
- **Union dead stores.** The body-definition view puts the mass and angle
  fields in unions with `int` members, and the constructor starts with dead
  integer stores to them. These create the shared constant 1 before the bool
  stores and hold the CSE instruction count at the value that gives retail's
  spill slots for the caps. Flow removes them.
- **Statement order.** The bool flags, hull vertex count and cap fields are
  assigned in the orders that give retail's scheduling, and the explicit
  user-data stores are left to the constructors.
