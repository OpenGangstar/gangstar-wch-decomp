# Reviewed bounded source controls, 2026-11-24

These four private source experiments remain unmatched. Each used exactly one
original GCC 4.2.1 frontend invocation and one original assembler invocation;
both commands exited 0. No linker invocation was made. No canonical function,
header, assembly marker, matching profile or progress denominator changed.

| Function | Retail address | Native bytes | Candidate function/input bytes | Result |
| --- | --- | ---: | ---: | --- |
| RenderFX::Find | 0x003ed6e5 | 416 | 420 / 420 | Extent fails |
| SoundManager::getNumberOfPlayingSounds | 0x00352cad | 80 | 96 / 96 | Extent fails |
| CarSounds::Init | 0x0035047d | 1032 | 1032 / 1032 | Known native instruction operands still differ |
| Vehicle::UpdatePhysic | 0x0030d6c9 | 9212 | 9088 / 9088 | Extent fails |

The accompanying patches describe historical private fixtures, not changes to
apply to the current source tree. Sound and Vehicle patches are function-body
fragments. `results.json` records original and LF-normalized public patch hashes,
actual unlinked object/function hashes, and detailed local report provenance.
Raw relocatable hashes establish candidate identity only; they do not establish
a native byte match. Original compiler output was never edited.

## Findings and preservation limits

Find composes unsigned length locals with the historical ordinary OR rejection
guard. It changes 13 target bytes without removing either expanded separator
branch. All 113 other function payloads and 138 off-target allocated payloads
remain exact. Off-target references require an explicitly disclosed anonymous
namespace correspondence C5B77F53 to 193B4F0D; raw name identity fails. No further
guard or likelihood variation is authorized.

Sound count preserves the signed fresh outer bound, four channels and one fresh
table read per entered channel. The refresh representation grows the function
from 80 to 96 bytes and retains the unwanted indexed operand order. All 73 other
function payloads, 83 off-target allocated payloads and all 152 semantic
references remain exact. Size-dependent metadata changes are target-owned.

CarSounds retains the signed ordinal for guards and separate unsigned byte
offset induction for address uses. Exactly four object bytes change: auxiliary
operands at target offsets 0x2d8 and 0x2e6 improve, while threshold operands at
0x32a and 0x32c regress. The earlier on-engine differences and auxiliary
destination difference remain. All 58 other functions, 49 off-target allocated
payloads, 212 symbol records, 27 imports and 245 references remain exact without
name correspondence. Native extent alone supplies no matching credit.

Vehicle correctly produces one common fourth-light dispatch with a fresh node
and vtable after the first three callbacks. Selected member-slot addresses are
retained; actual node dereferences remain after the fourth callback and at the
original timeline boundaries. It shrinks the preferred 9104-byte function by
16 bytes, increasing the native deficit. Frame allocation stays 396 bytes versus
native 412. All 200 other function payloads and raw imports remain exact.
Raw metadata/reference equality fails: 23 anonymous local symbol/section pairs
change namespace token D315B92B to 2986B562. A separately recorded one-token
bijection accounts for all 230 off-target allocated payloads and 1530 off-target
references; remaining symbol differences belong to the target extent/mapping
positions. This correspondence is disclosed, not a blanket raw-preservation
waiver. No existing historical linked result is attributed to this object.

All recorded source/tool pins remained unchanged: Find 858 original plus 858
copied inputs and 119 tools, Sound 1639 files, CarSounds 873 fixture inputs plus
eight tools, Vehicle 1864 files. Linked native comparisons, GOT checks and global
profile verification were not run for these failed candidates. Existing matched
progress remains 4294/4550 functions and 356938/561716 bytes (63.54%); Fully Linked
remains 114548 bytes (20.39%). No fuzzy similarity is credited as matching.

Preserve these negative results and existing attempt budgets. Revisit only with
new evidence and a separately bounded coordinator-approved experiment.
