# Irrlicht allocation wrappers and startup

All thirteen catalogued game functions in Irrlicht.cpp match, adding 332 code
bytes. The allocation and deletion overloads forward their arguments to the
retail IrrAlloc and IrrFree imports. The C wrappers supply the default hint
or return zero after freeing. Only the default MemHint value is recovered here.

The startup initializes the local empty string and registers its cleanup. It
then constructs the imported IdentityMatrix using the existing matrix4
constructor. The compiler generates the 64-byte clear, four diagonal stores
and identity flag writes. The linker retains the local 32-byte string storage,
the shared empty text and native Thumb bindings for the allocator calls.

The targeted build passes on the first source form. The full native build
passes 4,731 comparisons across 164 units. The audit covers every previous
1,357 match and all thirteen additions by symbol, address and size. All 324
prior primary artifacts retain their SHA-256 hashes and sizes. All new
function metadata agrees with retail. The tooling suite passes 83 tests.

Game progress is 1,370 / 4,661 functions and 99,268 / 575,264 bytes (17.26%).
Exact comparison output for the new unit follows.


```text
BUILD irrlicht-allocator
OK  __tcf_0  0x001e02cd  48 bytes
OK  _ZdaPvN3irr7MemHintEiPKci  0x001e0369  12 bytes
OK  _ZdlPvN3irr7MemHintEiPKci  0x001e0375  12 bytes
OK  irr_free  0x001e0381  14 bytes
OK  _ZdaPvN3irr7MemHintE  0x001e0391  12 bytes
OK  _ZdlPvN3irr7MemHintE  0x001e039d  12 bytes
OK  _ZnajN3irr7MemHintEiPKci  0x001e03a9  16 bytes
OK  _ZnwjN3irr7MemHintEiPKci  0x001e03b9  16 bytes
OK  irr_malloc  0x001e03c9  14 bytes
OK  _ZnajN3irr7MemHintE  0x001e03d9  12 bytes
OK  _ZnwjN3irr7MemHintE  0x001e03e5  12 bytes
OK  _Z41__static_initialization_and_destruction_0ii  0x001e03f1  132 bytes
OK  _GLOBAL__I__ZnwjN3irr7MemHintE  0x001e0475  20 bytes
OK SECTION .allocator_function_0  0x001e02cc  48 bytes
OK SECTION .allocator_function_1  0x001e0368  12 bytes
OK SECTION .allocator_function_2  0x001e0374  12 bytes
OK SECTION .allocator_function_3  0x001e0380  16 bytes
OK SECTION .allocator_function_4  0x001e0390  12 bytes
OK SECTION .allocator_function_5  0x001e039c  12 bytes
OK SECTION .allocator_function_6  0x001e03a8  16 bytes
OK SECTION .allocator_function_7  0x001e03b8  16 bytes
OK SECTION .allocator_function_8  0x001e03c8  16 bytes
OK SECTION .allocator_function_9  0x001e03d8  12 bytes
OK SECTION .allocator_function_10  0x001e03e4  12 bytes
OK SECTION .allocator_function_11  0x001e03f0  132 bytes
OK SECTION .allocator_function_12  0x001e0474  20 bytes
OK SECTION .shared_startup_empty_text  0x0044d91c  4 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
```
