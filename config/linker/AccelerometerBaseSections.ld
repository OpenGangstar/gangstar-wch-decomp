SECTIONS
{
    .accelerometer_base_constructor 0x0034d580 : { *sdk-startup-accelerometerbase.o(.text._ZN17AccelerometerBaseC1Ev .text._ZN17AccelerometerBaseC2Ev) }
    .accelerometer_base_delete 0x0034d7d4 : { *sdk-startup-accelerometerbase.o(.text._ZN17AccelerometerBaseD0Ev) }
    .accelerometer_base_destructor 0x0034d800 : { *sdk-startup-accelerometerbase.o(.text._ZN17AccelerometerBaseD1Ev .text._ZN17AccelerometerBaseD2Ev) }
    .accelerometer_base_vtable 0x004ad448 : { *sdk-startup-accelerometerbase.o(.data.rel.ro._ZTV17AccelerometerBase) }
    .accelerometer_updatable_d0 0x002d62b8 : { *sdk-startup-accelerometerbase.o(.gnu.linkonce.t._ZN10IUpdatableD0Ev) }
    .accelerometer_updatable_d1 0x002d62d8 : { *sdk-startup-accelerometerbase.o(.gnu.linkonce.t._ZN10IUpdatableD1Ev) }
    .accelerometer_updatable_vtable 0x004a6290 : { *sdk-startup-accelerometerbase.o(.gnu.linkonce.d.rel.ro._ZTV10IUpdatable) }
    .accelerometer_update 0x0034d420 : { *sdk-startup-accelerometerbase.o(.text._ZN17AccelerometerBase6updateEd) }
    .accelerometer_clear 0x0034d40c : { *sdk-startup-accelerometerbase.o(.text._ZN17AccelerometerBase5clearEv) }
    .sdk_startup_function_0 0x0034d42c : { *sdk-startup-accelerometerbase.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0034d5b8 : { *sdk-startup-accelerometerbase.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0034d624 : { *sdk-startup-accelerometerbase.o(.text._GLOBAL__I__ZN17AccelerometerBaseC2Ev) }
    .sdk_startup_storage_0 0x004bc0e0 (NOLOAD) : { *sdk-startup-accelerometerbase.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc100 (NOLOAD) : { *sdk-startup-accelerometerbase.o(.bss._ZN3irr2ps5vHalfE) }
}
