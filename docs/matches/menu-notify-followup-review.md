# Menu notification follow-up review

The follow-up to PR #726 investigated remaining menu handlers using the newly
recovered widget interfaces. None of the trials described here qualifies as a
match. Production functions, assembly files, compiler flags and progress
selectors remain unchanged.

## Car rental

`Menus::ServiceCarRental::Notify` is the 448-byte Thumb function at
`0x002eb761`. One additional, explicitly bounded trial replaced erased widget
lookup and C-ABI widget calls with the existing `MenuManager`, `Widgets::Arrows`
and complete `Widgets::Shop` interfaces. The original algorithm was retained,
including the page query during each iteration, the table reload after
`sprintf`, floating-point price conversion and final menu localization call.

The strict 448-byte function and section placements succeeded, but the actual
comparison exited with status 1:

```text
MISMATCH  _ZN5Menus16ServiceCarRental6NotifyEPK10MenuWidgeti  0x002eb761
  expected : 4d 46 44 46 f0 b4 63 4f 0c 1c 63 49 7f 44 93 b0
  actual   : 4d 46 44 46 f0 b4 63 4f 15 1c 63 4a 7f 44 93 b0
  differs at 0xe
MISMATCH SECTION .car_rental_notify
OK SECTION .car_rental_suffix  0x00419e68  8 bytes
```

There are 248 equal positional bytes and 200 differing bytes. This diagnostic
is not matched progress. The complete native function SHA-256 is
`abae50173cc035548d452be09ecdd65ae1e79d2e1fca0c4a779a1ce98b8d61d2`;
the candidate SHA-256 is
`db0cd7529abd2f196489022631b0586d99d5b6d400a723fddbd7c5394bc5b01b`.
All 640 existing function checks and 421 existing section, region and GOT
checks passed. All 832 previous allocated object payloads were unchanged.
The trial is parked; repeating source-order permutations is not authorized.

### Shared format prerequisite

The candidate needed the real pooled `%s%s` object at `0x00419e70`, currently
owned by `MenuWidget.cpp` as the local `tutorialPartFormat`. A separate private
prerequisite exposed that same definition through a hidden external
declaration. It did not duplicate storage or introduce an absolute alias.

The same five-image closure passed before and after the prerequisite: 640
function checks and 421 region checks in each run, with all 832 allocated
payloads unchanged. The one five-byte symbol and its eight-byte physical
section retained their native address and bytes. Symbol binding intentionally
changed from local/default to global/hidden. In the provider, 146 raw
relocation sections changed symbol indices; referenced names, types, offsets
and code/data addends remained unchanged. The other four objects retained
identical raw relocation bytes.

The coordinator accepted this preservation proof, but did not integrate the
refactor: the proposed consumer remains unmatched. Both prerequisites and
candidate remain private, without matching or Fully Linked credit.

## Other reviewed handlers

| Function | Native bytes | Reviewed result |
| --- | ---: | --- |
| `Menus::MainMenu::Notify` | 544 | Complete widget declarations produced the same unmatched archived bytes; all 1,054 existing comparisons passed. |
| `Menus::Map::Notify` | 220 | Best typed trial has 21 differing bytes. A grouped-case trial emitted only 216 bytes and was rejected. |
| `Menus::ServiceCorruption::Notify` | 184 | Complete widget interface emitted 196 bytes. Native and source already use the same canonical Wanted singleton and player APIs. |
| `Menus::ServiceMissions::Notify` | 340 | A signed loop index restored the native extent, but not the function bytes; all 1,054 existing comparisons passed. |
| `Menus::OptionGameSettings::Notify` | 1,056 | Corrected native call/data flow emitted 1,048 bytes. An unchanged diagnostic compile proved that register reload followed by CFG cleanup merges two virtual-call tails. This does not establish a compiler-flag correction. |

These results do not authorize optimization-flag searches, additional branch
hints, output modifications or edits to existing matched functions. Revisit
only with concrete new evidence and a recorded bounded assignment. Matched,
Fuzzy Matched and Fully Linked totals remain unchanged.
