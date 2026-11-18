# Vehicle constructor

The complete and base constructor aliases at 0x0030a955 reproduce the original
1,256-byte Thumb function. These are two catalogue entries (2,512 catalogue
bytes) sharing one 1,256-byte machine-code range. Both linked symbols are
executable STT_FUNC definitions, not absolute-address imports.

The constructor initializes the observed fields, calls Application::GetInstance(),
allocates four vector3df objects, and clears the four wheel-trail pointers.
Unknown gaps remain uninitialized. Offset-based member names describe recovered
storage rather than claimed original names.

The authentic secondary IMapTrackable base begins at offset 52 and contains the
pure getMarkerType interface. Its emitted 16-byte ABI-table section also compares exactly.
Vehicle occupies 1,012 bytes. Five genuine virtual overrides retain their native
slots. Four wheel-position vectors at offsets 512, 524, 536 and 548 are separate
members: an array would introduce a construction loop absent from retail code.
Existing Vehicle and NPC bodies only rename constant-index accesses to those
four members; their offsets and complete machine code remain exact. Scalar
wheel-height and light-node arrays retain ordinary value initialization.

No Vehicle destructor reconstruction is included. Parked destructor candidates
and the private PlayerTest migration receive no matching credit. No branch
hints, inline assembly, register constraints, barriers or compiler-output edits
are introduced.

Validation used the normal matching toolchain and integrated sources:

```sh
python tools/build.py --all
```

The command exited 0. All 9,722 function, section and region comparisons passed,
including existing Vehicle, NPC, Character and PhysicAttributes matches.
Exact constructor output:

```text
OK  _ZN7VehicleC1Ei  0x0030a955  1256 bytes
OK  _ZN7VehicleC2Ei  0x0030a955  1256 bytes
```

```text
OK SECTION .ctor_table_8  0x004ab050  16 bytes
```
