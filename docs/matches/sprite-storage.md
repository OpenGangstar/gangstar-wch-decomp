# Sprite storage

The recovered constructors initialize sprite state and either start with
no data or reference an existing blob. The erase routine frees owned
data and clears the pointer. The trace and image hooks and module-name
lookup reproduce the retail stubs.

```text
OK  _ZN7ASpriteC1Ev  0x003496e5  52 bytes
OK  _ZN7ASpriteC2Ev  0x003496e5  52 bytes
OK  _ZN7ASpriteC1ERKS_  0x00349719  60 bytes
OK  _ZN7ASpriteC2ERKS_  0x00349719  60 bytes
OK  _ZNK7ASprite6_traceEPKc  0x00349755  2 bytes
OK  _ZN7ASprite7_setPtrEPh  0x00349759  4 bytes
OK  _ZN7ASpriteC2EPh  0x0034975d  64 bytes
OK  _ZN7ASpriteC1EPh  0x0034975d  64 bytes
OK  _ZN7ASprite12GetModuleIdxEPKc  0x003497ad  6 bytes
OK  _ZN7ASprite9MakeImageEij  0x003497b5  2 bytes
OK  _ZN7ASprite9_erasePtrEv  0x00349879  32 bytes
```
