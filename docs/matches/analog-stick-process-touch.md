# AnalogStick::processTouch exact match

`AnalogStick::processTouch(long)` matches all 1016 retail bytes at Thumb
address `0x003268e1`, including relocations. Its non-virtual thunk at
`0x003268cc` (20 bytes) also matches. The diagnostic `printf` string is placed
at `0x004229ec`. The other sections of `AnalogStick.cpp` are unchanged.

## Source form

The function turns a touch drag into stick displacement and raises a
left/right, up/down or two-axis stick event, depending on the stick mode. The
source is goto-structured and already in the shape the optimiser would
otherwise produce by threading, so DOM and VRP have nothing left to move.
Details that the retail bytes require, each commented in the source:

- **Explicit Mode0 path.** Mode0 jumps to a block after the event code that
  sets `dy = 0` and the released flags. That keeps the mode-load pseudo alive,
  so CSE keeps it for the later compares (`mov r9, r2`).
- **Magnitude test last.** The horizontal magnitude test is the last code in
  the function, after every other use of `dx`. The `abs` copy then outlives
  `dx`, so CSE's `make_regs_eqv` keeps the copy as the canonical register and
  combine emits retail's `subs r3, r5, #0` compare.
- **Both-axes split.** The arm is entered by `goto` into an `if (0)` block.
  It holds an address-taken label statement, which keeps it in place.
- **Frequency hints.** Aggregate-copy dead tests (DOM-folded) give retail's
  branch frequencies. An aggregate `dy == 0` test stops VRP1 substituting zero
  into the horizontal join.
- **End-block order.** An unused user label at the start of the vertical arm
  keeps the negation block at the arm's own frequency, so the negative-sign
  block is laid out first, as in retail.
