# Menus::Map::Notify: 220 bytes matched

`_ZN5Menus3Map6NotifyEPK10MenuWidgeti`, Thumb `0x002e78ad`, now has an exact
C++ definition in `src/game/ui/MenuState.cpp`. It reuses the existing typed
menu/widget APIs and native strings. No existing production function, shared
header, compiler flag or data layout changes.

The function handles menu events, selects the service/volume/achievement menus,
and configures the confirmation dialog. Clause order is deliberately
`1, 2, 0, 3`. Every case retains its own original operations; case 0 returns
directly and has no fallthrough.

## Why clause order matters

The preceding complete-interface candidate was already 220 bytes, but differed
in 21 bytes. Compiler dumps showed three separate push tails through
`141r.flow2`. GCC 4.2.1's `143r.csa` cross-jumping selected the first eligible
pair by CFG predecessor traversal: cases 0 and 1 shared, while native shares
cases 1 and 2.

All six historical forms had clause order `0, 1, 2, 3`. One explicitly bounded
trial moved the entire case-0 clause after case 2, leaving every statement,
condition, declaration, literal, return and break unchanged. The same compiler
pairing now joins cases 1 and 2 and retains case 0's complete tail. The full
native byte comparison passes. This proves the reconstruction, not the exact
lexical order of unavailable original source.

No GNU branch hint, inline assembly, register pin, barrier, optimization-flag
change, padding object or compiler-output modification is involved.

## Verification

The isolated candidate passed all 637 previous function checks and 417 previous
section, region and GOT checks, plus the new target and section. The coordinator
then integrated only the function, normal verification selectors and strict
native linker placement, and ran:

```text
python tools/build.py --all
```

Exit status was 0: **190 profiles, 10,677 comparisons** comprising 5,299
function, 5,197 section and 181 region checks. No failures or skips occurred.
The target output was:

```text
OK  _ZN5Menus3Map6NotifyEPK10MenuWidgeti  0x002e78ad  220 bytes
OK SECTION .map_notify  0x002e78ac  220 bytes
```

Independent extraction from the integrated executable section confirms that
the actual symbol is a 220-byte executable definition, not an absolute binding,
and all 220 bytes equal retail. Native and compiled SHA-256:

```text
d2150e6fd9a80654ed7d2714f790db7ffc2a3d80c5d4b0721600bd9d3573530e
```

After normalizing only the new linker's text formatting, the complete affected
profile/dependency closure was rerun and passed. The original assembly was
removed only after the full integrated comparison succeeded. Catalogue,
symbol map, progress and ByteMatch report were regenerated normally.

Independent executable audits find no missing proofs for either matched entries
or fully completed source groups. All 89 unit tests, repository checks, progress
checks and pinned objdiff 3.8.1 report-schema validation pass.

## Progress

This adds one function and 220 game-code bytes: **4,254/4,661 entries,
341,530/575,264 bytes, 59.37% Matched and Fuzzy Matched**. `MenuState.cpp` still
has pending functions, so Fully Linked remains **110,400 bytes, 19.19%,
123/208 report units**. The Windows port is unaffected.
