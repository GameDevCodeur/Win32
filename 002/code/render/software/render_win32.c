
#include "../render.h"

#if GDC_PLATFORM_WINDOWS
	
	// 002
	void RenderDrawPoint(u16 x, u16 y, u32 color)
	{
		u32 *Pixel = (u32*)SURFACE.Memory + ((y * SURFACE.Width) + x);
		*Pixel = color;
	}
	
	void SetRenderDrawColor(u32 Color)
	{
		RENDER.DrawColor = Color;
	}
	
	void RenderClear(void)
	{
		u32 *Pixel = (u32*)SURFACE.Memory;
		for(int Index = 0; 
			Index < SURFACE.Width * SURFACE.Height;
			++Index) { *Pixel++ = RENDER.DrawColor; }
	}
	
	void RenderPresent(HDC DeviceContext)
	{
		// 002
		StretchDIBits(	DeviceContext, 
						0, 0, 
						SURFACE.Width, SURFACE.Height,
						0, 0,
						SURFACE.Width, SURFACE.Height,
						SURFACE.Memory, &BitmapInfo,
						DIB_RGB_COLORS, SRCCOPY);
	}

#endif 
