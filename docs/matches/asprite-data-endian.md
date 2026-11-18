# Sprite record endian conversions

`ASpriteData::AFrame::Swap()` and `ASpriteData::FModule::Swap()` use the same
inline endian conversion template. It detects the host byte order using the
first byte of a local integer, and reverses each field with the original XOR
swap loop only on a big-endian host. The ordinary C++ implementation preserves
the original field visits, pointer comparisons and byte operations. It uses no
assembly, register constraints, barriers, volatile accesses, likelihood hints,
or compiler-output edits.

The AFrame record visits four 16-bit fields at offsets 0, 2, 4 and 6. Their
semantic names remain unknown. The FModule layout reuses the existing ASprite
reader evidence: unsigned module index at 0, signed x/y at 2/4, and two byte
fields at 6/7. The byte fields are not swapped. FModule occupies eight bytes. AFrame has an eight-byte swapped prefix and an
untouched flags byte at offset 8 plus alignment padding; the whole-data loop
establishes its ten-byte stride. Adding nested declarations does not change ASpriteData's storage.

The first AFrame form had the correct algorithm but the first compound XOR
assignment evaluated the two byte loads in the opposite order. Writing its
original explicit `*first = *last ^ *first` expression produced all 196 retail
bytes on the second source form. FModule then matched all 150 bytes on its
first form using the same helper unchanged.

The existing `asprite-data` profile and its compiler flags are unchanged. Its
linker now retains the real generated definitions at their original ARM/Thumb
addresses. Existing constructor bodies are unchanged. No shared header or native
Windows port source was modified.

`python tools/build.py asprite-data` printed exactly:

```text
BUILD asprite-data
OK  _ZN11ASpriteDataC1Ev  0x0034a3b5  18 bytes
OK  _ZN11ASpriteDataC2Ev  0x0034a3b5  18 bytes
OK  _ZN11ASpriteData6AFrame4SwapEv  0x0034ad9d  196 bytes
OK  _ZN11ASpriteData7FModule4SwapEv  0x0034ac39  150 bytes
OK SECTION .asprite_data_ctor  0x0034a3b4  20 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
```

Only after coordinator review and native-address byte comparisons were the two
assembly files removed and generated progress updated. This adds two matched
functions and 346 code bytes. Other functions from this original source remain
pending; matching these records does not complete the source unit.

## Reused animation, image and module conversions

The same helper also matched three more independent records on their first
source forms, without changing the helper or any previously accepted body:

- Anim is 12 bytes: two 16-bit fields at 0/2 and two 32-bit fields at 4/8.
  The final word is the relative name offset established by the sprite readers.
- Image is 20 bytes: four 32-bit fields at 0/4/8/12 are swapped; the final word
  at 16 is left unchanged. Both the retail image-loop stride and debug reader
  independently establish the full record extent.
- Module is 10 bytes, consistent with existing ASprite module readers. Its
  16-bit fields at 2/4 are swapped only when kind byte 0 is zero; the width and
  height at 6/8 are always visited. The other byte at 1 is untouched.

Coordinator integration preserved all earlier definitions. The complete current
`python tools/build.py asprite-data` comparison output is:

```text
BUILD asprite-data
OK  _ZN11ASpriteDataC1Ev  0x0034a3b5  18 bytes
OK  _ZN11ASpriteDataC2Ev  0x0034a3b5  18 bytes
OK  _ZN11ASpriteData6AFrame4SwapEv  0x0034ad9d  196 bytes
OK  _ZN11ASpriteData7FModule4SwapEv  0x0034ac39  150 bytes
OK  _ZN11ASpriteData6Module4SwapEv  0x0034a655  210 bytes
OK  _ZN11ASpriteData4Anim4SwapEv  0x0034a3c9  200 bytes
OK  _ZN11ASpriteData5Image4SwapEv  0x0034acd1  204 bytes
OK SECTION .asprite_data_ctor  0x0034a3b4  20 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
```

This second batch adds three functions and 614 bytes; the five record converters
together account for 960 exact code bytes. Frame, whole-data conversion, debug
and rectangle work remain separate queue entries until independently verified.

## Frame and whole-data conversion

Frame's 28-byte record reuses SpriteBounds. Its converter visits the two initial
16-bit words, four bounds words, two 16-bit words at 20/22, and the 32-bit relative
name offset at 24. It matches 450 bytes on the first source form.

