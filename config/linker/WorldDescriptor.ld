OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_ZN15WorldDescriptorC1EPKc)
INCLUDE build/matches/world-descriptor/retail-symbols.ld
_ZdaPv = 0x001c461c;
_ZdlPv = 0x001c42b0;
__stack_chk_fail = 0x001c42e0;
SECTIONS {
    .descriptor_default 0x00322a8c : { *world-descriptor.o(.text._ZN15WorldDescriptorC1Ev .text._ZN15WorldDescriptorC2Ev) }
    .descriptor_dtor 0x00322a90 : { *world-descriptor.o(.text._ZN15WorldDescriptorD1Ev .text._ZN15WorldDescriptorD2Ev) }
    .descriptor_read 0x00322ac0 : { *world-descriptor.o(.text._ZN7Structs15WorldDescriptor4ReadER10DataStream .gnu.linkonce.t._ZN7Structs15WorldDescriptor4ReadER10DataStream) }
    .descriptor_path 0x00322afc : { *world-descriptor.o(.text._ZN15WorldDescriptorC1EPKc .text._ZN15WorldDescriptorC2EPKc) }
    .descriptor_id 0x00322b84 : { *world-descriptor.o(.text._ZN15WorldDescriptorC1Ei .text._ZN15WorldDescriptorC2Ei) }
    .data_stream_dtor 0x002d3654 : { *world-descriptor.o(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
