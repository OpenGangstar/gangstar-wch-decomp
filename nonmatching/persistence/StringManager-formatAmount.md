# Amount formatting: separate language-pack cases

Unmatched candidate for `StringManager::formatAmount(int, bool, bool) const`,
Thumb `0x0034b3c5`, native 480 bytes. Baseline production source is PR #740,
`39ae587ea4430b0b566500ef933dd8344e4e9fb3`. No matching credit or assembly deletion.

Six archived forms remain exhausted; this is exactly one bounded follow-up
using the separate-case structure that recovered the Character selector.
The source starts from archived v5, retaining signed division, static buffer,
reversed HTML text, currency handling and the genuine string helper calls.
Packs 1 and 3 retain the original `amount <= 9999` early break and every
operation formerly reached by falling through into pack 4. Pack 4 retains
unconditional grouping. Period cases 2/5 and suffix cases 1/2/5 also receive
independent identical bodies. No signature, header, compiler option or existing
function body changes. No further layout variation was tried.

The ordinary current owner toolchain emits 464 bytes, versus native 480.
Archived v5 emitted 452 bytes under its historical context; neither size is
matching evidence. Only the target is newly defined. The prelink extent guard
stops with exit 3 before linking. **No linked comparison, existing-function
preservation proof, static-data proof or complete profile gate is claimed.**

```text
BUILD sdk-startup-stringmanager
{"size": 464, "native_size": 480, "section_size": 464, "new_definitions": ["_ZNK13StringManager12formatAmountEibb"], "raw_sha256": "fade65adf8c2377939229177f82c074853640884bfc4edac1ac28055b2876ce2", "linked": false}
Prelink extent/helper guard failed; no linked comparison claimed.
```

Apply the patch only in an isolated checkout. With `WCH_BASE_LIB` configured,
`python tools/build.py sdk-startup-stringmanager` is expected to fail the
strict 480-byte extent assertion. Native placements are retained for the
function, pointer, guard, 64-byte buffer, cached length, 24-byte table and
suffix sections. Full function/table/pointer/suffix comparisons are configured;
NOBITS regions have explicit extent assertions. The four-byte space suffix
section, including compiler alignment, was independently confirmed in the
current unlinked object and archived v5 image; an initial private three-byte
assertion was corrected before preserving this patch. It was never linked.
No assertion or overlap check is relaxed. Runtime imports are the established
native libc and guard entries; no compiler output is edited.

The rejected candidate remains unapplied. Production ARM/Windows sources,
matched functions and progress remain unchanged. Further trials require new
evidence, rather than another case reorder.
