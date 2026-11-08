SECTIONS
{
    .npc_is_targetable 0x003011e4 : { *ai-startup-npc.o(.text._ZN3NPC12isTargetableEv) }
    .npc_death_event_dtor 0x002feff8 : { *ai-startup-npc.o(.gnu.linkonce.t._ZN10EvNPCDeathD1Ev) }
    .npc_death_event_delete 0x002feb9c : { *ai-startup-npc.o(.gnu.linkonce.t._ZN10EvNPCDeathD0Ev) }
    .npc_death_event_vtable 0x004aae70 : { *ai-startup-npc.o(.gnu.linkonce.d.rel.ro._ZTV10EvNPCDeath) }
    .npc_notify_targeted 0x002fedac : { *ai-startup-npc.o(.text._ZN3NPC14notifyTargetedEbP9Character) }
    .npc_event_dtor 0x002f5158 : { *ai-startup-npc.o(.gnu.linkonce.t._ZN5EvNPCD1Ev) }
    .npc_event_delete 0x002f626c : { *ai-startup-npc.o(.gnu.linkonce.t._ZN5EvNPCD0Ev) }
    .npc_event_vtable 0x004aa120 : { *ai-startup-npc.o(.gnu.linkonce.d.rel.ro._ZTV5EvNPC) }
    .npc_base_event_id 0x002d3c34 : { *ai-startup-npc.o(.gnu.linkonce.t._ZNK6IEvent10getEventIDEv) }
    .npc_base_event_dtor 0x002d4094 : { *ai-startup-npc.o(.gnu.linkonce.t._ZN6IEventD1Ev) }
    .npc_base_event_delete 0x002d4074 : { *ai-startup-npc.o(.gnu.linkonce.t._ZN6IEventD0Ev) }
    .npc_base_event_vtable 0x004a6198 : { *ai-startup-npc.o(.gnu.linkonce.d.rel.ro._ZTV6IEvent) }
}
