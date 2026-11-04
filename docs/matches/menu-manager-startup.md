# MenuManager startup

The initializer reuses the SDK string, half-vector and AI transition-list
startup from SaveGame. It then clears the local texture vector, registers
its destructor callback, and initializes the two cheat activation rectangles.
The texture callback uses the retail weak STL vector-base destructor.

The initial link failed the texture storage extent assertion because the
input section was named `.bss.s_textures`. After correcting the selector,
the first successful link matched the four functions.

```text
OK  __tcf_8  0x002e4cc5  48 bytes
OK  _Z41__static_initialization_and_destruction_0ii  0x002e4aa9  412 bytes
OK  _GLOBAL__I__Z16SwfTextureLoaderPKcii  0x002e4c45  20 bytes
OK  __tcf_9  0x002e3fe9  36 bytes
```
