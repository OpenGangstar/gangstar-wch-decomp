# ASprite startup

The initializer, wrapper and local string cleanup in ASprite.cpp match all
220 code bytes. The initializer constructs the local empty string, registers
its cleanup, initializes the half-vector and constructs the imported global
transform as an identity matrix. It reuses the existing SDK storage and matrix
constructor. The ASprite declaration covers the static transform member.

The targeted build passes on the first source form. The full build passes
4,739 comparisons across 165 units. The audit covers all 1,370 previous
matches and the three additions by symbol, address and size. The new symbol
metadata matches retail. All 326 previous primary artifacts match their
recorded hashes and sizes. All 83 tooling tests pass.

The catalogue totals 1,373 / 4,661 functions and 99,488 / 575,264 code bytes
(17.29%). Exact comparison output for the new unit follows.


```text
BUILD asprite-startup
OK  __tcf_2  0x00349849  48 bytes
OK  _Z41__static_initialization_and_destruction_0ii  0x0034a185  152 bytes
OK  _GLOBAL__I__ZN7ASprite18s_global_transformE  0x0034a21d  20 bytes
OK SECTION .asprite_function_0  0x00349848  48 bytes
OK SECTION .asprite_function_1  0x0034a184  152 bytes
OK SECTION .asprite_function_2  0x0034a21c  20 bytes
OK SECTION .shared_startup_empty_text  0x0044d91c  4 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
```
