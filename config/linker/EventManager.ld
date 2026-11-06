OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/event-manager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__cxa_pure_virtual = 0;
SECTIONS
{
    .event_manager_constructor 0x00354644 : { *event-manager.o(.text._ZN12EventManagerC1Ev) }
    .event_manager_trace 0x00354660 : { *event-manager.o(.text._ZNK12EventManager6_traceEPKc) }
    .event_manager_attach 0x00354860 : { *event-manager.o(.text._ZN12EventManager6attachEiP14IEventReceiver) }
    .event_manager_detach 0x0035488c : { *event-manager.o(.text._ZN12EventManager6detachEiP14IEventReceiver) }
    .event_manager_async 0x003548b8 : { *event-manager.o(.text._ZNK12EventManager10raiseAsyncEPK6IEvent) }
    .event_manager_refresh 0x003548d8 : { *event-manager.o(.text._ZN12EventManager7refreshEv) }
    .event_manager_raise 0x0035494c : { *event-manager.o(.text._ZN12EventManager5raiseERK6IEvent) }
    .event_manager_raise_ptr 0x003549d4 : { *event-manager.o(.text._ZN12EventManager5raiseEPK6IEvent) }
    .event_manager_update 0x003549e0 : { *event-manager.o(.text._ZN12EventManager6updateEd) }
    .event_manager_delete 0x00354a1c : { *event-manager.o(.text._ZN12EventManagerD0Ev) }
    .event_manager_base 0x00354a54 : { *event-manager.o(.text._ZN12EventManagerD1Ev) }
    .event_manager_vtable 0x004ad8c8 : { *event-manager.o(.data.rel.ro._ZTV12EventManager) }
    .updatable_delete 0x002d62b8 : { *event-manager.o(.gnu.linkonce.t._ZN10IUpdatableD0Ev) }
    .updatable_base 0x002d62d8 : { *event-manager.o(.gnu.linkonce.t._ZN10IUpdatableD1Ev) }
    .updatable_vtable 0x004a6290 : { *event-manager.o(.gnu.linkonce.d.rel.ro._ZTV10IUpdatable) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
