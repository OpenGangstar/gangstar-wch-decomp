# Application key-event translation

`Application::ProcessKeyEvent(bool, int)` matches all 268 bytes at Thumb address
0x002d40fd. It preserves pressed/released mouse-event selection, the original
Android log calls, and the original coordinate pairs for types 1/2/3: (20,313),
(33,33), (66,240). The native type-2 branch lands after the load of 313, which
makes its actual y coordinate 33. Type 4 pauses MainMenu only on release and
returns without posting the event or printing the common post-event message.
The original partially initialized event fields are preserved.

Four bounded candidate bodies were compared. The corrected branch-target
interpretation produced the exact fourth form. The existing MainMenu class is
shared through ui/MainMenu.h without changing its methods, field layout, virtual
slots or native SetPause implementation. The genuine Irrlicht device interface
now lives in core/IrrlichtDevice.h. Its existing slots are unchanged; the newly
required slots 15 through 25 use actual SDK/native signatures, including
postEventFromUser at slot 25. ECOLOR_FORMAT is the licensed Irrlicht four-value
enum in core/ColorFormat.h. Only actual device-call source files include the
complete interface; SceneNode.h retains its forward declaration and ITimer.
There are no new engine implementations or changes to Windows port files.

The interface additions changed instruction scheduling in the existing
68-byte TouchScreenBase::getID(long), reversing two independent initializations.
The coordinator changed only their source declaration order: freeSlot = -1
precedes i = 0. The loop, return values, touch-slot behavior, and existing comment
are unchanged. This restores the complete original function and its full section
under the real interfaces. This existing-function edit is also reported in the
commit message; it contributes no new matching credit.

Seven original strings are compiled into named sections and compared, including
alignment bytes. Both ApplicationHelpers and its GSFade dependency consumer
retain the actual generated new function and literals at native addresses.
They use the real Android logging PLT, with no absolute-symbol replacement for
the newly implemented function. No compiler flags or output bytes were changed.

Coordinator verification before credit:

```text
OK  _ZN11Application15ProcessKeyEventEbi  0x002d40fd  268 bytes
OK  _ZN15TouchScreenBase5getIDEl  0x0034c599  68 bytes
```

`python tools/build.py --all` exited 0: 180 profiles, 9,788 successful function,
section and region comparisons, with zero failures or skipped profiles. This
includes every existing matched function, the corrected getID function/section,
all seven strings and actual dependency links. The private full log is
_scratch/process-key-root-full.log and its exit file contains 0.

Only the new 268-byte function is credited. Native Windows port compilation was
not part of this ARM verification; its source and build configuration are
unchanged.
