/* Native relocation addend for the unresolved pure-virtual vtable entry. */
__cxa_pure_virtual = 0;
SECTIONS
{
    .application_d0 0x002d5c64 : { *application-helpers.o(.text._ZN11ApplicationD0Ev .gnu.linkonce.t._ZN11ApplicationD0Ev) }
    .application_d1 0x002d5cf8 : { *application-helpers.o(.text._ZN11ApplicationD1Ev .gnu.linkonce.t._ZN11ApplicationD1Ev .text._ZN11ApplicationD2Ev .gnu.linkonce.t._ZN11ApplicationD2Ev) }
    .application_receiver_d0 0x002537d8 : { *application-helpers.o(.text._ZN3irr14IEventReceiverD0Ev .gnu.linkonce.t._ZN3irr14IEventReceiverD0Ev) }
    .application_receiver_d1 0x002537f8 : { *application-helpers.o(.text._ZN3irr14IEventReceiverD1Ev .gnu.linkonce.t._ZN3irr14IEventReceiverD1Ev .text._ZN3irr14IEventReceiverD2Ev .gnu.linkonce.t._ZN3irr14IEventReceiverD2Ev) }
    .application_vtable 0x004a6168 : { *application-helpers.o(.data.rel.ro._ZTV11Application .gnu.linkonce.d.rel.ro._ZTV11Application) }
    .application_receiver_vtable 0x00488968 : { *application-helpers.o(.data.rel.ro._ZTVN3irr14IEventReceiverE .gnu.linkonce.d.rel.ro._ZTVN3irr14IEventReceiverE) }
}
