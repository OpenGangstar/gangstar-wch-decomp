# Application::OnEvent: unmatched reconstruction

Target: `libsanangeles.so`, Thumb `0x002d5eb9`, 596 bytes. This is an
unapplied candidate patch, not a matched definition. The assembly marker and
catalogue status remain pending. Apply only in a disposable matching checkout.

## Reproduction and exact result

The patch applies to source context `bc94763e` (PR733). With the existing
matching toolchain and an independently supplied retail library:

```sh
git apply --check nonmatching/app/Application-OnEvent.patch
git apply nonmatching/app/Application-OnEvent.patch
python tools/build.py application-helpers --baselib /path/to/libsanangeles.so
```

The original per-profile compiler and assembler flags are unchanged. Expected
result is a failed target comparison:

```text
MISMATCH  _ZN11Application7OnEventERKN3irr6SEventE  0x002d5eb9
  expected : d3 58 98 47 01 20 26 e7 0d 4b 4e 46 42 46 f3 58
  actual   : d3 58 98 47 01 20 26 e7 43 46 98 6b 0c 4b 4e 46
  differs at 0x1f6
MISMATCH SECTION .application_on_event
  expected : d3 58 98 47 01 20 26 e7 0d 4b 4e 46 42 46 f3 58
  actual   : d3 58 98 47 01 20 26 e7 43 46 98 6b 0c 4b 4e 46
  differs at 0x1f6
```

Both functions are 596 bytes. Exactly 570 bytes agree; 26 consecutive bytes at
`+0x1f6` through `+0x20f` differ in the left-button construction block's load
and register scheduling. The native 104-byte frame and all six temporary
positions agree: right button 0, middle 20, left 40, keyboard 60, wheel 80,
move 92. The complete 32-byte switch table matches at `0x00413dd8`.

The linked candidate SHA256 is
`f24ae8dca52474db0547592e371ac047f0e9e3c7cfadede58eabc37b2a0bc302`;
the native SHA256 is
`863d9d111c00696fe7a4feaddcf5ca9ece64f7978610ea0a28ea280d8afd3e61`.
The owner/JNI invocation passes 87 existing functions, 58 existing sections,
the new switch-table section, and two GOT regions. It exits 1 because the
target and its full section fail. No broader post-body gate is claimed.

## Reused interfaces and evidence

The reconstruction uses the already matched Application update/draw methods'
licensed STLport iterator, preserving boolean OR and every receiver callback.
All seven earlier saved forms used raw node loops. Reusing the actual iterator
removes the extra empty-list cold block, restoring the native 596-byte extent.

Full-expression event temporaries reuse the source pattern in the matched
VirtualButton release handler. Unlike the earlier named locals, they recover
the native 104-byte storage and wheel receiver-before-conversion boundary.
Natural switch case order recovers the six native temporary offsets. Pinned
[GCC 4.2.1 stack allocation](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/cfgexpand.c)
supports the per-size creation-order inference; it does not uniquely establish
the original source spelling or retail compiler patches.

The three-file prerequisite recovers the four existing event payloads, the
SEvent key union and driver virtual slots 116/117. Payload layouts passed 34
ARM frontend assertions, and native vtable targets were checked. Its separate
190-profile/10,923-comparison preservation gate predates the target body.
Existing destructor bodies/attributes and original comments are preserved.
These prerequisites remain inside the unapplied patch.

## Link setup and limitations

The first link correctly failed because an existing unreferenced 16-byte
compiler initializer overlapped the newly reconstructed switch table, and
`__aeabi_f2iz` lacked its ARM PLT binding. The patch supplies the normal retail
helper binding. It retains the initializer at verification-only address
`0x00610000`, asserts its 16-byte extent, and adds no native-data credit.
Actual relocation inspection finds no users of this zero initializer. No code
or data is discarded, no compiled definition is replaced, and no compiler
output is edited. All previously checked native constructor bytes still pass.
This remains a partial verification image, not a complete linked library.

Earlier 608-byte and 600-byte forms, original failures, object files, toolchains
and native analysis artifacts remain private. No extra target form is justified
without new evidence; no match, linked-unit or fuzzy credit is claimed.
