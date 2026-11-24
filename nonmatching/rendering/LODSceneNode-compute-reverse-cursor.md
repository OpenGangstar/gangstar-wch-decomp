# LOD reverse-cursor experiment: unmatched

Target: `LODSceneNode::computeLODLevel()`, `_ZN12LODSceneNode15computeLODLevelEv`,
Thumb `0x002d2d61`. Retail function size is 306 bytes; its physical input span is
308 bytes, including the genuine trailing `c046` padding.

The previous SDK-array candidate has the same sizes but four linked byte
differences. Existing authenticated compiler dumps locate the initial comparison
reversal at `037t.copyprop1` and independent induction-address commutation at
`085t.ivopts`. An earlier `-fno-tree-copy-prop` control emitted the same entire
object; ordinary comparison and entry-peeling variants were already spent.

One separately approved source representation used a genuine moving entry cursor
and the integer index required for `lodLevel`. The initial signed conversion and
negative-entry guard are preserved. A failed test at index zero returns before
forming a before-begin pointer. Successful selection retains fresh array lookups
after visibility callbacks; no cursor value crosses a callback for later use.
There are no new helpers, flags, barriers, layout changes or artificial uses.

Exactly one original frontend/assembler pair succeeded. Actual output is **302
function bytes and 304 input bytes**, with unchanged `c046` padding. Both native
extent gates fail. No linker or native-address comparison followed, and no
refinement or matching credit was granted. The previous 306-byte candidate
remains preferable; this experiment does not replace it.

The first threshold comparison still calls GT with distance in R0 and threshold
in R1; native uses LT with reversed arguments. The real cursor changes induction
and loop termination. Its initial base-plus-offset ADD is at a different dataflow
position from the native next-iteration initializer, so operand orientation alone
does not establish a corrected instruction.

All 37 other emitted functions, 41 off-target allocated sections, 93 named imports
and 222 off-target semantic references remain unchanged. Raw symbol and section
names retain identity without normalization. The only changed raw sections are
target code, its relocation table, and the symbol table's target size entry.
All 1,031 historical fixture files were pinned before and after; only the reviewed
method changed. Eight tool/runtime pins stayed stable.

The old 28-function/10-region native-linked receipts are historical; they were
not rerun for this unlinked candidate. The JSON retains exact source/object/raw
function hashes and strict failures. The public method is a historical full-TU
fragment, not standalone code. Its LF patch applies to the normalized historical
SDK fixture; a private apply check reproduced the complete tested source after
newline normalization. No compiler output was edited.
