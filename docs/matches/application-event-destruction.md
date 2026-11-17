# Application input-event destruction

The keyboard, mouse-move, mouse-wheel, and mouse-button events reuse the existing
polymorphic IEvent interface. Ordinary empty C++ virtual destructors emit each
complete and deleting destructor, with the original vptr stores and cleanup.
All four vtables are compared including their alignment padding.

These are partial deletion interfaces. Their event payloads and allocation
extents remain unrecovered; no code instantiates them. Only the observed
inheritance and destructor behavior are asserted. Incidental deleting sections
were first treated as uncredited, then formally checked as defined executable
functions after removing retail absolute fallbacks. No imported address is
counted as an implementation.

`python tools/build.py application-helpers` exited 0 with all existing functions,
sections, IEvent helpers, and GOT checks preserved:

```text
OK  _ZN11EvMouseMoveD1Ev  0x002d5da5  36 bytes
OK  _ZN11EvMouseMoveD0Ev  0x002d610d  44 bytes
OK  _ZN10EvKeyboardD1Ev  0x002d5df5  36 bytes
OK  _ZN10EvKeyboardD0Ev  0x002d5dc9  44 bytes
OK  _ZN12EvMouseWheelD1Ev  0x002d5e45  36 bytes
OK  _ZN12EvMouseWheelD0Ev  0x002d5e19  44 bytes
OK  _ZN13EvMouseButtonD1Ev  0x002d5e95  36 bytes
OK  _ZN13EvMouseButtonD0Ev  0x002d5e69  44 bytes
OK SECTION .application_event_EvMouseMove_vtable  0x004a61b0  24 bytes
OK SECTION .application_event_EvKeyboard_vtable  0x004a6180  24 bytes
OK SECTION .application_event_EvMouseWheel_vtable  0x004a61c8  24 bytes
OK SECTION .application_event_EvMouseButton_vtable  0x004a61e0  24 bytes
```

The GSFade verification image also links the native Application object. The first
full build exposed orphaned event sections in that dependent image. Moving the
placements into the existing ApplicationEventSections.ld fragment retains the
same native definitions in both images. GSFade now explicitly compares all eight
event functions and all four vtables as well; its scoped build exited 0 with
all previous comparisons preserved. No linker overlap checks were disabled.
