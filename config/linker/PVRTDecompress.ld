memcpy = 0x1c4190;
memcmp = 0x1c4544;
__aeabi_idiv = 0x1c43dc;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_Z15PVRTCDecompressPKviiiPh)
SECTIONS {
 .pvrtc_decoder 0x0020c73c : { *pvrt-decompress.o(.text._Z10DecompressP17AMTC_BLOCK_STRUCTiiiiPh) }
 .pvrtc_previous_init 0x00409b0c : { *pvrt-decompress.o(.rodata._ZZ10DecompressP17AMTC_BLOCK_STRUCTiiiiPhE3C.8) }
    .pvrtc_interpolate 0x0020c484 : { *pvrt-decompress.o(.text._Z18InterpolateColoursPKiS0_S0_S0_iiiPi) }
    .pvrtc_modulation 0x0020c5bc : { *pvrt-decompress.o(.text._Z18GetModulationValueiiiPA16_KiS1_PiS2_) }
    .pvrtc_rep0 0x00409b2c : { *pvrt-decompress.o(.rodata._ZZ18GetModulationValueiiiPA16_KiS1_PiS2_E8RepVals0) }
    .pvrtc_rep1 0x00409b1c : { *pvrt-decompress.o(.rodata._ZZ18GetModulationValueiiiPA16_KiS1_PiS2_E8RepVals1) }
    .got 0x004b0048 : { *(.got.plt) *(.got) }
    .pvrtc_power_two 0x0020c468 : { *pvrt-decompress.o(.text._Z22util_number_is_power_2j) }
    .pvrtc_twiddle 0x0020c6ec : { *pvrt-decompress.o(.text._Z9TwiddleUVmmmm) }
    .pvrtc_wrapper 0x0020ccd4 : { *pvrt-decompress.o(.text._Z15PVRTCDecompressPKviiiPh) }
}
ASSERT(ADDR(.pvrtc_wrapper)==0x0020ccd4,"PVRTC wrapper previous neighbor");
ASSERT(SIZEOF(.pvrtc_wrapper)==20,"PVRTC wrapper native20 extent");
ASSERT(ADDR(.pvrtc_wrapper)+SIZEOF(.pvrtc_wrapper)==0x0020cce8,"PVRTC wrapper next neighbor");

ASSERT(ADDR(.pvrtc_power_two)==0x0020c468,"power2 native start");
ASSERT(SIZEOF(.pvrtc_power_two)==28,"power2 native28 extent");
ASSERT(ADDR(.pvrtc_power_two)+SIZEOF(.pvrtc_power_two)==0x0020c484,"power2 next native neighbor");

ASSERT(ADDR(.pvrtc_twiddle)==0x0020c6ec,"TwiddleUV native start");
ASSERT(SIZEOF(.pvrtc_twiddle)==80,"TwiddleUV native78 plus alignment2 extent");
ASSERT(ADDR(.pvrtc_twiddle)+SIZEOF(.pvrtc_twiddle)==0x0020c73c,"TwiddleUV next native decoder boundary");

ASSERT(ADDR(.pvrtc_interpolate)==0x0020c484,"Interpolate native start");
ASSERT(SIZEOF(.pvrtc_interpolate)==312,"Interpolate native310 plus2B section padding");
ASSERT(ADDR(.pvrtc_interpolate)+SIZEOF(.pvrtc_interpolate)==0x0020c5bc,"Interpolate next native neighbor");
ASSERT(ADDR(.pvrtc_modulation)==0x0020c5bc,"modulation native start");
ASSERT(SIZEOF(.pvrtc_modulation)==304,"modulation native304 extent");
ASSERT(ADDR(.pvrtc_modulation)+SIZEOF(.pvrtc_modulation)==0x0020c6ec,"modulation next native neighbor");
ASSERT(SIZEOF(.pvrtc_rep0)==16,"modulation Rep0 native16");
ASSERT(SIZEOF(.pvrtc_rep1)==16,"modulation Rep1 native16");

ASSERT(SIZEOF(.pvrtc_decoder)==1432,"Decompress native1432 extent");
ASSERT(ADDR(.pvrtc_decoder)+SIZEOF(.pvrtc_decoder)==0x0020ccd4,"Decompress native next-wrapper boundary");
ASSERT(SIZEOF(.pvrtc_previous_init)==16,"Decompress original16B initializer");
