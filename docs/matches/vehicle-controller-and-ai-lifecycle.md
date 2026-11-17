# Vehicle controller states and AI manager lifecycle

The vehicle controller and cop-vehicle controller state handlers reuse the
existing vehicle, NPC, physics, and player interfaces. The base handler's
48-byte switch table is verified in full. The cop-vehicle handler copies the
observed float from Vehicle offset 188 to offset 776, preserving the class
extent and leaving stronger field names unassigned. Both methods retain the
original virtual calls, target selection, and flag-store ordering.

AIManager::clean reuses the existing ReceiverList and ReceiverNode layouts.
A local inline list helper shares the two cleanup loops while preserving the
cached next link across receiver destruction and rereading links for unlinking.
The four event detachments share the original cached event manager.

AIManager::onEvent uses typed event target accessors for event IDs 17, 18, 20,
and 21. The scoped loops preserve the original payload loads on each iteration.
A template helper was tested but did not reproduce the complete function; the
accepted source retains the four original scoped cases.

EvVehicleDeactivated and EvVehicleDestroyed declarations now live in the shared
VehicleEvents.h header. Existing constructor and destructor implementations in
Vehicle.cpp are unchanged. The destroyed event's observed payload pointer at
offset 8 completes its previously partial declaration. Existing NPC death and
despawn events gain only inline target accessors. No event constructor or
destructor receives new matching credit in this change.

Vehicle cleanup was byte-verified before extraction and again afterward. The
combined integrated command also checks AIManager, both vehicle-controller
units, and PlayerTest with all native dependencies. It exited 0 and printed:

```text
OK  _ZN9AIManager7onEventEPK6IEventPK12EventManager  0x00340741  164 bytes
OK  _ZN9AIManager5cleanEv  0x003406a9  150 bytes
OK  _ZN17VehicleController11switchStateEN8gameloft2ai7StateIDE  0x003426b5  356 bytes
OK SECTION .vehicle_switch_table  0x004323e0  48 bytes
OK  _ZN20CopVehicleController11switchStateEN8gameloft2ai7StateIDE  0x0034171d  144 bytes
```
