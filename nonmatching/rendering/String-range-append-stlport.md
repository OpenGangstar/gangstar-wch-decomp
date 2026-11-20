# STLport range append: native-backed inline reconstruction, unmatched

The unapplied patch reconstructs `_ZNSs9_M_appendEPKcS0_`, the 372-byte
`std::string::_M_append(const char*,const char*)` at Thumb `0x002dcd29`.
It remains pending, with its assembly marker intact and zero matching credit.
Canonical game sources, compiler flags, generated tables and Windows code are
unchanged. Apply this packet independently of other unapplied candidates.

## Current result

The coordinator independently applied the final public patch to a fresh copy
of current source/configuration/tools and rebuilt the genuine `gs3d-stuff`
profile, including its stream/data-stream dependencies. Ordinary build exit is
**1**: the complete function and strict 372-byte section differ at 60 byte
positions, beginning at `0x70`. The first 112 bytes are exact. Linked SHA-256 is
`5398c03b4c66f23f82296738a4bf75ec599268a5f800e299ec157fd7d560e943`.
All 147 existing graph function checks, 124 section checks and three region
checks pass with the target present. These include the existing public append.
No surplus helper definition or diagnostic-address placement remains.

```text
MISMATCH  _ZNSs9_M_appendEPKcS0_  0x002dcd29
  expected : 47 46 01 97 41 45 00 d2 6d e0 03 ab 1b 68 01 31
  actual   : 47 46 01 97 41 45 00 d2 73 e0 03 ab 1b 68 01 31
  differs at 0x70
```

The exact actual excerpt above is checked against the final replay log before
publication; the adjacent JSON records all actual differing offsets. Equal
function size and a longer exact prefix do not establish a match.

## Bounded reconstruction changes

The prior three original/traits forms emitted identical 372-byte callers with
unsupported `_M_deallocate_block` and `_M_copy` calls. Their old diagnostic image
placed helpers at artificial addresses, differed at 275 bytes and failed existing
GOT comparisons. That was not a valid owner closure. Its historical results and
source provenance remain recorded in the JSON; those placements are absent from
the current patch.

A separately authorized escalation compiled exactly three source forms:

1. Reconstruct the observed dynamic-buffer cleanup directly in the caller:
   check dynamic storage and nonnull buffer, then call genuine operator delete.
   This removes `_M_deallocate_block` but emits 376 bytes; strict native extent
   prevents linking. No linked preservation result is claimed for this form.
2. Also reconstruct the original static-buffer `_M_copy`/traits chain as guarded
   memcpy, preserving the dynamic uninitialized byte-copy loop. This removes
   every surplus helper, emits 372 bytes and differs at 86 positions. All existing
   graph checks pass under real native placements.
3. Reverse only the static/dynamic source if-else arm spelling to match the
   observed native dynamic fallthrough and out-of-line static copy. This reduces
   differing bytes to 60 without changing the algorithm, interfaces or flags.
   No fourth source form, likelihood hint or optimizer-option sweep was tried.

These direct operations reconstruct the observed original algorithm; they are
not claimed to reproduce its exact original source spelling. Native cleanup
calls operator delete, and the static nonzero copy calls memcpy. No emitted
helper is replaced with a retail import, discarded or moved to a fake address.

The adapted source retains the original licensed STLport notices. Public source
revision `e64e7c849b0b659d3e198e4efaed563601e554be` is a reference, not an identified
retail revision. The native 16-byte buffer union, finish at 16 and allocator
proxy at 20 remain unchanged. Private allocator declarations add only the
observed two-argument allocation overload and deallocation interface.

## Reproduction and remaining requirements

```sh
git apply --unidiff-zero nonmatching/rendering/String-range-append-stlport.patch
python tools/build.py gs3d-stuff
```

Configure the documented retail library and matching toolchain first. Expected
exit is 1, with both target and full-section mismatches. Native start and strict
372-byte extent assertions remain enforced. The adjacent compile-only probe
still exits 3 intentionally after assembly; it supplies no linked proof.

The initial coordinator replay failed to apply a context patch to the Windows
checkout before any compilation. The final zero-context patch was independently
applied and rebuilt successfully; that application format is required above.
No compiler output was edited. All 890 worker source/configuration/tool inputs
were frozen during each trial.

The full affected-header gate has **not** run: the target is unmatched and the
patch remains unapplied. The worker inventories 86 direct header users and 100
planned profiles including dependencies. Header compatibility beyond the tested
owner graph is unproven. Before adoption, obtain exact complete native function
and section bytes, run all affected header checks and the full native gate, and
preserve every existing match. No compilation unit becomes fully linked here.
Further source trials require distinct evidence or another explicit bounded
escalation; this packet does not reset the first-pass budget.
