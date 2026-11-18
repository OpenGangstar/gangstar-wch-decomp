# RenderFX utility family

Three reconstructed functions match their complete original code:

```text
OK  _ZN8RenderFX9SetMemberEPKcS1_S1_  0x003eeb71  96 bytes
OK  _Z16GetLocalPositionPN7gameswf9characterEff  0x003eccd9  112 bytes
OK  _Z38sprite_can_handle_mouse_event_callbackPN7gameswf9characterE  0x003eca69  12 bytes
```

Each first source body matches. The string setter reuses the existing integer
setter pattern, constructing the real as_value string temporary and forwarding
to the existing value overload. Its 40-byte, eight-byte-aligned value storage,
stack protection and native destructor remain unchanged.

GetLocalPosition preserves the eight-byte point return through the ARM hidden
result pointer, original 20.0f coordinate scaling, 24-byte world-matrix copy,
native inverse construction and transform. The world-matrix method uses the
existing explicit native this-pointer import already used by widgets. Only the
authentic void set_inverse declaration is added to the existing matrix view;
no engine implementation or new fields are supplied. The archived original
SDK interface declaration is recorded in
_scratch/renderfx-local-position/reference/SOURCE.txt.

The mouse callback forwards to the real native CanHandleMouseEvent. Its parked
80-byte candidate for a 92-byte target is not copied or credited. No extra data,
helper definitions, register constraints, hints or compiler-output edits are
used for these three functions.

A shared linker include retains all three definitions at native addresses in
RenderFX and both menu/widget dependency images. Each image explicitly checks
the actual executable definitions; original Thumb metadata is retained for
engine imports and the pending predicate. Both affected headers are checked
against all current users. Existing functions and Windows sources are unchanged.

Coordinator graph: 9 profiles, 1,845 passing function/section/GOT comparisons,
exit zero. Proof: _scratch/renderfx-utilities-root.log and .exit. Only the three
original game functions, totalling 220 bytes, receive progress credit.
