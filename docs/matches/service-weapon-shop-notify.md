# Menus::ServiceWeaponShop::Notify

The complete 188-byte Thumb function at `0x002eb921` matches retail using the
canonical manager getters, typed Arrows/Shop receivers and actual member calls.
Its refresh, selection, confirmation and return behavior remain unchanged.
The complete Shop declaration, including its real Item record, is copied from
MenuWidget.cpp. Existing Arrows declarations remain unchanged.

The existing ServiceWeaponShop class gains only the genuine nonvirtual
`void Refresh()` declaration needed by this handler. It changes no storage or
virtual slots. The first missing-declaration compilation failure was preserved;
the same source form passed after the approved declaration was restored.

```text
OK  _ZN5Menus17ServiceWeaponShop6NotifyEPK10MenuWidgeti  0x002eb921  188 bytes
OK SECTION .service_weaponshop_notify  0x002eb920  188 bytes
```

Function SHA-256:
`db60950c44ee9bc0ba3fd70e19f91c27a44ad5182fbcdce6312a7792e8a40079`.
The physical 188-byte extent has an exact linker assertion. The only new
native Thumb import is the verified, genuinely pending Refresh function at
`0x002e7ac5`, size 568. The compiled Services handler and widget getters retain
their actual definitions; no compiled symbol is overridden.

The private closure passes 1,056 checks, retaining all 1,054 previous checks.
No Shop helper, constructor, vtable or data storage is newly emitted. Final
combined verification passes all 190 profiles and 10,675 comparisons. No hints,
compiler flags, barriers or output modifications are used. Existing matched
function bodies remain unchanged.
