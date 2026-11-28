# RenderFX::UpdateCursor exact match

`RenderFX::UpdateCursor(RenderFX::Cursor&, int)` matches all 2012 retail bytes
at Thumb address `0x003ef511`, including relocations. The function is appended
to `menufx.cpp`; the other sections of the file are unchanged.

## Source form

The function moves a controller cursor over the Flash movie, hit-tests the
character under it, and sends the pressed, released, moved and click events.
The retail bytes depend on register-allocator and layout details, so the
source carries several no-code hints, each commented:

- **Spill-slot order.** The low spill slots come from the gcse PRE hash table
  size `S = (n/4)|1`, where `n` is the cse1 instruction count. Retail needs
  `S = 197` (`n` 784..791). The candidate is at `n = 791`. Neutral instruction
  cuts got it there: identity pointers through `__builtin_frob_return_addr`,
  `unsigned long` spellings that stop tree PRE from sharing a conversion, and
  `void*` locals. The parameter is declared as the field view
  `CursorMovieFields* const fields`, with a local `self` macro (undefined
  after the function), which removes the `fields = self` copy.
- **Point zero.** `point` is initialised from a zero (`pz`) that only combine
  can see is zero. It is computed from `&input << 30`, which is 0 because the
  frame object is aligned. The events therefore keep their own block-local
  0.0 constants, as in retail, while point's zero is spilled across calls.
- **Reload rotation.** Reload rotates scratch registers in instruction order.
  Selector tests whose identical arms crossjump away, such as
  `previousFocus.get() == target.get()` on values already spilled, add the
  rotation steps that retail's register choices imply. This applies at the
  event 6 head, the click block and around event 7.
- **Block layout.** Dead tests built from struct-copied constants and
  `__builtin_prefetch` adjust branch-prediction heuristics. No code remains
  for any of them.
- **PHI-copy store order.** An unused enum between the `pressed`/`released`
  and `moved` declarations shifts `moved`'s DECL_UID. This orders the
  out-of-SSA copy stores at 0x1b6, 0x3a0 and 0x464 as in retail. The
  enumerator count must be re-swept after any declaration change.

## Linking

The unit places `.text._ZN8RenderFX12UpdateCursorERNS_6CursorEi` at
`0x003ef510`. It also places the `"released"` and `"pressed"` animation names
at their retail addresses `0x0044de88` and `0x0044de9c`, next to the existing
`"clicked"` string. `__stack_chk_fail` is provided at its PLT address, and
`gameswf::root::notify_mouse_state` is bound as an external Thumb callee.
