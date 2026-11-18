# Application HUD number renderer

Application::displayNumberWithHUDSprite(int, int, int, char const*) matches all
416 bytes at Thumb 0x002d4861. The fourth bounded source form uses the native
shared index and character-assignment loops. It preserves null-sprite handling,
negative-number clamping, optional format selection, alignment calculations,
digit-frame selection and drawing. No bounds checks or formatting behavior were
invented. The original 12-byte buffer and stack canary are preserved.

The existing native allocator declaration is consolidated with NativeAllocator.h.
Three actual registration-node allocate specializations remain weak imports,
matching their original native bindings. The generic allocator header is
unchanged. No existing function algorithm changes. Application's verification
profile now enables its observed stack protector; every old function remains
byte-exact. Compiler output is never edited.

The canonical constructor-evidenced eight-byte region at 96 is represented as
float unknown96 and int unknown100. This coherent layout preserves offsets and
restores an existing menu comparison after the new method declaration; no old
menu body was changed. Application remains partial and is not instantiated.

The 40-byte static digit-frame table at 0x004143c8 and four-byte default format
at 0x00413c9c compare completely. The actual generated function and constants
are retained in both ApplicationHelpers and GSFade dependency images. Explicit
native placements also prevent existing stopSoundThread and logo/resume path
sections from becoming overlapping linker orphans. The GSFade PaintFrame import
uses the real Thumb binding, avoiding an incorrect ARM-call relocation.

Both images independently print:

```text
OK  _ZN11Application26displayNumberWithHUDSpriteEiiiPKc  0x002d4861  416 bytes
OK SECTION .application_number_frames  0x004143c8  40 bytes
OK SECTION .application_number_format  0x00413c9c  4 bytes
```

Coordinator full `python tools/build.py --all` exited zero across 180 profiles.
The complete log/exit are _scratch/application-number-root-full.log and .exit.
All existing application inputs, frame methods, menus, touch, support, data and
GOT comparisons pass. The worker independently passed its 123-profile graph and
retained-function/data checks. Only the new 416-byte game function is credited.
No Windows port source or build configuration is changed.

The complete coordinator run passed 9,797 comparisons.
