# NPC::isUnderCar exact match

```text
OK  _ZN3NPC10isUnderCarEv  0x002fde51  416 bytes
OK SECTION .npc_is_under_car  0x002fde50  416 bytes
```

Tests whether the NPC stands inside the last vehicle that hit it: it fetches
the vehicle's collision rectangle (inflated by 50) and checks the NPC's
position against all four edges with 2D cross products, returning false on the
first edge it lies outside.

The corner deltas and edge vectors are computed up front as `vector3d`
subtraction temporaries. Written as scalar or array locals, GCC's tree sinking
moved the later differences into their check blocks (440 bytes); retail keeps
them before the first test.

Declarations: `NPC.h` gains `isUnderCar()` and also `isHostileTo(LevelObject*)`,
a genuine retail method (0x002fe0e9) that is not yet defined. Adding only one
declaration changes the generated code of the already matched
`GameObjectManager::GetMetatypeFromName`, which depends on GCC declaration
ordering in that unit; with both declarations it is unchanged. This is a
compiler-order effect, recorded here because the second declaration was added
for that reason.

`Vehicle::getCollisionRect` is bound to its retail Thumb address. No hint,
inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,527 function,
5,604 section and 181 region comparisons and no mismatch or skip.
