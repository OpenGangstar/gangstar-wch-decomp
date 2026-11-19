# FPSCamera::scroll: unmatched candidate

`libsanangeles.so`, Thumb `0x00333e41`, 280 bytes, original source
`FPSCamera.cpp`. This candidate is **not matched**. It leaves the assembly
marker, catalogue status and progress unchanged. Apply the four-path patch
only in a disposable matching checkout; do not integrate its declaration alone.

The patch applies to the current source context at `8676409` / `e423bc9`.
It adds the ordinary declaration and body, then extends the existing owning
manifest and linker script without removing any existing checks. The body uses
the genuine `PlayerTest` / `Character` hierarchy, two separate `GetPlayer()`
acquisitions and the existing quaternion getter/setter interfaces. A normal
`const float verticalDelta` preserves the completed vertical product before
its unary negation. There are no hints, barriers, forced registers or output edits.

## Reproduction

Use a disposable checkout with the repository's matching toolchain setup and
an independently supplied retail library. From its root:

```sh
git apply --check nonmatching/core/FPSCamera-scroll.patch
git apply nonmatching/core/FPSCamera-scroll.patch
python tools/build.py ai-startup-fpscamera --baselib /path/to/libsanangeles.so
```

The configured NDK 1.6 GCC 4.2.1 `cc1plus.exe` has SHA-256
`914b3fe8024cdfe8358b6fc6f78ce672136db1f03ccd609a8cb8a432de7bb734`.
The owning profile retains these compiler flags:

```text
-O2 -fpic -fno-toplevel-reorder -fno-strict-aliasing -fno-rtti
-fno-exceptions -mthumb -mthumb-interwork -march=armv5te -mtune=xscale
-mfloat-abi=softfp -ffunction-sections -fdata-sections -finline-limit=70
```

Assembler flags remain `-march=armv5te -mfloat-abi=softfp -mfpu=vfp
-meabi=4`. The existing Camera dependency is rebuilt and checked. Genuine
normal metadata supplies ARM PLT `__aeabi_fdiv` at `0x001c4520` and Thumb
`CameraManager::getFOV` / `PlayerTest::GetPlayer`; none overrides a compiled
definition in this image. The target section is placed at `0x00333e40` and
asserted to be exactly 280 bytes.

Expected result: a failed target comparison, not a successful match.
The comparison tool prints:

```text
MISMATCH  _ZN9FPSCamera6scrollERKSt4listIP7Point2DIsESaIS3_EE  0x00333e41
  expected : 81 46 04 21 5d 5e f8 44 05 95 06 25 5a 5f 05 99
  actual   : 81 46 04 21 5d 5e f8 44 03 95 06 25 5a 5f 04 92
  differs at 0x1e
MISMATCH SECTION .fps_scroll
  expected : 81 46 04 21 5d 5e f8 44 05 95 06 25 5a 5f 05 99
  actual   : 81 46 04 21 5d 5e f8 44 03 95 06 25 5a 5f 04 92
  differs at 0x1e
```

Native and actual sizes are both 280 bytes. Exactly 266 of 280 bytes agree;
14 differ at `0x1e, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2c,
0x2e, 0x42, 0x50, 0xac, 0xb4, 0xe2`. This count describes a near miss
and earns no matching credit. All 28 existing functions, ten existing sections
and two GOT-region comparisons in the owner/dependency closure pass. A broader
post-body preservation gate was not run because the target fails.

The frame is the native 60 bytes. The entire 32-byte literal pool and all
20 call instructions have native offsets, resolved targets and BL/BLX modes.
Quaternion argument/result temporaries retain SP+40/SP+24. Final negation
and x-before-y camera stores agree. Remaining differences are spill placement
and early load/register scheduling: native x/FOV/setter use SP+20/SP+8/SP+12;
actual uses SP+12/SP+20/SP+8. No missing operation or source repair is inferred.

Linked target SHA-256:
`0c6a9c507fab577977755022a9944d4861ecd3f80fa167db2ceba207a2ccbc87`.

## Diagnostic history and limits

The declaration-only prerequisite separately passed all 190 profiles and
10,923 comparisons: 5,419 functions, 5,323 sections and 181 regions. That
result predates the target body and is not a post-body acceptance claim.
All 102 repository tests and the repository/progress checks passed there.

The initial actual-Character expression emitted only 272 bytes. A single
unchanged-source diagnostic compile, adding only tree/RTL dump switches,
produced a wholly identical object, including 31 allocated sections and
132 semantic relocations. Its earliest `.003t.original` dump already divides
by `-480`, instead of retaining final-product negation. This removes four
instruction bytes and the four-byte sign-mask literal. Older saved attempts
already exhibit the same folding.

The primary GCC 4.2.1 sources, pinned to commit
`0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc`, explain the frontend rule:
[C++ unary folding](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/cp/typeck.c#L4463)
reaches the [negation fold](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/fold-const.c#L1248),
which can move the sign recursively into the constant denominator. The ordinary
float-intermediate trial restores native arithmetic representation, but the
remaining 14-byte mismatch is unresolved. This establishes neither the original
source spelling nor identical retail compiler-fork/options. No further forms,
flags or speculative lifetime changes are justified by this package.

Only this text and the additive source/configuration patch are intended for
publication. Retail bytes, compiled objects, diagnostic binaries, downloaded
compiler sources and proprietary toolchains remain private.
