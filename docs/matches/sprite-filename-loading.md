# Sprite filename loading

The filename constructor loads the sprite through the resource stream
and looks for a texture with the same base name. It tries BMP, PNG,
TGA, then PSD. The retail code assumes the generated texture name fits
its 80-byte local buffer. The verification profile enables the compiler
stack protector and compares the filename delimiter.

```text
OK  _ZN7ASpriteC1EPKc  0x00349ac1  452 bytes
OK  _ZN7ASpriteC2EPKc  0x00349ac1  452 bytes
OK SECTION .asprite_extension  0x0044de24  4 bytes
```
