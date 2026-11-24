# Vehicle destructor family: exact reconstruction

Original source: `Vehicle.cpp`. Ordinary `Vehicle::~Vehicle()` emits all three
retail destructor identities and the real Vehicle vtable:

| Symbol | Retail Thumb address | Bytes |
| --- | --- | --- |
| `_ZN7VehicleD0Ev` | `0x00311251` | 584 |
| `_ZN7VehicleD1Ev` | `0x00311499` | 580 |
| `_ZN7VehicleD2Ev` | `0x00311499` | 580 |

D1 and D2 are aliases of one physical function. The existing catalogue counts
both original entries: this adds three matched entries and 1,744 catalogue
bytes, representing 1,164 distinct machine-code bytes. No identity, size,
classification or denominator was changed to obtain this progress.

## Reused construction context

The retained destructor body preserves the original cleanup order, repeated
player queries, callback receiver snapshots, object deletion and trail cleanup.
Its event uses an ordinary scoped automatic `EvVehicleDestroyed` object.

The accepted explosion reconstruction supplies the authentic existing
`EvVehicleDestroyed(Vehicle*) : IEvent(20), vehicle(...)` constructor. Earlier
destructor attempts established either placement lifetime with the base-ID
constructor or automatic lifetime with body-assigned event ID; the combination
used here was not established as previously tested. Current automatic lifetime
and the base-ID constructor produce the exact native event sequence without
forced vptr stores, new attributes, changed compiler flags or header edits.

Only three stale member names in the retained body needed adaptation:
`owned748/owned768/owned772` become the current `init748/init768/init772` fields.
All preexisting canonical source bytes are preserved as the prefix.

## Native linkage and exact verification

The generated deleting destructor and vtable are real compiler definitions.
They are excluded from generated retail fallback bindings. New external native
Thumb references retain their validated function metadata; array delete uses
the real ARM PLT entry at `0x001c461c`.

Strict linker assertions place the complete D0 section at `0x00311250` and D1
section at `0x00311498`, ending at the adjacent native boundaries. D2 resolves
to the same actual D1 definition. The vtable symbol is 188 bytes; its unmodified
input section is 192 bytes, including four zero padding bytes. Both the symbol
and complete section match retail through the next table at `0x004ab2b8`.
No output bytes are trimmed, patched or post-processed.

Reproduce the canonical verification with:

```text
python tools/build.py vehicle-cleanup --baselib <local-retail-library>
```

Exact output, independently repeated by the coordinator:

```text
OK  _ZN7VehicleD1Ev  0x00311499  580 bytes
OK  _ZN7VehicleD2Ev  0x00311499  580 bytes
OK  _ZN7VehicleD0Ev  0x00311251  584 bytes
OK SECTION .vehicle_d1  0x00311498  580 bytes
OK SECTION .vehicle_d0  0x00311250  584 bytes
OK SECTION .vehicle_vtable  0x004ab1f8  192 bytes
```

All 193 function and 117 section/region comparisons in this unit pass,
including all previous 190/114 checks, the 17,972-byte GOT region, explosion,
collision, constructor, event helpers and neighboring functions. The private
candidate preserves all old allocated payloads, 799 definition records and
1,566 semantic relocations; the original vtable import becomes a real definition.
Generated anonymous namespace names were paired for metadata inspection only;
no emitted names or outputs were rewritten to establish a native match.

## Complete preservation and progress

After canonical integration, a fresh `python tools/build.py --all` passes all
191 profiles and 11,122 comparisons: 5,460 function, 5,481 section and 181 region
comparisons. All 1,120 recorded source/configuration/tool/nonmatching inputs stay
hash-identical throughout that run. Every one of the 4,288 previously credited
game entries and all three new identities has direct successful exact-check
coverage. Only then are the three verified assembly markers removed.

Regeneration preserves all 17,703 original catalogue entries and changes only
the three destructor statuses. Matched/Fuzzy progress becomes **4,291/4,550
functions, 355,802/561,716 bytes (63.34%)**. Vehicle still has pending functions:
Fully Linked remains **114,548 bytes (20.39%), 126/203 reporting units**.

Private reproduction and proof packets:
`_scratch/heartbeat-20261124-vehicle-destructor/`,
`_scratch/root-vehicle-family-review.*` and
`_scratch/vehicle-destructor-integration/`.
