# WantedLevelManager update thunk

The generated secondary-base ARM thunk matches the complete native 20-byte
function. A verification wrapper includes the original production translation
unit once, then the faithful saved update body. That parent remains unmatched:
360 compiled bytes versus 376 native bytes. Its assembly and pending status
remain; only the thunk receives matching credit.

Recovered fields expose the four observed doubles at 40/48/56/64, integer at
72 and flags at 77/78. The class retains its 80-byte size with the true eight-byte
alignment. Its existing static instance at 0x004b6a98 satisfies that alignment.
WantedMeter grants access to its existing timer at 80. No event class extraction,
original function-body changes or duplicate classes are involved.

Both actual compiled definitions occupy retail addresses without ABS overrides.
The thunk's normal local-section relocation requires the real unmatched parent
to remain in this verification image; no imported stub substitutes for it.
All previous 18 functions, 22 sections/regions, complete 48-byte vtable allocation
and GOT remain exact. Layout checks confirm field offsets and alignment.

Exact output:

```text
OK  _ZThn4_N18WantedLevelManager6updateEd  0x00342fb4  20 bytes
```

All 41 affected profiles pass: 1,975 functions and 1,739 regions. The integrated
coordinator `python tools/build.py --all` exits zero across 187 profiles and
10,400 successful comparisons. The parent remains uncredited and the original
source unit remains incomplete; Fully Linked progress is unchanged.
