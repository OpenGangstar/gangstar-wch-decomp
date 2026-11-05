# Sprite animation lookups

The frame size accessors subtract the stored horizontal and vertical
bounds. The animation and module lookups index the sprite's packed
tables. The bounds fields are ordered left, right, top, bottom.

```text
OK  _ZN7ASprite14GetFrameHeightEi  0x002d4535  28 bytes
OK  _ZN7ASprite13GetFrameWidthEi  0x002d4551  28 bytes
OK  _ZNK7ASprite9GetAFrameEi  0x0034979d  14 bytes
OK  _ZNK7ASprite19GetModuleFromAFrameEii  0x00349d61  32 bytes
```
