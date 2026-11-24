# Vehicle event construction and exact cleanup

`Vehicle::cleanupTargetDetection()` remains an exact 84-byte match at Thumb
`0x00310881`. Its reconstruction now uses an ordinary automatic
`EvNPCVehicle`, replacing placement storage and the explicit mangled destructor
call. Destruction still occurs immediately after `EventManager::raise` in the
same conditional scope.

`EvNPCVehicle` initializes its base with `IEvent(19)`. Its existing `used`
destructor declaration also carries `long_call`, preserving the native GOT
lookup and indirect call. The obsolete weak C-linkage destructor declaration
has been removed from `Vehicle.cpp`. These are changes to an already matched
function and its shared event declaration; they add no matched functions or
bytes.

## Why the construction context matters

The pending `Vehicle::_processAIFlags()` contains ten distinct event
temporaries. Retail code initializes each base vptr, stores event ID 19, then
stores the derived vptr. Initializing the ID only in the derived constructor
body had allowed GCC to remove the base phase in the preserved candidate.
The base initializer restores all twenty native base/derived vptr stores and
all ten event homes in that historical fixture.

Simply changing the initializer while retaining cleanup's placement storage
regressed cleanup from 84 to 96 bytes. Ordinary automatic storage lets GCC
eliminate the redundant base store in cleanup while retaining the required
phases in the larger function. The linked cleanup is byte-identical to retail.
The resulting strong undefined destructor reference can resolve to the genuine
weak destructor; it is not evidence of a runtime ABI failure.

## Current-source verification

A fresh private copy of current source first passed 551 function and 247
section/region comparisons across Vehicle, PlayerTest and its four native
dependencies. The coordinator then integrated precisely those two tested
files and independently ran:

```text
python tools/build.py --all
exit: 0
profiles: 191
function comparisons: 5461
section comparisons: 5483
region comparisons: 181
total comparisons: 11125
previously credited functions: 4292
credited selector coverage gaps: 0
frozen inputs: 1135
changed inputs: 0
failures: 0
```

The complete cleanup input section at `0x00310880` was separately checked as
84 native-identical bytes. Exact checker output includes:

```text
OK  _ZN7Vehicle22cleanupTargetDetectionEv  0x00310881  84 bytes
OK  _ZN12EvNPCVehicleD1Ev  0x00303a95  36 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
```

The current workflow verifies the real destructor in its owning PlayerTest
profile. Vehicle's existing verifier still uses its sanctioned retail Thumb
binding; this change does not add a native dependency to that profile.

## The AI candidate is still unmatched

The preserved historical candidate now has 3,168 function/input bytes versus
3,220 native bytes, the native 476-byte frame, and all ten native event homes.
Both images contain 220 literal-pool bytes; the candidate has 52 fewer mapped
executable bytes. Shared raise/destructor tails are an observed code-shape
difference, not proof of missing source semantics or an excuse to insert code.

An independently linked historical fixture passed all 188 existing function
and 112 region checks. Only the pending AI function and its section failed.
The complete 18,836-byte GOT was also compared: 642 differing bytes remain in
the reserved prefix below `0x360`; the entire configured global remainder is
exact. Neither full-GOT equality nor an exact whole-library image is claimed.

The AI assembly marker remains present. Its fragment and machine-readable
evidence remain under `nonmatching/vehicles/`; it is not integrated as a
matched implementation. Progress remains 4,292/4,550 functions and
356,686/561,716 bytes (63.50%).
