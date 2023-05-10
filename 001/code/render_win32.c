
#include "render.h"

#if GDC_PLATFORM_WINDOWS

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
	
	void RenderPresent(void)
	{
		// 001
		HDC DeviceContext = GetDC(STATE.hwnd);		
		
		StretchDIBits(	DeviceContext, 
						0, 0, 
						SURFACE.Width, SURFACE.Height,
						0, 0,
						ClientWidth, ClientHeight,
						SURFACE.Memory, &BitmapInfo,
						DIB_RGB_COLORS, SRCCOPY);
						
		ReleaseDC(STATE.hwnd, DeviceContext);
	}

#endif 
