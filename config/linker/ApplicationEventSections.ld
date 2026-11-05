SECTIONS
{
    .event_id 0x002d3c34 : { *(.gnu.linkonce.t._ZNK6IEvent10getEventIDEv) }
    .event_delete 0x002d4074 : { *(.gnu.linkonce.t._ZN6IEventD0Ev) }
    .event_destructor 0x002d4094 : { *(.gnu.linkonce.t._ZN6IEventD1Ev) }
    .event_vtable 0x004a6198 : { *(.gnu.linkonce.d.rel.ro._ZTV6IEvent .data.rel.ro._ZTV6IEvent) }
}
