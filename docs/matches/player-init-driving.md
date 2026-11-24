# PlayerTest::initDriving exact match

`PlayerTest::initDriving(bool)` now matches all 184 retail bytes at Thumb
address `0x00301911`. Its complete 184-byte output section also matches:

```text
OK  _ZN10PlayerTest11initDrivingEb  0x00301911  184 bytes
OK SECTION .player_init_driving  0x00301910  184 bytes
```

The original fifteen compiler options and four assembler options are unchanged.
The source reuses existing Character, CameraManager and ScriptManager interfaces.
The existing SavePositionInterface adjustment supplies the retail Character
receiver for getSpecificAnimation, following the project's matched receiver view.
The genuine CameraManager::goBehind entry is declared Thumb in the manifest;
no compiled dependency definition is overridden.

## Source reconstruction

The method saves the requested driving state, respects cinematic early exits,
clears the target, updates camera following and touchscreen input, then restores
the character animation and calls justStoleCar on the saved vehicle when leaving
that state. It clears the two original pointer fields and the movement flag.
All callback counts, receiver adjustments and field offsets follow retail.

The final four-byte discrepancy was register allocation for the flags snapshot
and mask. A measured local-allocation trace ranked the flags quantity below the
mask. Moving the ordinary unknown368 null store before the flags snapshot,
while leaving unknown312 clearing after it, tested one specific lifetime change.
The fields are disjoint ordinary members; no callback lies between these stores
and the flags update. The resulting compiler output restores retail's flags R3
and mask R2 sequence, including retail's final scheduled load/store order.

No assembly, register pin, barrier, compiler-output edit, special compiler
parameter, new likelihood hint or dummy pressure root was used. Earlier failed
candidates and raw namespace-identity failures remain preserved privately. The
coordinator accepted only particular complete anonymous-namespace name
correspondences after independently proving all off-target object bytes and
section/symbol metadata unchanged. No compiler output was normalized.

## Verification and integration

A single private link of the actual candidate and six genuine saved auxiliary
and dependency objects passed the target/full-section comparisons, all 359 old
function and 132 section/region checks, and native extent/neighbor assertions.
The saved dependency images were not fresh builds. Its complete GOT equals the
old candidate: the known 642 native differences in the 864-byte prefix remain;
the checked 17,972-byte suffix matches retail.

Canonical integration then rebuilt all 191 configured ARM profiles from source:
5,465 function, 5,488 section and 181 region comparisons passed, 11,134 total.
All 891 source/configuration/tool files frozen for that invocation stayed
unchanged. A separate read-only audit verified coverage of every one of the
4,295 previously matched game entries, with no gaps. The full native input ends
at `0x003019c8`, where the existing stopMoving function begins; the preceding
setAnim function retains its 62-byte body and 64-byte input.

Only after this fresh gate passed was the original assembly marker removed.
Generated progress becomes 4,296/4,550 functions and 357,490/561,716 bytes
(63.64%). Fully Linked remains 114,548 bytes (20.39%, 126/202 units), because
PlayerTest remains incomplete. Fuzzy Matched also becomes 63.64%; unmatched
functions receive no partial credit. The native Windows port is unchanged.
