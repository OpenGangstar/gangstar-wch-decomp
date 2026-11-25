# AIManager::addAI(Vehicle*, StateID) exact match

```text
OK  _ZN9AIManager5addAIEP7VehicleN8gameloft2ai7StateIDE  0x00340305  336 bytes
```

Vehicle type 3 creates a `CopVehicleController` (sending it a wanted-level event),
type 0 a civilian `VehicleController` and type 6 a scripted one; an initial state
of 0 becomes 1 for types 0 and 3. Retail appends to the receiver list four
separate times (twice in case 0), not through a common tail as the earlier
244-byte attempt assumed. Source case order 3, 0, 6 reproduces retail
cross-jumping. `AIManager::ReceiverList::append` is a new inline helper using
the existing STLport node allocator; `Vehicle` grants `AIManager` friendship
for its type field. The controller constructors are bound as external Thumb
functions.

Full gate: `python -B tools/build.py --all` exited 0 with 5,482 function, 5,530 section and 181 region comparisons and no mismatch or skip.
