/*
 * PVRTDecompress
 *
 * Original file: PVRTDecompress.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of PVRTDecompress.cpp here, in the order they appear in the library.
 */

// Legacy PowerVR PVRTC helper, Copyright (C) 2000-2008 Imagination Technologies Limited.
// Reused from cocos2d-x e4b6a5ef8fcdc99a7ebea606312b67fe4c534b9f, cocos/base/pvr.cpp.
// The precise original retail revision remains unknown.
int util_number_is_power_2( unsigned  input )
{
    unsigned minus1;

    if( !input ) return 0;

    minus1 = input - 1;
    return ( (input | minus1) == (input ^ minus1) ) ? 1 : 0;
}

// Legacy PowerVR integer interpolation; same pinned source/attribution as above.
// Release assertion-only loops omitted; original retail helper has external linkage.
#define BLK_Y_SIZE (4)
#define BLK_X_2BPP (8)
#define BLK_X_4BPP (4)
void InterpolateColours(const int ColourP[4],
                               const int ColourQ[4],
                               const int ColourR[4],
                               const int ColourS[4],
                               const int Do2bitMode,
                               const int x,
                               const int y,
                               int Result[4])
{
	int u, v, uscale;
	int k;

	int tmp1, tmp2;

	int P[4], Q[4], R[4], S[4];

	// Copy the colours
	for(k = 0; k < 4; k++)
	{
		P[k] = ColourP[k];
		Q[k] = ColourQ[k];
		R[k] = ColourR[k];
		S[k] = ColourS[k];
	}

	// put the x and y values into the right range
	v = (y & 0x3) | ((~y & 0x2) << 1);

	if(Do2bitMode)
		u = (x & 0x7) | ((~x & 0x4) << 1);
	else
		u = (x & 0x3) | ((~x & 0x2) << 1);

	// get the u and v scale amounts
	v  = v - BLK_Y_SIZE/2;

	if(Do2bitMode)
	{
		u = u - BLK_X_2BPP/2;
		uscale = 8;
	}
	else
	{
		u = u - BLK_X_4BPP/2;
		uscale = 4;
	}

	for(k = 0; k < 4; k++)
	{
		tmp1 = P[k] * uscale + u * (Q[k] - P[k]);
		tmp2 = R[k] * uscale + u * (S[k] - R[k]);

		tmp1 = tmp1 * 4 + v * (tmp2 - tmp1);

		Result[k] = tmp1;
	}

	// Lop off the appropriate number of bits to get us to 8 bit precision
	if(Do2bitMode)
	{
		// do RGB
		for(k = 0; k < 3; k++)
		{
			Result[k] >>= 2;
		}

		Result[3] >>= 1;
	}
	else
	{
		// do RGB  (A is ok)
		for(k = 0; k < 3; k++)
		{
			Result[k] >>= 1;
		}
	}

	// sanity check
	// Release build: assertion-only sanity check omitted.


	/*
     Convert from 5554 to 8888

     do RGB 5.3 => 8
     */
	for(k = 0; k < 3; k++)
	{
		Result[k] += Result[k] >> 5;
	}

	Result[3] += Result[3] >> 4;

	// 2nd sanity check
	// Release build: assertion-only sanity check omitted.

}


// Legacy PowerVR PVRTC helper, Copyright (C) 2000-2008 Imagination Technologies Limited.
// Reused from cocos2d-x e4b6a5ef8fcdc99a7ebea606312b67fe4c534b9f, cocos/base/pvr.cpp.
// Precise retail revision remains unknown; integer mode and payloads verified natively.
#define PT_INDEX (2)
void GetModulationValue(int x,
							   int y,
							   const int Do2bitMode,
							   const int ModulationVals[8][16],
							   const int ModulationModes[8][16],
							   int *Mod,
							   int *DoPT)
{
	static const int RepVals0[4] = {0, 3, 5, 8};
	static const int RepVals1[4] = {0, 4, 4, 8};

	int ModVal;

	// Map X and Y into the local 2x2 block
	y = (y & 0x3) | ((~y & 0x2) << 1);

	if(Do2bitMode)
		x = (x & 0x7) | ((~x & 0x4) << 1);
	else
		x = (x & 0x3) | ((~x & 0x2) << 1);

	// assume no PT for now
	*DoPT = 0;

	// extract the modulation value. If a simple encoding
	if(ModulationModes[y][x]==0)
	{
		ModVal = RepVals0[ModulationVals[y][x]];
	}
	else if(Do2bitMode)
	{
		// if this is a stored value
		if(((x^y)&1)==0)
			ModVal = RepVals0[ModulationVals[y][x]];
		else if(ModulationModes[y][x] == 1) // else average from the neighbours if H&V interpolation..
		{
			ModVal = (RepVals0[ModulationVals[y-1][x]] +
					  RepVals0[ModulationVals[y+1][x]] +
					  RepVals0[ModulationVals[y][x-1]] +
					  RepVals0[ModulationVals[y][x+1]] + 2) / 4;
		}
		else if(ModulationModes[y][x] == 2) // else if H-Only
		{
			ModVal = (RepVals0[ModulationVals[y][x-1]] +
					  RepVals0[ModulationVals[y][x+1]] + 1) / 2;
		}
		else // else it's V-Only
		{
			ModVal = (RepVals0[ModulationVals[y-1][x]] +
					  RepVals0[ModulationVals[y+1][x]] + 1) / 2;
		}
	}
	else // else it's 4BPP and PT encoding
	{
		ModVal = RepVals1[ModulationVals[y][x]];

		*DoPT = ModulationVals[y][x] == PT_INDEX;
	}

	*Mod =ModVal;
}

#undef PT_INDEX

// Legacy PVRTC bit interleaving; original Y/X argument order is preserved.
unsigned long TwiddleUV(unsigned long YSize, unsigned long XSize, unsigned long YPos, unsigned long XPos)
{
	unsigned long Twiddled;

	unsigned long MinDimension;
	unsigned long MaxValue;

	unsigned long SrcBitPos;
	unsigned long DstBitPos;

	int ShiftCount;

	if(YSize < XSize)
	{
		MinDimension = YSize;
		MaxValue	 = XPos;
	}
	else
	{
		MinDimension = XSize;
		MaxValue	 = YPos;
	}



	// Step through all the bits in the "minimum" dimension
	SrcBitPos = 1;
	DstBitPos = 1;
	Twiddled  = 0;
	ShiftCount = 0;

	while(SrcBitPos < MinDimension)
	{
		if(YPos & SrcBitPos)
		{
			Twiddled |= DstBitPos;
		}

		if(XPos & SrcBitPos)
		{
			Twiddled |= (DstBitPos << 1);
		}


		SrcBitPos <<= 1;
		DstBitPos <<= 2;
		ShiftCount += 1;

	}

	// prepend any unused bits
	MaxValue >>= ShiftCount;

	Twiddled |=  (MaxValue << (2*ShiftCount));

	return Twiddled;
}


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
