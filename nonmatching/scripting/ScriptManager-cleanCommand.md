# Script command cleanup: separate scoped handlers

This candidate is **unmatched** at Thumb `0x0033ffc1`. Candidate and native are
212 bytes, but function and complete 472-byte table differ. No credit is added;
the original assembly remains pending.

Baseline: `39ae587ea4430b0b566500ef933dd8344e4e9fb3` (PR #740). Apply only in an
isolated checkout:

```powershell
git apply --check nonmatching/scripting/ScriptManager-cleanCommand.patch
git apply nonmatching/scripting/ScriptManager-cleanCommand.patch
$env:WCH_BASE_LIB = 'C:/path/to/your/libsanangeles.so'
python tools/build.py script-manager-helpers
```

Expected exit: **1**. The new function, full section and full table fail;
existing comparisons must remain exact.

The six archived forms group opcode cleanup handlers. One bounded transfer
from the selector recovery separates all 54 scoped handlers, preserving each
original cast, delete order and null store. There is no intentional fallthrough
in the eight original groups; default opcodes still do nothing. No signature,
field, header, existing body, helper or compiler option changes.

Original group order emits 212 bytes with 49 differing function bytes, first
at `0x8c`. One final numeric opcode order emits a distinct 212-byte function
with 33 differing bytes, versus 141 in the archived final executable. Numeric
order is retained. No further form was attempted.

```text
MISMATCH  _ZN13ScriptManager12cleanCommandEPN7Structs13ScriptCommandE  0x0033ffc1
  expected : 00 28 01 d0 84 f6 04 eb 00 23 a3 60 e7 e7 80 68
  actual   : 00 28 01 d0 84 f6 04 eb 60 68 00 25 a5 60 00 28
  differs at 0x54
```

The full 118-entry table at `0x0042f28c` also fails, first at `0x18`. Independent
function/section/table comparisons retain strict 212/472-byte assertions and
normal overlap checking. Only the target is newly emitted. Complete unlinked
SHA256: `6c9ab8a5aff54dd0f525659a7b31048d90564f5fa3caa0aa7d17641eebad0abe`.

The owner preserves 143 existing functions, 133 section checks and one GOT
region. This is an owner/dependency proof, not a new 190-profile gate. The
unapplied patch changes no production progress. Further cleanup-layout
experiments require new evidence; no output or table editing is permitted.
