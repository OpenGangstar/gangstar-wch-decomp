# ASprite frame-module painting: exact

`ASprite::PaintFModule(int,int,int,int,int) const`,
`_ZNK7ASprite12PaintFModuleEiiiii`, is byte-identical at Thumb `0x0034a015`:

```text
OK  _ZNK7ASprite12PaintFModuleEiiiii  0x0034a015  220 bytes
OK SECTION .asprite_paint_fmodule  0x0034a014  220 bytes
```

The implementation uses the existing serialized Frame, FModule and Module
records. It paints a nested frame when flag 8 is set; otherwise it adjusts
coordinates for horizontal/vertical flips and paints the selected module. The
terminal calls and transform flags retain their native argument order.

## Matching reconstruction

An unchanged-source diagnostic first reproduced the entire historical 11,056-byte
object, including all 70 section headers, 153 symbols and 64 relocation records.
This established that diagnostic dumps described the actual 220-byte candidate.
The earlier return-root discovery did not apply: receiver/blob roots remain
separate. Expansion selected a different address association; final scheduling
subsequently changed receiver and load ordering.

Three older raw-record forms already produced the native address association,
but all were 222 bytes and remained unmatched. The later typed-record form was
220 bytes, with 28 differing linked bytes. One bounded composition retained the
typed records and formed the serialized integer byte displacement before adding
the blob at the frame and two conditional module lookups. Frame and Module
strides are their genuine 28- and 10-byte extents. Unsigned frame arithmetic
preserves the measured 32-bit calculation without introducing signed overflow.

Only those three address expressions changed. Field widths, FModule lookup,
control flow, receiver, calls and compiler options stayed unchanged. This restored
native scheduling as an observed result; no barrier, register constraint, branch
hint, padding or compiler-output edit was used.

The explicit PaintModule declaration imports its original nonvirtual const-member
ABI: the ASprite receiver in R0, followed by four integer arguments. It names the
actual native function, not a surrogate implementation. Native Thumb metadata
binds that genuine import; PaintFModule is now a compiled executable definition
and is removed from the external-function metadata list.

## Verification and credit

The saved-object native link passed all 40 historical function selectors and 34
regions, plus the complete 220-byte target section. Its 39 pre-existing functions
were preserved. That historical GOT retained 642 native differences in its
reserved 864-byte prefix; the 17,972-byte checked body was exact. Neither that
prefix nor the historical context was represented as a complete current proof.

The coordinator then integrated the same function into current source without
changing shared headers. The current owner passes all **44 functions and 38
regions**. The full current regression build passes **191 profiles and 11,129
comparisons**: 5,463 function checks, 5,485 section checks and 181 region checks.
All 4,293 previously credited functions occur in the exact output, and all 1,153
captured inputs stayed unchanged during that run. The new complete section was
also independently compared against retail.

Only after that proof was the assembly marker removed and the catalogue
regenerated. Credit adds **one function and 220 bytes**: 4,294 / 4,550 functions,
356,938 / 561,716 bytes (63.54%). Fully Linked stays at 114,548 bytes (20.39%):
ASprite still has pending functions. All 17,703 retail catalogue entries remain.

Do not apply this association mechanically to other ASprite functions.
PaintModule and GetPixelInfoInFrame already use their own native table-base
associations; their bounded transfer reviews found no additional source trial.
