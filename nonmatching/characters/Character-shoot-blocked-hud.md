# Character::shoot: blocked-shot HUD guard, still unmatched

Target `_ZN9Character5shootEfb`, Thumb `0x002f55d1`, native **2,608 bytes**.
The [source fragment](Character-shoot-blocked-hud.cpp) preserves one independently
proved correction. It is not production source or a standalone translation unit.
Its assembly marker remains; no matched or Fully Linked credit is added.

## Original constraint and isolated correction

Native `0x2f5b10` retains the raycast result. At `0x2f5b8a`, nonzero blocked
branches to `0x2f5bce`, which returns through the common cleanup. That path skips
both damage and HUD work. The unblocked/non-null-hit path alone reaches HUD entry
`0x2f5bd2` and camera calls beginning at `0x2f5c0c`.

The retained body6 placed HUD work outside `if (!blocked && hit)`. A blocked shot
with a player hit therefore exposed extra camera calls and timer writes.
The control moves only that guard's closing brace after the existing HUD block.
It retains the separate escaped-hit/type recheck after damage callbacks, all
formulas, widths, callbacks, returns and the existing RAII cleanup.

Fresh retail-byte-verified CFG reachability reproduces the counterexample.
Paired source verification checks the corrected nesting and proves all
non-brace/whitespace target tokens unchanged. This is focused source/semantic
proof, **not** an ARM byte-match test.

## Compiler result and strict rejection

| Artifact | Function bytes | Entire target input section |
| --- | ---: | ---: |
| Reproduced body6 baseline | 2,626 | 2,628 |
| Single corrected control | **2,622** | **2,624** |
| Required | 2,608 | 2,608 |

Both compiler/assembler pairs exit 0. The control stops with:

```text
REJECT PRELINK: function AND entire target input section must each be 2608 bytes. NO LD.
```

The correction saves four bytes but remains 14 function bytes and 16 section
bytes oversized. No linker, native-placement comparison, linked dependency/owner
gate or canonical full build ran for this candidate. Padding is not removed.

The first remaining non-relocated instruction difference is at function `+0x0c`:
the native literal-load offset is 744, versus 532 in the corrected object.
External relocations remain unresolved; raw object diagnostics are not a linked
comparison result.

## Context, preservation and limits

The actual paired source is historical **body6**, not body4. A single baseline
compile first reproduced the complete saved assembly and ELF object exactly:

- Baseline object SHA256:
  `66f99e2d1214934407ad672f082ff4e7c703d107ba8d971c07697ec6398335e2`.
- Baseline function SHA256:
  `e92f5f06c902b1dcfff422e975a37c100da7d731e0a499f9dc7769fee07a7bb7`.
- Corrected function SHA256:
  `12893a9c43a7d4f45949d697598304d16907d19612ec5cfb1edac4c7b9186df8`.

Flags were selected once from surviving records; exact complete-object
reproduction proves this context, not uniqueness or recovery of the original
historical command. The frontend is NDK 1.6r1 GCC 4.2.1 with:

```text
-quiet -O2 -fpic -fno-toplevel-reorder -fno-strict-aliasing -fno-rtti
-fno-exceptions -mthumb -mthumb-interwork -march=armv5te -mtune=xscale
-mfloat-abi=softfp -ffunction-sections -fdata-sections -finline-limit=70
-fno-short-enums
```

Assembler flags: `-march=armv5te -mfloat-abi=softfp -mfpu=vfp -meabi=4`.

All 324 off-target definitions (110 functions), 693 off-target semantic
relocations, 160 imports and 139 off-target allocated sections are unchanged.
Only the target text and switch-data sections change. No header, flag, import,
layout, prerequisite or unrelated function was edited.

The fragment requires the retained private type/access context, including its
existing friend and HUD-pointer prerequisites; those are **not** installed in
canonical headers. The private replay package is
`_scratch/opencode-character-shoot-hud-guard-control/`: `closure.json` freezes the
396-file source tree, transitive includes, toolchain/runtime and source hashes;
`baseline/commands.json` and `corrected/commands.json` retain exact commands;
`final-proof.json`, `semantic-source-proof.json` and `REPRO.md` retain results.
That package is not a self-contained public build profile.

The published fragment differs from the tested method only in whitespace and
comments, verified separately; it has not been compiled outside that retained
context. The six historical forms stay exhausted. This one new-evidence control
is finished; further work requires a distinct supported cause, not another
cleanup, flag or ordering grid.
