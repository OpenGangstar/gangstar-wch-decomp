SECTIONS
{
    .map_notify 0x002e78ac : { *ai-startup-menustate.o(.text._ZN5Menus3Map6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.map_notify) == 220, "native Map Notify strict span")
}
