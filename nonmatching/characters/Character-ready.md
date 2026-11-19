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
