# SlideControl constructor: genuine height capture and common bottom tail

Both `SlideControl` constructor aliases at Thumb `0x0032b1f5` remain unmatched.
These patches apply to exact private fixtures, not directly to canonical source.
They introduce no header, ABI, compiler-option or other-function changes. No
assembly marker is removed and no matching credit is earned.

The native function and input section are 492 bytes: 480 instructions and a
12-byte literal pool. A new native-only halfword-copy scan exposed an important
source observation phase that the earlier six constructor forms all missed.

## Native observation and first control

After computing the right coordinate, native reads the sprite module's height
before writing the first three destination coordinates. Horizontal code reads a
signed halfword; vertical code loads a halfword and retains it across two stores
before sign extension. The retained 500-byte candidate instead reads height
after those three stores. These windows were independently checked against the
retail bytes, not inferred solely from a decompiler.

`height-snapshot.patch` captures the existing horizontal integer-height expression
and the genuine vertical short before those writes. Both values are consumed by
the unchanged final conversion. This deliberately corrects the observation phase;
it does not claim equivalence with the old program under every possible alias.
No dummy object, artificial extra use or callback is introduced.

One original frontend/assembler pair exited 0. Actual C1/C2 function and input
grew to 504 bytes, failing native 492. Both early height observations appeared,
including vertical unsigned halfword load plus register sign extension. Emitted
stores nevertheless reordered, and the final conversion/addition remained
duplicated. All 35 off-target definitions, 42 off-target allocated payloads, 34
imports and 167 off-target references remained exact; all 1892 pins stayed
stable. Complete raw metadata equality failed for target growth and physical
offsets, with every difference retained. No linker ran for this control.

## Native common tail and second control

Native's vertical branch at `0x0032b3d2` joins the horizontal path at
`0x0032b33c`. Both paths supply an integer height and float top to one final
integer-to-float conversion, float addition and bottom-coordinate store. The
retained candidates had two static copies of that pair: 23 calls versus native
21. The original six source forms all duplicate it.

`common-bottom.patch` applies only to the captured 504-byte fixture. It preserves
both early height reads, assigns real selected height/top values after the first
three stores, and performs the final computation once after the conditional.
The vertical short remains captured across the writes before promotion. Every
runtime path still performs its original final conversion and addition.

One original frontend/assembler pair exited 0. Literal audit fields:

```text
C1_size: 492
C2_size: 492
input_size: 492
strict492_function: true
strict492_input: true
target_raw_sha256: db9ab19785fa520968e2dc7bfee2534ad3df655bfa3bfc6a19641e424149770f
off_function_count: 35
off_function_failures: []
imports_exact: true
imports_count: 34
off_refs_exact: true
off_ref_count: 167
LD_runs: 0
```

Actual C1/C2 remain genuine same-section/same-value aliases. The common source
join is emitted, all 21 static call names/order agree with native, and the
left/top/right store order and early height-read phases appear. All off-target
payloads/imports/references remain exact; all 2773 pins are stable.

Equal extent is insufficient: actual code has 478 instruction bytes, two genuine
alignment bytes and the 12-byte pool, versus native's 480 instruction bytes and
pool. Both alignment bytes remain in the comparison. Registers and common fadd
operand order differ. The raw unlinked target has 333 differing positional
bytes, including unresolved call/pool operands; this is not a linked mismatch
count or matching percentage.

Raw symbol/section/reference equality fails for owned sizes, pool placement,
25-to-23 target relocations and physical offsets. All 35 off-target definitions,
42 allocated payloads, 34 imports and 167 references still match. No names are
mapped, code hidden behind native bindings, output rewritten or padding removed.
Both trials stopped before LD under their specific approvals. Native-placement
link verification was authorized separately, as recorded below.

## Separately approved native-placement comparison

After review, exactly one original LD invocation used the saved 492-byte object,
authenticated existing GOT/Thumb-binding objects and the unchanged strict linker
script. No compiler, assembler, script repair, source refinement or linker retry
ran. LD exited 0. Both real executable constructor symbols are Thumb
`0x0032b1f5`, size 492, in the complete section at `0x0032b1f4`, size 492.
Their section ends exactly at the emitted update neighbor's start.

Literal checker excerpts for the two aliases:

```text
MISMATCH  _ZN12SlideControlC1EP7ASpriteiiNS_16SlideControlModeE  0x0032b1f5
  differs at 0x10
MISMATCH  _ZN12SlideControlC2EP7ASpriteiiNS_16SlideControlModeE  0x0032b1f5
  differs at 0x10
```

The complete 492-byte comparison has 277 differing instruction bytes and zero
literal-pool differences. All 18 old selected functions and 18 old selected
regions pass. The opaque unmatched processTouch parent still fails and receives
no credit. No full-project linked closure is claimed after these target failures.

Complete unmasked GOT comparison retains 642 prefix differences; the historical
selected GOT-body check passes. The complete GOT is not called native-exact.
The linked image has no orphan allocated output sections, and real emitted input
definitions are accounted for without absolute-symbol overrides.

An original verification predicate reports `emitted_update_native:false` because
it incorrectly required a 54-byte input section. The real update function is 54
bytes at Thumb `0x0032b3e1`; its input/output section is 56 bytes, including the
actual two-byte alignment instruction. All 56 bytes compare exactly with native.
The failed predicate and original verifier output remain unchanged; a separate
read-only accounting record explains the size distinction. No LD reran and no
padding was trimmed.

The authoritative result is an unmatched native-placed candidate, not a completed
constructor. Original/prepared pins remained stable. Exact checker stdout/stderr,
image identities, complete code/pool/GOT differences and neighbor accounting are
in `common-tail/link-preparation/` under the private review directory below.

## Reproduction identities and limits

| Context | Source SHA-256 | Object SHA-256 |
| --- | --- | --- |
| Retained 500-byte complete context | `b99a6c04f0d1f1386ab6cc03055c54c7b62dbc80b9caae8ece55d597f7f76a86` | `3ff5a2387cadbbdb6ec4ce5faf9344655e17b20f3704e6e64467b42dd0dc2e88` |
| Height capture, 504 bytes | `c847913cc43945050458a8d311130f2d1c72fb143129f26061b120c7681cfa3e` | `44db99a774efd0a2e2a6531a0f45dddde22e6b3108b12cbc75c55291fdbbda45` |
| Shared bottom, 492 bytes | `fcb695d5e940fcafb7e3ba4eda52cb280d3805f9bd8a866c0c77d5c5f86aaf89` | `a7a773531d038c8a26d2075cbf4942e510a4645e194437d8ab59b32bbb2bf525` |

Each trial used the original ordered 15 compiler/four assembler options, relative
source/output paths, frontend and assembler. Actual include and entire selected
tool/runtime files were pinned before/after. There was no compiler retry,
diagnostic option, profile adoption or source grid. An initial proposal-generation
assertion failed on CRLF spelling and was corrected before any compilation.

Native may have used aggregate assignment or another expression structure; these
readable local captures do not establish original syntax. Keep the original,
captured and joined fixtures distinct. Details remain in
`_scratch/worker-slide-height-snapshot-review/` and its `common-tail/control/`
subdirectory. `patches.json` records original and published source-patch hashes.
