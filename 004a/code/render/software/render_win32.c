
#include "../render.h"

#if GDC_PLATFORM_WINDOWS

	#include "DrawPoint_win32.c"
	#include "DrawLine_win32.c"
	
	void SetRenderDrawColor(u32 Color)
	{
		RENDER.DrawColor = Color;
	}
	
	void RenderClear(void)
	{
		u32 *Pixel = (u32*)SURFACE.Memory;
		u32 Index;
		for(Index = 0; Index < SURFACE.Width * SURFACE.Height; ++Index)
		{ 
			*Pixel++ = RENDER.DrawColor;
		}
	}
	
	void RenderPresent(HDC DeviceContext)
	{
		StretchDIBits(	DeviceContext, 
						0, 0, 
						SURFACE.Width, SURFACE.Height,
						0, 0,
						SURFACE.Width, SURFACE.Height,
						SURFACE.Memory, &BitmapInfo,
						DIB_RGB_COLORS, SRCCOPY);
	}

#endif 
