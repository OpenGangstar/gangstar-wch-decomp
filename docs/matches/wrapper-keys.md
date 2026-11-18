# Native application key wrappers

Both first source candidates match their complete 36-byte native functions:

```text
OK  appOnKeyUp  0x002d2655  36 bytes
OK  appOnKeyDown  0x002d2679  36 bytes
```

The wrappers load the actual TU-local application pointer, null-check it and
forward the unchanged key to appKeyReleased/appKeyPressed. They do not call
GetInstance. Native appInit stores the GetInstance result in this same pointer;
appDeinit later reads it for shutdown. One ordinary static Application* app
supplies the actual four-byte zero-initialized LOCAL storage at 0x004b6720.
No Application instance or constructor is introduced.

Shared linker placements retain both executable wrappers and the pointer in
all eight images that link path-name.o. Every consumer explicitly compares both
functions. Top-level size assertions and independent final-ELF checks prove the
storage is LOCAL, four bytes, SHT_NOBITS and at its native address. Imports keep
actual Thumb metadata and never override compiled handler definitions.

Coordinator verification freshly rebuilt 21 profiles with 1,903 passing
function, section and GOT comparisons, including all seven dependency consumers,
the JNI bridges and existing Application handlers. Log and exit status:
_scratch/wrapper-keys-root.log and .exit. No existing function body, shared
header, Windows source or compiler output changes.
