# PlayerTest::setAnim

The complete 62-byte function at Thumb `0x003018d1` matches the retail bytes.
The linked 64-byte physical section also matches, including its original
two-byte NOP padding before the next function at `0x00301911`.

The implementation reuses the actual Character secondary base and virtual
setAnimation interface. On success with a non-null scene node, it snapshots
the real vector returned by getPosition, then updates the existing X/Y cached
fields. The genuine vector copy constructor supplies the value boundary;
unused Z generates no write or additional helper. No flags, barriers, register
bindings, hints or compiler-output edits are used. Existing matched bodies and
shared headers are unchanged.

Earlier reference-based forms retained four terminal load/store-order
mismatches. The fifth ordinary source form, a real vector value copy, resolves
them. Native and compiled function SHA256 are both
`0e50d2448d90d307aec64981e5bb4349de63db5db3786feaac5b7afb0168315c`.

Independent coordinator verification ran `python tools/build.py --all` with the
original per-profile toolchains: 190 profiles, 5,420 function comparisons,
5,324 section comparisons and 181 region comparisons, totaling 10,925 passing
checks. Exit 0, no mismatches or skips; all frozen inputs remained unchanged.

```text
OK  _ZN10PlayerTest7setAnimEibbbf  0x003018d1  62 bytes
OK SECTION .player_set_anim  0x003018d0  64 bytes
```

Only the independently verified function's assembly marker is removed.
Its 62 catalogue bytes receive matching credit; the two alignment bytes do not
increase the function-byte numerator. PlayerTest still has pending functions,
so this does not complete a fully linked unit.
