# Memory statistics hook

The retail `utility.cpp` function `dump_memory_stats(char const*, int, char const*)`
at Thumb address `0x0039c751` consists only of `bx lr`. Its C++ definition is an
empty function with the original signature; it performs no memory reporting.
No existing decompiled function or compiler flag was changed.

The `utility` verification profile uses the existing NDK 1.6 GCC 4.2.1 ARM/Thumb
settings and links the compiler-generated definition at the original address.
There are no data sections or external calls in this source unit.

`python tools/build.py utility` printed exactly:

```text
BUILD utility
OK  _Z17dump_memory_statsPKciS0_  0x0039c751  2 bytes
```

Only after this full-function comparison was the corresponding assembly file
removed and progress regenerated. This contributes one function and two code
bytes, completing the only game function attributed to `utility.cpp`.
