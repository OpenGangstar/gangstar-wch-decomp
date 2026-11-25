# NPC::isOutsideSearchRadius and PhysicAttributes::IsPositionOnJump exact matches

```text
OK  _ZN3NPC21isOutsideSearchRadiusEv  0x002fd565  172 bytes
OK SECTION .npc_outside_search_radius  0x002fd564  172 bytes
OK  _ZN16PhysicAttributes16IsPositionOnJumpERKN3irr4core8vector3dIfEE  0x0031a67d  128 bytes
OK SECTION .physic_position_on_jump  0x0031a67c  128 bytes
```

- `NPC::isOutsideSearchRadius` is true for a searching NPC (category 5) whose
  position's squared distance from its search origin exceeds the stored
  squared search radius.
- `PhysicAttributes::IsPositionOnJump` is true when a jump shape is set and the
  point's squared distance from the shape centre (`jumpVertices[4]`) is below
  90000.

Both use the same source idiom:

```cpp
bool flag = false;
if (!(distanceSquared < limit))
    flag = true;
return !flag;
```

With soft-float and NaNs honoured, GCC 4.2.1 cannot invert the comparison, so
this keeps retail's helper (`__aeabi_fcmplt` / `__aeabi_fcmpgt`) with an
inverted branch, the zero set before the call, the out-of-line `flag = true`
block and the final `eor`/zero-extend. Returning the comparison directly
either selects a different helper (`fcmpge`) or folds the double negation
(97 and 20 differing bytes respectively in the earlier attempts).

`NPC.h` and `PhysicAttributes.h` each gain the method declaration
(non-virtual; no layout change). No hint, inline assembly or register
constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,518 function,
5,595 section and 181 region comparisons and no mismatch or skip.
