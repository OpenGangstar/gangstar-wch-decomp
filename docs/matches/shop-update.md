# Shop::Update exact match

```text
OK  _ZN4Shop6UpdateEi  0x00305f5d  384 bytes
OK SECTION .shop_update  0x00305f5c  384 bytes
```

Runs the checkpoint update and, while the shop is active, either toggles the
trigger for a vehicle shop (type 32) as the player's car enters or leaves the
radius, or registers the shop as the player's closest shop when the player is
on foot within range.

The archived reconstruction (`nonmatching/ui/Shop-Update-current-hierarchy.md`)
was exact except at offset `0xea`, where it loaded the car's vtable through r1
instead of retail's r0. It wrote the in-vehicle guard as an early return,
`if (!(flags & 0x400) || !getVehicle()) return;`, which moves the second
`getVehicle` and its null test to the end of the function. Writing the same
condition as a nested positive `if (...) { car = ...; if (car) { ... } }`
keeps the body as the fall-through of the null test, so the post-reload
equivalence of r0 and r1 also rewrites the vtable load to r0, as in retail.

`Checkpoint::Update` and `PlayerTest::setClosestShop` are bound to retail Thumb
addresses and `__aeabi_i2f`/`__aeabi_f2iz` to their PLT entries. No header
change, hint, inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,521 function,
5,598 section and 181 region comparisons and no mismatch or skip.
