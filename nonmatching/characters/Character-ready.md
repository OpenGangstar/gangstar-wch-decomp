# Character ready: two-byte function near miss

This candidate is **not matched**. It preserves the native case mappings but
differs in physical handler placement. No decompilation credit is granted and
the original assembly remains pending.

Baseline: `cd3301292ca3e38471e30a6a944ae0f9581b7b53` (PR #739). Apply only in an
isolated checkout:

```powershell
git apply --check nonmatching/characters/Character-ready.patch
git apply nonmatching/characters/Character-ready.patch
$env:WCH_BASE_LIB = 'C:/path/to/your/libsanangeles.so'
python tools/build.py ai-startup-character
```

Expected exit: **1**. The new function, its full section and its switch table
fail. The original checks must remain successful.

## Bounded reconstruction

The five archived source forms stopped early after several identical outputs;
ordinary case reorderings with grouped handlers did not resolve placement.
One bounded structural escalation gives cases 2/6 and 3/4 separate identical
bodies, allowing the compiler to merge them. Every original animation ID,
condition and field store remains unchanged. The existing int `unknown228`
field replaces the archive's provisional last-punch field spelling; no shared
header, layout or existing method body changes are needed.

This restores the native layout except for the physical order of handlers for
cases 7 and 8. A reversal of their source order, followed by one explicit
return form for case 8, produces the identical complete unlinked target. All
three tested forms share SHA256
`d6846e4d0dd2a454e1604a2daae20a369207481264ebaef137f1f595410e66bd`.
The simple numeric-order form is retained. No hint, assembly, output editing
or forced-inline helper is introduced. The escalation stopped at this repeated
output; further case/return variations require new evidence.

## Exact remaining differences

Both executable function and physical section are 284 bytes. Only two function
bytes differ:

| Offset | Native immediate | Candidate immediate |
| --- | ---: | ---: |
| `0x96` | 145 | 138 |
| `0x106` | 138 | 145 |

The complete 36-byte native switch table at `0x0041bd18` has corresponding
single-byte differences at `0x1c` and `0x20`. Cases still select their intended
animations because the table destinations follow the moved handlers. Neither
the two-byte function difference nor the table difference may be patched out.

```text
MISMATCH  _ZN9Character5readyEf  0x002f26ad
  expected : 01 93 a0 23 d4 58 30 1c 91 21 3a 1c 00 23 a0 47
  actual   : 01 93 a0 23 d4 58 30 1c 8a 21 3a 1c 00 23 a0 47
  differs at 0x96
```

The owning native link retains **113 existing function checks, 31 section
checks and one GOT region check**. The profile compares the new full function,
full section and full table independently, with strict 284/36-byte extent
assertions and normal overlap checking. No new support definition is emitted.
This is an owner/dependency proof, not a new 190-profile run. The unapplied
patch changes no production progress, shared headers, flags or existing bodies.

## Replay after the selector match

One unchanged-source replay against the newly compiled getSpecificAnimation
callee produces the identical full unlinked target hash above. The same two
function bytes and two table bytes differ. This private owning image preserves
114 existing functions, 32 sections and one GOT region, including the new exact
selector. Callee visibility does not resolve the layout; no further source
variation or credit follows from this replay.


## Single switch-likelihood escalation

At main PR #743 (`68f0bc30`), one separately bounded experiment wraps only the
weapon-type selector in `__builtin_expect(getWeapon()->getWeaponType(), 8)`.
This tests whether weighting the earlier native case-8 handler resolves the
known case-7/case-8 physical inversion. Every case payload, field store and
ordinary compiler flag remains unchanged. No probability grid or additional
case reorder is attempted.

It does not resolve placement: the complete 284-byte function AND complete
36-byte table are byte-identical to the unhinted saved image. Function/section
still fail first at 0x96; table fails first at 0x1c. The valid owning run preserves
114 existing functions, 32 sections and the GOT region, plus its PhysicsAttributes
dependency (38 functions, ten sections and one GOT region); exit 1. No new whole-
project gate is claimed. The hint does not qualify for production or credit.
Character-ready-switch-likelihood.patch is a complete independent unapplied
reproducer against this newer baseline, not a delta on the older patch above.
The original assembly and every credited function remain unchanged.
