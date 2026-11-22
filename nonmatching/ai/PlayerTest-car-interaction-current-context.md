# PlayerTest car interaction: current-context replay remains unmatched

Target: `libsanangeles.so`, `_ZN10PlayerTest20updateCarInteractionEv`, Thumb
`0x0030406d`, 1,684 bytes. The recovered six-form v6 candidate already has
native size but does not match. Complete native switch recovery exposes no
new source guard or cleanup discrepancy. This compatibility-only replay does
not reset its exhausted source-form budget.

The current accepted PlayerTest hierarchy replaces the old duplicated storage.
The private replay retains current accepted source tokens and maps only two old
byte-array expressions to Character::unknown144, preserving Player offset 148.
It adds a nonvirtual declaration and the required GS3D include. All current
owner selectors, four dependency profiles, native placements and compiler flags
remain. Actual setAnim and getSpecificAnimation definitions are linked, never
replaced by imported retail bindings.

One primary GCC/assembler invocation emits a 1,684-byte function and input
section, plus its 68-byte switch table. All 85 preexisting actual function
definitions, 116 allocated payloads and 70 semantic relocation sections remain
unchanged. The primary object SHA-256 is
`ab0cde4dad38925cdf9ee2bcd256f329b989fbbec6886544db403d8cef72508d`.

The first dependency launch failed with `FileNotFoundError: [WinError 2]`
because the private runner resolved a relative toolchain under its scratch
directory. A separately authorized mechanical continuation resolves each
unchanged profile's toolchain against the actual toolchain directory and reuses
the same primary object. It freshly compiles dependencies, regenerates genuine
GOT/Thumb bindings and links the ordinary strict native image. No source retry,
global toolchain override, output editing or relaxed linker assertion is used.

Coordinator reran authoritative checks on the actual linked images:

| Unit | Existing function checks | Existing section/region checks |
| --- | ---: | ---: |
| PhysicAttributes | 38 | 11 |
| Character | 114 | 33 |
| HUD helpers | 49 | 42 |
| NPC | 72 | 16 |
| PlayerTest | 84 | 26 |

All 357 existing function and 128 section/region comparisons pass. All 1,109
frozen inputs remain unchanged. The target checks fail:

```text
MISMATCH  _ZN10PlayerTest20updateCarInteractionEv  0x0030406d
  expected : d1 f7 06 f9 ba 23 5b 00 c5 4e fb 58 84 6c 7e 44
  actual   : d1 f7 06 f9 ba 23 5b 00 ce 4e fb 58 84 6c 7e 44
  differs at 0x18
MISMATCH SECTION .player_car_interaction
  expected : d1 f7 06 f9 ba 23 5b 00 c5 4e fb 58 84 6c 7e 44
  actual   : d1 f7 06 f9 ba 23 5b 00 ce 4e fb 58 84 6c 7e 44
  differs at 0x18
MISMATCH SECTION .player_interaction_switch
  expected : 66 5e ee ff a0 5e ee ff 66 5e ee ff
  actual   : 66 5e ee ff b0 5e ee ff 66 5e ee ff
  differs at 0x4
```

The linked function SHA-256 is
`851bc6c9aea05032d1da326dbf2db74dfceba6f0e9e56580ddbf435244f464c2`.
Its 1,130 differing bytes and native-sized extent confer no matching credit.
The switch payload is identical to the old v6 candidate, still differing from
retail. No full 191-profile gate was run or claimed.

Source-fidelity limitation: writing the private source converted its accepted
prefix from LF to CRLF. The prefix is text-identical, but not byte-identical;
the original byte-preservation requirement was not met. The actual compiler
inputs and hashes are frozen, all old emitted definitions are preserved, and
no corrective recompile was used to conceal this limitation.

Commands, original failed launch, continuation output, sources, objects, images,
per-profile input identities and coordinator verification remain in
`_scratch/worker-player-carinteraction-current-context-control`. Keep its
current-context candidate separate from historical v6. Its assembly marker and
generated status remain unchanged. Further source attempts require new evidence.
