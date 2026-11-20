# Octree node depth layout

The nested OctTreeAABBNode class in GS3DStuff.cpp omitted the final depth
member. Native initialization and recursive ownership checks establish an int
at offset 60. Adding this field restores the observed 64-byte node allocation;
it does not add a constructor implementation or a matched function.

The coordinator checked these instruction bytes directly against the retail
library, independently of the archived candidate:

| Address | Bytes | Observation |
| --- | --- | --- |
| 0x002df67a | 01 32 | Increment the int parent-depth argument. |
| 0x002df684 | c2 63 | Store the incremented value at this + 60. |
| 0x002df884 | 40 20 | Request a 64-byte recursive node allocation. |
| 0x002df89c | ca 6b | Load the current depth for the recursive constructor. |
| 0x002df8c6 | 4d 46 eb 6b 01 2b | Load depth at 60 and compare against 1 for incoming-root ownership. |

Original GCC 4.2.1 syntax/layout probes return 0 before and after the declaration
change. The node size changes from 60 to 64; alignment remains 4, roots remains
at 24 and the eight child pointers remain at 28. The new member has type int
and offset 60. The compiler reports four existing offsetof warnings before,
six after including the new offset assertion; none are suppressed.

The archived constructor already contains this field and remains unmatched:
812 versus native 832 bytes, first difference at 0xe. Recovering the public
layout does not justify repeating its exhausted six source forms. No function
body, assembly marker, generated table, compiler setting or Windows port code
changes. The full current-root native preservation gate reports 190 profiles, 5434 functions,
5338 sections and 181 regions: all 10953 comparisons exact, exit 0. All 1063 frozen
source/configuration/tool/nonmatching inputs remain stable. Matched/Fuzzy remain
61.31%; Fully Linked remains 20.01%. No original function identity is removed.
