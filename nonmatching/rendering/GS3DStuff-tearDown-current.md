# GS3DStuff::tearDown: current unhinted 492-byte candidate

Target: `_ZN9GS3DStuff8tearDownEv`, Thumb `0x002df419`, 492 retail bytes.
The accompanying unapplied patch preserves a current-context reconstruction.
It remains unmatched; its assembly marker and progress status are unchanged.

The historical unhinted result survived only as a listing. This new compilation
uses the current complete GS3DStuff prefix and an authenticated archived body,
with the existing array member spelling corrected from `sorted` to `is_sorted`.
The patch adds the ordinary nonresetting ownership helper, its required include,
and the genuine nonvirtual `MenuManager::tearDown()` declaration privately.
It preserves array layout, cleanup order and global-reset behavior. The six
historical source/destructor/hint controls remain spent.

## Actual object result

One ordinary frontend/assembler pair succeeded with the current 16/4 options.
The actual Thumb function and input section are both 492 bytes. All 113 old
function payloads and 187 old allocated payloads remain exact. Generated
namespace names and specific assembly labels changed; their reviewed
correspondence preserves old metadata and semantic references. Raw whole-file
identity failures remain recorded; no compiler output was rewritten.

| Artifact | SHA256 |
| --- | --- |
| Measured source | `a5441aeb91b4ad923c1b9b5be3154038532770d492621610a1b9374819111e3b` |
| Object | `8511acc9cd313451c097386c40cc9c579a5efab5473931433dac2802edea4294` |
| Assembly | `991ac47d52bde28b545dc0c1814fec7cb42c8d7dbf2508e82e5ef31efc3dbcd1` |
| Raw target | `77b3cfbbaed2f80ead5f99b63d2ab4b80374e329e4d65ac36831694b5dadd88b` |

Six nonrelocated branch bytes differ from retail:

| Target offset | Retail | Actual |
| --- | --- | --- |
| `0x11c` | `38` | `40` |
| `0x132` | `35` | `31` |
| `0x148` | `26` | `22` |
| `0x196` | `c2` | `d8` |
| `0x19e` | `d4` | `c9` |
| `0x1a6` | `c5` | `ba` |

The object also contains 50 unresolved relocations, including all 17 literal
pool words. No candidate ELF or new linked comparison exists. Those relocation
bytes are not counted as native differences or silently treated as matching.
Linking cannot repair the six nonrelocated branch differences above.

## Measured layout origin

An unchanged-source diagnostic preserved every object and assembly byte outside
the specifically reviewed generated namespace strings. The actual backing-release
call order remains source order 1,2,3,4,5 from RTL expansion through pass 146.
Pass `147r.bbro` first changes it to 5,4,3,2,1; later passes retain that order.
Retail instead places those tails 5,4,1,3,2.

The first four candidate release blocks each have frequency 243; the final
block has 269. Recorded pointer, call and final early-return predictors explain
those frequencies. They do not reveal native probabilities or authorize precise
likelihood tuning, cleanup permutations or another source grid.

## Using the archive

`git apply --check nonmatching/rendering/GS3DStuff-tearDown-current.patch`
succeeds against the checkpoint after PR #790. The patch is source only: the
normal profile does not select this pending target. Future native verification
must place its real input at `0x002df418`, assert function/input 492 and end
`0x002df604`, preserve native neighbors, resolve genuine Thumb callees, exclude
emitted definitions from fallback bindings, and check all old owner/dependency
functions and complete regions. Passing old selectors alone is not a match.

The public patch normalizes newlines and blank context lines for whitespace
checks. Its SHA256 is
`b49dc408edf36a15ec2995a24bd6a415b256fe853c985ae387712143caec5144`;
the original measured private patch is retained separately. No production
source/header/profile or Matched/Fully Linked value changes.
