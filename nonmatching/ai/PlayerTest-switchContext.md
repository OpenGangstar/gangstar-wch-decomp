# Player context switching: current-layout replay

Unmatched candidate for `PlayerTest::switchContext(eContext, bool)`, Thumb
`0x00301a75`, native 900 bytes. Production base: `0e87d02` after the verified
NDK enum-width baseline and Script::setState match. No credit or assembly deletion.

Six historical forms remain exhausted. Their final candidate is 892 bytes but
uses an older private Player layout and an explicit C ABI bridge to pass the
context word. Exactly one bounded follow-up adapts that saved algorithm to the
current coherent Player hierarchy and verified word-sized enum baseline.

The candidate uses the genuine freezeRunningScripts enum API and the existing
40-byte context-cache view at the current inactive-node storage. Its animation
records still occupy the existing cached bytes, and the active animation view
starts at the existing unknown164Pointer field. No stored field, inheritance,
class size or existing function implementation changes. The real Character
base adjustment comes from the current hierarchy. The local 28-byte user-data
constructor retains the observed owner/node, float and boolean initialization.
Only private Map friendship is added to access its existing API; this header
change remains unapplied and has no new independent preservation proof.

The single reconstructed body emits 884 bytes, against native 900. Only the
assigned function is newly emitted. The strict prelink guard stops with exit 3;
no linked target or old owning-function preservation comparison is claimed.
Dependency builds completed normally before the owning prelink guard. Their
checks do not establish preservation of the unlinked owning candidate.

```text
BUILD ai-startup-playertest
{"size": 884, "native_size": 900, "section_size": 884, "new_definitions": ["_ZN10PlayerTest13switchContextENS_8eContextEb"], "raw_sha256": "83cf1962352748c6d6dcb98aaba8170d3440be867f52b5e7e889749988864427", "linked": false}
Prelink extent/helper guard failed; no linked comparison claimed.
```

The patch is an unapplied reconstruction artifact. In an isolated checkout,
configure `WCH_BASE_LIB`, apply it, and run `python tools/build.py
ai-startup-playertest`. The strict 900-byte section assertion is expected to
fail. Native text imports and call modes are explicit, and already compiled
dependency definitions are not replaced by imports. Normal overlap checks
remain enabled; the function is never moved to an invented address to fit.
No compiler output, hint, register constraint or barrier is used.

The old 892-byte attempt and this current-layout 884-byte attempt have different
source contexts. Neither size is matching evidence. Both are retained; no
further source variation or shared-header migration was attempted. Further
work requires new evidence beyond the already tried enum-width replay. All
production Player methods, current destructor/photo matches and source layouts
remain unchanged because this patch is not applied.
