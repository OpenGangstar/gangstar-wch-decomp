# Generated namespace identity in saved GCC controls

Several saved controls have different anonymous-namespace suffixes even when
their relative source paths and selected compiler binaries agree. Raw object
identity and preservation of compiled instructions are separate measurements.
Neither measurement replaces comparison with the retail executable.

Upstream GCC 4.2.1 provides a concrete mechanism consistent with these names:

1. The C++ parser creates an anonymous namespace through
   `get_file_function_name('N')` and caches that name for the translation unit.
2. Without a suitable first global object anchor, name generation appends CRCs
   derived from the weak global object name and `flag_random_seed` to the source
   filename.
3. When no explicit seed is supplied, initialization derives a seed from a time
   value and the process ID.

Primary sources at the immutable GCC 4.2.1 release commit:
[namespace creation](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/cp/name-lookup.c#L2997),
[name generation](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/tree.c#L6051),
[default seed initialization](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/toplev.c#L469).

This establishes upstream behavior, not the exact runtime cause of a particular
installed NDK compiler's output. The saved runs did not capture its internal
seed, first-global state, timestamp or process ID. A matching suffix format does
not prove that the proprietary compiler has identical source or patches.

## Reviewed Vehicle example

The original and void-set declaration-control objects are both 113088 bytes.
Their complete generated prefixes differ only in the final CRC field:

```text
_GLOBAL__N_src_game_vehicles_Vehicle.cpp_00000000_8164C232
_GLOBAL__N_src_game_vehicles_Vehicle.cpp_00000000_AD162EB4
```

Each prefix occurs at 46 corresponding locations: 23 symbol names and 23 section
names. Exactly 368 differing file bytes fall inside those names. Four additional
bytes differ in the constructor-setup instructions of `Vehicle::step`, at target
offsets 0xaf4 through 0xaf7. All 372 raw differences were classified directly
from the immutable files; neither output was rewritten. The four instruction
bytes remain real code changes and cannot be excused by namespace generation.

The separate preservation audit covers all 200 off-target function payloads,
230 off-target allocated payloads and 1530 off-target references under explicitly
enumerated identifier pairs. Raw whole-object, symbol and reference identity
remain failed. The control is still 4336 bytes against native 4372 and receives
no matching credit. See [the source-control record](../../nonmatching/vehicles/step-conditional-controls/README.md).

## Handling a future identity failure

Preserve the original output, hashes and complete raw inventories first. A
generated-name explanation is insufficient until every instruction, data byte,
import, symbol attribute, section attribute and semantic relocation is accounted
for. Any proposed correspondence must enumerate complete names, be one-to-one
and collision-free, and explain all associated string/index bookkeeping.

Only the coordinator may accept a specific correspondence for a subsequent
measurement. Report that acceptance separately from the failed raw identity
gate. For an unchanged-source diagnostic, target code and metadata must also
remain exact; a source-control experiment needs its approved target differences
reported independently. Stop on unexplained changes.

Do not edit compiler output, mask code, retry until a suffix agrees, or introduce
`-frandom-seed` to satisfy an existing reproduction protocol. This finding does
not change production flags, native-address byte verification, matching credit
or existing run-specific identity requirements. In particular, a diagnostic
explicitly requiring whole-object and assembly identity still has that gate.

Detailed raw spans, hashes and primary-source provenance remain in
`_scratch/worker-vehicle-step-anonymous-reproducibility/`.
