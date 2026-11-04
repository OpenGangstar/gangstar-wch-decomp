OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/irrlicht-allocator/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
memset = 0x001c45d4;
SECTIONS
{
    .allocator_function_0 0x001e02cc : { *irrlicht-allocator.o(.text.__tcf_0) }
    .allocator_function_1 0x001e0368 : { *irrlicht-allocator.o(.text._ZdaPvN3irr7MemHintEiPKci) }
    .allocator_function_2 0x001e0374 : { *irrlicht-allocator.o(.text._ZdlPvN3irr7MemHintEiPKci) }
    .allocator_function_3 0x001e0380 : { *irrlicht-allocator.o(.text.irr_free) }
    .allocator_function_4 0x001e0390 : { *irrlicht-allocator.o(.text._ZdaPvN3irr7MemHintE) }
    .allocator_function_5 0x001e039c : { *irrlicht-allocator.o(.text._ZdlPvN3irr7MemHintE) }
    .allocator_function_6 0x001e03a8 : { *irrlicht-allocator.o(.text._ZnajN3irr7MemHintEiPKci) }
    .allocator_function_7 0x001e03b8 : { *irrlicht-allocator.o(.text._ZnwjN3irr7MemHintEiPKci) }
    .allocator_function_8 0x001e03c8 : { *irrlicht-allocator.o(.text.irr_malloc) }
    .allocator_function_9 0x001e03d8 : { *irrlicht-allocator.o(.text._ZnajN3irr7MemHintE) }
    .allocator_function_10 0x001e03e4 : { *irrlicht-allocator.o(.text._ZnwjN3irr7MemHintE) }
    .allocator_function_11 0x001e03f0 : { *irrlicht-allocator.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .allocator_function_12 0x001e0474 : { *irrlicht-allocator.o(.text._GLOBAL__I__ZnwjN3irr7MemHintE) }
    .local_string 0x004b611c (NOLOAD) : { *irrlicht-allocator.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.local_string) == 32, "local string extent");
