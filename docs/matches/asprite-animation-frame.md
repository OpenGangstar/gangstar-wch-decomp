# ASprite::GetAFrame(int, int)

The animation lookup reuses canonical ASpriteData::Anim records. It preserves
signed count/first-frame values, the original Application::GetInstance call
and subsequent data reload, nine-byte runtime frame stride and unsigned
16-bit duration at offset two. It returns the first frame whose cumulative
duration exceeds time, or count minus one when exhausted.

## Permitted GNU likelihood hint

This function uses `__builtin_expect(time < total, 0)` on its existing early
return. This changes branch probability metadata, not C++ behavior. No compiler
flags, register constraints, barriers or emitted bytes are modified.

Without the hint the native-sized candidate differed in six register-encoding
bytes: GCC assigned entry to r5 and time to r6. Diagnostic-only rebuilds kept
identical object/function bytes and isolated GCC global-allocation priorities.
The hint reduces entry's weighted reference priority from 343 to 209; time's
priority changes from 299 to 285. Time is consequently allocated first to r5,
with entry in r6, reproducing the complete native function. A second hint form
was unnecessary and was not tried.

Exact comparison output:

```text
OK  _ZN7ASprite9GetAFrameEii  0x003499dd  106 bytes
```

Actual executable STT_FUNC address is 0x003499dd (Thumb), size 106, SHA-256
cad504bfe5ef9571da44a18831a2d8920464c57b56f3f8c7827e1f49c204f0ab.
The separate caller gate passed 63 function, 56 section and two GOT comparisons,
including AnimObject. Coordinator `python tools/build.py --all` exited zero:
183 profiles and 10,277 successful function/section/region comparisons. Every
previous comparison remains present. No existing function body was changed.

This adds one function and 106 bytes. ASprite remains incomplete; Fully Linked
completion is unchanged. Rejected canonical/likelihood PaintModule experiments
are not part of this implementation.
