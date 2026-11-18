# Native application update wrapper

The first source candidate matches all 84 bytes of appRun:

```text
OK  appRun  0x002d269d  84 bytes
```

A positive signed resume counter is decremented; only reaching zero calls
Application::Resume. Otherwise the native callback-finished flag is cleared,
Irrlicht Timer::tick runs, Application::Update runs and the flag becomes one.
The original application pointer is reused without adding a null guard.
Both global flags remain native imports; no extra storage or implementation is
invented. The restricted static Timer declaration follows the licensed original
Irrlicht interface and supplies no engine body or Timer object.

All eight wrapper images retain and independently compare the actual native
executable definition. Original Thumb imports preserve the three call targets.
Coordinator affected graph: 21 profiles, 1,919 function/section/GOT comparisons
passed, including both matched Application callees and the JNI bridge unit.
Proof: _scratch/wrapper-run-root.log and .exit. No existing body, shared header,
compiler output or Windows source changes.
