# Animation bounds

AnimObject returns the current sprite frame bounds, or an empty rectangle
when it has no sprite. ASprite translates animation frames to sprite
frames and returns a reference to the stored bounds. The native profiles
verify these functions and the empty rectangle.

```text
OK  _ZN10AnimObject22GetCurrentBoundingRectEv  0x003494b5  88 bytes
OK SECTION .anim_empty_bounds  0x00435a60  16 bytes
OK  _ZNK7ASprite20GetFrameBoundingRectEi  0x00349805  14 bytes
OK  _ZNK7ASprite18GetFrameFromAFrameEii  0x00349a49  34 bytes
OK  _ZNK7ASprite24GetAnimFrameBoundingRectEii  0x00349a6d  18 bytes
```
