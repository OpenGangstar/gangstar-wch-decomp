# Cash and RetroEffect draw thunks

Both compiler-generated secondary-base ARM thunks match the original 20-byte
functions. Their faithful parent reconstructions remain explicitly unmatched
under nonmatching/: Cash emits 320 of 324 native bytes; RetroEffect emits 324
of 332. Both parent assembly files and pending statuses remain unchanged.
Only the thunks receive credit; neither original compilation unit is complete.

Cash's separate parent translation unit links the real current Cash object as
a native dependency. The saved parent received only two mechanical field-name
updates to current declarations at the same offsets. RetroEffect's verification
wrapper includes the original production translation unit once, followed by
the unchanged saved parent. Its original source is untouched. Both retain the
real parent executable sections at retail addresses because generated thunk
relocations refer to those local sections. No ABS override, fake parent, hand
thunk, output editing or optimization change is used.

VideoDriver placeholders at slots 18 and 47 become the genuine set2DMaterial
and positional draw2DImage declarations. Slot order/count and all existing
method signatures remain unchanged. Current real Material constructors and
layer destructors remain intact; no imported replacement masks their output.
The refreshed header closure includes nonmatching sources: 50 profiles,
2,582 functions and 2,454 regions pass. Cash requires no header change and emits
only its parent and thunk. RetroEffect likewise emits no new SDK support.

Exact output:

```text
OK  _ZThn4_NK4Cash6draw2dEv  0x00327bd4  20 bytes
OK SECTION .cash_draw_thunk  0x00327bd4  20 bytes
OK  _ZThn4_NK11RetroEffect6draw2dEv  0x0032abd4  20 bytes
```

Every previous native function, full vtable allocation and GOT comparison is
retained. The coordinator's combined full gate exits zero across 186 profiles;
its log also verifies the separately documented AccelerometerWin32 callback.
These images verify matching and are not replacement game libraries.
