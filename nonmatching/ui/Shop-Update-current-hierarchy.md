# Shop update: current hierarchy replay and bounded scheduling checks

Target: `Shop::Update(int)`, Thumb `0x00305f5d`, native 384 bytes. Base: main
PR #743, `68f0bc30`. All patches remain unapplied and unmatched; no credit.

A read-only archive ranking found the older native-sized candidate differs in
only one byte. This is a candidate filter, not a proof or percentage claim.
The saved body is replayed unchanged in the complete current Shop translation
unit, using the accepted coherent PlayerTest/Character hierarchy and existing
compatibility aliases. No existing body, header, field or compiler flag changes.
Only Shop::Update is newly emitted. The target has its native address and a
384-byte extent assertion in the normal owning linker script.

Initial normal linking exposed missing __aeabi_i2f and __aeabi_f2iz bindings.
Add their actual ARM PLTs at 0x001c41e4 and 0x001c44cc. The first linked attempt
then had an ARM/Thumb call-mode mismatch at 0x0f. Comparing newly undefined
symbols with the retail ELF proves Checkpoint::Update(int) and
PlayerTest::setClosestShop(Shop*) are genuine external Thumb functions; add
those imports. Neither replaces a compiled definition. Normal guards stay
active. These are metadata repairs, not source-form iterations.

The valid current replay reproduces the archived executable exactly: 384 bytes,
one differing byte at 0xea, SHA256
`4f81803cbf1fe5bb29da4503281b60870ef10a8516ac81eb40ebd84b69830f6b`.
The native instruction loads the virtual table through R0; the candidate uses
R1, which already holds the same returned vehicle pointer. Semantic equivalence
does not count as a byte match.

The coordinator then permits two separately bounded scheduling models: one
`__builtin_expect(car != 0, 1)` condition in place of `if (car)`, and one
ordinary inline position-value helper in place of the direct virtual call.
The helper is not forced inline and emits no separate definition. Both produce
EXACTLY the same complete executable bytes as the unhinted current replay and
the old archive. No opposite hint or additional helper variants are attempted.
The GNU hint remains uncredited because it fails the complete-function check.

All three valid runs preserve all 20 existing functions, six sections and the
GOT region. The new function and its full section fail, exit 1:

```text
MISMATCH  _ZN4Shop6UpdateEi  0x00305f5d
MISMATCH SECTION .shop_update
  expected : 98 47 01 1c 00 28 95 d0 03 68 09 a8 1b 6b 98 47
  actual   : 98 47 01 1c 00 28 95 d0 0b 68 09 a8 1b 6b 98 47
  differs at 0xea
```

Set WCH_BASE_LIB and apply Shop-Update-current-hierarchy.patch in an isolated
checkout, then run `python tools/build.py ai-startup-shop`. The optional
Shop-Update-position-helper.patch is a DELTA requiring the baseline patch first.
To reproduce the rejected hint, replace only `if (car)` with the expression
above. No output edits, register pins, barriers or relocation tricks are used.
Production source/configuration, the assembly marker and progress stay intact.
No new whole-project proof is claimed for these rejected artifacts. Ownership
is released after coordinator review; another syntax or probability grid needs
new evidence or an explicitly bounded escalation with a distinct hypothesis.


## Controlled compiler-frontends comparison

One final bounded diagnostic compiles the unchanged unhinted full owning
translation unit with the installed NDK 1.6 r1, r3 and r4b GCC 4.2.1 frontends.
Their executable hashes are checked against the inventories in
[COMPILER-NOTES.md](../../docs/COMPILER-NOTES.md). All source, configuration,
tool and nonmatching input hashes are identical across the three contexts;
only the selected C++ frontend executable changes. The original 1.6 assembler,
linker and options remain fixed. This is not a production SDK change.

All three emit the same complete 384-byte target and identical semantic
relocations, raw SHA256
`fbb5aa87dffc1f3f53235144f48a6d618507c6af7659c175bb78d01fb18f8eba`.
Only Shop::Update is newly defined. Each diagnostic deliberately exits 3 after
assembly; the linker and GOT-harness frontend are not invoked. No new linked
old-closure or whole-project proof is claimed. Different installed GCC 4.2.1
frontends therefore do not resolve this function's copy-choice difference.


## Unchanged-source RTL audit and scoped declaration

A single diagnostic compile adds only GCC tree/RTL dump switches to the same
source, ordinary options and original compiler. Every allocated object payload
and every semantic relocation entry remains identical to the ordinary object;
all 986 preexisting input hashes are preserved. The 117 generated dump files
are outputs beneath the source directory, not changed compiler inputs. An
initial inventory assertion included those new outputs; comparison against the
original input key set confirms no input mutation.

Target instruction 54 already addresses the vtable through car pseudo 116 in
104r.expand. It retains that pseudo until 138r.greg assigns it R1; every later
pass retains R1. This rules out a later R0-to-R1 rewrite as an observed cause.
The audit does not establish the original source spelling or why retail chose
R0, and does not justify a blind optimization-flag search. No new linked proof
is claimed for the dump object; object equality establishes noninterference.

One separately bounded lifetime model moves the existing vehicle declaration
into `if (Vehicle* car = ...getVehicle())`. No extra call or operation is added.
It reproduces the EXACT same complete 384-byte executable and single 0xea
mismatch, retaining the 20/6/1 owning comparisons and failing target/section,
exit 1. Shop-Update-scoped-if.patch is an optional DELTA requiring the baseline
patch first. Ownership is released; further local syntax/flag variations are
stopped pending a new causal lead.
