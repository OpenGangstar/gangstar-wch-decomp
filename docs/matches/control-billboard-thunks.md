# Touch-control and billboard thunks

The real compiler-generated ARM thunks for SlideControl, Wheel and
CustomBillboardSceneNode now match all 20 native bytes each. Their saved
faithful parents remain explicitly unmatched under nonmatching, with their
original assembly and pending catalogue entries intact. SlideControl and Wheel
use the actual +8 touch interface; billboard uses its actual +100 interface.
No surrogate classes, handwritten thunks, ABS replacements or output edits
are used. All compiled definitions retain executable sections.

Parent extents remain 668/668, 300/300 and 704/704 respectively; equal size is
not a match. Normal local-section relocations require these real compiled
parent prerequisites at retail addresses. Verification profiles retain them
without granting matching or Fully Linked completion credit.

## Recovered interfaces

The coordinator moved the two existing directional-event declarations into a
shared header at their original AnalogStick.cpp declaration point. Their
existing destructor bodies are unchanged and remain byte exact. True bool/float
payloads at 8/12 and IDs 9/11 give the observed 16-byte objects. EvStickMove gains
its observed ID-7 constructor, preserving its prior default behavior. SlideControl
bounds are integers, centers floats, and compatibility aliases occupy existing
flag bytes. Wheel's observed unsigned displacement limit at 72 preserves its
84-byte size. Its actual EvWheelTurn declaration gains the observed ID-14
payload/constructor while keeping its existing destructor body unchanged.
All eight affected existing event destructor entries remain exact.

Billboard uses the actual camera getTarget slot, existing mutableElement API
and existing time word. Its crossProduct is explicitly marked as a modified
fork/native-expression reconstruction; it is not claimed to be unchanged
Irrlicht upstream. Irrlicht licensing remains intact. CRootSceneNode::OnAnimate's
normal long-call declaration is supported by its real native Thumb definition
and GOT relocation. No existing constructor body was changed.

Wheel's emitted Point2D destructors and vtable are placed at their native
addresses and compared completely. No DISCARD workaround masks support code.
A linker setup error was corrected by relinking the same compiled object.
SlideControl likewise needed only a linker whitespace correction, with no
second source form. Rejected AnalogStick code remains uncredited because its
1028-byte parent overlaps the next native function's 1016-byte allocation.

## Verification

Exact function output:

```text
OK  _ZThn8_N12SlideControl12processTouchEl  0x0032b650  20 bytes
OK  _ZThn8_N5Wheel12processTouchEl  0x0032cfb8  20 bytes
OK  _ZThn100_N24CustomBillboardSceneNode9OnAnimateEj  0x002f7ff8  20 bytes
```

Private affected-header closures passed: SlideControl nine profiles (202
functions/166 regions); Wheel seven (136/93); billboard 117 including dependencies
(3886 functions, 3742 sections and 114 regions). Existing nonmatching source
users were included. The integrated `python tools/build.py --all` exits zero:
190 profiles and 10,501 successful function/section/region comparisons.
All previous matches, complete vtable allocations and GOT checks remain.
