# Dispatcher semantic corrections

Retained unmatched reconstruction of `Script::executeCommand`, Thumb address
`0x00339cb9`, native size 12,636 bytes. The adjacent `.inc` is the complete
corrected source fragment for the archived prerequisite translation unit.
It is not a standalone current-root implementation. Production sources,
headers, markers, catalogue statuses and progress are unchanged.

The bounded audit found five concrete discrepancies worth preserving:

1. Opcode 46 must use `GameObjectManager::s_gom`, not `GS3DStuff::gom`.
   Native GOT offset `0x39b4` resolves to `0x004b88b0`; the rejected source
   uses offset `0x083c`, resolving to `0x004b6984`. A controlled pair changes
   exactly two linked literal bytes and reproduces the native receiver.
2. Opcode 24 obtains the Application/event-manager receiver before stack
   event construction, followed by raise, D1 destruction and initInVehicle.
3. FadeIn/FadeOut opcodes 41/42 compare and reset their fade sentinels to
   `-999`, not `-1`. The native words at `0x0033af9c` and `0x0033bc20` are
   `0xfffffc19`. Unrelated negative-one values remain intact.
4. WaitKilled opcode 87 reads `explosionFinished` at vehicle byte 901.
   WaitStolen still reads byte 421. The fifth experimental form incorrectly
   changed WaitStolen to byte 900; that hypothesis was rejected after rereading
   the actual native words at `0x0033c044` and `0x0033c048`. The final source
   restores byte 421. The rejected form is explicitly identified in the JSON.
5. The ordinary event initializer `: IEvent(18), object(object) {}` restores
   the native base-vtable reference and store. No forced vptr stores, barriers,
   register constraints or output editing are used. Generated target-member
   store order still differs from native, so the header change remains private.

The coordinator independently checks the actual native manager slots,
sentinel/vehicle literals and all six compiled images. The source correction
patch is a delta against the archived candidate fragment, not against the
currently absent production dispatcher body. The event patch is separate and
does not authorize changing the production event header.

Six forms occupy 12,376 / 12,376 / 12,372 / 12,380 / 12,364 / 12,380 bytes.
The fifth is semantically invalid and is not a preferred candidate. Every
form uses a 324-byte frame versus native 332. The final function, its whole
section and the 472-byte dispatch table all fail. The final linked hash is
`5f89f364a49789616c24bcc8efb42cf8926545fd632a7e5c1719e27c4c3e07fa`.
Its 11,836 Thumb bytes and 544 data bytes differ from native's 12,120 Thumb
bytes and 516 data bytes; appending padding cannot repair this reconstruction.

All forms preserve 31 functions, 28 sections and one GOT region in the
archived prerequisite graph, with 842 stable source/configuration inputs.
That graph contains 26 old Script functions and five event-support definitions;
it is not the current-root 27-function Script graph or a transitive header gate.
The coordinator separately reconstructs that isolated graph with the public
normalized-LF fragment and reproduces the final size, hash, failure exit 1
and all 31/28/1 existing comparisons. This is a reproducible archived-context
result, not a current-root closure claim.

The countdown buffer at `0x004ba578` is static BSS storage with a zero-sized,
non-STT_OBJECT symbol. The next known address is twelve bytes later; neither
that gap nor unbounded sprintf establishes the original array bound. The
retained `buffer[12]` is provisional. Changing it cannot explain the local-frame
gap; old ten/twelve-byte forms already produce identical function code.
Named vector-call probes confirm three 12-byte temporaries, not an artificial
missing eight-byte object. Native DriveWell intentionally calls getVehicle
twice, and that real behavior is preserved.

The six-form source budget is exhausted. Any inherited likelihood hints and
manual imported event-destruction idiom remain quarantined with the candidate.
No function is credited, no marker is removed, and no data-size or complete
unit claim is made. Further work requires new causal source or ABI evidence.

## Later wanted-bound predicate correction

Complete native switch recovery exposed a concrete discrepancy in shared cases
64/105. When maximum is exceeded, native still compares wanted against minimum
before selecting the message. The prior if/else-if gives maximum failure
priority. The fragment now uses the combined bound-violation predicate and then
selects low message 0x3022 when wanted is below minimum, otherwise high 0x3021.
For contradictory bounds minimum=3, maximum=1, wanted=2, native selects low;
the old candidate selects high. No claim is made that assets contain such bounds.

One separately authorized source-only control emits a 12,396-byte function and
12,400-byte input section versus native 12,636. Exact output:

```text
COMMAND 0 EXIT 0
COMMAND 1 EXIT 0
REJECT PRELINK: function/section extents differ from native12636; no target link attempted
```

Actual assembly now tests minimum on the maximum-failure path. The coordinator
independently verifies function SHA-256
`6f6b30f25a0ec9848310b9012d21e71ebb64b9cf50cb1bfeef1534b723349676`,
35 other raw function definitions unchanged and 842 stable inputs. All 201
imports and 68 other allocated section payloads remain unchanged. The local
frame remains 324 bytes. No native link or owner/dependency/switch/full-section
linked checks ran; the old 31/28/1 proof above remains historical only.

This correction supersedes the earlier 12,380-byte preferred semantic body;
it does not supersede its linked verification with a new successful result.
The published LF fragment still requires the full preserved private translation
unit, headers and compiler profile. Exact source, commands, failed gates and
objects are retained in `_scratch/worker-script-execute-wanted-bound-control`.
No marker, matching credit or compiler-output bytes were changed.

