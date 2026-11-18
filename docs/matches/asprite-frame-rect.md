# ASprite::GetFrameRect

The canonical ASpriteData::Frame and __rect records reproduce the original
rectangle lookup. GetFrame supplies the original frame pointer; its signed
16-bit field at offset 22 selects the first rectangle. The rectangle index
is added before ordinary typed indexing of the relative rectangle table.
No existing function bodies, layouts or compiler flags change.

The new nonvirtual declaration preserves ASprite storage and vtable layout.
The real compiled GetFrame definition supplies the exact native Thumb call;
no absolute binding substitutes for either function.

Verification against the retail library:

```text
OK  _ZNK7ASprite12GetFrameRectEii  0x00349825  34 bytes
OK SECTION .asprite_get_frame_rect  0x00349824  36 bytes
```

The section check includes its original two padding bytes. The independent
private header gate passed all 28 affected profiles: 802 functions and 665
sections/regions, including Cash and AnimObject. Coordinator integration then
passed `python tools/build.py --all`: exit 0, 183 profiles and 10,276 successful
function, section and region comparisons. All previous matches are retained.

This adds one matched function and 34 bytes. ASprite remains incomplete and
earns no Fully Linked completion credit. Five historical near-match forms
remain rejected; canonical record reuse matched on its first new attempt.