The whole-data converter also matches on its first source form: 1,122 bytes.
It preserves the original signed `imageCount > 65534` entry test, converts seven
signed count words and seven unsigned relative offsets, then visits the image,
module, rectangle, frame, frame-module, animation and animation-frame arrays in
native order. Counts and base-relative offsets are reloaded after calls, as in
the original. Existing record methods and the same endian helper are reused.

This loop established AFrame's complete **ten-byte** record stride: the earlier
eight-byte declaration described only its swapped prefix. A trailing flags byte
at offset 8 plus alignment padding are now represented and remain untouched by
AFrame::Swap. The native debug reader independently identifies this as a byte,
rather than the provisional 16-bit tail initially inferred from the stride.
The converter's existing 196-byte body is unchanged and remains exact. The
initial record description above has been corrected accordingly.

The opaque outer 28-byte prefix is now seven signed count fields; relative
words previously called unknown28/unknown36 are now images/rectangles. The
existing constructor's corresponding initializer names changed mechanically,
with its instructions and behavior preserved: both 18-byte aliases and the
complete 20-byte constructor section still compare exactly.

## Rectangle wrapper and combined verification

The 92-byte __rect::isIntersecting wrapper constructs the existing Rct<int>
using its native left/top/right/bottom argument order. Its own 16-byte record
stores left/right/top/bottom. The existing Rct header is unchanged; the genuine
weak const intersection method remains an import. Its emitted validation and
destructor definitions and vtable are linked and compared at their native
addresses. These support definitions receive no new progress credit.

After combining all worker results, `python tools/build.py asprite-data` printed:

```text
BUILD asprite-data
OK  _ZN11ASpriteDataC1Ev  0x0034a3b5  18 bytes
OK  _ZN11ASpriteDataC2Ev  0x0034a3b5  18 bytes
OK  _ZN11ASpriteData6AFrame4SwapEv  0x0034ad9d  196 bytes
OK  _ZN11ASpriteData7FModule4SwapEv  0x0034ac39  150 bytes
OK  _ZN11ASpriteData6Module4SwapEv  0x0034a655  210 bytes
OK  _ZN11ASpriteData4Anim4SwapEv  0x0034a3c9  200 bytes
OK  _ZN11ASpriteData5Image4SwapEv  0x0034acd1  204 bytes
OK  _ZN11ASpriteData5Frame4SwapEv  0x0034a491  450 bytes
OK  _ZN11ASpriteData6__rect14isIntersectingEii  0x0034a231  92 bytes
OK  _ZN3RctIiE9_validateEv  0x00335cc5  96 bytes
OK  _ZN3RctIiED0Ev  0x00335d55  32 bytes
OK  _ZN3RctIiED1Ev  0x00335d75  24 bytes
OK  _ZN11ASpriteData4SwapEv  0x0034ae61  1122 bytes
OK SECTION .asprite_data_ctor  0x0034a3b4  20 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK SECTION .asprite_data_rect_vtable  0x004ace10  16 bytes
```

All eight newly recovered source functions contribute 2,624 exact code bytes.
Debug remains pending, so the original source is still incomplete. Native
Windows port files and all shared headers remain unchanged. The rectangle
worker also freshly verified ASprite, ScriptManager, Mission and TouchScreenBase
Rct callers without changing their sources or the Rct interface.

## Shared declaration for sprite readers

The complete recovered ASpriteData declaration now lives in core/ASpriteData.h,
included by ASpriteData.cpp and ASprite.cpp. Every original nested-record comment
and field is preserved. ASprite is a friend so future verified readers can use
the genuine records rather than inventing a second class with the same name.
The older partial SpriteData reader remains unchanged; no existing method body
was migrated or rewritten. The __rect intersection declaration now explicitly
has the original native weak linkage; its complete 92-byte definition remains
exact. No unverified PixelInfo or Debug body is included by this extraction.

Before and after the move, the coordinator ran:

```text
python tools/build.py asprite-data asprite-startup
```

Both runs exited zero. The full comparison output was identical, including all
49 existing function checks and 35 section/region checks. A byte-for-byte log
comparison printed:

```text
Unchanged comparison output: 49 functions; 35 section/region checks
```

The shared declaration does not add matching credit. Catalogue, matched bytes
and function counts remain unchanged by the move. A single separately owned
Debug replay after extraction still differed in its indexed-load instruction;
that body remains private and uncredited. Native Windows port files and existing
ASprite public header are unchanged.
