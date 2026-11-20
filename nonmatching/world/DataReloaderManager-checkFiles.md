# DataReloaderManager::checkFiles: original short-string accessor reuse

This function remains **unmatched**, with no progress credit. Native Thumb
`0x0034c119` and the complete retained candidate are both 248 bytes; 21 bytes
still differ. The assembly marker remains. Baseline: main PR #746,
`7fcefedd0e5ceb4358967c234de717c8ea5dbd2b`.

The reconstruction marks all monitored entries changed, then reloads each
changed entry through the existing filesystem interface. It passes the opened
file and filename to callback slot 8, closes the file by reference, clears the
changed flag and traces the filename. Failed opens log the error and filename.
The callback is named reload in the partial call interface; its original
spelling and ignored scalar return type are not established. No callback body
or new interface function is invented or credited.

The old string view supplied only opaque 24-byte storage. Pinned original
Android STLport [_string.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_string.h)
and [_string_base.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_string_base.h)
supply the short-buffer selection/accessor path. The private char-string view
uses its 16-byte buffer/dynamic-pointer union, finish pointer and end-storage
proxy. It reuses the already accepted empty-allocator proxy, retaining original
license notices and an altered-source notice. Allocation and destruction remain
actual native imports; this is a restricted ABI view, not a complete STL.
The native filename object begins at entry+28, its tag at+48 and its local-buffer
end at+44, agreeing with the observed 24-byte char-string representation.

The current pointer-vector view lacks its standard const_iterator and const
begin/end overloads. The source patch supplies only those nonvirtual APIs,
without data/layout changes. The first setup compile correctly failed on those
missing interfaces; the failed log/input snapshot is retained privately. An
initial setup script also stopped before writing source when a formatting marker
was too strict. Both setup issues were repaired before successful assembly.

Three ordinary caller forms were measured: separate loop iterators, one reused
iterator and a positive changed guard. All three produce **identical complete
function bytes and semantic relocations**. The three-identical-output stop rule
ends the pass; no further loop, source-order, hint or compiler-flag grid follows.
The JSON ledger preserves both source deltas and the full relocation signature.

## Reproduction and actual comparison

Apply only in an isolated baseline checkout:

```powershell
git apply nonmatching/world/DataReloaderManager-checkFiles.patch
python nonmatching/world/DataReloaderManager-checkFiles-probe.py --baselib C:/path/to/libsanangeles.so
```

The compile-only probe intentionally exits 3 after assembly and makes no native
acceptance claim. Raw target SHA-256:
`8e76e287df5460f24254a1fe65eae6679348b985f7e5c28e01ac0645eb8f4e45`.
To compare the real native-address link, apply the companion configuration:

```powershell
git apply nonmatching/world/DataReloaderManager-checkFiles-link.patch
python tools/build.py --baselib C:/path/to/libsanangeles.so sdk-startup-datareloadermanager
```

Actual normal build exit: **1**. Exact standalone target comparison output:

```text
MISMATCH  _ZNK19DataReloaderManager10checkFilesEv  0x0034c119
  expected : 45 46 e0 b4 38 4b 82 b0 05 1c 99 46 89 f7 af f8
  actual   : 45 46 e0 b4 38 4b 82 b0 06 1c 99 46 89 f7 af f8
  differs at 0xe
```

The complete target section fails too. All **11 existing functions and seven
existing section/region checks pass**, including both destructors, constructor,
startup helpers, vtable and native GOT. Both original string sections pass at
0x00435fd4/0x00435fe4. The only new primary object definition is the target;
all accessor helpers inline. The strict 248-byte extent assertion, real native
entry and full comparison remain. No compiled definition is replaced by an
absolute import or edited after compilation.

The linked target SHA-256 is
`98e52e529076aee56c998f0b15386a74f3b2ac185e62ff61cc22c1ed626f4386`.
An old archived candidate was 240 bytes; it is not a match and its overlapping
byte count is not used as a percentage or evidence of acceptance. The new
candidate restores native extent and all three high-register saves, but register
allocation and control-flow details still differ, beginning with the receiver
in R6 versus native R5 at +0x0e. All frozen link inputs remain stable across the
three measured builds. The private shared-header addition has not received a
full 190-profile consumer gate and remains unapplied in production. No matched,
fully linked or fuzzy progress is added.

The public primary-object probe reproduces exit 3 and the exact raw hash above.
Both source/link patches and the two variant deltas reconstruct the measured
text in an isolated checkout. The normal negative build retains the unchanged
production flags; only the quoted header APIs and local source view are added.
