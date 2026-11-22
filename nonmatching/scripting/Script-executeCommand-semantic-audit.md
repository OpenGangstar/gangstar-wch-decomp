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
