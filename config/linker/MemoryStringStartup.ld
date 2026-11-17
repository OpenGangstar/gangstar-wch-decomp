OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-memory/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
nativeMalloc = 0x001c41cc;
nativeFree = 0x001c4964;
SECTIONS
{
    .memory_function_0 0x002d3338 : { *string-startup-memory.o(.text._Z10CustomFreePv) }
    .memory_function_1 0x002d3348 : { *string-startup-memory.o(.text._Z7SwfFreePv) }
    .memory_function_2 0x002d3354 : { *string-startup-memory.o(.text._Z7IrrFreePv) }
    .memory_function_3 0x002d3360 : { *string-startup-memory.o(.text._Z11CustomAllocj) }
    .memory_function_4 0x002d3370 : { *string-startup-memory.o(.text._Z8SwfAllocjN3swf7MemHintEPKci) }
    .memory_function_5 0x002d337c : { *string-startup-memory.o(.text._Z8SwfAllocjN3swf7MemHintE) }
    .memory_function_6 0x002d3388 : { *string-startup-memory.o(.text._Z8IrrAllocjN3irr7MemHintE) }
    .memory_function_7 0x002d3394 : { *string-startup-memory.o(.text._Z8IrrAllocjN3irr7MemHintEiPKci) }
    .string_startup_function_0 0x002d3308 : { *string-startup-memory.o(.text.__tcf_0) }
    .string_startup_function_1 0x002d33a0 : { *string-startup-memory.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x002d33f8 : { *string-startup-memory.o(.text._GLOBAL__I__Z11CustomAllocj) }
    .string_startup_storage_0 0x004b675c (NOLOAD) : { *string-startup-memory.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
