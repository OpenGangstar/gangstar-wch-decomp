SECTIONS
{
    .application_on_event 0x002d5eb8 : { *application-helpers.o(.text._ZN11Application7OnEventERKN3irr6SEventE) }
    ASSERT(SIZEOF(.application_on_event) == 596, "Application OnEvent strict native596 extent")
    .application_on_event_switch 0x00413dd8 : { *application-helpers.o(.rodata._ZN11Application7OnEventERKN3irr6SEventE) }
    ASSERT(SIZEOF(.application_on_event_switch) == 32, "Application OnEvent native32 switch table")
}

/* Retain the unreferenced compiler initializer in verification-only storage.
   It has no relocation users and is not credited as native game data. */
SECTIONS {
    .application_unused_initializer 0x00610000 : {
        *application-helpers.o(.rodata._ZZN33ApplicationMonitoredPointerHeaderC1ERKSaISt4pairIKPvPKcEEE3C.4)
    }
    ASSERT(SIZEOF(.application_unused_initializer) == 16, "Unreferenced initializer extent")
}
