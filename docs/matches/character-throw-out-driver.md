# Character::throwOutDriver exact match

`Character::throwOutDriver(bool)` matches all 288 retail bytes at Thumb address
`0x002f4cf9`, and its strict section ends at the retail extent.

```text
OK  _ZN9Character14throwOutDriverEb  0x002f4cf9  288 bytes
OK SECTION .character_throw_out_driver  0x002f4cf8  288 bytes
```

## Source form

The function needs a vehicle with a driver.

1. It copies the vehicle's physics info to the character.
2. If the driver is the player, it stops the vehicle, plays the throw animation
   and stops the player's driving (state 14).
3. Otherwise it positions and shows the driver. Then, by side:
   - **Left:** it plays the throw and thrown animations and clears the driver.
   - **Right:** it positions and shows the character, opens the door from inside,
     ejects the driver and installs the character as the new driver.

The driver null test is written through a file-local `bool hasDriver(...)`
helper. A plain pointer test gets GCC's pointer heuristic, which places the
epilogue and assigns registers differently. `__builtin_expect` overshoots in the
other direction. The bool-valued test leaves only the call heuristic, which
reproduces retail's early epilogue and register assignment, as in
`RenderFX::Update`.

`Character` does not declare this member, and `vehicle`, `show()` and
`positionInVehicle()` are private. The function is therefore an `extern "C"`
definition of the retail mangled name. It uses a local field view and local
mangled declarations of the two retail callees. No header is changed, which
avoids the declaration-UID perturbation that headers such as `Character.h` cause
elsewhere.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,558 function, 5,641 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
