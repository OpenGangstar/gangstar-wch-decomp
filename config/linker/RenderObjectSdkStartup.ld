OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-renderobject/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .render_object_vtable 0x004ab078 : { *sdk-startup-renderobject.o(.data.rel.ro._ZTV12RenderObject) }
    .render_object_ctor 0x00305be8 : { *sdk-startup-renderobject.o(.text._ZN12RenderObjectC1EP10GameObject .text._ZN12RenderObjectC2EP10GameObject) }
    .render_object_d1 0x00305bd0 : { *sdk-startup-renderobject.o(.text._ZN12RenderObjectD1Ev .text._ZN12RenderObjectD2Ev) }
    .render_object_d0 0x00305bb0 : { *sdk-startup-renderobject.o(.text._ZN12RenderObjectD0Ev) }
    .render_object_render 0x00305b7c : { *sdk-startup-renderobject.o(.text._ZNK12RenderObject6RenderEv) }
    .sdk_startup_function_0 0x00305b80 : { *sdk-startup-renderobject.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00305c24 : { *sdk-startup-renderobject.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00305c90 : { *sdk-startup-renderobject.o(.text._GLOBAL__I__ZN12RenderObjectC2EP10GameObject) }
    .sdk_startup_storage_0 0x004b8168 (NOLOAD) : { *sdk-startup-renderobject.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b8188 (NOLOAD) : { *sdk-startup-renderobject.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
