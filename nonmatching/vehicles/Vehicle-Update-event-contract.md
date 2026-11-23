# Vehicle::Update: event-construction contract, still unmatched

Target `_ZN7Vehicle6UpdateEi`, Thumb `0x00313b01`, native **4,020 bytes**.
The retained [source fragment](Vehicle-Update-damage-common.cpp) now reflects
the proved event construction/order. It is not a standalone or configured
canonical source unit. Its assembly marker remains; no credit is added.

## Original constraint

Native obtains a fresh application/event-manager receiver at `0x3144b4..bc`,
then constructs the event: payload, base `IEvent` vptr, word ID20, derived
`EvVehicleDestroyed` vptr. Raise and the genuine D1 follow at `0x3144d4/de`.

The old private header used default `IEvent()` followed by derived-body ID
assignment, producing only the derived-vptr reference. Its source also obtained
the manager after construction. This was a construction/reference discrepancy,
not a wrong-ID runtime bug: both forms delivered ID20.

One coherent control uses the already established constructor
`EvVehicleDestroyed(Vehicle* value) : IEvent(20), vehicle(value) {}` and:

```cpp
{
    EventManager* events = Application::GetInstance()->GetEventManager();
    EvVehicleDestroyed event(this);
    events->raise(event);
}
```

Automatic destruction remains before siren/target/statistics cleanup. No
placement buffer, forced destructor/vptr stores, compiler flags or unrelated
header/body changes were introduced.

## Actual result

| Artifact | Function | Entire input section |
| --- | ---: | ---: |
| Saved/reproduced preferred baseline | 3,924 | 3,928 |
| One event-contract control | **3,936** | **3,936** |
| Native function | 4,020 | not reached for review |

Both baseline and control compiler/assembler pairs exit 0. The strict
function-extent check stops the control:

```text
REJECT PRELINK: target FUNCTION does not have exact native4020-byte extent; NO LD; linked target/neighbor/owner/dependency checks SKIPPED
```

The control remains 84 bytes short. Its 228-byte frame is unchanged; native
event-stack placement is not reproduced. No linker, target/section/neighbor/GOT
comparison, linked owner/dependency gate or fresh canonical full build ran.

Actual object instructions now show manager capture before construction,
base-vptr → ID20 → derived-vptr order, raise, and genuine automatic D1 before
siren cleanup. Both fresh `Application::GetInstance` calls remain. The target's
sole new relocation is a real GOT32 reference to `_ZTV6IEvent`.

## Preservation and limits

The baseline reproduces the original raw function SHA256
`fdd4f495dcd8895d735f4cab51449258543028bf88cf7f6aaed7329d6e0f2073`
and the entire original input section. Control raw function SHA256:
`fc1c951e944a292f0df364d71d608cfc37ade1c52aaa6c343498e1b5c3d17756`.

All 199 old executable definitions, 226 off-target allocated payloads, 1,448
off-target semantic relocations and 306 imports are preserved. Comparisons
explicitly record one bijective compiler-generated Vehicle anonymous-namespace
identity correspondence; actual names/output bytes were not rewritten, and
whole-object/name identity is not claimed. All 1,065 original inputs, fixtures
and prior artifacts remain unchanged.

The private packet is `_scratch/opencode-vehicle-update-event-contract-control/`.
`baseline-commands.json`, `control-commands.json`, `source-delta.diff`,
`inspection-proof.json`, `final-summary.json` and `REPORT.md` retain exact
commands, hashes, store/reference proof and failed extent. The public method
fragment has the same target tokens as the tested source, ignoring whitespace
and comments, but still requires that retained type/context closure and the
current payload constructor.

The old unused private `dcmpge` binding is known wrong; it was neither silently
repaired nor executed. Do not link that fixture unchanged.

Native function bytes end at `0x314ab4`; four genuine outside-function NOP bytes
precede `GameObjectList` constructors at `0x314ab8`. If a future function first
reaches 4,020 bytes, its complete input-section/padding/neighbor gate requires
separate review. No padding is trimmed, inserted or counted as function credit.

The six original forms and subsequent specifically authorized controls remain
spent. This one event refresh is finished; no second construction, lifetime,
placement, flag or source-order form follows without genuinely new evidence.
