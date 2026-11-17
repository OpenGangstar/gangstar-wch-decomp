__cxa_pure_virtual = 0;
SECTIONS
{
    .camera_enter 0x00331c68 : { *string-startup-camera.o(.text._ZN6Camera5enterEv) }
    .camera_exit 0x00331c6c : { *string-startup-camera.o(.text._ZN6Camera4exitEv) }
    .camera_destructor 0x00331c70 : { *string-startup-camera.o(.text._ZN6CameraD1Ev .text._ZN6CameraD2Ev) }
    .camera_get_position 0x00331c88 : { *string-startup-camera.o(.text._ZNK6Camera11getPositionEv) }
    .camera_get_look_at 0x00331c8c : { *string-startup-camera.o(.text._ZNK6Camera9getLookAtEv) }
    .camera_set_look_at 0x00331c90 : { *string-startup-camera.o(.text._ZN6Camera9setLookAtERKN3irr4core8vector3dIfEE) }
    .camera_constructor 0x00331cd0 : { *string-startup-camera.o(.text._ZN6CameraC1Ev .text._ZN6CameraC2Ev) }
    .camera_set_position 0x00331cf8 : { *string-startup-camera.o(.text._ZN6Camera11setPositionERKN3irr4core8vector3dIfEE) }
    .camera_vtable 0x004acc58 : { *string-startup-camera.o(.data.rel.ro._ZTV6Camera) }
    .string_startup_function_0 0x00331ca0 : { *string-startup-camera.o(.text.__tcf_0) }
    .string_startup_function_1 0x00331d08 : { *string-startup-camera.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x00331d60 : { *string-startup-camera.o(.text._GLOBAL__I__ZN6CameraC2Ev) }
    .string_startup_storage_0 0x004b9ca0 (NOLOAD) : { *string-startup-camera.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
}
