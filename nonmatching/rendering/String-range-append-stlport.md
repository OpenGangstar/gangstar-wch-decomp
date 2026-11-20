# STLport range append: bounded source reuse

This is an unapplied candidate for `_ZNSs9_M_appendEPKcS0_`, the 372-byte
Thumb function at `0x002dcd29` in `libsanangeles.so`. It remains pending in
the function catalogue and its assembly marker remains present. No bytes
are credited and no production source or matching profile is changed.

The candidate reuses the licensed Android STLport range-append algorithm,
short-string representation, reference-returning maximum, allocator proxy,
and random-access uninitialized-copy loop. The public source commit is
`e64e7c849b0b659d3e198e4efaed563601e554be`; this is a reference revision,
not a claim about the exact retail STLport revision. Source URLs and hashes
are recorded in the adjacent JSON. The patch retains the source notices
and documents the altered implementation.

The native string has a 16-byte union followed by its finish pointer and
allocator proxy at offsets 16 and 20. Native GOT references identify the
weak length-error helper and `allocator<char>::allocate(unsigned int,
unsigned int&)`. The private allocator interface adds that observed overload
without replacing the existing overload used by other code.

Three source forms were compiled using the owning `gs3d-stuff` profile and
the original NDK 1.6 r1 GCC 4.2.1 compiler and assembler:

1. The adapted original range-append algorithm.
2. The original `char_traits<char>::copy` zero-length guard restored.
3. The original trivial character assignment/destruction traits restored.

Every primary function is 372 bytes with SHA-256
`f7e4752f99d37f699eabe352d618dae80b8106fb91954b36201246bcd3a246e2`.
Their primary GOT references also agree. Each compile-only diagnostic exits
3 and prints `COMPILE-ONLY: no native byte comparison or old-match proof.`
The repository's three-identical-output stopping rule applies.

Equal size does not establish a match. The generated caller retains calls
to `_M_deallocate_block` and `_M_copy`, whereas the retail function contains
the corresponding operations inline. The guarded traits implementation
also emits a separate `char_traits<char>::copy`. None of those three helper
definitions is present under that symbol in the retail library.

A diagnostic image placed the caller at its native address and the extra
helpers at diagnostic addresses `0x00500100`, `0x00500200`, and `0x00500300`.
No compiled definition was replaced with an absolute retail import. The
caller differs at 275 byte positions; its linked SHA-256 is
`0c5b1d34d8eaa95feef4b725e357537a418126252cb5a11201c9ef2ac75b7322`.
The exact target comparison output and differing offsets are in the JSON.
The extra symbols change GOT ordering, causing existing function mismatches.
The build exits 2 with `BUILD FAILED: comparison extends beyond a retail
section: .got`. Consequently, this is not a successful existing-match
closure. Earlier diagnostic setup attempts also failed before comparison:
one failed to insert the linker placements and another put diagnostic helpers
outside Thumb call range. Neither attempt is counted as a source iteration.

The adjacent patch retains the third source form. Apply it only in a private
checkout. The adjacent probe uses the real build implementation but stops
after primary assembly; it does not link, compare native bytes, or accept a
match. An isolated current-checkout patch-application replay reproduced the
recorded 372-byte primary hash using this public probe, with intentional
exit 3. Both patched source files also equal the retained private source.

Further work requires new evidence about the original source or inlining
context. Repeating operand, hint, or compiler-flag searches without that
evidence is not justified. Before production integration, remove the extra
helper calls through supported C++ reconstruction, verify the entire native
function, preserve the existing public append match in every owning profile,
and run all affected header/profile checks and the complete native gate.
