SECTIONS
{
    .application_event_EvMouseMove_D1Ev 0x002d5da4 : { *application-helpers.o(.gnu.linkonce.t._ZN11EvMouseMoveD1Ev) }
    .application_event_EvMouseMove_D0Ev 0x002d610c : { *application-helpers.o(.gnu.linkonce.t._ZN11EvMouseMoveD0Ev) }
    .application_event_EvMouseMove_vtable 0x004a61b0 : { *application-helpers.o(.gnu.linkonce.d.rel.ro._ZTV11EvMouseMove) }
    .application_event_EvKeyboard_D1Ev 0x002d5df4 : { *application-helpers.o(.gnu.linkonce.t._ZN10EvKeyboardD1Ev) }
    .application_event_EvKeyboard_D0Ev 0x002d5dc8 : { *application-helpers.o(.gnu.linkonce.t._ZN10EvKeyboardD0Ev) }
    .application_event_EvKeyboard_vtable 0x004a6180 : { *application-helpers.o(.gnu.linkonce.d.rel.ro._ZTV10EvKeyboard) }
    .application_event_EvMouseWheel_D1Ev 0x002d5e44 : { *application-helpers.o(.gnu.linkonce.t._ZN12EvMouseWheelD1Ev) }
    .application_event_EvMouseWheel_D0Ev 0x002d5e18 : { *application-helpers.o(.gnu.linkonce.t._ZN12EvMouseWheelD0Ev) }
    .application_event_EvMouseWheel_vtable 0x004a61c8 : { *application-helpers.o(.gnu.linkonce.d.rel.ro._ZTV12EvMouseWheel) }
    .application_event_EvMouseButton_D1Ev 0x002d5e94 : { *application-helpers.o(.gnu.linkonce.t._ZN13EvMouseButtonD1Ev) }
    .application_event_EvMouseButton_D0Ev 0x002d5e68 : { *application-helpers.o(.gnu.linkonce.t._ZN13EvMouseButtonD0Ev) }
    .application_event_EvMouseButton_vtable 0x004a61e0 : { *application-helpers.o(.gnu.linkonce.d.rel.ro._ZTV13EvMouseButton) }
    .event_id 0x002d3c34 : { *(.gnu.linkonce.t._ZNK6IEvent10getEventIDEv) }
    .event_delete 0x002d4074 : { *(.gnu.linkonce.t._ZN6IEventD0Ev) }
    .event_destructor 0x002d4094 : { *(.gnu.linkonce.t._ZN6IEventD1Ev) }
    .event_vtable 0x004a6198 : { *(.gnu.linkonce.d.rel.ro._ZTV6IEvent .data.rel.ro._ZTV6IEvent) }
}