## Case 37: retain the native flags snapshot

Native captures flags344 OR 0x400800, stores it, calls lrand48 once, then ORs
the selected random bit into that saved value. The prior candidate reloads
flags344 after the call. The fragment now explicitly retains savedFlags across
the call, preserving the initial store, one PRNG invocation and the existing
aiTarget tail. No vehicle-mutating libc behavior or gameplay defect is claimed;
this is an observed source-lifetime and compiler constraint.

One separately authorized control emits the intended saved value in a
callee-saved register with no post-call flags reload. The function remains
12,396 bytes and its input section 12,400, versus native 12,636; the strict
extent gate stops before linking. Raw function SHA-256 is
`0ced24317462d66a332f5d41dd3c70f5d9232c76cc3ca1dbc05c6eb6a85afee9`.
All 35 other definitions, their semantic relocations, 201 imports and 842 inputs
remain unchanged. Of 69 allocated sections, only target text and its 472-byte
dispatch payload change; the other 67 preserve payload, extent and alignment.
No relocated or native switch comparison is claimed for that changed table.

The local frame remains 324 bytes. Native linking, target/full-section/switch
and owner/dependency linked checks were skipped. The coordinator independently
verifies the object, extent, raw function hash and preserved definitions/inputs.
Evidence remains in `_scratch/worker-script-execute-saved-flags-control`.
This is the preferred semantic body with the wanted correction retained;
it remains unmatched and requires the same full private compilation context.

## Case 86: initialization stores and vehicle-guard association

Native initialization explicitly zeros only Speed and Jumping accumulators.
Original GOT references and distinct global addresses prove the candidate's
additional Drifting and WantedLevel zero stores are extra operations. One
separately authorized control removes only those two stores; actual output
retains exactly the two native resets. Function/input section become
12,372/12,376 bytes versus native function 12,636. Strict function extent fails,
so no native link or linked target/owner verification runs.

A second separate correction fixes the two genuine vehicle comparisons.
Native first mismatch enters the objective reminder; first match followed by
second mismatch returns false directly. The old combined && sends both
mismatches to the reminder. The fragment now nests an immediate second-mismatch
false return inside the first equality, leaving the reminder else attached only
to that first comparison. Both real getters and fresh static reads remain;
no invented callback transition or collapsed/cached getter is used as proof.

The actual control emits this native failure-edge association. Function and
input section are both 12,352 bytes, still short of 12,636. Raw function hash:
`fc1276c4fe539bb7af09c2e576245ae8572f1e1fef27d4f158dd14d3971e564c`.
The local frame remains 324 bytes. Strict function extent again stops before
linking; no native target/full-section/switch or owner/dependency linked result
exists for either control. No additional source form is run.

For each control, all 35 other raw definitions and semantic relocations,
201 imports and 842 frozen inputs remain unchanged. INIT changes only target
text, preserving 68 other allocated sections. The guard correction changes
target text and its 472-byte dispatch payload, preserving the other 67.
The coordinator independently verifies both objects, extents, raw target hashes,
old raw definitions and frozen inputs. Exact evidence is preserved in
`_scratch/worker-script-execute-init-cache-control` and
`_scratch/worker-script-execute-second-vehicle-guard-control`.

This preferred semantic fragment retains all four later corrections: wanted
selector, saved flags, two-reset initialization and nested vehicle guard. The
earlier six-form and private-context limitations remain. No matching credit,
native switch claim or Fully Linked progress follows from these corrections.

## Case 101: highlight child, retained vehicles and guarded type

Four later separately authorized controls correct native-backed field and
lifetime constraints without changing headers, flags or layouts:

| Control | Function bytes | Input section bytes |
| --- | ---: | ---: |
| Test existing highlight child at offset 20, rather than sceneNode16 | 12,352 | 12,352 |
| Retain one vehicle for initial highlight/action instead of three getters | 12,340 | 12,344 |
| Retain one vehicle for cleanup highlight/unset instead of two getters | 12,320 | 12,320 |
| Acquire target type only after isEnabled returns true | 12,320 | 12,320 |

Retail requires a 12,636-byte function. Every strict function extent check
fails before linking; no native target/full-section/table or owner/dependency
linked comparisons run. The field-only result differs in exactly one target
byte, selecting original+20. Actual output for each later control preserves
the native receiver capture or enabled-before-type acquisition. Cleanup stays
outside both type/death guards. The distance condition remains !(distance >=
minimum), preserving the native unordered/NaN result rather than substituting <.

All 35 other definitions and semantic relocations, 201 imports and 842 frozen
inputs remain unchanged per control. Field/type controls preserve the other 68
allocated payloads; vehicle-cache controls change target text and its 472-byte
dispatch payload while preserving the other 67. The coordinator independently
extracts each function and confirms extent, raw hash, old definitions and
input stability. The preferred eight-correction function hash is
`7b97bab7493574e8532046169b56b3796fd619822c91a87a48885b117d892dce`.
The local frame is still 324 bytes. Similarity and smaller size earn no credit.

Private packets under `_scratch/worker-script-execute-` have suffixes
`highlight-field-control`, `initial-highlight-cache-control`,
`cleanup-highlight-cache-control` and `type-guard-control`. Their exact source,
commands, objects, comparison inventories and failed gates remain preserved.
The public LF fragment needs those complete private compilation contexts;
it is still unmatched, with its original assembly marker retained.
