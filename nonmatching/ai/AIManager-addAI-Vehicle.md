# Vehicle AI factory: common NPC allocation tail

Unmatched candidate for `AIManager::addAI(Vehicle*, StateID)`, Thumb
`0x00340305`, native size 336 bytes. No matching credit or assembly deletion.
Baseline: `39ae587ea4430b0b566500ef933dd8344e4e9fb3` (PR #740).

This single bounded follow-up reuses the already matched NPC factory's genuine
allocator and common receiver-list tail. The six archived Vehicle forms used
an inline append adapter. Vehicle constructors, case-specific transitions and
the existing wanted-level event interface remain intact. The candidate adds
only private friend access and the current CopVehicleController declaration;
no existing function body changes. The class declaration is copied from its
existing source and would require coordinated header extraction if accepted.

The ordinary matching toolchain emits 244 bytes, versus 336 retail bytes.
Only the assigned function is newly emitted. The prelink extent guard stops
with exit 3 before linking; **no linked comparison or preservation proof is
claimed**. Raw function SHA256:
`78555f379a321d8dd2ff172b956ba9e59c60b5912146e8b2592bd0fb1c9bae0c`.

```text
BUILD ai-startup-aimanager
{"size": 244, "native_size": 336, "section_size": 244, "new_definitions": ["_ZN9AIManager5addAIEP7VehicleN8gameloft2ai7StateIDE"], "raw_sha256": "78555f379a321d8dd2ff172b956ba9e59c60b5912146e8b2592bd0fb1c9bae0c", "linked": false}
Prelink extent/helper guard failed; no linked comparison claimed.
```

Apply the patch only in an isolated checkout. `python tools/build.py
ai-startup-aimanager` with `WCH_BASE_LIB` configured is expected to fail the
strict 336-byte linker assertion; the patch never relaxes that assertion.
The private probe also checks newly emitted definitions before linking.
No further source form was tried. New evidence is required before reopening
this common-tail hypothesis. Production ARM and Windows sources remain unchanged.
