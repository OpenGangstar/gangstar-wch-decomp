# Script state and player-context selection

`Script::setState(Script::State, PlayerTest::eContext)` at Thumb `0x0033922d`
now matches all 58 retail bytes. Its entire 60-byte physical section also
matches, including the native alignment bytes. The assembly marker is removed
only after complete verification. No existing function implementation changes.

The function stores the requested script state. Only State2 resolves a player
context: AnyContext selects the player's current context; another requested
context that differs from the player's moves the script to State1. It then
stores the resolved context. The genuine enum parameters, existing member
layouts and current PlayerTest interface are retained.

The saved canonical source previously emitted 66 bytes. Replaying that exact
body under the verified original NDK `-fno-short-enums` baseline produces the
native 58 bytes without a new source form. The first strict linked comparison
then exposed only an import-mode error: GetPlayer was linked as ARM instead of
Thumb. Adding the genuine existing Thumb import corrects that call. No other
compiler option, source expression, hint, field or helper change is needed.
See the NDK configuration evidence in [COMPILER-NOTES.md](../COMPILER-NOTES.md).

Exact final output:

```text
OK  _ZN6Script8setStateENS_5StateEN10PlayerTest8eContextE  0x0033922d  58 bytes
OK SECTION .script_set_state  0x0033922c  60 bytes
```

All 26 existing owner functions, 11 existing sections and the GOT region remain
exact; the new function and section bring the owner to 27/12/1 successful
checks. Normal strict linking and independent function/whole-section checks
remain enabled. No output rewriting, inline assembly, register constraints,
barriers or branch hints are used.

The complete actual-root verification passes 190 profiles: 5,433 functions,
5,337 sections and 181 regions, totaling 10,951 comparisons. All 976 frozen
source/configuration/tool/nonmatching input hashes remain stable, exit 0,
no mismatches or dependency skips. This gate includes the adopted NDK enum
flag in the real manifests and the new implementation. It supersedes the
preliminary copied-manifest diagnostic for this resulting source context.

Independent ELF review confirms a real executable definition at the native
address, size 58, in the allocated `.script_set_state` section (flags 6), not
an absolute import or unverified relocated body. Executable function SHA256:
`e7a7b128023c493233647116c017360312c9050491de2e1ef833e20b1928befe`.

This adds one genuinely matched function and 58 game-code bytes. All original
catalogue identities and denominator bytes remain. Script.cpp still has pending
functions, so this change adds no Fully Linked bytes. Native Windows/x86 and
launcher sources are untouched.
