# Menus::Infos::Notify

The complete 304-byte Thumb function at `0x002ea7f5` and its 20-byte switch
table at `0x0041a070` match retail. The handler reuses the canonical manager
getter and typed IGMenu pointer/member interface. Sound operations, conditions,
menu cases, evaluation counts and source order remain unchanged. No hints,
compiler flags, register constraints or output modifications are used.

```text
OK  _ZN5Menus5Infos6NotifyEPK10MenuWidgeti  0x002ea7f5  304 bytes
OK SECTION .infos_notify  0x002ea7f4  304 bytes
OK SECTION .infos_notify_table  0x0041a070  20 bytes
```

Function SHA-256:
`e0b9dd720d8c199b90ae1409ece57497ae08098aee654a56c6f5f027d76b4c73`.
Both physical extents have exact linker assertions. The stale Infos Thumb
import is removed; InfoAchievements and InfoHelp now link the actual compiled
definition and retain their exact bytes. The private closure passes 1,057
comparisons, retaining all 1,054 previous checks.

The initial Infos-only integration changed two independent initializations in
an existing focus method. The final combination with the genuine Shop
declaration preserves that method without editing it. Final integrated
verification exits 0 across 190 profiles: 5,298 function, 5,196 section and
181 region comparisons (10,675 total), with no failures or skips.
