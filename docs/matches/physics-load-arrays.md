# Physics navigation array loader

PhysicAttributes::LoadArrays(char*) is a static void function at 0x00319ed5.
Its complete 1,336-byte executable definition matches retail at the native
address. No absolute-address replacement or compiler-output editing is used.

The loader reconstructs the binary navigation file: region/index counts,
eight neighbor rows per region, wrong-way flags, overlap pairs, eight material
IDs, two cliff maps and two material-cost rows. It preserves original fread
argument sizes/counts and the original behavior of logging a failed fopen
before continuing to read. No additional failure path is invented.

Native symbol sizes and four-byte fread calls establish int-width material
IDs, including the corrected SIDEWALK declaration. Two-byte reads and
allocations establish unsigned-short cliff-map elements. Existing Taxi,
Ambulance and Delivery material readers remain byte exact without body changes.

The existing licensed UnsignedShortArray specialization supplies destruction.
Its recovered default constructor initializes data, allocated and used to zero,
free/sorted flags to true, and the native fork's final word to one. The observed
20-byte elements and genuine eight-byte new[] cookie are preserved. The generic
array view and existing AStar cleanup remain unchanged. A preliminary generic
destructor experiment was discarded after it introduced an unwanted AStar
cleanup dependency.

The unit adds -fstack-protector for the original 255-byte filename buffer and
-fno-merge-constants to preserve its readonly literals. The original mode and
error sections, stack-failure import, allocation/file PLT imports and Thumb
path/debug imports are verified. Shared native sections retain the loader and
literals in every Physics dependency image.

Final integrated validation:

```sh
python tools/build.py --all
```

Exit 0; all 9,750 function, section and region comparisons passed. This includes
all existing Physics, Character, NPC, PlayerTest and material-reader functions.
The existing Radio inline-destructor warning remains; compilation and linking
succeed. The 84 unit tests and repository/progress checks run before the commit.
No existing matched C++ function body changes or branch hints are introduced.

```text
OK  _ZN16PhysicAttributes10LoadArraysEPc  0x00319ed5  1336 bytes
OK SECTION .physics_load_arrays  0x00319ed4  1336 bytes
OK SECTION .load_arrays_mode  0x004014f0  4 bytes
OK SECTION .load_arrays_error  0x00420a68  60 bytes
```
