# Character::show and Character::positionInVehicle exact match

`Character::show()` and `Character::positionInVehicle(bool)` match all retail
bytes, including relocations.

```text
OK  _ZN9Character4showEv  0x002f4659  600 bytes
OK  _ZN9Character17positionInVehicleEb  0x002f4a79  640 bytes
```

## Source form

**`show()`** sets the visibility flag and makes the scene and shadow nodes
visible. For a non-player character in a vehicle it also:

1. copies the vehicle position;
2. sets the rotation to the vehicle orientation turned a quarter turn about Z;
3. places the collision body beside the driver's or passenger's door. The
   door point is offset along the vehicle's right axis (111 or 118, depending
   on the vehicle's height) and its front axis (11 or 21).

It then moves the character from its object list to the game object manager.

**`positionInVehicle(bool)`** computes the same door point. It applies the
quarter-turn rotation only for the passenger side. Players have their position
set directly; anyone else has their collision body moved.

### Operand order

Earlier reconstructions differed in 10 and 12 bytes: the operand order of the
last offset multiplications and the order in which the two offset constants
are loaded. GCC 4.2.1 orders commutative operands by SSA version.

- **Plain `float` offset.** Passed by reference to a helper, it is renamed
  late (alias analysis) and receives a high version.
- **Component of a `vector3d` local** (`offset.Y`, or `right.X` and
  `front.X`). This is scalarised by SRA after dead-code elimination. Its PHI
  then takes a lower name, and the two PHIs are created in declaration order.

Holding the offsets as vector components reproduces both the multiplication
order and the constant-load order in retail. In `positionInVehicle`, the result
vector is declared after the height branch. Declaring it earlier moves its zero
initialisation above that branch.

All 107 previously matched functions of the unit keep their bytes. No branch
hint, inline assembly, register constraint or output edit is used, and no
header change.

## Linking

Both sections are placed in the shared `CharacterRecoveredSections.ld`. The NPC
and PlayerTest units also link the character object, and their scripts would
otherwise discard the sections. The two symbols are no longer bound
externally in those units.

## Verification

`python -B tools/build.py` passes for ai-startup-character, ai-startup-npc and
ai-startup-playertest. A fresh complete build, `python -B tools/build.py --all`,
exited 0 with 5,579 function, 5,663 section and 181 region comparisons and no
mismatch or skip; the previous baseline was 5,577, 5,661 and 181.
