# FSelect: exact 32-byte match

`FSelect(float, float, float)` now matches the complete retail function and
literal pool at Thumb `0x00349315`. It returns the positive argument for
values greater than or equal to zero, including either signed zero; unordered
comparisons select the negative argument.

The named `result` local is intentional. The earlier direct returns let
GCC 4.2.1 rename its ignored return temporary into parameter `positive`.
The cold path consequently overwrote that parameter before the shared return,
differing in two bytes. An unchanged-source diagnostic reproduced the complete
924-byte object and traced this decision to `032t.copyrename1`. A genuine
named result invokes GCC's rejection of coalescing two user variables and
preserves the native independent return register. No hints, assembly, register
pins or compiler-output changes are used.

Exact comparison output:

```text
OK  _Z7FSelectfff  0x00349315  32 bytes
OK SECTION .fselect  0x00349314  32 bytes
```

The worker's fresh current caller verification preserved all 21 previous
AnimObject functions and 22 section/region checks. The coordinator then placed
the function in its original translation unit, linked its genuine definition
with the existing caller, and verified all 22 functions and 23 section/region
checks. Independent global verification passed all 191 profiles and 11,127
comparisons, covering all 4,292 previous credited selectors plus FSelect.

## Corrected source attribution

The previous catalogue incorrectly assigned FSelect to `IPhone.cpp`. Empty
IPhone and Win32 object entries have coincident `$t` markers at `0x00349314`;
the nearest-anchor table retained the first. The AnimObject object owns the
function's internal `$d` marker at `0x00349330`, the following code marker,
and `_GLOBAL__I__Z7FSelectfff`. GCC's module-name selection excludes external
declarations, providing independent support for this ownership.

The narrowly scoped attribution correction is in `tools/layout.py`, with
regression tests. Generated tables retain every original retail function and
source-file entry. FSelect moves from app/IPhone to characters/AnimObject and
adds 32 genuinely matched bytes. AnimObject still contains unmatched code;
this change does not create a completed IPhone unit or add Fully Linked bytes.
