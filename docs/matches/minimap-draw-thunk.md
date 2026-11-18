# MiniMap draw thunk

The compiler-generated secondary-base thunk now matches the original 20-byte
ARM function. It comes from the faithful saved MiniMap::draw2d reconstruction,
retained explicitly under nonmatching/hud/. The parent still differs: 1,356
compiled bytes versus 1,380 retail bytes. Its assembly and pending status remain;
only the exact thunk receives matching credit.

The genuine thunk's literal has a normal R_ARM_REL32 relocation against its
local parent section. Both compiled sections therefore remain at their retail
addresses in a separate verification image. The current native MiniMap object
is a real dependency. No surrogate thunk, default parent, absolute definition,
compiler-output modification or guessed return is used. An old private fixture
had accidentally bound the thunk as ABS; the new image proves every compiled
function remains an executable definition, with no ABS overrides.

Recovered views expose existing Map rotation, pixel offsets and rectangle,
MiniMap's integer at 112 and its genuine coordinate helper, plus MiniMap friend
access to Item and TargetMarker. Storage sizes and offsets remain unchanged.
The existing Map::Map C1/C2 body is explicitly changed: six scalar zero
initializers become two pixel zeros and clip(0,0,0,0). Both original 52-byte
constructor aliases and all existing Map comparisons remain exact. Rect.h,
existing SDK constructors and optimization flags are unchanged.

Exact output:

```text
OK  _ZThn4_NK7MiniMap6draw2dEv  0x0032a0e0  20 bytes
OK SECTION .minimap_draw_thunk  0x0032a0e0  20 bytes
OK  _ZN3MapC1Ev  0x00328c15  52 bytes
OK  _ZN3MapC2Ev  0x00328c15  52 bytes
```

The private header closure passed 32 profiles, 1,303 function and 1,325 region
comparisons. Combined MiniMap checks retain all 15 old functions, all 17 old
sections/regions, its complete 128-byte vtable allocation and global GOT.
Coordinator `python tools/build.py --all` exits zero: 184 profiles and 10,311
successful comparisons. MiniMap remains incomplete and gains no Fully Linked
completion credit. This verification image is not a replacement game library.
