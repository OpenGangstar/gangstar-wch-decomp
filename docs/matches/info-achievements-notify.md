# Menus::InfoAchievements::Notify

The complete 224-byte Thumb function at `0x002ea925` now matches retail. It
delegates to `Infos::Notify`, accepts arrow-widget events 1 and 2, updates the
title text and icon for the selected achievement category, and resets the
achievement scroll for event 1. Definitions remain in `MenuState.cpp`.

The reconstruction reuses existing widget interfaces, the achievement icon
table, and the verified `MenuWidgetTable` fields at offsets 420 and 424. Adding
the missing nonvirtual `Title::SetIcon` declaration and the partial Achievements
interface changes no existing function body or object layout.

## Permitted branch hints

Two GCC branch-likelihood annotations retain the native block layout without
changing either getter's condition, returned pointer, null fallback or number
of manager evaluations:

- `__builtin_expect(15 < titleTable.count, 1)` keeps the title-null fallback in
  the cold tail.
- `__builtin_expect(11 < achievementsTable.count, 0)` places the successful
  achievement-widget load after that fallback, matching the native tail order.

These are compiler layout annotations under the maintainer's documented hint
exception, not assertions about observed gameplay probabilities. No inline
assembly, register constraints, barriers, output editing or optimization-flag
changes are used.

The historical four source forms stalled at a branch-layout difference. A
bounded two-orientation escalation recovered the hot body but left 17 bytes
different because the cold blocks were reversed. One explicitly authorized
follow-up annotated the second existing getter condition and matched the
complete function. No assembly was removed until the coordinator integrated
the result and completed native verification.

## Verification

The comparison tool printed:

```text
OK  _ZN5Menus16InfoAchievements6NotifyEPK10MenuWidgeti  0x002ea925  224 bytes
OK SECTION .info_achievements_notify  0x002ea924  224 bytes
```

The complete native function SHA-256 is
`ec3d5b135dbccdc762679e763800a075912e5a55054bbead72eb3cc43202715a`.
The linker asserts the complete 224-byte physical section extent. The sole new
native import is the genuinely pending `Achievements::SetCategory`; actual
compiled widget definitions remain linked normally and are not overridden.

The affected five-profile closure passes 635 function, 408 section and five GOT
region comparisons: 1,048 checks, retaining all 1,046 previous checks. Only the
new target's allocated code changes relative to the historical replay; no
helper, constructor, vtable or data implementation is added.

The coordinator's integrated `python tools/build.py --all` exits 0 across 190
profiles with 5,291 function, 5,186 section and 181 region comparisons: 10,658
successful checks. All previously matched functions and sections remain exact.
This adds one game entry and 224 matched bytes. Matched/Fuzzy becomes
340,216 / 575,264 bytes (59.14%); Fully Linked remains 110,400 bytes (19.19%)
because the original source group still contains pending functions.
