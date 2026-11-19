# Header declarations can change matching code

This is a compiler diagnostic, not a new match or a proposed source fix.
The existing matched functions, shared headers and production options remain
unchanged. It explains why declaration-only prerequisites need native checks.

## Controlled observation

At source context `32ef85f0`, adding the genuine release-mode Irrlicht const
array accessor was the only changed native input:

```cpp
const T& operator[](unsigned int index) const { return data[index]; }
```

The layout, existing non-const accessor and all function bodies were unchanged.
Nevertheless, the complete ARM gate rejected
`WeaponManager::getKeepWeaponsWhenBustedCost()` at Thumb `0x00331a09`:

| Context | Function bytes | Literal-pool offset | Result |
| --- | ---: | ---: | --- |
| Accepted baseline | 264 | 248 | Existing native match |
| Added const declaration | 260 | 244 | Function and full-section mismatch |

The rejected prerequisite also skipped its two dependent profiles, weapon and
save-game. It was never integrated. Comparing every source, configuration and
tool input independently confirmed that Array.h was the only difference.

## Diagnostic output identity

Two unchanged-source compiles used the original NDK 1.6r1 GCC 4.2.1 frontend,
assembler and configured weapon-manager options, adding only diagnostic
`-fdump-tree-all -fdump-rtl-all`. Each produced an object **byte-identical in
its entirety** to its corresponding pre-diagnostic object. The dumps therefore
describe the observed code, rather than a different diagnostic code generation.
Each context produced 116 numbered tree/RTL dump files.

Raw target object SHA256:

```text
baseline  d8edf4ffb91f42d0232d841c15d1005986576583987ba88c718c31f62e57e71a
const     eaa0d9a96c1f188b4a13979d347af54f120c7f566a6e4f727f70f8d7e5ecb561
```

These are object-section identities, not an assertion that unlinked bytes are
the retail bytes. The baseline's linked/native proof is separate.

## Where the difference appears

The extra declaration advances relevant declaration identifiers by eight;
for example, the `this` parameter changes from UID 8831 to 8839. The SSA dump reverses the
ordering of the loop-index and total PHIs. After bijective temporary/SSA-name
normalization and treating PHI-list order as unordered, the function bodies
remain equivalent through `098t.uncprop`.

The first resulting statement-order difference appears in `099t.optimized`
after SSA destruction:

```cpp
// Accepted context:
total = 0;
i = 0;

// Rejected context:
i = 0;
total = 0;
```

The complete assembly difference, apart from label numbering, is:

```diff
 mov r7, #0
+mov fp, r7
 ldr r3, [r4, r3]
 add r5, r3, #4
-mov r3, #0
-mov fp, r3
```

One Thumb instruction disappears. Two alignment bytes also disappear before
the same 16-byte literal pool, accounting for the four-byte size difference.
This changes matching bytes without changing the function's behavior.

Upstream GCC 4.2.1 provides a consistent mechanism: referenced variables are
looked up using declaration identifiers, PHIs are inserted by iterating that
table, and pending constant copies are emitted in stack order. See
[tree-dfa.c](https://github.com/gcc-mirror/gcc/blob/releases/gcc-4.2.1/gcc/tree-dfa.c),
[tree-into-ssa.c](https://github.com/gcc-mirror/gcc/blob/releases/gcc-4.2.1/gcc/tree-into-ssa.c),
and [tree-outof-ssa.c](https://github.com/gcc-mirror/gcc/blob/releases/gcc-4.2.1/gcc/tree-outof-ssa.c).
The Android frontend's complete patch identity was not established; this
upstream explanation is an inference supporting the directly observed dumps.

Do not add dummy declarations, change production options or edit compiler
output to exploit this sensitivity. Recovered interfaces need independent
preservation checks, even when they add no fields or executable helpers.

One bounded octree const-SDK context check was justified by this evidence. It
still emitted exactly the previous 616-byte candidate against native 620,
with identical raw bytes. It stopped before linking and received no credit.
