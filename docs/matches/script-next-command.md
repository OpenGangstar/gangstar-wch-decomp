# Script::nextCommand exact match

Script::nextCommand(int) matches all 252 retail bytes, including every call
relocation, at Thumb address 0x0033ce19. Its full input/output section is 252
bytes and ends at the following executeSubScript boundary, 0x0033cf14.

```text
OK  _ZN6Script11nextCommandEi  0x0033ce19  252 bytes
OK SECTION .script_next_command  0x0033ce18  252 bytes
```

## Source and branch hint

The existing retained reconstruction had 254 function bytes and a 256-byte
input. A byte-identical unchanged-source diagnostic established that its extra
instruction was introduced by global allocation/reload: the event-manager
pointer in R8 required a low-register load and a separate move. Retail loads
that pointer directly into R7 and keeps the script-manager pointer in R8.

The reconstruction adds only this GNU branch-likelihood hint to the loop guard:

```cpp
__builtin_expect(getState() == State2, 1)
```

The call remains evaluated once at its original short-circuit position. All
callbacks, memory accesses and execution order remain unchanged. The hint is
permitted by AGENTS.md because the entire function and affected existing matches
compare byte for byte; the comparison output is recorded above.

Measured old profile weights and the primary GCC 4.2.1 allocation formula gave
manager/events priorities 209/208. The untried Script State2 hint was distinct
from an earlier Mission-state hint. GCC 4.2.1's 99.01-percent expectation,
compared with the old inferred 98-percent edge, conditionally modeled priorities
207/208 with unchanged CFG/lifetimes. Those modeled post-hint priorities were
not separately observed. Actual compiled bytes confirm the desired register
homes and removal of the extra move. This does not prove retail used this hint
or establish gameplay frequencies.

The reconstructed return type is bool, reflecting normalized zero/one on every
retail exit. Observed callers ignore the result, so original bool versus int
source spelling remains unavailable; the resulting complete physical ABI and
machine code match. Mission.h supplies the existing real getState interface.
No inline assembly, register pin, barrier or compiler-output editing is used.

## Verification

A private genuine three-object link passed all 28 function and 14 section/region
selectors, including the target. The new owner and original auxiliary objects
were used without emitted-definition overrides; all 437 frozen link inputs
stayed unchanged. The linked image SHA-256 is
248ca92e3dd432e0fb98d1e7b53461778290451139901c527150245252cff6b6.

Canonical integration initially failed compilation because Mission was only
forward-declared. That failed 52-profile log is preserved. Adding the genuine
Mission.h include resolved it. A subsequent fresh complete build passed all
191 ARM profiles: 5,466 function, 5,489 section and 181 region comparisons,
11,136 total. All 891 frozen source/configuration/tool files remained unchanged.
A separate read-only audit covered all 4,296 previously matched game entries
without gaps. The marker was removed only after those gates passed.

Raw private stop receipts remain preserved: two old references included the
owned function's changed size, 254 to 252. Their instructions, relocation bytes,
addends and other symbol metadata were unchanged; the coordinator independently
verified all 20 off-target relocation sections before accepting that particular
annotation change. Nothing rewrote or normalized compiler output.

No native Windows implementation was changed or built. Script remains an
incomplete unit, so this match adds no Fully Linked credit.
