# Preferences::LoadAndApply

The complete 604-byte Thumb function `_ZN11Preferences12LoadAndApplyEPKc` at
`0x00343a39` matches the retail library. It reads and applies preference blocks
using the existing typed game interfaces and ordinary automatic FileStream,
DataStream, Block and BlockInt objects. Destructor headers, bodies and compiler
flags are unchanged. No existing function implementation was rewritten.

Native behavior includes the case-1 fallthrough into case 2 even when its
throttle read fails. The source preserves this explicitly. Volume conversion
retains the native float-to-double multiplication by `0.01`; no literal suffix
or extra validation was added. Cleanup and stored-stream-pointer reset follow
the original paths.

Reproduce with the configured retail toolchain:

```sh
python tools/build.py ai-startup-preferences
python tools/build.py --all
```

Exact comparison output:

```text
OK  _ZN11Preferences12LoadAndApplyEPKc  0x00343a39  604 bytes
OK SECTION .preferences_load_apply  0x00343a38  608 bytes
OK SECTION .preferences_load_dispatch  0x00433064  32 bytes
```

The section includes the function's 604 bytes plus four original alignment
bytes (`c046c046`). The next initializer starts at `0x00343c98`. Both the
complete 608-byte region and the 32-byte dispatch table compare exactly;
only the function's 604 bytes add matched credit. The initial private
604-byte section assertion rejected the real trailing alignment and was
corrected after independently checking this native boundary. No padding
or compiler output was edited. Function SHA-256:
`3df61033cdd31d8dd4bf215f841e00bbe3082ab7cf47eec2515b641352d9222d`.

At this function's integration, full verification passed 190 profiles and 10,512 function/section/region
comparisons. The affected caller/header closure passes five builds, 390 function
comparisons, 247 sections and five regions. All old Preferences comparisons,
including GetOrientation, SampleAndSave and both real D1 copies, remain enabled.
The only new code/data are this function and its original dispatch table.

This completes all 13 catalogue entries attributed to Preferences.cpp, totaling
1,786 reported code bytes. The full original source therefore qualifies for
Fully Linked progress; previously matched entries gain completion credit
without being counted again as new matches. This is ARM byte-match evidence;
native Windows execution was not tested and no port configuration changed.
