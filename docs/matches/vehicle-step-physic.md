# Vehicle physics update

Vehicle::stepPhysic() at 0x003116dd matches its complete 1,536-byte native
Thumb function. The linked symbol is an executable STT_FUNC definition at the
original address, not an absolute-address import.

The function reconstructs vehicle position from the physics body and wheel
heights, derives normalized orientation axes, clamps angle inputs, applies the
original yaw/pitch/roll quaternion composition, updates the scene node and
records player driving, drifting and jumping distance. Normal components
preserve the native floating-point negation/addition operand order. Flattened
axes use ordinary vector copies followed by explicit Z resets, preserving the
native XY copy and Z-store order. No ordering barriers or register constraints
are used.

The licensed Irrlicht 1.4.2 clamp implementation is reused in Geometry.h.
Its const-reference parameters and min_/max_ selection reproduce the original
floating-point behavior. An unused crossProduct prototype from the worker's
private experiments is not introduced.

Adding the authentic SDK overload exposed a compile-time ambiguity with the
existing altered by-value Item clamp view. That existing view now has the
dedicated ItemScalarMath namespace; Item::add changes only its helper
qualification. Its complete function and all other Item comparisons remain
byte exact. No arithmetic or gameplay behavior is changed.

Final integrated validation:

```sh
python tools/build.py --all
```

Exit 0; all 9,751 function, section and region comparisons passed. This covers
all 187 existing Vehicle functions, its 112 sections and the complete current
Physics, Character, PlayerTest, NPC, controller and other header users. The
existing Radio inline-destructor warning remains; compilation and linking
succeed. The 84 unit tests and repository/progress checks run before the commit.
No branch hints or compiler-output edits are introduced.

```text
OK  _ZN4Item3addEv  0x002fca3d  352 bytes
OK  _ZN7Vehicle10stepPhysicEv  0x003116dd  1536 bytes
```
