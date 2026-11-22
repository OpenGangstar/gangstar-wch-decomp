# Quaternion header preservation investigation

The pending `GS3DStuff::load(int, int&)` reconstruction at Thumb address
`0x002dfb15` remains unmatched. Its portable factory-expression candidate has
the correct 2,576-byte extent, but four bytes differ. No source, assembly marker,
matching profile, or progress credit is changed by this investigation.

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
trial will test a loader-local inline definition with the declaration-only
header; its result and broad preservation must be verified before integration.

Private reproducibility packets are `worker-cash-header-isolation` and
`worker-gs3d-load-header-only-preservation-complete-inputs` under `_scratch`.
They retain full commands, frozen input hashes, raw comparison logs, and
relocation inventories. Retail data and toolchains are not committed.
