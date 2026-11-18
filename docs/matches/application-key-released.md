# Application released-key handling

`Application::appKeyReleased(int)` matches all 348 bytes at Thumb 0x002d45ad on its
first source candidate. It reuses the previously reconstructed press-handler
logic while preserving the native movie-state guard, cutscene guard, key-reset
ordering, false/true event arguments and special splash-state notification.
The otherwise similar pressed implementation remains separately owned until
its complete comparison and dependency checks are accepted.

The Application interface now declares this genuine method. Its existing opaque
eight-byte region at144 is split into four unchanged bytes and lastPressedKey
at148; following soundThreadPlaying storage remains at152. Application remains a
partial layout and is never instantiated. Precise StateMachine friendship permits
access to the existing state-stack object; no StateMachine storage or methods
change. Both original native globals and nativeNotifyPause remain imports.

The coordinator retains the real generated new function at0x002d45ac in both
ApplicationHelpers and GSFade dependency images. No compiler flag, old body,
assembly, register constraint or output byte was changed for this function.

Scoped coordinator output includes:

```text
OK  _ZN11Application15ProcessKeyEventEbi  0x002d40fd  268 bytes
OK  _ZN11Application14appKeyReleasedEi  0x002d45ad  348 bytes
OK  _ZN15TouchScreenBase5getIDEl  0x0034c599  68 bytes
```

Full coordinator `python tools/build.py --all` exited 0 with all 9,789 comparisons
passing across 180 profiles. Existing menu, touch, script, callback and GOT/data
comparisons are preserved. The private full log and explicit exitcode are
_scratch/key-released-root-full.log and .exit. Only this new 348-byte function
receives additional matching credit.

The worker's separate header validation initially forced NDK 1.6 on Logs, whose
manifest deliberately uses the normal r4b default, causing alignment-fill
mismatches. The authorized correction used each manifest's actual toolchain,
without modifying any source or generated output. Its corrected deduplicated
proof covers92 profiles, 3,432 functions and 3,921 section/region checks. The
initial failed command remains documented; it is not reported as a passing run.
Coordinator full verification independently used normal per-manifest settings.
