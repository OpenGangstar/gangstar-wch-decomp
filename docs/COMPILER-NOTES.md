# Compiler baseline (2026-10-22)

The Windows Android NDK r4b GCC 4.2.1 can produce the retail bytes of two
small functions. This establishes a usable compiler and comparison path;
it does **not** establish the complete game's compiler flags or patch set.
No function has been marked matched by this experiment.

## Local tools

All downloaded archives and extracted binaries live under ignored
`toolchain/`. The retail library lives under ignored `baselib/`.
No system installation or global PATH change is needed.

Download these archives into `toolchain/downloads/`:

| Local archive name | Source |
| --- | --- |
| `android-ndk-r4b-windows.zip` | [Google](https://dl.google.com/android/ndk/android-ndk-r4b-windows.zip) |
| `cygwin-3.3.6-1-x86.tar.xz` | [Cygwin x86 archive](https://cygwin.com/ftp/cygwin-archive/20221123/x86/release/cygwin/cygwin-3.3.6-1.tar.xz) |
| `zlib0-1.2.11-1-x86.tar.xz` | [Cygwin zlib](https://cygwin.com/ftp/cygwin-archive/20221123/x86/release/zlib/zlib0/zlib0-1.2.11-1.tar.xz) |
| `libgcc1-10.2.0-1-x86.tar.xz` | [Cygwin libgcc](https://cygwin.com/ftp/cygwin-archive/20221123/x86/release/gcc/libgcc1/libgcc1-10.2.0-1.tar.xz) |

Observed SHA-256 values (download fingerprints, not independent publisher
signature verification), in the same order:

```text
b6b859e18efa560fa7c6c84e9f9b7c21de360dadb365be8f100d810147728ed4
cb39b20f4bffa59efd7df2f718d53b76c811bd83f52038592c81c1538a845798
5f11aa18a48dd4824cc876a0c51472fc746740943b115c412922e522de1974ed
b3620491d373e297f135385719355109a02e4ceea520374dbb55d927572b7116
```

Extract the NDK into `toolchain/android-ndk-r4b/`, preserving the archive's
layout. Extract only these runtime files into `toolchain/cygwin32/bin/`:

* `usr/bin/cygwin1.dll` from the Cygwin archive;
* `usr/bin/cygz.dll` from zlib;
* `usr/bin/cyggcc_s-1.dll` from libgcc.

The Cygwin and GCC executables must both be 32-bit. The existing MSYS2
64-bit runtime cannot replace these DLLs. Cygwin documents its final x86
release and archive in its [end-of-life announcement](https://cygwin.com/pipermail/cygwin/2022-November/252542.html).

## Repeat the probe

From PowerShell, with Python on PATH:

```powershell
& .\config\toolchain\Test-Baseline.ps1
```

In this agent environment, Cygwin executables must run outside the sandbox:
inside it they fail at startup with an illegal DLL relocation error.
Outside it, the GCC driver can still fail during `fork` with a heap
allocation error. The script invokes `cc1plus.exe` and `arm-eabi-as.exe`
directly to avoid that driver fork. It passes compiler-generated assembly
to the assembler without any edits.

The source probe is `config/toolchain/probes/importgl.cpp`. Flags:

```text
-O2 -fno-strict-aliasing -fno-rtti -fno-exceptions
-mthumb -mthumb-interwork -march=armv5te -mfloat-abi=softfp
```

Assembler arguments:

```text
-march=armv5te -mfloat-abi=softfp -mfpu=vfp -meabi=4
```

Comparison output:

```text
OK  importGLInit  0x002d16ed  4 bytes
OK  importGLDeinit  0x002d16f1  2 bytes
```

The bytes are `01 20 70 47` and `70 47`, respectively. Neither function
has relocations. These very small integer-only functions cannot distinguish
optimization levels, floating-point settings, exception settings or RTTI.
Their assembly queue entries remain intact.

## Corrections and remaining work

* The retail `.comment` contains only `GCC: (GNU) 4.2.1`. Its embedded paths
  identify an NDK build, but not the exact release or downstream changes.
* [The NDK changelog](https://android.googlesource.com/platform/ndk/+/tools_r21/docs/CHANGES.html)
  records GCC 4.2.1 as a compatibility compiler in r3/r4 and its removal in
  r5. The r4b Windows archive still downloads directly from Google.
* Retail `e_flags = 0x04000002` encodes EABI version 4. It does not set the
  hard-float bit. See [Arm's ELF specification](https://github.com/ARM-software/abi-aa/blob/main/aaelf32/aaelf32.rst#elf-header).
  Floating-point code still needs dedicated experiments.
* `tools/check.py` needed to clear the Thumb marker before extracting object
  bytes and before deciding whether relocations touch a function. Regression
  tests cover both boundaries and preserve odd data/non-ARM offsets.
* Functions containing unresolved relocations are still rejected by the raw
  checker. `python tools/build.py logs` now uses the original GNU linker to
  resolve calls, GOT-relative string references and retail section placement.
  It checks all six functions plus the whole code and string sections.
* `-mtune=xscale` reproduces the retail Logs PIC instruction scheduling;
  `-O2 -fpic -fno-toplevel-reorder` also preserves its observed source order.
  Both `-O2` and `-Os` gave the relevant instruction sequence with this tune,
  so this unit does not distinguish their use in the original build.
* The probe does not require system headers or engine types. Larger functions
  will need headers, reconstructed class layouts and further flag recovery.

## Earlier assembler for ADPCM

The decoder's two-byte literal-pool padding matches NDK 1.6 r1's binutils
2.17 (`00 00`), whereas r4b binutils 2.19 emits `c0 46`. The complete decoder
matches with the earlier GCC 4.2.1 toolchain. Its manifest selects that version
without changing the Logs toolchain. This is evidence about these units,
not proof that every retail object used one specific NDK release.

Download [Google's NDK 1.6 r1 Windows archive](https://dl.google.com/android/ndk/android-ndk-1.6_r1-windows.zip)
and extract it into `toolchain/android-ndk-1.6_r1/`. Its observed SHA-256 is:

```text
fcfe28edfe4a28fe50d352569ba27d873ffd48b35f93b1d3c04db7f03284d46d
```

It uses the same local 32-bit Cygwin runtime. Run:

```sh
python tools/build.py adpcm-state adpcm-decoder
python tools/build.py --all
```

The generated GOT reference harness and its verification scope are explained
in [matches/adpcm.md](matches/adpcm.md). No compiler output is rewritten.

## Enum width in the legacy toolchain (2026-10-28)

The local NDK 1.6 r1 GCC 4.2.1 defaults to one-byte storage for the small signed
enum in [the standalone probe](../config/probes/enum-width.cpp).
`-fno-short-enums` changes it to four bytes. A following pointer hides this
difference in the probe record's total extent:

| Probe | Default flags | With `-fno-short-enums` |
| --- | ---: | ---: |
| `sizeof(EnumWidthProbe)` | 1 | 4 |
| `sizeof(PaddedEnumProbe)` | 8 | 8 |
| `sizeof(bool)` | 1 | 1 |

Matching a record's total size therefore does not establish an enum field's
storage width. Check field accesses and generated instructions as well.

Reproduce on Windows with the same Cygwin runtime used above. This compiles
object files only and needs no game data:

```powershell
$probeCompilerRoot = Join-Path (Get-Location) 'toolchain/android-ndk-1.6_r1/build/prebuilt/windows/arm-eabi-4.2.1'
$enumProbeDir = Join-Path (Get-Location) 'build/enum-width'
New-Item -ItemType Directory -Force $enumProbeDir | Out-Null
$env:PATH = (Join-Path (Get-Location) 'toolchain/cygwin32/bin') + ';' + $env:PATH
foreach ($enumProbeMode in @('default', 'integer')) {
    $enumProbeFlags = @()
    if ($enumProbeMode -eq 'integer') { $enumProbeFlags = @('-fno-short-enums') }
    & "$probeCompilerRoot/libexec/gcc/arm-eabi/4.2.1/cc1plus.exe" -quiet -O2 -mthumb -march=armv5te -fdata-sections @enumProbeFlags config/probes/enum-width.cpp -o "$enumProbeDir/$enumProbeMode.s"
    if ($LASTEXITCODE -ne 0) { throw 'Enum probe compilation failed' }
    & "$probeCompilerRoot/bin/arm-eabi-as.exe" -march=armv5te -meabi=4 -o "$enumProbeDir/$enumProbeMode.o" "$enumProbeDir/$enumProbeMode.s"
    if ($LASTEXITCODE -ne 0) { throw 'Enum probe assembly failed' }
    & "$probeCompilerRoot/bin/arm-eabi-readelf.exe" -x .data.probe_enum_width -x .data.probe_record_width -x .data.probe_bool_width "$enumProbeDir/$enumProbeMode.o"
    if ($LASTEXITCODE -ne 0) { throw 'Enum probe inspection failed' }
}
```

The legacy readelf displays `00000001`, `00000008`, `00000001` for the default
object, and `00000004`, `00000008`, `00000001` for the integer-width object,
in the section order requested above.

This does not identify the retail game's global enum flags. Its 16-byte
`.ARM.attributes` section contains an empty AEABI file-attribute subsection;
`arm-eabi-readelf -A` reports no enum-width tag. In the current Rocket near miss,
an explicit shape enum with `-fno-short-enums` reproduces the same target bytes
as the partial integer-field view and preserves its existing comparisons, but
does not improve the 125 differing bytes. No production flag or matched-function
credit was changed by this experiment.

## Retail debug information coverage

The retail library has DWARF sections, but its 242-byte `.debug_info` contains
one assembler compilation unit for GCC's `config/arm/ieee754-sf.S`, covering
`0x00401034` through `0x00401088`. It contains no game C++ type or member-layout
entries. `arm-eabi-readelf --debug-dump=info baselib/libsanangeles.so` reproduces
that coverage. A different build with game C++ DWARF could provide useful type
information; the debug-section names in this retail build alone do not provide it.

## Installed GCC 4.2.1 identity audit (2026-11-19)

The existing NDK 1.6 r1, r3 and r4b installations contain genuinely distinct
compiler code, despite their common GCC 4.2.1 version string. Both complete
`cc1plus.exe` hashes and PE code-section hashes differ. The installed compiler,
assembler and linker executables match their corresponding local archive
members; duplicate assembler/linker paths within one SDK are exact aliases.
No executable was patched or newly downloaded for this inventory.

| NDK | `cc1plus.exe` bytes | SHA-256 |
| --- | ---: | --- |
| 1.6 r1 | 16,231,115 | `914b3fe8024cdfe8358b6fc6f78ce672136db1f03ccd609a8cb8a432de7bb734` |
| r3 | 7,011,268 | `6f9f288e1313fae4cba64239a06b19613f52c2c1d870355dab767f696c1ee643` |
| r4b | 6,234,112 | `9a2945efb802aac30e6584476003b4c174ec84e2b06a0fab3f8cc89e14b5fe4c` |

The 1.6 r1 driver records the `digit/Android` build path seen in retail runtime
debug information and uses binutils 2.17. The r3 and r4b build paths differ and
their binutils versions are 2.19. Retail's lone assembler compilation unit
therefore supports the earlier runtime lineage, but does not identify the
compiler binary or patch set used for game C++. Linking an older runtime into
objects produced by a different compiler remains possible.

Binary identity is not a function-matching result. The existing r4b ASprite
experiment changed the whole SDK, retained the target mismatch and regressed
14 old functions and nine regions; those failures cannot all be attributed to
the C++ frontend because assembler and linker also changed. A controlled
frontend comparison must keep source, flags, assembler, linker and native
placements fixed, and report its actual old closure. Such a mixed diagnostic
does not establish an original or production toolchain.

### Controlled r3 frontend result

One such diagnostic compiled only the frozen 220-byte `Menus::Map::Notify`
owning translation unit with the r3 frontend, holding all dependency compilers,
assembler, linker, source and flags at their original 1.6 r1 settings. The
target's raw bytes and semantic relocations were identical to the 1.6 output;
there was no observed target code-generation improvement.

All 391 dependency function checks and 284 region checks passed. The owner
link then failed on orphan overlaps: 26 existing weak sections changed from
`.gnu.linkonce.t.*` names to `.text.*` naming/group conventions, outside the
old placement selectors. All 257 mapped owner allocated payloads and 572
dependency payloads remained unchanged. This was a linker-layout compatibility
failure, not evidence that those old function bytes changed or that a native
extent assertion failed.

No placement repair or second compile was attempted. The linked native target
comparison and full 637-function/417-region closure were not completed in this
experiment. The production compiler remains unchanged. Map subsequently matched
with the original 1.6 toolchain and a bounded source-order correction, as
documented in [its match note](matches/map-notify.md).

### Controlled animation-duration frontend comparison

A separate controlled experiment used the frozen canonical
`ASprite::GetAnimDuration(int)` candidate at Thumb `0x00349d81` (native 82 bytes).
All 955 source, configuration, tool and nonmatching input files were identical
across three contexts. Only the owning C++ frontend executable changed. The
original 1.6 r1 assembler and production options were retained.

| C++ frontend | Function bytes | Input-section bytes | Result |
| --- | ---: | ---: | --- |
| NDK 1.6 r1 | 80 | 80 | Stopped before linking |
| NDK r3 | 80 | 80 | Stopped before linking |
| NDK r4b | 80 | 80 | Stopped before linking |

All three emitted the identical complete unlinked target:
`c8cda221040383236d7bb1e8c719bc0963bf8832c4eceefd266fe5b2d7b13d3a` (SHA256).
Each emitted only the intended new function. Compiler and assembler succeeded;
the prelink native-extent guard deliberately exited 3 because 80 is not 82.
The linker and harness frontend were not invoked after that guard. No linked
native comparison or old-function/region closure is claimed for these runs.

These installed frontend choices do not resolve this candidate's fused signed
halfword load. This is a case-specific result, not proof that the frontends are
interchangeable for all code. The production toolchain remains unchanged. The
earlier Map::Notify and ASprite::GetAnimIdx frontend experiments are separate;
an older inventory's absence of r3 records must not be read as a current claim
that r3 has never been tested.

### Pickup proximity value capture

After review of the six archived `GS3DStuff::checkPickableProximity` forms,
one bounded value-lifetime experiment combined a named by-value `GetPosition()`
result with a complete vector subtraction before the three range tests. The
existing `PlayerTest`/`Character` position interfaces already return the correct
vector value; no ABI or shared-header correction was justified.

The current production frontend emitted 360 target bytes versus native 356 at
Thumb `0x002deba1`, with an additional out-of-line `Character::position()` helper.
The complete unlinked target SHA256 was
`3b05a35d2fccec25b7ac8bc42b349099c7c667af12a1224a10f69307af65a465`.
The experiment stopped before the owner linker. Dependency checks printed by
the build do not establish an owner native comparison or old-owner closure.
The candidate was rejected; no function definition, marker, compiler option or
progress credit changed. Further variations require new evidence.

### NPC freeze voice-selection escalation

The archived best `NPC::freeze()` candidate already has the native 224-byte
extent at Thumb `0x002fe999`; its second voice-selection branch differs in
polarity and the placement of sound IDs 76 and 73. One bounded escalation
replaced only that branch's assignment-plus-if form with a conditional
expression, retaining the first branch and the other operations.

The current production frontend emits exactly the same complete linked target
as the archived best candidate. Native differences remain at offsets `0x83`,
`0x84` and `0xb8`. The target comparison prints:

```text
MISMATCH  _ZN3NPC6freezeEv  0x002fe999
  expected : d1 f0 23 eb 58 00 2b 19 d0 4c 23 98 46 14 4b 8c
  actual   : d1 f0 23 eb 58 00 2b 19 d1 49 23 98 46 14 4b 8c
  differs at 0x83
```

The owner retains all 70 existing function checks, 13 section checks and
1 region checks. This is an owner/dependency proof, not a new full-profile
gate. The private explicit frozen-bit declaration and candidate were not
integrated. No matching credit was added; further expression variants require
new evidence.

### Failure overlay alpha capture

`GSFailure::draw2d` at Thumb `0x002e1e15` narrows its positive alpha value to a
byte before the second failure-cause call. One bounded escalation of archived
form four explicitly captured that byte before constructing the overlay color.
The unchanged archived form was also compiled as a current-context control.
Both emit the identical complete 284-byte unlinked target, versus native 308:
SHA256 `b640f66c9562e779567cbc1a7f2ba0b7b842e4a97f6d0d1254649ae05e89c45b`.
Both define only the intended new function. Explicit source narrowing does not
restore the native lifetime/register choice in this experiment.

The first attempt did not compile: the current device type was incomplete and
the failure getter was declared nonstatic. The private contexts then included
`IrrlichtDevice.h` and declared the failure getter static, following the already
recorded native call evidence. These changes enabled the diagnostics; they
were not integrated or given a shared-header preservation proof. The successful
compiler/assembler runs deliberately stop at the extent guard before linking;
no owner or full-profile native closure is claimed. No function or marker was
changed in production. The old registry's `98/308` described same-offset byte
equality for a different 308-byte form, not a 98-byte reconstruction.
