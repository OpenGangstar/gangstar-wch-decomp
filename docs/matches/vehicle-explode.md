# Vehicle::explode: exact 740-byte reconstruction

Target `_ZN7Vehicle7explodeEv`, Thumb `0x003130a1`, original source `Vehicle.cpp`.
The implementation uses ordinary C++ with unchanged compiler policy. No compiler
output, relocation result or linked byte is edited.

## Missing shared receiver

Native `jumpTo` returns at `0x313154`. At `0x313158`, the function reads the
post-call timeline pointer once. Stores at `0x31315e` and `0x313160` use that same
receiver for callback data and callback.

The retained candidate separately read `explosionTimeline` for each store.
An isolated control adds a local pointer **after** the existing `jumpTo`:

```cpp
irr::scene::ITimelineController* const timeline = explosionTimeline;
timeline->callbackData = this;
timeline->callback = VehicleExplosionAnimCallback;
```

Taking the snapshot before `jumpTo`, reordering the two stores, or retaining a
pre-call controller would not express the original constraint.

## Reused original constraints

The implementation also retains the earlier recovered behavior:

- Zero the player's genuine inherited health word at offset 224, not 448.
  Keep both original `GetPlayer` calls.
- Construct `EvVehicleDestroyed` through `IEvent(20)` and the derived constructor,
  preserving both compiler-generated vptr references. No forced vptr stores.
- Run its real destructor before siren/target cleanup.
- Preserve material-damage NaN comparisons, separate position-result temporaries,
  sound receiver snapshot, flags, callbacks and cleanup order.

The event header retains default-construction availability and gains the observed
payload constructor. Timeline slot four gains the `setClip(int)` call view used
by native; its result is ignored, so this does not establish the original return
type. Neither change alters the recovered layouts or virtual slot order.

## Exact verification

One private baseline and one timeline-only source control were compiled.
Both the function and entire input section are exactly 740 bytes. Generated
anonymous-namespace identities differ between private runs; earlier off-target
object comparisons explicitly record the one-to-one name correspondence.
Actual symbols and compiler outputs were never rewritten. That comparison
qualification is **not** used to accept the native function.

The coordinator first linked the unchanged control object at the native address,
strengthening its private linker assertion from `<= 740` to `== 740`. All 189
function and 113 section/region checks passed, including:

```text
OK  _ZN7Vehicle7explodeEv  0x003130a1  740 bytes
OK SECTION .vehicle_explode_candidate  0x003130a0  740 bytes
```

The current canonical source is independently rebuilt by:

```text
python tools/build.py vehicle-cleanup --baselib <local-retail-library>
```

All 190 function and 114 section/region comparisons pass:

```text
OK  _ZN7Vehicle7explodeEv  0x003130a1  740 bytes
OK SECTION .vehicle_explode  0x003130a0  740 bytes
```

This includes the previously matched adjacent 1,360-byte collision function and
the complete 17,972-byte checked global GOT region. Native callees use validated
Thumb metadata; no compiled definition is replaced with a retail binding.

## Global acceptance

The fresh preservation gate passes all **191 profiles / 11,116 comparisons**:
5,457 function, 5,478 section and 181 region checks. All 1,115 inputs remain
hash-identical throughout that run. Every one of the 4,287 previously credited
game function identities appears in successful exact comparisons, with no gap;
the new complete function and section also pass.

Only the verified explosion assembly marker is removed after this gate.
Regenerated tables retain all 17,703 original entries and change only this
function's status. Direct comparison-log coverage now proves all 4,288 credited
game functions. Progress is **354,058 / 561,716 bytes (63.03%)**; Fully Linked
remains **114,548 bytes (20.39%, 126/203 units)**.
The overall 100% game-code goal remains incomplete.

Private evidence: `_scratch/opencode-vehicle-explode-timeline-control/`,
`_scratch/opencode-vehicle-explode-native-link/` and
`_scratch/opencode-explode-integration/`. The historical
`nonmatching/vehicles/Vehicle-explode-current.*` artifacts preserve the earlier
failed reconstruction; they are not the source of a matching claim.
