# Native touch wrapper

The second source candidate matches the complete 152-byte Thumb appOnTouch:

```text
OK  appOnTouch  0x002d2511  152 bytes
```

It writes the original pointer identifier, updates the actual held-button flag,
selects release/press/move from the native action codes and ignores unheld moves
or unsupported actions. A shared event-field assignment preserves native control
flow. Coordinates use the original double constant 0.6666 and truncating integer
conversion. The existing event/device interfaces are reused without new layouts.
The event is dispatched through the original virtual postEventFromUser slot.

One genuine static device pointer supplies four LOCAL zero-initialized bytes at
0x004b671c, corroborated by the original appInit store. The held flag and pointer
identifier remain imported globals. No getter, null guard or input validation is
invented. The literal pool is included in the complete function comparison.

The shared wrapper linker include retains the target and pointer in all eight
consumer images. Every image compares the new executable definition and checks
the storage extent. Independent final-ELF checks prove LOCAL binding, NOBITS,
four-byte size and native address. Real double-conversion/multiply PLT addresses
preserve the native calls without altering compiler output.

Coordinator graph: 23 profiles, 2,036 passing function/section/GOT checks,
including the existing touchscreen receiver, JNI bridges and wrapper consumers.
Log and exit: _scratch/wrapper-touch-root.log and .exit. No old function body,
shared header or Windows source changes. The first 160-byte candidate receives
no credit; only the exact second candidate is accepted.
