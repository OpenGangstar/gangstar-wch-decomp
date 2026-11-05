# Radio control

Radio extends SwipeButton and uses an animation for the current station.
The Radio object emits the inline, weak SwipeButton destructor and its
adjustment thunk. Keeping that destructor out of line at the call site
reproduces the retail GOT call. The profile compares both destructors,
the Radio methods, and its generated vtable.

```text
OK  _ZN5Radio4showEv  0x0032a661  68 bytes
OK  _ZThn4_N5RadioD0Ev  0x0032a714  20 bytes
OK  _ZN5RadioD0Ev  0x0032a729  76 bytes
OK  _ZThn4_N5RadioD1Ev  0x0032a774  20 bytes
OK  _ZN5RadioD1Ev  0x0032a789  68 bytes
OK  _ZThn4_NK5Radio6draw2dEv  0x0032a7cc  20 bytes
OK  _ZNK5Radio6draw2dEv  0x0032a7e1  50 bytes
OK  _ZN5RadioC2EP7ASpriteiiiiii  0x0032a815  100 bytes
OK  _ZN5RadioC1EP7ASpriteiiiiii  0x0032a815  100 bytes
OK  _ZThn8_N5Radio12processTouchEl  0x0032a878  20 bytes
OK  _ZN5Radio12processTouchEl  0x0032a88d  104 bytes
OK  _ZN11SwipeButtonD1Ev  0x0032a6e9  44 bytes
OK  _ZThn4_N11SwipeButtonD1Ev  0x0032a6d4  20 bytes
OK SECTION .radio_vtable  0x004ac530  128 bytes
OK SECTION .radio_swipe_destructor  0x0032a6d4  64 bytes
```
