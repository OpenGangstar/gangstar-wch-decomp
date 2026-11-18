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
fields at 6/7. The byte fields are not swapped. Both observed records occupy
eight bytes; adding nested declarations does not change ASpriteData's storage.

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
