# Reviewed local-record, byte-transport and row-array controls

These are rejected matching candidates, preserved as unapplied patches. None
changes canonical source, a shared declaration, a compiler profile, an assembly
marker or matching credit. Each trial used one original frontend/assembler pair;
all exited zero. No linker ran, and no linked match is claimed.

| Function | Retail address | Native bytes | Actual function/input bytes | Result |
| --- | --- | --- | --- | --- |
| `Path::Load` | `0x00300bc5` | 200 | 200/200 | Entire object and assembly identical to the preferred candidate; four known native byte differences remain |
| `ASprite::GetAnimDuration` | `0x00349d81` | 82 | 92/92 | Two-byte memcpy inlined, but introduced eight scratch-stack bytes and a signed stack reload |
| `SoundManager::getNumberOfPlayingSounds` | `0x00352cad` | 80 | 82/84 | Genuine four-pointer row reference changed outer address association, but introduced channel scaling and nonnative induction |

`patches.json` records both the original private patch hash and the published
LF-only patch hash. These are source patches, not compiler output. No retail
code, object files, disassembly or proprietary tool is included.

## Path local snapshot

The only source change replaced three real integer locals with a fully consumed
local three-integer record initialized from the same scalar reads. It did not
reinterpret external storage as a fabricated record. The source became
`0ad6cb78a7077bad1589bb50dbacc64a5c781145a9754cafa5a419f775e3c63e`.

Literal recorded comparison results:

```text
function:200
physical_input:200
strict200:true
whole_object_sha:f9159c7ef44da921eddce3207775b581595c7f3e449518b2e417b36c4e606666
raw_target_sha:4fa4c9b91c74ccc2db285b062b52ee293819318686e7a1d6fd954d866d651619
whole_object_identical:true
raw_target_identical:true
assembly_identical:true
raw_old_gates_pass:true
no_ld:true
```

All 12 off-target definitions, 17 off-target allocated payloads, 53 imports and
69 off-target references remained raw-exact. All 997 original pins and 866 copied
inputs were stable except the approved source change. The same four historical
native differences at target offsets 0x68, 0x6a, 0x72 and 0x78 remain; no new
linked comparison was run. A separate reporting assertion initially failed on
Windows path spelling. Only the read-only summary was corrected; compilation
was not retried. No particular eliminating optimization pass is established.

An earlier external-record view was rejected before compilation because no live
record object at the source address was established. Disabling strict aliasing
would not establish that lifetime.

## ASprite two-byte transport

The guarded first-frame read became standard `memcpy` into a real unsigned short,
followed by signed-short conversion using the pinned target compiler's conversion
semantics. It reads exactly the same two bytes. No include, callback, loop,
declaration or other function changed. Original coherent source SHA-256 was
`20aa4311dfcd131db50278a508365a6e70c6ddaca06607a518c6cddd3be297b0`.

Literal recorded output:

```text
function_size: 92
input_size: 92
native_size: 82
raw_sha256: d34a33f871b061ee0554ab0285d16b0252392b5353ac5615ed4f768222c89036
object_sha256: bd1bfae599081e3cff2d3debd1f3d1fc07e50b9c8761d4ffaad808a9b67b1169
object_bytes: 13704
frontend: 1
assembler: 1
LD: 0
```

No memcpy call survived. The actual sequence used an unsigned field load, a
stack halfword store and a signed stack reload, rather than native register sign
extension. All 46 off-target definitions (44 credited and two pending), 45
off-target allocated payloads, 74 off-target references and 17 imports stayed
exact. Complete raw metadata equality failed for target growth and consequent
physical offsets; those failures are retained, not waived. All 440 original and
copied inputs, 119 tool/runtime files and 29 actual includes were stable.

A subsequent read-only corresponding-unsigned-access review found no supported
new transport boundary: single-use casts remain eligible for temporary-expression
replacement and lead to the known signed-memory selection. No alias candidate
was compiled; its full byte identity is therefore not claimed. The older
no-TER result also remains rejected: its 82-byte function had 84 input bytes,
nonnative target bytes and regressions in existing matches.

## SoundManager real row-array reference

The matched producer really allocates each row with `new CSound*[4]`; the
reference therefore names an established four-element array. The trial retained
a fresh table and row read on every entered channel, mutable signed outer bound,
callback order and return behavior. It did not hoist a row across a callback.

Literal recorded audit fields:

```text
old_functions:74
off_target_functions_exact:73
off_target_functions_total:73
imports_exact:true
off_target_refs_exact:true
all_ref_counts:[152,152]
target_size:82
input_size:84
strict80:false
native_common_positional_diffs:48
LD_runs:0
```

Object SHA-256:
`93592f2a9773a8ce27391dc03232cce7e1c9830be8e9a7d0ea450e96a9e6cec3`.
Target SHA-256:
`bc9e0de0e95accb0a1c5de3461c4cdec2cd0118f2399bd2ab8d29e3dff1ceb1f`.
All 73 off-target definitions, 83 off-target allocated payloads and 151 off-target
references remained exact; all 2079 pins stayed stable. Complete symbol,
reference and section equality failed only for the owned size change, shifted
call offset and owned section growth. No generated-name correspondence was used.

The outer load became table-first, but selected a different destination register.
Inner induction became increment-one/compare-four with an extra scaling
instruction, versus native increment-four/compare-sixteen. Function growth was
two bytes; section alignment added two more. Positional differences include
unresolved call operands and are not a linked mismatch count. Any byte-offset
composition requires a separately reviewed proposal; this patch is not accepted.

## Return-contract audit and progress

An independent ResStream audit found inherited `BufferStream::Close`, currently
declared void. All ten recovered direct callers discarded its return. This does
not prove an original signature or exhaustive indirect-call coverage; no return
type trial was justified or compiled.

Verified progress remains 4294/4550 game functions and 356938/561716 matched
bytes (63.54%). Fully Linked remains 114548 bytes (20.39%). Unmatched candidates
and instruction similarity do not contribute to either count.
