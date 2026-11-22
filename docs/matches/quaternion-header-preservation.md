# Quaternion header preservation investigation

This records prerequisite failures during reconstruction of
`GS3DStuff::load(int, int&)` at Thumb address `0x002dfb15`. The factory-expression
candidate initially had the correct 2,576-byte extent with four differing bytes.
Those failed proposals received no credit. The final genuine array-type
correction matches exactly; see [the accepted loader](gs3d-loading.md).

## Existing-match regression isolated

A private header-only proposal adds an empty `quaternion::uninitialized_t`
constructor adapter so the loader can create a real quaternion object before
calling the existing `set` method. The original float constructor is unchanged.
Despite that, the added declaration changes an already matched function:
`Cash::drawCash(int, int const*, int&, int) const`, Thumb `0x00327a71`, 332 bytes.

Two controls used the original `ai-startup-cash` source, linker, bindings,
selectors, flags, and NDK 1.6 compiler:

1. Only the proposed Quaternion header: 16 owner functions match; drawCash and
   its separately checked complete section fail.
2. The other six proposed headers, with canonical Quaternion.h: all 17 owner
   functions, six complete sections including drawCash, and one GOT region match.

The first control reproduces the combined proposal's entire object and linked
ELF hashes. The only allocated object payload difference between controls is
five bytes in drawCash, at offsets `0x3c`, `0x3d`, `0x3e`, `0x3f`, and `0x43`.
All 80 semantic relocation tuples are identical. Two instructions exchange
order and a subsequent zero store selects the other zero-valued register.
This isolates a declaration-sensitive code-generation regression; it does not
identify the compiler pass responsible.

The authoritative checker printed:

```text
MISMATCH  _ZNK4Cash8drawCashEiPKiRii  0x00327a71
  expected : 00 dc 80 e0 00 22 04 ab 92 46 00 24 99 46 03 92
  actual   : 00 dc 80 e0 00 22 04 ab 00 24 92 46 99 46 03 94
  differs at 0x3c
```

The second control printed:

```text
OK  _ZNK4Cash8drawCashEiPKiRii  0x00327a71  332 bytes
OK SECTION .cash_draw_cash  0x00327a70  332 bytes
```

Both controls retain all original owner selectors. The separate draw-thunk
profile was not run in these controls and is not counted as passed. The
canonical Cash implementation and Quaternion header remain unchanged.

A third control retains only the nested tag type and omits the constructor.
All 17 owner functions, six sections, and one region pass; its entire compiler
assembly, object, and linked ELF equal the passing second control. Thus the
nested type alone is insufficient. The constructor declaration/body or its
interaction is required; the internal compiler cause remains unproven.

A fourth control retains the nested tag and constructor declaration, but omits
its inline empty definition from the header. It also passes all 17 owner
functions, six sections, and one region; the whole assembly, object, and ELF
remain identical to the passing controls. In this tested context the inline
definition is required for the regression. Moving its definition into the
loader translation unit is a new candidate hypothesis, not verified integration.

## Complete-input gate and next constraint

The first combined header-only gate attempted 73 of 191 profiles; 71 passed.
It found the genuine Cash mismatch, skipped its dependent thunk, then stopped
on a missing nonmatching billboard verification source. The missing source
is a separate setup error and does not explain the Cash mismatch.

A fresh snapshot includes all 207 canonical nonmatching files and validates
all profile sources, linkers, and dependency paths. The complete-input run finished with exit 1: 190 profiles attempted, 189
passed, and Cash the sole failing profile. The dependent `cash-draw-thunk`
profile was skipped. Actual checks printed 5,428 function OK lines, 5,351 section
OK lines, 180 region OK lines, and one function mismatch. All 1,097 frozen
inputs remained stable; no missing source or fatal build error remained. These
counts do not include the skipped profile as passed. Pending
loader source is excluded from the header-only gate, so even a successful gate
would not prove its four remaining bytes or complete emitted-body integration.

Further reconstruction must preserve existing matches and legal C++ object
lifetimes without global constructor attributes, raw-storage lifetime tricks,
output editing, or changes to the already matched Cash function. A loader-local
factory using canonical default construction was measured at 2,588 bytes,
12 bytes over the native extent. It receives no matching credit. A separate
trial restored the four-byte best with a loader-local inline definition and
declaration-only header. The subsequent array-type correction and full fresh
preservation gate passed before final acceptance.

Private reproducibility packets are `worker-cash-header-isolation` and
`worker-gs3d-load-header-only-preservation-complete-inputs` under `_scratch`.
They retain full commands, frozen input hashes, raw comparison logs, and
relocation inventories. Retail data and toolchains are not committed.

## Declaration-only broad preservation verified

A separate complete-input header-only snapshot replaces only the failing
Quaternion header with the declaration-only control. It retains the other
six proposed headers, local OctTree size correction, all canonical nonmatching
sources, original selectors, dependency ordering, and per-profile toolchains.
The coordinator ran it once; all 191 profiles passed, with 5,447 function,
5,356 section, and 181 region OK lines (10,984 comparisons). All 1,097 frozen
inputs remained unchanged. There were no mismatches, skipped dependencies,
missing sections, or build errors.

The loader candidate separately defines the empty tag constructor inline in
GS3DStuff.cpp before its factory. That real compile/link restores the 2,576-byte
portable best with the same four differences, while all 147 scoped existing
function checks and 132 support checks pass. No factory or constructor helper
is emitted. This is still an unmatched candidate. The global header-only run
excludes that body, so actual-body downstream dependency closure remains a
separate requirement. No canonical source or matching credit has changed.

The complete broad-preservation evidence is retained privately under
`_scratch/worker-gs3d-header-declaration-complete-inputs`; the body evidence is
under `_scratch/worker-gs3d-load-local-tag-definition-control`.

The accepted loader subsequently passed all 191 profiles with its actual body,
including all seven dependent images: 11,112 exact comparisons and 880 additional
cross-image GS function checks. The shared header uses only the declaration;
the definition remains local. Only the loader receives new matching credit.
