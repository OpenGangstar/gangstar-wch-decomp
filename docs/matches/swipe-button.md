# Swipe button interactions

SwipeButton draws its configured frame and dispatches touches initiated
inside its region. A recognized swipe clears the touch point. The
profile checks the handlers, deleting destructor, adjustment thunks,
and vtable. The constructor remains pending.

```text
OK  _ZThn8_N11SwipeButton19processTouchReleaseEv  0x0032bbc8  20 bytes
OK  _ZN11SwipeButton19processTouchReleaseEv  0x0032bbdd  2 bytes
OK  _ZThn4_N11SwipeButtonD0Ev  0x0032bc10  20 bytes
OK  _ZN11SwipeButtonD0Ev  0x0032bc25  48 bytes
OK  _ZThn4_NK11SwipeButton6draw2dEv  0x0032bc54  20 bytes
OK  _ZNK11SwipeButton6draw2dEv  0x0032bc69  30 bytes
OK  _ZThn8_N11SwipeButton12processTouchEl  0x0032bc88  20 bytes
OK  _ZN11SwipeButton12processTouchEl  0x0032bc9d  50 bytes
OK  _ZN11SwipeButton6updateEd  0x0032bcd1  44 bytes
OK SECTION .swipe_vtable  0x004ac7b0  128 bytes
```
