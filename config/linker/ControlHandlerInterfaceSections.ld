__cxa_pure_virtual = 0;
SECTIONS
{
    .control_handler_delete 0x0032e468 : { *(.gnu.linkonce.t._ZN15IControlHandlerD0Ev) }
    .control_handler_destructor 0x0032e494 : { *(.gnu.linkonce.t._ZN15IControlHandlerD1Ev) }
    .control_handler_vtable 0x004aca98 : { *(.gnu.linkonce.d.rel.ro._ZTV15IControlHandler) }
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_destructor 0x002db4d4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD1Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
}
