# PhysicAttributes::GetHeight exact match

`PhysicAttributes::GetHeight(irr::core::vector3d<float> const&, int, bool)`
matches all 248 retail bytes at Thumb address `0x0031ff49`, including relocations.

```text
OK  _ZN16PhysicAttributes9GetHeightERKN3irr4core8vector3dIfEEib  0x0031ff49  248 bytes
```

## Source form

The body follows the retail instruction sequence:

1. If the slot's cached height is the `999999.0f` sentinel, it seeds the cached
   position.
2. It clears the slot's `unknown60` flag.
3. For an active slot (`unknown4 != 0`), it adds 4 to `s_currentUsed` and queries
   the detailed `GetHeight(int, ...)` overload.
4. A valid height stores the position. Where a jump shape exists, the larger
   jump height wins: slot 0 first resets `unknown116`. The function then
   returns the stored height.
5. Every other path returns the cached height.

Neither `GetHeight(int, vector3df const&, bool, bool)` nor
`GetJumpHeight(vector3df const&, int)` is declared in `PhysicAttributes.h`.
Both are called through local `extern "C"` declarations of their mangled names,
so no header changes. Both callees are bound as Thumb functions in the
manifest.

### Documented branch hint

The active-slot test is written as
`if (__builtin_expect(info[slot].unknown4 != 0, 1))`. The maintainer
clarification of 2026-10-25 allows `__builtin_expect` when it is documented. The
hint makes the inactive-slot return share the final return block, as it does in
retail. Every memory access and call is the same as in retail.

Without the hint, the same source gives a 244-byte function with 173 unmasked
differing bytes.

### Placement in the file

The definition sits before `FindLowerCostNode` in `PhysicAttributes.cpp`.
Appending it at the end of the file left GetHeight exact, but changed a register
tie in the already-matched `FindLowerCostNode` (192 bytes grew to 196). With
`-ffunction-sections` and an explicit linker placement, the position in the
source file does not affect the linked layout.

No inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py ai-startup-physicattributes` passes every function and
section check of the unit, including the strict 192-byte `FindLowerCostNode`
assertion. A fresh complete build, `python -B tools/build.py --all`, exited 0
with 5,570 function, 5,653 section and 181 region comparisons and no mismatch
or skip; the previous baseline was 5,569, 5,652 and 181.
