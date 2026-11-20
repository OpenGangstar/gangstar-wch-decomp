/*
 * PVRTDecompress
 *
 * Original file: PVRTDecompress.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of PVRTDecompress.cpp here, in the order they appear in the library.
 */

// The decoder remains native. The void return view is inferred from its observed
// epilogue and legacy interface; the wrapper's complete ARM bytes are verified.
struct AMTC_BLOCK_STRUCT;
void Decompress(AMTC_BLOCK_STRUCT*, int, int, int, int, unsigned char*);

void PVRTCDecompress(const void* compressed, int mode, int width, int height,
                     unsigned char* output)
{
    Decompress(static_cast<AMTC_BLOCK_STRUCT*>(const_cast<void*>(compressed)),
               mode, width, height, 1, output);
}
