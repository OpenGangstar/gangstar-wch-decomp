# Trail mesh candidate: four bytes unmatched

This is an unapplied diagnostic packet. All three pending Trail methods remain
unmatched. No progress credit or assembly-marker deletion accompanies it. Keep
`profile-reference-NONMATCHING.json` outside the active profile directory.

The source and narrow header patch preserve accepted definitions and layouts.
Restricted mesh views have verified sizes: vertex 36 bytes, mesh buffer 196 bytes,
and mesh 92 bytes. Constructors are genuine retail imports; their implementations
are neither reconstructed nor credited. No proprietary binaries or tools are
included. Compiler IR excerpts and comparison logs are diagnostic evidence, not
modified output consumed by the build.

| Candidate | Compiled / retail bytes | Result |
| --- | --- | --- |
| Update | 320 / 324 | Unmatched |
| BuildPoint | 760 / 812 | Unmatched |
| CreateMeshSceneNode | 500 / 500 | Four differing bytes at offsets 0x46–0x49 |

The mesh mismatch swaps two independent initialization instructions. All other
mesh bytes match, including literal pools. The same image preserves all 16
accepted function selections, six support regions including the GOT, and the
24-byte UV table. Short pending definitions remain compiled at their native
starts within their envelopes; they are not discarded, padded or replaced by
retail fallbacks. There is no whole-unit completion claim.

The archived declaration-order variant produced identical bytes. Diagnostic-only
tree/RTL dumps also preserve the function bytes and relocation targets. They
bracket the ordering change before RTL expansion: IV optimization rewrites the
induction PHIs; the optimized non-SSA preheader already initializes the vertex
before the derived index. This rules out blaming a later RTL scheduler and does
not identify the original source spelling. Further work requires new evidence.

## Reproduce in private output

Use the matching toolchain described in [BUILDING.md](../../../docs/BUILDING.md).
Set these environment variables, then run `python reproduce.py` from this folder:

- `REPO_ROOT`: the checkout containing the existing Python verification tools.
- `GAME_TOOLS_ROOT`: a directory containing the configured `toolchain/` tree.
- `RETAIL_LIBRARY`: the privately supplied retail library.
- `TRAIL_OUTPUT`: a new output directory outside the checkout.

The script verifies the retail SHA-256 before compilation, copies source privately,
compiles with the established profile flags, and links using ordinary native
placements. It verifies the expected target failures and exact mesh difference,
then checks all accepted selections, support regions and the UV table. A zero
exit status means this documented negative result reproduced; it does not mean
that the candidate matched. The script does not modify the checkout or delete
an existing output directory. Linker paths are quoted to support spaces.

The coordinator executed this reproduction successfully before publication.
The expected mesh SHA-256 is
`9440c3fd19bec7e47ff2c81c23367ecd245c37fdbadae38411461e4e429493f0`.
The input source/header patch, complete private inputs, linker, reference selectors,
comparison logs and selected compiler-pass excerpts are included for review.
