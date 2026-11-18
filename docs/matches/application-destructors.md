# Application destructor family

The original empty C++ destructor now reproduces the native deleting destructor
and the shared complete/base destructor. The existing recovered 180-byte
Application layout supplies the IEventReceiver base, four STLport registration
lists and monitored-pointer map. Ordinary compiler-generated destruction handles
their cleanup and vtable transitions. No existing function body or header changed.

Coordinator verification on the current integrated checkout:

```text
OK  _ZN11ApplicationD0Ev  0x002d5c65  148 bytes
OK  _ZN11ApplicationD1Ev  0x002d5cf9  144 bytes
OK  _ZN11ApplicationD2Ev  0x002d5cf9  144 bytes
OK  _ZN3irr14IEventReceiverD0Ev  0x002537d9  32 bytes
OK  _ZN3irr14IEventReceiverD1Ev  0x002537f9  24 bytes
OK SECTION .application_vtable  0x004a6168  24 bytes
OK SECTION .application_receiver_vtable  0x00488968  24 bytes
```

`python tools/build.py application-helpers state-hooks-gsfade` passed with exit
zero: five profiles, 816 function/section/GOT comparisons. Both consumers retain
and explicitly compare the real compiled destructor family, SDK base destructors
and vtables at native addresses. Obsolete destructor imports were removed.
The 24-byte table regions include the original 20-byte vtables and alignment.

The base vtable's pure-virtual slot at 0x00488978 contains a zero addend and an
R_ARM_ABS32 relocation against the undefined `__cxa_pure_virtual` symbol. The
verification linker binds that symbol to zero to preserve the retail relocation
addend; this supplies no runtime implementation. Both emitted vtables and the
existing GOT regions compare exactly. An initial linker-comment syntax error was
corrected before the successful comparison; no compiler output was modified.

Progress counts three original function entries, 436 bytes; D1 and D2 alias the
same 144-byte body, so the physical code added is 292 unique bytes. SDK functions
are verified support, outside game progress. The constructor remains pending.
No Windows port source or configuration changed.
