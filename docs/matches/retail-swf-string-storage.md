# Retail gameswf string storage

This change replaces the shared `tu_string` interface's opaque byte array and
separate heap pointer with the natural overlapping union from historical
public-domain gameswf source. It is a representation prerequisite for further
game-code reconstruction, not a newly matched function.

## Source and ABI evidence

The source reference is `tu-testbed/base/container.h` at
[`b29f4cc842244eb8e1daf3b7c4d8ce2693c04853`](https://github.com/weihuoya/gameswf/blob/b29f4cc842244eb8e1daf3b7c4d8ce2693c04853/tu-testbed/base/container.h).
Its SHA-256 is
`e1ea989a6524b9749111fd2b3d1cbc42d7c2f45dc9799cac800439e423f944d4`.
The original public-domain notice is retained in the shared header.

On the target 32-bit ARM ABI, the local representation contains a character
count tag at offset 0 and a 15-byte character buffer at offset 1. The heap
representation overlaps it: marker at 0, integer size at 4, integer capacity at
8, and character pointer at 12. The complete class remains 16 bytes with
four-byte alignment. Compile-time assertions check these offsets on the actual
class. Stored size includes the terminator; inline capacity is 14 characters.

Only existing field reads change to their corresponding union members. Public
interfaces, constructor attributes, destructor operations, accessor branching,
compiler flags and linker configuration are preserved. No default constructor,
assignment operation, vendor implementation or game function is added.

The historical source is evidence for these fields, not proof of the whole
Gameloft fork. In particular, its C-string constructor has a null check absent
from the measured retail constructor. The unexplained extra local object in
`RenderFX::Load` remains unresolved; this storage correction does not justify
inventing that object's identity or lifetime.

## Preservation verification

Before integration, a private baseline and the representation-only candidate
were rebuilt against the same retail library and toolchain. The affected
closure passed 634 function comparisons, 407 section comparisons and five GOT
region comparisons. All 14 emitted objects retained identical allocated code
and data sections and raw relocation payloads. The renderer object's compiler
anonymous-namespace checksum changed in `.strtab`; whole-file object identity
is not claimed.

The coordinator also runs the complete native gate after integration:

```sh
python tools/build.py --all
python -m unittest discover -s tests
python tools/check_repository.py
python tools/progress.py --check
```

No assembly files or catalogue statuses change. Matched and Fully Linked
progress must remain unchanged.

The integrated gate exited 0 across 190 profiles: 5,290 function, 5,185 section
and 181 region comparisons, totaling 10,656 successful comparisons. For example,
the comparison tool printed:

```text
OK  _Z19CanHandleMouseEventPN7gameswf9characterE  0x003eca0d  92 bytes
OK  _ZN7Widgets8Tutorial18UpdateLocalizationEv  0x002ef6f5  464 bytes
OK  _ZN7Widgets7Volumes18UpdateLocalizationEv  0x002ef415  736 bytes
OK  _ZN7Widgets7Confirm18UpdateLocalizationEv  0x002edec1  252 bytes
```

Independent native-address executable audits found no missing proofs among all
4,246 credited entries or the 1,647 entries belonging to complete original-source
groups. Progress remains 339,992 / 575,264 matched bytes (59.10%) and 110,400 fully
linked bytes (19.19%). The tooling suite reports `Ran 89 tests` and `OK`;
repository and generated-progress checks pass. No native Windows port source or
application build flow changes.
