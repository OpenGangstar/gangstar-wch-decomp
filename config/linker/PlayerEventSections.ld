SECTIONS
{
    .character_recovered_002f61f9 0x002f61f8 : { *(.text._ZN8EvPlayerD1Ev .gnu.linkonce.t._ZN8EvPlayerD1Ev) }
    .character_recovered_002f512d 0x002f512c : { *(.text._ZN8EvPlayerD0Ev .gnu.linkonce.t._ZN8EvPlayerD0Ev) }
    .character_player_event_vtable 0x004aa138 : { *(.gnu.linkonce.d.rel.ro._ZTV8EvPlayer) }
    .character_base_event_vtable 0x004a6198 : { *(.gnu.linkonce.d.rel.ro._ZTV6IEvent) }
    .character_base_event_dtor 0x002d4094 : { *(.gnu.linkonce.t._ZN6IEventD1Ev) }
    .character_base_event_delete 0x002d4074 : { *(.gnu.linkonce.t._ZN6IEventD0Ev) }
    .character_base_event_id 0x002d3c34 : { *(.gnu.linkonce.t._ZNK6IEvent10getEventIDEv) }
}
