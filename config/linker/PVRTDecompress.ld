OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_Z15PVRTCDecompressPKviiiPh)
SECTIONS {
    .pvrtc_wrapper 0x0020ccd4 : { *pvrt-decompress.o(.text._Z15PVRTCDecompressPKviiiPh) }
}
ASSERT(ADDR(.pvrtc_wrapper)==0x0020ccd4,"PVRTC wrapper previous neighbor");
ASSERT(SIZEOF(.pvrtc_wrapper)==20,"PVRTC wrapper native20 extent");
ASSERT(ADDR(.pvrtc_wrapper)+SIZEOF(.pvrtc_wrapper)==0x0020cce8,"PVRTC wrapper next neighbor");
