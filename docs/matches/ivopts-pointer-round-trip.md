# MenuManager::tearDown and GS3DStuff::checkPickableProximity exact matches

Both functions match all their retail bytes, including relocations.

```text
OK  _ZN11MenuManager8tearDownEv  0x002e6149  300 bytes
OK  _ZN9GS3DStuff22checkPickableProximityERSt6vectorIP4ItemSaIS2_EE  0x002deba1  356 bytes
```

## Shared cause

In both functions the last mismatch was the operand order of one loop's
latch compare (`cmp r3,r6; bhi` instead of retail's `cmp r6,r3; bcc`, and
`cmp r3,r2; bls` instead of `cmp r2,r3; bcs`).

GCC's induction-variable optimisation rewrote the loop's `(unsigned)index`
use through a new SSA name, and dominator optimisation then put the lower
SSA version (the count) first. Compiling with `-fno-ivopts` gives retail's
compare, so retail's loop counter was not an analysable induction
variable.

## Source form

The loop increment is written as a pointer round trip:

```cpp
index = reinterpret_cast<int>(reinterpret_cast<char*>(index) + 1)
```

On this 32-bit target the conversions are no-ops, so the emitted
instructions are the same as `++index`. The C++ front end represents them
as `CONVERT_EXPR`, which GCC 4.2's scalar evolution does not follow
(`follow_ssa_edge_in_rhs`), so the counter is not recognised as an
induction variable and ivopts leaves the loop alone. The cast in the
compare then keeps its original low SSA version, giving retail's order. A
source comment explains the form in both files.

The rest of both bodies is unchanged from the earlier best candidates:
tearDown keeps its `extern "C"` mangled definition with a file-local field
view, and checkPickableProximity is placed after the `inRange` helper,
before `checkVehicleProximity`, which keeps that function's spill slots.
The six state-hook units that link the menu-manager object discard the new
tearDown section, since they do not place it.

Behaviour is unchanged. No branch hint, inline assembly, register
constraint, flag change, output edit or header change is used.

## Verification

`python -B tools/build.py menu-manager-helpers` and
`python -B tools/build.py gs3d-stuff` pass. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,646 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,644, 5,713 and 180.
