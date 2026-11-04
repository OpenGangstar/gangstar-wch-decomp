# SoundManager destructor

The manager derives from IUpdatable and contains a 32-byte radio controller.
The destructor releases the sound table, channel rows and frequencies before
the embedded controller and base destructors run. The radio station accessors
now read the count through the embedded controller at the same retail offset.

The first candidate used the base destructor alias for the radio controller
binding. Binding its complete destructor preserved the retail Thumb call.
Both generated vtables compare exactly.

```text
OK  _ZN12SoundManagerD0Ev  0x00353a79  112 bytes
OK  _ZN12SoundManagerD2Ev  0x00353ae9  104 bytes
OK  _ZN12SoundManagerD1Ev  0x00353ae9  104 bytes
OK SECTION .sound_manager_vtable  0x004ad850  24 bytes
OK SECTION .sound_updatable_vtable  0x004a6290  24 bytes
```
