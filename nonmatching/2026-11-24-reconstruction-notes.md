# Reviewed reconstruction candidates, 24 November 2026

**None of these functions is byte-matched.** These fragments preserve tested
source and native constraints for subsequent work. They are not standalone
translation units or configured current-main build inputs. Their original
assembly markers and catalogue status remain unchanged.

| Candidate | Function/input bytes | Retail function bytes | Frame |
| --- | ---: | ---: | --- |
| [NPC::Update](ai/NPC-Update-storage.cpp) | 3044/3044 | 3012 | 284, matching native extent |
| [Vehicle::_processAIFlags](vehicles/Vehicle-processAIFlags-reconstruction.cpp) | 3044/3048 | 3220 | 476, matching native extent |
| [ScriptManager::update](scripting/ScriptManager-update.cpp) | 1220/1224 | 1220 | 52, matching native extent |

Each JSON companion records the actual tested object/source hashes, published
LF-source hash and narrower verification results. The coordinator extracted the
actual function bytes and checked the published method text against the tested
source after line-ending normalization. The published files were not separately
compiled as standalone units. Historical source/header fixtures remain required;
no private type proposals have been silently integrated into production.

## NPC storage and callback fidelity

Naming the two genuine vehicle-entry argument vectors, binding the early
GetPosition return by const reference, and ordering the independent scalar
captures/declarations reproduce all mapped native event/vector/scalar locations.
No dummy storage, barriers, register pins or output editing is used. Callback
order, the saved initial target and arrival-event lifetime through startTurn
remain intact.

A subsequent native-backed correction reloads the current target/category after
successful virtual getVehicle before checking category3 and its driver. The old
cached category skipped that native continuation. This is conservative native
callback/CFG fidelity, not a claim that a gameplay mutation was observed.

The resulting function is still 32 bytes oversized, so no NPC native link ran.
All 73 old raw definitions and off-target payloads/relocations remain unchanged;
the historical frozen dependencies pass 152 function and 44 section/region
checks. Genuine PhysicInfo constructor placement remains unresolved separately.
The earlier common-down/short-circuit fragment is retained as historical evidence.

## Vehicle field and event corrections

All three arrival resets now clear the existing pathToFollow pointer at offset 300,
matching native, instead of the unrelated entryAnimationScale at 308. The existing
pursuit-first and adjustedDestination-before-GetPosition corrections are retained.
Three genuine steering components survive the path join, with the real rotate
vector materialized at the native join.

Ordinary full-expression EvNPCVehicle temporaries reproduce the native 476-byte
frame, all ten distinct event homes and rotate/origin homes while preserving every
raise/destructor boundary. All 197 other definitions, 225 allocated payloads,
1,446 off-target semantic relocations and 294 imports pass preservation. Extent
still fails, and the native base-vptr phase is missing. No linker ran.

The later IEvent(19) constructor composition is **rejected**, not integrated:
target size became 3,168, but the existing cleanupTargetDetection function grew
from 84 to 96 bytes. Its preservation failure and skipped checks remain recorded.
That experiment does not supersede the published preservation-passing candidate.

## Script layout findings

The remaining getState unlikely hint removes the measured loop-tail duplicate.
Removing the older achievement hint restores its native relative show-block order.
An ordinary inversion of the initial failure arms uses GCC's measured 50/50
trace tie-break to restore native GetPlayer fallthrough. No new failure hint is
introduced. Pool placement and the first argument-move ordering still differ.

The latest candidate was not linked. An earlier linked candidate passed 143 other
function and 136 section checks but failed both complete target comparisons and
the additional full GOT comparison. Its 988 target and 642 GOT byte differences
were not masked. These results are not transferred into a fresh native-check
claim for the latest source. The remaining GNU hint is experimental and has not
earned production acceptance or matching credit.

Matched, Fully Linked and fuzzy progress do not increase from this batch. Current
production source, the Windows port and the original function catalogue remain
unchanged.
