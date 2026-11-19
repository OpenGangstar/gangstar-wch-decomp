# CSoundDecoderMSADPCM::Init: matched-constructor reuse

This function is **not matched** and receives no credit. Native Thumb
`0x003511b9` is 134 bytes; the retained complete candidate is 132 bytes.
Its assembly marker remains. Baseline: main PR #745,
`d151cad3d53bfd1a6628b362a9d298a158a41bdb`.

## Reconstruction and first-pass limit

The existing byte-matched parameterized constructor already supplies the header
parsing, state field interfaces and samples-per-block calculation. Init reuses
that source with the native reset fields and native whole-block PCM-size formula.
It stores the supplied stream/header pointers, resets decoder state, skips
extended format bytes, reads fact/data headers, derives the mono/stereo block
sample count, computes complete decoded-block bytes and copies the fact count.
No existing decompiled body or shared header changes.

The six ordinary source forms use current production flags and the same current
translation unit. The JSON ledger includes exact unresolved signatures,
relocations and source deltas from the retained second candidate:

| Form | Change | Function bytes |
| --- | --- | ---: |
| 1 | Constructor reuse; multiply PCM sample product by four | 138 |
| 2 | Explicit product-then-shift PCM calculation | 132 |
| 3 | Flags assignment before riff assignment | 132 |
| 4 | Existing constructor member initialization order | 130 |
| 5 | Staged unsigned PCM calculation | 132 |
| 6 | Initial seek uses supplied arguments directly | 132 |

Forms **2, 5 and 6 have identical complete raw bytes and semantic relocations**.
The six-form budget and three-identical-output stop condition are both met.
No seventh source form, prototype guess, hint, compiler-flag variant or artificial
padding follows. Raw object hashes identify inputs; they do not prove a match.

## Reproduction

Apply only in an isolated checkout of the baseline:

```powershell
git apply --check nonmatching/audio/CSoundDecoderMSADPCM-Init.patch
git apply nonmatching/audio/CSoundDecoderMSADPCM-Init.patch
python nonmatching/audio/CSoundDecoderMSADPCM-Init-probe.py --baselib C:/path/to/libsanangeles.so
```

The compile-only probe always stops after assembly with actual exit **3**,
without linking or claiming native acceptance. Retained object: 132 bytes,
SHA-256 `8b62c5b8fe9aceb35bb80ad1bada1b68c6fb46166ce71d116b2de316ce4b5568`.

To reproduce the normal native-address diagnostic:

```powershell
git apply nonmatching/audio/CSoundDecoderMSADPCM-Init-link.patch
python tools/build.py --baselib C:/path/to/libsanangeles.so msadpcm-decoder-pool
```

Actual normal build exit: **1**. Exact target/section failures:

```text
MISMATCH  _ZN20CSoundDecoderMSADPCM4InitEP7__sFILEP10RiffHeaderP12FormatHeader  0x003511b9
  expected : 10 b5 04 1c e1 60 a3 62 08 1c 19 1c
  actual   : 10 b5 04 1c 62 62 01 22 e1 60 a2 65
  differs at 0x4
MISMATCH SECTION .msadpcm_init_trial
  expected : 10 b5 04 1c e1 60 a3 62 08 1c 19 1c
  actual   : 10 b5 04 1c 62 62 01 22 e1 60 a2 65
  differs at 0x4
```

All **22 existing function checks and 19 existing section/region checks pass**,
including the matched constructor, pool caller, vtable and native GOT.
The real compiled Init definition occupies its correct native address; its
previous external Thumb import is removed. No absolute binding masks it.
The maximum-span guard prevents overlap but does not pad the 132-byte function
to 134 bytes or make either failed comparison pass. No earlier assertion is
removed or weakened. Both candidate checks remain mandatory and fail.

The linked target SHA-256 is
`639b7f87ed87626e32add46d68303706ccbe553708db89d7c865eb46b00360dc`.
The first ordinary multiply-by-four expression changes multiplication grouping
and costs a second saved register plus alignment. Explicit shifting restores
the native product/shift sequence and sole saved R4, but entry pointer/store
scheduling still differs and lacks two native instruction bytes. Those bytes
cannot be supplied with a dummy statement, barrier or output edit.

All first-pass source/header hashes are preserved. Five snapshots still agree
with all 884 frozen inputs. Candidate 2 later changes only the two documented
diagnostic configuration files; its new 884-input link snapshot remains stable
through native comparison. The initial ledger audit caught Windows path spelling
in its own two-file exception check; correcting path normalization required no
new compile or input change. The published compile-only probe reproduces exit3 and the retained raw hash.
Both patch applications and all six JSON source deltas reconstruct the measured
source/configuration text in an isolated checkout. No full 190-profile gate is
claimed because this
function is unaccepted and production source/configuration remain untouched.
