# Car-repair menu overlay

`GSCarRepairMenu::draw2d(StateMachine const*)`, Thumb address `0x002e1571`,
matches all 136 retail bytes with the existing NDK 1.6 r1 GCC 4.2.1 profile.
The normal verification output is:

```text
OK  _ZN15GSCarRepairMenu6draw2dEPK12StateMachine  0x002e1571  136 bytes
OK SECTION .repair_draw2d  0x002e1570  136 bytes
```

The reconstruction reuses the established application, device, screen-size,
driver, color and rectangle interfaces. State zero returns immediately.
State two draws an opaque black overlay; states three and one compute the
fade alpha and skip drawing when it is nonpositive. A shared C++ label keeps
the opaque path independent of the fade-alpha test, matching the original
control flow. No branch hints, compiler-output edits or existing-body edits
are used.

Five bounded source forms were measured. The archived explicit chain and a
likely-case trial each occupied 136 bytes but differed. A direct switch
occupied 132 bytes; an initialized-alpha form repeated the first output.
The early-zero return followed by a switch and shared drawing path matches.
Failed setup attempts were retained separately and were not counted as
source iterations. An existing Radio destructor declaration warning was
observed; it does not prevent compilation or verification.

The coordinator reviewed the three-file source/configuration patch and
independently rebuilt `state-hooks-gscarrepairmenu` with its dependencies:
334 function comparisons and 418 section/region comparisons passed. The
owning profile preserves all 66 previously selected functions and 205
previously selected sections/regions, adding the function and its section.

The complete coordinator native gate then passed all 190 profiles:
5,434 function comparisons, 5,338 section comparisons and 181 GOT/other
region comparisons, totaling 10,953. All 1,033 frozen source, configuration,
tool and nonmatching-artifact inputs remained stable throughout the run.
The linked native function SHA-256 is
`b5f7bf3bf9fcca3ce6276fc9228be5b9163a18dc5563abea952d34663ae8aa02`.

Only after those checks was the assembly marker removed and the official
catalogue, symbol map and progress reports regenerated. All 17,703 original
function identities remain accounted for. Exactly one function changes
from pending to matched, adding 136 matched bytes.

This completes the final pending function in the car-repair source unit:
all 15 tracked functions and 1,330 bytes are matched. The normal ByteMatch
report therefore adds the complete 1,330-byte unit to Fully Linked code;
the other 1,194 bytes were already matched. Aggregate progress becomes
4,272/4,550 functions, 344,406/561,716 matched bytes (61.31%), and
112,376/561,716 Fully Linked bytes (20.01%, 125/203 units). Fuzzy Matched
remains equal to Matched because partial candidates receive no credit.
