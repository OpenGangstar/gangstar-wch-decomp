# Vehicle pointer-comparison controls: still unmatched

These two independent, unapplied patches preserve improved reconstructions of
`Vehicle::disable()` and `Vehicle::OnDespawn()`. Each retains the complete
accepted Vehicle translation unit and appends only its own pending function
and required includes. Do not apply both patches together or treat them as
accepted matching source. Their assembly markers remain unchanged.

| Function | Retail address | Function and input section | Remaining differing bytes |
| --- | --- | ---: | --- |
| `Vehicle::disable()` | Thumb `0x00310fa9` | 416 | `0x4a`, `0x54` |
| `Vehicle::OnDespawn()` | Thumb `0x00310e75` | 308 | `0x7e`, `0x88`, `0xec` |

The explicit `static_cast<const LevelObject*>(this)` comparison against
`lastHitVehicle` corrects one previous CMP operand byte in each function.
Vehicle has a genuine public, nonvirtual LevelObject primary base. The cast
preserves object identity; no field declaration, layout, calling convention,
compiler option or existing function is changed. The remaining comparisons
against `unknown368` and `unknown312` still emit opposite CMP operand order.
Equivalent equality behavior is not byte identity.

Each control was compiled once with the established GCC 4.2.1 owning profile,
assembled normally and linked with strict native start/end/extent assertions
and ordinary section-overlap rejection. Both retain all 193 existing function
and 117 section/region comparisons, including the accepted destructor, vtable
and complete GOT region. Off-target allocated object payloads, definitions,
imports and semantic relocations pass the recorded preservation gates.
The coordinator independently reparsed both actual linked images and repeated
every owning selector and complete target comparison.

Exact function comparison output:

```text
MISMATCH  _ZN7Vehicle7disableEv  0x00310fa9
  expected : 71 e0 b8 22 52 00 b3 58 ab 42 4b d0 9c 22 52 00
  actual   : 71 e0 b8 22 52 00 b3 58 9d 42 4b d0 9c 22 52 00
  differs at 0x4a

MISMATCH  _ZN7Vehicle9OnDespawnEv  0x00310e75
  expected : 49 d0 b8 22 52 00 ab 58 a3 42 30 d0 9c 22 52 00
  actual   : 49 d0 b8 22 52 00 ab 58 9c 42 30 d0 9c 22 52 00
  differs at 0x7e
```

Both complete target sections also fail. The accompanying JSON records full
linked target hashes, source/patch hashes and all differing offsets. These
patches preserve source, not the private placement/verification harness: a
normal existing profile does not select these pending functions. Reproduction
requires adding the actual native target section, its full-section check and
validated external Thumb callees in an isolated verification configuration,
and removing the newly defined function from fallback bindings. Passing only
the existing owning selectors must not be reported as a target match.

## Rejected follow-up and compiler evidence

One ordinary local `LevelObject* const self = this` control in OnDespawn,
used only in the remaining two source comparisons, reproduces the identical
308-byte near miss and all 193/117 existing matches. No alias variant followed.
The corresponding disable alias was proposed but not compiled after this
negative family evidence; it is not included in either patch.

GCC 4.2.1 frontend operand canonicalization prefers declaration operands on the
right, motivating the local-variable hypothesis. However, `const` alone does
not prove early initializer substitution: `constant_value_1` also requires a
constant initializer. The unchanged output does not establish which pass
eliminated this runtime-this alias. No alias compiler dump was run and no
original field type or source spelling has been recovered from that result.
Do not infer permission for qualifier, integer-cast, helper or flag grids.

All controls remain unmatched. No Matched, Fully Linked or fuzzy progress is
added, no generated catalogue row is hand-edited, and no game data or compiler
output is included in these artifacts.
