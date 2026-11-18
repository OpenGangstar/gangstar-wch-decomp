# Application frame and texture-reload updates

GlobalResumingUpdate matches 272 bytes at Thumb 0x002d4bc1; Update matches 264
bytes at Thumb 0x002d50f1. Both worker bodies matched on their first source forms.
The coordinator reused them unchanged and verified the combined source.

The texture updater preserves the original state queries, per-texture versus
whole-texture reload decision, frame counters, draw call and end-of-reload sprite
cleanup/music selection. The frame wrapper preserves the resuming early return,
unsigned timer delta, pre-update state snapshot, conditional draw when the state
is unchanged, and original floating-point timing statistics/reset threshold.
Pending _Update and _Draw bodies remain actual native Thumb imports.

The existing provisional ITextureManager source API now aliases the authentic
CTextureManager class. Its virtual prefix remains unchanged; native reload
methods use their genuine C++ names. The compatibility typedef is intentional:
removing it in a diagnostic changed an existing InfoHelp comparison. No fake
class, ABI-name alias, compiler-output modification or new engine body is used.
Application's field at 92 is an unsigned timestamp; its surrounding eight-byte
prefix/tail extents are preserved. No incomplete Application is instantiated.

Four file-static variables retain their original names, LOCAL bindings, four-byte
sizes and native BSS addresses: s_frameUpdateStart at 0x004b683c,
s_frameTotalUpdateTime at 0x004b6840, s_frameUpdateCount at 0x004b6844, and
s_frameUpdateTime at 0x004b6848. GCC emits the proper names naturally. The linker
asserts all four extents. These source variables are not imported replacements.

Shared native placement rules serve ApplicationHelpers and its GSFade consumer.
The ordinary merged string pool at 0x00413ca0 is 144 exact bytes; the separate
Loop message at 0x00413d94 is 28 exact bytes. Native ARM floating-point PLT and
Thumb function bindings preserve real call destinations. The legacy linker
required the BSS extent assertions in each top-level script rather than inside
the included placement file; that setup error was fixed before comparison.

Both actual executable verification images independently printed:

```text
OK  _ZN11Application20GlobalResumingUpdateEv  0x002d4bc1  272 bytes
OK  _ZN11Application6UpdateEv  0x002d50f1  264 bytes
OK SECTION .resume_update_literals  0x00413ca0  144 bytes
OK SECTION .application_update_loop  0x00413d94  28 bytes
```

All four LOCAL BSS objects were independently audited in both images. Full
coordinator `python tools/build.py --all` exited zero across all 180 profiles.
The private log/exit files are _scratch/application-frames-root-full.log and
.exit. Existing inputs, menus, touch handling, support, data and GOT comparisons
pass. No existing decompiled body, compiler flag or Windows port file changed.
Only the two new functions and their 536 code bytes receive matching credit.

The complete run passed 9,794 function, section and region comparisons.
