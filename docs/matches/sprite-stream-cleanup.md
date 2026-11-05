# Sprite stream loading and cleanup

The stream constructor reads the complete sprite data into an owned
buffer and restores the caller's stream position. The destructor
releases the texture through the retail driver's removeTexture slot,
then erases the owned sprite data. The verification profile also
compares the generated vtable.

```text
OK  _ZN7ASpriteC1EP11IFileStream  0x00349899  152 bytes
OK  _ZN7ASpriteC2EP11IFileStream  0x00349899  152 bytes
OK  _ZN7ASpriteD0Ev  0x00349931  72 bytes
OK  _ZN7ASpriteD1Ev  0x00349979  64 bytes
OK  _ZN7ASpriteD2Ev  0x00349979  64 bytes
OK SECTION .asprite_vtable  0x004ad2b8  16 bytes
```
