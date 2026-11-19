# PlayerTest::Update: current-hierarchy candidate

This function is **not matched**. The original assembly remains in the queue,
and this patch contributes no matched, fuzzy or fully linked progress.

The baseline is `16cf0c73bca9fb1064892cf85ab04bd04042fa46` (PR #729).
Apply the candidate only in a separate checkout of that commit:

```powershell
git apply --check nonmatching/ai/PlayerTest-Update.patch
git apply nonmatching/ai/PlayerTest-Update.patch
```

The patch changes three prerequisite headers and appends the existing safe
candidate to `src/game/ai/PlayerTest.cpp`. It preserves the genuine
`IMapTrackable, Character` hierarchy and existing implementations. It does not
change compiler flags, match configurations, event constructors or generated
tables. The patch SHA256 is
`27e0030d5ca06ed26cf42ccddfaafd6b1d3cc763bd620301e1d860cf92092970`.

## Verification and limits

Before adding the candidate body, the prerequisite-only snapshot passed all
190 profiles and 10,687 native comparisons: 5,304 functions, 5,202 sections and
181 regions. Eleven ARM layout assertions also passed. This preservation gate
does not prove that the appended candidate matches or preserves linked callers.

The single current-context replay compiled and assembled successfully with the
owning profile's original toolchain and flags. Its actual emitted function is
**2,192 bytes**, whereas native `_ZN10PlayerTest6UpdateEv` at Thumb
`0x00304ec9` requires **2,228 bytes**. The strict extent check failed; the run
stopped before linking. There is no current linked byte comparison to report.
Raw object function SHA256:
`77468d5a5079709f0a934afab597d71837c3f0d37a20c63be3124ed60bcc96cd`.

Historical candidates used different surrounding headers and emitted 2,212
bytes. That historical size is not a current preservation result. No padding,
compiler-output edits or artificial progress credit are permitted.

## Reproducing the pre-link extent

Use the toolchain and flag arrays in
`config/matches/ai-startup-playertest.json`. On Windows, prepend the existing
`toolchain/cygwin32/bin` directory to `PATH`. Run that toolchain's
`libexec/gcc/arm-eabi/4.2.1/cc1plus.exe` with `-quiet`, the manifest's
`compiler_flags`, `src/game/ai/PlayerTest.cpp`, and `-o candidate.s`. Then run
its `bin/arm-eabi-as.exe` with the manifest's `assembler_flags` and
`-o candidate.o candidate.s`. Do not substitute a compiler for all profiles.

Inspect the object with existing repository tools:

```python
from tools.elf import ElfFile
from tools.check import find_symbol

obj = ElfFile.load("candidate.o")
print(find_symbol(obj, "_ZN10PlayerTest6UpdateEv").st_size)
```

The recorded candidate prints `2192`. Stop before linking when the extent
differs from `2228`. The normal owning profile does not currently select this
pending function, so passing its existing checks alone would not prove a match.

## Next evidence

The native function contains 2,112 Thumb-mapped bytes (including alignment)
and a 116-byte literal pool; the current candidate contains 2,084 Thumb-mapped
bytes and a 108-byte pool. The two
native-only pool references are `PlayerTest::SetSpeed` and the `IEvent` vtable.
Native `SetSpeed` has weak/default ELF binding, whereas the current definition
has global/default binding in this pinned baseline. The later declaration-only
correction passed a separate full 190-profile preservation gate. Its one
unchanged-body replay emits 2,200 bytes, still short of native 2,228; it also
stops before linking. Its raw function SHA256 is
`8083e27abd02e9a9c653af4daff59b3b7f6064dbf2ec10e66192f26924778ee9`.
This patch deliberately preserves the original baseline experiment. See
[the accepted linkage correction](../../docs/matches/player-set-speed-linkage.md).

Native event construction sometimes retains a base-vptr store and sometimes
elides it. Changing the shared event constructor previously regressed the
matched 84-byte cleanup function. That rejected change is excluded here.
