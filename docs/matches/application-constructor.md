# Application constructor

`Application::Application()` matches the retail ARM constructor at Thumb
`0x002d51f9`. Its complete 148-byte section, including its literal pool and
alignment bytes, matches. C1 and C2 are genuine compiled aliases in the same
section at the same address; neither is an absolute import.

The constructor initializes the existing members and registration containers,
then obtains the default language from the real JNI `nativedetectPhoneLang`
definition. The body reuses the previously preserved v3 algorithm. Its only
current-type adaptation is `unknown60 = 0`, because that member is a pointer.
No compiler flags, branch hints, register bindings, output edits, or prescribed
comparator/padding bytes are used.

## Source reconstruction

The prerequisite restores the authentic STLport construction boundaries over
the existing storage. The registration sentinel is a POD link pair. An
allocator-derived proxy copies it by value, and the list constructor then
self-links it. The map header is constructed through its allocator proxy base
before the derived count and const-reference comparator copy. The canonical
allocator retains its allocation ABI and the genuine empty construction,
conversion, destruction, rebind, and recognition interfaces. The adaptation is
restricted to the three existing registration pointer families.

The primary references are pinned Android STLport sources at commit
`e64e7c849b0b659d3e198e4efaed563601e554be`:

- [_list.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_list.h), particularly the POD node and list-base construction.
- [_alloc.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_alloc.h), particularly allocator construction and the by-value allocator proxy.
- [_tree.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_tree.h), particularly the header base and derived count/comparator construction.
- [_map.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_map.h), particularly the default tree construction.

The original permissive license notices are retained. These references support
the reconstructed interfaces and construction semantics; they do not establish
the exact retail STLport version or configuration.

Actual ARM ELF data and DWARF verify Application's 180-byte size and 4-byte
alignment, all 39 data-member offsets, the 8-byte registration lists, and the
24-byte map. The map header is at offset 0, count at 16, and comparator at 20.
No storage or virtual slots were added. Six existing Application readers only
change their member paths to the real `_M_node._M_data` sentinel.

The header prerequisite also requires a disclosed compatibility edit in the
already matched `Menus::InfoHelp::Notify`: its adjacent zero-initialized
`firstPage` declaration precedes `category`. The loop and all operations are
unchanged. This restores its complete native 284-byte match after the genuine
header context changed compiler scheduling.

## Verification

Before adding the constructor, the complete prerequisite gate passed all 190
profiles: 5,415 function comparisons, 5,321 section comparisons, and 181 region
comparisons, totaling 10,917. The command exited 0 with no mismatches or skips.
The original per-profile compiler/assembler/linker selection was retained.

The constructor replay printed:

```text
OK  _ZN11ApplicationC1Ev  0x002d51f9  148 bytes
OK  _ZN11ApplicationC2Ev  0x002d51f9  148 bytes
OK SECTION .application_ctor  0x002d51f8  148 bytes
```

The replay exited 0. All 144 existing Application/JNI comparisons remained
exact: 85 functions, 57 sections, and 2 GOT regions. Adding the two constructor
alias comparisons and its complete section gives 147 passing comparisons.
The actual and retail 148-byte SHA256 are both
`95b28574ae2cf97b30d8c5f91277f100d7ef1d508e4e87fd045bf4ae0ede55f3`.
There are no differing bytes.

The real compiled JNI callee remains a 52-byte Thumb definition at
`0x002d18f9`. The constructor's native BL at `0x002d5268` targets its code at
`0x002d18f8`, and the callee's complete native bytes pass in both verification
images. The constructor's obsolete external Thumb import is removed so the
real definition has normal linker precedence.

Every generated native executable section in the two-image graph was compared:
86 complete sections totaling 8,068 bytes are exact. The two synthetic
`.verification` sections at `0x00600000` are unchanged generated GOT harnesses;
they have no retail placement and are not native game-code matches. Emission
inventory finds only the two constructor aliases as new code definitions, with
no changes to existing definitions or newly outlined helpers. The compiler
naturally emits the native byte at Application offset 176; source assigns no
semantic meaning or prescribed value to that representation byte.

## Integrated repository verification

The independent coordinator build ran `python tools/build.py --all` with the
original per-profile toolchains. Its final result was 190 profiles, 5,419
function comparisons, 5,323 section comparisons and 181 region comparisons:
10,923 passing comparisons, exit 0, with no mismatches or skips. All 941 frozen
source, manifest, linker, tool and nonmatching inputs remained unchanged during
that invocation.

The first integration attempt stopped after 9,137 passing comparisons because
GSFade still declared the constructor as an external Thumb import. The compiled
dependency correctly rejected that stale binding. The GSFade manifest now uses
the real constructor, checks both aliases and its section, and places that
section at its native address with the same strict 148-byte assertion. No
existing comparisons were removed. The complete gate then passed.

Only the two verified constructor assembly markers are removed. The catalogue
counts both original alias entries, adding two matched functions and 296
catalogue bytes; the physical constructor is one shared 148-byte body. This
does not complete Application.cpp: UnRegisterForUpdate and OnEvent remain
pending, so no new fully linked unit is claimed.
