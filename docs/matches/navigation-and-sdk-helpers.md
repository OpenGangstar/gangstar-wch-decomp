# Navigation and SDK helpers

This batch reconstructs nine game catalogue entries and 1,008 retail bytes.
All nine are native-address executable STT_FUNC definitions, with complete
function bytes compared against the retail library.

The four HUD SafeDelete specializations reuse the existing core/SafeDelete.h
without changing its implementation. Each uses the correct concrete HUD
complete destructor, deletes the allocation, and clears the pointer reference.
The no-exception overflow and out-of-range shims preserve weak linkage, print
the original message through puts, and call the genuine noreturn libc abort.
Their calls use the original ARM PLT addresses.

The b2CircleDef complete and deleting destructors reuse the partial polymorphic
SDK destructor interface already present in GS3DStuff.cpp. Ordinary C++ emits
the original derived/base vtable stores. These declarations model the destructor
interface; they do not claim a complete allocation layout. The emitted base
shape destructors and both 16-byte ABI tables also compare exactly, without
additional matching credit.

LevelObject::canGoToPoint queries up to 100 broadphase shapes, preserves the
original collision filters and mutable segment fraction, and checks the
interpolated height against transformed node bounds or stored height intervals.
The vector interpolation expression preserves native temporary lifetimes and
repeated GetPosition calls. The new declaration is nonvirtual; no object layout
changes. Existing function bodies remain unchanged.

Shared linker sections retain these new definitions at native addresses in
every dependent verification image. Initial integration links failed when
dependency scripts discarded new definitions or left them as orphan sections;
shared placements and the genuine floating-point comparison import resolve
those failures. No compiler output is edited or unverified fallback credited.

Final integrated validation:

```sh
python tools/build.py --all
```

Exit 0; all 9,746 function, section and region comparisons passed. The existing
Radio inline-destructor warning remains; compilation and linking succeed.
No branch hints, inline assembly, register constraints or barriers are added.
The unit tests, repository check and progress check are run before each commit.

Exact new-function output:

```text
OK  _ZN11b2CircleDefD1Ev  0x002f4441  36 bytes
OK  _ZN11b2CircleDefD0Ev  0x002f462d  44 bytes
OK  _Z10SafeDeleteI11CDrivingHudEvRPT_  0x00323b69  32 bytes
OK  _Z10SafeDeleteI11CWalkingHudEvRPT_  0x00323b89  32 bytes
OK  _Z10SafeDeleteI10CSniperHudEvRPT_  0x00323ba9  32 bytes
OK  _Z10SafeDeleteI10CCameraHudEvRPT_  0x00323bc9  32 bytes
OK  _ZSt26__stl_throw_overflow_errorPKc  0x003238a1  12 bytes
OK  _ZN11LevelObject12canGoToPointERKN3irr4core8vector3dIfEE  0x00318be5  776 bytes
OK  _ZSt24__stl_throw_out_of_rangePKc  0x0034b6f5  12 bytes
```
