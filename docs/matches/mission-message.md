# Mission::message exact match

```text
OK  _ZN7Mission7messageEi  0x00336345  120 bytes
OK SECTION .mission_message  0x00336344  120 bytes
```

Shows a mission message: for a new message ID it sets the text and, unless
the ID is -1, plays sound 224 with the sound manager's flag at offset 140
raised for the call. It then sets both message timers to 3000 (or 0 for -1)
and forwards the current message and timer to the HUD `Message` widget with
text category 9.

Earlier attempts (six forms, 124 bytes) wrote the timer inside each branch,
which duplicated the timer tail. Writing it once after the same-ID guard,

```cpp
unknown12 = unknown8 = (id != -1) ? 3000 : 0;
```

gives retail's shared tail and the `[8]` then `[12]` store order. No header,
hint, inline assembly or register constraint is used; `Mission.h`,
`SoundManager.h` and `Message.h` are unchanged.

Full gate: `python -B tools/build.py --all` exited 0 with 5,501 function,
5,577 section and 181 region comparisons and no mismatch or skip.
