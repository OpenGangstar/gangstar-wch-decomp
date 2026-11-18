# Native application initialization wrapper

The saved first reconstruction of appInit now matches in the integrated ARM
checkout after its genuine Application::InitWin32 prerequisite was completed.
The function body was reused unchanged.

```text
OK  appInit  0x002d2759  192 bytes
```

The wrapper sets the native resource-path length to 32, allocates 33 bytes,
zeroes them and copies the original 32-character path. The source literal includes
its terminating zero; the complete aligned 36-byte native read-only region is
compared. It calls the original device factory with the observed driver value 9,
signed dimensions divided by 1.5, 16 bits and the original false/null arguments,
then obtains Application::GetInstance and calls InitWin32.

The actual exported factory ABI uses dimension2d<int>. Existing dimension storage
is unchanged; the two faithful Irrlicht constructors are reused inline. The
original spelling of driver enumerator 9 remains unknown and is identified as
DriverType9 rather than assigned a guessed renderer name. The engine factory
implementation remains native. No out-of-line dimension helper is emitted.

All eight wrapper consumer images retain the real function and resource-path
section at their original addresses, explicitly compare them and use the true
Thumb imports for the factory, singleton accessor and initialization method.
The native allocation, memory and floating-point PLT bindings are preserved.
An independent retail ELF read confirmed all 192 function bytes and all 36
resource-path bytes. The existing global app/device storage is reused; no fake
objects or compiler-output edits are involved.

The previous header-context blocker and failed attempts remain documented in the
local saved package. The current function required no source search, no additional
Application declarations and no further existing-function edits. No Windows port
source or build configuration changed.

Fresh `python tools/build.py --all` passed with exit zero: 182 profiles,
10,250 function/section/GOT comparisons. appInit and its path region pass in
all eight consumers; every earlier match remains exact. Local proof:
_scratch/wrapper-app-init-root-full.log and .exit.
