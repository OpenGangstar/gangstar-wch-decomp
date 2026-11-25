# MenuState::OnEvent exact match

`MenuState::OnEvent(RenderFX::Event&)` matches all 232 retail bytes at Thumb
address `0x002e8551`, including relocations.

```text
OK  _ZN9MenuState7OnEventERN8RenderFX5EventE  0x002e8551  232 bytes
```

## Source form

`OnEvent` does the following:

1. It walks the state's widgets and forwards the event to each widget that
   owns the event's character.
2. When a widget consumes the event, it consumes the cursor and returns.
3. After the loop, a button event whose character name starts with `btn` is
   marked consumed, and the cursor is consumed.

Details that the retail bytes require:

- **Consumed exit inside the loop.** It calls `consumeCursor()` and returns
  directly. The post-loop consume block therefore stays dominated by the
  post-loop test, which gets the call heuristic and retail's fall-through.
  Post-reload cross-jumping merges the two calls.
- **Tail order.** The tail tests the unconsumed, unfocused return first. Then
  it handles the already-consumed case, and only then stores
  `event.consumed`. The store then starts its own cse1 block, so the offset
  36 is rematerialised as retail does.
- **Character path call.** `GetCharacterPath` is declared
  `__attribute__((long_call))`, so it is called through the GOT as in
  retail. This is a calling-convention attribute, which the file already
  uses for `check_proxy`, not a branch hint.

## Strings and data

Retail shares the `"btn"` prefix string at `0x00419f00` with menufx.cpp.
MenuState references menufx's hidden `widgetButtonPrefix`, declared at the
top of the file.
- A file-local copy cannot share the address, because the menustate link also
  checks `CanHandleMouseEvent`, which uses menufx's copy.
- Declaring the extern lower in the file alters `ServiceCarRental::Notify`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py ai-startup-menustate` passes every function and
section check, including `ServiceCarRental::Notify` and
`CanHandleMouseEvent`. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,607 function, 5,698 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,606, 5,697 and 181.
