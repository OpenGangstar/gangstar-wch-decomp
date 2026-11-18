# AccelerometerWin32 empty callback

The retail callback is a two-byte Thumb BX LR stub; its generated secondary-base
ARM thunk adjusts this by 76 bytes. The actual class inherits Irrlicht's genuine
IEventReceiver interface, which proves the bool signature. No false-return
implementation or void substitute reproduces the original callback.

The reconstruction intentionally retains the missing return: the native stub
does not assign a boolean result, and the C++ function has no defined return
value. This preserves the original bug under the matching ARM compiler rather
than inventing a default. The project already preserves a missing-return path
in WeaponManager::isWeaponUsableFromVehicle. No warning was printed under the
canonical compiler flags, and no warning suppression was added. No Windows
port implementation or launcher configuration changes are included.

Exact comparison output:

```text
OK  _ZN18AccelerometerWin327OnEventERKN3irr6SEventE  0x0034d989  2 bytes
OK  _ZThn76_N18AccelerometerWin327OnEventERKN3irr6SEventE  0x0034d974  20 bytes
```

Both are real executable STT_FUNC definitions at their original addresses.
The existing 11 functions and seven section/region comparisons remain exact,
including the 48-byte class vtable, 24-byte receiver vtable and full global GOT.
The callback's complete four-byte allocation, including padding, also matches.
No compiled function is masked by an absolute binding. Native references use
these vtable entries; no additional direct caller was found in static analysis.

The coordinator combined gate passes all 186 profiles and 10,358 function,
section and region comparisons. All 13 game functions attributed to the original
AccelerometerWin32.cpp source now match, totaling 570 bytes. Its two previously
pending entries add 22 Matched bytes; completing the original source qualifies
all 570 bytes for Fully Linked accounting. Other unfinished source units remain
incomplete. Native Windows execution was not tested by these ARM comparisons.
