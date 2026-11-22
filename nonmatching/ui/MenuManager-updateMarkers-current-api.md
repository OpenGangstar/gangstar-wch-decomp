# Map markers: current interface reconstruction

This is an unapplied candidate for `MenuManager::updateMarkers()`, the
360-byte Thumb function at `0x002e6949`. Both tested source forms compile
to 356 bytes and remain unmatched. Its assembly marker and pending status
remain present. No matched or Fully Linked progress is added.

The earlier four source forms used a synthetic position interface and
compiled to 368 bytes. The only surviving old linked image relocated the
target; that image does not prove a native-address match or full closure.
The new reconstruction uses the real PlayerTest/Character hierarchy,
`GetPosition()`, `getVehicle()` and the existing Irrlicht dimension
constructor. The current headers also retain a compatibility `position()`
forwarding shim; the issue was the obsolete private model, not the absence
of that spelling from production headers.

The private header prerequisites add access-only friendship, the missing
method declaration and an observed word-sized field view at offset 28.
All 28 before/after model layout measurements agree. Header-only
verification preserves 75 existing functions and 36 existing regions.
These are compatibility checks on current partial class models; they do
not independently establish complete retail allocation sizes. The layout
probe's `-fno-access-control` option is confined to standalone data probes
and is not used to compile game code.

The first source computes both relative coordinates before `getScaledSize`,
then updates the target marker and map arrow through the recovered APIs.
The second uses the retained mutable-vector source form with those same
interfaces and evaluation order. It changes only four raw bytes, swapping
the independent X/Y load pair. Both candidates still use a 36-byte local
frame versus the native 44-byte frame. No padding, synthetic frame-forcing
locals, branch hints or compiler flag changes are used.

Both real canonical builds exit 1. Each preserves all 75 previously
selected functions and 36 previously selected sections/regions; each
freezes 884 unchanged inputs. The coordinator independently loads both
actual native-address images and repeats the native function comparison.
Both fail first at `0xc`; exact outputs and complete differences are in
the adjacent JSON.

The first linked function SHA-256 is
`b1f34734d8e1349c6df017b25b3357580da91fbec47870cb6a2c95934b38335b`;
the second is
`79977134f0e08ebf3f80671410f8d6fd8549a75e52ad496b920f92af50a29ce4`.
Neither same-size proximity nor the four-byte source delta earns credit.

Initial harness attempts rejected an overly strict size assertion and
lacked five native floating-point PLT bindings. Those failures are retained
separately. The corrected harness allows the candidate to fit within its
native extent while the function checker still requires the entire exact
native function; no neighboring function is moved or compiled definition
masked as an imported address.

To reproduce, apply the adjacent patch in a private checkout and run
`python tools/build.py menu-manager-helpers --baselib <retail-library>`
with the original configured toolchain available. The JSON also contains
the second source delta to apply after the first patch. A future accepted
consumer would require all affected shared-header closures and the full
native gate. This package does not claim either broader verification or
production integration. Further source searches require new causal evidence.


## Pre-getter viewport-top snapshot

A later complete native audit found one previously untested scalar lifetime.
Retail loads viewport top at 0x002e6a22, preserves it in `r8`, and uses that same
value after the TargetMarker getter at 0x002e6a86. Both faithful candidates and
all four older forms instead reloaded manager top after that call. The getter
is not shown to mutate this manager; the evidence concerns the caller's actual
memory snapshot and generated instructions.

The [incremental snapshot patch](MenuManager-updateMarkers-top-snapshot.patch)
applies after the first adjacent current-interface patch. It captures top
immediately before the getter and uses the captured value for `offsetY`. No
other expression, bound, type, header, compiler flag or linker input changes.
Do not combine the second mutable-vector variant with this control.

One approved compile and assembly completed successfully. The corrected
function and input section are still **356/native 360 bytes**; the 36-byte
frame also remains unchanged. Its target payload SHA-256 is
`2e48f04982239ce85c54c53ecf432e3596935e7c1a630f74a5d2a46b7234daf8`.
The compiler now preserves top across the getter and emits the native-supported
`blx r5; mov r2, r8; sub r3, r6, r2` sequence. This verifies the narrow snapshot
hypothesis, not the complete function.

All 77 previous section-backed function definitions retain their raw payloads
and semantic relocations; all other allocated sections are unchanged. The
884-file input snapshot is stable, with only the approved source differing
from the baseline. The coordinator independently reread the emitted object,
verified the target extent/hash and compared all 77 old function payloads.
The incremental patch was independently applied with strict Git checks;
resulting source content matches the compiled control after line-ending
normalization required by this repository.

The stricter exact-360-byte pre-link gate rejected the short candidate before
harness generation or linking. No new target ELF, native byte comparison or
fresh 75-function/36-region/GOT gate exists. Historical successful checks above
remain historical. No second source form was tried, no assembly marker was
removed, and no matching progress was added.
