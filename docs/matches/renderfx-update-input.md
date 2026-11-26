# RenderFX::UpdateInput exact match

`RenderFX::UpdateInput(int, int)` matches all 852 retail bytes at Thumb
address `0x003efced`, including relocations. Its `clicked` animation string is
placed at `0x0044de94` and compared.

## Source form

The function moves the menu focus to the nearest selectable character in the
pressed direction. Details that the retail bytes require, each commented in
the source:

- **Direction candidates.** Left and right are `{distance, character}`
  structs filled from a probe struct; the up and down candidates stay plain
  variables. That gives retail's compare operand order and stack slots.
- **Early return.** `__builtin_expect(!keys, 0)` fixes the stack-guard block
  position and the high registers.
- **Index register.** The cold early-return path releases the current
  character through two identical `release()` calls selected by a test on
  `index`. The calls are merged after register allocation and the test is
  deleted, but its uses give `index` retail's register.
- **Store order.** The event's character is stored after `unknown24`, which
  gives the scheduler retail's store order.
