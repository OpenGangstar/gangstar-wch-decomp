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

## NPC controller allocation

The NPC addAI overload reuses shared declarations of the recovered passive,
aggressive, cop, and guard controllers. It preserves category-specific default
states, the cop's wanted-level event before list insertion, and the original
list-link update order. Categories 0 and 6 select the passive controller with
different transition tables; categories 1/2, 3, and 5 select aggressive, cop,
and guard controllers respectively. Invalid categories use the original message.

Allocation reuses NativeAllocator.h and a weak declaration of the observed
STLport list-node allocator specialization. The empty allocator subobject is
addressed through the existing list sentinel; no allocator implementation or
additional storage is invented. EvWantedLevelChanged initializes IEvent(23),
preserving the original temporary store order and all existing event layouts.

The scoped command exited 0 and preserved existing comparisons:

```text
OK  _ZN9AIManager5addAIEP3NPCN8gameloft2ai7StateIDE  0x00340455  376 bytes
OK SECTION .ai_add_npc_table  0x0042fabc  28 bytes
OK SECTION .ai_add_invalid_text  0x0042fa84  56 bytes
```
