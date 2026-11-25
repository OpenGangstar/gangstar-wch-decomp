# Application::OnEvent exact match

`Application::OnEvent(irr::SEvent const&)` matches all 596 retail bytes at Thumb
address `0x002d5eb9`, including relocations. Its 32-byte switch table at
`0x00413dd8` also matches.

```text
OK  _ZN11Application7OnEventERKN3irr6SEventE  0x002d5eb9  596 bytes
```

## Source form

The body extends the unapplied reconstruction kept in
`nonmatching/app/Application-OnEvent.patch`:

1. Every registered receiver gets the event, and their results are ORed
   together.
2. A key event toggles video option 128 on a pressed `b` and raises
   `EvKeyboard`. It then returns `true`.
3. A mouse event raises `EvMouseMove`, `EvMouseWheel` or `EvMouseButton`
   (buttons 0, 1 and 2, with a pressed flag), then returns `true`.
4. Anything else returns the receivers' result.

That patch differed in 26 bytes at `+0x1f6`: the left-button block's loads were
scheduled differently. Putting the `MouseMoved` and `MouseWheel` cases ahead of
the button cases in the switch reproduces the retail block order. The stack
temporaries are unchanged.

No branch hint, inline assembly, register constraint or output edit is used.

## Interface additions

These come from the patch:

- **Event payloads** in `Application.cpp`: constructors and fields for
  `EvMouseMove`, `EvKeyboard`, `EvMouseWheel` and `EvMouseButton`.
- **Event kinds and keyboard payload**: these are file-local in
  `Application.cpp`. Two anonymous-namespace enumerations hold the values
  OnEvent uses beyond the shared mouse prefix: `KeyInputEvent = 2`, and the
  right and middle buttons and `MouseWheel = 7`. A `KeyInputEventView` holds
  `{ character, key, pressed, shift, control }`, which shares storage with
  the mouse payload in retail.

  The patch had added them to the shared `TouchScreenMouseEvent.h` instead.
  That changed already-matched code in other units:
  - The enumeration change alone changed four bytes of
    `SceneNodeManager::crc`.
  - The union together with the `VideoDriver.h` slot name changed
    `Menus::ServiceCarRental::Notify` by 49 bytes.

  The shared header is therefore unchanged.
- **`VideoDriver.h`**: vtable slot 116 is `bool getOption(unsigned int) const`.

## Linking

`config/linker/ApplicationOnEventSections.ld` places the function, its switch
table and an unreferenced compiler initializer. The initializer goes to
verification-only storage at `0x00610000` and is not credited. Both
`application-helpers` and `state-hooks-gsfade` include the script, because both
link the application object.

## Verification

The unit builds pass every function and section check. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,576 function, 5,660 section
and 181 region comparisons and no mismatch or skip; the previous baseline was
5,574, 5,657 and 181.
