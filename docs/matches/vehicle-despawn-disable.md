# Vehicle::OnDespawn and Vehicle::disable exact matches

```text
OK  _ZN7Vehicle9OnDespawnEv  0x00310e75  308 bytes
OK  _ZN7Vehicle7disableEv  0x00310fa9  416 bytes
```

Both preserved candidates differed only in CMP operand order where the player's
`LevelObject*` fields `unknown368` and `unknown312` are compared with `this`.
Comparing `field == this` converts `this` to its `LevelObject` base, reusing
the base temporary already computed for the call to `LevelObject::OnDespawn`, so
it became the first operand. Writing `static_cast<Vehicle*>(field) == this`
compares against the raw receiver, as retail does; the base is at offset 0, so
the cast adds no code. PlayerTest already uses the same `static_cast` on these
fields.

Retail-only callees (`LevelObject::OnDespawn`, `LevelObject::disable`,
`PlayerTest::_SetTarget`, `CameraManager::enterMode`, `CHudManager::walking`,
`CControlManager::exitCar`, `CameraManager::getInstance`) are bound as external
Thumb functions. python -B tools/build.py --all exited 0 with 5,476 function, 5,509 section and 181 region comparisons and no mismatch or skip.
