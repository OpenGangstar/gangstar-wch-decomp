# Unmatched octree node constructor

This is an unapplied reconstruction candidate for libsanangeles.so function
`OctTreeAABB::OctTreeAABBNode::OctTreeAABBNode` at Thumb address `0x002df655`.
It is **not matched or credited**. The canonical source, assembly marker,
catalogue and reported progress are unchanged by publishing this packet.

The patch preserves the native 64-byte node layout, eight child pointers at
28 through 59, and depth at 60. It reuses original Irrlicht 1.4.2 vector/AABB
operations, genuine weak helper declarations and native PLT bindings. The
constructor uses natural inline/used weak emission; an explicit weak constructor
attribute produced GCC's invalid `*INTERNAL*` assembler directive. The emitted
C2 alias has no retail catalogue entry and receives no separate credit.

The final source restores the verified first-store-plus-seven-iteration child
zeroing sequence and expands the original intersection expression at its call
site. An earlier ordinary memset experiment did not reproduce native control
flow and was discarded. No compiler output, registers, instruction padding or
artificial helper locations are used. The exact 18-byte zeroing span matches
locally; that fact does not establish a complete constructor match.

## Independent replay

The coordinator applied this public patch cleanly to a fresh copy of canonical
source, then compiled it with the normal NDK 1.6 r1 GCC 4.2.1 profile. Actual
function and section size are 828 bytes versus native 832. The strict native
extent assertions stop linking, exit 2, as intended.

A separate diagnostic linker script retained the original start, selected the
actual 828-byte section and left the four-byte gap before the next native
function. The SAME compiled objects were relinked without compilation or edits.
The diagnostic target comparison exits 1: **611 common bytes differ and four are
missing**, first at `+0x0e`. All 147 existing function checks and 118 owner
section/region checks pass in that actual diagnostic image. No complete target
or immediate compiled-next-neighbor proof is claimed.

Raw function SHA256:
`b4448f2897be503085b9a7922ba95540b4c722864b264e4cf6dc1e0043472f38`.
Diagnostic linked function SHA256:
`2cebe0b4e95fb6e70e3b45dc1ba9a8477feb239f30a3b91b7465c794494b0359`.
The adjacent JSON records these exact limitations. No executable or game data is
included. Legacy GCC warns about the compile-time NULL-object member-offset
assertions for children/depth; compilation succeeds before the expected strict
link failure.

## Reproduction

Use a disposable checkout with the normal retail library and matching toolchain:

```sh
git apply --unidiff-zero --check nonmatching/rendering/OctTreeAABBNode-constructor.patch
git apply --unidiff-zero nonmatching/rendering/OctTreeAABBNode-constructor.patch
python tools/build.py gs3d-stuff
```

The last command is EXPECTED to fail the original 832-byte extent. Do not remove
the assembly marker or regenerate progress as a match. For diagnostic comparison
only, use a separate linker script asserting actual size 828 and actual end
`0x002df990`, then relink the unchanged objects. Never fill the four missing bytes
or weaken the canonical native-fit guard. The diagnostic still fails comparison.

Before the owned body trial, the private original-SDK header prerequisites also
passed 125 affected profiles with 8,876 existing comparisons. This is historical
prerequisite evidence, not a claim that the unpublished constructor passes.
