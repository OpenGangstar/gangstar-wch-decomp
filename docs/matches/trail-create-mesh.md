# Trail::CreateMeshSceneNode

`Trail::CreateMeshSceneNode()` at Thumb address `0x00348cfd` matches all 500
retail bytes, including the complete linked section at `0x00348cfc`.

The reconstruction preserves vertex and index allocation, the six-index segment
pattern, mesh-buffer reference ownership, scene-manager attachment and material
configuration. The required vertex, buffer and mesh views assert native sizes
36, 196 and 92 bytes. The original engine constructors remain imported retail
functions; their implementations receive no game matching credit. A translation-unit-local
scene-manager prefix view names the observed mesh-factory virtual slot without
adding or shifting any virtual entries. A shared-header declaration control
changed an existing WeaponManager function, so that shared change was rejected.
The final implementation leaves the shared scene-manager declaration unchanged.

The final compiler discrepancy was four bytes: two independent loop initializer
instructions appeared in the opposite order. Compiler dumps located the order
before RTL expansion, in the induction-variable and SSA transformations.
Computing the narrow vertex index from the existing loop counter removed an
independent mutable recurrence and produced the exact original bytes:

```cpp
const unsigned short vertex =
    static_cast<unsigned short>((static_cast<unsigned int>(i) - 1u) * 2u);
```

At every reached iteration this equals the former vertex recurrence modulo
65536. The unsigned arithmetic is defined, the final narrowing preserves wrap,
and the removed local has no address or observable post-loop use. Store order,
other induction variables, compiler flags and existing function bodies remain
unchanged. No inline assembly, register constraints, barriers or compiler-output
modification are used.

The canonical verification build prints:

```text
OK  _ZN5Trail19CreateMeshSceneNodeEv  0x00348cfd  500 bytes
OK SECTION .trail_mesh  0x00348cfc  500 bytes
```

The linker asserts the exact 500-byte extent and its end immediately before
`Trail::Init`. The canonical profile retains retail imports for the other
pending functions rather than including their unmatched candidates.

The historical nonmatching packet remains a record of the earlier four-byte
miss. Its reproduction now reads its frozen reference selectors, so accepting
this function does not silently change the historical expected checks.

The final coordinator gate rebuilt all 191 ARM profiles: 5,447 function,
5,356 complete-section and 181 region comparisons passed (10,984 total).
All 1,095 frozen inputs remained unchanged during the run. The earlier shared
header attempt failed an existing WeaponManager function and skipped two
consumers; it was not accepted as a successful gate. The successful final run
used the local factory view and rebuilt every profile.

A separate catalogue audit found direct exact comparisons for all 4,285 matched
game entries, with no gaps. All 102 unit tests, repository checks, generated
progress checks and whitespace checks pass. Progress increases by one function
and 500 bytes to 350,518/561,716 bytes (62.40%). Trail still has two pending
functions, so Fully Linked remains 114,548 bytes (20.39%, 126/203 units).
